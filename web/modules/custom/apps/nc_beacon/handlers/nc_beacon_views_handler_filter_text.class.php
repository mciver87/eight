<?php
/**
 * @file
 *
 * Basic filter that provide a search string to be passed to query URL.
 */

class nc_beacon_views_handler_filter_text extends views_handler_filter {
  /**
   * Provide a simple textfield for equality
   */
  function value_form(&$form, &$form_state) {
    $form['value'] = array(
      '#type' => 'textfield',
      '#title' => t('Value'),
      '#size' => 30,
      '#default_value' => $this->value,
    );
    if (!empty($form_state['exposed'])) {
      $identifier = $this->options['expose']['identifier'];
      if (!isset($form_state['input'][$identifier])) {
        $form_state['input'][$identifier] = $this->value;
      }
    }

    if (!isset($form['value'])) {
      // Ensure there is something in the 'value'.
      $form['value'] = array(
        '#type' => 'value',
        '#value' => NULL
      );
    }
  }

  /**
   * Add this filter to the query.
   */
  function query() {
    $this->query->add_where($this->options['group'], strtolower($this->real_field), $this->value);
  }
}
