<?php
/**
 * @file
 * nc_tax_type.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function nc_tax_type_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'tax_search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Tax Search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Tax Search';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'input_required';
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'full_html';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'entry';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Last updated */
  $handler->display->display_options['fields']['field_revised_date']['id'] = 'field_revised_date';
  $handler->display->display_options['fields']['field_revised_date']['table'] = 'field_data_field_revised_date';
  $handler->display->display_options['fields']['field_revised_date']['field'] = 'field_revised_date';
  $handler->display->display_options['fields']['field_revised_date']['label'] = '';
  $handler->display->display_options['fields']['field_revised_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_revised_date']['type'] = 'nc_fields_date_formatter';
  $handler->display->display_options['fields']['field_revised_date']['settings'] = array(
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
        'element' => 'time',
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
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['settings'] = array(
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
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'tax_type' => 'tax_type',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Tax Type';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    8 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    6 => 0,
  );
  /* Filter criterion: Content: Tax Category (field_tax_category) */
  $handler->display->display_options['filters']['field_tax_category_tid']['id'] = 'field_tax_category_tid';
  $handler->display->display_options['filters']['field_tax_category_tid']['table'] = 'field_data_field_tax_category';
  $handler->display->display_options['filters']['field_tax_category_tid']['field'] = 'field_tax_category_tid';
  $handler->display->display_options['filters']['field_tax_category_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_tax_category_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_tax_category_tid']['expose']['operator_id'] = 'field_tax_category_tid_op';
  $handler->display->display_options['filters']['field_tax_category_tid']['expose']['label'] = 'Tax Category';
  $handler->display->display_options['filters']['field_tax_category_tid']['expose']['operator'] = 'field_tax_category_tid_op';
  $handler->display->display_options['filters']['field_tax_category_tid']['expose']['identifier'] = 'field_tax_category_tid';
  $handler->display->display_options['filters']['field_tax_category_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    8 => 0,
    4 => 0,
    5 => 0,
    7 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['field_tax_category_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_tax_category_tid']['vocabulary'] = 'tax_category';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'results';
  $handler->display->display_options['path'] = 'file-and-pay/file-and-pay-search-results';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'File & Pay Search Results';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Block */
  $handler = $view->new_display('page', 'Block', 'page_1');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'file-and-pay/file-and-pay-search-results';
  $translatables['tax_search'] = array(
    t('Master'),
    t('Tax Search'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Select any filter and click on Apply to see results'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Tax Type'),
    t('Tax Category'),
    t('Page'),
    t('Block'),
  );
  $export['tax_search'] = $view;

  return $export;
}
