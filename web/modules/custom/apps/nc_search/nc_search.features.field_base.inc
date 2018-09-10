<?php
/**
 * @file
 * nc_search.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function nc_search_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_key_search_topics'.
  $field_bases['field_key_search_topics'] = array(
    'active' => 1,
    'cardinality' => 10,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_key_search_topics',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'key_search_topics',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  return $field_bases;
}
