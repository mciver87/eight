<?php
/**
 * @file
 * NC Cards Bean plugin.
 */

class NCCardsBeanInfo extends BeanPlugin {
  /**
   * View the Bean.
   */
  public function view($bean, $content, $view_mode = 'default', $langcode = NULL) {
    // Provide variables to our theme function.
    $wrapper = entity_metadata_wrapper('bean', $bean);
    $variables['card_description'] = $wrapper->field_card_description->value(array('sanitized' => TRUE));
    $variables['card_style'] = _nc_cards_info_wrapper_style_to_class($wrapper->field_info_card_style->value());
    $link = $wrapper->field_card_link->value(array('sanitized' => TRUE));
    if ($link) {
      $link = _nc_cards_card_link_query_fix($link);
      $url = url($link['url'], $link);
      $variables['card_link'] = nc_cards_check_url($url);
    }
    $variables['card_title'] = check_plain($link['title']);
    $build = theme('nc_card_info', $variables);
    return $build;
  }
}
