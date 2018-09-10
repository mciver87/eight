<?php

/**
 * @file
 * Declares our migrations.
 */

/**
 * Implements hook_migrate_api().
 */
function nc_oah_migrate_migrate_api() {
  $api = array(
    'api' => 2,
    'groups' => array(
      'ncoah' => array(
        'title' => t('NC OAH Content Migrations'),
      ),
    ),
    'migrations' => array(
      'NcOAHRegister' => array(
        'class_name' => 'MigrateNcoahRegisterMigration',
        'group_name' => 'ncoah',
      ),
    ),
  );
  return $api;
}
