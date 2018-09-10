<?php
/**
 * @file
 * Contains class for Governor tags migration.
 */

/**
 * Class definition for MigrateGovernorPressReleaseTerms.
 */
class MigrateGovernorPressReleaseTerms extends MigrateGovernorBase {
  /**
   * Simple initialization.
   *
   * @param array $args
   *   Passed from calling code.
   */
  public function __construct($args) {
    // Required to properly set source info.
    parent::__construct($args);

    // Set up source.
    $this->source = $this->createSource('taxonomy_term', 'tags');

    // Set up destination.
    $this->destination = new MigrateDestinationTerm('press_release_terms');

    // Set source-dest ID map.
    $source_key = array(
      'tid' => array('type' => 'int',
        'unsigned' => TRUE,
        'not null' => TRUE,
      )
    );
    $this->map = new MigrateGatherContentSQLMap(
      $this->getMachineName(),
      $source_key,
      MigrateDestinationTerm::getKeySchema(),
      'default',
      array(
        'track_last_imported' => TRUE,
        'cache_map_lookups' => TRUE,
      )
    );

    // Add field mappings.
    $this->addFieldMapping('name', 'name');
  }
}
