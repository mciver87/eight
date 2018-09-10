<?php
/**
 * @file
 * Code for receiving the alerts for NC DPS (Silver, Amber, Blue) after the
 * custom alerts.
 */

class NcAlertsMissingPersonsAlertsCollectorPost extends AbstractNcAlertsMissingPersonsAlertsCollector {

  /**
   * Protected function that handles http requests.
   *
   * @return array
   *   Returns alert data.
   */
  protected function retrieveResults() {
    $feeds = $this->getFeeds(FALSE);
    if (!empty($feeds)) {
      return $this->retrieveAlerts($feeds);
    }
    return array();
  }

  /**
   * Get the cache id.
   *
   * @return string
   *   Cache id.
   */
  public function getCacheId() {
    return static::CACHE_KEY . '_post';
  }
}
