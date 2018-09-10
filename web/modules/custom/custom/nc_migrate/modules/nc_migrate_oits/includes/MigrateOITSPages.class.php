<?php
/**
 * @file
 * Contains OITS static HTML to Site Page migration.
 */

class MigrateOITSPages extends MigrateOITSBase {
  // Class constants for spreadsheet column headers.
  const NEW_TITLE = 'New Page Title';
  const NEW_URL = 'New Page URL';
  const PAGE_TYPE = 'Page Type';
  const SOURCE = 'Content Source';
  const OLD_URL = 'Reference Page(s) from Legacy Site';

  // Class variables.
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
    $url_source = variable_get('nc_migrate_oits_pages', FALSE);
    if ($url_source) {
      $this->urls = $this->processSpreadsheet($url_source);
    }

    $list_urls = new MigrateListUrl('http://www.its.nc.gov', array_keys($this->urls));
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
    $body_text = $row->qp->find('#bodyText')->first();

    // Extract body and remove unwanted elements.
    $body_text->top();
    $body_text->remove('#breadcrumbs');
    $body_text->remove('> h1:first-of-type');

    // Process all links to see if we can swap out for document node links.
    $body_text->top();
    $body_text->find('a')->each(function ($index, $item) {
      if ($item->hasAttribute('href')) {
        // Pull URL and see if we have a possible match in documents.
        $href = $item->getAttribute('href');
        if (!parse_url($href,  PHP_URL_HOST)) {
          $href = 'http://www.its.nc.gov' . $href;
        }
        if ($nid = $this->getDestID($href, 'MigrateOITSDocuments')) {
          $item->setAttribute('href', url('node/' . $nid));
        }
      }
    });

    // Extract body and save.
    $row->body = trim($body_text->innerHTML());

    // Now assign new values from 1:1 mapping spreadsheet.
    $row->title = $page_info[self::NEW_TITLE];
    $row->path = $page_info[self::NEW_URL];

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
        if (2 == $rownum) {
          // Header #1
          foreach ($row as $colidx => $col) {
            if (!empty($col)) {
              $colnames[$colidx] = $col;
            }
          }
        }
        elseif ($rownum > 3) {
          // Process row data.
          $row[0] = implode('', array_slice($row, 0, 5));
          $page = array();
          foreach ($row as $colidx => $col) {
            if (isset($colnames[$colidx])) {
              $page[$colnames[$colidx]] = trim($col);
            }
          }

          // Perform final cleanup or row data.
          if (strpos($page[self::NEW_URL], '/') === 0) {
            $page['New Page URL'] = substr($page['New Page URL'], 1);
          }

          // Make sure this is a row we want to import.
          $page_url = trim($page[self::OLD_URL]);
          if (!empty($page_url) && 'Existing Site (its.nc.gov)' == trim($page[self::SOURCE])) {
            // Check to see if this is a page type we're importing.
            if ('Site Page' != trim($page[self::PAGE_TYPE])) {
              $message = t('Target page type is not %type: !target_type', array('%type' => 'Site Page', '!target_type' => $page[self::PAGE_TYPE]));
              //$this->getMap()->saveMessage(array('Bad URL'), $message, MigrationBase::MESSAGE_NOTICE);
            }
            // Check to see if someone stuffed a multiline value in the URL.
            elseif (count(explode("\n", $page_url)) > 1) {
              $message = t('Source URL field contains multiple lines: !url', array('!url' => $page_url));
              //$this->getMap()->saveMessage(array('Bad URL'), $message, MigrationBase::MESSAGE_NOTICE);
            }
            // Check to see if the URL is too long.
            elseif (strlen($page_url) > 255) {
              $message = t('Source URL is too long: !url', array('!url' => $page_url));
              //$this->getMap()->saveMessage(array('Bad URL'), $message, MigrationBase::MESSAGE_NOTICE);
            }
            // Otherwise, add to URL list.
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