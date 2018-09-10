<?php
/**
 * @file
 * nc_webform.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nc_webform_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_strongarm_alter().
 */
function nc_webform_strongarm_alter(&$data) {
  if (isset($data['node_preview_webform'])) {
    $data['node_preview_webform']->value = 0; /* WAS: 1 */
  }
  if (isset($data['node_submitted_webform'])) {
    $data['node_submitted_webform']->value = 0; /* WAS: 1 */
  }
}
