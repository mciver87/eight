<?php
/**
 * @file
 * Declares our migrations.
 */

/**
 * Implements hook_migrate_api().
 */
function nc_migrate_dhhs_migrate_api() {
  // Required for migration registrations.
  $items['api'] = 2;

  // Stub migrations array.
  $items['migrations'] = array();
  $migrations = &$items['migrations'];

  // Return migration tasks.
  $items['groups']['dhhs'] = array(
    'title' => t('DHHS'),
    'default_format' => 'full_html',
  );
  $migrations['MigrateDHHSDocuments'] = array(
    'class_name' => 'MigrateDHHSDocuments',
    'group_name' => 'dhhs',
  );
  $migrations['MigrateDHHSPressReleases'] = array(
    'class_name' => 'MigrateDHHSPressReleases',
    'group_name' => 'dhhs',
  );

  return $items;
}
