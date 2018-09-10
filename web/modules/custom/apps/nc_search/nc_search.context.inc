<?php
/**
 * @file
 * nc_search.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function nc_search_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'search_page';
  $context->description = '';
  $context->tag = 'Search';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'search_results:page' => 'search_results:page',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;
  $context->hidden = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Search');
  $export['search_page'] = $context;

  return $export;
}
