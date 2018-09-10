<?php
/**
 * @file
 * Declares our migrations.
 */

/**
 * Implements hook_migrate_api().
 */
function nc_migrate_osbm_migrate_api() {
  // Required for migration registrations.
  $items['api'] = 2;

  // Stub migrations array.
  $items['migrations'] = array();
  $migrations = &$items['migrations'];

  // Return migration tasks.
  $items['groups']['osbm'] = array(
    'title' => t('OSBM'),
    'default_format' => 'full_html',
  );

  $migrations['MigrateOSBMDocument'] = array(
    'class_name' => 'MigrateOSBMDocument',
    'group_name' => 'osbm',
  );
  $migrations['MigrateOSBMFileCatalog'] = array(
    'class_name' => 'MigrateOSBMFileCatalog',
    'group_name' => 'osbm',
  );
  return $items;
}
