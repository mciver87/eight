<?php
/**
 * @file
 * nc_services.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nc_services_ctools_plugin_api($module = NULL, $api = NULL) {
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
function nc_services_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_field_default_field_instances_alter().
 */
function nc_services_field_default_field_instances_alter(&$data) {
  if (isset($data['node-services-body'])) {
    $data['node-services-body']['display']['basic_card'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-services-body']['display']['block_feature'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-services-body']['display']['default']['settings']['style_settings'] = array(
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
    $data['node-services-body']['display']['teaser']['settings']['style_settings'] = array(
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
    $data['node-services-body']['widget']['weight'] = 4; /* WAS: -4 */
  }
  if (isset($data['node-services-field_files'])) {
    $data['node-services-field_files']['display']['basic_card'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-services-field_files']['display']['block_feature'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-services-field_files']['display']['default']['label'] = 'hidden'; /* WAS: 'above' */
    $data['node-services-field_files']['display']['default']['module'] = 'nc_fields'; /* WAS: 'file' */
    $data['node-services-field_files']['display']['default']['settings']['style_settings'] = array(
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
    $data['node-services-field_files']['display']['default']['type'] = 'nc_fields_file_formatter_detail'; /* WAS: 'file_default' */
    $data['node-services-field_files']['widget']['settings']['filefield_sources'] = array(
      'filefield_sources' => array(),
      'source_attach' => array(
        'absolute' => 0,
        'attach_mode' => 'move',
        'path' => 'file_attach',
      ),
      'source_imce' => array(
        'imce_mode' => 0,
      ),
      'source_reference' => array(
        'autocomplete' => 0,
      ),
    ); /* WAS: '' */
    $data['node-services-field_files']['widget']['weight'] = 6; /* WAS: 32 */
  }
  if (isset($data['node-services-field_services_photo'])) {
    $data['node-services-field_services_photo']['display']['basic_card'] = array(
      'label' => 'hidden',
      'module' => 'image',
      'settings' => array(
        'image_link' => '',
        'image_style' => '',
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
      'type' => 'image',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-services-field_services_photo']['display']['block_feature'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-services-field_services_photo']['display']['default']['settings']['image_style'] = 'main-image'; /* WAS: 'content_detail_photo' */
    $data['node-services-field_services_photo']['display']['default']['settings']['style_settings'] = array(
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
    $data['node-services-field_services_photo']['widget']['settings']['filefield_sources'] = array(
      'filefield_sources' => array(),
      'source_attach' => array(
        'absolute' => 0,
        'attach_mode' => 'move',
        'path' => 'file_attach',
      ),
      'source_imce' => array(
        'imce_mode' => 0,
      ),
      'source_reference' => array(
        'autocomplete' => 0,
      ),
    ); /* WAS: '' */
    $data['node-services-field_services_photo']['widget']['weight'] = 2; /* WAS: -3 */
  }
}

/**
 * Implements hook_strongarm_alter().
 */
function nc_services_strongarm_alter(&$data) {
  if (isset($data['field_bundle_settings_node__services'])) {
    $data['field_bundle_settings_node__services']->value['extra_fields']['display']['language'] = array(
      'default' => array(
        'weight' => 5,
        'visible' => FALSE,
      ),
      'basic_card' => array(
        'weight' => 0,
        'visible' => FALSE,
      ),
    ); /* WAS: '' */
    $data['field_bundle_settings_node__services']->value['extra_fields']['form']['language'] = array(
      'weight' => 1,
    ); /* WAS: '' */
    $data['field_bundle_settings_node__services']->value['extra_fields']['form']['metatags'] = array(
      'weight' => 40,
    ); /* WAS: '' */
    $data['field_bundle_settings_node__services']->value['extra_fields']['form']['path']['weight'] = 9; /* WAS: 30 */
    $data['field_bundle_settings_node__services']->value['extra_fields']['form']['title']['weight'] = 0; /* WAS: -5 */
    $data['field_bundle_settings_node__services']->value['view_modes']['basic_card'] = array(
      'custom_settings' => TRUE,
    ); /* WAS: '' */
    $data['field_bundle_settings_node__services']->value['view_modes']['block_feature'] = array(
      'custom_settings' => TRUE,
    ); /* WAS: '' */
    $data['field_bundle_settings_node__services']->value['view_modes']['diff_standard'] = array(
      'custom_settings' => FALSE,
    ); /* WAS: '' */
    $data['field_bundle_settings_node__services']->value['view_modes']['full'] = array(
      'custom_settings' => FALSE,
    ); /* WAS: '' */
    $data['field_bundle_settings_node__services']->value['view_modes']['rss'] = array(
      'custom_settings' => FALSE,
    ); /* WAS: '' */
    $data['field_bundle_settings_node__services']->value['view_modes']['teaser'] = array(
      'custom_settings' => TRUE,
    ); /* WAS: '' */
    $data['field_bundle_settings_node__services']->value['view_modes']['token'] = array(
      'custom_settings' => FALSE,
    ); /* WAS: '' */
  }
  if (isset($data['node_preview_services'])) {
    $data['node_preview_services']->value = 0; /* WAS: 1 */
  }
  if (isset($data['node_submitted_services'])) {
    $data['node_submitted_services']->value = 0; /* WAS: 1 */
  }
}

/**
 * Implements hook_views_default_views_alter().
 */
function nc_services_views_default_views_alter(&$data) {
  if (isset($data['services_list'])) {
    $data['services_list']->display['attachment_1'] = unserialize('O:13:"views_display":7:{s:15:"display_options";a:11:{s:5:"query";a:2:{s:4:"type";s:11:"views_query";s:7:"options";a:2:{s:8:"distinct";b:1;s:13:"pure_distinct";b:1;}}s:19:"display_description";s:56:"This attachment is used to display the term description.";s:8:"defaults";a:12:{s:5:"query";b:0;s:12:"style_plugin";b:0;s:13:"style_options";b:0;s:10:"row_plugin";b:0;s:11:"row_options";b:0;s:6:"header";b:0;s:13:"relationships";b:0;s:6:"fields";b:0;s:5:"sorts";b:0;s:9:"arguments";b:0;s:13:"filter_groups";b:0;s:7:"filters";b:0;}s:5:"pager";a:2:{s:4:"type";s:4:"some";s:7:"options";a:2:{s:14:"items_per_page";s:2:"10";s:6:"offset";s:1:"0";}}s:12:"style_plugin";s:7:"default";s:10:"row_plugin";s:6:"fields";s:11:"row_options";a:2:{s:10:"hide_empty";b:1;s:22:"default_field_elements";b:0;}s:13:"relationships";a:1:{s:13:"term_node_tid";a:4:{s:2:"id";s:13:"term_node_tid";s:5:"table";s:4:"node";s:5:"field";s:13:"term_node_tid";s:12:"vocabularies";a:15:{s:16:"service_category";s:16:"service_category";s:15:"agency_category";i:0;s:20:"nc_agency_department";i:0;s:13:"blog_category";i:0;s:10:"blog_terms";i:0;s:13:"card_keywords";i:0;s:19:"document_collection";i:0;s:14:"document_terms";i:0;s:15:"event_organizer";i:0;s:11:"event_terms";i:0;s:10:"event_type";i:0;s:17:"key_search_topics";i:0;s:11:"nc_counties";i:0;s:19:"press_release_terms";i:0;s:11:"video_terms";i:0;}}}s:6:"fields";a:1:{s:11:"description";a:6:{s:2:"id";s:11:"description";s:5:"table";s:18:"taxonomy_term_data";s:5:"field";s:11:"description";s:12:"relationship";s:13:"term_node_tid";s:5:"label";s:0:"";s:19:"element_label_colon";b:0;}}s:9:"arguments";a:1:{s:3:"tid";a:10:{s:2:"id";s:3:"tid";s:5:"table";s:18:"taxonomy_term_data";s:5:"field";s:3:"tid";s:12:"relationship";s:13:"term_node_tid";s:21:"default_argument_type";s:5:"fixed";s:7:"summary";a:2:{s:17:"number_of_records";s:1:"0";s:6:"format";s:15:"default_summary";}s:15:"summary_options";a:1:{s:14:"items_per_page";s:2:"25";}s:18:"specify_validation";b:1;s:8:"validate";a:1:{s:4:"type";s:13:"taxonomy_term";}s:16:"validate_options";a:3:{s:12:"vocabularies";a:1:{s:16:"service_category";s:16:"service_category";}s:4:"type";s:7:"convert";s:9:"transform";b:1;}}}s:8:"displays";a:2:{s:6:"page_1";s:6:"page_1";s:7:"default";i:0;}}s:8:"db_table";s:13:"views_display";s:3:"vid";i:0;s:2:"id";s:12:"attachment_1";s:13:"display_title";s:29:"Attachment - Term Description";s:14:"display_plugin";s:10:"attachment";s:8:"position";i:0;}'); /* WAS: '' */
    $data['services_list']->display['attachment_3'] = unserialize('O:13:"views_display":7:{s:15:"display_options";a:11:{s:5:"query";a:2:{s:4:"type";s:11:"views_query";s:7:"options";a:2:{s:8:"distinct";b:1;s:13:"pure_distinct";b:1;}}s:19:"display_description";s:61:"This attachment is used to display the title for the results.";s:8:"defaults";a:12:{s:5:"query";b:0;s:12:"style_plugin";b:0;s:13:"style_options";b:0;s:10:"row_plugin";b:0;s:11:"row_options";b:0;s:6:"header";b:0;s:13:"relationships";b:0;s:6:"fields";b:0;s:5:"sorts";b:0;s:9:"arguments";b:0;s:13:"filter_groups";b:0;s:7:"filters";b:0;}s:5:"pager";a:2:{s:4:"type";s:4:"some";s:7:"options";a:2:{s:14:"items_per_page";s:2:"10";s:6:"offset";s:1:"0";}}s:12:"style_plugin";s:7:"default";s:10:"row_plugin";s:6:"fields";s:11:"row_options";a:2:{s:6:"inline";a:1:{s:4:"name";s:4:"name";}s:10:"hide_empty";b:1;}s:13:"relationships";a:1:{s:13:"term_node_tid";a:4:{s:2:"id";s:13:"term_node_tid";s:5:"table";s:4:"node";s:5:"field";s:13:"term_node_tid";s:12:"vocabularies";a:15:{s:16:"service_category";s:16:"service_category";s:15:"agency_category";i:0;s:20:"nc_agency_department";i:0;s:13:"blog_category";i:0;s:10:"blog_terms";i:0;s:13:"card_keywords";i:0;s:19:"document_collection";i:0;s:14:"document_terms";i:0;s:15:"event_organizer";i:0;s:11:"event_terms";i:0;s:10:"event_type";i:0;s:17:"key_search_topics";i:0;s:11:"nc_counties";i:0;s:19:"press_release_terms";i:0;s:11:"video_terms";i:0;}}}s:6:"fields";a:1:{s:4:"name";a:9:{s:2:"id";s:4:"name";s:5:"table";s:18:"taxonomy_term_data";s:5:"field";s:4:"name";s:12:"relationship";s:13:"term_node_tid";s:5:"label";s:0:"";s:5:"alter";a:2:{s:10:"alter_text";b:1;s:4:"text";s:6:"[name]";}s:12:"element_type";s:2:"h2";s:13:"element_class";s:13:"section-title";s:19:"element_label_colon";b:0;}}s:9:"arguments";a:1:{s:3:"tid";a:10:{s:2:"id";s:3:"tid";s:5:"table";s:18:"taxonomy_term_data";s:5:"field";s:3:"tid";s:12:"relationship";s:13:"term_node_tid";s:21:"default_argument_type";s:5:"fixed";s:7:"summary";a:2:{s:17:"number_of_records";s:1:"0";s:6:"format";s:15:"default_summary";}s:15:"summary_options";a:1:{s:14:"items_per_page";s:2:"25";}s:18:"specify_validation";b:1;s:8:"validate";a:1:{s:4:"type";s:13:"taxonomy_term";}s:16:"validate_options";a:3:{s:12:"vocabularies";a:1:{s:16:"service_category";s:16:"service_category";}s:4:"type";s:7:"convert";s:9:"transform";b:1;}}}s:8:"displays";a:2:{s:6:"page_1";s:6:"page_1";s:7:"default";i:0;}}s:8:"db_table";s:13:"views_display";s:3:"vid";i:0;s:2:"id";s:12:"attachment_3";s:13:"display_title";s:26:"Attachment - Section Title";s:14:"display_plugin";s:10:"attachment";s:8:"position";i:0;}'); /* WAS: '' */
    $data['services_list']->display['default']->display_options['arguments'] = array(
      'term_node_tid_depth' => array(
        'id' => 'term_node_tid_depth',
        'table' => 'node',
        'field' => 'term_node_tid_depth',
        'title_enable' => TRUE,
        'title' => '%1',
        'breadcrumb_enable' => TRUE,
        'breadcrumb' => '%1',
        'default_argument_type' => 'taxonomy_tid',
        'summary' => array(
          'format' => 'default_summary',
        ),
        'specify_validation' => TRUE,
        'validate' => array(
          'type' => 'taxonomy_term',
        ),
        'validate_options' => array(
          'vocabularies' => array(
            'service_category' => 'service_category',
          ),
          'type' => 'convert',
          'transform' => TRUE,
        ),
        'depth' => 1,
      ),
    ); /* WAS: '' */
    $data['services_list']->display['default']->display_options['exposed_form']['options'] = array(
      'reset_button' => TRUE,
    ); /* WAS: '' */
    $data['services_list']->display['default']->display_options['filters']['combine'] = array(
      'id' => 'combine',
      'table' => 'views',
      'field' => 'combine',
      'operator' => 'contains',
      'group' => 1,
      'exposed' => TRUE,
      'expose' => array(
        'operator_id' => 'combine_op',
        'label' => 'Keywords',
        'operator' => 'combine_op',
        'identifier' => 'combine',
        'remember_roles' => array(
          2 => 2,
          1 => 0,
          5 => 0,
          4 => 0,
          3 => 0,
          6 => 0,
          7 => 0,
        ),
      ),
      'fields' => array(
        'title' => 'title',
        'entity_id_1' => 'entity_id_1',
        'name' => 'name',
      ),
    ); /* WAS: '' */
    $data['services_list']->display['default']->display_options['filters']['delta'] = array(
      'id' => 'delta',
      'table' => 'field_data_field_service_category',
      'field' => 'delta',
      'value' => array(
        'value' => 1,
      ),
    ); /* WAS: '' */
    $data['services_list']->display['default']->display_options['filters']['field_service_type_value'] = array(
      'id' => 'field_service_type_value',
      'table' => 'field_data_field_service_type',
      'field' => 'field_service_type_value',
      'group' => 1,
      'exposed' => TRUE,
      'expose' => array(
        'operator_id' => 'field_service_type_value_op',
        'label' => 'Type',
        'operator' => 'field_service_type_value_op',
        'identifier' => 'type',
        'remember_roles' => array(
          2 => 2,
          1 => 0,
          5 => 0,
          4 => 0,
          3 => 0,
          6 => 0,
        ),
      ),
    ); /* WAS: '' */
    $data['services_list']->display['default']->display_options['filters']['status']['group'] = 1; /* WAS: '' */
    $data['services_list']->display['default']->display_options['filters']['term_node_tid_depth'] = array(
      'id' => 'term_node_tid_depth',
      'table' => 'node',
      'field' => 'term_node_tid_depth',
      'group' => 1,
      'exposed' => TRUE,
      'expose' => array(
        'operator_id' => 'term_node_tid_depth_op',
        'label' => 'Category',
        'operator' => 'term_node_tid_depth_op',
        'identifier' => 'content',
        'remember_roles' => array(
          2 => 2,
          1 => 0,
          5 => 0,
          4 => 0,
          3 => 0,
          6 => 0,
        ),
      ),
      'type' => 'select',
      'vocabulary' => 'service_category',
      'depth' => 2,
    ); /* WAS: '' */
    $data['services_list']->display['default']->display_options['filters']['type']['group'] = 1; /* WAS: '' */
    $data['services_list']->display['default']->display_options['header'] = array(
      'result' => array(
        'id' => 'result',
        'table' => 'views',
        'field' => 'result',
        'content' => '<strong> @total</strong> services found',
      ),
    ); /* WAS: '' */
    $data['services_list']->display['default']->display_options['pager']['type'] = 'full'; /* WAS: 'some' */
    $data['services_list']->display['default']->display_options['relationships'] = array(
      'field_service_category_tid' => array(
        'id' => 'field_service_category_tid',
        'table' => 'field_data_field_service_category',
        'field' => 'field_service_category_tid',
      ),
    ); /* WAS: '' */
    $data['services_list']->display['default']->display_options['row_options'] = array(
      'default_field_elements' => FALSE,
    ); /* WAS: '' */
    $data['services_list']->display['default']->display_options['sorts']['title'] = array(
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
    ); /* WAS: '' */
    $data['services_list']->display['default']->display_options['style_options']['default_row_class'] = FALSE; /* WAS: '' */
    $data['services_list']->display['default']->display_options['style_options']['row_class'] = 'article service'; /* WAS: 'entry' */
    $data['services_list']->display['default']->display_options['style_options']['row_class_special'] = FALSE; /* WAS: '' */
    $data['services_list']->display['page_1']->display_options['arguments'] = array(
      'term_node_tid_depth' => array(
        'id' => 'term_node_tid_depth',
        'table' => 'node',
        'field' => 'term_node_tid_depth',
        'default_action' => 'not found',
        'exception' => array(
          'value' => '',
        ),
        'title_enable' => TRUE,
        'title' => '%1',
        'breadcrumb_enable' => TRUE,
        'breadcrumb' => '%1',
        'default_argument_type' => 'taxonomy_tid',
        'summary' => array(
          'number_of_records' => 0,
          'format' => 'default_summary',
        ),
        'summary_options' => array(
          'items_per_page' => 25,
        ),
        'specify_validation' => TRUE,
        'validate' => array(
          'type' => 'taxonomy_term',
        ),
        'validate_options' => array(
          'vocabularies' => array(
            'service_category' => 'service_category',
          ),
          'type' => 'convert',
          'transform' => TRUE,
        ),
        'depth' => 1,
      ),
    ); /* WAS: '' */
    $data['services_list']->display['page_1']->display_options['defaults']['arguments'] = FALSE; /* WAS: '' */
    $data['services_list']->display['page_1']->display_options['defaults']['exposed_form'] = FALSE; /* WAS: '' */
    $data['services_list']->display['page_1']->display_options['defaults']['filter_groups'] = FALSE; /* WAS: '' */
    $data['services_list']->display['page_1']->display_options['defaults']['filters'] = FALSE; /* WAS: '' */
    $data['services_list']->display['page_1']->display_options['defaults']['header'] = FALSE; /* WAS: '' */
    $data['services_list']->display['page_1']->display_options['defaults']['use_ajax'] = FALSE; /* WAS: '' */
    $data['services_list']->display['page_1']->display_options['exposed_form'] = array(
      'type' => 'better_exposed_filters',
      'options' => array(
        'reset_button' => TRUE,
        'autosubmit' => TRUE,
        'autosubmit_hide' => FALSE,
        'bef' => array(
          'general' => array(
            'allow_secondary' => 0,
            'secondary_label' => 'Advanced options',
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'term_node_tid_depth' => array(
            'bef_format' => 'bef',
            'more_options' => array(
              'bef_select_all_none' => 0,
              'bef_collapsible' => 0,
              'is_secondary' => 0,
              'any_label' => '',
              'bef_filter_description' => '',
              'tokens' => array(
                'available' => array(
                  0 => 'global_types',
                  1 => 'vocabulary',
                  'secondary_label' => NULL,
                  'collapsible_label' => NULL,
                  'combine_rewrite' => NULL,
                  'reset_label' => NULL,
                  'bef_filter_description' => NULL,
                  'any_label' => NULL,
                  'filter_rewrite_values' => NULL,
                ),
                'secondary_label' => NULL,
                'collapsible_label' => NULL,
                'combine_rewrite' => NULL,
                'reset_label' => NULL,
                'bef_filter_description' => NULL,
                'any_label' => NULL,
                'filter_rewrite_values' => NULL,
              ),
              'rewrite' => array(
                'filter_rewrite_values' => '',
                'secondary_label' => NULL,
                'collapsible_label' => NULL,
                'combine_rewrite' => NULL,
                'reset_label' => NULL,
                'bef_filter_description' => NULL,
                'any_label' => NULL,
              ),
              'secondary_label' => NULL,
              'collapsible_label' => NULL,
              'combine_rewrite' => NULL,
              'reset_label' => NULL,
              'filter_rewrite_values' => NULL,
            ),
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'field_service_type_value' => array(
            'bef_format' => 'bef',
            'more_options' => array(
              'bef_select_all_none' => 0,
              'bef_collapsible' => 0,
              'is_secondary' => 0,
              'any_label' => '',
              'bef_filter_description' => '',
              'tokens' => array(
                'available' => array(
                  0 => 'global_types',
                  'secondary_label' => NULL,
                  'collapsible_label' => NULL,
                  'combine_rewrite' => NULL,
                  'reset_label' => NULL,
                  'bef_filter_description' => NULL,
                  'any_label' => NULL,
                  'filter_rewrite_values' => NULL,
                ),
                'secondary_label' => NULL,
                'collapsible_label' => NULL,
                'combine_rewrite' => NULL,
                'reset_label' => NULL,
                'bef_filter_description' => NULL,
                'any_label' => NULL,
                'filter_rewrite_values' => NULL,
              ),
              'rewrite' => array(
                'filter_rewrite_values' => '',
                'secondary_label' => NULL,
                'collapsible_label' => NULL,
                'combine_rewrite' => NULL,
                'reset_label' => NULL,
                'bef_filter_description' => NULL,
                'any_label' => NULL,
              ),
              'secondary_label' => NULL,
              'collapsible_label' => NULL,
              'combine_rewrite' => NULL,
              'reset_label' => NULL,
              'filter_rewrite_values' => NULL,
            ),
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'combine' => array(
            'bef_format' => 'default',
            'more_options' => array(
              'is_secondary' => 0,
              'any_label' => '',
              'bef_filter_description' => '',
              'tokens' => array(
                'available' => array(
                  0 => 'global_types',
                  'secondary_label' => NULL,
                  'collapsible_label' => NULL,
                  'combine_rewrite' => NULL,
                  'reset_label' => NULL,
                  'bef_filter_description' => NULL,
                  'any_label' => NULL,
                  'filter_rewrite_values' => NULL,
                ),
                'secondary_label' => NULL,
                'collapsible_label' => NULL,
                'combine_rewrite' => NULL,
                'reset_label' => NULL,
                'bef_filter_description' => NULL,
                'any_label' => NULL,
                'filter_rewrite_values' => NULL,
              ),
              'rewrite' => array(
                'filter_rewrite_values' => '',
                'secondary_label' => NULL,
                'collapsible_label' => NULL,
                'combine_rewrite' => NULL,
                'reset_label' => NULL,
                'bef_filter_description' => NULL,
                'any_label' => NULL,
              ),
              'secondary_label' => NULL,
              'collapsible_label' => NULL,
              'combine_rewrite' => NULL,
              'reset_label' => NULL,
              'filter_rewrite_values' => NULL,
            ),
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
          'filter_rewrite_values' => NULL,
        ),
        'input_required' => 0,
        'text_input_required_format' => 'full_html',
      ),
    ); /* WAS: '' */
    $data['services_list']->display['page_1']->display_options['fields']['entity_id_1']['alter']['strip_tags'] = TRUE; /* WAS: '' */
    $data['services_list']->display['page_1']->display_options['fields']['entity_id_1']['element_label_colon'] = FALSE; /* WAS: '' */
    $data['services_list']->display['page_1']->display_options['fields']['entity_id_1']['settings'] = array(
      'trim_length' => 600,
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
    ); /* WAS: '' */
    $data['services_list']->display['page_1']->display_options['fields']['field_external_url'] = array(
      'id' => 'field_external_url',
      'table' => 'field_data_field_external_url',
      'field' => 'field_external_url',
      'click_sort_column' => 'url',
      'type' => 'link_absolute',
      'settings' => array(
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
      ),
    ); /* WAS: '' */
    $data['services_list']->display['page_1']->display_options['fields']['field_online_service'] = array(
      'id' => 'field_online_service',
      'table' => 'field_data_field_online_service',
      'field' => 'field_online_service',
      'ui_name' => 'Prefix',
      'alter' => array(
        'text' => '<article class="service"><span class="icon-nc-online-service">Online service available</span></article>',
      ),
      'type' => 'list_key',
      'settings' => array(
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
      ),
    ); /* WAS: '' */
    $data['services_list']->display['page_1']->display_options['fields']['field_service_category'] = array(
      'id' => 'field_service_category',
      'table' => 'field_data_field_service_category',
      'field' => 'field_service_category',
      'type' => 'taxonomy_term_reference_plain',
      'settings' => array(
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
      ),
      'delta_limit' => 2,
      'delta_first_last' => TRUE,
    ); /* WAS: '' */
    $data['services_list']->display['page_1']->display_options['fields']['field_service_icon'] = array(
      'id' => 'field_service_icon',
      'table' => 'field_data_field_service_icon',
      'field' => 'field_service_icon',
      'relationship' => 'field_service_category_tid',
      'settings' => array(
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
      ),
    ); /* WAS: '' */
    $data['services_list']->display['page_1']->display_options['fields']['name'] = array(
      'id' => 'name',
      'table' => 'taxonomy_term_data',
      'field' => 'name',
      'relationship' => 'field_service_category_tid',
    ); /* WAS: '' */
    $data['services_list']->display['page_1']->display_options['fields']['nid'] = array(
      'id' => 'nid',
      'table' => 'node',
      'field' => 'nid',
      'alter' => array(
        'alter_text' => TRUE,
        'text' => 'node/[nid]',
      ),
    ); /* WAS: '' */
    $data['services_list']->display['page_1']->display_options['fields']['title']['link_to_node'] = FALSE; /* WAS: '' */
    $data['services_list']->display['page_1']->display_options['filters'] = array(
      'status' => array(
        'id' => 'status',
        'table' => 'node',
        'field' => 'status',
        'value' => 1,
        'group' => 1,
      ),
      'type' => array(
        'id' => 'type',
        'table' => 'node',
        'field' => 'type',
        'value' => array(
          'services' => 'services',
        ),
        'group' => 1,
      ),
      'delta' => array(
        'id' => 'delta',
        'table' => 'field_data_field_service_category',
        'field' => 'delta',
        'value' => array(
          'value' => 1,
        ),
        'group' => 1,
      ),
      'term_node_tid_depth' => array(
        'id' => 'term_node_tid_depth',
        'table' => 'node',
        'field' => 'term_node_tid_depth',
        'group' => 1,
        'exposed' => TRUE,
        'expose' => array(
          'operator_id' => 'term_node_tid_depth_op',
          'label' => 'Category',
          'operator' => 'term_node_tid_depth_op',
          'identifier' => 'content',
          'multiple' => TRUE,
          'remember_roles' => array(
            2 => 2,
            1 => 0,
            5 => 0,
            4 => 0,
            3 => 0,
            6 => 0,
            7 => 0,
            8 => 0,
          ),
        ),
        'type' => 'select',
        'vocabulary' => 'service_category',
        'depth' => 2,
      ),
      'field_service_type_value' => array(
        'id' => 'field_service_type_value',
        'table' => 'field_data_field_service_type',
        'field' => 'field_service_type_value',
        'group' => 1,
        'exposed' => TRUE,
        'expose' => array(
          'operator_id' => 'field_service_type_value_op',
          'label' => 'Type',
          'operator' => 'field_service_type_value_op',
          'identifier' => 'type',
          'multiple' => TRUE,
          'remember_roles' => array(
            2 => 2,
            1 => 0,
            5 => 0,
            4 => 0,
            3 => 0,
            6 => 0,
            7 => 0,
            8 => 0,
          ),
        ),
      ),
      'combine' => array(
        'id' => 'combine',
        'table' => 'views',
        'field' => 'combine',
        'operator' => 'contains',
        'group' => 1,
        'exposed' => TRUE,
        'expose' => array(
          'operator_id' => 'combine_op',
          'label' => 'Keyword',
          'description' => 'Contains:',
          'operator' => 'combine_op',
          'identifier' => 'combine',
          'remember_roles' => array(
            2 => 2,
            1 => 0,
            5 => 0,
            4 => 0,
            3 => 0,
            6 => 0,
            7 => 0,
            8 => 0,
          ),
        ),
        'fields' => array(
          'title' => 'title',
          'entity_id_1' => 'entity_id_1',
          'name' => 'name',
        ),
      ),
    ); /* WAS: '' */
    $data['services_list']->display['page_1']->display_options['header'] = array(
      'result' => array(
        'id' => 'result',
        'table' => 'views',
        'field' => 'result',
        'content' => '<strong> @total</strong> services found',
      ),
    ); /* WAS: '' */
    $data['services_list']->display['page_1']->display_options['metatags'] = array(
      'und' => array(
        'title' => array(
          'value' => 'NC.gov: Services',
          'default' => '[view:title] | [site:name]',
        ),
        'description' => array(
          'value' => '[view:description]',
          'default' => '[view:description]',
        ),
        'abstract' => array(
          'value' => '',
        ),
        'keywords' => array(
          'value' => '',
        ),
        'robots' => array(
          'value' => array(
            'index' => 0,
            'follow' => 0,
            'noindex' => 0,
            'nofollow' => 0,
            'noarchive' => 0,
            'nosnippet' => 0,
            'noodp' => 0,
            'noydir' => 0,
            'noimageindex' => 0,
            'notranslate' => 0,
          ),
        ),
        'news_keywords' => array(
          'value' => '',
        ),
        'standout' => array(
          'value' => '',
        ),
        'rights' => array(
          'value' => '',
        ),
        'image_src' => array(
          'value' => '',
        ),
        'canonical' => array(
          'value' => '[view:url]',
          'default' => '[view:url]',
        ),
        'shortlink' => array(
          'value' => '[current-page:url:unaliased]',
          'default' => '[current-page:url:unaliased]',
        ),
        'publisher' => array(
          'value' => '',
        ),
        'author' => array(
          'value' => '',
        ),
        'original-source' => array(
          'value' => '',
        ),
        'revisit-after' => array(
          'value' => '',
          'period' => '',
        ),
        'content-language' => array(
          'value' => '',
        ),
      ),
    ); /* WAS: '' */
    $data['services_list']->display['page_1']->display_options['path'] = 'services/%'; /* WAS: 'services' */
    $data['services_list']->display['page_1']->display_options['use_ajax'] = TRUE; /* WAS: '' */
    unset($data['services_list']->display['default']->display_options['css_class']);
    unset($data['services_list']->display['page_1']->display_options['defaults']['title']);
    unset($data['services_list']->display['page_1']->display_options['fields']['entity_id']);
    unset($data['services_list']->display['page_1']->display_options['fields']['view_node']);
    unset($data['services_list']->display['page_1']->display_options['title']);
  }
}
