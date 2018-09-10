<?php
/**
 * @file
 * NC Cards Bean plugin.
 */

class NCCardsBeanStat extends BeanPlugin {
  /**
   * View the Bean.
   */
  public function view($bean, $content, $view_mode = 'default', $langcode = NULL) {
    // Provide variables to our theme function.
    $wrapper = entity_metadata_wrapper('bean', $bean);
    $variables['card_title'] = $wrapper->field_card_title->value(array('sanitized' => TRUE));
    $variables['card_description'] = $wrapper->field_card_description->value(array('sanitized' => TRUE));
    $variables['card_stat'] = $wrapper->field_card_stat->value(array('sanitized' => TRUE));
    $build = theme('nc_card_stat', $variables);
    return $build;
  }
}
