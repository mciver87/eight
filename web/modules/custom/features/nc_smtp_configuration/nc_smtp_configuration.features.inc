<?php
/**
 * @file
 * nc_smtp_configuration.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nc_smtp_configuration_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
