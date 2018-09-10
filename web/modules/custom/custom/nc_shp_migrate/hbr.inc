<?php
/**
 * @file
 * HBR migration class.
 */

class MigrateNcshpHbrMigration extends Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('Import SHP HBR content from CSV file');
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'nc_shp_migrate') . '/files/hbr.csv',
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
    $this->addFieldMapping('type', 'type');
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
    $row->title = strip_tags($row->link);
    $row->terms[] = 'HBRs';
    $row->terms[] = $row->hbr;
    $row->body = $row->link;
    $row->body .= '<br /><br />';
    $row->body .= $row->text;
    $row->created = strtotime($row->created);
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
}
