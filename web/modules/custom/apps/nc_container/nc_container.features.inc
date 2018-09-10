<?php
/**
 * @file
 * nc_container.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nc_container_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function nc_container_node_info() {
  $items = array(
    'application_container' => array(
      'name' => t('Application Container'),
      'base' => 'node_content',
      'description' => t('Provides a way to create an application page with Javascript libraries, CSS files and raw markup.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
