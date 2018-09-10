<?php
/**
 * @file
 * nc_tax_type.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nc_tax_type_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function nc_tax_type_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function nc_tax_type_node_info() {
  $items = array(
    'tax_type' => array(
      'name' => t('Tax Type'),
      'base' => 'node_content',
      'description' => t('Content type for different taxes(DOR)'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
