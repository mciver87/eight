<?php
/**
 * @file
 * Sets up the views plugin for NC Quick Links View.
 */

/**
 * Implements hook_views_plugins().
 */
function nc_quick_links_view_views_plugins() {
  return array(
    'style' => array(
      'nc_quick_links' => array(
        'title' => t('Quick Links'),
        'help' => t('Displays the content in a simple, already styled, list. Best suited for very few fields being displayed.'),
        'handler' => 'views_plugin_style_nc_quick_links',
        'uses options' => TRUE,
        'theme' => 'views_nc_quick_links',
        'uses fields' => TRUE,
        'even empty' => TRUE,
        'uses row plugin' => TRUE,
        'type' => 'normal',
      ),
    ),
    'row' => array(
      'nc_quick_link' => array(
        'title' => t('Quick Link'),
        'help' => t("A preformatted link containing the title of a node and it's possible date."),
        'handler' => 'views_plugin_row_nc_quick_link',
        'uses fields' => TRUE,
        'uses options' => TRUE,
        'type' => 'normal',
        'theme' => 'views_nc_quick_link',
      ),
    ),
  );
}

/**
 * Implements template_preprocess_THEME().
 */
function template_preprocess_views_nc_quick_links(&$variables) {
  if (isset($variables['options']) && isset($variables['options']['display_modifier'])) {
    switch ($variables['options']['display_modifier']) {
      case views_plugin_style_nc_quick_links::DISPLAY_MODIFIER_ACCENT_INVERTED:
        $variables['classes_array'][] = 'accent inverted';
        break;

      case views_plugin_style_nc_quick_links::DISPLAY_MODIFIER_PRIMARY_INVERTED:
        $variables['classes_array'][] = 'primary inverted';
        break;
    }
  }
}
