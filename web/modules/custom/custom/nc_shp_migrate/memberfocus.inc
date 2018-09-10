<?php
/**
 * @file
 * Member Focus migration class.
 */

class MigrateNcshpMemberFocusMigration extends Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('Import SHP Member Focus content from CSV file');
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'nc_shp_migrate') . '/files/memberfocus.csv',
      array(),
      array(
        'header_rows' => 1,
        'embedded_newlines' => TRUE,
      )
    );
    $this->destination = new MigrateDestinationNode('blog_entry');
    // Set source-dest ID map.
    $this->map = new MigrateSQLMap(
      $this->machineName,
      array(
        'uid' => array(
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
    $this->addFieldMapping('status')
         ->defaultValue(TRUE);
    $this->addFieldMapping('body', 'body');
    $this->addFieldMapping('body:format')
         ->defaultValue('full_html');
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('pathauto')
         ->defaultValue(TRUE);
    $this->addFieldMapping('field_blog_terms', 'terms');
    $this->addFieldMapping('field_blog_terms:create_term')
         ->defaultValue(TRUE);
    $this->addFieldMapping('field_release_date', 'created');
    $this->addFieldMapping('created', 'created');

  }

  /**
   * Prepare a row.
   */
  public function prepareRow($row) {
    $row->title = strip_tags($row->title);
    $row->terms[] = 'Member Focus';

    $raw_body = l('Read the issue', $row->link);
    $raw_body .= '<br /><br />';
    $raw_body .= check_markup($row->text, 'filtered_html');
    $row->created = strtotime($row->created);

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
