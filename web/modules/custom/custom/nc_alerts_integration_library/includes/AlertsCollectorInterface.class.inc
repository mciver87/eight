<?php
/**
 * @file
 * Interface for alert collector.
 */

interface AlertsCollectorInterface {
  /**
   * Get alert data.
   *
   * @return array|bool
   *   Returns alerts data;
   */
  public function getAlerts();
}
