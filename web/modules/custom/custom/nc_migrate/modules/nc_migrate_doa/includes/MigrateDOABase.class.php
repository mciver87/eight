<?php
/**
 * @file
 * Contains base class for OSBM migrations.
 */

/**
 * Class definition for MigrateOSBMBase.
 */
class MigrateDOABase extends Migration {
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

  /**
   * Util method to look up document crossref.
   */
  public static function getDocumentXref($url) {
    $result = db_select('nc_migrate_doa_docrefs', 'xrefs')
      ->fields('xrefs')
      ->condition('old_url', $url)
      ->execute()
      ->fetchAssoc();
    return $result;
  }

  /**
   * The hosts that this migration is sourcing from.
   *
   * http://www.doa.nc.gov/ (main site)
   * http://www.doa.state.nc.us
   * http://www.pandc.nc.gov/
   * http://www.councilforwomen.nc.gov/
   * http://www.nc-sco.com/
   * http://www.ncmotorfleet.com/
   * http://www.ncdnpe.org/
   * http://www.surplus.nc.gov/
   *
   * @return array
   *   The list of hosts, in no particular order.
   */
  public static function listHosts() {
    return array(
      'www.ncmotorfleet.com',
      'www.pandc.nc.gov',
      'www.doa.state.nc.us',
      'www.ncdnpe.org',
      'www.councilforwomen.nc.gov',
      'www.nc-sco.com',
      'www.surplus.nc.gov',
      'www.doa.nc.gov',
    );
  }

  /**
   * Called after rollback, passed array of entity IDs.
   */
  public function completeRollback($entity_ids) {
    // Code to execute after an entity has been rolled back.
  }
}
