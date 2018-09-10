<?php
/**
 * @file
 * nc_document.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function nc_document_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_region-node-document-default';
  $strongarm->value = array(
    'field_related_content' => 'sidebar_second',
  );
  $export['field_region-node-document-default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_node_options_document';
  $strongarm->value = array();
  $export['i18n_node_options_document'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_document';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_document'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_document';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_document'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_document';
  $strongarm->value = '0';
  $export['node_preview_document'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_document';
  $strongarm->value = 0;
  $export['node_submitted_document'] = $strongarm;

  return $export;
}
