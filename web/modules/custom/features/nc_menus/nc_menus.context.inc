<?php
/**
 * @file
 * nc_menus.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function nc_menus_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sidebar_navigation';
  $context->description = 'sidebar secondary and tertiary navigation';
  $context->tag = 'navigation';
  $context->conditions = array(
    'exclusion' => array(
      'values' => array(
        'landing_page' => 'landing_page',
        'agency' => 'agency',
        'data_table' => 0,
        'blog_entry' => 0,
        'document' => 0,
        'event' => 0,
        'media_gallery' => 0,
        'photo' => 0,
        'profile' => 0,
        'press_release' => 0,
        'services' => 0,
        'site_page' => 0,
        'webform' => 0,
      ),
      'options' => array(
        'node_form' => '0',
        'paths' => '~<front>',
        'reverse' => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-nc_menus-1' => array(
          'module' => 'menu_block',
          'delta' => 'nc_menus-1',
          'region' => 'sidebar_second',
          'weight' => '0',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('navigation');
  t('sidebar secondary and tertiary navigation');
  $export['sidebar_navigation'] = $context;

  return $export;
}
