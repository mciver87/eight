<?php
/**
 * @file
 * Page migration class.
 */

class MigrateNcshpPageMigration extends Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('Import SHP Pages from CSV file');
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'nc_shp_migrate') . '/files/shppages.csv',
      array(),
      array(
        'header_rows' => 1,
        'embedded_newlines' => TRUE,
      )
    );
    $this->destination = new MigrateDestinationNode('site_page');
    // Set source-dest ID map.
    $this->map = new MigrateSQLMap(
      $this->machineName,
      array(
        'uuid' => array(
          'type' => 'varchar',
          'length' => 6,
          'not null' => TRUE,
          'description' => 'Unique ID of the page',
        )
      ),
      MigrateDestinationNode::getKeySchema()
    );

    // Add simple 1:1 mappings.
//    $this->addSimpleMappings(array(
//      'title',
//    ));

    // Add custom mappings.
    $this->addFieldMapping('type', 'type');
    $this->addFieldMapping('status')
         ->defaultValue(TRUE);
    $this->addFieldMapping('body', 'body');
    $this->addFieldMapping('body:format')
         ->defaultValue('full_html');
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('pathauto')
         ->defaultValue(TRUE);
  }

  /**
   * Prepare a row.
   */
  public function prepareRow($row) {
    module_load_include('inc', 'nc_shp_migrate', '/includes/simple_html_dom');
    // Always include this fragment at the beginning of every prepareRow()
    // implementation, so parent classes can ignore rows.
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
    // CURL to get page content.
    $html = file_get_html($row->url);
    if (empty($html->find("#contentBox"))) {
      // Some kind of failure.
      return FALSE;
    }

    // Need body, title.
    $title_object = $html->find(".s4-wpcell-plain h1", 0);
    // First try with H1
    if (!empty($title_object)) {
      $title = trim(strip_tags($title_object->outertext));
    }
    else {
      // If no H1s found, go for TRs.
      $title_object = $html->find(".s4-wpcell-plain", 0);
      $title_parts = $title_object->find("tr");
      $subtitle = trim(strip_tags($title_parts[0]->outertext));
      $title = trim(strip_tags($title_parts[1]->outertext));
    }
    if (!empty($title)) {
      $row->title = $title;
    }
    else {
      $row->title = "NO PARSEABLE TITLE - " . $row->url;
    }

    $body = $html->find("#contentBox #wrapper td");
    foreach ($body as $body_elt) {
      $raw_body .= $body_elt->innertext;
    }
    $cleaned_body = $this->removeTags($raw_body, array("img", "iframe", "div", "span"));
    $row->body = preg_replace("/<([a-z][a-z0-9]*)(?:[^>]*(\shref=['\"][^'\"]*['\"]))?[^>]*?(\/?)>/i",'<$1$2>', $cleaned_body);
    return TRUE;
  }



  private function removeTags($str, $tags) {
    $tagsString = "";
    foreach($tags as $key => $v) {
      $tagsString .= $key == count($tags)-1 ? $v : "{$v}|";
    }

    $patterns = array("/(<\s*\b({$tagsString})\b[^>]*>)/i", "/(<\/\s*\b({$tagsString})\b\s*>)/i");
    $output = preg_replace($patterns, "", $str);

    // Remove empty tags
    $empty_tags_removed = preg_replace('/<([^<\/>]*)>([\s]*?|(?R))<\/\1>/imsU', "", $output);

    return $empty_tags_removed;

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
}
