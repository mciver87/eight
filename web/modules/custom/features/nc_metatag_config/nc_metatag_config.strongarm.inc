<?php
/**
 * @file
 * nc_metatag_config.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function nc_metatag_config_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'metatag_enable_node';
  $strongarm->value = TRUE;
  $export['metatag_enable_node'] = $strongarm;

  return $export;
}
