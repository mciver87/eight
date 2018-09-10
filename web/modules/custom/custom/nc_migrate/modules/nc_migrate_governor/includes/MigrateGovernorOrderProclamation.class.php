<?php
/**
 * @file
 * Contains class for Governor orders and proclamations migration.
 */

/**
 * Class definition for MigrateGovernorOrderProclamation.
 */
class MigrateGovernorOrderProclamation extends MigrateGovernorNodeBase {
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
    $this->source = $this->createSource('node', 'order_proclamation');

    // Set up destination.
    $this->destination = new MigrateDestinationNode('document');

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
    $url_base = 'http://' . $this->hostname . '/' . $this->public_base;

    $this->addSimpleMappings(array(
      'title',
      'status',
      'created',
      'changed',
    ));
    $this->addFieldMapping('body', 'body__und__0__value')->defaultValue('');
    $this->addFieldMapping('body:summary', 'body__und__0__summary')->defaultValue('');
    $this->addFieldMapping('field_published_date', 'field_date__und__0__value')->defaultValue('');
    $this->addFieldMapping('field_published_date:timezone')->defaultValue('America/New_York');
    $this->addFieldMapping('field_revised_date', 'field_date__und__0__value')->defaultValue('');
    $this->addFieldMapping('field_revised_date:timezone')->defaultValue('America/New_York');
    $this->addFieldMapping('field_document_collection', 'field_order_type__und__0__value');
    $this->addFieldMapping('field_document_collection:create_term')->defaultValue(TRUE);
    $this->addFieldMapping('field_document_collection:ignore_case')->defaultValue(TRUE);
    $this->addFieldMapping('field_document_attachment', 'field_pdf__url')->defaultValue('');
    $this->addFieldMapping('field_document_attachment:destination_file', 'field_pdf__filename')->defaultValue('');
    $this->addFieldMapping('field_document_attachment:source_dir')->defaultValue($url_base);
    $this->addFieldMapping('field_document_type', 'field_topics__und__0__tid')->defaultValue('')->sourceMigration(array('MigrateGovernorDocumentTerms'));
    $this->addFieldMapping('field_document_type:source_type')->defaultValue('tid');

    //$this->addFieldMapping('field_key_search_topics', 'field_topics');
    //$this->addFieldMapping('field_key_search_topics:create_term')->defaultValue(TRUE);
    //$this->addFieldMapping('field_key_search_topics:ignore_case')->defaultValue(TRUE);

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

    // Build file field value.
    $row->field_pdf__url = array();
    $row->field_pdf__filename = array();
    if (!empty($row->field_pdf['und'])) {
      foreach ($row->field_pdf['und'] as $file) {
        $row->field_pdf__filename = $file['filename'];
        $row->field_pdf__url[] = str_replace('public://', '', $file['uri']);
      }
    }

    return TRUE;
  }
}
