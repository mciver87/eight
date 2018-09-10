<?php
/**
 * @file
 * Contains OSBM documents migration.
 */

class MigrateOSBMDocument extends MigrateOSBMBase {
  /**
   * Constructor.
   */
  public function __construct($args) {
    parent::__construct($args);

    // Set up source.
    $url_source = variable_get('nc_migrate_osbm_documents', FALSE);
    if ($url_source) {
      $columns = array(
        0 => array('id', 'id'),
        1 => array('field_document_attachment', 'URL'),
        2 => array('title', 'Node title'),
        3 => array('body:summary', 'Short Description'),
        4 => array('body', 'Long Description'),
        5 => array('field_document_author', 'Document Author'),
        6 => array('field_document_archived', 'Archived/Current'),
        7 => array('field_document_collection', 'Collection'),
        8 => array('field_document_type', 'Document Terms'),
        9 => array('file_title', 'Document Official Title'),
        10 => array('field_published_date', 'First Published'),
        11 => array('field_revised_date', 'Last Updated'),
        13 => array('supplemental_file', 'Supplemental URL'),
        15 => array('path', 'URL Alias'),
        99 => array('created', 'Created'),
      );
      $options = array(
        'header_rows' => 1,
        'embedded_newlines' => TRUE,
      );
      $this->source = new MigrateSourceCSV($url_source, $columns, $options);
    }

    $this->addUnmigratedSources(array(
      'supplemental_file',
    ));

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

    $this->addUnmigratedDestinations(array(
      'uid',
      'changed',
      'revision',
      'log',
      'language',
      'tnid',
      'translate',
      'revision_uid',
      'body:language',
      'field_document_attachment:file_class',
      'field_document_attachment:language',
      'field_document_attachment:destination_dir',
      'field_document_attachment:destination_file',
      'field_document_attachment:source_dir',
      'field_document_attachment:urlencode',
      'field_document_attachment:display',
      'field_key_search_topics',
      'field_key_search_topics:source_type',
      'field_key_search_topics:create_term',
      'field_key_search_topics:ignore_case',
      'field_thumbnail_image',
      'field_thumbnail_image:file_class',
      'field_thumbnail_image:language',
      'field_thumbnail_image:preserve_files',
      'field_thumbnail_image:destination_dir',
      'field_thumbnail_image:destination_file',
      'field_thumbnail_image:file_replace',
      'field_thumbnail_image:source_dir',
      'field_thumbnail_image:urlencode',
      'field_thumbnail_image:alt',
      'field_thumbnail_image:title',
      'field_document_collection:source_type',
      'field_document_type:source_type',
      'field_official_title',
      'field_published_date:timezone',
      'field_published_date:rrule',
      'field_published_date:to',
      'field_revised_date:timezone',
      'field_revised_date:rrule',
      'field_revised_date:to',
      'field_related_content',
      'field_related_content:title',
      'field_related_content:attributes',
      'field_related_content:language',
      'field_agency_department',
      'field_agency_department:source_type',
      'field_agency_department:create_term',
      'field_agency_department:ignore_case',
      'metatag_title',
      'metatag_description',
      'metatag_abstract',
      'metatag_keywords',
      'metatag_robots',
      'metatag_news_keywords',
      'metatag_standout',
      'metatag_generator',
      'metatag_rights',
      'metatag_image_src',
      'metatag_canonical',
      'metatag_shortlink',
      'metatag_publisher',
      'metatag_author',
      'metatag_original-source',
      'metatag_revisit-after',
      'metatag_content-language',
    ));

    // Add simple 1:1 mappings.
    $this->addSimpleMappings(array(
      'title',
      'body',
      'body:summary',
      'field_document_type',
      'field_document_collection',
      'field_document_author',
      'field_document_archived',
      'field_published_date',
      'field_revised_date',
      'created',
    ));

    // Add custom mappings.
    $this->addFieldMapping('field_document_attachment', 'field_document_attachment')->separator(',');
    $this->addFieldMapping('field_document_attachment:description', 'file_title')->separator(',');
    $this->addFieldMapping('field_document_attachment:file_replace')->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_document_attachment:preserve_files')->defaultValue(TRUE);
    $this->addFieldMapping('is_new')->defaultValue(0);
    $this->addFieldMapping('status')->defaultValue(1);
    $this->addFieldMapping('path', 'path');
    $this->addFieldMapping('pathauto')->defaultValue(0);

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
    // Provide a date for our fake 'created' field (column 99).
    $row->created = strtotime($row->field_published_date);

    // Cleanup the URL.
    $row->field_document_attachment = $this->fixURL($row->field_document_attachment);

    // Make sure we have a URL and title, otherwise skip row.
    if (empty($row->field_document_attachment)) {
      $message = t('Missing URL for document title !title', array('!title' => $row->title));
      $this->getMap()->saveMessage(array($row->title), $message, MigrationBase::MESSAGE_NOTICE);
      return FALSE;
    }
    if (empty($row->title)) {
      $message = t('Missing title for document URL !url', array('!url' => $row->field_document_attachment));
      $this->getMap()->saveMessage(array($row->field_document_attachment), $message, MigrationBase::MESSAGE_NOTICE);
      return FALSE;
    }

    // Add the supplemental url if needed.
    if ($row->field_document_attachment && $row->supplemental_file) {
      $document_collection = array(
        $row->field_document_attachment,
        $this->fixURL($row->supplemental_file),
      );
      $row->field_document_attachment = implode(',', $document_collection);
    }

    return TRUE;
  }

  /**
   * Preprocess the entity prior to saving it.
   */
  public function prepare($entity, $row) {
    // Disable pathauto for this node so our custom paths will take effect.
    $entity->path['pathauto'] = 0;
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
    return $url_parts['scheme'] . '://' . $url_parts['host'] . rtrim($url_parts['path']);
  }
}
