<?php
/**
 * @file
 * nc_blog_entry.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function nc_blog_entry_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: context
  $overrides["context.blog.conditions|node|options|node_form"] = 0;
  $overrides["context.blog.conditions|views"] = array(
    'values' => array(
      'blog_entry_list:page_1' => 'blog_entry_list:page_1',
    ),
  );

  // Exported overrides for: field_instance
  $overrides["field_instance.node-blog_entry-body.display|basic_card"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-blog_entry-body.display|block_feature"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-blog_entry-body.display|default|settings|style_settings"] = array(
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
  );
  $overrides["field_instance.node-blog_entry-body.display|default|weight"] = 3;
  $overrides["field_instance.node-blog_entry-body.display|teaser|module"] = 'nc_field_formatters';
  $overrides["field_instance.node-blog_entry-body.display|teaser|settings|style_settings"] = array(
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
  );
  $overrides["field_instance.node-blog_entry-body.display|teaser|type"] = 'text_summary_or_trimmed_plain';
  $overrides["field_instance.node-blog_entry-body.display|teaser|weight"] = 1;
  $overrides["field_instance.node-blog_entry-body.required"] = 0;
  $overrides["field_instance.node-blog_entry-body.settings|display_summary"] = 1;
  $overrides["field_instance.node-blog_entry-body.widget|active"] = 1;
  $overrides["field_instance.node-blog_entry-body.widget|weight"] = 4;
  $overrides["field_instance.node-blog_entry-field_author.node-blog_entry-field_author"]["DELETED"] = TRUE;
  $overrides["field_instance.node-blog_entry-field_files.display|basic_card"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-blog_entry-field_files.display|block_feature"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-blog_entry-field_files.display|default|module"] = 'nc_fields';
  $overrides["field_instance.node-blog_entry-field_files.display|default|settings|style_settings"] = array(
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
  );
  $overrides["field_instance.node-blog_entry-field_files.display|default|type"] = 'nc_fields_file_formatter_detail';
  $overrides["field_instance.node-blog_entry-field_files.display|default|weight"] = 3;
  $overrides["field_instance.node-blog_entry-field_files.display|teaser|weight"] = 8;
  $overrides["field_instance.node-blog_entry-field_files.widget|settings|imce_filefield_on"] = 1;
  $overrides["field_instance.node-blog_entry-field_files.widget|weight"] = 8;
  $overrides["field_instance.node-blog_entry-field_release_date.display|basic_card"] = array(
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
  );
  $overrides["field_instance.node-blog_entry-field_release_date.display|block_feature"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-blog_entry-field_release_date.display|default|settings|show_repeat_rule"]["DELETED"] = TRUE;
  $overrides["field_instance.node-blog_entry-field_release_date.display|default|settings|style_settings"] = array(
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
  );
  $overrides["field_instance.node-blog_entry-field_release_date.display|default|weight"] = 1;
  $overrides["field_instance.node-blog_entry-field_release_date.display|teaser|label"] = 'hidden';
  $overrides["field_instance.node-blog_entry-field_release_date.display|teaser|module"] = 'date';
  $overrides["field_instance.node-blog_entry-field_release_date.display|teaser|settings|format_type"] = 'nc_event_detail';
  $overrides["field_instance.node-blog_entry-field_release_date.display|teaser|settings|fromto"] = 'both';
  $overrides["field_instance.node-blog_entry-field_release_date.display|teaser|settings|multiple_from"] = '';
  $overrides["field_instance.node-blog_entry-field_release_date.display|teaser|settings|multiple_number"] = '';
  $overrides["field_instance.node-blog_entry-field_release_date.display|teaser|settings|multiple_to"] = '';
  $overrides["field_instance.node-blog_entry-field_release_date.display|teaser|settings|style_settings"] = array(
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
  );
  $overrides["field_instance.node-blog_entry-field_release_date.display|teaser|type"] = 'date_default';
  $overrides["field_instance.node-blog_entry-field_release_date.display|teaser|weight"] = 1;
  $overrides["field_instance.node-blog_entry-field_release_date.widget|weight"] = 2;
  $overrides["field_instance.node-blog_entry-field_thumbnail_image.display|basic_card"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-blog_entry-field_thumbnail_image.display|block_feature"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-blog_entry-field_thumbnail_image.display|default|module"]["DELETED"] = TRUE;
  $overrides["field_instance.node-blog_entry-field_thumbnail_image.display|default|settings|image_link"]["DELETED"] = TRUE;
  $overrides["field_instance.node-blog_entry-field_thumbnail_image.display|default|settings|image_style"]["DELETED"] = TRUE;
  $overrides["field_instance.node-blog_entry-field_thumbnail_image.display|default|type"] = 'hidden';
  $overrides["field_instance.node-blog_entry-field_thumbnail_image.display|default|weight"] = 7;
  $overrides["field_instance.node-blog_entry-field_thumbnail_image.display|teaser|label"] = 'hidden';
  $overrides["field_instance.node-blog_entry-field_thumbnail_image.display|teaser|weight"] = 3;
  $overrides["field_instance.node-blog_entry-field_thumbnail_image.display|teaser|module"] = 'image';
  $overrides["field_instance.node-blog_entry-field_thumbnail_image.display|teaser|settings|image_link"] = '';
  $overrides["field_instance.node-blog_entry-field_thumbnail_image.display|teaser|settings|image_style"] = '';
  $overrides["field_instance.node-blog_entry-field_thumbnail_image.display|teaser|settings|style_settings"] = array(
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
  );
  $overrides["field_instance.node-blog_entry-field_thumbnail_image.display|teaser|type"] = 'image';
  $overrides["field_instance.node-blog_entry-field_thumbnail_image.widget|settings|imce_filefield_on"] = TRUE;
  $overrides["field_instance.node-blog_entry-field_thumbnail_image.widget|weight"] = 9;

  // Exported overrides for: variable
  $overrides["variable.field_bundle_settings_node__blog_entry.value|extra_fields|display|language"] = array(
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
  );
  $overrides["variable.node_preview_blog_entry.value"] = 0;
  $overrides["variable.node_submitted_blog_entry.value"] = 0;

  // Exported overrides for: views_view
  $overrides["views_view.blog_entry_list.display|default|display_options|query|options|distinct"] = TRUE;
  $overrides["views_view.blog_entry_list.display|default|display_options|query|options|query_comment"]["DELETED"] = TRUE;
  $overrides["views_view.blog_entry_list.display|feed_1|display_options|path"] = 'blog/feed';
  $overrides["views_view.blog_entry_list.display|page_1|display_options|arguments"] = array(
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
  );
  $overrides["views_view.blog_entry_list.display|page_1|display_options|defaults|arguments"] = FALSE;
  $overrides["views_view.blog_entry_list.display|page_1|display_options|defaults|filter_groups"] = FALSE;
  $overrides["views_view.blog_entry_list.display|page_1|display_options|defaults|filters"] = FALSE;
  $overrides["views_view.blog_entry_list.display|page_1|display_options|defaults|row_options"] = FALSE;
  $overrides["views_view.blog_entry_list.display|page_1|display_options|defaults|row_plugin"] = FALSE;
  $overrides["views_view.blog_entry_list.display|page_1|display_options|defaults|style_options"] = FALSE;
  $overrides["views_view.blog_entry_list.display|page_1|display_options|defaults|style_plugin"] = FALSE;
  $overrides["views_view.blog_entry_list.display|page_1|display_options|filters"] = array(
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
  );
  $overrides["views_view.blog_entry_list.display|page_1|display_options|row_plugin"] = 'node';
  $overrides["views_view.blog_entry_list.display|page_1|display_options|style_plugin"] = 'default';

 return $overrides;
}
