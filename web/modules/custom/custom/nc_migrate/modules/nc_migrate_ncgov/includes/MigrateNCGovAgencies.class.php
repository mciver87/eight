<?php
/**
 * @file
 * Contains class for NC.Gov agencies migration.
 */

/**
 * Class definition for MigrateNCGovAgencies.
 */
class MigrateNCGovAgencies extends MigrateNCGovNodeBase {
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
      0 => array('name', 'Name'),
      1 => array('phone', 'Phone'),
      2 => array('short_description', 'Short Description'),
      3 => array('external_link', 'External Link'),
      4 => array('topic_empty', 'Topic Category (empty?)'),
      5 => array('topic_1', 'Topic Category'),
      6 => array('topic_2', '2nd Topic'),
      7 => array('tags', 'Keyword Tags'),
      8 => array('social_links', 'Social Links'),
      9 => array('more_contacts', 'More Contacts'),
    );
    $options = array(
      'header_rows' => 1,
      'embedded_newlines' => TRUE,
    );
    $fields = array(
      'topics' => 'Aggregated topics (topic_1, topic_2)',
      'external_link__title' => 'Link title subfield for external_link',
      'social_links__title' => 'Link title subfield for social_link',
    );
    $csv_path = variable_get('nc_migrate_ncgov_agencies_csv', '');
    $this->source = new MigrateSourceCSV($csv_path, $columns, $options, $fields);

    // Set up destination.
    $this->destination = new MigrateDestinationNode('agency');

    // Set source-dest ID map.
    $source_key = array(
      'name' => array(
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
    $this->addFieldMapping('title', 'name');
    $this->addFieldMapping('field_agency_phone', 'phone');
    $this->addFieldMapping('body', 'short_description');
    $this->addFieldMapping('field_agency_card_link', 'external_link');
    $this->addFieldMapping('field_agency_social_links', 'social_links');
    $this->addFieldMapping('field_agency_category:create_term')->defaultValue(TRUE);
    $this->addFieldMapping('field_agency_category:ignore_case')->defaultValue(TRUE);
    $this->addFieldMapping('field_key_search_topics', 'tags');
    $this->addFieldMapping('field_key_search_topics:create_term')->defaultValue(TRUE);
    $this->addFieldMapping('field_key_search_topics:ignore_case')->defaultValue(TRUE);

    // Fields generated in prepareRow().
    $this->addFieldMapping('field_agency_card_link:title', 'external_link__title');
    $this->addFieldMapping('field_agency_social_links:title', 'social_links__title');
    $this->addFieldMapping('field_agency_category', 'topics');

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
    if (empty($row->name)) {
      return FALSE;
    }

    // Fix empty phone number validation.
    $row->phone = trim($row->phone);

    // Clean up any A tags from original document export.
    $row->external_link = strip_tags($row->external_link);

    // Map link to title for card links.
    $row->external_link__title = $row->external_link;

    // Break out social links based on whatever we've seen in the CSV.
    $row->social_links = trim($row->social_links);
    if (!empty($row->social_links)) {
      $social_links = str_replace(array("\n", ' '), '|', $row->social_links);
      $row->social_links = explode('|', $social_links);
      array_walk($row->social_links, function(&$value, $index) {
        $value = str_replace('"', '', strip_tags($value));
      });
    }
    else {
      $row->social_links = array();
    }

    // Perform very basic social network identificatuon based on URL.
    foreach ($row->social_links as $link) {
      $title = $link;
      $network_matches = array(
        'twitter' => 'Twitter',
        'facebook' => 'Facebook',
        'youtube' => 'Youtube',
        'flickr' => 'Flickr',
        'pinterest' => 'Pinterest',
        'instagram' => 'Instagram',
        'linkedin' => 'LinkedIn',
        'wordpress' => 'Wordpress',
      );
      foreach ($network_matches as $match => $name) {
        if (strstr($link, $match)) {
          $title = $name;
          break;
        }
      }
      $row->social_links__title[] = $title;
    }

    // Aggregate topic columns.
    $row->topics = array_merge(explode(',', $row->topic_1), explode(',', $row->topic_2));

    // Clean up tags.
    $row->tags = explode(',', $row->tags);

    return TRUE;
  }
}
