<?php
/**
 * @file
 * Contains DHHS documents migration.
 */

class MigrateDHHSDocuments extends MigrateDHHSBase {
  /**
   * Constructor.
   */
  public function __construct($args) {
    parent::__construct($args);

    // Set up source.
    $url_source = variable_get('nc_migrate_dhhs_documents', FALSE);
    if ($url_source) {
      $columns = array(
        0 => array('field_document_attachment', 'URL'),
        1 => array('title', 'Node title'),
        2 => array('body:summary', 'Short Description'),
        3 => array('body', 'Long Description'),
        5 => array('field_document_type', 'Topic'),
        6 => array('field_document_collection', 'Collection'),
        8 => array('file_title', 'Official Title'),
        9 => array('field_published_date', 'First Published'),
        10 => array('field_revised_date', 'Last Updated'),
      );
      $options = array(
        'header_rows' => 1,
        'embedded_newlines' => TRUE,
        'group_col' => 1,
        'array_cols' => array(
          'field_document_attachment',
          'file_title',
          'field_published_date',
          'field_revised_date',
        ),
      );
      $this->source = new MigrateDHHSDocumentSource($url_source, $columns, $options);
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
          'description' => 'Title of source document',
        )
      ),
      MigrateDestinationNode::getKeySchema()
    );

    // Add simple 1:1 mappings.
    $this->addSimpleMappings(array(
      'title',
      'body',
      'body:summary',
      'field_document_attachment',
      'field_document_type',
      'field_document_collection',
      'field_published_date',
      'field_revised_date',
    ));

    // Add custom mappings.
    $this->addFieldMapping('field_document_attachment:title', 'file_title');
    $this->addFieldMapping('field_document_attachment:description', 'file_title');

    // Add default mappings.
    $this->addFieldMapping('field_document_type:create_term')->defaultValue(TRUE);
    $this->addFieldMapping('field_document_type:ignore_case')->defaultValue(TRUE);
    $this->addFieldMapping('field_document_collection:create_term')->defaultValue(TRUE);
    $this->addFieldMapping('field_document_collection:ignore_case')->defaultValue(TRUE);
    $this->addFieldMapping('promote')->defaultValue(0);
    $this->addFieldMapping('sticky')->defaultValue(0);
    $this->addFieldMapping('comment')->defaultValue(0);
    $this->addFieldMapping('body:format')->defaultValue('full_html');
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
    if (empty($row->field_document_attachment)) {
      $message = t('Missing URL for document title !title', array('!title' => $row->title));
      $this->getMap()->saveMessage(array($row->title), $message, MigrationBase::MESSAGE_NOTICE);
    }
    if (empty($row->title)) {
      $message = t('Missing title for document URL !url', array('!url' => $row->field_document_attachment));
      $this->getMap()->saveMessage(array($row->field_document_attachment), $message, MigrationBase::MESSAGE_NOTICE);
    }

    // Clean up URLs from spreadsheet.
    $files = array();
    if (!empty($row->field_document_attachment)) {
      foreach ($row->field_document_attachment as $url) {
        $files[] = $this->fixURL($url);
      }
    }
    $row->field_document_attachment = $files;

    // Reduce published/updated dates from all documents into single values.
    $row->field_published_date = min(array_map('strtotime', $row->field_published_date));
    $row->field_revised_date = max(array_map('strtotime', $row->field_revised_date));

    return TRUE;
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
    return $url_parts['scheme'] . '://' . $url_parts['host'] . $url_parts['path'];
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