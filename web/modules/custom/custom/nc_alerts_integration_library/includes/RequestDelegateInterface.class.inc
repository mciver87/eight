<?php
/**
 * @file
 * Request interface.
 */

/**
 * Interface RequestDelegateInterface
 */
interface RequestDelegateInterface {
  /**
   * Do request.
   *
   * @param string $url
   *   Url.
   * @param array $options
   *   Request options.
   *
   * @return mixed
   *   This.
   */
  public function request($url, $options = array());

  /**
   * Get Response.
   *
   * @return mixed
   *   Raw Response.
   */
  public function getResponse();

  /**
   * Get response body.
   *
   * @return mixed
   *   Response body.
   */
  public function getResponseBody();
}
