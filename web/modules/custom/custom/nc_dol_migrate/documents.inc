<?php
/**
 * @file
 * Document migration class.
 */

class MigrateNcdolDocumentMigration extends Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('Import DOL Documents from CSV file');
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'nc_dol_migrate') . '/files/doldocs.csv',
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
          'length' => 6,
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
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('status')
         ->defaultValue(TRUE);
    $this->addFieldMapping('body', 'description');
    $this->addFieldMapping('field_document_attachment', 'address');
    $this->addFieldMapping('field_document_attachment:destination_dir', 'destination_dir');
    $this->addFieldMapping('path', 'path');
    $this->addFieldMapping('pathauto')
         ->defaultValue(FALSE);
    $this->addFieldMapping('field_revised_date', 'last_modified');
    $this->addFieldMapping('field_document_collection', 'collection');
    $this->addFieldMapping('field_document_collection:create_term')
         ->defaultValue(TRUE);
    $this->addFieldMapping('field_agency_department', 'division');
    $this->addFieldMapping('field_agency_department:create_term')
         ->defaultValue(TRUE);
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

    // Now prepare the Address field, explode on |.
    $row->address = explode("|", $row->address);

    // Prepare the taxonomy terms.
    $full_terms = array();
    // Special handling for "Publications" and "OSH Enforcement Procedures"
    if (!empty($row->collection)) {
      $full_terms[] = $row->collection;
      if ($row->collection == 'Publications' && !empty($row->publication)) {
        $full_terms[] = $row->publication;
      }
      else if ($row->collection == 'OSH Enforcement Procedures' && !empty($row->osh)) {
        $full_terms[] = $row->osh;
      }
    }
    $row->collection = $full_terms;

    // Set path default.
    $path_to_file_or_node = '';
    if (!empty($row->division)) {
      $path_to_file_or_node .= strtolower(str_replace(' ', '-', $row->division));
    }
    if (!empty($row->collection[0])) {
      $path_to_file_or_node .= '/' . strtolower(str_replace(' ', '-', $row->collection[0]));
    }
    $row->path = $path_to_file_or_node . '/' . strtolower(str_replace(' ', '-', $row->title));

    // Handle file destination directory.
    $row->destination_dir = 'public://' . $path_to_file_or_node;

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
