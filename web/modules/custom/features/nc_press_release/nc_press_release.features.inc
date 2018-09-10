<?php
/**
 * @file
 * nc_press_release.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nc_press_release_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function nc_press_release_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_context_default_contexts_alter().
 */
function nc_press_release_context_default_contexts_alter(&$data) {
  if (isset($data['nav_press_release'])) {
    $data['nav_press_release']->hidden = 0; /* WAS: '' */
    $data['nav_press_release']->reactions['theme'] = array(
      'title' => '',
      'subtitle' => '',
    ); /* WAS: '' */
    $data['nav_press_release']->reactions['theme_html'] = array(
      'class' => '',
    ); /* WAS: '' */
  }
}

/**
 * Implements hook_field_default_field_bases_alter().
 */
function nc_press_release_field_default_field_bases_alter(&$data) {
  if (isset($data['field_agency_department'])) {
    $data['field_agency_department']['cardinality'] = -1; /* WAS: 1 */
  }
  if (isset($data['field_release_date'])) {
    unset($data['field_release_date']['foreign keys']);
  }
}

/**
 * Implements hook_field_default_field_instances_alter().
 */
function nc_press_release_field_default_field_instances_alter(&$data) {
  if (isset($data['node-press_release-body'])) {
    $data['node-press_release-body']['display']['basic_card'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-press_release-body']['display']['block_feature'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-press_release-body']['display']['default']['settings']['style_settings'] = array(
      'content' => array(
        'class' => 'field-items',
        'element' => 'div',
      ),
      'default_classes' => TRUE,
      'item' => array(
        'class' => 'field-item',
        'element' => 'div',
      ),
      'item_limit' => '',
      'prefix_markup' => '',
      'title' => array(
        'class' => 'field-label',
        'element' => 'div',
        'suffix' => ':',
      ),
      'wrapper' => array(
        'class' => '',
        'element' => 'div',
      ),
    ); /* WAS: '' */
    $data['node-press_release-body']['display']['default']['weight'] = 13; /* WAS: 2 */
    $data['node-press_release-body']['display']['rss']['settings']['field_formatter_class'] = ''; /* WAS: '' */
    $data['node-press_release-body']['display']['rss']['settings']['style_settings'] = array(
      'content' => array(
        'class' => 'field-items',
        'element' => 'div',
      ),
      'default_classes' => TRUE,
      'item' => array(
        'class' => 'field-item',
        'element' => 'div',
      ),
      'item_limit' => '',
      'prefix_markup' => '',
      'title' => array(
        'class' => 'field-label',
        'element' => 'div',
        'suffix' => ':',
      ),
      'wrapper' => array(
        'class' => '',
        'element' => 'div',
      ),
    ); /* WAS: '' */
    $data['node-press_release-body']['display']['teaser']['settings']['style_settings'] = array(
      'content' => array(
        'class' => 'field-items',
        'element' => 'div',
      ),
      'default_classes' => 1,
      'item' => array(
        'class' => 'field-item',
        'element' => 'div',
      ),
      'item_limit' => '',
      'prefix_markup' => '',
      'title' => array(
        'class' => 'field-label',
        'element' => 'div',
        'suffix' => ':',
      ),
      'wrapper' => array(
        'class' => '',
        'element' => 'div',
      ),
    ); /* WAS: '' */
    $data['node-press_release-body']['display']['teaser']['settings']['trim_length'] = 200; /* WAS: 600 */
    $data['node-press_release-body']['display']['teaser']['weight'] = 1; /* WAS: 0 */
    $data['node-press_release-body']['widget']['weight'] = 6; /* WAS: 4 */
  }
  if (isset($data['node-press_release-field_files'])) {
    $data['node-press_release-field_files']['display']['basic_card'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-press_release-field_files']['display']['block_feature'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-press_release-field_files']['display']['default']['module'] = 'nc_fields'; /* WAS: 'file' */
    $data['node-press_release-field_files']['display']['default']['settings']['style_settings'] = array(
      'content' => array(
        'class' => 'field-items',
        'element' => 'div',
      ),
      'default_classes' => TRUE,
      'item' => array(
        'class' => 'field-item',
        'element' => 'div',
      ),
      'item_limit' => '',
      'prefix_markup' => '',
      'title' => array(
        'class' => 'field-label',
        'element' => 'div',
        'suffix' => ':',
      ),
      'wrapper' => array(
        'class' => '',
        'element' => 'div',
      ),
    ); /* WAS: '' */
    $data['node-press_release-field_files']['display']['default']['type'] = 'nc_fields_file_formatter_detail'; /* WAS: 'file_default' */
    $data['node-press_release-field_files']['widget']['settings']['imce_filefield_on'] = 1; /* WAS: '' */
    $data['node-press_release-field_files']['widget']['weight'] = 8; /* WAS: 6 */
  }
  if (isset($data['node-press_release-field_related_content'])) {
    $data['node-press_release-field_related_content']['display']['basic_card'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-press_release-field_related_content']['display']['block_feature'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-press_release-field_related_content']['display']['default']['settings']['style_settings'] = array(
      'content' => array(
        'class' => 'field-items',
        'element' => 'div',
      ),
      'default_classes' => TRUE,
      'item' => array(
        'class' => 'field-item',
        'element' => 'div',
      ),
      'item_limit' => '',
      'prefix_markup' => '',
      'title' => array(
        'class' => 'field-label',
        'element' => 'div',
        'suffix' => ':',
      ),
      'wrapper' => array(
        'class' => '',
        'element' => 'div',
      ),
    ); /* WAS: '' */
    $data['node-press_release-field_related_content']['display']['default']['weight'] = 3; /* WAS: 4 */
    $data['node-press_release-field_related_content']['settings']['validate_url'] = 0; /* WAS: 1 */
    $data['node-press_release-field_related_content']['widget']['settings']['validate_url'] = 0; /* WAS: '' */
  }
  if (isset($data['node-press_release-field_release_date'])) {
    $data['node-press_release-field_release_date']['display']['basic_card'] = array(
      'label' => 'hidden',
      'module' => 'date',
      'settings' => array(
        'style_settings' => array(
          'content' => array(
            'class' => 'field-items',
            'element' => 'div',
          ),
          'default_classes' => TRUE,
          'item' => array(
            'class' => 'field-item',
            'element' => 'div',
          ),
          'item_limit' => '',
          'prefix_markup' => '',
          'title' => array(
            'class' => 'field-label',
            'element' => 'div',
            'suffix' => ':',
          ),
          'wrapper' => array(
            'class' => '',
            'element' => 'div',
          ),
        ),
      ),
      'type' => 'date_plain',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-press_release-field_release_date']['display']['block_feature'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-press_release-field_release_date']['display']['default']['module'] = 'nc_fields'; /* WAS: 'date' */
    $data['node-press_release-field_release_date']['display']['default']['settings']['style_settings'] = array(
      'content' => array(
        'class' => 'field-items',
        'element' => 'div',
      ),
      'default_classes' => TRUE,
      'item' => array(
        'class' => 'field-item',
        'element' => 'div',
      ),
      'item_limit' => '',
      'prefix_markup' => '',
      'title' => array(
        'class' => 'field-label',
        'element' => 'div',
        'suffix' => ':',
      ),
      'wrapper' => array(
        'class' => '',
        'element' => 'div',
      ),
    ); /* WAS: '' */
    $data['node-press_release-field_release_date']['display']['default']['type'] = 'nc_fields_date_formatter'; /* WAS: 'date_default' */
    $data['node-press_release-field_release_date']['display']['default']['weight'] = 11; /* WAS: 0 */
    $data['node-press_release-field_release_date']['display']['teaser']['label'] = 'hidden'; /* WAS: 'above' */
    $data['node-press_release-field_release_date']['display']['teaser']['module'] = 'date'; /* WAS: '' */
    $data['node-press_release-field_release_date']['display']['teaser']['settings']['format_type'] = 'nc_event_calendar_day'; /* WAS: '' */
    $data['node-press_release-field_release_date']['display']['teaser']['settings']['fromto'] = 'both'; /* WAS: '' */
    $data['node-press_release-field_release_date']['display']['teaser']['settings']['multiple_from'] = ''; /* WAS: '' */
    $data['node-press_release-field_release_date']['display']['teaser']['settings']['multiple_number'] = ''; /* WAS: '' */
    $data['node-press_release-field_release_date']['display']['teaser']['settings']['multiple_to'] = ''; /* WAS: '' */
    $data['node-press_release-field_release_date']['display']['teaser']['settings']['style_settings'] = array(
      'content' => array(
        'class' => 'field-items',
        'element' => 'div',
      ),
      'default_classes' => 0,
      'item' => array(
        'class' => 'field-item',
        'element' => 'div',
      ),
      'item_limit' => '',
      'prefix_markup' => '',
      'title' => array(
        'class' => 'field-label',
        'element' => 'div',
        'suffix' => ':',
      ),
      'wrapper' => array(
        'class' => '',
        'element' => 'div',
      ),
    ); /* WAS: '' */
    $data['node-press_release-field_release_date']['display']['teaser']['type'] = 'date_default'; /* WAS: 'hidden' */
    $data['node-press_release-field_release_date']['widget']['weight'] = 3; /* WAS: 1 */
    unset($data['node-press_release-field_release_date']['display']['default']['settings']['show_repeat_rule']);
    unset($data['node-press_release-field_release_date']['widget']['settings']['repeat_collapsed']);
  }
}

