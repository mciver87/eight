<?php
/**
 * @file
 * nc_search.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function nc_search_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_key_search_topics_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_key_search_topics_pattern'] = $strongarm;

  return $export;
}
