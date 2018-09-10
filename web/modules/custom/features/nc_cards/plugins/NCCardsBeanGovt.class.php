<?php
/**
 * @file
 * NC Cards Bean plugin.
 */

class NCCardsBeanGovt extends BeanPlugin {
  /**
   * View the Bean.
   */
  public function view($bean, $content, $view_mode = 'default', $langcode = NULL) {
    // Provide variables to our theme function.
    $wrapper = entity_metadata_wrapper('bean', $bean);
    if (!empty($content['bean'][$bean->delta]['field_card_image'][0])) {
      $variables['card_image'] = $content['bean'][$bean->delta]['field_card_image'][0];
    }
    $link = $wrapper->field_card_link->value(array('sanitized' => TRUE));
    if ($link) {
      $link = _nc_cards_card_link_query_fix($link);
      $url = url($link['url'], $link);
      $variables['card_link'] = nc_cards_check_url($url);
    }
    $variables['card_link_text'] = check_plain($link['title']);
    $variables['card_title'] = $wrapper->field_card_title->value(array('sanitized' => TRUE));
    $keywords = $wrapper->field_card_keywords->value(array('sanitized' => TRUE));
    $keyword_array = array();
    // Guard against 1 result.
    if (!is_object($keywords)) {
      foreach ($keywords as $keyword) {
        $keyword_array[] = check_plain($keyword->name);
      }
      $variables['card_keywords'] = implode(', ', $keyword_array);
    }
    else {
      $variables['card_keywords'] = check_plain($keywords->name);
    }
    $build = theme('nc_card_govt', $variables);
    return $build;
  }
}
