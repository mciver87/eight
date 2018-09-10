<?php

/**
 * @file
 * Declares our migrations.
 */

/**
 * Implements hook_migrate_api().
 */
function nc_dol_migrate_migrate_api() {
  $api = array(
    'api' => 2,
    'groups' => array(
      'ncdol' => array(
        'title' => t('NC DOL Document Migrations'),
      ),
    ),
    'migrations' => array(
      'NcDOLDocs' => array(
        'class_name' => 'MigrateNcdolDocumentMigration',
        'group_name' => 'ncdol',
      ),
    ),
  );
  return $api;
}
