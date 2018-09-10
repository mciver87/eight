<?php
/**
 * @file
 * nc_layout.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function nc_layout_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'context_by_node_content_types';
  $strongarm->value = array(
    'landing_page' => 'landing_page',
    'press_release' => 'press_release',
    'site_page' => 'site_page',
    'agency' => 0,
    'blog_entry' => 0,
    'data_table' => 0,
    'document' => 0,
    'event' => 0,
    'media_gallery' => 0,
    'photo' => 0,
    'profile' => 0,
    'services' => 0,
    'video' => 0,
    'webform' => 0,
  );
  $export['context_by_node_content_types'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'context_by_node_hide_context_ui_admin';
  $strongarm->value = 1;
  $export['context_by_node_hide_context_ui_admin'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'context_ui_dialog_enabled';
  $strongarm->value = 1;
  $export['context_ui_dialog_enabled'] = $strongarm;

  return $export;
}
