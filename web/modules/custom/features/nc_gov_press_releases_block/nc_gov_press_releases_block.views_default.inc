<?php
/**
 * @file
 * nc_gov_press_releases_block.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function nc_gov_press_releases_block_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'nc_gov_press_releases_block';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'aggregator_item';
  $view->human_name = 'NC Gov Press Releases Block';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Press Releases';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Aggregator: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'aggregator_item';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title']['display_as_link'] = FALSE;
  /* Field: Aggregator: Timestamp */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'aggregator_item';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['element_type'] = '0';
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'custom';
  $handler->display->display_options['fields']['timestamp']['custom_date_format'] = 'M j';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'nc_event_calendar_day';
  /* Field: Aggregator: Link */
  $handler->display->display_options['fields']['link']['id'] = 'link';
  $handler->display->display_options['fields']['link']['table'] = 'aggregator_item';
  $handler->display->display_options['fields']['link']['field'] = 'link';
  $handler->display->display_options['fields']['link']['label'] = '';
  $handler->display->display_options['fields']['link']['element_type'] = '0';
  $handler->display->display_options['fields']['link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['link']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['link']['display_as_link'] = FALSE;
  /* Sort criterion: Aggregator: Timestamp */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'aggregator_item';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';

  /* Display: Press Releases - Block */
  $handler = $view->new_display('block', 'Press Releases - Block', 'block');
  $handler->display->display_options['display_description'] = 'Press Releases block created using the aggregator';
  $handler->display->display_options['block_description'] = 'NC Gov Press Releases Block';
  $translatables['nc_gov_press_releases_block'] = array(
    t('Master'),
    t('Press Releases'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Press Releases - Block'),
    t('Press Releases block created using the aggregator'),
    t('NC Gov Press Releases Block'),
  );
  $export['nc_gov_press_releases_block'] = $view;

  return $export;
}
