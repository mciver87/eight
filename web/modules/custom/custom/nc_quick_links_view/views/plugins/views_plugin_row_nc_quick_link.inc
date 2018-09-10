<?php
class views_plugin_row_nc_quick_link extends views_plugin_row {

  static protected $_row_index_tracker = array();

  /**
   * Declare that options are set for this plugin.
   */
  public function option_definition() {
    $options = parent::option_definition();
    $options['link_title'] = array('default' => '');
    $options['link_date'] = array('default' => '');
    return $options;
  }

  /**
   * Build options form.
   */
  public function options_form(&$form, &$form_state) {
    $initial_labels = array('' => t('- None -'));
    $view_fields_labels = $this->display->handler->get_field_labels();
    $view_fields_labels = array_merge($initial_labels, $view_fields_labels);

    $form['link_title'] = array(
      '#type' => 'select',
      '#title' => t('Link Title'),
      '#description' => t("The field that is going to be used as the link's title for each row."),
      '#options' => $view_fields_labels,
      '#default_value' => $this->options['link_title'],
      '#required' => TRUE,
    );
    $form['link_date'] = array(
      '#type' => 'select',
      '#title' => t('Date Field'),
      '#description' => t('The field that is going to be used as the date, if there is one.'),
      '#options' => $view_fields_labels,
      '#default_value' => $this->options['link_date'],
    );
  }

  /**
   * Validate the options form.
   */
  public function validate() {
    $errors = parent::validate();
    $required_options = array(
      'link_title',
    );
    foreach ($required_options as $required_option) {
      if (empty($this->options[$required_option])) {
        $errors[] = t('Row style plugin requires specifying which views fields to use for link item.');
        break;
      }
    }
    return $errors;
  }

  /**
   * Render a row object. This usually passes through to a theme template
   * of some form, but not always.
   *
   * Even though this is a public method, it should never be called on its own.
   * This is due to the poorly programed Views module.  It should only be called
   * when rendering the entire result set.  If not, their is a chance that the
   * incorrect information will be displayed.
   *
   * @param stdClass $row
   *   A single row of the query result, so an element of $view->result.
   *
   * @return string
   *   The rendered output of a single row, used by the style plugin.
   */
  public function render($row) {
    $row_index = $this->_get_row_index($row, $this->view);
    $link_date = '';
    $link_date_field = FALSE;
    $date_time = '';
    if ($this->options['link_date']) {
      $link_date_field = $this->get_field($row_index, $this->options['link_date']);
      if (is_array($link_date_field) && isset($link_date_field[0]) && isset($link_date_field[0]['value'])) {
        $timezone = isset($link_date_field[0]['timezone']) ? $link_date_field[0]['timezone'] : NULL;
        $time = $link_date_field[0]['value'];
        if (!is_numeric($time)) {
          $time = strtotime($time);
        }
        $date_time = format_date($time, 'custom', 'c', $timezone);

        $time2 = FALSE;
        if (isset($link_date_field[0]['value2']) && $link_date_field[0]['value2'] != $link_date_field[0]['value']) {
          $time2 = $link_date_field[0]['value2'];
          if (!is_numeric($time2)) {
            $time2 = strtotime($time2);
          }
        }

        $link_date = format_date($time, 'custom', 'M j', $timezone);
        if ($time2) {
          $date2 = format_date($time2, 'custom', 'M j', $timezone);
          if ($date2 !== $link_date) {
            $link_date .= ' - ' . $date2;
          }
        }
      }
    }

    $variables = array(
      'view' => $this->view,
      'options' => $this->options,
      'row' => $row,
      'field_alias' => isset($this->field_alias) ? $this->field_alias : '',
      'link_title' => $this->get_field($row_index, $this->options['link_title']),
      'link_date' => $link_date,
      'link_url' => url('node/' . $row->nid),
      'link_date_field' => $link_date_field,
      'date_time' => $date_time,
    );

    return theme($this->theme_functions(), $variables);
  }

  /**
   * Finds the passed row's index.
   */
  protected function _get_row_index($row, $view) {
    $view_id = $view->vid;
    $view_display = $view->current_display;
    $nid = $row->nid;
    if (!isset(self::$_row_index_tracker[$view_id])) {
      self::$_row_index_tracker[$view_id] = array();
    }

    if (!isset(self::$_row_index_tracker[$view_id][$view_display])) {
      self::$_row_index_tracker[$view_id][$view_display] = array();
    }

    if (!isset(self::$_row_index_tracker[$view_id][$view_display][$nid])) {
      $index = count(self::$_row_index_tracker[$view_id][$view_display]);
      self::$_row_index_tracker[$view_id][$view_display][$nid] = $index;
    }

    return self::$_row_index_tracker[$view_id][$view_display][$nid];
  }

  /**
   * Retrieves a views field value from the style plugin.
   */
  public function get_field($index, $field_id) {
    if (empty($this->view->field[$field_id]) || !is_object($this->view->field[$field_id]) || empty($field_id)) {
      return NULL;
    }
    return $this->view->field[$field_id]->get_value($this->view->result[$index]);
  }
}
