<?php
/**
 * @file
 * nc_db_backup.backup_migrate_exportables.inc
 */

/**
 * Implements hook_exportables_backup_migrate_destinations().
 */
function nc_db_backup_exportables_backup_migrate_destinations() {
  $export = array();

  $item = new stdClass();
  $item->disabled = FALSE; /* Edit this to true to make a default item disabled initially */
  $item->api_version = 1;
  $item->machine_name = 's3_db_storage';
  $item->name = 'S3 DB Storage';
  $item->subtype = 's3';
  $item->location = 'https://AKIAJY2JBS5ITJDRQOVA:FFHl7%2F1CeTdifbklEa888GWekVBFck6R6RKrSewJ@s3.amazonaws.com/p2ncgov/backups';
  $item->settings = array();
  $export['s3_db_storage'] = $item;

  return $export;
}

/**
 * Implements hook_exportables_backup_migrate_schedules().
 */
function nc_db_backup_exportables_backup_migrate_schedules() {
  $export = array();

  $item = new stdClass();
  $item->disabled = FALSE; /* Edit this to true to make a default item disabled initially */
  $item->api_version = 1;
  $item->machine_name = 'daily_backup';
  $item->name = 'Daily Backup';
  $item->source_id = 'db';
  $item->destination_id = 's3_db_storage';
  $item->copy_destination_id = '';
  $item->profile_id = 'default';
  $item->keep = -2;
  $item->period = 86400;
  $item->enabled = TRUE;
  $item->cron = 'builtin';
  $item->cron_schedule = '0 4 * * *';
  $export['daily_backup'] = $item;

  return $export;
}
