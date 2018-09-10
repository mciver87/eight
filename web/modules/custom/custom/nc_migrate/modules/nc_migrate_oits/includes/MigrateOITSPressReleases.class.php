<?php
/**
 * @file
 * Contains OITS static HTML to Press Releases migration.
 */

class MigrateOITSPressReleases extends MigrateOITSBase {
  // Class constants for spreadsheet column headers.
  const OLD_URL = 'URL';

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
      'date' => t('Release data'),
    );

    // The source of the migration is pages from the legacy site.
    $url_source = variable_get('nc_migrate_oits_press_releases', FALSE);
    if ($url_source) {
      $this->urls = $this->processSpreadsheet($url_source);
    }

    $list_urls = new MigrateListUrl('http://www.its.nc.gov/press-releases', array_keys($this->urls));
    $item_url = new MigrateItemUrl();
    $this->source = new MigrateSourceList($list_urls, $item_url, $fields);

    // The destination is the site_page content type.
    $this->destination = new MigrateDestinationNode('press_release');

    // Map the fields, pretty straightforward in this case.
    $this->addFieldMapping('uid', 'uid')->defaultValue(1);
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('body', 'body');
    $this->addFieldMapping('body:format')->defaultValue('full_html');
    $this->addFieldMapping('field_release_date', 'date');
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

    // Locate main content region.
    $row->qp->top();
    $body_text = $row->qp->find('#newsDetail')->first();

    // Extract date.
    $body_text->top();
    $row->date = strip_tags($body_text->find('span.date')->innerHTML());

    // Extract title.
    $body_text->top();
    $row->title = strip_tags($body_text->find('span.headline')->innerHTML());

    // Remove unwanted elements.
    $body_text->top();
    $body_text->remove('> p:first-of-type');

    // Strip all inline styling.
    $body_text->top();
    foreach ($body_text->find('p, span') as $item) {
      $item->removeAttr('style');
      $item->removeClass('MsoNormal');
    }

    // Remove empty elements as best we may.
    $body_text->top();
    foreach ($body_text->find('p, span') as $item) {
      $text = $item->innerHTML();
      $text = str_replace('&nbsp;', '', $text);
      $text = strip_tags($text);
      $text = trim($text);
      if (empty($text)) {
        $item->remove();
      }
    }

    // Extract body and save.
    $row->body = trim($body_text->innerHTML());

    return TRUE;
  }

  /**
   * Preprocess the entity prior to saving it.
   */
  public function prepare($entity, $row) {
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
        if (0 == $rownum) {
          // Header #1
          foreach ($row as $colidx => $col) {
            if (!empty($col)) {
              $colnames[$colidx] = $col;
            }
          }
        }
        elseif ($rownum > 0) {
          // Process row data.
          $page = array();
          foreach ($row as $colidx => $col) {
            if (isset($colnames[$colidx])) {
              $page[$colnames[$colidx]] = trim($col);
            }
          }

          // Make sure this is a row we want to import.
          $page_url = trim($page[self::OLD_URL]);
          if (!empty($page_url)) {
            $urls[$page_url] = $page;
          }
        }
        $rownum++;
      }
    }

    return $urls;
  }
}