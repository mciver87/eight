<?php
/**
 * @file
 * Code for the NC DPS Silver and Amber Alerts feature.
 */

class NcAlertsMissingPersonsAlertsCollector extends CachedAlertsCollector {
  const CACHE_KEY = 'nc_dps_alerts_missing_persons_feed_data';
  const KEY_ALERT_SILVER = 'silver';
  const KEY_ALERT_AMBER = 'amber';

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
   * Protected function that handles http requests.
   *
   * @return array
   *   Returns alert data.
   */
  protected function retrieveResults() {
    $request = new DrupalRequestDelegate();
    $parser = new NcAlertsMissingPersonsResponseBodyParser();
    $connector = new RequestParserConnector($request, $parser);
    $connector->setFeeds(
      array(
        self::KEY_ALERT_SILVER => variable_get(
          NcAlertsMissingPersonsForm::URL_VARIABLE_SILVER,
          'https://www.ncdps.gov/rss/rssSilverAlert.cfm'
        ),
        self::KEY_ALERT_AMBER => variable_get(
          NcAlertsMissingPersonsForm::URL_VARIABLE_AMBER,
          'https://www.ncdps.gov/rss/rssAmberAlert.cfm'
        ),
      )
    );

    return $connector->getData();
  }

  /**
   * Get the cache id.
   *
   * @return string
   *   Cache id.
   */
  public function getCacheId() {
    return static::CACHE_KEY;
  }
}
