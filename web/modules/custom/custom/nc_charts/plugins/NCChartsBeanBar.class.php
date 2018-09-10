<?php
class NCChartsBeanBar extends NCChartsBean {

  const COLOR_DISTRIBUTION_COLUMN = 'column';
  const COLOR_DISTRIBUTION_ROW    = 'row';

  /**
   * Define the form values and their defaults
   */
  public function values() {
    $values = array(
      'bar_settings' => array(
        'color_distribution' => self::COLOR_DISTRIBUTION_ROW,
        'horizontal' => self::VALUE_NO,
        'border_width' => 0,
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
    $form['bar_settings'] = array(
      '#type'  => 'fieldset',
      '#title' => t('Bar Chart Settings'),
      '#tree'  => 1,
    );
    $color_dist_desc = 'Determines how the colors are distributed to the bars, '
      . 'based off the datat table used to build the chart.<ul><li><strong>'
      . 'Column</strong> - the colors are different per column headings. All '
      . 'bars grouped together have the same color.</li><li><strong>Row</strong>'
      . ' - the colors are different per row heading.  The colors will repeat '
      . 'in the same order when bunched together under the different column '
      . 'headings</li></ul>';
    $form['bar_settings']['color_distribution'] = array(
      '#type'        => 'select',
      '#title'       => t('Color Distribution'),
      '#description' => t($color_dist_desc),
      '#options'     => array(
        self::COLOR_DISTRIBUTION_COLUMN => t('column'),
        self::COLOR_DISTRIBUTION_ROW    => t('row'),
      ),
      '#default_value' => $bean->bar_settings['color_distribution'],
    );
    $form['bar_settings']['horizontal'] = array(
      '#type'  => 'select',
      '#title' => t('Horizontal'),
      '#options' => array(
        self::VALUE_YES => t('Yes'),
        self::VALUE_NO  => t('No'),
      ),
      '#default_value' => $bean->bar_settings['horizontal'],
    );
    $form['bar_settings']['border_width'] = array(
      '#type'    => 'select',
      '#title'   => t('Border Width'),
      '#options' => array(
        0 => 'none',
        1 => 1,
        2 => 2,
        3 => 3,
        4 => 4,
        5 => 5,
      ),
      '#default_value' => $bean->bar_settings['border_width'],
    );
    $form['bar_settings']['data_set_options'] = array(
      '#type'  => 'fieldset',
      '#title' => t('Data Set Options'),
      '#tree'  => 1,
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $title = 'JSON to apply advanced settings to each set of bars. For more '
      . 'information go to <a href="http://www.chartjs.org/docs/#bar-chart">'
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

    $form['bar_settings']['data_set_options']['json'] = array(
      '#type' => 'textarea',
      '#title' => t($title),
      '#description' => t($description),
      '#default_value' => $bean->bar_settings['data_set_options']['json']
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
    if (!empty($values['bar_settings']['data_set_options']['json']) && !$this->_isValidJson($values['bar_settings']['data_set_options']['json'])) {
      form_set_error('bar_settings][data_set_options][json', '<em>Data Set Options</em> must be valid JSON.');
    }
    parent::validate($values, $form_state);
  }

  /**
   * Returns the type name for the JS for the chart to be made.
   */
  protected function _getJsChartType(Bean $bean) {
    return $bean->bar_settings['horizontal'] ? 'horizontalBar' : 'bar';
  }

  /**
   * Returns the data sets to be used in the Chart object.
   */
  protected function _getJsData(Bean $bean)
  {
    $colorSet = $this->getColorSet($bean->settings['color_set']);
    $colorDistribution = $bean->bar_settings['color_distribution'];
    $colors = $colorSet['sets'];
    $currentColor = 0;

    // Setup custom data set options;
    $dataSetOptions = FALSE;
    $currentDataSetOption = 0;
    if (!empty($bean->bar_settings['data_set_options'])) {
      $dataSetOptions = json_decode($bean->bar_settings['data_set_options']['json']);
      if (!is_array($dataSetOptions)) {
        $dataSetOptions = array((array) $dataSetOptions);
      }
    }

    $jsData = array(
      'labels' => array(),
      'datasets' => array(),
    );
    $groupedData = $this->_groupData($bean->field_chart_data['und'][0]['tablefield']);
    $first = TRUE;
    $borderWidth = $bean->bar_settings['border_width'];
    foreach ($groupedData as $rowLabel => $data) {
      if ($first) {
        $jsData['labels'] = array_keys($data);
      }
      $dataset = array(
        'label'           => $rowLabel,
        'backgroundColor'      => array(),
        'hoverBackgroundColor' => array(),
        'data'                 => array(),
      );
      if ($borderWidth) {
        $dataset['borderWidth'] = $borderWidth;
        $dataset['borderColor'] = array();
        $dataset['hoverBorderColor'] = array();
      }
      foreach ($data as $value) {
        $dataset['data'][] = $value;
        $dataset['backgroundColor'][] = $colors[$currentColor]['original_color'];
        $dataset['hoverBackgroundColor'][] = $colors[$currentColor]['dark_hover'];
        if ($borderWidth) {
          $dataset['borderColor'][] = $colors[$currentColor]['light_fill'];
          $dataset['hoverBorderColor'][] = $colors[$currentColor]['original_color'];
        }
        if ($colorDistribution == self::COLOR_DISTRIBUTION_COLUMN) {
          $currentColor++;
          if ($currentColor >= count($colors)) {
            $currentColor = 0;
          }
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

      $jsData['datasets'][] = $dataset;
      if ($colorDistribution == self::COLOR_DISTRIBUTION_ROW) {
        $currentColor++;
        if ($currentColor >= count($colors)) {
          $currentColor = 0;
        }
      } else {
        $currentColor = 0;
      }
      $first = FALSE;
    }
    return $jsData;
  }

  /**
   * Allows overrides of the variables being passed to the theme function.
   */
  protected function _modifyJsSettings(array $settings, Bean $bean)
  {
    if ($bean->settings['legend']['display'] && $bean->bar_settings['border_width']) {
      $chartObject = json_decode($bean->chart_object, true);
      $settings['legend_border_colors'] = array();
      foreach ($chartObject['data']['datasets'] as $dataset) {
        $settings['legend_border_colors'][] = $dataset['hoverBorderColor'][0];
      }
    }
    return $settings;
  }
}