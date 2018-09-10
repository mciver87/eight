<?php
/**
 * @file
 * nc_webform_deter.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nc_webform_deter_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "webform_deter" && $api == "default_webform_deter_pattern") {
    return array("version" => "1");
  }
}
