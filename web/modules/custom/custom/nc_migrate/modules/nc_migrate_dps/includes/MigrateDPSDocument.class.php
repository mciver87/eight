<?php
/**
 * @file
 * Contains DPS documents migration.
 */

class MigrateDPSDocument extends MigrateDPSBase {
  /**
   * Constructor.
   */
  public function __construct($args) {
    parent::__construct($args);

    // Set up source.
    $url_source = variable_get('nc_migrate_dps_documents', FALSE);
    if ($url_source) {
      $columns = array(
        0 => array('field_document_attachment', 'URL'),
        1 => array('title', 'Node title'),
        2 => array('body:summary', 'Short Description'),
        3 => array('body', 'Long Description'),
        4 => array('field_document_author', 'Document Author'),
        6 => array('collection_1', 'Collection Item 1'),
        7 => array('collection_2', 'Collection Item 2'),
        11 => array('field_revised_date', 'Last Updated'),
        98 => array('field_document_collection', 'Collection'),
        99 => array('id', 'id'),
      );
      $options = array(
        'header_rows' => 1,
        'embedded_newlines' => TRUE,
        'group_col' => 1,
        'array_cols' => array(
          'field_document_attachment',
        ),
      );
      $this->source = new MigrateDPSDocumentSource($url_source, $columns, $options);
    }

    // Set up destination.
    $this->destination = new MigrateDestinationNode('document');

    // Set source-dest ID map.
    $this->map = new MigrateSQLMap(
      $this->machineName,
      array(
        'id' => array(
          'type' => 'int',
          'length' => 255,
          'not null' => TRUE,
          'description' => 'id',
        ),
      ),
      MigrateDestinationNode::getKeySchema()
    );

    // Add simple 1:1 mappings.
    $this->addSimpleMappings(array(
      'field_document_attachment',
      'title',
      'body',
      'body:summary',
      'field_document_author',
      'field_revised_date',
    ));

    // Add field mappings.
    $this->addFieldMapping('field_document_attachment:file_replace')->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_document_attachment:preserve_files')->defaultValue(TRUE);
    $this->addFieldMapping('body:format')->defaultValue('full_html');
    $this->addFieldMapping('field_document_collection', 'field_document_collection')->separator(',');
    $this->addFieldMapping('field_document_collection:create_term')->defaultValue(TRUE);
    $this->addFieldMapping('field_document_collection:ignore_case')->defaultValue(TRUE);

    // Default mappings for nodes.
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
    $row->id = $row->csvrownum;
    // Always include this fragment at the beginning of every prepareRow()
    // implementation, so parent classes can ignore rows.
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    // Clean up URLs from spreadsheet.
    $files = array();
    if (!empty($row->field_document_attachment)) {
      foreach ($row->field_document_attachment as $url) {
        $files[] = $this->fixURL($url);
      }
    }
    $row->field_document_attachment = $files;

    // Make sure we have Title, otherwise skip row.
    if (empty($row->title)) {
      $message = t('Missing title for document !row', array('!row' => $row->csvrownum));
      $this->getMap()->saveMessage(array($row->csvrownum), $message, MigrationBase::MESSAGE_NOTICE);
      return FALSE;
    }

    // Prepare collections.
    $collections = array(
      trim($row->collection_1),
      trim($row->collection_2),
    );
    $row->field_document_collection = implode(',', array_filter((array) $collections));
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
