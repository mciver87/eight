<?php
/**
 * @file
 * openpublic_agency.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function openpublic_agency_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function openpublic_agency_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function openpublic_agency_node_info() {
  $items = array(
    'agency' => array(
      'name' => t('Agency'),
      'base' => 'node_content',
      'description' => t('Provide agency specific details such as contact information and website link.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
