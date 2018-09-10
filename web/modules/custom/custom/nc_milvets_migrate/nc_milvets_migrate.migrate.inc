<?php
/**
 * @file nc_milvets_migrate.migrate.inc
 */

/**
 * This is example code for milvets to NCDMVA migration.
 */

/**
 * Implements hook_migrate_api().
 */
function nc_milvets_migrate_migrate_api() {
  /**
   * Declare the api version and migration group.
   */
  $api = array(
    'api' => 2,
    'groups' => array(
      'milvets' => array(
        'title' => t('NC4Vets to NCDVMA Migration.'),
      ),
      'migrations' => array(),
    ),
  );

  /**
   * Each migration being registered takes an array of arguments, some required
   * and some optional. Start with the common arguments required by all - the
   * source_connection (connection key, set up in settings.php, pointing to
   * the source database), source_version (major version of Drupal), and
   * group_name (a.k.a. import job).
   */
  $common_arguments = array(
    'source_connection' => 'nc4vets',
    'source_version' => 7,
    'group_name' => 'milvets',
  );

  // For vocabulary migrations, source_vocabulary and destination_vocabulary are
  // required arguments.

  // Two vovcabularies: provider type and service type

  $vocabulary_arguments = array(
    'Provider' => array(
      'description' => t('Migration of Providers'),
      'source_vocabulary' => 'provider_type',
      'destination_vocabulary' => 'catalog_category',
    ),
    'Service' => array(
      'description' => t('Migration of Services from NC4Vets'),
      'source_vocabulary' => 'service_type',  // D6 Vocabulary ID
      'destination_vocabulary' => 'catalog_category',
    ),
  );

  // Again, we're using the migrate_d2d class directly.
  // The soft dependency says that while we don't have to run the user migration
  // first, we want to make sure it's listed first so the vocabularies are
  // listed right ahead of the node migrations.
  $common_vocabulary_arguments = $common_arguments + array(
    'class_name' => 'NcMilvetsVocabularyMigration',
  );
  foreach ($vocabulary_arguments as $migration_name => $arguments) {
    $arguments += $common_vocabulary_arguments;
    $api['migrations'][$migration_name] = $arguments;
  }

  // Node migrations - each has its own class derived from the migrate_d2d class,
  // specifying its particular field mappings and transformations. source_type
  // and destination_type are required arguments.
  $node_arguments = array(
    'Image' => array(
      'class_name' => 'ExampleImageMigration',
      'description' => t('Migration of image nodes from Drupal 6'),
      'source_type' => 'image',
      'destination_type' => 'image',
    ),
    'Article' => array(
      'class_name' => 'ExampleArticleMigration',
      'description' => t('Migration of article nodes from Drupal 6'),
      'source_type' => 'my_article',
      'destination_type' => 'new_article',
      'dependencies' => array('Image', 'Countries', 'Topics'),
    ),
  );

  // Tell the node migrations where the users are coming from, so they can
  // set up the dependency and resolve D6->D7 uids.
  $common_node_arguments = $common_arguments + array(
      'user_migration' => 'User'
    );

  foreach ($node_arguments as $migration_name => $arguments) {
    $arguments = array_merge_recursive($arguments, $common_node_arguments);
    $api['migrations'][$migration_name] = $arguments;
  }

  // Menu migrations -- same requirements as users
  $menu_arguments = $common_arguments + array(
    'description' => t('Migration of menus from Drupal 6'),
    'class_name' => 'DrupalMenu6Migration',
  );

  // We just use the migrate_d2d D6 migration class as-is.
  $api['migrations']['Menu'] = $menu_arguments;

  // Menu links migrations -- basic requirements, plus must set up menu dependency
  $menu_links_arguments = $common_arguments + array(
    'description' => t('Migration of menu links from Drupal 6'),
    'class_name' => 'DrupalMenuLinks6Migration',
    'menu_migration' => 'Menu',
  );
  $api['migrations']['MenuLinks'] = $menu_links_arguments;

  return $api;
}
