<?php
/**
 * @file
 * View plugin file for NC Quick Links View
 */

class views_plugin_style_nc_quick_links extends views_plugin_style {

  const DISPLAY_MODIFIER_NORMAL = 'normal';
  const DISPLAY_MODIFIER_PRIMARY_INVERTED = 'primary_inverted';
  const DISPLAY_MODIFIER_ACCENT_INVERTED = 'accent_inverted';

  public function option_definition() {
    $options = parent::option_definition();
    $options['display_modifier'] = array('default' => self::DISPLAY_MODIFIER_NORMAL);
    return $options;
  }

  /**
   * Provide a form to edit options for this plugin.
   */
  public function options_form(&$form, &$form_state)
  {
    parent::options_form($form, $form_state);
    $form['display_modifier'] = array(
      '#type' => 'select',
      '#title' => t('Display Modifier'),
      '#options' => array(
        self::DISPLAY_MODIFIER_NORMAL => t('Normal'),
        self::DISPLAY_MODIFIER_PRIMARY_INVERTED => t('Primary Inverted'),
        self::DISPLAY_MODIFIER_ACCENT_INVERTED => t('Accent Inverted'),
      ),
      '#default_value' => $this->options['display_modifier'],
    );
  }

  public function render() {
    foreach ($this->view->result as $row) {
      $rows[] = $this->row_plugin->render($row);
    }
    $variables = array(
      'view' => $this->view,
      'options' => $this->options,
      'rows' => $rows,
      'title' => $this->display->display_options['title'],
    );
    return theme($this->theme_functions(), $variables);
  }
}
