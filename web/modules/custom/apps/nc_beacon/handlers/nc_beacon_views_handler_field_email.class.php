<?php

/**
 * @file
 * Definition of nc_beacon_views_handler_field_email.
 */

/**
 * Field handler to provide simple renderer that controls rendering an email
 * address as plain text or into a clickable link.
 *
 * @ingroup views_field_handlers
 */
class nc_beacon_views_handler_field_email extends views_handler_field {
  /**
   * Collect options for field display
   */
  function option_definition() {
    $options = parent::option_definition();

    $options['display_as_link'] = array('default' => TRUE, 'bool' => TRUE);
    $options['display_text'] = array('default' => '', 'translatable' => TRUE);

    return $options;
  }

  function options_form(&$form, &$form_state) {
    $form['display_as_link'] = array(
      '#type' => 'checkbox',
      '#title' => t('Display as link'),
      '#default_value' => !empty($this->options['display_as_link']),
    );
    $form['display_text'] = array(
      '#type' => 'textfield',
      '#title' => t('Display text'),
      '#description' => t('Alternate text to display instead of email address.  If empty, the email address will be displayed.'),
      '#default_value' => $this->options['display_text'],
    );
    parent::options_form($form, $form_state);
  }

  /**
   * Provide link for email address
   */
  function render($values) {
    $text = '';
    $value = $this->get_value($values);
    if (!empty($value)) {
      $text = ($this->options['display_as_link'] && !empty($this->options['display_text'])) ? $this->sanitize_value($this->options['display_text'], 'xss') : $this->sanitize_value($value, 'xss');
      if (!empty($this->options['display_as_link'])) {
        $this->options['alter']['make_link'] = TRUE;
        $this->options['alter']['path'] = "mailto:{$value}";
      }
    }

    return $text;
  }
}
