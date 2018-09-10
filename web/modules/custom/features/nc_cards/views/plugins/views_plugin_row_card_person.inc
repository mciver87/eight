<?php
/**
 * @file
 * Views row plugin for Person cards.
 */

class views_plugin_row_card_person extends views_plugin_row {
  /**
   * Declare that options are set for this plugin.
   */
  public function option_definition() {
    $options = parent::option_definition();
    $options['card_title'] = array('default' => '');
    $options['card_name'] = array('default' => '');
    $options['card_link'] = array('default' => '');
    $options['card_image'] = array('default' => '');
    $options['card_framed'] = array('default' => '');
    return $options;
  }

  /**
   * Build options form.
   */
  public function options_form(&$form, &$form_state) {
    $initial_labels = array('' => t('- None -'));
    $view_fields_labels = $this->display->handler->get_field_labels();
    $view_fields_labels = array_merge($initial_labels, $view_fields_labels);

    $form['card_name'] = array(
      '#type' => 'select',
      '#title' => t('Person name'),
      '#description' => t('The field that is going to be used as the Person name for each row.'),
      '#options' => $view_fields_labels,
      '#default_value' => $this->options['card_title'],
      '#required' => TRUE,
    );
    $form['card_title'] = array(
      '#type' => 'select',
      '#title' => t('Person title'),
      '#description' => t('The field that is going to be used as the title for each row.'),
      '#options' => $view_fields_labels,
      '#default_value' => $this->options['card_title'],
      '#required' => TRUE,
    );
    $form['card_link'] = array(
      '#type' => 'select',
      '#title' => t('Person link'),
      '#description' => t('The field that is going to be used as the link for each row. This must be a valid absolute or relative url.'),
      '#options' => $view_fields_labels,
      '#default_value' => $this->options['card_link'],
    );
    $form['card_image'] = array(
      '#type' => 'select',
      '#title' => t('Person image'),
      '#description' => t('The field that is going to be used as the image for each row.'),
      '#options' => $view_fields_labels,
      '#default_value' => $this->options['card_image'],
    );
    $form['card_framed'] = array(
      '#type' => 'select',
      '#title' => t('Framed'),
      '#description' => t('Whether or not to frame the card.'),
      '#options' => $view_fields_labels,
      '#default_value' => $this->options['card_framed'],
    );
  }

  /**
   * Validate the options form.
   */
  public function validate() {
    $errors = parent::validate();
    $required_options = array(
      'card_title',
    );
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
    $item['card_title'] = $this->get_field($row_index, $this->options['card_title']);
    if (($this->get_field($row_index, $this->options['card_link']))) {
      $item['card_link'] = url($this->get_field($row_index, $this->options['card_link']), array('absolute' => TRUE));
    }
    $item['card_name'] = $this->get_field($row_index, $this->options['card_name']);
    $item['card_image'] = $this->get_field($row_index, $this->options['card_image']);
    if ($this->get_field($row_index, $this->options['card_framed'])) {
      $item['card_framed'] = 'framed';
    }

    $row_index++;
    return theme('nc_card_person', $item);
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
