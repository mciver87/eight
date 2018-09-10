<?php
/**
 * @file
 * Contains migration source class for complex DHHS document catalog CSV file.
 */

/**
 * Implementation of MigrateDENRCSVSource.
 *
 * Borrows *heavily* from MigrateSourceCSV, but required too much of an
 * overhaul to just derive from that class.
 */
class MigrateDENRCSVSource extends MigrateSource {
  protected $groupCol = FALSE;
  protected $arrayCols = array();
  protected $file = NULL;
  protected $rows = array();
  protected $fields = array();
  protected $fgetcsv = array();
  protected $csvHandle = NULL;
  protected $csvcolumns = array();
  protected $headerRows = 0;
  protected $rowNumber = 0;

  /**
   * Simple initialization.
   *
   * @param string $path
   *  The path to the source file
   * @param array $csvcolumns
   *  Keys are integers. values are array(field name, description).
   * @param array $options
   *  Options applied to this source.
   * @param array $fields
   *  Optional - keys are field names, values are descriptions. Use to override
   *  the default descriptions, or to add additional source fields which the
   *  migration will add via other means (e.g., prepareRow()).
   */
  public function __construct($path, array $csvcolumns = array(), array $options = array(), array $fields = array()) {
    parent::__construct($options);
    $this->file = $path;
    $this->headerRows = !empty($options['header_rows']) ? $options['header_rows'] : 0;
    $this->groupCol = !empty($options['group_col']) ? $options['group_col'] : FALSE;
    $this->arrayCols = !empty($options['array_cols']) ? $options['array_cols'] : array();
    $this->options = $options;
    $this->fields = $fields;
    // fgetcsv specific options
    foreach (array('length' => NULL, 'delimiter' => ',', 'enclosure' => '"', 'escape' => '\\') as $key => $default) {
      $this->fgetcsv[$key] = isset($options[$key]) ? $options[$key] : $default;
    }
    // One can either pass in an explicit list of column names to use, or if we have
    // a header row we can use the names from that.
    if ($this->headerRows && empty($csvcolumns)) {
      $this->csvcolumns = array();
      $this->csvHandle = fopen($this->file, 'r');
      // Skip all but the last header.
      for ($i = 0; $i < $this->headerRows - 1; $i++) {
        $this->getNextLine();
      }

      $row = $this->getNextLine();
      foreach ($row as $header) {
        $header = trim($header);
        $this->csvcolumns[] = array($header, $header);
      }
      fclose($this->csvHandle);
      $this->csvHandle = NULL;
    }
    else {
      $this->csvcolumns = $csvcolumns;
    }

    // Now load CSV and build row array.
    $this->rows = $this->loadCSV();
  }

  /**
   * Load the CSV file into property.
   */
  protected function loadCSV() {
    $rows = array();

    if (!empty($this->file)) {
      $this->csvHandle = fopen($this->file, 'r');
      if ($this->csvHandle) {
        $menu_rows = array();
        while ($row = $this->getNextCSVRow()) {

          // Don't migrate the header row.
          if ($row['csvrownum'] != $this->headerRows - 1) {
            // Make sure this is a row we want to migrate.
            $row['ref_parent'] = !empty($row['ref_parent']) ? $row['ref_parent'] : 0;
            $title_key = array_filter(array_slice($row, 2, 7));
            $row['title'] = current($title_key);
            $depth = current(array_flip($title_key));
            $row['depth'] = str_replace('menu_', '', $depth);
            $menu_rows[] = $row;
          }
        }
        $rows = $menu_rows;
      }
    }
    return $rows;
  }

  /**
   * Return a string representing the source query.
   *
   * @return string
   *   The file.
   */
  public function __toString() {
    return $this->file;
  }

  /**
   * Returns a list of fields available to be mapped from the source query.
   *
   * @return array
   *   Keys: machine names of the fields (to be passed to addFieldMapping)
   *   Values: Human-friendly descriptions of the fields.
   */
  public function fields() {
    $fields = array();
    foreach ($this->csvcolumns as $values) {
      $fields[$values[0]] = $values[1];
    }

    // Any caller-specified fields with the same names as extracted fields will
    // override them; any others will be added.
    if ($this->fields) {
      $fields = $this->fields + $fields;
    }

    return $fields;
  }

  /**
   * Return a count of all available source records.
   */
  public function computeCount() {
    $rows = array();
    foreach ($this->rows as $index => $row) {
      if ($row['type'] == 'Site Page') {
        $rows[$index] = $row;
      }
    }
    return count($rows);
  }

  /**
   * Implements MigrateSource::performRewind().
   */
  public function performRewind() {
    $this->rowNumber = 1;
  }

  /**
   * Implements MigrateSource::getNextRow().
   *
   * Return the next line of the source CSV file as an object.
   *
   * @return null|object
   *   Return the row.
   */
  public function getNextRow() {
    $row = NULL;

    if (!empty($this->rows[$this->rowNumber])) {
      $row = (object) $this->rows[$this->rowNumber];
      $this->rowNumber++;
    }

    return $row;
  }

  /**
   * Retrieve next row from the CSV file.
   */
  public function getNextCSVRow() {
    $row = $this->getNextLine();
    if ($row) {
      // Only use rows specified in $this->csvcolumns().
      $row = array_intersect_key($row, $this->csvcolumns);
      // Set meaningful keys for the columns mentioned in $this->csvcolumns().
      foreach ($this->csvcolumns as $int => $values) {
        list($key, $description) = $values;
        // Copy value to more descriptive string based key and then unset
        // original.
        if (!in_array($key, $this->arrayCols)) {
          $row[$key] = isset($row[$int]) ? $row[$int] : NULL;
        }
        else {
          $row[$key] = isset($row[$int]) ? array($row[$int]) : array();
        }
        unset($row[$int]);
      }
      $row['csvrownum'] = $this->rowNumber++;
      return $row;
    }
    else {
      fclose($this->csvHandle);
      $this->csvHandle = NULL;
      return NULL;
    }
  }

  /**
   * Implements getNextLine().
   */
  protected function getNextLine() {
    // Escape parameter was added in PHP 5.3.
    if (version_compare(phpversion(), '5.3', '<')) {
      $row = fgetcsv($this->csvHandle, $this->fgetcsv['length'],
        $this->fgetcsv['delimiter'], $this->fgetcsv['enclosure']);
    }
    else {
      $row = fgetcsv($this->csvHandle, $this->fgetcsv['length'],
        $this->fgetcsv['delimiter'], $this->fgetcsv['enclosure'],
        $this->fgetcsv['escape']);
    }
    return $row;
  }
}
