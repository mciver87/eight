<?php
/**
 * @file
 * Contains DOA documents migration.
 */

class MigrateDOADocument extends MigrateDOABase {
  /**
   * Constructor.
   */
  public function __construct($args) {
    parent::__construct($args);

    // Set up source.
    $url_source = variable_get('nc_migrate_doa_documents', FALSE);
    if ($url_source) {
      $columns = array(
        0 => array('field_document_attachment', 'URL'),
        1 => array('title', 'Node title'),
        2 => array('body:summary', 'Short Description'),
        3 => array('body', 'Long Description'),
        4 => array('field_document_author', 'Document Author'),
        6 => array('collection_1', 'Collection Item 1'),
        7 => array('collection_2', 'Collection Item 2'),
        8 => array('field_agency_department', 'Agency / Division'),
        9 => array('field_document_type', 'Document Terms'),
        11 => array('field_published_date', 'First Published'),
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
      $this->source = new MigrateDOADocumentSource($url_source, $columns, $options);
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
      'field_published_date',
    ));

    // Add field mappings.
    $this->addFieldMapping('field_document_attachment:file_replace')->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_document_attachment:preserve_files')->defaultValue(TRUE);
    $this->addFieldMapping('field_document_attachment:urlencode')->defaultValue(FALSE);
    $this->addFieldMapping('field_document_attachment:file_class')->defaultValue('MigrateDOAFileUri');
    $this->addFieldMapping('body:format')->defaultValue('full_html');
    $this->addFieldMapping('field_document_collection', 'field_document_collection')->separator(',');
    $this->addFieldMapping('field_document_collection:create_term')->defaultValue(TRUE);
    $this->addFieldMapping('field_document_collection:ignore_case')->defaultValue(TRUE);
    $this->addFieldMapping('field_agency_department', 'field_agency_department');
    $this->addFieldMapping('field_agency_department:create_term')->defaultValue(TRUE);
    $this->addFieldMapping('field_agency_department:ignore_case')->defaultValue(TRUE);
    $this->addFieldMapping('field_document_type', 'field_document_type');
    $this->addFieldMapping('field_document_type:create_term')->defaultValue(TRUE);
    $this->addFieldMapping('field_document_type:ignore_case')->defaultValue(TRUE);

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

    // If files are not attached (404, timeout), log this but allow the
    // migration to continue to process the node. (do not return FALSE).
    $row->field_document_attachment = $files;
    if (count($files) < 1 && @$row->title) {
      $message = t('Missing file(s) for document !title', array('!title' => $row->title));
      $this->getMap()->saveMessage(array($row->csvrownum), $message, MigrationBase::MESSAGE_NOTICE);
    }

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

    // Prepare field_release_date
    if (!empty($row->field_published_date)) {
      $row->field_published_date = "January 1, " . $row->field_published_date;
    }

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
   * The Migration class complete() method is analogous to prepare(), but is
   * called immediately after the complete destination object is saved.
   */
  public function complete($entity, stdClass $row) {
    if (!empty($row->field_document_attachment)) {
      foreach ($row->field_document_attachment as $idx => $doc_url) {
        // Generate crossref record for each file to this node as well as the
        // file URL.
        $file = file_load($entity->field_document_attachment[$entity->language][$idx]['fid']);
        if ($file && !empty($file->uri)) {
          $new_url = file_create_url($file->uri);
          db_merge('nc_migrate_doa_docrefs')
            ->key(array('old_url' => $doc_url))
            ->fields(array(
              'old_url' => $doc_url,
              'new_url' => $new_url,
              'nid' => $entity->nid,
              'fid' => $file->fid,
            ))
            ->execute();
        }
      }
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
