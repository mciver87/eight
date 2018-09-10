<?php
/**
 * @file
 * nc_blog_entry.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function nc_blog_entry_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_blog_author'.
  $field_bases['field_blog_author'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_blog_author',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 60,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  return $field_bases;
}
