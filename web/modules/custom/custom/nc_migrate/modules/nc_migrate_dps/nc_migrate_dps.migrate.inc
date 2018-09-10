<?php
/**
 * @file
 * Declares our migrations.
 */

/**
 * Implements hook_migrate_api().
 */
function nc_migrate_dps_migrate_api() {
  // Required for migration registrations.
  $items['api'] = 2;

  // Stub migrations array.
  $items['migrations'] = array();
  $migrations = &$items['migrations'];

  // Return migration tasks.
  $items['groups']['dps'] = array(
    'title' => t('DPS'),
    'default_format' => 'full_html',
  );

  $migrations['MigrateDPSDocument'] = array(
    'class_name' => 'MigrateDPSDocument',
    'group_name' => 'dps',
  );

  $migrations['MigrateDPSPages'] = array(
    'class_name' => 'MigrateDPSPages',
    'group_name' => 'dps',
  );

  $migrations['MigrateDPSNews'] = array(
    'class_name' => 'MigrateDPSNews',
    'group_name' => 'dps',
  );

  $migrations['MigrateDPSPageMenu'] = array(
    'class_name' => 'MigrateDPSPageMenu',
    'group_name' => 'dps',
    'dependencies' => array('MigrateDPSPages'),
  );

  return $items;
}
