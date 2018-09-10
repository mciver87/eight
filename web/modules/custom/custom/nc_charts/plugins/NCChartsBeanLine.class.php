<?php
class NCChartsBeanLine extends NCChartsBean {

  // Cap styles.
  const CAP_STYLE_BUTT           = 'butt';
  const CAP_STYLE_ROUND          = 'round';
  const CAP_STYLE_SQUARE         = 'square';
  // Joint styles.
  const JOINT_STYLE_BEVEL        = 'bevel';
  const JOINT_STYLE_ROUND        = 'round';
  const JOINT_STYLE_MITER        = 'miter';
  // Point styles.
  const POINT_STYLE_CIRCLE       = 'circle';
  const POINT_STYLE_CROSS        = 'cross';
  const POINT_STYLE_CROSS_ROT    = 'crossRot';
  const POINT_STYLE_DASH         = 'dash';
  const POINT_STYLE_LINE         = 'line';
  const POINT_STYLE_RECT         = 'rect';
  const POINT_STYLE_RECT_ROUNDED = 'rectRounded';
  const POINT_STYLE_RECT_ROT     = 'rectRot';
  const POINT_STYLE_STAR         = 'star';
  const POINT_STYLE_TRIANGLE     = 'triangle';

  /**
   * Define the form values and their defaults.
   */
  public function values() {
    $values = array(
      'line_settings' => array(
        'fill'      => self::VALUE_NO,
        'stacked'   => self::VALUE_NO,
        'show_line' => self::VALUE_YES,
        'lines'     => array(
          'span_gaps'    => self::VALUE_YES,
          'width'        => '',
          'cap_style'    => self::CAP_STYLE_BUTT,
          'joint_style'  => self::JOINT_STYLE_ROUND,
          'stepped_line' => self::VALUE_NO,
          'tension'      => '',
        ),
        'points'    => array(
          'width'       => '',
          'radius'      => '',
          'point_style' => self::POINT_STYLE_CIRCLE,
        ),
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
    $form['line_settings'] = array(
      '#type'  => 'fieldset',
      '#title' => t('Line Chart Settings'),
      '#tree'  => 1,
    );

    $form['line_settings']['fill'] = array(
      '#type'  => 'select',
      '#title' => t('Fill'),
      '#description' => t('When on, fills the area underneath the line.'),
      '#options'     => array(
        self::VALUE_YES => t('Yes'),
        self::VALUE_NO  => t('No'),
      ),
      '#default_value' => $bean->line_settings['fill'],
    );

    $stackedDescription = t('Brings the lines into an even distribution.  It '
      . 'changes the scale of the Y axis so there is not such wide gaps between '
      . 'data points when there is a large difference between them.');
    $form['line_settings']['stacked'] = array(
      '#type' => 'select',
      '#title' => t('Stacked'),
      '#description' => $stackedDescription,
      '#options'     => array(
        self::VALUE_YES => t('Yes'),
        self::VALUE_NO  => t('No'),
      ),
      '#default_value' => $bean->line_settings['stacked'],
    );

    $form['line_settings']['show_line'] = array(
      '#type' => 'select',
      '#title' => t('Show Line'),
      '#options'     => array(
        self::VALUE_YES => t('Yes'),
        self::VALUE_NO  => t('No'),
      ),
      '#default_value' => $bean->line_settings['show_line'],
    );

    // Line Options.
    $form['line_settings']['lines'] = array(
      '#type'  => 'fieldset',
      '#title' => t('Line Options'),
      '#tree'  => 1,
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#states' => array(
        'visible' => array(':input[name="line_settings[show_line]"]' => array('value' => 1))
      ),
    );
    $form['line_settings']['lines']['span_gaps'] = array(
      '#type'        => 'select',
      '#title'       => t('Span Gaps'),
      '#description' => t('If Yes, line will be drawn between points with no data'),
      '#options'     => array(
        self::VALUE_YES => t('Yes'),
        self::VALUE_NO  => t('No'),
      ),
      '#default_value' => $bean->line_settings['span_gaps'],
    );
    $form['line_settings']['lines']['width'] = array(
      '#type'  => 'textfield',
      '#title' => t('Width'),
      '#description' => t('Keep empty to use default value from chart library.'),
      '#element_validate' => array('element_validate_integer'),
      '#size'             => 10,
      '#default_value'    => $bean->line_settings['lines']['width'],
    );
    $form['line_settings']['lines']['cap_style'] = array(
      '#type'    => 'select',
      '#title'   => t('Cap Style'),
      '#options' => array(
        self::CAP_STYLE_BUTT   => self::CAP_STYLE_BUTT,
        self::CAP_STYLE_ROUND  => self::CAP_STYLE_ROUND,
        self::CAP_STYLE_SQUARE => self::CAP_STYLE_SQUARE,
      ),
      '#default_value' => $bean->line_settings['lines']['cap_style'],
    );
    $form['line_settings']['lines']['joint_type'] = array(
      '#type'          => 'select',
      '#title'         => t('Join Style'),
      '#options'       => array(
        self::JOINT_STYLE_BEVEL => self::JOINT_STYLE_BEVEL,
        self::JOINT_STYLE_ROUND => self::JOINT_STYLE_ROUND,
        self::JOINT_STYLE_MITER => self::JOINT_STYLE_MITER,
      ),
      '#default_value' => $bean->line_settings['lines']['joint_style'],
    );
    $form['line_settings']['lines']['stepped_line'] = array(
      '#type'          => 'select',
      '#title'         => t('Stepped Line'),
      '#options'       => array(
        self::VALUE_YES => t('Yes'),
        self::VALUE_NO  => t('No'),
      ),
      '#default_value' => $bean->line_settings['lines']['stepped_line'],
    );
    $form['line_settings']['lines']['tension'] = array(
      '#type'             => 'textfield',
      '#title'            => t('Line Tension'),
      '#description'      => t('Bezier curve tension of the line. Set to 0 to draw straight lines.<br />Keep empty to use default value from chart library.'),
      '#element_validate' => array('element_validate_integer'),
      '#size'             => 10,
      '#default_value'    => $bean->line_settings['lines']['tension'],
    );

    // Point Options.
    $form['line_settings']['points'] = array(
      '#type' => 'fieldset',
      '#title' => t('Point Options'),
      '#tree'  => 1,
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $form['line_settings']['points']['width'] = array(
      '#type'  => 'textfield',
      '#title' => t('Width'),
      '#description' => t('Keep empty to use default value from chart library.'),
      '#element_validate' => array('element_validate_integer'),
      '#size'             => 10,
      '#default_value'    => $bean->line_settings['points']['width'],
    );
    $form['line_settings']['points']['radius'] = array(
      '#type'  => 'textfield',
      '#title' => t('Radius'),
      '#description' => t('The radius of the point shape. If set to 0, the point is not rendered.<br />Keep empty to use default value from chart library.'),
      '#element_validate' => array('element_validate_integer'),
      '#size'             => 10,
      '#default_value'    => $bean->line_settings['points']['radius'],
    );
    $form['line_settings']['points']['point_style'] = array(
      '#type'          => 'select',
      '#title'         => t('Point Style'),
      '#options'       => array(
        self::POINT_STYLE_CIRCLE       => self::POINT_STYLE_CIRCLE,
        self::POINT_STYLE_CROSS        => self::POINT_STYLE_CROSS,
        self::POINT_STYLE_CROSS_ROT    => self::POINT_STYLE_CROSS_ROT,
        self::POINT_STYLE_DASH         => self::POINT_STYLE_DASH,
        self::POINT_STYLE_LINE         => self::POINT_STYLE_LINE,
        self::POINT_STYLE_RECT         => self::POINT_STYLE_RECT,
        self::POINT_STYLE_RECT_ROUNDED => self::POINT_STYLE_RECT_ROUNDED,
        self::POINT_STYLE_RECT_ROT     => self::POINT_STYLE_RECT_ROT,
        self::POINT_STYLE_STAR         => self::POINT_STYLE_STAR,
        self::POINT_STYLE_TRIANGLE     => self::POINT_STYLE_TRIANGLE,
      ),
      '#default_value' => $bean->line_settings['points']['point_style'],
    );


    $form['line_settings']['data_set_options'] = array(
      '#type'  => 'fieldset',
      '#title' => t('Data Set Options'),
      '#tree'  => 1,
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $title = 'JSON to apply advanced settings to each set of lines. For more '
      . 'information go to <a href="http://www.chartjs.org/docs/latest/charts/line.html">'
      . 'http://www.chartjs.org/docs/latest/charts/line.html</a>';
    $description = 'This will allow some settings in the form to be overridden '
      . 'and settings that are not in the form to be added to the graph.  The '
      . 'JSON can be added as two ways:<br /><ul><li><b>Object</b> - if it is '
      . 'entered as an object, then the settings is will be added to every '
      . 'dataset added to the chart.  Each line will have these settings added.'
      . '</li><li><b>Array</b> - if the JSON is entered as an array, then the '
      . 'array will loop through the data sets adding the settings in the order '
      . 'they are in the array.  This will allow for different settings to be '
      . 'applied to the lines.</li></ul>';

    $form['line_settings']['data_set_options']['json'] = array(
      '#type' => 'textarea',
      '#title' => t($title),
      '#description' => t($description),
      '#default_value' => $bean->line_settings['data_set_options']['json']
    );

    return $form + parent::form($bean, $form, $form_state);
  }

  /**
   * Returns the type name for the JS for the chart to be made.
   */
  protected function _getJsChartType(Bean $bean) {
    return 'line';
  }

  /**
   * Returns the data sets to be used in the Chart object.
   */
  protected function _getJsData(Bean $bean) {
    $colorSet = $this->getColorSet($bean->settings['color_set']);
    $colors = $colorSet['sets'];
    $currentColor = 0;

    // Setup custom data set options;
    $dataSetOptions = FALSE;
    $currentDataSetOption = 0;
    if (!empty($bean->line_settings['data_set_options'])) {
      $dataSetOptions = json_decode($bean->line_settings['data_set_options']['json']);
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
    $defaultOptions = $this->_getDefaultDatasetOptions($bean);
    foreach ($groupedData as $rowLabel => $data) {
      if ($first) {
        $jsData['labels'] = array_keys($data);
      }
      $dataset = $defaultOptions;
      $dataset['label'] = $rowLabel;
      $dataset['data'] = array_values($data);
      $dataset['borderColor'] = $colors[$currentColor]['original_color'];
      if ($bean->line_settings['fill']) {
        $dataset['backgroundColor'] = $colors[$currentColor]['light_fill'];
      } else {
        $dataset['backgroundColor'] = $colors[$currentColor]['original_color'];
      }
      $dataset['pointBackgroundColor'] = $colors[$currentColor]['original_color'];
      $dataset['pointBorderColor'] = $colors[$currentColor]['original_color'];
      $dataset['pointHoverBackgroundColor'] = $colors[$currentColor]['dark_hover'];
      $dataset['pointHoverBorderColor'] = $colors[$currentColor]['dark_hover'];

      if ($dataSetOptions) {
        $dataset = array_replace_recursive($dataset, (array) $dataSetOptions[$currentDataSetOption]);
        $currentDataSetOption++;
        if ($currentDataSetOption >= count($dataSetOptions)) {
          $currentDataSetOption = 0;
        }
      }

      $jsData['datasets'][] = $dataset;
      $first = FALSE;
      $currentColor++;
      if ($currentColor >= count($colors)) {
        $currentColor = 0;
      }
    }

    return $jsData;
  }

  /**
   * Get the options for a dataset.
   */
  protected function _getDefaultDatasetOptions(Bean $bean) {
    $showLine = $bean->line_settings['show_line'] ? TRUE : FALSE;
    $defaultOptions = array(
      'fill' => $bean->line_settings['fill'] ? TRUE: FALSE,
      'showLine' => $showLine,
    );
    if ($showLine) {
      // Span gaps.
      $defaultOptions['spanGaps'] = $bean->line_settings['lines']['span_gaps'] ? TRUE : FALSE;
      if (is_numeric($bean->line_settings['lines']['width'])) {
        $defaultOptions['borderWidth'] = $bean->line_settings['lines']['width'];
      }
      // Cap style.
      $defaultOptions['borderCapStyle'] = $bean->line_settings['lines']['cap_style'];
      // Joint style.
      $defaultOptions['borderJointStyle'] = $bean->line_settings['lines']['joint_type'];
      // Stepped line/line tension.
      if ($bean->line_settings['lines']['stepped_line'] != self::VALUE_NO) {
        $defaultOptions['steppedLine'] = TRUE;
      } else if (is_numeric($bean->line_settings['lines']['tension'])) {
        $defaultOptions['lineTension'] = $bean->line_settings['lines']['tension'];
      }
    }


    // Point radius.
    if (is_numeric($bean->line_settings['points']['radius'])) {
      $defaultOptions['pointRadius'] = $bean->line_settings['points']['radius'];
    }

    if ($bean->line_settings['points']['radius'] !== '0') {
      // Point width.
      if (is_numeric($bean->line_settings['points']['width'])) {
        $defaultOptions['pointWidth'] = $bean->line_settings['points']['width'];
      }
      // Point style.
      $defaultOptions['pointStyle'] = $bean->line_settings['points']['point_style'];
    }

    return $defaultOptions;
  }

  /**
   * Returns the JS Options for the specific type of chart.
   */
  protected function _getJsTypeOptions(array $options, Bean $bean) {
    if ($bean->line_settings['stacked']) {
      $options['scales']['yAxes'][0]['stacked'] = TRUE;
    }
    return $options;
  }
}