<?php
/**
 * @file
 * nc_varnish.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function nc_varnish_strongarm() {
  $export = array();
  global $shortcode;
  global $base_url;
  global $os_env;

  $env = $os_env;
  if ($env != 'prod') {
    $env = 'nonprod';
  }

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'purge_proxy_urls';
  if ($env != 'prod') {
    $strongarm->value = 'http://v1.' . $env . '.aws:6081';
  }
  else {
    $strongarm->value = 'http://v1.' . $env . '.aws:6081 http://v2.' . $env . '.aws:6081';
  }
  $export['purge_proxy_urls'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'varnish_tag_invalidate_entities_view';
  $strongarm->value = array(
    'bean' => 'bean',
    'comment' => 'comment',
    'field_collection_item' => 'field_collection_item',
    'i18n_translation' => 'i18n_translation',
    'node' => 'node',
    'paragraphs_item' => 'paragraphs_item',
    'redirect' => 'redirect',
    'search_api_server' => 'search_api_server',
    'search_api_index' => 'search_api_index',
    'file' => 'file',
    'taxonomy_term' => 'taxonomy_term',
    'taxonomy_vocabulary' => 'taxonomy_vocabulary',
    'user' => 'user',
    'wysiwyg_profile' => 'wysiwyg_profile',
    'twitter_status' => 'twitter_status',
    'twitter_account' => 'twitter_account',
    'workbench_moderation_transition' => 'workbench_moderation_transition',
    'menu_link' => 'menu_link',
  );
  $export['varnish_tag_invalidate_entities_view'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'varnish_tag_invalidate_header';
  $strongarm->value = 'X-Varnish-Tag';
  $export['varnish_tag_invalidate_header'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'varnish_tag_invalidate_hosts';
  $strongarm->value = $base_url;
  $export['varnish_tag_invalidate_hosts'] = $strongarm;

  return $export;
}
