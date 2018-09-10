<?php
/**
 * @file
 * nc_osbm_document.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function nc_osbm_document_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'osbm_documents';
  $view->description = 'Creates a list page of documents with links to detail pages as well as downloads.';
  $view->tag = 'OpenPublic';
  $view->base_table = 'node';
  $view->human_name = 'OSBM Documents';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Statistics';
  $handler->display->display_options['css_class'] = 'content-listing results';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: File Usage: File */
  $handler->display->display_options['relationships']['node_to_file']['id'] = 'node_to_file';
  $handler->display->display_options['relationships']['node_to_file']['table'] = 'file_usage';
  $handler->display->display_options['relationships']['node_to_file']['field'] = 'node_to_file';
  /* Relationship: Content: Data Year (field_data_year) */
  $handler->display->display_options['relationships']['field_data_year_tid']['id'] = 'field_data_year_tid';
  $handler->display->display_options['relationships']['field_data_year_tid']['table'] = 'field_data_field_data_year';
  $handler->display->display_options['relationships']['field_data_year_tid']['field'] = 'field_data_year_tid';
  /* Relationship: Content: Data Race (field_data_race) */
  $handler->display->display_options['relationships']['field_data_race_tid']['id'] = 'field_data_race_tid';
  $handler->display->display_options['relationships']['field_data_race_tid']['table'] = 'field_data_field_data_race';
  $handler->display->display_options['relationships']['field_data_race_tid']['field'] = 'field_data_race_tid';
  /* Relationship: Content: Data Race (field_data_race) */
  $handler->display->display_options['relationships']['field_data_race_tid_1']['id'] = 'field_data_race_tid_1';
  $handler->display->display_options['relationships']['field_data_race_tid_1']['table'] = 'field_data_field_data_race';
  $handler->display->display_options['relationships']['field_data_race_tid_1']['field'] = 'field_data_race_tid';
  /* Relationship: Content: Data Sex (field_data_sex) */
  $handler->display->display_options['relationships']['field_data_sex_tid']['id'] = 'field_data_sex_tid';
  $handler->display->display_options['relationships']['field_data_sex_tid']['table'] = 'field_data_field_data_sex';
  $handler->display->display_options['relationships']['field_data_sex_tid']['field'] = 'field_data_sex_tid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Attachment */
  $handler->display->display_options['fields']['entity_id']['id'] = 'entity_id';
  $handler->display->display_options['fields']['entity_id']['table'] = 'field_data_field_document_attachment';
  $handler->display->display_options['fields']['entity_id']['field'] = 'field_document_attachment';
  $handler->display->display_options['fields']['entity_id']['label'] = '';
  $handler->display->display_options['fields']['entity_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['entity_id']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['entity_id']['settings'] = array(
    'style_settings' => array(
      'title' => array(
        'element' => 'div',
        'class' => 'field-label',
        'suffix' => ':',
      ),
      'content' => array(
        'element' => 'div',
        'class' => 'field-items',
      ),
      'item' => array(
        'element' => 'div',
        'class' => 'field-item',
      ),
      'wrapper' => array(
        'element' => 'div',
        'class' => '',
      ),
      'default_classes' => 1,
      'prefix_markup' => '',
      'item_limit' => '',
    ),
  );
  $handler->display->display_options['fields']['entity_id']['delta_offset'] = '0';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Document Terms (field_document_type) */
  $handler->display->display_options['arguments']['field_document_type_tid']['id'] = 'field_document_type_tid';
  $handler->display->display_options['arguments']['field_document_type_tid']['table'] = 'field_data_field_document_type';
  $handler->display->display_options['arguments']['field_document_type_tid']['field'] = 'field_document_type_tid';
  $handler->display->display_options['arguments']['field_document_type_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_document_type_tid']['summary']['format'] = 'default_summary';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'document' => 'document',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Document Collection (field_document_collection) */
  $handler->display->display_options['filters']['field_document_collection_tid']['id'] = 'field_document_collection_tid';
  $handler->display->display_options['filters']['field_document_collection_tid']['table'] = 'field_data_field_document_collection';
  $handler->display->display_options['filters']['field_document_collection_tid']['field'] = 'field_document_collection_tid';
  $handler->display->display_options['filters']['field_document_collection_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_document_collection_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_document_collection_tid']['expose']['operator_id'] = 'field_document_collection_tid_op';
  $handler->display->display_options['filters']['field_document_collection_tid']['expose']['label'] = 'Document Collection';
  $handler->display->display_options['filters']['field_document_collection_tid']['expose']['operator'] = 'field_document_collection_tid_op';
  $handler->display->display_options['filters']['field_document_collection_tid']['expose']['identifier'] = 'field_document_collection_tid';
  $handler->display->display_options['filters']['field_document_collection_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_document_collection_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_document_collection_tid']['vocabulary'] = 'document_collection';
  /* Filter criterion: Content: Data Topics (field_data_topic) */
  $handler->display->display_options['filters']['field_data_topic_tid']['id'] = 'field_data_topic_tid';
  $handler->display->display_options['filters']['field_data_topic_tid']['table'] = 'field_data_field_data_topic';
  $handler->display->display_options['filters']['field_data_topic_tid']['field'] = 'field_data_topic_tid';
  $handler->display->display_options['filters']['field_data_topic_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_data_topic_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_data_topic_tid']['expose']['operator_id'] = 'field_data_topic_tid_op';
  $handler->display->display_options['filters']['field_data_topic_tid']['expose']['label'] = 'Topic';
  $handler->display->display_options['filters']['field_data_topic_tid']['expose']['operator'] = 'field_data_topic_tid_op';
  $handler->display->display_options['filters']['field_data_topic_tid']['expose']['identifier'] = 'field_data_topic_tid';
  $handler->display->display_options['filters']['field_data_topic_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_data_topic_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_data_topic_tid']['vocabulary'] = 'data_topic';
  /* Filter criterion: Content: Data Type (field_data_type) */
  $handler->display->display_options['filters']['field_data_type_tid']['id'] = 'field_data_type_tid';
  $handler->display->display_options['filters']['field_data_type_tid']['table'] = 'field_data_field_data_type';
  $handler->display->display_options['filters']['field_data_type_tid']['field'] = 'field_data_type_tid';
  $handler->display->display_options['filters']['field_data_type_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_data_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_data_type_tid']['expose']['operator_id'] = 'field_data_type_tid_op';
  $handler->display->display_options['filters']['field_data_type_tid']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['field_data_type_tid']['expose']['operator'] = 'field_data_type_tid_op';
  $handler->display->display_options['filters']['field_data_type_tid']['expose']['identifier'] = 'field_data_type_tid';
  $handler->display->display_options['filters']['field_data_type_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_data_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_data_type_tid']['vocabulary'] = 'data_type';
  /* Filter criterion: Content: Data Sex (field_data_sex) */
  $handler->display->display_options['filters']['field_data_sex_tid']['id'] = 'field_data_sex_tid';
  $handler->display->display_options['filters']['field_data_sex_tid']['table'] = 'field_data_field_data_sex';
  $handler->display->display_options['filters']['field_data_sex_tid']['field'] = 'field_data_sex_tid';
  $handler->display->display_options['filters']['field_data_sex_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_data_sex_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_data_sex_tid']['expose']['operator_id'] = 'field_data_sex_tid_op';
  $handler->display->display_options['filters']['field_data_sex_tid']['expose']['label'] = 'Sex';
  $handler->display->display_options['filters']['field_data_sex_tid']['expose']['operator'] = 'field_data_sex_tid_op';
  $handler->display->display_options['filters']['field_data_sex_tid']['expose']['identifier'] = 'field_data_sex_tid';
  $handler->display->display_options['filters']['field_data_sex_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_data_sex_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_data_sex_tid']['vocabulary'] = 'data_sex';
  /* Filter criterion: Content: Data Race (field_data_race) */
  $handler->display->display_options['filters']['field_data_race_tid']['id'] = 'field_data_race_tid';
  $handler->display->display_options['filters']['field_data_race_tid']['table'] = 'field_data_field_data_race';
  $handler->display->display_options['filters']['field_data_race_tid']['field'] = 'field_data_race_tid';
  $handler->display->display_options['filters']['field_data_race_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_data_race_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_data_race_tid']['expose']['operator_id'] = 'field_data_race_tid_op';
  $handler->display->display_options['filters']['field_data_race_tid']['expose']['label'] = 'Race';
  $handler->display->display_options['filters']['field_data_race_tid']['expose']['operator'] = 'field_data_race_tid_op';
  $handler->display->display_options['filters']['field_data_race_tid']['expose']['identifier'] = 'field_data_race_tid';
  $handler->display->display_options['filters']['field_data_race_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_data_race_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_data_race_tid']['vocabulary'] = 'data_race';
  /* Filter criterion: Content: Data Year (field_data_year) */
  $handler->display->display_options['filters']['field_data_year_tid']['id'] = 'field_data_year_tid';
  $handler->display->display_options['filters']['field_data_year_tid']['table'] = 'field_data_field_data_year';
  $handler->display->display_options['filters']['field_data_year_tid']['field'] = 'field_data_year_tid';
  $handler->display->display_options['filters']['field_data_year_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_data_year_tid']['expose']['operator_id'] = 'field_data_year_tid_op';
  $handler->display->display_options['filters']['field_data_year_tid']['expose']['label'] = 'Year';
  $handler->display->display_options['filters']['field_data_year_tid']['expose']['operator'] = 'field_data_year_tid_op';
  $handler->display->display_options['filters']['field_data_year_tid']['expose']['identifier'] = 'field_data_year_tid';
  $handler->display->display_options['filters']['field_data_year_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_data_year_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_data_year_tid']['vocabulary'] = 'data_year';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['path'] = 'facts-figures/statistics';
  $handler->display->display_options['menu']['title'] = 'Documents';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['style_options']['uses_fields'] = TRUE;
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['path'] = 'documents/feed';
  $handler->display->display_options['displays'] = array(
    'page_1' => 'page_1',
    'default' => 0,
  );
  $translatables['osbm_documents'] = array(
    t('Defaults'),
    t('Statistics'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('File'),
    t('term from field_data_year'),
    t('term from field_data_race'),
    t('term from field_data_sex'),
    t('All'),
    t('Document Collection'),
    t('Topic'),
    t('Type'),
    t('Sex'),
    t('Race'),
    t('Year'),
    t('Page'),
    t('Feed'),
  );
  $export['osbm_documents'] = $view;

  return $export;
}
