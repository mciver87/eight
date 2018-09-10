<?php
/**
 * @file
 * Views row plugin for Service cards.
 */

class views_plugin_row_card_service extends views_plugin_row {
  /**
   * Declare that options are set for this plugin.
   */
  public function option_definition() {
    $options = parent::option_definition();

    $options['card_name_field'] = array('default' => '');
    $options['card_link_field'] = array('default' => '');
    $options['card_icon_class'] = array('default' => 'icon-check');
    return $options;
  }

  /**
   * Build options form.
   */
  public function options_form(&$form, &$form_state) {
    $initial_labels = array('' => t('- None -'));
    $view_fields_labels = $this->display->handler->get_field_labels();
    $view_fields_labels = array_merge($initial_labels, $view_fields_labels);

    $form['card_name_field'] = array(
      '#type' => 'select',
      '#title' => t('Name field'),
      '#description' => t('The field that is going to be used as the service name for each row.'),
      '#options' => $view_fields_labels,
      '#default_value' => $this->options['card_name_field'],
      '#required' => TRUE,
    );
    $form['card_link_field'] = array(
      '#type' => 'select',
      '#title' => t('Link field'),
      '#description' => t('The field that is going to be used as the link for each row. This must be a valid url.'),
      '#options' => $view_fields_labels,
      '#default_value' => $this->options['card_link_field'],
    );
    $form['card_icon_class'] = array(
      '#type' => 'select',
      '#title' => t('Icon classes'),
      '#description' => t('The field that is going to be used as the icon class for each row.'),
      '#options' => $view_fields_labels,
      '#default_value' => $this->options['card_icon_class'],
    );
  }

  /**
   * Validate the options form.
   */
  public function validate() {
    $errors = parent::validate();
    $required_options = array('card_name_field');
    foreach ($required_options as $required_option) {
      if (empty($this->options[$required_option])) {
        $errors[] = t('Row style plugin requires specifying which views fields to use for Card item.');
        break;
      }
    }
    return $errors;
  }

  /**
   * Render the row.
   */
  public function render($row) {
    static $row_index;
    if (!isset($row_index)) {
      $row_index = 0;
    }

    // Create the item object.;
    $item['card_name'] = $this->get_field($row_index, $this->options['card_name_field']);
    $icon = $this->get_field($row_index, $this->options['card_icon_class']);
    if ($icon) {
      $item['icon_classes'] = $icon;
    }
    else {
      $item['icon_classes'] = 'icon-check';
    }
    $item['card_link'] = url($this->get_field($row_index, $this->options['card_link_field']), array('absolute' => TRUE));

    $row_index++;
    return theme('nc_card_service', $item);
  }
  /**
   * Retrieves a views field value from the style plugin.
   */
  public function get_field($index, $field_id) {
    if (empty($this->view->style_plugin) || !is_object($this->view->style_plugin) || empty($field_id)) {
      return '';
    }
    return $this->view->style_plugin->get_field($index, $field_id);
  }
}
