<?php
/**
 * @file
 * Views row plugin for Agency cards.
 */

class views_plugin_row_card_agency extends views_plugin_row {
  /**
   * Declare that options are set for this plugin.
   */
  public function option_definition() {
    $options = parent::option_definition();
    $options['card_title'] = array('default' => '');
    $options['card_link'] = array('default' => '');
    $options['card_description'] = array('default' => '');
    $options['card_link_website'] = array('default' => '');
    $options['card_link_website_title'] = array('default' => '');
    $options['social_links'] = array('default' => '');
    $options['card_keywords'] = array('default' => '');
    $options['card_prefix'] = array('default' => '');
    $options['phone'] = array('default' => '');
    $options['icon_classes'] = array('default' => '');
    return $options;
  }

  /**
   * Build options form.
   */
  public function options_form(&$form, &$form_state) {
    $initial_labels = array('' => t('- None -'));
    $view_fields_labels = $this->display->handler->get_field_labels();
    $view_fields_labels = array_merge($initial_labels, $view_fields_labels);

    $form['card_prefix'] = array(
      '#type' => 'select',
      '#title' => t('Card prefix'),
      '#description' => t('The field that is going to be used as the card prefix content.'),
      '#options' => $view_fields_labels,
      '#default_value' => $this->options['card_prefix'],
    );
    $form['card_title'] = array(
      '#type' => 'select',
      '#title' => t('Agency title'),
      '#description' => t('The field that is going to be used as the agency title for each row.'),
      '#options' => $view_fields_labels,
      '#default_value' => $this->options['card_title'],
      '#required' => TRUE,
    );
    $form['card_link'] = array(
      '#type' => 'select',
      '#title' => t('Agency link'),
      '#description' => t('The field that is going to be used as the link for each row. This must be a valid absolute or relative url.'),
      '#options' => $view_fields_labels,
      '#default_value' => $this->options['card_link'],
    );
    $form['card_description'] = array(
      '#type' => 'select',
      '#title' => t('Card description'),
      '#description' => t('The field that is going to be used as the description for each row.'),
      '#options' => $view_fields_labels,
      '#default_value' => $this->options['card_description'],
    );
    $form['card_link_website'] = array(
      '#type' => 'select',
      '#title' => t('Agency website link'),
      '#description' => t('The field that is going to be used as the agency website link for each row. This must be a valid absolute or relative url.'),
      '#options' => $view_fields_labels,
      '#default_value' => $this->options['card_link_website'],
    );
    $form['card_link_website_title'] = array(
      '#type' => 'select',
      '#title' => t('Agency website title'),
      '#description' => t('The field that is going to be used as the agency website title for each row.'),
      '#options' => $view_fields_labels,
      '#default_value' => $this->options['card_link_website_title'],
    );
    $form['card_keywords'] = array(
      '#type' => 'select',
      '#title' => t('Card keywords'),
      '#description' => t('The field that is going to be used as the agency keywords for each row.'),
      '#options' => $view_fields_labels,
      '#default_value' => $this->options['card_keywords'],
    );
    $form['social_links'] = array(
      '#type' => 'select',
      '#title' => t('Agency social links'),
      '#description' => t('The field that is going to be used as the agency website links.'),
      '#options' => $view_fields_labels,
      '#default_value' => $this->options['card_link_website'],
    );
    $form['phone'] = array(
      '#type' => 'select',
      '#title' => t('Agency phone'),
      '#description' => t('The field that is going to be used as the agency phone.'),
      '#options' => $view_fields_labels,
      '#default_value' => $this->options['phone'],
    );
    $form['icon_classes'] = array(
      '#type' => 'select',
      '#title' => t('Agency icon class'),
      '#description' => t('The field that is going to be used as the agency icon class.'),
      '#options' => $view_fields_labels,
      '#default_value' => $this->options['icon_classes'],
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
    $item['card_description'] = $this->get_field($row_index, $this->options['card_description']);
    $item['card_link_website'] = url($this->get_field($row_index, $this->options['card_link_website']), array('absolute' => TRUE));
    $item['card_link_website_title'] = $this->get_field($row_index, $this->options['card_link_website_title']);
    $item['card_keywords'] = $this->get_field($row_index, $this->options['card_keywords']);
    $item['social_links'] = $this->get_field($row_index, $this->options['social_links']);
    $item['card_prefix'] = $this->get_field($row_index, $this->options['card_prefix']);
    $item['phone'] = $this->get_field($row_index, $this->options['phone']);

    if ($icon = $this->get_field($row_index, $this->options['icon_classes'])) {
      $item['icon_classes'] = $icon;
    }
    else {
      $item['icon_classes'] = 'icon-nc-government-building';
    }

    $row_index++;
    return theme('nc_card_agency', $item);
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
