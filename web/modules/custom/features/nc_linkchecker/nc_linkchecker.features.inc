<?php
/**
 * @file
 * nc_linkchecker.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nc_linkchecker_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
