<?php
/**
 * @file
 * nc_alerts.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function nc_alerts_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'alerts';
  $context->description = 'North Carolina Alerts and Notifications';
  $context->tag = 'Notifications';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'nc_alerts-nc_alerts_block' => array(
          'module' => 'nc_alerts',
          'delta' => 'nc_alerts_block',
          'region' => 'alert_box',
          'weight' => '0',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $context->hidden = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('North Carolina Alerts and Notifications');
  t('Notifications');
  $export['alerts'] = $context;

  return $export;
}
