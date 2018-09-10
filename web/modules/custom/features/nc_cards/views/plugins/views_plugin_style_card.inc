<?php
/**
 * @file
 * Views style base plugin for Cards.
 */

class views_plugin_style_card extends views_plugin_style {
  /**
   * Set default options
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['columns'] = array('default' => '');
    $options['padding'] = array('default' => '');
    return $options;
  }

  /**
   * Render the options form.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['columns'] = array(
      '#type' => 'select',
      '#title' => t('Columns'),
      '#description' => t('The number of columns.'),
      '#options' => array('1', '2', '3', '4'),
      '#default_value' => $this->options['columns'],
      '#required' => TRUE,
    );
    $form['padding'] = array(
      '#type' => 'checkbox',
      '#title' => 'Padding none',
      '#description' => t('Removes the band padding.'),
      '#default_value' => $this->options['padding'],
    );
  }

  /**
   * Render the View style.
   */
  function render() {
    if (empty($this->row_plugin)) {
      vpr('views_plugin_style_default: Missing row plugin');
      return;
    }
    $rows = '';

    foreach ($this->view->result as $row_index => $row) {
      $this->view->row_index = $row_index;
      $rows .= $this->row_plugin->render($row);
    }

    $class = '';
    switch ($this->options['columns']) {
      case '1':
        $class = 'parts-span-half';
        break;

      case '2':
        $class = 'parts-span-third';
        break;

      case '3':
        $class = 'parts-span-fourth';
        break;
    }
    $pad = !empty($this->options['padding']) ? 'pad-none' : '';
    $build = array(
      '#prefix' => '<section class="band ' . $pad . '"><section class="' . $class . '">',
      '#suffix' => '</section></section>',
      '#suffic' => '</section></section>',
      'rows' => array(
        '#markup' => $rows,
      ),
    );
    $output = drupal_render($build);
    return $output;
  }
}
