<?php
class NCChartsBeanPie extends NCChartsBean {

  /**
   * Define the form values and their defaults.
   */
  public function values() {
    $values = array(
      'pie_settings' => array(
        'doughnut'         => self::VALUE_NO,
        'animate_rotate'   => self::VALUE_YES,
        'animate_scale'   => self::VALUE_NO,
        'data_set_options' => array(
          'json' => NULL,
        ),
      ),
    );
    return array_merge_recursive(parent::values(), $values);
  }

  /**
   * The Plugin Form
   *
   * The Bean object will be either loaded from the database or filled with the defaults.
   *
   * @param $bean
   * @param $form
   * @param $form_state
   * @return array
   *  form array
   */
  public function form($bean, $form, &$form_state) {
    $form = array();
    $form['pie_settings'] = array(
      '#type'  => 'fieldset',
      '#title' => t('Pie Chart Settings'),
      '#tree'  => 1,
    );
    $form['pie_settings']['doughnut'] = array(
      '#type'    => 'select',
      '#title'   => t('Doughnut'),
      '#options' => array(
        self::VALUE_YES => t('Yes'),
        self::VALUE_NO  => t('No'),
      ),
      '#default_value' => $bean->pie_settings['doughnut'],
    );
    $form['pie_settings']['animate_rotate'] = array(
      '#type'        => 'select',
      '#title'       => t('Animate Rotate'),
      '#description' => t('If yes, will animate the rotation of the chart.'),
      '#options'     => array(
        self::VALUE_YES => t('Yes'),
        self::VALUE_NO  => t('No'),
      ),
      '#default_value' => $bean->pie_settings['animate_rotate'],
    );
    $form['pie_settings']['animate_scale'] = array(
      '#type'        => 'select',
      '#title'       => t('Animate Scale'),
      '#description' => t('If yes, will animate scaling the Doughnut from the center.'),
      '#options'     => array(
        self::VALUE_YES => t('Yes'),
        self::VALUE_NO  => t('No'),
      ),
      '#default_value' => $bean->pie_settings['animate_scale'],
    );
    $form['pie_settings']['data_set_options'] = array(
      '#type'  => 'fieldset',
      '#title' => t('Data Set Options'),
      '#tree'  => 1,
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $title = 'JSON to apply advanced settings to each set of arcs. For more '
      . 'information go to <a href="http://www.chartjs.org/docs/#doughnut-pie-chart">'
      . 'http://www.chartjs.org/docs/#doughnut-pie-chart</a>';
    $description = 'This will allow some settings in the form to be overridden '
      . 'and settings that are not in the form to be added to the graph.  The '
      . 'JSON can be added as two ways:<br /><ul><li><b>Object</b> - if it is '
      . 'entered as an object, then the settings is will be added to every '
      . 'dataset added to the chart.  Each line will have these settings added.'
      . '</li><li><b>Array</b> - if the JSON is entered as an array, then the '
      . 'array will loop through the data sets adding the settings in the order '
      . 'they are in the array.  This will allow for different settings to be '
      . 'applied to the lines.</li></ul>';

    $form['pie_settings']['data_set_options']['json'] = array(
      '#type' => 'textarea',
      '#title' => t($title),
      '#description' => t($description),
      '#default_value' => $bean->pie_settings['data_set_options']['json']
    );
    return $form + parent::form($bean, $form, $form_state);
  }

  /**
   * Validate function for bean type form
   *
   * @param  $values
   * @param $form_state
   */
  public function validate($values, &$form_state) {
    if (!empty($values['pie_settings']['data_set_options']['json']) && !$this->_isValidJson($values['pie_settings']['data_set_options']['json'])) {
      form_set_error('pie_settings][data_set_options][json', '<em>Data Set Options</em> must be valid JSON.');
    }
    parent::validate($values, $form_state);
  }

  protected function _getJsChartType(Bean $bean) {
    return $bean->pie_settings['doughnut'] ? 'doughnut' : 'pie';
  }

  protected function _getJsData(Bean $bean)
  {
    $colorSet = $this->getColorSet($bean->settings['color_set']);
    $colors = $colorSet['sets'];
    $currentColor = 0;

    // Setup custom data set options;
    $dataSetOptions = FALSE;
    $currentDataSetOption = 0;
    if (!empty($bean->pie_settings['data_set_options'])) {
      $dataSetOptions = json_decode($bean->pie_settings['data_set_options']['json']);
      if (!is_array($dataSetOptions)) {
        $dataSetOptions = array((array) $dataSetOptions);
      }
    }

    $data = array(
      'labels' => array(),
      'datasets' => array(),
    );
    $groupedData = $this->_groupData($bean->field_chart_data['und'][0]['tablefield']);
    $first = TRUE;
    foreach ($groupedData as $setLabel => $labels) {
      $dataset = array(
        'data' => array(),
        'backgroundColor' => array(),
        'hoverBackgroundColor' => array(),
        'label' => $setLabel,
      );
      foreach ($labels as $label => $value) {
        if ($first) {
          $data['labels'][] = $label;
        }
        $dataset['data'][] = $value;
        $dataset['backgroundColor'][] = $colors[$currentColor]['original_color'];
        $dataset['hoverBackgroundColor'][] = $colors[$currentColor]['dark_hover'];
        $currentColor++;
        if ($currentColor >= count($colors)) {
          $currentColor = 0;
        }
      }

      // Merge in custom dataset options.
      if ($dataSetOptions) {
        $dataset = array_replace_recursive($dataset, (array) $dataSetOptions[$currentDataSetOption]);
        $currentDataSetOption++;
        if ($currentDataSetOption >= count($dataSetOptions)) {
          $currentDataSetOption = 0;
        }
      }
      $data['datasets'][] = $dataset;

      $first = FALSE;
    }
    return $data;
  }

  /**
   * THIS IS DIFFERENT THAN THE ORGANIZATION DONE IN THE BASE ABSTRACT CLASS.
   *
   * Groups the data from the data table in a usable array.
   *
   * The data table array follows this format.  If you have the following table:
   * --------------------
   * |   |2017|2018|2019|
   * --------------------
   * |Foo|  23|  35|  40|
   * --------------------
   * |Bar|  35|  50|  30|
   * --------------------
   *
   * It makes an array like this:
   * array(
   *  'cell_0_0' => '',
   *  'cell_0_1' => 2017,
   *  'cell_0_2' => 2018,
   *  'cell_0_3' => 2019,
   *  'cell_1_0' => 'Foo',
   *  'cell_1_1' => 23,
   *  'cell_1_2' => 35,
   *  'cell_1_3' => 40,
   *  'cell_2_0' => 'Bar',
   *  'cell_2_1' => 35,
   *  'cell_2_2' => 50,
   *  'cell_2_3' => 30,
   * );
   *
   * This function turns the array into this format:
   * array(
   *  '2017' => array(
   *    'Foo' => 23,
   *    'Bar' => 35,
   *  ),
   * '2018'  => array(
   *    'Foo' => 35,
   *    'Bar' => 50,
   * ),
   * '2019'  => array(
   *    'Foo' => 40,
   *    'Bar' => 30,
   * ),
   *
   */
  protected function _groupData(array $dataField) {
    $groupedData = array();
    $setMap = array();
    $labelMap = array();
    foreach ($dataField as $cellName => $data) {
      $cell = explode('_', $cellName);
      if (count($cell) != 3 || $cell[0] !== 'cell') {
        continue;
      }
      // If we are on the first row.
      if ($cell[1] == '0') {
        // Skip the first cell.
        if ($cell[2] == '0') {
          continue;
        }
        $groupedData[$data] = array();
        $setMap[$cell[2]] = $data;
        // If we are in the first column.
      } else if ($cell[2] == 0) {
        $labelMap[$cell[1]] = $data;
        // We are on a data cell.
      } else {
        $set = $setMap[$cell[2]];
        $label = $labelMap[$cell[1]];
        $groupedData[$set][$label] = $data;
      }
    }
    return $groupedData;
  }

  /**
   * Returns the JS Options for the specific type of chart.
   */
  protected function _getJsTypeOptions(array $options, Bean $bean) {
    $options['animation']['animateRotate'] = $bean->pie_settings['animate_rotate'] && $bean->settings['animation_duration'] !== '0' ? TRUE : FALSE;
    $options['animation']['animateScale'] = $bean->pie_settings['animate_scale'] && $bean->settings['animation_duration'] !== '0' ? TRUE : FALSE;
    return $options;
  }
}