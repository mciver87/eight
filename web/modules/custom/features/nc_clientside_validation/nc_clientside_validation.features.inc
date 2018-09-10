<?php
/**
 * @file
 * nc_clientside_validation.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nc_clientside_validation_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
