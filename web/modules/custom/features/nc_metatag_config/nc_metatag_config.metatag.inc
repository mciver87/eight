<?php
/**
 * @file
 * Include file with metatag moudle hooks.
 */

/**
 * Implements hook_metatag_config_default().
 */
function nc_metatag_config_metatag_config_default() {
  $configs = array();

  $config = new stdClass();
  $config->disabled = FALSE; /* Edit this to true to make a default config disabled initially */
  $config->api_version = 1;
  $config->instance = 'global:frontpage';
  $config->config = array(
    'title' => array(
      'value' => 'NC.gov: The Official Site of the State of North Carolina.',
    ),
    'description' => array(
      'value' => 'NC.gov is your portal to NC state governments. Get access to online services, state agencies, contact numbers. Explore the great state of North Carolina. Read how to start a business in NC. Learn how your tax dollars are being spent.',
    ),
    'canonical' => array(
      'value' => '[site:url]',
    ),
    'shortlink' => array(
      'value' => '[site:url]',
    ),
  );

  $configs[$config->instance] = $config;

  return $configs;
}
