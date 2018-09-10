<?php
/**
 * @file
 * Contains DHHS static HTML to Press Releases migration.
 */

class MigrateDHHSPressReleases extends MigrateDHHSBase {
  // Class constants for spreadsheet column headers.
  const OLD_URL = 'Press Releases to be Migrated';

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
      'subtitle' => t('Subtitle'),
      'body' => t('Body'),
      'uid' => t('User id'),
      'release_date' => t('Release date'),
      'city_location' => t('City / location'),
      'contact' => t('Contact info'),
    );

    // The source of the migration is pages from the legacy site.
    $url_source = variable_get('nc_migrate_dhhs_press_releases', FALSE);
    if ($url_source) {
      $this->urls = $this->processSpreadsheet($url_source);
    }

    $list_urls = new MigrateListUrl('http://www.ncdhhs.gov/press-releases', array_keys($this->urls));
    $item_url = new MigrateItemUrl();
    $this->source = new MigrateSourceList($list_urls, $item_url, $fields);

    // The destination is the site_page content type.
    $this->destination = new MigrateDestinationNode('press_release');

    // Map the fields, pretty straightforward in this case.
    $this->addFieldMapping('uid', 'uid')->defaultValue(1);
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('body', 'body');
    $this->addFieldMapping('body:summary', 'subtitle')->defaultValue('');
    $this->addFieldMapping('body:format')->defaultValue('full_html');
    $this->addFieldMapping('field_release_date', 'release_date');
    $this->addFieldMapping('field_city_location', 'city_location')->defaultValue('');
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
    $body_text = $row->qp->find('#purpleWrapper')->first();

    // Remove unwanted elements.
    $body_text->remove('#breadcrumbs');
    $body_text->remove('> span:first-of-type');

    // Extract/remove subtitle.
    $row->subtitle = trim(strip_tags($body_text->find('p.subtitle')->innerHTML()));
    $body_text->remove('p.subtitle');

    // Extract/remove title.
    $row->title = trim(strip_tags($body_text->find('> h1:first-of-type')->innerHTML()));
    $body_text->remove('> h1:first-of-type');

    // Extract/remove release date and contact info.
    $date_contact = trim($body_text->find('> p:first-of-type')->innerHTML());
    $date_contact_parts = explode('<br />', $date_contact);
    array_shift($date_contact_parts);
    $release_date = array_shift($date_contact_parts);
    if (strtotime($release_date)) {
      $row->release_date = $release_date;
    }
    $row->contact = implode('<br />', $date_contact_parts);
    $body_text->remove('> p:first-of-type');

    // Extract/remove city-location text.
    $first_para = $body_text->find('> p:first-of-type');
    $row->city_location = trim(strip_tags($first_para->find('strong:first-of-type')->innerHTML()));
    $first_para->remove('strong:first-of-type');
    $first_para_html = $first_para->innerHTML();
    if (' - ' == substr($first_para_html, 0, 3)) {
      $first_para->html('<p>' . substr($first_para_html, 3) . '</p>');
    }

    // Strip all inline styling.
    foreach ($body_text->find('p, span') as $item) {
      $item->removeAttr('style');
    }

    // Extract body and save.
    $row->body = trim($body_text->innerHTML());
    $row->body .= '<p>' . $row->contact .'</p>';

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