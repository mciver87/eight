<?php

abstract class NCChartsBean extends BeanPlugin {

  const COLOR_SET_BRIGHT         = 'bright';
  const COLOR_SET_COOL           = 'cool';
  const COLOR_SET_WARM           = 'warm';
  const POSITION_TOP             = 'top';
  const POSITION_LEFT            = 'left';
  const POSITION_BOTTOM          = 'bottom';
  const POSITION_RIGHT           = 'right';
  const JSON_STRICT_LEVEL_EITHER = 'either';
  const JSON_STRICT_LEVEL_ARRAY  = 'array';
  const JSON_STRICT_LEVEL_OBJECT = 'object';
  const VALUE_NO                 = 0;
  const VALUE_YES                = 1;

  protected $_colorSets = array(
    self::COLOR_SET_BRIGHT => array(
      'base' => '#5F6C7B',
      'sets' => array(
        array(
          'dark_hover'     => '#235553',
          'original_color' => '#3C807d',
          'light_fill'     => '#76A6A4',
        ),
        array(
          'dark_hover'     => '#3d5d13',
          'original_color' => '#588023',
          'light_fill'     => '#8aa665',
        ),
        array(
          'dark_hover'     => '#411045',
          'original_color' => '#662E6B',
          'light_fill'     => '#946c97',
        ),
        array(
          'dark_hover'     => '#7c1419',
          'original_color' => '#a83338',
          'light_fill'     => '#c27073',
        ),
        array(
          'dark_hover'     => '#8a3b0a',
          'original_color' => '#C05411',
          'light_fill'     => '#d38758',
        ),
      ),
    ),
    self::COLOR_SET_COOL => array(
      'base' => '#5F6C7B',
      'sets' => array(
        array(
          'dark_hover'     => '#3d5d13',
          'original_color' => '#588023',
          'light_fill'     => '#8aa665',
        ),
        array(
          'dark_hover'     => '#235553',
          'original_color' => '#3c807d',
          'light_fill'     => '#76a6a4',
        ),
        array(
          'dark_hover'     => '#2d6c9d',
          'original_color' => '#397AAC',
          'light_fill'     => '#74A2C5',
        ),
        array(
          'dark_hover'     => '#411045',
          'original_color' => '#662E6B',
          'light_fill'     => '#946c97',
        ),
        array(
          'dark_hover'     => '#795706',
          'original_color' => '#9A6F09',
          'light_fill'     => '#b89a52',
        ),
      ),
    ),
    self::COLOR_SET_WARM => array(
      'base' => '#5F6C7B',
      'sets' => array(
        array(
          'dark_hover'     => '#7c1419',
          'original_color' => '#a83338',
          'light_fill'     => '#c27073',
        ),
        array(
          'dark_hover'     => '#8a3b0a',
          'original_color' => '#C05411',
          'light_fill'     => '#d38758',
        ),
        array(
          'dark_hover'     => '#795706',
          'original_color' => '#9A6F09',
          'light_fill'     => '#b89a52',
        ),
        array(
          'dark_hover'     => '#3d5d13',
          'original_color' => '#588023',
          'light_fill'     => '#8aa665',
        ),
        array(
          'dark_hover'     => '#411045',
          'original_color' => '#662E6B',
          'light_fill'     => '#946c97',
        ),
      ),
    ),
  );

