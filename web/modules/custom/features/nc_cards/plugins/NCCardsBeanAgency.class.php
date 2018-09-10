<?php
/**
 * @file
 * NC Cards Bean plugin.
 */

class NCCardsBeanAgency extends BeanPlugin {
  /**
   * View the Bean.
   */
  public function view($bean, $content, $view_mode = 'default', $langcode = NULL) {
    // Provide variables to our theme function.
    $wrapper = entity_metadata_wrapper('bean', $bean);
    $link = $wrapper->field_card_link->value(array('sanitized' => TRUE));
    if ($link) {
      $link = _nc_cards_card_link_query_fix($link);
      $url = url($link['url'], $link);
      $variables['card_link'] = nc_cards_check_url($url);
    }
    $variables['card_title'] = $wrapper->field_card_title->value(array('sanitized' => TRUE));
    $website_link = $wrapper->field_card_agency_website->value(array('sanitized' => TRUE));
    $variables['card_link_website'] = nc_cards_check_url($website_link['url']);
    $variables['card_link_website_title'] = check_plain($website_link['title']);
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
    $variables['card_description'] = $wrapper->field_card_description->value(array('sanitized' => TRUE));
    $social_data = $wrapper->field_card_social_links->value(array('sanitized' => TRUE));
    $icon_class = '';
    foreach ($social_data as $social_link) {
      $icon_text = "icon-" . check_plain(strtolower($social_link['title']));
      $icons = nc_cards_icon_classes();
      if (array_key_exists($icon_text, $icons)) {
        $icon_class = $icons[$icon_text];
      }
      $options = array('class' => array($icon_class));
      $attributes = drupal_attributes($options);
      $social_links[$icon_class] = array(
        '#prefix' => "<li><a href='{$social_link['url']}'>",
        '#suffix' => '</a></li>',
        'icon' => array(
          '#markup' => "<span {$attributes} aria-hidden='true'></span><span>{$social_link['title']}</span>",
        ),
      );
    }
    if (!empty($social_links)) {
      $variables['social_links'] = array(
        '#prefix' => '<ul>',
        '#suffix' => '</ul>',
        'links' => $social_links,
      );
    }
    $build = theme('nc_card_agency', $variables);
    return $build;
  }
}
