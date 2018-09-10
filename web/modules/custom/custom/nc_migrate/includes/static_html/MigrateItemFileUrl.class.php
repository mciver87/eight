<?php
/**
 * @file
 * Implementation of MigrateItem for URL lists.
 */

/**
 * Class MigrateItemFileUrl.
 *
 * Used in conjunction with MigrateListUrl to process a list of file URLs.
 */
class MigrateItemFileUrl extends MigrateItem {
  /**
   * Implementation of abstract method.
   *
   * Implementors are expected to return an object representing a source item.
   *
   * @param mixed $id
   *  Assumed for this class to be the URL of the page to retrieve.
   *
   * @return stdClass | NULL
   */
  public function getItem($id) {
    $row = new stdClass();
    $row->url = $id;
    $row->path = parse_url($id,  PHP_URL_PATH);
    return $row;
  }
}
