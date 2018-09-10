<?php
/**
 * @file
 * nc_catalog.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nc_catalog_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function nc_catalog_node_info() {
  $items = array(
    'catalog' => array(
      'name' => t('Catalog Item'),
      'base' => 'node_content',
      'description' => t('Entries for site catalogs'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
