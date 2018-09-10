<?php
/**
 * @file
 * Contains class for Governor press release migration.
 */

/**
 * Class definition for MigrateGovernorPressRelease.
 */
class MigrateGovernorPressRelease extends MigrateGovernorNodeBase {
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
    $this->source = $this->createSource('node', 'press_release');

    // Set up destination.
    $this->destination = new MigrateDestinationNode('press_release');

    // Set source-dest ID map.
    $source_key = array(
      'nid' => array('type' => 'int',
        'unsigned' => TRUE,
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
    $this->addSimpleMappings(array(
      'title',
      'status',
      'created',
      'changed',
    ));
    $this->addFieldMapping('body', 'body__und__0__value');
    $this->addFieldMapping('body:summary', 'field_subtitle__und__0__value');
    $this->addFieldMapping('field_release_date', 'field_date__und__0__value');
    $this->addFieldMapping('field_release_date:timezone')->defaultValue('America/New_York');
    $this->addFieldMapping('field_related_content', 'field_links__url');
    $this->addFieldMapping('field_related_content:title', 'field_links__title');
    $this->addFieldMapping('field_press_release_terms', 'field_topics__und__0__tid')->defaultValue('')->sourceMigration(array('MigrateGovernorPressReleaseTerms'));
    $this->addFieldMapping('field_press_release_terms:source_type')->defaultValue('tid');

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

    // We have a raw decode of a JSON-encoded node, flatten out fields.
    $flattened = $this->_flattenArray((array) $row);
    foreach ($flattened as $key => $val) {
      $row->{$key} = $val;
    }

    // Remove spacer P elements from body content.
    if (!empty($row->body__und__0__value)) {
      $row->body__und__0__value = str_replace(
        array(
          '<p><span>&nbsp;</span></p>',
          '<p>&nbsp;</p>',
          '<p><strong>&nbsp;</strong></p>',
        ),
        '',
        $row->body__und__0__value
      );
    }
    if (!empty($row->body__und__0__summary)) {
      $row->body__und__0__summary = str_replace(
        array(
          '<p><span>&nbsp;</span></p>',
          '<p>&nbsp;</p>',
          '<p><strong>&nbsp;</strong></p>',
        ),
        '',
        $row->body__und__0__summary
      );
    }

    // Rewrite link fields.
    $row->field_links__url = array();
    $row->field_links__title = array();
    if (!empty($row->field_links['und'])) {
      foreach ($row->field_links['und'] as $link) {
        $row->field_links__url[] = $link['url'];
        $row->field_links__title[] = $link['title'];
      }
    }

    return TRUE;
  }

  /**
   * Util method to flatten an array into property-safe names.
   */
  protected function _flattenArray($arr, $prefix = NULL) {
    $new_arr = array();
    foreach ($arr as $key => $value) {
      $new_key = $prefix ? "{$prefix}__{$key}" : $key;
      if (is_array($value) && !is_string($value)) {
        $new_arr += $this->_flattenArray($value, $new_key);
      }
      else {
        $new_arr[$new_key] = $value;
      }
    }

    return $new_arr;
  }
}
