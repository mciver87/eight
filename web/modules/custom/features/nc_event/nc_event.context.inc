<?php
/**
 * @file
 * nc_event.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function nc_event_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'event';
  $context->description = 'Context for Event content.';
  $context->tag = 'Content Types';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'event' => 'event',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean-nc_event_node_block_featured' => array(
          'module' => 'bean',
          'delta' => 'nc_event_node_block_featured',
          'region' => 'sidebar_second',
          'weight' => 0,
        ),
      ),
    ),
    'theme' => array(
      'title' => '',
      'subtitle' => '',
    ),
    'theme_html' => array(
      'class' => '',
    ),
  );
  $context->condition_mode = 0;
  $context->hidden = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Content Types');
  t('Context for Event content.');
  $export['event'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'events';
  $context->description = 'Context for events listing page';
  $context->tag = 'Views';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'event_list:page' => 'event_list:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-event_list-page' => array(
          'module' => 'views',
          'delta' => '-exp-event_list-page',
          'region' => 'content',
          'weight' => '-34',
        ),
      ),
    ),
    'theme' => array(
      'title' => '',
      'subtitle' => '',
    ),
    'theme_html' => array(
      'class' => '',
    ),
  );
  $context->condition_mode = 0;
  $context->hidden = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context for events listing page');
  t('Views');
  $export['events'] = $context;

  return $export;
}
