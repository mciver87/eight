<?php
/**
 * @file
 * Implementation of MigrateList for URL lists.
 */

/**
 * Class MigrateListUrl.
 */
class MigrateListUrl extends MigrateList {
  protected $site_id = '';
  protected $urls = array();

  /**
   * Constructor for class.
   *
   * @param $site_id
   *  Unique identifier for this URL list
   * @param $urls
   *  Hashed array of pages where the key is the retrieval URL and the value is
   *  an array of values used by the migration to process the source URL.
   */
  public function __construct($site_id, $urls = array()) {
    parent::__construct();
    $this->site_id = $site_id;
    $this->urls = $urls;
  }

  /**
   * Implementation of abstract method.
   *
   * Implementors are expected to return a string representing where the listing
   * is obtained from (a URL, file directory, etc.)
   *
   * @return string
   */
  public function __toString() {
    return $this->site_id;
  }

  /**
   * Implementation of abstract method.
   *
   * Implementors are expected to return an array of unique IDs, suitable for
   * passing to the MigrateItem class to retrieve the data for a single item.
   *
   * @return Mixed, iterator or array
   */
  public function getIdList() {
    return $this->urls;
  }

  /**
   * Implementation of abstract method.
   *
   * Implementors are expected to return a count of IDs available to be migrated.
   *
   * @return int
   */
  public function computeCount() {
    return count($this->urls);
  }
}