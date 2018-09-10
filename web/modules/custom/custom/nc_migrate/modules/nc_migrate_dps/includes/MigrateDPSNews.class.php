<?php
/**
 * @file
 * Contains DPS static HTML to Press Release migration.
 */

class MigrateDPSNews extends MigrateDPSBase {
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
      'field_city_location' => t('Location'),
      'field_release_date' => t('Release Date'),
    );

    // The source of the migration is pages from the legacy site.
    $url_source = variable_get('nc_migrate_dps_news', FALSE);
    if ($url_source) {
      $this->urls = $this->processSpreadsheet($url_source);
    }

    $list_urls = new MigrateListUrl('https://www.ncdps.gov/', array_keys($this->urls));
    $item_url = new MigrateItemUrl();
    $this->source = new MigrateSourceList($list_urls, $item_url, $fields);

    // The destination is the press_release content type.
    $this->destination = new MigrateDestinationNode('press_release');

    // Map the fields, pretty straightforward in this case.
    $this->addFieldMapping('uid', 'uid')->defaultValue(1);
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('body', 'body');
    $this->addFieldMapping('body:format')->defaultValue('full_html');
    $this->addFieldMapping('field_city_location', 'field_city_location');
    $this->addFieldMapping('field_release_date', 'field_release_date');
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
    if (empty($page_info['Title'])) {
      $message = t('Target page has no title: %row', array('%row' => $row['id']));
      $this->getMap()->saveMessage(array($row->sourceid), $message, MigrationBase::MESSAGE_NOTICE);
      return FALSE;
    }

    $url = parse_url($row->sourceid);
    $host = !empty($url['host']) ? $url['host'] : NULL;
    $row->qp->top();
    switch ($host) {
      case 'www.ncdps.gov':
        $element = $row->qp->find('div.container div.span9')->first();
        $content = trim($element->innerHTML());
        break;

      default:
        $content = '';
    }
    // Extract body.
    $row->body = $content;

    // Now assign new values from 1:1 mapping spreadsheet.
    $row->title = $page_info['Title'];
    $row->field_city_location = $page_info['City/Location'];
    $row->field_release_date = "January 1, " . $page_info['Year'];

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
    if ($urls = cache_get('nc_migrate_dps_news')) {
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
            $page = array();
            foreach ($row as $colidx => $col) {
              if (isset($colnames[$colidx])) {
                $page[$colnames[$colidx]] = trim($col);
              }
            }

            // Make sure this is a node we want to import.
            $page_url = $page['URL'];
            if ($page_url) {
              $urls[$page_url] = $page;
            }
          }
          $rownum++;
        }
      }
    }
    cache_set('nc_migrate_dps_news', $urls, 'cache', CACHE_TEMPORARY);
    return $urls;
  }
}
