<?php

class MigrateDENRFiles extends MigrateDENRBase {
  /**
   * Constructor.
   */
  public function __construct($args) {
    parent::__construct($args);
    // A map of source HTML filename -> destination node id.
    $this->map = new MigrateSQLMap(
      $this->machineName,
      array(
        'sourceid' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
          'description' => 'URL of source page',
        ),
      ),
      MigrateDestinationFile::getKeySchema()
    );

    // The source fields.
    $fields = array(
      'url' => t('File URL'),
      'path' => t('File path'),
    );

    // The source of the migration is pages from the legacy site.
    $url_source = variable_get('nc_migrate_denr_pages', FALSE);
    $page_urls = $url_source ? array_keys($this->processSpreadsheet($url_source)) : array();

    // Now extract file links from the pages.
    $file_urls = $this->processPages($page_urls);

    $list_urls = new MigrateListUrl('http://www.denr.nc.gov/migrated_files', $file_urls);
    $item_url = new MigrateItemFileUrl();
    $this->source = new MigrateSourceList($list_urls, $item_url, $fields);

    // The destination is the site_page content type.
    $this->destination = new MigrateDestinationFile('file', 'MigrateFileUri');

    // Map the fields, pretty straightforward in this case.
    $this->addFieldMapping('value', 'url');
    $this->addFieldMapping('destination_file', 'path');
    $this->addFieldMapping('destination_dir')
      ->defaultValue('public://migrated_files');
  }

  /**
   * Prepare a row.
   */
  public function prepareRow($row) {
    // Always include this fragment at the beginning of every prepareRow()
    // implementation, so parent classes can ignore rows.
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    // Bail if no QueryPath object was created.
    if (!$row) {
      return FALSE;
    }

    return TRUE;
  }

  /**
   * The Migration class complete() method is analogous to prepare(), but is
   * called immediately after the complete destination object is saved.
   */
  public function complete($entity, stdClass $row) {
    if (!empty($row->url)) {
      // Generate crossref record for each file URL.
      $new_url = file_create_url($entity->uri);
      db_insert('nc_migrate_denr_docrefs')
        ->fields(array(
          'old_url' => $row->url,
          'new_url' => $new_url,
          'nid' => 0,
          'fid' => $entity->fid,
        ))
        ->execute();
    }
  }

  /**
   * Called after rollback, passed array of entity IDs.
   */
  public function completeRollback($entity_ids) {
    // Code to execute after an entity has been rolled back.
    db_delete('nc_migrate_denr_docrefs')
      ->condition('fid', $entity_ids, 'IN')
      ->execute();
  }

  /**
   * Util method to load URLs from spreadsheet.
   */
  protected function processSpreadsheet($filename) {
    // Make sure we have this copied somewhere local.
    $urls = array();
    if (($handle = fopen($filename, "r")) !== FALSE) {
      $colnames = array();
      $rownum = 0;
      while (($row = fgetcsv($handle)) !== FALSE) {
        if (1 == $rownum) {
          // Header #1
          foreach ($row as $colidx => $col) {
            if (!empty($col)) {
              $colnames[$colidx] = $col;
            }
          }
        }
        elseif ($rownum > 2) {
          // Process row data.
          $row[0] = implode('', array_slice($row, 0, 7));
          $page = array();
          foreach ($row as $colidx => $col) {
            if (isset($colnames[$colidx])) {
              $page[$colnames[$colidx]] = trim($col);
            }
          }
          // Perform final cleanup or row data.
          if (strpos($page['NEW/Target URL'], '/') === 0) {
            $page['NEW/Target URL'] = substr($page['NEW/Target URL'], 1);
          }

          // Make sure this is a row we want to import.
          $page_url = $page['CURRENT URL'];
          preg_match('/http/i', $page['Content Source'], $match);
          if (!empty($page_url) && !empty($match)) {
            if ('Site Page' == $page['PAGE TYPE']) {
              $urls[$page_url] = $page;
            }
          }
        }
        $rownum++;
      }
    }

    return $urls;
  }

  /**
   * Util method to extract all file links from body content (A and IMG).
   *
   * VERY ugly code, cobbled together from MigrateDENRPages.
   */
  protected function processPages($page_urls) {
    return array();
  }
}
