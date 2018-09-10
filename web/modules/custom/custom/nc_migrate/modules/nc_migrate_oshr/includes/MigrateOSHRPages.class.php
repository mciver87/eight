<?php
/**
 * @file
 * Contains OSHR static HTML to Site Page migration.
 */

class MigrateOSHRPages extends MigrateOSHRBase {
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
          )
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
    $url_source = variable_get('nc_migrate_oshr_pages', FALSE);
    if ($url_source) {
      $this->urls = $this->processSpreadsheet($url_source);
    }

    $list_urls = new MigrateListUrl('http://www.oshr.nc.gov', array_keys($this->urls));
    $item_url = new MigrateItemUrl();
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

    // Locate "section1" which is the main content region.
    $row->qp->top();
    $section1 = $row->qp->find('#section1')->first();

    // Remove unwanted elements from body.
    $section1->top();
    $section1->remove('> h2:first-of-type');
    $section1->remove('> h2:first-of-type');

    // Process all links to see if we can swap out for document node links.
    $section1->top();
    $section1->find('a,img')->each(function ($index, $item) use ($row) {
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
          return;
        }

        if (empty($url_parts['scheme'])) {
          $url_parts['scheme'] = 'http';
        }
        if (empty($url_parts['host'])) {
          $url_parts['host'] = 'oshr.nc.gov';
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

        $xref = MigrateOSHRBase::getDocumentXref($href);
        if ($xref) {
          if ($xref['nid']) {
            $item->setAttribute($attrName, url('node/' . $xref['nid']));
          }
          elseif (!empty($xref['new_url'])) {
            $item->setAttribute($attrName, urldecode($xref['new_url']));
          }
        }
      }
    });
    // Extract body.
    $row->body = trim($section1->innerHTML());

    // Now assign new values from 1:1 mapping spreadsheet.
    $row->title = $page_info['New Page Title'];
    $row->path = $page_info['New Page URL'];

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
}
