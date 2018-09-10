<?php
/**
 * @file
 * Interface for alert collector.
 */

/**
 * Class CachedAlertsCollector
 */
abstract class CachedAlertsCollector extends AbstractAlertsCollector {
  const DEFAULT_CACHE_BIN = 'cache';
  const DEFAULT_CACHE_LIFETIME = 60;

  /**
   * This is the cache lifetime in seconds.
   *
   * @var int
   *   Int.
   */
  protected $cacheLifetime = self::DEFAULT_CACHE_LIFETIME;

  /**
   * This is the cache bin, likely 'cache' by default.
   *
   * @var string
   *   String.
   */
  protected $cacheBin = self::DEFAULT_CACHE_BIN;

  /**
   * Protected function that handles http requests.
   *
   * @return array
   *   Returns alert data.
   */
  abstract protected function retrieveResults();

  /**
   * Get the cache id.
   *
   * @return string
   *   Cache id.
   */
  abstract public function getCacheId();

  /**
   * Get alert data.
   *
   * Wrapper function for caching + remote request.
   *
   * @return array|bool
   *   Returns alerts data;
   */
  public function getAlerts() {
    if (!($alerts_data = $this->getCacheData())) {
      $alerts_data = $this->retrieveResults();
      $this->setCacheData($alerts_data);
    }

    return $alerts_data;
  }

  /**
   * Get cache bin.
   *
   * @return string
   *   Return cache bin.
   */
  public function getCacheBin() {
    return $this->cacheBin;
  }

  /**
   * Return cache bin for Drupal.
   *
   * @param string $cache_bin
   *   Bin.
   *
   * @return this
   *   Returns this.
   */
  public function setCacheBin($cache_bin) {
    $this->cacheBin = $cache_bin;
    return $this;
  }

  /**
   * Gets the cache lifetime (in seconds).
   *
   * @return bool|int
   *   Returns cache lifetime.
   */
  public function getCacheLifetime() {
    return $this->cacheLifetime;
  }

  /**
   * Sets cache lifetime.
   *
   * @param int $time
   *   Lifetime in seconds.
   *
   * @return this
   *   Returns this.
   */
  public function setCacheLifetime($time) {
    $this->cacheLifetime = $time;
    return $this;
  }

  /**
   * Computes UNIX timestamp for cache expiration.
   *
   * @return int
   *   Returns expiry.
   */
  protected function getCacheExpiration() {
    return REQUEST_TIME + $this->getCacheLifetime();
  }

  /**
   * Returns cached data.
   *
   * @return mixed
   *   Returns cache data.
   */
  protected function getCacheData() {
    // If cache lifetime == 0, cache is disabled,
    // for performance sake, skip the rest of this work.
    if ($this->getCacheLifetime() > 0) {
      // Pull the cache first.
      $cache = cache_get($this->getCacheId(), $this->getCacheBin());

      // Test cache & expiration.
      if ($cache && !empty($cache->expire) && REQUEST_TIME < $cache->expire) {
        return $cache->data;
      }
    }

    return FALSE;
  }

  /**
   * Set cache data.
   *
   * @param mixed $data
   *   Data to be cached.
   *
   * @return this
   *   Return this.
   */
  protected function setCacheData($data) {
    // If cache lifetime == 0, cache is disabled,
    // for performance sake, skip the rest of this work.
    if ($this->getCacheLifetime() !== 0) {
      cache_set(
        $this->getCacheId(),
        $data,
        $this->getCacheBin(),
        $this->getCacheExpiration()
      );
    }

    return $this;
  }
}
