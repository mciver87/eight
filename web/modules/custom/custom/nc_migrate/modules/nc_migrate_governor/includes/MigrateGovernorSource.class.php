<?php
/**
 * @file
 * Contains the class definition for MigrateGovernorSource.
 */

/**
 * Provides the source class for Governor site JSON feeds.
 */
class MigrateGovernorSource extends MigrateSource {
  /**
   * Variables related to Governor JSON source.
   */
  public $hostname = NULL;
  public $public_base = '';
  public $entity_type = NULL;
  public $bundle = NULL;
  public $json_url;

  /**
   * Variables used for managing source traversal.
   */
  public $entities = array();
  public $offset = 0;
  public $highwaterField = 'changed';

  /**
   * Simple initialization.
   *
   * @param string $account
   *  The account shortname used to access the API.
   * @param string $api_key
   *  The API key from GatherContent.
   * @param string $project_id
   *  The numeric project ID to load pages and templates from.
   * @param string $template_id
   *  The numeric template ID to filter pages on.
   */
  public function __construct($hostname, $public_base, $secret, $entity_type, $bundle) {
    // Store off source info we'll need later.
    $this->hostname = $hostname;
    $this->public_base = $public_base;
    $this->entity_type = $entity_type;
    $this->bundle = $bundle;

    // Retrieve entities.
    $this->json_url = url('http://' . $hostname . '/entity-dump', array('query' => array(
      'entity' => $entity_type,
      'bundle' => $bundle,
      'secret' => $secret,
    )));
    $resp = drupal_http_request($this->json_url);
    if (200 == $resp->code) {
      $data = json_decode($resp->data, TRUE);
      if ($data) {
        $this->entities = array_values($data);
      }
    }
  }

  /**
   * Return a string representing the source query.
   *
   * @return string
   */
  public function __toString() {
    return $this->json_url . '/' . $this->entity_type . '/' . $this->bundle;
  }

  /**
   * Returns a list of fields available to be mapped from the source query.
   *
   * @return array
   *  Keys: machine names of the fields (to be passed to addFieldMapping)
   *  Values: Human-friendly descriptions of the fields.
   */
  public function fields() {
    $fields = array();

    return $fields;
  }

  /**
   * Return a count of all available source records.
   */
  public function computeCount() {
    return count($this->entities);
  }

  /**
   * Implementation of MigrateSource::performRewind().
   *
   * @return void
   */
  public function performRewind() {
    $this->offset = 0;
  }

  /**
   * Implementation of MigrateSource::getNextRow().
   * Return the next line of the source as an object.
   *
   * @return null|object
   */
  public function getNextRow() {
    $row = NULL;

    if (isset($this->entities[$this->offset])) {
      // Init row object, store GatherContent page metadata fields.
      $entity = $this->entities[$this->offset];
      $row = (object) $entity;
      $this->offset++;
    }

    return $row;
  }
}
