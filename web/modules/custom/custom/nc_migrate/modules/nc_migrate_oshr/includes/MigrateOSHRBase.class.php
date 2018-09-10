<?php
/**
 * @file
 * Contains base class for OSHR migrations.
 */

/**
 * Class definition for MigrateOSHRBase.
 */
class MigrateOSHRBase extends Migration {
  // Cache vars.
  var $dest_ids = array();

  /**
   * Provide one-stop-shop for getDestID
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

  /**
   * Called after rollback, passed array of entity IDs.
   */
  public function completeRollback($entity_ids) {
    // Code to execute after an entity has been rolled back.
  }

  /**
   * Util method to look up document crossref.
   */
  public static function getDocumentXref($url) {
    $result = db_select('nc_migrate_denr_docrefs', 'xrefs')
    ->fields('xrefs')
    ->condition('old_url', $url)
    ->execute()
    ->fetchAssoc();
    return $result;
  }
}
