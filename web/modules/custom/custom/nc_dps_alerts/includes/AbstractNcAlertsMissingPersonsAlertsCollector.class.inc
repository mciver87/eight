<?php
/**
 * @file
 * Code for receiving the alerts for NC DPS (Silver, Amber, Blue).
 */

abstract class AbstractNcAlertsMissingPersonsAlertsCollector extends CachedAlertsCollector {
  const CACHE_KEY = 'nc_dps_alerts_missing_persons_feed_data';
  const KEY_ALERT_SILVER = 'silver';
  const KEY_ALERT_AMBER = 'amber';
  const KEY_ALERT_BLUE = 'blue';

  /**
   * Constructor.
   *
   * Sets the default cache lifetime to the value
   * specified in the module's extension.
   */
  public function __construct() {
    $this->setCacheLifetime(
      variable_get(
        NcAlertsMissingPersonsForm::CACHE_LIFETIME_VARIABLE,
        static::DEFAULT_CACHE_LIFETIME
      )
    );
  }

  /**
   * Gets the feeds that should be displayed before/after the custom feeds.
   *
   * @param bool|TRUE $before_custom
   *   bool TRUE if before custom alerts, FALSE if to display after.
   *
   * @return array
   *   array of the feeds.
   */
  protected function getFeeds($before_custom = TRUE) {
    $available_feeds = array(
      self::KEY_ALERT_AMBER => array(
        'feed' => variable_get(
          NcAlertsMissingPersonsForm::URL_VARIABLE_AMBER,
          'https://www2.ncdps.gov/rss/rssAmberAlert.cfm'
        ),
        'position' => variable_get(
          NcAlertsMissingPersonsForm::ORDER_VARIABLE_AMBER,
          1
        ),
      ),
      self::KEY_ALERT_BLUE => array(
        'feed' => variable_get(
          NcAlertsMissingPersonsForm::URL_VARIABLE_BLUE,
          'https://www.ncdps.gov/rss/rssBlueAlert.cfm'
        ),
        'position' => variable_get(
          NcAlertsMissingPersonsForm::ORDER_VARIABLE_BLUE,
          2
        ),
      ),
      self::KEY_ALERT_SILVER => array(
        'feed' => variable_get(
          NcAlertsMissingPersonsForm::URL_VARIABLE_SILVER,
          'https://www.ncdps.gov/rss/rssSilverAlert.cfm'
        ),
        'position' => variable_get(
          NcAlertsMissingPersonsForm::ORDER_VARIABLE_SILVER,
          4
        ),
      ),
    );

    // Sort the array by position.
    uasort($available_feeds, array($this, 'sortFeeds'));

    $custom_position = variable_get(
      NcAlertsMissingPersonsForm::ORDER_VARIABLE_CUSTOM, 3
    );
    $feeds = array();

    foreach ($available_feeds as $name => $info) {
      if (($before_custom && $info['position'] <= $custom_position)
        || (!$before_custom && $info['position'] > $custom_position)) {
        $feeds[$name] = $info['feed'];
      }
    }

    return $feeds;
  }

  /**
   * Used to sort the available feeds.
   */
  protected function sortFeeds($a, $b) {
    if ($a['position'] == $b['position']) {
      return 0;
    }
    return ($a['position'] < $b['position']) ? -1 : 1;
  }

  /**
   * Retrieves the alerts from the passed feeds.
   *
   * @param array $feeds
   *   array Array of feeds to be retrieved.
   *
   * @return array
   *   Array of the retrieved data.
   */
  protected function retrieveAlerts(array $feeds) {
    $request = new DrupalRequestDelegate();
    $parser = new NcAlertsMissingPersonsResponseBodyParser();
    $connector = new RequestParserConnector($request, $parser);
    $connector->setFeeds($feeds);
    return $connector->getData();
  }
}
