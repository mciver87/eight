<?php
/**
 * @file
 * Wrapper for Drupal http requests.
 */

/**
 * Class DrupalRequestDelegate.
 *
 * Acts as a wrapper around drupal_http_request.
 */
class DrupalRequestDelegate extends AbstractRequestDelegate {
  const TIMEOUT = 15;

  /**
   * Do request.
   *
   * @param string $url
   *   Url.
   *
   * @param array $options
   *   Request options.
   *
   * @return DrupalRequestDelegate
   *   Request delegate.
   */
  public function request($url, $options = array()) {
    if ($options && is_array($options)) {
      $options = array_merge_recursive($this->getRequestOptions(), $options);
    }

    try {
      $this->setResponse(drupal_http_request($url, $options));
    }
    catch (Exception $exception) {
      // Do anything here?
      $this->setResponse(array());
    }

    return $this;
  }

  /**
   * Get the default request options.
   *
   * @return array
   *   Default request options.
   */
  public function getRequestOptions() {
    return array('timeout' => static::TIMEOUT);
  }

  /**
   * Get response body.
   *
   * @return mixed
   *   Response body.
   */
  public function getResponseBody() {
    // TODO: Error checks.
    return $this->getResponse()->data;
  }
}
