<?php
/**
 * @file
 * Contains base class for OSBM migrations.
 */

/**
 * Class definition for MigrateOSBMBase.
 */
class MigrateDPSBase extends Migration {
  // Cache vars.
  var $dest_ids = array();

  /**
   * Provide one-stop-shop for getDestID.
   */
  public function getDestID($source_id, $migration) {
    $migration = strtolower($migration);
    if (!isset($this->dest_ids[$migration][$source_id])) {
      $dest_id = db_query("SELECT destid1 FROM {migrate_map_{$migration}} m WHERE sourceid1 = :sid", array(':sid' => $source_id))->fetchField();
      if ($dest_id) {
        $this->dest_ids[$migration][$source_id] = $dest_id;
      }
    }
    return isset($this->dest_ids[$migration][$source_id]) ? $this->dest_ids[$migration][$source_id] : FALSE;
  }
}