/**
 * Implements hook_strongarm_alter().
 */
function nc_press_release_strongarm_alter(&$data) {
  if (isset($data['field_bundle_settings_node__press_release'])) {
    $data['field_bundle_settings_node__press_release']->value['extra_fields']['display']['language'] = array(
      'default' => array(
        'weight' => 5,
        'visible' => FALSE,
      ),
      'teaser' => array(
        'weight' => 3,
        'visible' => FALSE,
      ),
      'basic_card' => array(
        'weight' => 0,
        'visible' => FALSE,
      ),
    ); /* WAS: '' */
  }
  if (isset($data['node_preview_press_release'])) {
    $data['node_preview_press_release']->value = 0; /* WAS: 1 */
  }
}

/**
 * Implements hook_views_default_views_alter().
 */
function nc_press_release_views_default_views_alter(&$data) {
  if (isset($data['press_release_list'])) {
    $data['press_release_list']->display['default']->display_options['exposed_form']['options'] = array(
      'reset_button' => TRUE,
    ); /* WAS: '' */
    $data['press_release_list']->display['default']->display_options['sorts']['field_release_date_value']['expose'] = array(
      'label' => 'Release Date (field_release_date)',
    ); /* WAS: '' */
    $data['press_release_list']->display['default']->display_options['sorts']['field_release_date_value']['exposed'] = TRUE; /* WAS: '' */
    $data['press_release_list']->display['page_1']->display_options['defaults']['empty'] = FALSE; /* WAS: '' */
    $data['press_release_list']->display['page_1']->display_options['defaults']['filter_groups'] = FALSE; /* WAS: '' */
    $data['press_release_list']->display['page_1']->display_options['defaults']['filters'] = FALSE; /* WAS: '' */
    $data['press_release_list']->display['page_1']->display_options['defaults']['sorts'] = FALSE; /* WAS: '' */
    $data['press_release_list']->display['page_1']->display_options['empty'] = array(
      'area' => array(
        'id' => 'area',
        'table' => 'views',
        'field' => 'area',
        'empty' => TRUE,
        'content' => 'There were no results found matching the selected criteria.',
        'format' => 'plain_text',
      ),
    ); /* WAS: '' */
    $data['press_release_list']->display['page_1']->display_options['fields']['field_release_date']['settings']['style_settings'] = array(
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
    ); /* WAS: '' */
    $data['press_release_list']->display['page_1']->display_options['fields']['type']['alter']['text'] = '<br><span class=\'date\'>[field_release_date]</span> | <span class=\'tag\'>[type]</span><br/>'; /* WAS: '<span class=\'date\'>[field_release_date]</span> | <span class=\'tag\'>[type]</span>' */
    $data['press_release_list']->display['page_1']->display_options['filters'] = array(
      'status' => array(
        'id' => 'status',
        'table' => 'node',
        'field' => 'status',
        'value' => 1,
      ),
      'type' => array(
        'id' => 'type',
        'table' => 'node',
        'field' => 'type',
        'value' => array(
          'press_release' => 'press_release',
          'story' => 'story',
        ),
      ),
      'field_agency_department_tid' => array(
        'id' => 'field_agency_department_tid',
        'table' => 'field_data_field_agency_department',
        'field' => 'field_agency_department_tid',
        'exposed' => TRUE,
        'expose' => array(
          'operator_id' => 'field_agency_department_tid_op',
          'label' => 'Division/Office',
          'operator' => 'field_agency_department_tid_op',
          'identifier' => 'field_agency_department_tid',
          'remember_roles' => array(
            2 => 2,
            1 => 0,
            4 => 0,
            3 => 0,
            5 => 0,
            6 => 0,
            7 => 0,
            8 => 0,
          ),
        ),
        'type' => 'select',
        'vocabulary' => 'nc_agency_department',
        'hierarchy' => 1,
      ),
    ); /* WAS: '' */
    $data['press_release_list']->display['page_1']->display_options['path'] = 'news/press-releases'; /* WAS: 'press-releases' */
    $data['press_release_list']->display['page_1']->display_options['row_options'] = array(
      'links' => FALSE,
    ); /* WAS: '' */
    $data['press_release_list']->display['page_1']->display_options['row_plugin'] = 'node'; /* WAS: 'fields' */
    $data['press_release_list']->display['page_1']->display_options['sorts'] = array(
      'field_release_date_value' => array(
        'id' => 'field_release_date_value',
        'table' => 'field_data_field_release_date',
        'field' => 'field_release_date_value',
        'order' => 'DESC',
        'expose' => array(
          'label' => 'Release Date (field_release_date)',
        ),
      ),
    ); /* WAS: '' */
    $data['press_release_list']->display['page_2'] = unserialize('O:13:"views_display":7:{s:15:"display_options";a:14:{s:5:"query";a:2:{s:4:"type";s:11:"views_query";s:7:"options";a:0:{}}s:8:"defaults";a:13:{s:5:"title";b:0;s:16:"hide_admin_links";b:0;s:5:"pager";b:0;s:12:"style_plugin";b:0;s:13:"style_options";b:0;s:10:"row_plugin";b:0;s:11:"row_options";b:0;s:6:"header";b:0;s:5:"empty";b:0;s:6:"fields";b:0;s:5:"sorts";b:0;s:13:"filter_groups";b:0;s:7:"filters";b:0;}s:5:"title";s:14:"Press Releases";s:5:"pager";a:2:{s:4:"type";s:4:"full";s:7:"options";a:3:{s:14:"items_per_page";s:2:"10";s:6:"offset";s:1:"0";s:2:"id";s:1:"0";}}s:12:"style_plugin";s:7:"default";s:13:"style_options";a:2:{s:9:"row_class";s:5:"entry";s:11:"uses_fields";b:1;}s:10:"row_plugin";s:6:"fields";s:6:"header";a:1:{s:4:"area";a:5:{s:2:"id";s:4:"area";s:5:"table";s:5:"views";s:5:"field";s:4:"area";s:7:"content";s:38:"<div class="divide-double-line"></div>";s:6:"format";s:9:"full_html";}}s:5:"empty";a:1:{s:4:"area";a:6:{s:2:"id";s:4:"area";s:5:"table";s:5:"views";s:5:"field";s:4:"area";s:5:"empty";b:1;s:7:"content";s:59:"There were no results found matching the selected criteria.";s:6:"format";s:10:"plain_text";}}s:6:"fields";a:4:{s:4:"type";a:9:{s:2:"id";s:4:"type";s:5:"table";s:4:"node";s:5:"field";s:4:"type";s:5:"label";s:0:"";s:7:"exclude";b:1;s:5:"alter";a:1:{s:4:"text";s:55:"<br><span class=\'date\'>[field_release_date]</span><br/>";}s:12:"element_type";s:3:"div";s:13:"element_class";s:8:"date-tag";s:19:"element_label_colon";b:0;}s:5:"title";a:5:{s:2:"id";s:5:"title";s:5:"table";s:4:"node";s:5:"field";s:5:"title";s:5:"label";s:0:"";s:12:"element_type";s:2:"h4";}s:18:"field_release_date";a:9:{s:2:"id";s:18:"field_release_date";s:5:"table";s:29:"field_data_field_release_date";s:5:"field";s:18:"field_release_date";s:5:"label";s:0:"";s:5:"alter";a:2:{s:10:"alter_text";b:1;s:4:"text";s:52:"<span class=\'label date\'>[field_release_date]</span>";}s:18:"element_label_type";s:4:"span";s:19:"element_label_class";s:4:"meta";s:19:"element_label_colon";b:0;s:8:"settings";a:6:{s:11:"format_type";s:4:"long";s:6:"fromto";s:4:"both";s:15:"multiple_number";s:0:"";s:13:"multiple_from";s:0:"";s:11:"multiple_to";s:0:"";s:14:"style_settings";a:7:{s:5:"title";a:3:{s:7:"element";s:3:"div";s:5:"class";s:11:"field-label";s:6:"suffix";s:1:":";}s:7:"content";a:2:{s:7:"element";s:3:"div";s:5:"class";s:11:"field-items";}s:4:"item";a:2:{s:7:"element";s:3:"div";s:5:"class";s:10:"field-item";}s:7:"wrapper";a:2:{s:7:"element";s:3:"div";s:5:"class";s:0:"";}s:15:"default_classes";i:1;s:13:"prefix_markup";s:0:"";s:10:"item_limit";s:0:"";}}}s:4:"body";a:7:{s:2:"id";s:4:"body";s:5:"table";s:15:"field_data_body";s:5:"field";s:4:"body";s:5:"label";s:0:"";s:19:"element_label_colon";b:0;s:4:"type";s:23:"text_summary_or_trimmed";s:8:"settings";a:2:{s:11:"trim_length";s:3:"350";s:14:"style_settings";a:7:{s:5:"title";a:3:{s:7:"element";s:3:"div";s:5:"class";s:11:"field-label";s:6:"suffix";s:1:":";}s:7:"content";a:2:{s:7:"element";s:3:"div";s:5:"class";s:11:"field-items";}s:4:"item";a:2:{s:7:"element";s:3:"div";s:5:"class";s:10:"field-item";}s:7:"wrapper";a:2:{s:7:"element";s:3:"div";s:5:"class";s:0:"";}s:15:"default_classes";i:1;s:13:"prefix_markup";s:0:"";s:10:"item_limit";s:0:"";}}}}s:5:"sorts";a:1:{s:24:"field_release_date_value";a:5:{s:2:"id";s:24:"field_release_date_value";s:5:"table";s:29:"field_data_field_release_date";s:5:"field";s:24:"field_release_date_value";s:5:"order";s:4:"DESC";s:6:"expose";a:1:{s:5:"label";s:33:"Release Date (field_release_date)";}}}s:7:"filters";a:4:{s:6:"status";a:5:{s:2:"id";s:6:"status";s:5:"table";s:4:"node";s:5:"field";s:6:"status";s:5:"value";i:1;s:5:"group";i:1;}s:4:"type";a:5:{s:2:"id";s:4:"type";s:5:"table";s:4:"node";s:5:"field";s:4:"type";s:5:"value";a:2:{s:13:"press_release";s:13:"press_release";s:5:"story";s:5:"story";}s:5:"group";i:1;}s:7:"combine";a:9:{s:2:"id";s:7:"combine";s:5:"table";s:5:"views";s:5:"field";s:7:"combine";s:8:"operator";s:8:"contains";s:5:"group";i:1;s:7:"exposed";b:1;s:6:"expose";a:5:{s:11:"operator_id";s:10:"combine_op";s:5:"label";s:21:"Combine fields filter";s:8:"operator";s:10:"combine_op";s:10:"identifier";s:7:"combine";s:14:"remember_roles";a:8:{i:2;s:1:"2";i:1;i:0;i:4;i:0;i:3;i:0;i:5;i:0;i:6;i:0;i:7;i:0;i:8;i:0;}}s:10:"group_info";a:3:{s:5:"label";s:21:"Combine fields filter";s:10:"identifier";s:7:"combine";s:11:"group_items";a:3:{i:1;a:3:{s:5:"title";s:0:"";s:8:"operator";s:8:"contains";s:5:"value";s:0:"";}i:2;a:3:{s:5:"title";s:0:"";s:8:"operator";s:8:"contains";s:5:"value";s:0:"";}i:3;a:3:{s:5:"title";s:0:"";s:8:"operator";s:8:"contains";s:5:"value";s:0:"";}}}s:6:"fields";a:2:{s:5:"title";s:5:"title";s:4:"body";s:4:"body";}}s:27:"field_agency_department_tid";a:9:{s:2:"id";s:27:"field_agency_department_tid";s:5:"table";s:34:"field_data_field_agency_department";s:5:"field";s:27:"field_agency_department_tid";s:5:"value";a:11:{i:122;s:3:"122";i:409;s:3:"409";i:433;s:3:"433";i:123;s:3:"123";i:121;s:3:"121";i:446;s:3:"446";i:421;s:3:"421";i:642;s:3:"642";i:432;s:3:"432";i:416;s:3:"416";i:438;s:3:"438";}s:7:"exposed";b:1;s:6:"expose";a:6:{s:11:"operator_id";s:30:"field_agency_department_tid_op";s:5:"label";s:43:"Agency/Department (field_agency_department)";s:8:"operator";s:30:"field_agency_department_tid_op";s:10:"identifier";s:27:"field_agency_department_tid";s:14:"remember_roles";a:8:{i:2;s:1:"2";i:1;i:0;i:4;i:0;i:3;i:0;i:5;i:0;i:6;i:0;i:7;i:0;i:8;i:0;}s:6:"reduce";b:1;}s:4:"type";s:6:"select";s:10:"vocabulary";s:20:"nc_agency_department";s:9:"hierarchy";i:1;}}s:4:"path";s:31:"news/press-releases-search-test";s:4:"menu";a:3:{s:5:"title";s:14:"Press Releases";s:6:"weight";s:1:"0";s:4:"name";s:9:"main-menu";}}s:8:"db_table";s:13:"views_display";s:3:"vid";i:0;s:2:"id";s:6:"page_2";s:13:"display_title";s:31:"Press Releases Page search test";s:14:"display_plugin";s:4:"page";s:8:"position";i:0;}'); /* WAS: '' */
    unset($data['press_release_list']->display['page_1']->display_options['fields']['field_release_date']['exclude']);
  }
}

