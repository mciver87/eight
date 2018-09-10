<?php
/**
 * @file
 * nc_division.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nc_division_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function nc_division_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function nc_division_node_info() {
  $items = array(
    'nc_division' => array(
      'name' => t('Division'),
      'base' => 'node_content',
      'description' => t('Provides the Division content type.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
