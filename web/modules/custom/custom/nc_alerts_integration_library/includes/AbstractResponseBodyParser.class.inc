<?php
/**
 * @file
 * Abstract parser.
 */

/**
 * Class AbstractResponseBodyParser
 */
abstract class AbstractResponseBodyParser implements ResponseBodyParserInterface {
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
   *   Parsed data.
   */
  abstract public function parse($data, $key = NULL);
}
