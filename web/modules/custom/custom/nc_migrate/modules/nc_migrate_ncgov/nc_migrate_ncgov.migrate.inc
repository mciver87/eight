<?php
/**
 * @file
 * Declares our migrations.
 */

/**
 * Implements hook_migrate_api().
 */
function nc_migrate_ncgov_migrate_api() {
  // Required for migration registrations.
  $items['api'] = 2;

  // Stub migrations array.
  $items['migrations'] = array();
  $migrations = &$items['migrations'];

  // NC.gov migrations.
  $items['groups']['ncgov'] = array(
    'title' => t('NC.gov'),
    'default_format' => 'full_html',
  );
  $migrations['MigrateNCGovAgencies'] = array(
    'class_name' => 'MigrateNCGovAgencies',
    'group_name' => 'ncgov',
  );
  $migrations['MigrateNCGovServices'] = array(
    'class_name' => 'MigrateNCGovServices',
    'group_name' => 'ncgov',
  );

  return $items;
}
