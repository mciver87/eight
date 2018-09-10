<?php
/**
 * @file
 * nc_landing_page.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nc_landing_page_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function nc_landing_page_image_default_styles() {
  $styles = array();

  // Exported image style: band_background_image.
  $styles['band_background_image'] = array(
    'name' => 'band_background_image',
    'label' => 'Band Background Image',
    'effects' => array(),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function nc_landing_page_node_info() {
  $items = array(
    'landing_page' => array(
      'name' => t('Landing Page'),
      'base' => 'node_content',
      'description' => t('Provides a banded landing page with 1, 2, and 3 column layouts per band'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_paragraphs_info().
 */
function nc_landing_page_paragraphs_info() {
  $items = array(
    'accordion' => array(
      'name' => 'Accordion',
      'bundle' => 'accordion',
      'locked' => '1',
    ),
    'four_column' => array(
      'name' => '4-Column Band',
      'bundle' => 'four_column',
      'locked' => '1',
    ),
    'full_width' => array(
      'name' => 'Full Width',
      'bundle' => 'full_width',
      'locked' => '1',
    ),
    'tabs_accordion' => array(
      'name' => 'Tabs/Accordion',
      'bundle' => 'tabs_accordion',
      'locked' => '1',
    ),
    'three_column' => array(
      'name' => '3-Column Band',
      'bundle' => 'three_column',
      'locked' => '1',
    ),
    'two_column' => array(
      'name' => '2-Column Band',
      'bundle' => 'two_column',
      'locked' => '1',
    ),
  );
  return $items;
}
