<?php
/**
 * @file
 * Contains OSHR documents migration.
 */

class MigrateOSHRDocuments extends MigrateOSHRBase {
  /**
   * Class variables for holding related documents.
   */
  protected $archives = array();
  protected $history = array();

  /**
   * Constructor.
   */
  public function __construct($args) {
    parent::__construct($args);

    // Set up source.
    $url_source = variable_get('nc_migrate_oshr_documents', FALSE);
    if ($url_source) {
      $columns = array(
        0 => array('field_document_attachment', 'URL'),
        1 => array('title', 'Node title'),
        2 => array('body:summary', 'Short Description'),
        3 => array('body', 'Long Description'),
        5 => array('field_document_type', 'Topic'),
        6 => array('field_document_collection', 'Collection'),
      );
      $options = array(
        'header_rows' => 2,
        'embedded_newlines' => TRUE,
      );
      $this->source = new MigrateSourceCSV($url_source, $columns, $options);
    }

    // Set up destination.
    $this->destination = new MigrateDestinationNode('document');

    // Set source-dest ID map.
    $this->map = new MigrateSQLMap(
      $this->machineName,
      array(
        'main_url' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
          'description' => 'URL of source document',
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

    // Load additional document arrays.
    $csv_filename = variable_get('nc_migrate_oshr_archives', FALSE);
    if ($csv_filename) {
      $this->archives = $this->loadCSV($csv_filename, 1, 2);
    }
    $csv_filename = variable_get('nc_migrate_oshr_public_history', FALSE);
    if ($csv_filename) {
      $this->history = $this->loadCSV($csv_filename, 1, 2);
    }
  }

  /**
   * Prepare a proper unique key.
   */
  public function prepareKey($source_key, $row) {
    $key = array();
    $row->main_url = $row->field_document_attachment;
    $key['main_url'] = $row->main_url;
    return $key;
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
    if (empty($row->field_document_attachment) || empty($row->title)) {
      return FALSE;
    }

    // Make sure the URL is properly formed and add to files array.
    $files = array();
    $titles = array();

    $main_url = $row->main_url;
    $files[] = $this->fixURL($main_url);
    $titles[] = $row->title;

    // Add archives and public history docs to files array if present.
    if (!empty($this->archives[$main_url])) {
      foreach ($this->archives[$main_url] as $doc) {
        $files[] = $this->fixURL($doc['PDF file']);
        $titles[] = $doc['Title'];
      }
    }
    if (!empty($this->public_history[$main_url])) {
          foreach ($this->public_history[$main_url] as $doc) {
        $files[] = $this->fixURL($doc['PDF file']);
        $titles[] = $doc['Title'];
      }
    }

    // Add back to row.
    $row->file_title = $titles;
    $row->field_document_attachment = $files;

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
        // Generate crossref record for each file to this node as well as the file URL.
        $file = file_load($entity->field_document_attachment[$entity->language][$idx]['fid']);
        if ($file && !empty($file->uri)) {
          $new_url = file_create_url($file->uri);
          db_insert('nc_migrate_oshr_docrefs')
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
   * Called after rollback, passed array of entity IDs.
   */
  public function completeRollback($entity_ids) {
    parent::completeRollback($entity_ids);
    // Code to execute after an entity has been rolled back.
    db_delete('nc_migrate_oshr_docrefs')
      ->condition('nid', $entity_ids, 'IN')
      ->execute();
  }

  /**
   * Util method for loading archive list.
   */
  protected function loadCSV($filename, $col_name_row, $header_rows) {
    // Make sure we have this copied somewhere local.
    $docs = array();
    if (($handle = fopen($filename, "r")) !== FALSE) {
      $colnames = array();
      $rownum = 0;
      while (($row = fgetcsv($handle)) !== FALSE) {
        if ($col_name_row == $rownum) {
          // Col name row.
          foreach ($row as $colidx => $col) {
            if (!empty($col)) {
              $colnames[$colidx] = $col;
            }
          }
        }
        elseif ($rownum > $header_rows) {
          // Process row data.
          $doc = array();
          foreach ($row as $colidx => $col) {
            if (isset($colnames[$colidx])) {
              $doc[$colnames[$colidx]] = trim($col);
            }
          }

          // Perform final cleanup or row data.

          // Make sure this is a row we want to import.
          $target_url = $doc['Current Source URL'];
          if (!empty($target_url)) {
            $docs[$target_url][] = $doc;
          }
        }
        $rownum++;
      }
    }

    return $docs;
  }

  /**
   * Util method to fix partial URLs from document catalog.
   */
  protected function fixURL($url) {
    $url_scheme = parse_url($url, PHP_URL_SCHEME);
    if (!$url_scheme) {
      $url = 'http://' . $url;
    }

    return $url;
  }
}