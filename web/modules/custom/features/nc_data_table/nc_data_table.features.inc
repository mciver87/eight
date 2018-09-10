<?php
/**
 * @file
 * nc_data_table.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nc_data_table_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function nc_data_table_node_info() {
  $items = array(
    'data_table' => array(
      'name' => t('Data Table'),
      'base' => 'node_content',
      'description' => t('Content that contains a data table'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
