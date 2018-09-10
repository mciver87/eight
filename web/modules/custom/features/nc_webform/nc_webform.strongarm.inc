<?php
/**
 * @file
 * nc_webform.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function nc_webform_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'webform_disabled_components';
  $strongarm->value = array(
    0 => 'file',
  );
  $export['webform_disabled_components'] = $strongarm;

  return $export;
}
