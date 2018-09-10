<?php
/**
 * @file
 * Code for receiving the alerts for NC DPS (Silver, Amber, Blue) before the
 * custom alerts.
 */

class NcAlertsMissingPersonsAlertsCollectorPre extends AbstractNcAlertsMissingPersonsAlertsCollector {

  /**
   * Protected function that handles http requests.
   *
   * @return array
   *   Returns alert data.
   */
  protected function retrieveResults() {
    $feeds = $this->getFeeds(TRUE);
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
    return static::CACHE_KEY . '_pre';
  }
}
