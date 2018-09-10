<?php
/**
 * @file
 * nc_microformats.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function nc_microformats_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'microdata_enabled_vocabularies';
  $strongarm->value = array(
    'schema_org' => 'schema_org',
    'google_schema_org_extensions' => 'google_schema_org_extensions',
  );
  $export['microdata_enabled_vocabularies'] = $strongarm;

  return $export;
}
