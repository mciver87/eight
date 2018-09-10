<?php
/**
 * @file
 * nc_google_analytics_anonymize.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function nc_google_analytics_anonymize_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'googleanalytics_tracker_anonymizeip';
  $strongarm->value = 1;
  $export['googleanalytics_tracker_anonymizeip'] = $strongarm;

  return $export;
}
