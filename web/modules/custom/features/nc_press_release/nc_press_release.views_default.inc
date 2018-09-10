<?php
/**
 * @file
 * nc_press_release.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function nc_press_release_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'single_press_release_blocks';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Single Press Release Blocks';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Press Release Contact Information';
  $handler->display->display_options['css_class'] = 'quick-links';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_contact_email' => 'field_contact_email',
    'field_contact_name' => 'field_contact_name',
    'field_contact_phone' => 'field_contact_phone',
  );
  $handler->display->display_options['row_options']['separator'] = '<br/>';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Field: Content: Contact Name */
  $handler->display->display_options['fields']['field_contact_name']['id'] = 'field_contact_name';
  $handler->display->display_options['fields']['field_contact_name']['table'] = 'field_data_field_contact_name';
  $handler->display->display_options['fields']['field_contact_name']['field'] = 'field_contact_name';
  $handler->display->display_options['fields']['field_contact_name']['label'] = '';
  $handler->display->display_options['fields']['field_contact_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_contact_name']['settings'] = array(
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
  /* Field: Content: Contact Email */
  $handler->display->display_options['fields']['field_contact_email']['id'] = 'field_contact_email';
  $handler->display->display_options['fields']['field_contact_email']['table'] = 'field_data_field_contact_email';
  $handler->display->display_options['fields']['field_contact_email']['field'] = 'field_contact_email';
  $handler->display->display_options['fields']['field_contact_email']['label'] = '';
  $handler->display->display_options['fields']['field_contact_email']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_contact_email']['settings'] = array(
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
  /* Field: Content: Contact Phone */
  $handler->display->display_options['fields']['field_contact_phone']['id'] = 'field_contact_phone';
  $handler->display->display_options['fields']['field_contact_phone']['table'] = 'field_data_field_contact_phone';
  $handler->display->display_options['fields']['field_contact_phone']['field'] = 'field_contact_phone';
  $handler->display->display_options['fields']['field_contact_phone']['label'] = '';
  $handler->display->display_options['fields']['field_contact_phone']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_contact_phone']['settings'] = array(
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
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
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
    'press_release' => 'press_release',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Contact Email (field_contact_email) */
  $handler->display->display_options['filters']['field_contact_email_email']['id'] = 'field_contact_email_email';
  $handler->display->display_options['filters']['field_contact_email_email']['table'] = 'field_data_field_contact_email';
  $handler->display->display_options['filters']['field_contact_email_email']['field'] = 'field_contact_email_email';
  $handler->display->display_options['filters']['field_contact_email_email']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_contact_email_email']['group'] = 2;
  /* Filter criterion: Content: Contact Name (field_contact_name) */
  $handler->display->display_options['filters']['field_contact_name_value']['id'] = 'field_contact_name_value';
  $handler->display->display_options['filters']['field_contact_name_value']['table'] = 'field_data_field_contact_name';
  $handler->display->display_options['filters']['field_contact_name_value']['field'] = 'field_contact_name_value';
  $handler->display->display_options['filters']['field_contact_name_value']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_contact_name_value']['group'] = 2;
  /* Filter criterion: Content: Contact Phone (field_contact_phone) */
  $handler->display->display_options['filters']['field_contact_phone_value']['id'] = 'field_contact_phone_value';
  $handler->display->display_options['filters']['field_contact_phone_value']['table'] = 'field_data_field_contact_phone';
  $handler->display->display_options['filters']['field_contact_phone_value']['field'] = 'field_contact_phone_value';
  $handler->display->display_options['filters']['field_contact_phone_value']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_contact_phone_value']['group'] = 2;

  /* Display: Press Release Contact Information */
  $handler = $view->new_display('block', 'Press Release Contact Information', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Contact Information';
  $handler->display->display_options['display_description'] = 'Press Release Contact Information';
  $handler->display->display_options['block_description'] = 'Contact Information';
  $handler->display->display_options['block_caching'] = '4';
  $translatables['single_press_release_blocks'] = array(
    t('Master'),
    t('Press Release Contact Information'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('All'),
    t('Contact Information'),
  );
  $export['single_press_release_blocks'] = $view;

  return $export;
}
