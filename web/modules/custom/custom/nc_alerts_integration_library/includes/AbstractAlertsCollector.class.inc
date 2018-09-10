<?php
/**
 * @file
 * Interface for alert collector.
 */

/**
 * Class AbstractAlertsCollector.
 */
abstract class AbstractAlertsCollector {
  /**
   * Get alert data.
   *
   * @return array|bool
   *   Returns alerts data;
   */
  abstract public function getAlerts();
}
