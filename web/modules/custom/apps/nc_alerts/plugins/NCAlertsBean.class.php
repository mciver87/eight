<?php
/**
 * @file
 * NC Alerts Bean Class.
 */

class NCAlertsBean extends BeanPlugin {
  /**
   * Displays the bean.
   */
  public function view($bean, $content, $view_mode = 'default', $langcode = NULL) {
    $variables = array();
    $build = array();
    global $user;
    $wrapper = entity_metadata_wrapper('bean', $bean);
    $variables['title'] = $wrapper->field_alert_title->value();
    $variables['severity'] = $wrapper->field_alert_level->value();
    $variables['expires'] = $wrapper->field_alert_expiration->value();
    $variables['summary'] = $wrapper->field_alert_summary->value();
    $variables['id'] = "alert-{$bean->bid}";

    $link = isset($wrapper->field_alert_link) ? $wrapper->field_alert_link->value() : null;
    // Add link to the summary and title if field_alert_link is not empty.
    if (!empty($link)) {
      $variables['link'] = array(
        'url' => $wrapper->field_alert_link->url->value(),
        'title' => $wrapper->field_alert_link->title->value(),
        'attributes' => $wrapper->field_alert_link->attributes->value(),
      );
    }

    // Don't show alert if past its expiration date.
    if ($variables['expires'] >= time()) {
      $build = theme('alert', array('alert' => $variables));
    }
    return $build;
  }
}
