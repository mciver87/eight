<?php
/**
 * @file
 * nc_blog_entry.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nc_blog_entry_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_context_default_contexts_alter().
 */
function nc_blog_entry_context_default_contexts_alter(&$data) {
  if (isset($data['blog'])) {
    $data['blog']->conditions['node']['options']['node_form'] = 0; /* WAS: 1 */
    $data['blog']->conditions['views'] = array(
      'values' => array(
        'blog_entry_list:page_1' => 'blog_entry_list:page_1',
      ),
    ); /* WAS: '' */
  }
}

/**
 * Implements hook_field_default_field_instances_alter().
 */
function nc_blog_entry_field_default_field_instances_alter(&$data) {
  if (isset($data['node-blog_entry-body'])) {
    $data['node-blog_entry-body']['display']['basic_card'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-blog_entry-body']['display']['block_feature'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-blog_entry-body']['display']['default']['settings']['style_settings'] = array(
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
    $data['node-blog_entry-body']['display']['default']['weight'] = 3; /* WAS: 2 */
    $data['node-blog_entry-body']['display']['teaser']['module'] = 'nc_field_formatters'; /* WAS: 'text' */
    $data['node-blog_entry-body']['display']['teaser']['settings']['style_settings'] = array(
      'content' => array(
        'class' => 'field-items',
        'element' => '',
      ),
      'default_classes' => 1,
      'item' => array(
        'class' => 'field-item',
        'element' => '',
      ),
      'item_limit' => '',
      'prefix_markup' => '',
      'title' => array(
        'class' => 'field-label',
        'element' => '',
        'suffix' => ':',
      ),
      'wrapper' => array(
        'class' => '',
        'element' => '',
      ),
    ); /* WAS: '' */
    $data['node-blog_entry-body']['display']['teaser']['type'] = 'text_summary_or_trimmed_plain'; /* WAS: 'text_summary_or_trimmed' */
    $data['node-blog_entry-body']['display']['teaser']['weight'] = 2; /* WAS: 0 */
    $data['node-blog_entry-body']['required'] = 0; /* WAS: FALSE */
    $data['node-blog_entry-body']['settings']['display_summary'] = 1; /* WAS: TRUE */
    $data['node-blog_entry-body']['widget']['active'] = 1; /* WAS: '' */
    $data['node-blog_entry-body']['widget']['weight'] = 4; /* WAS: 5 */
  }
  if (isset($data['node-blog_entry-field_author'])) {
    unset($data['node-blog_entry-field_author']);
  }
  if (isset($data['node-blog_entry-field_files'])) {
    $data['node-blog_entry-field_files']['display']['basic_card'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-blog_entry-field_files']['display']['block_feature'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-blog_entry-field_files']['display']['default']['module'] = 'nc_fields'; /* WAS: 'file' */
    $data['node-blog_entry-field_files']['display']['default']['settings']['style_settings'] = array(
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
    $data['node-blog_entry-field_files']['display']['default']['type'] = 'nc_fields_file_formatter_detail'; /* WAS: 'file_default' */
    $data['node-blog_entry-field_files']['display']['default']['weight'] = 3; /* WAS: 4 */
    $data['node-blog_entry-field_files']['display']['teaser']['weight'] = 8; /* WAS: 0 */
    $data['node-blog_entry-field_files']['widget']['settings']['imce_filefield_on'] = 1; /* WAS: '' */
    $data['node-blog_entry-field_files']['widget']['weight'] = 8; /* WAS: 9 */
  }
  if (isset($data['node-blog_entry-field_release_date'])) {
    $data['node-blog_entry-field_release_date']['display']['basic_card'] = array(
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
    $data['node-blog_entry-field_release_date']['display']['block_feature'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-blog_entry-field_release_date']['display']['default']['settings']['style_settings'] = array(
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
    $data['node-blog_entry-field_release_date']['display']['default']['weight'] = 1; /* WAS: 0 */
    $data['node-blog_entry-field_release_date']['display']['teaser']['label'] = 'hidden'; /* WAS: 'above' */
    $data['node-blog_entry-field_release_date']['display']['teaser']['module'] = 'date'; /* WAS: '' */
    $data['node-blog_entry-field_release_date']['display']['teaser']['settings']['format_type'] = 'nc_event_detail'; /* WAS: '' */
    $data['node-blog_entry-field_release_date']['display']['teaser']['settings']['fromto'] = 'both'; /* WAS: '' */
    $data['node-blog_entry-field_release_date']['display']['teaser']['settings']['multiple_from'] = ''; /* WAS: '' */
    $data['node-blog_entry-field_release_date']['display']['teaser']['settings']['multiple_number'] = ''; /* WAS: '' */
    $data['node-blog_entry-field_release_date']['display']['teaser']['settings']['multiple_to'] = ''; /* WAS: '' */
    $data['node-blog_entry-field_release_date']['display']['teaser']['settings']['style_settings'] = array(
      'content' => array(
        'class' => 'meta',
        'element' => 'div',
      ),
      'default_classes' => 1,
      'item' => array(
        'class' => 'label date',
        'element' => 'span',
      ),
      'item_limit' => '',
      'prefix_markup' => '',
      'title' => array(
        'class' => 'field-label',
        'element' => '',
        'suffix' => ':',
      ),
      'wrapper' => array(
        'class' => '',
        'element' => '',
      ),
    ); /* WAS: '' */
    $data['node-blog_entry-field_release_date']['display']['teaser']['type'] = 'date_default'; /* WAS: 'hidden' */
    $data['node-blog_entry-field_release_date']['display']['teaser']['weight'] = 1; /* WAS: 0 */
    $data['node-blog_entry-field_release_date']['widget']['weight'] = 2; /* WAS: 1 */
    unset($data['node-blog_entry-field_release_date']['display']['default']['settings']['show_repeat_rule']);
  }
  if (isset($data['node-blog_entry-field_thumbnail_image'])) {
    $data['node-blog_entry-field_thumbnail_image']['display']['basic_card'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-blog_entry-field_thumbnail_image']['display']['block_feature'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-blog_entry-field_thumbnail_image']['display']['default']['type'] = 'hidden'; /* WAS: 'image' */
    $data['node-blog_entry-field_thumbnail_image']['display']['default']['weight'] = 7; /* WAS: 1 */
    $data['node-blog_entry-field_thumbnail_image']['display']['teaser']['label'] = 'hidden'; /* WAS: 'above' */
    $data['node-blog_entry-field_thumbnail_image']['display']['teaser']['module'] = 'image'; /* WAS: '' */
    $data['node-blog_entry-field_thumbnail_image']['display']['teaser']['settings']['image_link'] = ''; /* WAS: '' */
    $data['node-blog_entry-field_thumbnail_image']['display']['teaser']['settings']['image_style'] = ''; /* WAS: '' */
    $data['node-blog_entry-field_thumbnail_image']['display']['teaser']['settings']['style_settings'] = array(
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
    $data['node-blog_entry-field_thumbnail_image']['display']['teaser']['type'] = 'image'; /* WAS: 'hidden' */
    $data['node-blog_entry-field_thumbnail_image']['display']['teaser']['weight'] = 3; /* WAS: 0 */
    $data['node-blog_entry-field_thumbnail_image']['widget']['settings']['imce_filefield_on'] = TRUE; /* WAS: '' */
    $data['node-blog_entry-field_thumbnail_image']['widget']['weight'] = 9; /* WAS: 11 */
    unset($data['node-blog_entry-field_thumbnail_image']['display']['default']['module']);
    unset($data['node-blog_entry-field_thumbnail_image']['display']['default']['settings']['image_link']);
    unset($data['node-blog_entry-field_thumbnail_image']['display']['default']['settings']['image_style']);
  }
}

/**
 * Implements hook_strongarm_alter().
 */
function nc_blog_entry_strongarm_alter(&$data) {
  if (isset($data['field_bundle_settings_node__blog_entry'])) {
    $data['field_bundle_settings_node__blog_entry']->value['extra_fields']['display']['language'] = array(
      'default' => array(
        'weight' => 8,
        'visible' => FALSE,
      ),
      'teaser' => array(
        'weight' => 6,
        'visible' => FALSE,
      ),
      'basic_card' => array(
        'weight' => 0,
        'visible' => FALSE,
      ),
    ); /* WAS: '' */
  }
  if (isset($data['node_preview_blog_entry'])) {
    $data['node_preview_blog_entry']->value = 0; /* WAS: 1 */
  }
  if (isset($data['node_submitted_blog_entry'])) {
    $data['node_submitted_blog_entry']->value = 0; /* WAS: 1 */
  }
}

/**
 * Implements hook_views_default_views_alter().
 */
function nc_blog_entry_views_default_views_alter(&$data) {
  if (isset($data['blog_entry_list'])) {
    $data['blog_entry_list']->display['default']->display_options['query']['options']['distinct'] = TRUE; /* WAS: '' */
    $data['blog_entry_list']->display['feed_1']->display_options['path'] = 'blog/feed'; /* WAS: 'blogs/feeds' */
    $data['blog_entry_list']->display['page_1']->display_options['arguments'] = array(
      'tid' => array(
        'id' => 'tid',
        'table' => 'taxonomy_index',
        'field' => 'tid',
        'title_enable' => TRUE,
        'title' => 'In the News: %1',
        'breadcrumb_enable' => TRUE,
        'breadcrumb' => '%1',
        'default_argument_type' => 'fixed',
        'summary' => array(
          'format' => 'default_summary',
        ),
        'specify_validation' => TRUE,
        'validate' => array(
          'type' => 'taxonomy_term',
        ),
        'validate_options' => array(
          'vocabularies' => array(
            'blog_category' => 'blog_category',
          ),
          'type' => 'convert',
        ),
        'reduce_duplicates' => TRUE,
      ),
    ); /* WAS: '' */
    $data['blog_entry_list']->display['page_1']->display_options['defaults']['arguments'] = FALSE; /* WAS: '' */
    $data['blog_entry_list']->display['page_1']->display_options['defaults']['filter_groups'] = FALSE; /* WAS: '' */
    $data['blog_entry_list']->display['page_1']->display_options['defaults']['filters'] = FALSE; /* WAS: '' */
    $data['blog_entry_list']->display['page_1']->display_options['defaults']['row_options'] = FALSE; /* WAS: '' */
    $data['blog_entry_list']->display['page_1']->display_options['defaults']['row_plugin'] = FALSE; /* WAS: '' */
    $data['blog_entry_list']->display['page_1']->display_options['defaults']['style_options'] = FALSE; /* WAS: '' */
    $data['blog_entry_list']->display['page_1']->display_options['defaults']['style_plugin'] = FALSE; /* WAS: '' */
    $data['blog_entry_list']->display['page_1']->display_options['filters'] = array(
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
          'blog_entry' => 'blog_entry',
        ),
      ),
      'field_blog_category_tid' => array(
        'id' => 'field_blog_category_tid',
        'table' => 'field_data_field_blog_category',
        'field' => 'field_blog_category_tid',
        'exposed' => TRUE,
        'expose' => array(
          'operator_id' => 'field_blog_category_tid_op',
          'label' => 'Category',
          'operator' => 'field_blog_category_tid_op',
          'identifier' => 'field_blog_category_tid',
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
        'reduce_duplicates' => TRUE,
        'type' => 'select',
        'vocabulary' => 'blog_category',
      ),
      'field_blog_terms_tid' => array(
        'id' => 'field_blog_terms_tid',
        'table' => 'field_data_field_blog_terms',
        'field' => 'field_blog_terms_tid',
        'exposed' => TRUE,
        'expose' => array(
          'operator_id' => 'field_blog_terms_tid_op',
          'label' => 'Terms',
          'operator' => 'field_blog_terms_tid_op',
          'identifier' => 'field_blog_terms_tid',
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
        'reduce_duplicates' => TRUE,
        'type' => 'select',
        'vocabulary' => 'blog_terms',
      ),
    ); /* WAS: '' */
    $data['blog_entry_list']->display['page_1']->display_options['row_plugin'] = 'node'; /* WAS: '' */
    $data['blog_entry_list']->display['page_1']->display_options['style_plugin'] = 'default'; /* WAS: '' */
    unset($data['blog_entry_list']->display['default']->display_options['query']['options']['query_comment']);
  }
}

/**
 * Implements hook_microdata_mappings_defaults().
 */
function nc_blog_entry_microdata_mappings_defaults() {
  $microdata_mappings = array();

  // Exported Microdata mapping: blog_entry
  $microdata_mappings['node']['blog_entry'] = array(
    '#itemtype' => array(
      0 => 'http://schema.org/BlogPosting',
    ),
    'title' => array(
      '#itemprop' => array(),
    ),
    '#is_item' => TRUE,
    '#itemid_token' => '[node:url]',
    '#use_schema_url' => 0,
    'field_blog_author' => array(
      '#itemprop' => array(),
      '#is_item' => FALSE,
    ),
  );

  return $microdata_mappings;
}
