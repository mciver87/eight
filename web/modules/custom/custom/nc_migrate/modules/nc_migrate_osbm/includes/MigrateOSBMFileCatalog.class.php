<?php
/**
 * @file
 * Contains OSBM documents migration.
 */

class MigrateOSBMFileCatalog extends MigrateOSBMBase {
  /**
   * Constructor.
   */
  public function __construct($args) {
    parent::__construct($args);

    // Set up source.
    $url_source = variable_get('nc_migrate_osbm_file_catalog', FALSE);
    if ($url_source) {
      $columns = array(
        0 => array('field_document_attachment', 'File URL'),
        1 => array('title', 'title'),
        2 => array('body:summary', 'Short Description'),
        3 => array('body', 'Long Description'),
        4 => array('field_document_author', 'Document Author'),
        5 => array('field_key_search_topics', 'Search Topics'),
        6 => array('field_document_collection', 'Document Collection'),
        7 => array('field_document_type', 'Document Term'),
        8 => array('field_official_title', 'Document Official Title'),
        9 => array('field_published_date', 'First Published'),
        10 => array('field_revised_date', 'Last Updated'),
        11 => array('topic_1', 'Topic 1'),
        12 => array('topic_2', 'Topic 2'),
        13 => array('topic_3', 'Topic 3'),
        14 => array('field_data_year', 'Year'),
        15 => array('field_data_race', 'Race'),
        16 => array('field_data_sex', 'Sex'),
        17 => array('type_county', 'Type (county)'),
        18 => array('type_municipal', 'Type (municipal)'),
        19 => array('topic_municipal', 'Topic (municipal)'),
      );
      $options = array(
        'header_rows' => 1,
        'embedded_newlines' => TRUE,
        'group_col' => 1,
        'array_cols' => array(
          'field_document_attachment',
          'field_official_title',
          'field_published_date',
          'field_revised_date',
        ),
      );
      $this->source = new MigrateOSBMDocumentSource($url_source, $columns, $options);
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
        ),
      ),
      MigrateDestinationNode::getKeySchema()
    );

    $this->addUnmigratedSources(array(
      'topic_2',
      'topic_3',
      'type_municipal',
      'topic_municipal',
    ));

    // Add simple 1:1 mappings.
    $this->addSimpleMappings(array(
      'field_document_attachment',
      'title',
      'body:summary',
      'body',
      'field_official_title',
      'field_document_author',
      'field_key_search_topics',
      'field_document_collection',
      'field_published_date',
      'field_revised_date',
      'field_data_year',
      'field_data_race',
      'field_data_sex',
    ));

    // Add field mappings.
    $this->addFieldMapping('field_document_attachment:file_replace')->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_document_attachment:preserve_files')->defaultValue(TRUE);
    $this->addFieldMapping('field_document_attachment:destination_dir')->defaultValue('public://demog');
    $this->addFieldMapping('is_new')->defaultValue(0);
    $this->addFieldMapping('status')->defaultValue(1);
    $this->addFieldMapping('field_document_type:create_term')->defaultValue(TRUE);
    $this->addFieldMapping('field_document_type:ignore_case')->defaultValue(TRUE);
    $this->addFieldMapping('field_document_type', 'field_document_type')->separator('|');
    $this->addFieldMapping('field_document_collection:create_term')->defaultValue(TRUE);
    $this->addFieldMapping('field_document_collection:ignore_case')->defaultValue(TRUE);
    $this->addFieldMapping('field_key_search_topics:create_term')->defaultValue(TRUE);
    $this->addFieldMapping('field_key_search_topics:ignore_case')->defaultValue(TRUE);
    $this->addFieldMapping('field_data_year:create_term')->defaultValue(TRUE);
    $this->addFieldMapping('field_data_year:ignore_case')->defaultValue(TRUE);
    $this->addFieldMapping('field_data_race:create_term')->defaultValue(TRUE);
    $this->addFieldMapping('field_data_race:ignore_case')->defaultValue(TRUE);
    $this->addFieldMapping('field_data_sex:create_term')->defaultValue(TRUE);
    $this->addFieldMapping('field_data_sex:ignore_case')->defaultValue(TRUE);
    $this->addFieldMapping('field_data_topic', 'topic_1')->separator(',');
    $this->addFieldMapping('field_data_topic:ignore_case')->defaultValue(TRUE);
    $this->addFieldMapping('field_data_topic:create_term')->defaultValue(TRUE);
    $this->addFieldMapping('field_data_type', 'type_county')->separator(',');
    $this->addFieldMapping('field_data_type:ignore_case')->defaultValue(TRUE);
    $this->addFieldMapping('field_data_type:create_term')->defaultValue(TRUE);
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

    if ($row->title == "Title") {
      // This is the header row.
      $message = t('Skipping header row due to !title', array('!title' => $row->title));
      $this->getMap()->saveMessage(array($row->title), $message, MigrationBase::MESSAGE_NOTICE);
      return FALSE;
    }

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

    // Clean up URLs from spreadsheet.
    $files = array();
    $row->field_document_attachment = (array) $row->field_document_attachment;
    if (!empty($row->field_document_attachment)) {
      foreach ($row->field_document_attachment as $url) {
        $files[] = $this->fixURL($url);
      }
    }
    $row->field_document_attachment = $files;

    // Reduce published/updated dates from all documents into single values.
    $row->field_published_date = min(array_map('strtotime', (array) $row->field_published_date));
    $row->field_revised_date = max(array_map('strtotime', (array) $row->field_revised_date));

    // Prepare topics.
    $topics = array(
      $row->topic_1,
      $row->topic_2,
      $row->topic_3,
      $row->topic_municipal,
    );
    $row->topic_1 = implode(',', array_filter((array) $topics));

    // Prepare types.
    $types = array(
      $row->type_county,
      $row->type_municipal,
    );
    $row->type_county = implode(',', array_filter((array) $types));

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
    // Disable pathauto for this node so our custom paths will take effect.
    // $entity->path['pathauto'] = 0;
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
