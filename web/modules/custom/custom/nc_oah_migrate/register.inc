<?php
/**
 * @file
 * Document migration class.
 */

class MigrateNcoahRegisterMigration extends Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('Import OAH Register Documents from CSV file');
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'nc_oah_migrate') . '/files/register.csv',
      array(),
      array(
        'header_rows' => 1,
        'embedded_newlines' => TRUE,
      )
    );
    $this->destination = new MigrateDestinationNode('document');
    // Set source-dest ID map.
    $this->map = new MigrateSQLMap(
      $this->machineName,
      array(
        'fid' => array(
          'type' => 'varchar',
          'length' => 7,
          'not null' => TRUE,
          'description' => 'Unique ID of the document',
        )
      ),
      MigrateDestinationNode::getKeySchema()
    );

    // Add custom mappings.
    // File
    $this->addFieldMapping('field_document_attachment', 'file');
    $this->addFieldMapping('field_document_attachment:urlencode')
      ->defaultValue(0);
    // Title
    $this->addFieldMapping('title', 'title');
    // Document Collection
    $this->addFieldMapping('field_document_collection')
      ->defaultValue('The North Carolina Register');
    $this->addFieldMapping('field_document_collection:create_term')
      ->defaultValue(TRUE);
    // Status
    $this->addFieldMapping('status')
      ->defaultValue(TRUE);
    // Pathauto
    $this->addFieldMapping('path', 'path');
    $this->addFieldMapping('pathauto')
         ->defaultValue(FALSE);
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
    $row->title = basename($row->file);
    $adjusted_title = urldecode($row->title);
    $adjusted_title = strtolower($adjusted_title);
    $adjusted_title = str_replace(' ', '', $adjusted_title);
    $adjusted_title_array = explode('issue', $adjusted_title);
    $issue_number = substr($adjusted_title_array[1], 0, 2);
    $volume_number = str_replace('volume', '', $adjusted_title_array[0]);
    $row->title = 'Volume ' . $volume_number . ' Issue ' . $issue_number;
    $row->path = 'documents/the-register' . '/' . strtolower(str_replace(' ', '-', $row->title));
    $row->title = 'NC Register ' . $row->title;
    $ext = pathinfo($row->file, PATHINFO_EXTENSION);
    $row->new_alias = str_replace(' ', '-', $row->title) . '.' . $ext;

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

  public function complete($node, $row) {
    // If a file object was created, and the file is actually supposed to be
    // renamed as part of the migration, do it here, as Migrate module doesn't
    // support renaming files.
    if (!empty($row->file)) {
      $original = basename($row->file);

      foreach (get_object_vars($node) as $key => $prop) {
        if (is_array($prop)) {
          if ($prop['und'][0]['fid'] > 0) {
            // We have file id.
            $file_obj = file_load($prop['und'][0]['fid']);
            $target = basename($row->new_alias);
            $src = basename($file_obj->filename);

            if ($target != $src) {
              drush_print("Target $target is not equal to source $src");
              $target_uri = substr($file_obj->uri, 0, strrpos($file_obj->uri, '/')) . '/' . $target;

              if ($uri = file_unmanaged_move($file_obj->uri, $target_uri, FILE_EXISTS_ERROR)) {
                // Some of this code lifted from file_move(), which doesn't work
                // properly, see core bug /node/1415858
                $file = clone $file_obj;
                $file->uri = $uri;
                $file->filename = basename($target_uri);
                $file = file_save($file);

                // Inform modules that the file has been moved.
                module_invoke_all('file_move', $file, $source);                
              }
            }
          }
        }
      }
    }
  }
}
