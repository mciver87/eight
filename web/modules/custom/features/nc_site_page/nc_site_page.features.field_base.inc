<?php
/**
 * @file
 * nc_site_page.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function nc_site_page_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_accordion_sidebar_block'.
  $field_bases['field_accordion_sidebar_block'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_accordion_sidebar_block',
    'indexes' => array(
      'moddelta' => array(
        0 => 'moddelta',
      ),
    ),
    'locked' => 0,
    'module' => 'blockreference',
    'settings' => array(
      'referenceable_modules' => array(),
    ),
    'translatable' => 0,
    'type' => 'blockreference',
  );
  
  // Exported field_base: 'field_tabs'.
  $field_bases['field_tabs'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_tabs',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'paragraphs',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'paragraphs',
  );

  return $field_bases;
}
