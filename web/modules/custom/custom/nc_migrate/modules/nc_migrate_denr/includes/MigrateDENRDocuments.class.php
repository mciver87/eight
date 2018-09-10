<?php
/**
 * @file
 * Contains DENR documents migration.
 */

class MigrateDENRDocuments extends MigrateDENRBase {
  /**
   * Constructor.
   */
  public function __construct($args) {
    parent::__construct($args);

    // Set up source.
    $url_source = variable_get('nc_migrate_denr_documents', FALSE);
    if ($url_source) {
      $columns = array(
        0 => array('field_agency_department', 'Division'),
        1 => array('field_document_attachment', 'URL'),
        2 => array('alt_url', 'Alternate URL'),
        3 => array('path', 'Document Library Path'),
        4 => array('filename', 'Filename'),
        5 => array('body', 'Description'),
        6 => array('title', 'title'),
        7 => array('field_document_type', 'Topic'),
        8 => array('field_document_collection', 'Collection'),
        9 => array('field_published_date', 'First Published'),
        10 => array('field_revised_date', 'Last Updated'),
      );
      $options = array(
        'header_rows' => 1,
        'group_col' => 6,
        'array_cols' => array('field_document_attachment'),
      );
      $this->source = new MigrateDENRDocumentSource($url_source, $columns, $options);
    }

    // Set up destination.
    $this->destination = new MigrateDestinationNode('document');

    // Set source-dest ID map.
    $this->map = new MigrateSQLMap(
      $this->machineName,
      array(
        'title' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
          'description' => 'Title of node',
        ),
      ),
      MigrateDestinationNode::getKeySchema()
    );

    // Add unmigrated source mappings.
    $this->addUnmigratedSources(array('alt_url'));

    // Add simple 1:1 mappings.
    $this->addSimpleMappings(array(
      'field_agency_department',
      'title',
      'body',
      'field_document_type',
      'field_document_collection',
      'field_published_date',
      'field_revised_date',
    ));

    // Add default mappings.
    $this->addFieldMapping('field_document_attachment', 'field_document_attachment')->separator(',');
    $this->addFieldMapping('field_document_attachment:file_replace')->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_document_attachment:preserve_files')->defaultValue(TRUE);
    $this->addFieldMapping('field_document_attachment:destination_file', 'filename');
    $this->addFieldMapping('field_document_attachment:destination_dir', 'path');
    $this->addFieldMapping('field_agency_department:create_term')->defaultValue(TRUE);
    $this->addFieldMapping('field_agency_department:ignore_case')->defaultValue(TRUE);
    $this->addFieldMapping('field_document_type:create_term')->defaultValue(TRUE);
    $this->addFieldMapping('field_document_type:ignore_case')->defaultValue(TRUE);
    $this->addFieldMapping('field_document_collection:create_term')->defaultValue(TRUE);
    $this->addFieldMapping('field_document_collection:ignore_case')->defaultValue(TRUE);
    $this->addFieldMapping('body:format')->defaultValue('full_html');
    $this->addFieldMapping('is_new')->defaultValue(0);
    $this->addFieldMapping('status')->defaultValue(1);
    $this->addFieldMapping('promote')->defaultValue(0);
    $this->addFieldMapping('sticky')->defaultValue(0);
    $this->addFieldMapping('comment')->defaultValue(0);

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

    // Make sure we have a URL and title, otherwise skip row.
    if (empty($row->field_document_attachment) || empty($row->title)) {
      return FALSE;
    }

    // Fix the path.
    if (strpos($row->path, '/') === 0) {
      $row->path = substr($row->path, 1);
      $row->path = "public://" . $row->path;
    }
    // Cleanup the URL.
    $files = array();
    foreach ($row->field_document_attachment as $file) {
      $files[] = $this->fixURL($file);
    }
    // Convert the file attachment field to a single value.
    $row->field_document_attachment = implode(",", $files);
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
   * Clean up URLs from the spreadsheet.
   */
  protected function fixURL($url) {
    $url_parts = parse_url($url);
    if (empty($url_parts['path']) || (!empty($url_parts['scheme']) && !in_array(strtolower($url_parts['scheme']), array('http', 'https')))) {
      return FALSE;
    }
    if (empty($url_parts['scheme'])) {
      $url_parts['scheme'] = 'http';
    }
    if (empty($url_parts['query'])) {
      return $url_parts['scheme'] . '://' . $url_parts['host'] . rtrim($url_parts['path']);
    }
    else {
      return $url_parts['scheme'] . '://' . $url_parts['host'] . rtrim($url_parts['path'] . $url_parts . "?" . $url_parts['query']);
    }
  }
}
