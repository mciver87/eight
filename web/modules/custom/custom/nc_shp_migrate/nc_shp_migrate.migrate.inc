<?php

/**
 * @file
 * Declares our migrations.
 */

/**
 * Implements hook_migrate_api().
 */
function nc_shp_migrate_migrate_api() {
  $api = array(
    'api' => 2,
    'groups' => array(
      'ncshp' => array(
        'title' => t('NC SHP Migrations'),
      ),
    ),
    'migrations' => array(
      'NcSHPDocs' => array(
        'class_name' => 'MigrateNcshpDocumentMigration',
        'group_name' => 'ncshp',
      ),
      'NcSHPPages' => array(
        'class_name' => 'MigrateNcshpPageMigration',
        'group_name' => 'ncshp',
      ),
      'NcSHPHbr' => array(
        'class_name' => 'MigrateNcshpHbrMigration',
        'group_name' => 'ncshp',
      ),
      'NcSHPMemberFocus' => array(
        'class_name' => 'MigrateNcshpMemberFocusMigration',
        'group_name' => 'ncshp',
      )
    ),
  );
  return $api;
}
