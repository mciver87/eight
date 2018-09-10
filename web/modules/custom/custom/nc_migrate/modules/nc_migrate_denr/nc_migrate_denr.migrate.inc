<?php
/**
 * @file
 * Declares our migrations.
 */

/**
 * Implements hook_migrate_api().
 */
function nc_migrate_denr_migrate_api() {
  // Required for migration registrations.
  $items['api'] = 2;

  // Stub migrations array.
  $items['migrations'] = array();
  $migrations = &$items['migrations'];

  // Return migration tasks.
  $items['groups']['denr'] = array(
    'title' => t('DENR'),
    'default_format' => 'full_html',
  );
  $migrations['MigrateDENRPages'] = array(
    'class_name' => 'MigrateDENRPages',
    'group_name' => 'denr',
    'soft_dependencies' => array(
      'MigrateDENRDocuments',
    ),
  );
  $migrations['MigrateDENRPageMenu'] = array(
    'class_name' => 'MigrateDENRPageMenu',
    'group_name' => 'denr',
    'soft_dependencies' => array(
      'MigrateDENRPages',
    ),
  );
  $migrations['MigrateDENRDocuments'] = array(
    'class_name' => 'MigrateDENRDocuments',
    'group_name' => 'denr',
  );
  return $items;
}
