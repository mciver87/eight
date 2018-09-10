<?php
/**
 * @file
 * Abstract request component.
 */

/**
 * Class AbstractRequestDelegate
 */
abstract class AbstractRequestDelegate implements RequestDelegateInterface {

  /**
   * The response.
   *
   * @var mixed
   */
  protected $response;

  /**
   * Do request.
   *
   * @param string $url
   *   Url.
   *
   * @param array $options
   *   Request options.
   *
   * @return mixed
   *   Request.
   */
  abstract public function request($url, $options = array());

  /**
   * Get response body.
   *
   * @return mixed
   *   Response body.
   */
  abstract public function getResponseBody();

  /**
   * Get full response.
   *
   * @return mixed
   *   Unaltered response.
   */
  public function getResponse() {
    return $this->response;
  }

  /**
   * Set response.
   *
   * @param mixed $response
   *   Response.
   *
   * @return AbstractRequestDelegate
   *   This.
   */
  protected function setResponse($response) {
    $this->response = $response;
    return $this;
  }
}
