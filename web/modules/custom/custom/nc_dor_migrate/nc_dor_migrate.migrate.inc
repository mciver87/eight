<?php

/**
 * @file
 * Declares our migrations.
 */

/**
 * Implements hook_migrate_api().
 */
function nc_dor_migrate_migrate_api() {
  $api = array(
    'api' => 2,
    'groups' => array(
      'ncdor' => array(
        'title' => t('NC DOR Document Migrations'),
      ),
    ),
    'migrations' => array(
      'NcDORDocs' => array(
        'class_name' => 'MigrateNcdorDocumentMigration',
        'group_name' => 'ncdor',
      ),
    ),
  );
  return $api;
}
