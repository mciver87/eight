<?php
/**
 * @file
 * Declares our migrations.
 */

/**
 * Implements hook_migrate_api().
 */
function nc_migrate_governor_migrate_api() {
  // Required for migration registrations.
  $items['api'] = 2;

  // Stub migrations array.
  $items['migrations'] = array();
  $migrations = &$items['migrations'];

  // Governor migrations.
  $governor_args = array(
    'hostname' => 'govadmin.nc.gov',
    'public_base' => 'sites/default/files',
    'secret' => '685bd5d9382631b0dac510dc1f30aa07',
  );
  $items['groups']['governor'] = array(
    'title' => t('Governor'),
    'default_format' => 'full_html',
  );
  $migrations['MigrateGovernorDocumentTerms'] = $governor_args + array(
    'class_name' => 'MigrateGovernorDocumentTerms',
    'group_name' => 'governor',
  );
  $migrations['MigrateGovernorPressReleaseTerms'] = $governor_args + array(
    'class_name' => 'MigrateGovernorPressReleaseTerms',
    'group_name' => 'governor',
  );
  $migrations['MigrateGovernorVideoTerms'] = $governor_args + array(
    'class_name' => 'MigrateGovernorVideoTerms',
    'group_name' => 'governor',
  );
  $migrations['MigrateGovernorPressRelease'] = $governor_args + array(
    'class_name' => 'MigrateGovernorPressRelease',
    'group_name' => 'governor',
    'dependencies' => array(
      'MigrateGovernorPressReleaseTerms',
    ),
  );
  $migrations['MigrateGovernorOrderProclamation'] = $governor_args + array(
    'class_name' => 'MigrateGovernorOrderProclamation',
    'group_name' => 'governor',
    'dependencies' => array(
      'MigrateGovernorDocumentTerms',
    ),
  );
  $migrations['MigrateGovernorVideo'] = $governor_args + array(
    'class_name' => 'MigrateGovernorVideo',
    'group_name' => 'governor',
    'dependencies' => array(
      'MigrateGovernorVideoTerms',
    ),
  );

  return $items;
}
