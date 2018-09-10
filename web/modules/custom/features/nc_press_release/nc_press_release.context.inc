<?php
/**
 * @file
 * nc_press_release.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function nc_press_release_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'press_release';
  $context->description = 'Context for Press Release content.';
  $context->tag = 'Content Types';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'press_release' => 'press_release',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'theme' => array(
      'title' => '',
      'subtitle' => '',
    ),
    'theme_html' => array(
      'class' => '',
    ),
    'block' => array(
      'blocks' => array(
        'views-68242c37a4b749b47a67ea2f6e272a4c' => array(
          'module' => 'views',
          'delta' => '68242c37a4b749b47a67ea2f6e272a4c',
          'region' => 'sidebar_second',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $context->hidden = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Content Types');
  t('Context for Press Release content.');
  $export['press_release'] = $context;

  return $export;
}
