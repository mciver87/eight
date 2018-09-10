<?php
/**
 * @file
 * Document migration class.
 */

class MigrateNcdorDocumentMigration extends Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('Import DOR Documents from CSV file');
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'nc_dor_migrate') . '/files/dordocs.csv',
      array(),
      array(
        'header_rows' => 1,
        'embedded_newlines' => TRUE,
      )
    );
    $this->destination = new MigrateDestinationNode('document');
    // Set source-dest ID map.
    $this->map = new MigrateSQLMap(
      $this->machineName,
      array(
        'uid' => array(
          'type' => 'varchar',
          'length' => 7,
          'not null' => TRUE,
          'description' => 'Unique ID of the document',
        )
      ),
      MigrateDestinationNode::getKeySchema()
    );

    // Add simple 1:1 mappings.
//    $this->addSimpleMappings(array(
//      'title',
//    ));

    // Add custom mappings.
    // File
    $this->addFieldMapping('field_document_attachment', 'address')
      ->separator('|');
    $this->addFieldMapping('field_document_attachment:urlencode')
      ->defaultValue(0);
    $this->addFieldMapping('field_document_attachment:destination_dir', 'destination_dir');
    // Title
    $this->addFieldMapping('title', 'title');
    // Body Summary
    $this->addFieldMapping('body:summary', 'summary');
    // Body
    $this->addFieldMapping('body', 'body');
    $this->addFieldMapping('body:format')
      ->defaultValue('full_html');
    // Document Collection
    $this->addFieldMapping('field_document_collection', 'collection');
    $this->addFieldMapping('field_document_collection:create_term')
      ->defaultValue(TRUE);
    // Document Terms
    $this->addFieldMapping('field_document_type', 'terms')
      ->separator(',');
    $this->addFieldMapping('field_document_type:create_term')
      ->defaultValue(TRUE);
    // User
    $this->addFieldMapping('uid', 'user');
    // Status
    $this->addFieldMapping('status')
      ->defaultValue(TRUE);
    // Pathauto
    $this->addFieldMapping('pathauto')
      ->defaultValue(TRUE);
    // Date range
    $this->addFieldMapping('field_tax_year', 'year_from');
    $this->addFieldMapping('field_tax_year:to', 'year_to' );
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
    $row->title = trim($row->title);
    // Replace empty titles with filenames.
    if (empty($row->title)) {
      $row->title = basename($row->address);
    }

    // Prepare the taxonomy terms.
    $full_terms = array();
    // Special handling for "Publications" and "OSH Enforcement Procedures"
    if (!empty($row->collection)) {
      $full_terms[] = $row->collection;
    }
    $row->collection = $full_terms;

    // Set path default.
    $path_to_file_or_node = '';
    if (!empty($row->collection[0])) {
      $path_to_file_or_node .= '/' . strtolower(str_replace(' ', '-', $row->collection[0]));
    }
    
    // Create acceptable date format for migrate module.
    if($row->year_from) :
      $row->year_from = $row->year_from . '-01-01 00:00:00';
    endif;
    if($row->year_to) :
      $row->year_to = $row->year_to . '-01-01 00:00:00';
    endif;

    // Handle file destination directory.
    $row->destination_dir = 'public://documents' . $path_to_file_or_node;

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
