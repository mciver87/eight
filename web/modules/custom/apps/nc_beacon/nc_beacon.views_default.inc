<?php
/**
 * @file
 * nc_beacon.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function nc_beacon_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'empdir';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'nc_beacon';
  $view->human_name = 'Employee Directory (BEACON)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Employee Directory';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'NameLast' => 'NameLast',
    'NameFirst' => 'NameFirst',
    'NameMiddle' => 'NameMiddle',
    'nothing' => 'nothing',
    'Phone' => 'Phone',
    'PhoneExt' => 'PhoneExt',
    'nothing_1' => 'nothing_1',
    'Email' => 'Email',
  );
  $handler->display->display_options['style_options']['default'] = 'NameLast';
  $handler->display->display_options['style_options']['info'] = array(
    'NameLast' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'NameFirst' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'NameMiddle' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'Phone' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'PhoneExt' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'Email' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<p><a href="/how-update-data-employee-directory">How to Update Data in the Employee Directory</a><p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  /* Field: North Carolina BEACON: pkEmployee */
  $handler->display->display_options['fields']['pkEmployee']['id'] = 'pkEmployee';
  $handler->display->display_options['fields']['pkEmployee']['table'] = 'nc_beacon';
  $handler->display->display_options['fields']['pkEmployee']['field'] = 'pkEmployee';
  $handler->display->display_options['fields']['pkEmployee']['exclude'] = TRUE;
  /* Field: North Carolina BEACON: NameLast */
  $handler->display->display_options['fields']['NameLast']['id'] = 'NameLast';
  $handler->display->display_options['fields']['NameLast']['table'] = 'nc_beacon';
  $handler->display->display_options['fields']['NameLast']['field'] = 'NameLast';
  $handler->display->display_options['fields']['NameLast']['label'] = 'Last Name';
  $handler->display->display_options['fields']['NameLast']['exclude'] = TRUE;
  /* Field: North Carolina BEACON: NameFirst */
  $handler->display->display_options['fields']['NameFirst']['id'] = 'NameFirst';
  $handler->display->display_options['fields']['NameFirst']['table'] = 'nc_beacon';
  $handler->display->display_options['fields']['NameFirst']['field'] = 'NameFirst';
  $handler->display->display_options['fields']['NameFirst']['label'] = 'First Name';
  $handler->display->display_options['fields']['NameFirst']['exclude'] = TRUE;
  /* Field: North Carolina BEACON: NameMiddle */
  $handler->display->display_options['fields']['NameMiddle']['id'] = 'NameMiddle';
  $handler->display->display_options['fields']['NameMiddle']['table'] = 'nc_beacon';
  $handler->display->display_options['fields']['NameMiddle']['field'] = 'NameMiddle';
  $handler->display->display_options['fields']['NameMiddle']['label'] = 'Middle Name';
  $handler->display->display_options['fields']['NameMiddle']['exclude'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Name';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[NameLast], [NameFirst] [NameMiddle]';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'employee/[pkEmployee]';
  /* Field: North Carolina BEACON: Phone */
  $handler->display->display_options['fields']['Phone']['id'] = 'Phone';
  $handler->display->display_options['fields']['Phone']['table'] = 'nc_beacon';
  $handler->display->display_options['fields']['Phone']['field'] = 'Phone';
  $handler->display->display_options['fields']['Phone']['exclude'] = TRUE;
  /* Field: North Carolina BEACON: PhoneExt */
  $handler->display->display_options['fields']['PhoneExt']['id'] = 'PhoneExt';
  $handler->display->display_options['fields']['PhoneExt']['table'] = 'nc_beacon';
  $handler->display->display_options['fields']['PhoneExt']['field'] = 'PhoneExt';
  $handler->display->display_options['fields']['PhoneExt']['label'] = 'Ext';
  $handler->display->display_options['fields']['PhoneExt']['exclude'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Phone';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[Phone] [PhoneExt]';
  /* Field: North Carolina BEACON: Email */
  $handler->display->display_options['fields']['Email']['id'] = 'Email';
  $handler->display->display_options['fields']['Email']['table'] = 'nc_beacon';
  $handler->display->display_options['fields']['Email']['field'] = 'Email';
  /* Filter criterion: North Carolina BEACON: NameFirst */
  $handler->display->display_options['filters']['NameFirst']['id'] = 'NameFirst';
  $handler->display->display_options['filters']['NameFirst']['table'] = 'nc_beacon';
  $handler->display->display_options['filters']['NameFirst']['field'] = 'NameFirst';
  $handler->display->display_options['filters']['NameFirst']['exposed'] = TRUE;
  $handler->display->display_options['filters']['NameFirst']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['NameFirst']['expose']['label'] = 'First / Middle Name';
  $handler->display->display_options['filters']['NameFirst']['expose']['operator'] = 'NameFirst_op';
  $handler->display->display_options['filters']['NameFirst']['expose']['identifier'] = 'NameFirst';
  $handler->display->display_options['filters']['NameFirst']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  /* Filter criterion: North Carolina BEACON: NameLast */
  $handler->display->display_options['filters']['NameLast']['id'] = 'NameLast';
  $handler->display->display_options['filters']['NameLast']['table'] = 'nc_beacon';
  $handler->display->display_options['filters']['NameLast']['field'] = 'NameLast';
  $handler->display->display_options['filters']['NameLast']['exposed'] = TRUE;
  $handler->display->display_options['filters']['NameLast']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['NameLast']['expose']['label'] = 'Last Name';
  $handler->display->display_options['filters']['NameLast']['expose']['operator'] = 'NameLast_op';
  $handler->display->display_options['filters']['NameLast']['expose']['identifier'] = 'NameLast';
  $handler->display->display_options['filters']['NameLast']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  /* Filter criterion: North Carolina BEACON: Agency */
  $handler->display->display_options['filters']['Agency']['id'] = 'Agency';
  $handler->display->display_options['filters']['Agency']['table'] = 'nc_beacon';
  $handler->display->display_options['filters']['Agency']['field'] = 'Agency';
  $handler->display->display_options['filters']['Agency']['exposed'] = TRUE;
  $handler->display->display_options['filters']['Agency']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['Agency']['expose']['label'] = 'Agency';
  $handler->display->display_options['filters']['Agency']['expose']['operator'] = 'Agency_op';
  $handler->display->display_options['filters']['Agency']['expose']['identifier'] = 'Agency';
  $handler->display->display_options['filters']['Agency']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );

  /* Display: Page - Full Search */
  $handler = $view->new_display('page', 'Page - Full Search', 'empdir_full_page');
  $handler->display->display_options['display_description'] = 'Provides a full search page for the BEACON employee directory, with first/middle, last, and agency exposed filters.';
  $handler->display->display_options['path'] = 'employee-directory';
  $translatables['empdir'] = array(
    t('Master'),
    t('Employee Directory'),
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
    t('<p><a href="/how-update-data-employee-directory">How to Update Data in the Employee Directory</a><p>'),
    t('Displaying @start - @end of @total'),
    t('pkEmployee'),
    t('Last Name'),
    t('First Name'),
    t('Middle Name'),
    t('Name'),
    t('[NameLast], [NameFirst] [NameMiddle]'),
    t('Phone'),
    t('Ext'),
    t('[Phone] [PhoneExt]'),
    t('Email'),
    t('First / Middle Name'),
    t('Agency'),
    t('Page - Full Search'),
    t('Provides a full search page for the BEACON employee directory, with first/middle, last, and agency exposed filters.'),
  );
  $export['empdir'] = $view;

  return $export;
}
