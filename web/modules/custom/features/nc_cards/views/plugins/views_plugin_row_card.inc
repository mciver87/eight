<?php
/**
 * @file
 * Views plugin row base class for Cards.
 */

class views_plugin_style_card extends views_plugin_row {
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
