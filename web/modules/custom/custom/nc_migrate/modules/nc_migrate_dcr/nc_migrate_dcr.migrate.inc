<?php
/**
 * @file
 * Declares our migrations.
 */

/**
 * Implements hook_migrate_api().
 */
function nc_migrate_dcr_migrate_api() {
  // Required for migration registrations.
  $items['api'] = 2;

  return $items;
}