/**
 * Implements hook_microdata_mappings_defaults().
 */
function nc_press_release_microdata_mappings_defaults() {
  $microdata_mappings = array();

  // Exported Microdata mapping: press_release
  $microdata_mappings['node']['press_release'] = array(
    '#itemtype' => array(
      0 => 'http://schema.org/NewsArticle',
    ),
    'title' => array(
      '#itemprop' => array(
        0 => 'name',
        1 => 'headline',
      ),
    ),
    '#is_item' => TRUE,
    '#itemid_token' => '[node:url]',
    '#use_schema_url' => 1,
    'body' => array(
      '#itemprop' => array(),
      '#is_item' => FALSE,
      'value' => array(
        '#itemprop' => array(),
        '#itemtype' => '',
      ),
      'summary' => array(
        '#itemprop' => array(
          0 => 'description',
        ),
        '#itemtype' => '',
      ),
    ),
    'field_release_date' => array(
      '#itemprop' => array(
        0 => 'datePublished',
      ),
      '#is_item' => FALSE,
    ),
    'field_thumbnail_image' => array(
      '#itemprop' => array(
        0 => 'image',
      ),
      '#is_item' => FALSE,
    ),
    'field_agency_department' => array(
      '#itemprop' => array(),
      '#is_item' => FALSE,
    ),
    'field_press_release_terms' => array(
      '#itemprop' => array(
        0 => 'about',
      ),
      '#is_item' => FALSE,
    ),
    'field_city_location' => array(
      '#itemprop' => array(
        0 => 'dateline',
      ),
      '#is_item' => FALSE,
    ),
    'field_main_image' => array(
      '#itemprop' => array(),
      '#is_item' => FALSE,
    ),
    'field_contact_name' => array(
      '#itemprop' => array(),
      '#is_item' => FALSE,
    ),
    'field_contact_phone' => array(
      '#itemprop' => array(),
      '#is_item' => FALSE,
    ),
    'field_subtitle' => array(
      '#itemprop' => array(
        0 => 'description',
      ),
      '#is_item' => FALSE,
    ),
  );

  return $microdata_mappings;
}
