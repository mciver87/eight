<?php
/**
 * @file
 * nc_layout.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function nc_layout_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'blog';
  $context->description = 'Context for Blog Entry content.';
  $context->tag = 'Content Types';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'blog_entry' => 'blog_entry',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;
  $context->hidden = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Content Types');
  t('Context for Blog Entry content.');
  $export['blog'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'blog_list';
  $context->description = 'Context for Blog list View.';
  $context->tag = 'Views';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'blog_entry_list:page_1' => 'blog_entry_list:page_1',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;
  $context->hidden = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context for Blog list View.');
  t('Views');
  $export['blog_list'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'homepage';
  $context->description = 'Context for the site\'s front page.';
  $context->tag = 'Homepage';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;
  $context->hidden = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t("Context for the site's front page.");
  t('Homepage');
  $export['homepage'] = $context;

  return $export;
}
