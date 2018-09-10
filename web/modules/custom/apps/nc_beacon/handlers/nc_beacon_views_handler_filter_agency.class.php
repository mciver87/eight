<?php
/**
 * @file
 *
 * Basic filter that provide a search string to be passed to query URL.
 */

class nc_beacon_views_handler_filter_agency extends views_handler_filter {
  var $def_agency = '';

  /**
   * Provide some extra help to get the operator/value easier to use.
   *
   * This likely has to be overridden by filters which are more complex
   * than simple operator/value.
   */
  function init(&$view, &$options) {
    parent::init($view, $options);

    $this->def_agency = variable_get('nc_beacon_default_agency', '');
  }

  /**
   * Provide a simple textfield for equality
   */
  function value_form(&$form, &$form_state) {
    $options = drupal_map_assoc($this->get_agencies());
    $form['value'] = array(
      '#type' => 'select',
      '#title' => t('Value'),
      '#options' => $options,
      '#default_value' => $this->value,
      '#required' => FALSE,
      '#multiple' => FALSE,
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
        '#value' => NULL,
      );
    }
  }

  /**
   * Render our chunk of the exposed filter form when selecting
   */
  function exposed_form(&$form, &$form_state) {
    if (empty($this->options['exposed'])) {
      return;
    }

    if (empty($this->def_agency)) {
      $options = drupal_map_assoc(nc_beacon_get_agencies());
      $form['Agency'] = array(
        '#type' => 'select',
        '#options' => $options,
        '#default_value' => $this->value,
        '#required' => FALSE,
        '#multiple' => FALSE,
        '#empty_option' => '- Any -',
        '#empty_value' => '',
      );
    }
    else {
      $form['Agency'] = array(
        '#type' => 'value',
        '#value' => $this->def_agency,
      );
    }
  }

  /**
   * Tell the renderer about our exposed form. This only needs to be
   * overridden for particularly complex forms. And maybe not even then.
   *
   * @return array|null
   *   For standard exposed filters. An array with the following keys:
   *   - operator: The $form key of the operator. Set to NULL if no operator.
   *   - value: The $form key of the value. Set to NULL if no value.
   *   - label: The label to use for this piece.
   *   For grouped exposed filters. An array with the following keys:
   *   - value: The $form key of the value. Set to NULL if no value.
   *   - label: The label to use for this piece.
   */
  function exposed_info() {
    if (empty($this->options['exposed'])) {
      return;
    }

    if ($this->is_a_group()) {
      return array(
        'value' => $this->options['group_info']['identifier'],
        'label' => $this->options['group_info']['label'],
        'description' => $this->options['group_info']['description'],
      );
    }

    return array(
      'operator' => $this->options['expose']['operator_id'],
      'value' => $this->options['expose']['identifier'],
      'label' => empty($this->def_agency) ? $this->options['expose']['label'] : '',
      'description' => empty($this->def_agency) ? $this->options['expose']['description'] : '',
    );
  }

  /**
   * Add this filter to the query.
   */
  function query() {
    $this->query->add_where($this->options['group'], strtolower($this->real_field), $this->value);
  }
}
