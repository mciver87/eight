<?php
/**
 * @file
 * nc_layout.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nc_layout_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_context_default_contexts_alter().
 */
function nc_layout_context_default_contexts_alter(&$data) {
  if (isset($data['leadership'])) {
    unset($data['leadership']->conditions['path']);
  }
}
