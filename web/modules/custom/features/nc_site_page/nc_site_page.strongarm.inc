<?php
/**
 * @file
 * nc_site_page.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function nc_site_page_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_region-node-site_page-default';
  $strongarm->value = array(
    'field_related_content' => 'sidebar_second',
  );
  $export['field_region-node-site_page-default'] = $strongarm;

  return $export;
}
