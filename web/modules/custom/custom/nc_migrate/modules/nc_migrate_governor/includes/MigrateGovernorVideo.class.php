<?php
/**
 * @file
 * Contains class for Governor videos migration.
 */

/**
 * Class definition for MigrateGovernorVideo.
 */
class MigrateGovernorVideo extends MigrateGovernorNodeBase {
  protected $videos = array();

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
    $this->source = $this->createSource('node', 'video');

    // Set up destination.
    $this->destination = new MigrateDestinationNode('video');

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
    $this->addFieldMapping('body', 'field_description__und__0__value')->defaultValue('');
    $this->addFieldMapping('body:summary', 'body__und__0__summary')->defaultValue('');
    $this->addFieldMapping('field_video', 'field_youtube_url')->defaultValue('');
    $this->addFieldMapping('field_published_date', 'field_date__und__0__value')->defaultValue('');
    $this->addFieldMapping('field_published_date:timezone')->defaultValue('America/New_York');
    $this->addFieldMapping('field_video_terms', 'field_topics__und__0__tid')->defaultValue('')->sourceMigration(array('MigrateGovernorVideoTerms'));
    $this->addFieldMapping('field_video_terms:source_type')->defaultValue('tid');

    // Add default mappings.
    $this->addFieldMapping('promote')->defaultValue(0);
    $this->addFieldMapping('sticky')->defaultValue(0);
    $this->addFieldMapping('comment')->defaultValue(0);
    $this->addFieldMapping('body:format')->defaultValue('full_html');

    // Preload video "files" for YouTube links.
    $this->_getVideoFiles();
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

    // Derive video URL from fid.
    $fid = $row->field_youtube__und__0__fid;
    if (!empty($this->videos[$fid]) && strpos($this->videos[$fid]->uri, 'youtube://') !== FALSE) {
      $row->field_youtube_url = str_replace('youtube://', 'http://www.youtube.com/', $this->videos[$fid]->uri);
    }

    return TRUE;
  }

  /**
   * Util function to preload all video "file" entities from legacy site.
   */
  protected function _getVideoFiles() {
    // Set up source.
    $videos = $this->createSource('file', 'video');
    while ($video = $videos->getNextRow()) {
      $this->videos[$video->fid] = $video;
    }
  }
}
