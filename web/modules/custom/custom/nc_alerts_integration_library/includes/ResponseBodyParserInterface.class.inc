<?php
/**
 * @file
 * Parser interface.
 */

/**
 * Interface ResponseBodyParserInterface
 */
interface ResponseBodyParserInterface {
  /**
   * Parse data.
   *
   * @param mixed $data
   *   Data.
   *
   * @param string $key
   *   Identifies which feed the url represents.
   *
   * @return mixed
   *   Parsed output.
   */
  public function parse($data, $key = NULL);
}
