<?php
/**
 * @file
 * Contains OSHR migration for linked files within static pages.
 */

class MigrateOSHRFiles extends MigrateOSHRBase {
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
        )
      ),
      MigrateDestinationFile::getKeySchema()
    );

    // The source fields.
    $fields = array(
      'url' => t('File URL'),
      'path' => t('File path'),
    );

    // The source of the migration is pages from the legacy site.
    $url_source = variable_get('nc_migrate_oshr_pages', FALSE);
    $page_urls = $url_source ? array_keys($this->processSpreadsheet($url_source)) : array();

    // Now extract file links from the pages.
    $file_urls = $this->processPages($page_urls);

    $list_urls = new MigrateListUrl('http://www.oshr.nc.gov/migrated_files', $file_urls);
    $item_url = new MigrateItemFileUrl();
    $this->source = new MigrateSourceList($list_urls, $item_url, $fields);

    // The destination is the site_page content type.
    $this->destination = new MigrateDestinationFile('file', 'MigrateFileUri');

    // Map the fields, pretty straightforward in this case.
    $this->addFieldMapping('value', 'url');
    $this->addFieldMapping('destination_file', 'path');
    $this->addFieldMapping('destination_dir')->defaultValue('public://migrated_files');
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
      db_insert('nc_migrate_oshr_docrefs')
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
    parent::completeRollback($entity_ids);
    // Code to execute after an entity has been rolled back.
    db_delete('nc_migrate_oshr_docrefs')
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
          $row[0] = implode('', array_slice($row, 0, 5));
          $page = array();
          foreach ($row as $colidx => $col) {
            if (isset($colnames[$colidx])) {
              $page[$colnames[$colidx]] = trim($col);
            }
          }

          // Perform final cleanup or row data.
          if (strpos($page['New Page URL'], '/') === 0) {
            $page['New Page URL'] = substr($page['New Page URL'], 1);
          }

          // Make sure this is a row we want to import.
          $page_url = $page['Reference Page from Existing Site'];
          if (!empty($page_url) && 'oshr.nc.gov' == $page['Content Source']) {
            if ('Site Page' != $page['Page Type']) {
              $message = t('Target page type is not %type: !target_type', array('%type' => 'Site Page', '!target_type' => $page['Page Type']));
              //$this->getMap()->saveMessage(array($page_url), $message, MigrationBase::MESSAGE_NOTICE);
            }
            else {
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
  * VERY ugly code, cobbled together from MigrateOSHRPages.
  */
  protected function processPages($page_urls) {
    $file_urls = array();
    $migrate_item = new MigrateItemUrl();
    foreach ($page_urls as $page_url) {
      $row = $migrate_item->getItem($page_url);
      if ($row) {
        $row->sourceid = $page_url;

        // Locate "section1" which is the main content region.
        $row->qp->top();
        $section1 = $row->qp->find('#section1')->first();

        // Process all links to see if we can swap out for document node links.
        $section1->top();
        $section1->find('a,img')->each(function ($index, $item) use ($row, &$file_urls) {
          $href = NULL;
          if ($item->hasAttribute('href')) {
            // Pull HREF and try to form into an absolute URL for lookup.
            $href = $item->getAttribute('href');
          }
          elseif ($item->hasAttribute('src')) {
            // Pull SRC and try to form into an absolute URL for lookup.
            $href = $item->getAttribute('src');
          }
          if ($href) {
            $url_parts = parse_url($href);
            if (empty($url_parts['path']) || (!empty($url_parts['scheme']) && 'http' != $url_parts['scheme'])) {
              // Invalid URL, bail.
              return;
            }

            if (empty($url_parts['scheme'])) {
              $url_parts['scheme'] = 'http';
            }
            if (empty($url_parts['host'])) {
              $url_parts['host'] = 'oshr.nc.gov';
            }
            elseif (!strstr($url_parts['host'], 'oshr.nc.gov')) {
              // Not an OSHR-hosted file, bail.
              return;
            }
            if ('/' != $url_parts['path'][0]) {
              // Yay, we've got a relative URL!  Now we get to try and reconstruct from the page URL.
              $base_url_parts = parse_url($row->sourceid);
              $rel_offset = 0;
              $base_url_parts_path_expl = explode('/', $base_url_parts['path']);
              $url_parts_path_expl = explode('/', $url_parts['path']);
              foreach ($url_parts_path_expl as $tmp) {
                if ('..' == $tmp) {
                  $rel_offset++;
                }
              }
              $base_path = implode('/', array_slice($base_url_parts_path_expl, 0, -1 - $rel_offset));
              $url_parts['path'] = str_replace('//', '/', (!empty($base_path) ? '/' : '') . $base_path . '/' . implode('/', array_slice($url_parts_path_expl, $rel_offset)));
            }
            $href = urldecode($url_parts['scheme'] . '://' . $url_parts['host'] . $url_parts['path']);

            // Make sure our URL hasn't already been processed.
            if (!MigrateOSHRBase::getDocumentXref($href)) {
              $file_urls[$href] = $href;
            }
          }
        });
      }
    }

    return $file_urls;
  }
}
