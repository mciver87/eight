<?php
/**
 * @file
 * Code for the NC DPS Silver and Amber Alerts feature.
 */

/**
 * Class NcAlertsMissingPersonsResponseBodyParser
 */
class NcAlertsMissingPersonsResponseBodyParser extends AbstractResponseBodyParser {

  /**
   * Constructor.
   */
  public function __construct() {
    // Attempt to include the theme file for NC Alerts.
    module_load_include('inc', 'nc_alerts', 'nc_alerts.theme');
  }

  /**
   * Parse data.
   *
   * @param mixed $data
   *   Data.
   *
   * @param string $key
   *   Identifies which feed the url represents.
   *
   * @return array
   *   Parsed response.
   */
  public function parse($data, $key = NULL) {
    $alerts = array();

    try {
      $feed = new SimpleXMLElement($data);
      $channel = $feed->channel;

      foreach ($channel->item as $alert) {
        array_push($alerts, $this->parseAlert($alert, $key));
      }
    }
    catch (Exception $exception) {
      // Nothing to do here, there was an exception
      // move along and just be glad this is the worst
      // that happens.
    }

    return $alerts;
  }

  /**
   * Parse individual alert.
   *
   * @param mixed $alert
   *   Alert array.
   *
   * @param string $key
   *   Identifies which feed the url represents.
   *
   * @return array
   *   Parsed alert.
   */
  protected function parseAlert($alert, $key = NULL) {
    if (function_exists('nc_alerts_theme_alert_content')) {
      $title = sprintf('%s Alert', lcfirst($key));
      $link = $alert->link && count($alert->link) ? (string) $alert->link[0] : NULL;
      $alert = array(
        // 2016-01-15: Design spec is for the alert type/class to be breaking.
        'severity' => $this->getAlertSeverity($alert, $key),
        'id' => md5($alert->guid),
        'summary' => trim($alert->title),
        'title' => $title,
        'link' => array(
          'url' => html_entity_decode(trim($link)),
          'title' => t('Read More'),
          'attributes' => array(
            'alt' => t('Read More') . ' ' . trim($alert->title),
            'target' => '_blank',
          ),
        ),
      );

      return nc_alerts_theme_alert_content($alert);
    }
    else {
      // Do we need/want to do something here if the required
      // function goes away?
      return '';
    }
  }

  /**
   * Get the severity (i.e. the class).
   *
   * 2016-02-11: For Silver & Amber alerts, the severity/class
   * is breaking-silver or breaking-amber respectively.
   *
   * If this ever changes or there needs to be a more complex
   * transformation, you can change it here. Or you can use
   * the alter hook provided...
   *
   * {module}_nc_dps_alert_severity_alter(&$severity, &$key, &$alert).
   *
   * @param array $alert
   *   Alert array.
   *
   * @param string|null $key
   *   Key (silver / amber) to identify source.
   *
   * @return string
   *   Class.
   */
  protected function getAlertSeverity($alert, $key = NULL) {
    $severity = 'breaking' . (isset($key) ? '-' . $key : '');
    // You can override the severity in a theme or module now.
    // Use {module}_nc_dps_alert_severity_alter(&$severity, &$key, &$alert).
    drupal_alter('nc_dps_alert_severity', $severity, $key, $alert);
    return $severity;
  }
}
