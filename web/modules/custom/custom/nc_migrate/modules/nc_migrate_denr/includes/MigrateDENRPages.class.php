<?php
/**
 * @file
 * Contains DENR static HTML to Site Page migration.
 */

class MigrateDENRPages extends MigrateDENRBase {
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
    $url_source = variable_get('nc_migrate_denr_pages', FALSE);
    if ($url_source) {
      $this->urls = $this->processSpreadsheet($url_source);
    }

    $list_urls = new MigrateListUrl('http://portal.ncdenr.org', array_keys($this->urls));
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

    // Bail if no title.
    if (empty($page_info['Page Title'])) {
      if (!empty($page['NEW/Target URL'])) {
        $message = t('Target page has no title: %page', array('%page' => $page['NEW/Target URL']));
        $this->getMap()->saveMessage(array($row->sourceid), $message, MigrationBase::MESSAGE_NOTICE);
      }
      return FALSE;
    }

    $url = parse_url($row->sourceid);
    $host = !empty($url['host']) ? $url['host'] : NULL;
    switch ($host) {
      case 'www.ncair.org':
      case 'ncair.org':
      case 'daq.state.nc.us':
        $row->qp->top();
        $element = $row->qp->find('#mainContainer > table')->first();
        $content = trim($element->innerHTML());
        break;

      case 'portal.ncdenr.org':
      case 'www.nccoastalmanagement.net':
        $row->qp->top();
        $element = $row->qp->find('td.lfr-column.seventy')->first();

        // Remove unwanted elements.
        $row->qp->top();
        $element->remove('div.journal-content-article h1')->first();
        $content = trim($element->innerHTML());

        if (!$content) {
          // If we lack content here it is likely because there is a one-column
          // layout on this page, so lets try again with that in mind.
          $row->qp->top();
          $element = $row->qp->find('#column-1')->first();
          $element->remove('div.journal-content-article h1')->first();
          $content = trim($element->innerHTML());
        }

        break;

      default:
        $content = '';
    }

    // Extract body.
    $row->body = $content;

    // Now assign new values from 1:1 mapping spreadsheet.
    $row->title = $page_info['Page Title'];
    $row->path = $page_info['NEW/Target URL'];

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
}
