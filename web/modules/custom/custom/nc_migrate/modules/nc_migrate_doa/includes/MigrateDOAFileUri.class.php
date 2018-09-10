<?php
/**
 * @file
 * Implementation of MigrateDOAFileUri for DOA.
 */

class MigrateDOAFileUri extends MigrateFileUri {
  /**
   * Constructor.
   */
  public function __construct($arguments = array(), $default_file = NULL) {
    parent::__construct($arguments, $default_file);
  }

  /**
   * Implementation of MigrateFileInterface::fields().
   *
   * @return array
   */
  static public function fields() {
    return parent::fields();
  }

  /**
   * Implementation of MigrateFile::copyFile().
   *
   * @param $destination
   *  Destination within Drupal.
   *
   * @return bool
   *  TRUE if the copy succeeded, FALSE otherwise.
   */
  protected function copyFile($destination) {
    if (FALSE !== strpos($destination, ' ')) {
      // A string literal ` ` exists in the destination url, so we need to
      // urlencode.
      $this->urlEncode = TRUE;
    }
    if ($this->urlEncode) {
      // Path may need to be encoded depending on
      // Perform the copy operation, with a cleaned-up path.
      $this->sourcePath = self::urlencode($this->sourcePath);
    }
    try {
      copy($this->sourcePath, $destination);
      return TRUE;
    }
    catch (Exception $e) {
      $migration = Migration::currentMigration();
      $migration->saveMessage(t('The specified file %file could not be copied to %destination: "%exception_msg"',
        array('%file' => $this->sourcePath, '%destination' => $destination, '%exception_msg' => $e->getMessage())));
      return FALSE;
    }
  }

  /**
   * Urlencode all the components of a remote filename.
   *
   * @param $filename
   *
   * @return string
   */
  static public function urlencode($filename) {
    return parent::urlencode($filename);
  }

  /**
   * Implementation of MigrateFileInterface::processFiles().
   *
   * This is a clone of the processFile() method from the MigrateFileUri method.
   *
   * @param $value
   *  The URI or local filespec of a file to be imported.
   * @param $owner
   *  User ID (uid) to be the owner of the file.
   * @return object
   *  The file entity being created or referenced.
   */
  public function processFile($value, $owner) {
    // Identify the full path to the source file
    if (!empty($this->sourceDir)) {
      $this->sourcePath = rtrim($this->sourceDir, "/\\") . '/' . ltrim($value, "/\\");
    }
    else {
      $this->sourcePath = $value;
    }

    if (empty($this->destinationFile)) {
      $this->destinationFile = basename($this->sourcePath);
    }

    // MigrateFile has most of the smarts - the key is that it will call back
    // to our copyFile() implementation.
    $file = parent::processFile($value, $owner);

    return $file;
  }
}