  public function values() {
    $values = array(
      'settings' => array(
        'color_set' => self::COLOR_SET_BRIGHT,
        'animation_duration' => '',
        'title' => array(
          'display'    => 1,
          'position'   => self::POSITION_TOP,
          'full_width' => 1,
          'font_size'  => '',
        ),
        'legend' => array(
          'display'    => 1,
          'position'   => self::POSITION_TOP,
          'full_width' => 1,
          'font_size'  => '',
        ),
        'axes' => array(
          'x_axes_label' => '',
          'y_axes_label' => '',
        ),
        'tooltips' => array(
          'enabled' => 1,
        ),
        'data_table' => array(
          'toggle' => self::VALUE_YES,
          'hide_table' => self::VALUE_YES,
        ),
        'advanced_options' => array(
          'json' => '{"maintainAspectRatio":false}',
        ),
      ),
      'chart_object' => '',
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
  public function form($bean, $form, &$form_state) {;
    $form = array();

    $form['settings'] = array(
      '#type'  => 'fieldset',
      '#title' => t('Standard Chart Settings'),
      '#tree'  => 1,
    );

    // Color sets.
    $form['settings']['color_set'] = array(
      '#type' => 'select',
      '#title' => t('Color Set'),
      '#options' => array(
        self::COLOR_SET_BRIGHT => t('Bright'),
        self::COLOR_SET_COOL   => t('Cool'),
        self::COLOR_SET_WARM   => t('Warm'),
      ),
      '#default_value' => $bean->settings['color_set'],
    );

    $form['settings']['animation_duration'] = array(
      '#type' => 'textfield',
      '#title' => t('Animation Duration'),
      '#description' => t('In milliseconds. Enter 0 to disable animation'),
      '#default_value' => $bean->settings['animation_duration'],
      '#size' => 10,
      '#element_validate' => array('element_validate_integer'),
    );

    // Title Options.
    $form['settings']['title'] = array(
      '#type'  => 'fieldset',
      '#title' => t('Title Options'),
      '#tree'  => 1,
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $form['settings']['title']['display'] = array(
      '#type' => 'select',
      '#title' => t('Display'),
      '#options' => array(
        self::VALUE_YES => t('Yes'),
        self::VALUE_NO  => t('No'),
      ),
      '#default_value' => $bean->settings['title']['display'],
    );

    // Legend Options.
    $form['settings']['legend'] = array(
      '#type'  => 'fieldset',
      '#title' => t('Legend Settings'),
      '#tree'  => 1,
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $form['settings']['legend']['display'] = array(
      '#type' => 'select',
      '#title' => t('Display'),
      '#options' => array(
        self::VALUE_YES => t('Yes'),
        self::VALUE_NO  => t('No'),
      ),
      '#default_value' => $bean->settings['legend']['display'],
    );
    $form['settings']['legend']['position'] = array(
      '#type' => 'select',
      '#title' => t('Position'),
      '#options' => array(
        self::POSITION_TOP    => t('Top'),
        self::POSITION_LEFT   => t('Left'),
        self::POSITION_BOTTOM => t('Bottom'),
        self::POSITION_RIGHT  => t('Right'),
      ),
      '#default_value' => $bean->settings['legend']['position'],
      '#states' => array(
        'visible' => array(':input[name="settings[legend][display]"]' => array('value' => 1))
      ),
    );
    $form['settings']['legend']['full_width'] = array(
      '#type' => 'select',
      '#title' => t('Full Width'),
      '#desciprtion' => t('Marks that this box should take the full width of the canvas (pushing down other boxes)'),
      '#options' => array(
        self::VALUE_YES => t('Yes'),
        self::VALUE_NO  => t('No'),
      ),
      '#default_value' => $bean->settings['legend']['full_width'],
    );

    // Axes Labels
    $form['settings']['axes'] = array(
      '#type' => 'fieldset',
      '#title' => t('Axes Labels'),
      '#tree'  => 1,
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $form['settings']['axes']['x_axes_label'] = array(
      '#type'          => 'textfield',
      '#title'         => t('X Axis'),
      '#default_value' => $bean->settings['axes']['x_axes_label'],
    );
    $form['settings']['axes']['y_axes_label'] = array(
      '#type'          => 'textfield',
      '#title'         => t('Y Axis'),
      '#default_value' => $bean->settings['axes']['y_axes_label'],
    );

    // Tooltip.
    $form['settings']['tooltips'] = array(
      '#type'  => 'fieldset',
      '#title' => t('Tooltip Settings'),
      '#tree'  => 1,
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $form['settings']['tooltips']['enabled'] = array(
      '#type' => 'select',
      '#title' => t('Enabled'),
      '#options' => array(
        self::VALUE_YES => t('Yes'),
        self::VALUE_NO  => t('No'),
      ),
      '#default_value' => $bean->settings['tooltips']['enabled'],
    );

    // Data Table Display
    $form['settings']['data_table'] = array(
      '#type' => 'fieldset',
      '#title' => t('Data Table Display'),
      '#tree'  => 1,
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $form['settings']['data_table']['toggle'] = array(
      '#type' => 'select',
      '#title' => t('Enable Toggle'),
      '#options' => array(
        self::VALUE_YES => t('Yes'),
        self::VALUE_NO  => t('No'),
      ),
      '#default_value' => $bean->settings['data_table']['toggle'],
    );
    $form['settings']['data_table']['hide_table'] = array(
      '#type' => 'select',
      '#title' => t('Hide Data Table on Page Load'),
      '#options' => array(
        self::VALUE_YES => t('Yes'),
        self::VALUE_NO  => t('No'),
      ),
      '#default_value' => $bean->settings['data_table']['hide_table'],
      '#states' => array(
        'visible' => array(':input[name="settings[data_table][toggle]"]' => array('value' => 1))
      ),
    );

    // Advanced Options
    $form['settings']['advanced_options'] = array(
      '#type'  => 'fieldset',
      '#title' => t('Advanced Options'),
      '#tree'  => 1,
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $form['settings']['advanced_options']['json'] = array(
      '#type'  => 'textarea',
      '#title' => t('JSON that will set all available options for the chart.  For more information, see <a href="http://www.chartjs.org/docs/">http://www.chartjs.org/docs/</a>.'),
      '#default_value' => $bean->settings['advanced_options']['json'],
    );
    return $form;
  }

  /**
   * The plugin validation function
   */
  public function validate($values, &$form_state) {
    if (!empty($values['settings']['advanced_options']['json']) && !$this->_isValidJson($values['settings']['advanced_options']['json'], self::JSON_STRICT_LEVEL_OBJECT)) {
      form_set_error('settings][advanced_options][json', '<em>Advanced Options</em> must be valid JSON.');
    }

    if (isset($values['field_chart_data']) && is_array($values['field_chart_data'])) {
      if (!$this->_validateChartData($values['field_chart_data']['und'][0]['tablefield'])) {
        form_set_error('field_chart_data', '<em>Char Data</em> is invalid.  Make sure only numeric values are inserted in the data cells.');
      }
    } else {
      form_set_error('field_chart_data', '<em>Chart Data</em> must have data.');
    }
  }

  /**
   * React to a bean being saved
   *
   * @param Bean $bean
   */
  public function submit(Bean $bean) {
    $chartObject = $this->_buildChartObject($bean);
    $bean->data['chart_object'] = json_encode($chartObject);
    return $this;
  }

  /**
   * Return the block content.
   *
   * @param        $bean
   *   The bean object being viewed.
   * @param        $content
   *   The default content array created by Entity API.  This will include any
   *   fields attached to the entity.
   * @param string $view_mode
   *   The view mode passed into $entity->view().
   *
   * @param null   $langcode
   *
   * @return
   *   Return a renderable content array.
   */
  public function view($bean, $content, $view_mode = 'default', $langcode = NULL) {
    $variables = array(
      'chart_object' => $bean->chart_object,
      'chart_type'   => $this->_getJsChartType($bean),
      'bid'          => $bean->bid,
      'table_data'   => $bean->field_chart_data[LANGUAGE_NONE][0]['tabledata'],
      'toggle_table' => isset($bean->settings['data_table']['toggle']) ? $bean->settings['data_table']['toggle'] : TRUE,
      'hide_table'   => isset($bean->settings['data_table']['hide_table']) ? $bean->settings['data_table']['hide_table'] : TRUE,
      'bean'         => $bean,
      'show_title'   => isset($bean->settings['title']['display']) ? $bean->settings['title']['display'] : TRUE,
    );
    $variables = $this->_modifyViewVariables($variables, $bean);
    $settings = array('chart_object' => drupal_json_decode($bean->chart_object));
    $settings = $this->_modifyJsSettings($settings, $bean);
    $jsSettings = array(
      'nc_charts' => array(
        'nc-chart-' . $bean->bid  => $settings,
      ),
    );
    $jsPath = drupal_get_path('module', 'nc_charts') . '/js/';
    return array(
      '#markup' =>  theme('nc_charts_chart', $variables),
      '#attached' => array(
        'js' => array(
          array(
            'type' => 'file',
            'data' => $jsPath . 'Chart.bundle.min.js'
          ),
          array(
            'type' => 'setting',
            'data' => $jsSettings,
          ),
          array(
            'type' => 'file',
            'data' => $jsPath . 'nc_charts.js',
          )
        ),
      ),
    );
  }

  /**
   * Returns a color set.
   */
  public function getColorSet($name) {
    if (isset($this->_colorSets[$name])) {
      return $this->_colorSets[$name];
    }
    return FALSE;
  }

  /**
   * Returns the type name for the JS for the chart to be made.
   */
  abstract protected function _getJsChartType(Bean $bean);

  /**
   * Returns the data sets to be used in the Chart object.
   */
  abstract protected function _getJsData(Bean $bean);

  /**
   * Returns the options for the JS Object.
   */
  protected function _getJsOptions(Bean $bean) {
    $colorSet = $this->getColorSet($bean->settings['color_set']);
    $options = array();

    if ($bean->settings['animation_duration'] !== '') {
      $options['animation']['duration'] = $bean->settings['animation_duration'];
    }

    if ($bean->settings['axes']['x_axes_label']) {
      $options['scales']['xAxes'] = array(
        array(
          'display' => TRUE,
          'scaleLabel' => array(
            'display' => TRUE,
            'labelString' => $bean->settings['axes']['x_axes_label'],
          ),
        ),
      );
    }

    if ($bean->settings['axes']['y_axes_label']) {
      $options['scales']['yAxes'] = array(
        array(
          'display' => TRUE,
            'scaleLabel' => array(
            'display'    => TRUE,
            'labelString' => $bean->settings['axes']['y_axes_label'],
          ),
        ),
      );
    }

    // Legend Options.
    if ($bean->settings['legend']['display']) {
      $options['legend'] = array(
        'display'   => TRUE,
        'position'  => $bean->settings['legend']['position'],
        'fullWidth' => $bean->settings['legend']['full_width'] ? TRUE : FALSE,
        'labels'    => array(
          'fontColor' => $colorSet['base'],
        ),
      );
    } else {
      $options['legend'] = array(
        'display' => FALSE,
      );
    }

    // Tooltips options.
    $options['tooltips']['enabled'] = $bean->settings['tooltips']['enabled'] ? TRUE : FALSE;

    // Hide title inside of canvas element
    $options['title'] = array(
      'display' => FALSE,
    );

    $options = $this->_getJsTypeOptions($options, $bean);

    // Merge in advanced options.
    if (!empty($bean->settings['advanced_options']['json'])) {
      $advancedOptions = json_decode($bean->settings['advanced_options']['json'], TRUE);
      $options = array_replace_recursive($options, $advancedOptions);
    }

    return $options;
  }

  /**
   * Updates the options array to have the options that are specific to the chart type.
   */
  protected function _getJsTypeOptions(array $options, Bean $bean) {
    return $options;
  }

  /**
   * Builds the chart object to be used in JS.
   */
  protected function _buildChartObject(Bean $bean) {
    $chartObject = array(
      'type'    => $this->_getJsChartType($bean),
      'data'    => $this->_getJsData($bean),
      'options' => $this->_getJsOptions($bean),
    );
    return $chartObject;
  }

  /**
   * Checks if the passed value is valid JSON or not.
   */
  protected function _isValidJson($value, $strictLevel = self::JSON_STRICT_LEVEL_EITHER) {
    if (!is_string($value)) {
      return FALSE;
    }
    $decoded = json_decode($value);
    switch ($strictLevel) {
      case self::JSON_STRICT_LEVEL_ARRAY:
        return is_array($decoded);
        break;
      case self::JSON_STRICT_LEVEL_OBJECT:
        return is_object($decoded);
        break;
      default:
        return is_object($decoded) || is_array($decoded);
        break;
    }
  }

  /**
   * Validates that only numeric data is in the data cells.
   */
  protected function _validateChartData(array $chartDataField) {
    foreach ($chartDataField as $key => $data) {
      $cellInfo = explode('_', $key);
      // We only care about data that is on a cell.
      if (count($cellInfo) !=3 || $cellInfo[0] !== 'cell') {
        continue;
      }
      // Check cells that are not in the header row or the first column and make sure they contain a number.
      if ($cellInfo[1] != '0' && $cellInfo[2] != '0' && !empty($data) && !is_numeric($data)) {
        return FALSE;
      }
     }
    return TRUE;
  }

  /**
   * Allows overrides of the variables being passed to the theme function.
   */
  protected function _modifyViewVariables(array $variables, Bean $bean)
  {
    return $variables;
  }

  /**
   * Allows ovrrides of the settings being passed to the JS that will make the chart.
   */
  protected function _modifyJsSettings(array $settings, Bean $bean)
  {
    return $settings;
  }

  /**
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
   *  'Foo' => array(
   *    2017 => 23,
   *    2018 => 35,
   *    2019 => 40,
   *  ),
   *  'Bar' => array(
   *    2017 => 35,
   *    2018 => 50,
   *    2019 => 30,
   *  ),
   * ),
   *
   */
  protected function _groupData(array $dataField) {
    $groupedData = array();
    $columnMap = array();
    $rowMap = array();
    foreach ($dataField as $cellName => $data) {
      $cell = explode('_', $cellName);
      if (count($cell) != 3 || $cell[0] !== 'cell') {
        continue;
      }
      // If we are on the first row.
      if ($cell[1] == '0') {
        // Skip the first cell.
        if ($cell[2]== '0') {
          continue;
        }
        $columnMap[$cell[2]] = $data;
        // If we are in the first column.
      } else if ($cell[2] == '0') {
        $groupedData[$data] = array();
        $rowMap[$cell[1]] = $data;
      } else {
        $row = $rowMap[$cell[1]];
        $column = $columnMap[$cell[2]];
        $groupedData[$row][$column] = $data;
      }
    }
    return $groupedData;
  }
}