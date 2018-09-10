<?php
/**
 * @file
 * nc_oauth.oauth.inc
 */

/**
 * Implements hook_default_oauth_common_context().
 */
function nc_oauth_default_oauth_common_context() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 1;
  $context->name = 'filebrowser';
  $context->title = 'filebrowser';
  $context->authorization_options = array(
    'access_token_lifetime' => '7500',
    'page_title' => NULL,
    'message' => NULL,
    'warning' => NULL,
    'deny_access_title' => NULL,
    'grant_access_title' => NULL,
    'disable_auth_level_selection' => 1,
    'automatic_authorization' => 1,
    'signature_methods' => array(
      0 => 'HMAC-SHA1',
    ),
    'default_authorization_levels' => array(
      0 => 'base',
    ),
  );
  $context->authorization_levels = array(
    'base' => array(
      'name' => 'base',
      'title' => 'base',
      'default' => 1,
      'delete' => 0,
      'description' => '',
    ),
  );
  $export['filebrowser'] = $context;

  return $export;
}
