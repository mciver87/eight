<?php
/**
 * @file
 * Declares our migrations.
 */

/**
 * Implements hook_migrate_api().
 */
function nc_migrate_oits_migrate_api() {
  // Required for migration registrations.
  $items['api'] = 2;

  // Stub migrations array.
  $items['migrations'] = array();
  $migrations = &$items['migrations'];

  // Return migration tasks.
  $items['groups']['oits'] = array(
    'title' => t('OITS'),
    'default_format' => 'full_html',
  );
  $migrations['MigrateOITSDocuments'] = array(
    'class_name' => 'MigrateOITSDocuments',
    'group_name' => 'oits',
  );
  $migrations['MigrateOITSPages'] = array(
    'class_name' => 'MigrateOITSPages',
    'group_name' => 'oits',
  );
  $migrations['MigrateOITSPressReleases'] = array(
    'class_name' => 'MigrateOITSPressReleases',
    'group_name' => 'oits',
  );

  return $items;
}
