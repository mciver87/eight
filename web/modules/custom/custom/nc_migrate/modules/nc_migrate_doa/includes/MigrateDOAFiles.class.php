<?php
/**
 * @file
 * Contains DOA migration for linked files within static pages.
 */

class MigrateDOAFiles extends MigrateDOABase {
  /**
   * Constructor.
   */
  public function __construct($args) {
    parent::__construct($args);

    // A map of source HTML filename -> destination node id.
    $this->map = new MigrateSQLMap(
      $this->machineName,
      array(
        'url' => array(
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
    $url_source = variable_get('nc_migrate_doa_content', FALSE);
    $page_urls = $url_source ? array_keys($this->processSpreadsheet($url_source)) : array();

    // Now extract file links from the pages.
    $file_urls = $this->processPages($page_urls);

    $list_urls = new MigrateListUrl('http://www.doa.nc.gov/migrated_files', $file_urls);
    $item_url = new MigrateItemUrl();
    $this->source = new MigrateSourceList($list_urls, $item_url, $fields);

    // The destination is the site_page content type.
    $this->destination = new MigrateDestinationFile('file', 'MigrateFileUri');

    // Map the fields, pretty straightforward in this case.
    $this->addFieldMapping('value', 'url');
    $this->addFieldMapping('destination_file', 'path');
    $this->addFieldMapping('destination_dir')->defaultValue('public://');
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

    // Bail if no url was created.
    if (!$row->url) {
      return FALSE;
    }

    // Parse the original file path and pass along to the file destination
    // so we end a folder structure that mimics the original.
    $parts = parse_url($row->url);
    $row->path = $parts['path'];
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
      db_insert('nc_migrate_doa_docrefs')
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
    db_delete('nc_migrate_doa_docrefs')
    ->condition('fid', $entity_ids, 'IN')
    ->execute();
  }

  /**
   * Util method to load URLs from spreadsheet.
   */
  protected function processSpreadsheet($filename) {
    if ($urls = cache_get('nc_migrate_doa_files')) {
      return $urls->data;
    }
    else {
      // Process the CSV.
      $urls = array();

      if (($handle = fopen($filename, "r")) !== FALSE) {
        $colnames = array();
        $rownum = 0;
        while (($row = fgetcsv($handle)) !== FALSE) {
          if (0 == $rownum) {
            // Header.
            foreach ($row as $colidx => $col) {
              if (!empty($col)) {
                $colnames[$colidx] = $col;
              }
            }
          }
          elseif ($rownum > 0) {
            // Rows 2 to 6 need to be combined to a single row.
            @$row[2] = array_shift(array_filter(array_slice($row, 2, 6)));
            $page = array();
            foreach ($row as $colidx => $col) {
              if (isset($colnames[$colidx])) {
                $page[$colnames[$colidx]] = trim($col);
              }
            }
            // Guard against target beginning with a '/'.
            if (strpos($page['New/Target URL'], '/') === 0) {
              $page['New/Target URL'] = substr($page['New/Target URL'], 1);
            }

            // Make sure this is a Site Page node.
            $page_url = $page['Current URL'];
            if ('Site Page' == ($page['Page Type']) || 'Site Page - SHELL' == ($page['Page Type'])) {
              if (!$page_url) {
                // We are migrating Site Pages with blank Reference URLs by
                // faking the domain here and later filling the content with
                // an empty string.
                $page_url = "http://fakepath.domain/?row={$rownum}";
              }
              $urls[$page_url] = $page;
            }
          }
          $rownum++;
        }
      }
    }
    cache_set('nc_migrate_doa_files', $urls, 'cache', CACHE_TEMPORARY);
    return $urls;
  }


 /**
  * Util method to extract all file links from body content (A and IMG).
  *
  * VERY ugly code, cobbled together from MigrateDOAPages.
  */
  protected function processPages($page_urls) {
    $file_urls = array();
    $migrate_item = new MigrateItemUrl();
    foreach ($page_urls as $page_url) {
      $row = $migrate_item->getItem($page_url);
      if ($row) {
        $row->url = $page_url;
        $url = parse_url($row->url);
        $host = !empty($url['host']) ? $url['host'] : NULL;
        $row->qp->top();
        switch ($host) {
          case 'www.doa.nc.gov':
          case 'www.surplus.nc.gov':
          case 'www.nc-sco.com':
          case 'www.councilforwomen.nc.gov':
            $element = $row->qp->find('div#page')->first();
            $element->remove('h2');
            $element->remove('a[href="#_Top"]');
            break;

          case 'www.ncdnpe.org':
            $element = $row->qp->find('p.MainContentHeaders')->first();
            break;

          case 'www.doa.state.nc.us':
            $element = $row->qp->find('div#page')->first();
            $element->remove('h2');
            $element->remove('iframe');
            break;

          case 'www.pandc.nc.gov':
          case 'www.ncmotorfleet.com':
            $element = $row->qp->find('div#content')->first();
            break;

          default:
            $element = $row->qp->find('#impossibletofindelement');
        }

        // Process all links to see if we can swap out for document node links.
        $element->find('a,img')->each(function ($index, $item) use ($row, &$file_urls) {
          $href = NULL;
          $item = qp($item);
          if ($item->hasAttr('href')) {
            // Pull HREF and try to form into an absolute URL for lookup.
            $href = $item->attr('href');
          }
          elseif ($item->hasAttr('src')) {
            // Pull SRC and try to form into an absolute URL for lookup.
            $href = $item->attr('src');
          }
          if ($href) {
            $url_parts = parse_url($href);
            if (empty($url_parts['path']) || (!empty($url_parts['scheme']) && 'http' != $url_parts['scheme'])) {
              // Invalid URL, bail.
              return;
            }
            else {
              // Paths with a "." (presumably a file extension) are the only
              // safe assets to move during this migration.
              if (FALSE === strpos($url_parts['path'], '.')) {
                return;
              }
              $ignored_extesions = array(
                'aspx',
                'htm',
              );
              foreach ($ignored_extesions as $ext) {
                if (preg_match("/{$ext}/i", $url_parts['path'], $matches)) {
                  return;
                }
              }
              if (empty($url_parts['scheme'])) {
                $url_parts['scheme'] = 'http';
              }
              $base_url_parts = parse_url($row->url);
              if (empty($url_parts['host']) && !empty($base_url_parts['host'])) {
                $url_parts['host'] = $base_url_parts['host'];
              }
              if (!in_array($url_parts['host'], MigrateDOABase::listHosts())) {
                // Not an DOA-hosted file, bail.
                return;
              }
              if ('/' != $url_parts['path'][0]) {
                // Yay, we've got a relative URL!  Now we get to try and
                // reconstruct from the page URL.
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
              if (!MigrateDOABase::getDocumentXref($href)) {
                $file_urls[$href] = $href;
              }
            }
          }
        });
      }
    }
    return $file_urls;
  }
}
