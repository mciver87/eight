<?php
/**
 * @file
 * nc_press_release.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function nc_press_release_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_region-node-press_release-default';
  $strongarm->value = array(
    'field_related_content' => 'sidebar_second',
  );
  $export['field_region-node-press_release-default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_node_options_press_release';
  $strongarm->value = array();
  $export['i18n_node_options_press_release'] = $strongarm;

  return $export;
}
