<?php
/**
 * @file
 * Contains DOA static HTML to Site Page migration.
 */

class MigrateDOAPages extends MigrateDOABase {
  protected $urls = array();

  /**
   * Constructor.
   */
  public function __construct($args) {
    parent::__construct($args);

    // A map of source HTML filename -> destination node id.
    $this->map = new MigrateSQLMap($this->machineName,
        array(
          'sourceid' => array(
            'type' => 'varchar',
            'length' => 255,
            'not null' => TRUE,
            'description' => 'URL of source page',
          ),
        ),
        MigrateDestinationNode::getKeySchema()
    );

    // The source fields.
    $fields = array(
      'title' => t('Title'),
      'body' => t('Body'),
      'uid' => t('User id'),
    );

    // The source of the migration is pages from the legacy site.
    $url_source = variable_get('nc_migrate_doa_content', FALSE);
    if ($url_source) {
      $this->urls = $this->processSpreadsheet($url_source);
    }

    $list_urls = new MigrateListUrl('https://www.doa.nc.go', array_keys($this->urls));
    $item_url = new MigrateDOAItemUrl();
    $this->source = new MigrateSourceList($list_urls, $item_url, $fields);

    // The destination is the site_page content type.
    $this->destination = new MigrateDestinationNode('site_page');

    // Map the fields, pretty straightforward in this case.
    $this->addFieldMapping('uid', 'uid')->defaultValue(1);
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('body', 'body');
    $this->addFieldMapping('body:format')->defaultValue('full_html');
    $this->addFieldMapping('path', 'path');
    $this->addFieldMapping('pathauto')->defaultValue(0);
  }

  /**
   * Prepare a row.
   */
  public function prepareRow($row) {
    $content = '';
    // Always include this fragment at the beginning of every prepareRow()
    // implementation, so parent classes can ignore rows.
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    // Bail if no QueryPath object was created.
    if (!$row || empty($row->qp)) {
      return FALSE;
    }

    // Pull detailed import info for this item.
    $page_info = $this->urls[$row->sourceid];

    // Bail if no title.
    if (empty($page_info['Level 1'])) {
      $message = t('Target page has no title: %row', array('%row' => $row['id']));
      $this->getMap()->saveMessage(array($row->sourceid), $message, MigrationBase::MESSAGE_NOTICE);
      return FALSE;
    }

    $url = parse_url($row->sourceid);
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
        $content = '';
    }

    if (!empty($element)) {
      $element->find('a,img')->each(function ($index, $item) use ($row) {
        $href = NULL;
        $attrName = '';
        if ($item->hasAttribute('href')) {
          // Pull HREF and try to form into an absolute URL for lookup.
          $href = $item->getAttribute('href');
          $attrName = 'href';
        }
        elseif ($item->hasAttribute('src')) {
          // Pull SRC and try to form into an absolute URL for lookup.
          $href = $item->getAttribute('src');
          $attrName = 'src';
        }
        if ($href) {
          $url_parts = parse_url($href);
          if (empty($url_parts['path']) || (!empty($url_parts['scheme']) && 'http' != $url_parts['scheme'])) {
            // Invalid URL, bail.
            return;
          }
          else {
            if (empty($url_parts['scheme'])) {
              $url_parts['scheme'] = 'http';
            }
            $base_url_parts = parse_url($row->sourceid);
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

            $xref = MigrateDOABase::getDocumentXref($href);
            if ($xref) {
              if ($xref['nid']) {
                $item->setAttribute($attrName, url('node/' . $xref['nid']));
              }
              elseif (!empty($xref['new_url'])) {
                $item->setAttribute($attrName, urldecode($xref['new_url']));
              }
            }
          }
        }
      });
    }


    // Extract body.
    $row->body = !(empty($element)) ? trim($element->innerHTML()) : $content;

    // Now assign new values from 1:1 mapping spreadsheet.
    $row->title = $page_info['Level 1'];
    $row->path = $page_info['New/Target URL'];

    return TRUE;
  }

  /**
   * Preprocess the entity prior to saving it.
   */
  public function prepare($entity, $row) {
    // Disable pathauto for this node so our custom paths will take effect.
    $entity->path['pathauto'] = 0;

    /*
     * If workbench_moderation is enabled, add correct flags if node status
     * is set to published.
     * https://www.drupal.org/node/1452016#comment-8503687
     */
    if (module_exists('workbench_moderation') && isset($entity->status)) {
      $entity->revision = TRUE;
      $entity->is_new = !(isset($entity->nid) && ($entity->nid));
      $entity->workbench_moderation_state_current = 'published';
      $entity->workbench_moderation_state_new = 'published';
    }
  }

  /**
   * Util method to load URLs from spreadsheet.
   */
  protected function processSpreadsheet($filename) {
    if ($urls = cache_get('nc_migrate_doa_pages')) {
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
    cache_set('nc_migrate_doa_pages', $urls, 'cache', CACHE_TEMPORARY);
    return $urls;
  }
}
