<?php
/**
 * @file
 * Document migration class.
 */

class MigrateNcshpDocumentMigration extends Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('Import SHP Documents from CSV file');
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'nc_shp_migrate') . '/files/shpdocs.csv',
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
        'uid' => array(
          'type' => 'varchar',
          'length' => 8,
          'not null' => TRUE,
          'description' => 'Unique ID of the document',
        )
      ),
      MigrateDestinationNode::getKeySchema()
    );

    // Add simple 1:1 mappings.
//    $this->addSimpleMappings(array(
//      'title',
//    ));

    // Add custom mappings.
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('status')
         ->defaultValue(TRUE);
    $this->addFieldMapping('body', 'short_description');
    $this->addFieldMapping('field_document_attachment', 'address');
    $this->addFieldMapping('field_document_attachment:destination_dir', 'destination_dir');
    $this->addFieldMapping('path', 'path');
    $this->addFieldMapping('field_document_type', 'terms');
    $this->addFieldMapping('field_document_type:create_term')
         ->defaultValue(TRUE);
    $this->addFieldMapping('pathauto')
         ->defaultValue(FALSE);
    $this->addFieldMapping('field_document_collection', 'document_collection');
    $this->addFieldMapping('field_document_collection:create_term')
         ->defaultValue(TRUE);
    $this->addFieldMapping('field_published_date', 'published');
    $this->addFieldMapping('field_revised_date', 'updated');
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
    $row->address = urldecode($row->address);

    $row->title = trim($row->title);
    // Replace empty titles with filenames.
    if (empty($row->title)) {
      $row->title = basename($row->address);
    }

    // Prepare the terms for the Pharmacy documents.
    if ($row->document_collection == 'Pharmacy Documents') {
      $pharmacy_list = variable_get('ncshppharmacy');
      // See if we can identify it.
      $full_path = $row->address;
      $parsed_path = pathinfo($full_path);
      $filename = $parsed_path['filename'];
      $item_key = FALSE;
      foreach ($pharmacy_list as $item_key => $item) {
        $find_name = strpos($filename, $item[0]);
        if ($find_name === false) {
          // Do nothing.
        }
        else {
          $found_element = $item_key;
        }
      }
      if (isset($found_element)) {
        $matched = $pharmacy_list[$found_element];
        // If so, replace the title with the "Correct" one,
        // Then add the generic name to the body, set first published
        // and last updated, and add 'terms' rows.
        $row->terms[] = $matched[5];
        $row_three = explode(',', $matched[3]);
        if (is_array($row_three) && !empty($row_three)) {
          foreach ($row_three as $three_term) {
            $row->terms[] = trim($three_term);
          }
        }
        $row->short_description = $matched[1];
        $row->published = strtotime($matched[2]);
        $row->updated = strtotime($matched[8]);
        $old_title = $row->title;
        $row->title = $matched[0];
      }  
    }
    // Now prepare the Address field, explode on |.
    // $row->address = explode("|", $row->address);

    // Set path default.
    $path_to_file_or_node = '';

    if (!empty($row->document_collection)) {
      $path_to_file_or_node .= strtolower(str_replace(' ', '-', $row->document_collection));
    }
    if ($row->document_collection == 'Pharmacy Documents') {
      $safe_title = mb_ereg_replace("([^\w\s\d\-.])", '', urldecode($old_title));
    }
    else {
      $safe_title = mb_ereg_replace("([^\w\s\d\-.])", '', urldecode($row->title));
    }
    $safe_title = mb_ereg_replace("([\.]{2,})", '', $safe_title);
    $safe_title = str_replace(' ', '-', $safe_title);
    $row->new_alias = $safe_title;
    if (!empty($path_to_file_or_node)) {
      $row->path = $path_to_file_or_node . '/' . strtolower(str_replace(' ', '-', $safe_title));
    }
    else {
      $row->path = strtolower(str_replace(' ', '-', $safe_title));
    }

    // Handle file destination directory.

    $row->destination_dir = 'public://documents/' . $path_to_file_or_node;

    return TRUE;
  }

/**
   * This is run after each file row is successfully migrated.
   */
  public function complete($node, $row) {
    // If a file object was created, and the file is actually supposed to be
    // renamed as part of the migration, do it here, as Migrate module doesn't
    // support renaming files.
    if (!empty($row->address)) {
      $original = basename($row->address);

      foreach (get_object_vars($node) as $key => $prop) {
        if (is_array($prop) && !empty($prop['und']) && !empty($prop['und'][0]) && isset($prop['und'][0]['fid'])) {
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
}
