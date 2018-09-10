<?php
/**
 * @file
 * Declares our migrations.
 */

/**
 * Implements hook_migrate_api().
 */
function nc_migrate_oshr_migrate_api() {
  // Required for migration registrations.
  $items['api'] = 2;

  // Stub migrations array.
  $items['migrations'] = array();
  $migrations = &$items['migrations'];

  // Return migration tasks.
  $items['groups']['oshr'] = array(
    'title' => t('OSHR'),
    'default_format' => 'full_html',
  );

  $migrations['MigrateOSHRDocuments'] = array(
    'class_name' => 'MigrateOSHRDocuments',
    'group_name' => 'oshr',
  );
  $migrations['MigrateOSHRFiles'] = array(
    'class_name' => 'MigrateOSHRFiles',
    'group_name' => 'oshr',
    'soft_dependencies' => array(
      'MigrateOSHRDocuments',
    ),
  );
  $migrations['MigrateOSHRPages'] = array(
    'class_name' => 'MigrateOSHRPages',
    'group_name' => 'oshr',
    'soft_dependencies' => array(
      'MigrateOSHRDocuments',
      'MigrateOSHRFiles',
    ),
  );

  return $items;
}
