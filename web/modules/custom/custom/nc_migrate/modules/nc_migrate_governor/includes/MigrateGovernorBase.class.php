<?php
/**
 * @file
 * Contains base class for Governor migrations.
 */

/**
 * Class definition for MigrateGovernorBase.
 */
class MigrateGovernorBase extends Migration {
  // Cache vars.
  var $dest_ids = array();

  // Setup args.
  public $hostname = '';
  public $public_base = '';
  public $secret = '';

  /**
   * Simple initialization.
   *
   * @param array $args
   *  Arguments used to dynamically create a migration, contains:
   *   @param string appname
   *    The short app name from GatherContent.
   *   @param string apikey
   *    The API key from GatherContent.
   *   @param object project
   *    The project to load pages and templates from.
   *   @param object template
   *    The template to filter pages on.
   *   @param string node_type
   *    Drupal content type to migrate into.
   *   @param array fields
   *    The field mappings to add.
   */
  public function __construct($args) {
    parent::__construct($args);

    // Store off source info we'll need later.
    $this->hostname = $args['hostname'];
    $this->public_base = $args['public_base'];
    $this->secret = $args['secret'];
  }

  /**
   * Creates new source object for migration.
   */
  public function createSource($entity_type, $bundle) {
    return new MigrateGovernorSource($this->hostname, $this->public_base, $this->secret, $entity_type, $bundle);
  }

  /**
   * Provide one-stop-shop for getDestID
   */
  public function getDestID($source_id, $migration) {
    if (!isset($this->dest_ids[$migration][$source_id])) {
      $dest_id = db_query("SELECT destid1 FROM {migrate_map_{$migration}} m WHERE sourceid1 = :sid", array(':sid' => $source_id))->fetchField();
      if ($dest_id) {
        $this->dest_ids[$migration][$source_id] = $dest_id;
      }
    }
    return isset($this->dest_ids[$migration][$source_id]) ? $this->dest_ids[$migration][$source_id] : FALSE;
  }

  /**
   * Util method to flatten an array into property-safe names.
   */
  protected function _flattenArray($arr, $prefix = NULL) {
    $new_arr = array();
    foreach ($arr as $key => $value) {
      $new_key = $prefix ? "{$prefix}__{$key}" : $key;
      if (is_array($value) && !is_string($value)) {
        $new_arr += $this->_flattenArray($value, $new_key);
      }
      else {
        $new_arr[$new_key] = $value;
      }
    }

    return $new_arr;
  }
}
