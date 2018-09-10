<?php
/**
 * @file
 * Contains class for NC.Gov services migration.
 */

/**
 * Class definition for MigrateNCGovServices.
 */
class MigrateNCGovServices extends MigrateNCGovNodeBase {
  /**
   * Simple initialization.
   *
   * @param array $args
   *   Passed from calling code.
   */
  public function __construct($args) {
    // Required to properly set source info.
    parent::__construct($args);

    // Set up source.
    $columns = array(
      0 => array('itemno', '#'), // NOT a unique id for the row, not sure where it came from
      1 => array('headline', 'Headline'),
      2 => array('short_description', 'Short Description'),
      3 => array('link_url', 'Link URL'),
      4 => array('category_1', 'Category'),
      5 => array('topic_1', 'Topic'),
      6 => array('category_2', '2nd Category'),
      7 => array('topic_2', '2nd Topic'),
      8 => array('online', 'Online Service (bool)'),
      9 => array('data', 'Data (bool)'),
      10 => array('grant', 'Grant (bool)'),
      11 => array('law_regulation', 'Law/ Regulation (bool)'),
      12 => array('license_permit', 'License/ Permit (bool)'),
      13 => array('contacts', 'Contacts'),
      14 => array('map', 'Map'),
      15 => array('lookup', 'Lookup'),
      16 => array('newsletter_signup', 'nwsltr/blog signup (bool)'),
      17 => array('related_to', 'Related to'),
    );
    $options = array(
      'header_rows' => 1,
      'embedded_newlines' => TRUE,
    );
    $fields = array(
      'service_type' => 'Aggregates boolean fields (online, grant, data, law_regulation, license_permit)',
      'service_categories' => 'Aggregates tags (category and topic)',
    );
    $csv_path = variable_get('nc_migrate_ncgov_services_csv', '');
    $this->source = new MigrateSourceCSV($csv_path, $columns, $options, $fields);

    // Set up destination.
    $this->destination = new MigrateDestinationNode('services');

    // Set source-dest ID map.
    $source_key = array(
      'headline' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => TRUE,
      )
    );
    $this->map = new MigrateGatherContentSQLMap(
      $this->getMachineName(),
      $source_key,
      MigrateDestinationNode::getKeySchema(),
      'default',
      array(
        'track_last_imported' => TRUE,
        'cache_map_lookups' => TRUE,
      )
    );

    // Add field mappings.
    $this->addFieldMapping('title', 'headline');
    $this->addFieldMapping('body', 'short_description');
    $this->addFieldMapping('field_online_service', 'online');

    // Add dynamic fields.
    $this->addFieldMapping('field_service_type', 'service_type');
    $this->addFieldMapping('field_service_category', 'service_categories');
    $this->addFieldMapping('field_service_category:create_term')->defaultValue(TRUE);
    $this->addFieldMapping('field_service_category:ignore_case')->defaultValue(TRUE);
    $this->addFieldMapping('field_external_url', 'link_url');

    // Add default mappings.
    $this->addFieldMapping('promote')->defaultValue(0);
    $this->addFieldMapping('sticky')->defaultValue(0);
    $this->addFieldMapping('comment')->defaultValue(0);
    $this->addFieldMapping('body:format')->defaultValue('full_html');
  }

  /**
   * Preprocess source row before things get passed to the destination.
   */
  public function prepareRow($row) {
    // Always include this fragment at the beginning of every prepareRow()
    // implementation, so parent classes can ignore rows.
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    // If name is empty, skip this row.
    if (empty($row->headline)) {
      return FALSE;
    }

    // Categories.
    $row->service_categories = array();
    if (!empty($row->category_1)) {
      $row->service_categories[] = $row->category_1;
    }
    if (!empty($row->category_2)) {
      $row->service_categories[] = $row->category_2;
    }
    if (!empty($row->topic_1)) {
      $row->service_categories[] = $row->topic_1;
    }
    if (!empty($row->topic_2)) {
      $row->service_categories[] = $row->topic_2;
    }

    // Handle boolean values; note these have to match values in field_service_type.
    $row->service_type = array();
    $row->online = !empty($row->online);
    if ($row->online) {
      $row->service_type[] = 'Online Services';
    }
    $row->data = !empty($row->data);
    if ($row->data) {
      $row->service_type[] = 'Data';
    }
    $row->grant = !empty($row->grant);
    if ($row->grant) {
      $row->service_type[] = 'Grant';
    }
    $row->law_regulation = !empty($row->law_regulation);
    if ($row->law_regulation) {
      $row->service_type[] = 'Laws & Regulation';
    }
    $row->license_permit = !empty($row->license_permit);
    if ($row->license_permit) {
      $row->service_type[] = 'License & Permit';
    }

    // Strip markup from link fields.
    $row->link_url = strip_tags($row->link_url);

    return TRUE;
  }
}
