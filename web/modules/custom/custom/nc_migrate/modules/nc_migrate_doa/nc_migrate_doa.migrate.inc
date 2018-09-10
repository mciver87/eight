<?php
/**
 * @file
 * Declares our migrations.
 */

/**
 * Implements hook_migrate_api().
 */
function nc_migrate_doa_migrate_api() {
  // Required for migration registrations.
  $items['api'] = 2;

  // Stub migrations array.
  $items['migrations'] = array();
  $migrations = &$items['migrations'];

  // Return migration tasks.
  $items['groups']['doa'] = array(
    'title' => t('DOA'),
    'default_format' => 'full_html',
  );

  $migrations['MigrateDOAPages'] = array(
    'class_name' => 'MigrateDOAPages',
    'group_name' => 'doa',
    'soft_dependencies' => array(
      'MigrateDOAFiles',
      'MigrateDOADocument',
    ),
  );

  $migrations['MigrateDOAFiles'] = array(
    'class_name' => 'MigrateDOAFiles',
    'group_name' => 'doa',
  );

  $migrations['MigrateDOADocument'] = array(
    'class_name' => 'MigrateDOADocument',
    'group_name' => 'doa',
  );

  $migrations['MigrateDOAPageMenu'] = array(
    'class_name' => 'MigrateDOAPageMenu',
    'group_name' => 'doa',
    'soft_dependencies' => array(
      'MigrateDOAPages',
    ),
  );

  return $items;
}
