<?php
/**
 * @file
 * nc_document.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function nc_document_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'document';
  $context->description = 'Context for Document content.';
  $context->tag = 'Content Types';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'document' => 'document',
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
  t('Context for Document content.');
  $export['document'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'documents';
  $context->description = '';
  $context->tag = 'Views';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'nc_documents:page_1' => 'nc_documents:page_1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-nc_documents-page_1' => array(
          'module' => 'views',
          'delta' => '-exp-nc_documents-page_1',
          'region' => 'content',
          'weight' => '-26',
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
  t('Views');
  $export['documents'] = $context;

  return $export;
}
