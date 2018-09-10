<?php
/**
 * @file
 * nc_document.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function nc_document_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'nc_documents';
  $view->description = 'Creates a list page of documents with links to detail pages as well as downloads.';
  $view->tag = 'OpenPublic';
  $view->base_table = 'node';
  $view->human_name = 'NC Documents';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Documents';
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
  /* Field: Content: Attachment */
  $handler->display->display_options['fields']['entity_id']['id'] = 'entity_id';
  $handler->display->display_options['fields']['entity_id']['table'] = 'field_data_field_document_attachment';
  $handler->display->display_options['fields']['entity_id']['field'] = 'field_document_attachment';
  $handler->display->display_options['fields']['entity_id']['label'] = '';
  $handler->display->display_options['fields']['entity_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['entity_id']['click_sort_column'] = 'fid';
  /* Field: File: Size */
  $handler->display->display_options['fields']['filesize']['id'] = 'filesize';
  $handler->display->display_options['fields']['filesize']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filesize']['field'] = 'filesize';
  $handler->display->display_options['fields']['filesize']['relationship'] = 'node_to_file';
  $handler->display->display_options['fields']['filesize']['label'] = '';
  $handler->display->display_options['fields']['filesize']['exclude'] = TRUE;
  /* Field: File: Path */
  $handler->display->display_options['fields']['uri_1']['id'] = 'uri_1';
  $handler->display->display_options['fields']['uri_1']['table'] = 'file_managed';
  $handler->display->display_options['fields']['uri_1']['field'] = 'uri';
  $handler->display->display_options['fields']['uri_1']['relationship'] = 'node_to_file';
  $handler->display->display_options['fields']['uri_1']['label'] = '';
  $handler->display->display_options['fields']['uri_1']['exclude'] = TRUE;
  /* Field: File: Path */
  $handler->display->display_options['fields']['uri']['id'] = 'uri';
  $handler->display->display_options['fields']['uri']['table'] = 'file_managed';
  $handler->display->display_options['fields']['uri']['field'] = 'uri';
  $handler->display->display_options['fields']['uri']['relationship'] = 'node_to_file';
  $handler->display->display_options['fields']['uri']['label'] = '';
  $handler->display->display_options['fields']['uri']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['uri']['alter']['text'] = '<div class="download-link"><a href="[uri]">Download</a></div><div class="download-info"><span class="download-type">[uri_1]</span> : <span class="download-filesize">[filesize]</span></div>';
  $handler->display->display_options['fields']['uri']['file_download_path'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['entity_id_2']['id'] = 'entity_id_2';
  $handler->display->display_options['fields']['entity_id_2']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['entity_id_2']['field'] = 'body';
  $handler->display->display_options['fields']['entity_id_2']['label'] = '';
  $handler->display->display_options['fields']['entity_id_2']['click_sort_column'] = 'summary';
  $handler->display->display_options['fields']['entity_id_2']['type'] = 'text_summary_or_trimmed';
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
  /* Filter criterion: Content: Agency/Department (field_agency_department) */
  $handler->display->display_options['filters']['field_agency_department_tid']['id'] = 'field_agency_department_tid';
  $handler->display->display_options['filters']['field_agency_department_tid']['table'] = 'field_data_field_agency_department';
  $handler->display->display_options['filters']['field_agency_department_tid']['field'] = 'field_agency_department_tid';
  $handler->display->display_options['filters']['field_agency_department_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_agency_department_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_agency_department_tid']['expose']['operator_id'] = 'field_agency_department_tid_op';
  $handler->display->display_options['filters']['field_agency_department_tid']['expose']['label'] = 'Agency/Department';
  $handler->display->display_options['filters']['field_agency_department_tid']['expose']['operator'] = 'field_agency_department_tid_op';
  $handler->display->display_options['filters']['field_agency_department_tid']['expose']['identifier'] = 'field_agency_department_tid';
  $handler->display->display_options['filters']['field_agency_department_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_agency_department_tid']['group_info']['label'] = 'Agency/Department (field_agency_department)';
  $handler->display->display_options['filters']['field_agency_department_tid']['group_info']['identifier'] = 'field_agency_department_tid';
  $handler->display->display_options['filters']['field_agency_department_tid']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_agency_department_tid']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  $handler->display->display_options['filters']['field_agency_department_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_agency_department_tid']['vocabulary'] = 'nc_agency_department';
  /* Filter criterion: Content: Document Terms (field_document_type) */
  $handler->display->display_options['filters']['field_document_type_tid']['id'] = 'field_document_type_tid';
  $handler->display->display_options['filters']['field_document_type_tid']['table'] = 'field_data_field_document_type';
  $handler->display->display_options['filters']['field_document_type_tid']['field'] = 'field_document_type_tid';
  $handler->display->display_options['filters']['field_document_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_document_type_tid']['expose']['operator_id'] = 'field_document_type_tid_op';
  $handler->display->display_options['filters']['field_document_type_tid']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['field_document_type_tid']['expose']['operator'] = 'field_document_type_tid_op';
  $handler->display->display_options['filters']['field_document_type_tid']['expose']['identifier'] = 'field_document_type_tid';
  $handler->display->display_options['filters']['field_document_type_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    4 => 0,
    3 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['field_document_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_document_type_tid']['vocabulary'] = 'document_terms';
  $handler->display->display_options['filters']['field_document_type_tid']['hierarchy'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['entity_id_2']['id'] = 'entity_id_2';
  $handler->display->display_options['fields']['entity_id_2']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['entity_id_2']['field'] = 'body';
  $handler->display->display_options['fields']['entity_id_2']['label'] = '';
  $handler->display->display_options['fields']['entity_id_2']['click_sort_column'] = 'summary';
  $handler->display->display_options['fields']['entity_id_2']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Global: Populate filters */
  $handler->display->display_options['filters']['populate']['id'] = 'populate';
  $handler->display->display_options['filters']['populate']['table'] = 'views_filters_populate';
  $handler->display->display_options['filters']['populate']['field'] = 'populate';
  $handler->display->display_options['filters']['populate']['group'] = 2;
  $handler->display->display_options['filters']['populate']['exposed'] = TRUE;
  $handler->display->display_options['filters']['populate']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['populate']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['populate']['expose']['operator'] = 'populate_op';
  $handler->display->display_options['filters']['populate']['expose']['identifier'] = 'populate';
  $handler->display->display_options['filters']['populate']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['populate']['filters'] = array(
    'combine' => 'combine',
    'field_document_attachment_description' => 'field_document_attachment_description',
    'status' => 0,
    'type' => 0,
    'field_agency_department_tid' => 0,
    'field_document_collection_tid' => 0,
  );
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
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Agency/Department (field_agency_department) */
  $handler->display->display_options['filters']['field_agency_department_tid']['id'] = 'field_agency_department_tid';
  $handler->display->display_options['filters']['field_agency_department_tid']['table'] = 'field_data_field_agency_department';
  $handler->display->display_options['filters']['field_agency_department_tid']['field'] = 'field_agency_department_tid';
  $handler->display->display_options['filters']['field_agency_department_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_agency_department_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_agency_department_tid']['expose']['operator_id'] = 'field_agency_department_tid_op';
  $handler->display->display_options['filters']['field_agency_department_tid']['expose']['label'] = 'Divisions';
  $handler->display->display_options['filters']['field_agency_department_tid']['expose']['operator'] = 'field_agency_department_tid_op';
  $handler->display->display_options['filters']['field_agency_department_tid']['expose']['identifier'] = 'field_agency_department_tid';
  $handler->display->display_options['filters']['field_agency_department_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['field_agency_department_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_agency_department_tid']['vocabulary'] = 'nc_agency_department';
  $handler->display->display_options['filters']['field_agency_department_tid']['hierarchy'] = 1;
  /* Filter criterion: Type */
  $handler->display->display_options['filters']['field_document_collection_tid']['id'] = 'field_document_collection_tid';
  $handler->display->display_options['filters']['field_document_collection_tid']['table'] = 'field_data_field_document_collection';
  $handler->display->display_options['filters']['field_document_collection_tid']['field'] = 'field_document_collection_tid';
  $handler->display->display_options['filters']['field_document_collection_tid']['ui_name'] = 'Type';
  $handler->display->display_options['filters']['field_document_collection_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_document_collection_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_document_collection_tid']['expose']['operator_id'] = 'field_document_collection_tid_op';
  $handler->display->display_options['filters']['field_document_collection_tid']['expose']['label'] = 'Type';
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
  $handler->display->display_options['filters']['field_document_collection_tid']['hierarchy'] = 1;
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 2;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['combine']['group_info']['label'] = 'Combine fields filter';
  $handler->display->display_options['filters']['combine']['group_info']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['combine']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'entity_id_2' => 'entity_id_2',
  );
  /* Filter criterion: Content: Attachment (field_document_attachment:description) */
  $handler->display->display_options['filters']['field_document_attachment_description']['id'] = 'field_document_attachment_description';
  $handler->display->display_options['filters']['field_document_attachment_description']['table'] = 'field_data_field_document_attachment';
  $handler->display->display_options['filters']['field_document_attachment_description']['field'] = 'field_document_attachment_description';
  $handler->display->display_options['filters']['field_document_attachment_description']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_document_attachment_description']['group'] = 2;
  $handler->display->display_options['filters']['field_document_attachment_description']['expose']['operator_id'] = 'field_document_attachment_description_op';
  $handler->display->display_options['filters']['field_document_attachment_description']['expose']['label'] = 'Attachment (field_document_attachment:description)';
  $handler->display->display_options['filters']['field_document_attachment_description']['expose']['operator'] = 'field_document_attachment_description_op';
  $handler->display->display_options['filters']['field_document_attachment_description']['expose']['identifier'] = 'field_document_attachment_description';
  /* Filter criterion: Content: Document Terms (field_document_type) */
  $handler->display->display_options['filters']['field_document_type_tid']['id'] = 'field_document_type_tid';
  $handler->display->display_options['filters']['field_document_type_tid']['table'] = 'field_data_field_document_type';
  $handler->display->display_options['filters']['field_document_type_tid']['field'] = 'field_document_type_tid';
  $handler->display->display_options['filters']['field_document_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_document_type_tid']['expose']['operator_id'] = 'field_document_type_tid_op';
  $handler->display->display_options['filters']['field_document_type_tid']['expose']['label'] = 'Terms';
  $handler->display->display_options['filters']['field_document_type_tid']['expose']['operator'] = 'field_document_type_tid_op';
  $handler->display->display_options['filters']['field_document_type_tid']['expose']['identifier'] = 'field_document_type_tid';
  $handler->display->display_options['filters']['field_document_type_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['field_document_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_document_type_tid']['vocabulary'] = 'document_terms';
  $handler->display->display_options['path'] = 'documents';
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
  $translatables['nc_documents'] = array(
    t('Defaults'),
    t('Documents'),
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
    t('<div class="download-link"><a href="[uri]">Download</a></div><div class="download-info"><span class="download-type">[uri_1]</span> : <span class="download-filesize">[filesize]</span></div>'),
    t('All'),
    t('Agency/Department'),
    t('Agency/Department (field_agency_department)'),
    t('Type'),
    t('Page'),
    t('Search'),
    t('Divisions'),
    t('Combine fields filter'),
    t('Attachment (field_document_attachment:description)'),
    t('Terms'),
    t('Feed'),
  );
  $export['nc_documents'] = $view;

  return $export;
}
