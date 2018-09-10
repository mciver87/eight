<?php
/**
 * @file
 * nc_profile.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function nc_profile_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: context
  $overrides["context.profile_page.hidden"] = 0;
  $overrides["context.profile_page.reactions|block|blocks|bean-nc_profile_node_block_featured"] = array(
    'module' => 'bean',
    'delta' => 'nc_profile_node_block_featured',
    'region' => 'sidebar_second',
    'weight' => 0,
  );
  $overrides["context.profile_page.tag"] = 'Content Types';

  // Exported overrides for: field_instance
  $overrides["field_instance.node-profile-body.display|basic_card"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 15,
  );
  $overrides["field_instance.node-profile-body.display|block_feature"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-profile-body.display|default|settings|style_settings"] = array(
    'content' => array(
      'class' => 'field-items',
      'element' => '',
    ),
    'default_classes' => 0,
    'item' => array(
      'class' => 'field-item',
      'element' => '',
    ),
    'item_limit' => '',
    'prefix_markup' => '',
    'title' => array(
      'class' => 'field-label',
      'element' => 'div',
      'suffix' => ':',
    ),
    'wrapper' => array(
      'class' => 'clearfix',
      'element' => 'div',
    ),
  );
  $overrides["field_instance.node-profile-body.display|default|weight"] = 5;
  $overrides["field_instance.node-profile-body.display|teaser|settings|style_settings"] = array(
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
  $overrides["field_instance.node-profile-field_profile_address.display|basic_card"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 11,
  );
  $overrides["field_instance.node-profile-field_profile_address.display|block_feature"] = array(
    'label' => 'hidden',
    'module' => 'text',
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
    'type' => 'text_default',
    'weight' => 0,
  );
  $overrides["field_instance.node-profile-field_profile_address.display|default|module"]["DELETED"] = TRUE;
  $overrides["field_instance.node-profile-field_profile_address.display|default|type"] = 'hidden';
  $overrides["field_instance.node-profile-field_profile_address.display|default|weight"] = 2;
  $overrides["field_instance.node-profile-field_profile_department.display|basic_card"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 12,
  );
  $overrides["field_instance.node-profile-field_profile_department.display|block_feature"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-profile-field_profile_department.display|default|weight"] = 8;
  $overrides["field_instance.node-profile-field_profile_division.display|basic_card"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 13,
  );
  $overrides["field_instance.node-profile-field_profile_division.display|block_feature"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-profile-field_profile_division.display|default|module"]["DELETED"] = TRUE;
  $overrides["field_instance.node-profile-field_profile_division.display|default|type"] = 'hidden';
  $overrides["field_instance.node-profile-field_profile_division.display|default|weight"] = 15;
  $overrides["field_instance.node-profile-field_profile_email.display|basic_card"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 14,
  );
  $overrides["field_instance.node-profile-field_profile_email.display|block_feature"] = array(
    'label' => 'hidden',
    'module' => 'text',
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
    'type' => 'text_default',
    'weight' => 0,
  );
  $overrides["field_instance.node-profile-field_profile_email.display|default|weight"] = 13;
  $overrides["field_instance.node-profile-field_profile_first_name.display|basic_card"] = array(
    'label' => 'hidden',
    'module' => 'text',
    'settings' => array(
      'field_formatter_class' => '',
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
    'type' => 'text_plain',
    'weight' => 1,
  );
  $overrides["field_instance.node-profile-field_profile_first_name.display|block_feature"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-profile-field_profile_first_name.display|default|weight"] = 9;
  $overrides["field_instance.node-profile-field_profile_job_title.display|basic_card"] = array(
    'label' => 'hidden',
    'module' => 'text',
    'settings' => array(
      'field_formatter_class' => '',
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
    'type' => 'text_plain',
    'weight' => 3,
  );
  $overrides["field_instance.node-profile-field_profile_job_title.display|block_feature"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-profile-field_profile_job_title.display|default|module"]["DELETED"] = TRUE;
  $overrides["field_instance.node-profile-field_profile_job_title.display|default|type"] = 'hidden';
  $overrides["field_instance.node-profile-field_profile_job_title.display|default|weight"] = 0;
  $overrides["field_instance.node-profile-field_profile_last_name.display|basic_card"] = array(
    'label' => 'hidden',
    'module' => 'text',
    'settings' => array(
      'field_formatter_class' => '',
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
    'type' => 'text_plain',
    'weight' => 2,
  );
  $overrides["field_instance.node-profile-field_profile_last_name.display|block_feature"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-profile-field_profile_last_name.display|default|weight"] = 11;
  $overrides["field_instance.node-profile-field_profile_leadership.display|basic_card"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 10,
  );
  $overrides["field_instance.node-profile-field_profile_leadership.display|block_feature"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-profile-field_profile_leadership.display|default|module"]["DELETED"] = TRUE;
  $overrides["field_instance.node-profile-field_profile_leadership.display|default|type"] = 'hidden';
  $overrides["field_instance.node-profile-field_profile_leadership.display|default|weight"] = 4;
  $overrides["field_instance.node-profile-field_profile_organization.display|basic_card"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 9,
  );
  $overrides["field_instance.node-profile-field_profile_organization.display|block_feature"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-profile-field_profile_organization.display|default|module"]["DELETED"] = TRUE;
  $overrides["field_instance.node-profile-field_profile_organization.display|default|type"] = 'hidden';
  $overrides["field_instance.node-profile-field_profile_organization.display|default|weight"] = 14;
  $overrides["field_instance.node-profile-field_profile_phone.display|basic_card"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 5,
  );
  $overrides["field_instance.node-profile-field_profile_phone.display|block_feature"] = array(
    'label' => 'hidden',
    'module' => 'text',
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
    'type' => 'text_default',
    'weight' => 0,
  );
  $overrides["field_instance.node-profile-field_profile_phone.display|default|weight"] = 7;
  $overrides["field_instance.node-profile-field_profile_photo.display|basic_card"] = array(
    'label' => 'hidden',
    'module' => 'image',
    'settings' => array(
      'field_formatter_class' => '',
      'image_link' => '',
      'image_style' => 'profile_square',
      'style_settings' => array(
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
      ),
    ),
    'type' => 'image',
    'weight' => 0,
  );
  $overrides["field_instance.node-profile-field_profile_photo.display|block_feature"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-profile-field_profile_photo.display|default|settings|image_style"] = 'profile_wide';
  $overrides["field_instance.node-profile-field_profile_photo.display|default|settings|style_settings"] = array(
    'content' => array(
      'class' => 'field-items',
      'element' => '',
    ),
    'default_classes' => 0,
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
      'class' => 'clearfix',
      'element' => 'div',
    ),
  );
  $overrides["field_instance.node-profile-field_profile_photo.display|default|weight"] = 1;
  $overrides["field_instance.node-profile-field_profile_photo.widget|settings|filefield_sources"] = array(
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
  );
  $overrides["field_instance.node-profile-field_profile_social_media.display|basic_card"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 4,
  );
  $overrides["field_instance.node-profile-field_profile_social_media.display|block_feature"] = array(
    'label' => 'above',
    'module' => 'text',
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
    'type' => 'text_default',
    'weight' => 0,
  );
  $overrides["field_instance.node-profile-field_profile_social_media.display|default|module"]["DELETED"] = TRUE;
  $overrides["field_instance.node-profile-field_profile_social_media.display|default|type"] = 'hidden';
  $overrides["field_instance.node-profile-field_profile_social_media.display|default|weight"] = 3;
  $overrides["field_instance.node-profile-field_profile_staff.display|basic_card"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 6,
  );
  $overrides["field_instance.node-profile-field_profile_staff.display|block_feature"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-profile-field_profile_staff.display|default|weight"] = 10;
  $overrides["field_instance.node-profile-field_profile_user.display|basic_card"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 7,
  );
  $overrides["field_instance.node-profile-field_profile_user.display|block_feature"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-profile-field_profile_user.display|default|weight"] = 12;

  // Exported overrides for: variable
  $overrides["variable.field_bundle_settings_node__profile.value|extra_fields|display|language"] = array(
    'default' => array(
      'weight' => 6,
      'visible' => FALSE,
    ),
    'basic_card' => array(
      'weight' => 8,
      'visible' => FALSE,
    ),
    'block_feature' => array(
      'weight' => 6,
      'visible' => FALSE,
    ),
  );
  $overrides["variable.field_bundle_settings_node__profile.value|view_modes|block_feature"] = array(
    'custom_settings' => TRUE,
  );
  $overrides["variable.node_preview_profile.value"] = 0;

  // Exported overrides for: views_view
  $overrides["views_view.profile_list.display|block_2"] = unserialize('O:13:"views_display":7:{s:15:"display_options";a:7:{s:5:"query";a:2:{s:4:"type";s:11:"views_query";s:7:"options";a:0:{}}s:8:"defaults";a:5:{s:5:"pager";b:0;s:12:"style_plugin";b:0;s:13:"style_options";b:0;s:10:"row_plugin";b:0;s:11:"row_options";b:0;}s:5:"pager";a:2:{s:4:"type";s:4:"some";s:7:"options";a:2:{s:14:"items_per_page";s:1:"2";s:6:"offset";s:1:"0";}}s:12:"style_plugin";s:4:"card";s:13:"style_options";a:2:{s:7:"columns";s:1:"1";s:7:"padding";i:1;}s:10:"row_plugin";s:13:"person_fields";s:11:"row_options";a:5:{s:10:"card_title";s:11:"entity_id_6";s:9:"card_name";s:5:"title";s:9:"card_link";s:3:"nid";s:10:"card_image";s:11:"entity_id_9";s:11:"card_framed";s:7:"nothing";}}s:8:"db_table";s:13:"views_display";s:3:"vid";i:0;s:2:"id";s:7:"block_2";s:13:"display_title";s:27:"Leadership Block - 2 Column";s:14:"display_plugin";s:5:"block";s:8:"position";i:0;}');
  $overrides["views_view.profile_list.display|block_3"] = unserialize('O:13:"views_display":7:{s:15:"display_options";a:8:{s:5:"query";a:2:{s:4:"type";s:11:"views_query";s:7:"options";a:0:{}}s:8:"defaults";a:6:{s:12:"link_display";b:0;s:5:"pager";b:0;s:12:"style_plugin";b:0;s:13:"style_options";b:0;s:10:"row_plugin";b:0;s:11:"row_options";b:0;}s:12:"link_display";s:6:"page_2";s:5:"pager";a:2:{s:4:"type";s:4:"some";s:7:"options";a:2:{s:14:"items_per_page";s:1:"4";s:6:"offset";s:1:"0";}}s:12:"style_plugin";s:4:"card";s:13:"style_options";a:2:{s:7:"columns";s:1:"3";s:7:"padding";i:1;}s:10:"row_plugin";s:13:"person_fields";s:11:"row_options";a:5:{s:10:"card_title";s:11:"entity_id_6";s:9:"card_name";s:5:"title";s:9:"card_link";s:3:"nid";s:10:"card_image";s:11:"entity_id_9";s:11:"card_framed";s:7:"nothing";}}s:8:"db_table";s:13:"views_display";s:3:"vid";i:0;s:2:"id";s:7:"block_3";s:13:"display_title";s:27:"Leadership Block - 4 Column";s:14:"display_plugin";s:5:"block";s:8:"position";i:0;}');
  $overrides["views_view.profile_list.display|default|display_options|fields|entity_id_9|element_label_colon"] = FALSE;
  $overrides["views_view.profile_list.display|default|display_options|fields|entity_id_9|settings|image_link"] = '';
  $overrides["views_view.profile_list.display|default|display_options|fields|entity_id_9|settings|image_style"] = 'card_photo';
  $overrides["views_view.profile_list.display|default|display_options|fields|entity_id_9|settings|style_settings"] = array(
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
  );
  $overrides["views_view.profile_list.display|default|display_options|fields|nid"] = array(
    'id' => 'nid',
    'table' => 'node',
    'field' => 'nid',
    'label' => 'Link',
    'alter' => array(
      'alter_text' => TRUE,
      'text' => 'node/[nid]',
    ),
  );
  $overrides["views_view.profile_list.display|default|display_options|fields|nothing"] = array(
    'id' => 'nothing',
    'table' => 'views',
    'field' => 'nothing',
    'label' => 'Framed',
    'alter' => array(
      'text' => 1,
      'trim_whitespace' => TRUE,
      'strip_tags' => TRUE,
    ),
  );
  $overrides["views_view.profile_list.display|default|display_options|fields|title"] = array(
    'id' => 'title',
    'table' => 'node',
    'field' => 'title',
    'label' => 'Title only',
    'element_label_colon' => FALSE,
    'link_to_node' => FALSE,
  );
  $overrides["views_view.profile_list.display|default|display_options|fields|title_1"]["DELETED"] = TRUE;
  $overrides["views_view.profile_list.display|default|display_options|pager|options"] = array(
    'items_per_page' => 12,
  );
  $overrides["views_view.profile_list.display|default|display_options|relationships"] = array(
    'nodequeue_rel' => array(
      'id' => 'nodequeue_rel',
      'table' => 'node',
      'field' => 'nodequeue_rel',
      'required' => TRUE,
      'limit' => 1,
      'names' => array(
        'leadership' => 'leadership',
      ),
    ),
  );
  $overrides["views_view.profile_list.display|default|display_options|sorts"] = array(
    'position' => array(
      'id' => 'position',
      'table' => 'nodequeue_nodes',
      'field' => 'position',
      'relationship' => 'nodequeue_rel',
    ),
    'field_profile_last_name_value' => array(
      'id' => 'field_profile_last_name_value',
      'table' => 'field_data_field_profile_last_name',
      'field' => 'field_profile_last_name_value',
    ),
  );
  $overrides["views_view.profile_list.display|default|display_options|style_plugin"] = 'list';
  $overrides["views_view.profile_list.display|page_1|display_options|defaults"] = array(
    'style_plugin' => FALSE,
    'style_options' => FALSE,
    'row_plugin' => FALSE,
    'row_options' => FALSE,
    'relationships' => FALSE,
    'arguments' => FALSE,
    'filter_groups' => FALSE,
    'filters' => FALSE,
  );
  $overrides["views_view.profile_list.display|page_1|display_options|filters"] = array(
    'status_extra' => array(
      'id' => 'status_extra',
      'table' => 'node',
      'field' => 'status_extra',
    ),
    'type' => array(
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'value' => array(
        'author' => 'author',
        'profile' => 'profile',
      ),
    ),
    'field_profile_staff_value' => array(
      'id' => 'field_profile_staff_value',
      'table' => 'field_data_field_profile_staff',
      'field' => 'field_profile_staff_value',
      'value' => array(
        1 => 1,
      ),
      'expose' => array(
        'operator_id' => 'field_profile_staff_value_op',
        'label' => 'Staff Member (field_profile_staff)',
        'operator' => 'field_profile_staff_value_op',
        'identifier' => 'field_profile_staff_value',
        'remember_roles' => array(
          2 => 2,
          1 => 0,
          5 => 0,
          4 => 0,
          3 => 0,
          6 => 0,
        ),
      ),
    ),
  );
  $overrides["views_view.profile_list.display|page_1|display_options|path"] = 'about/staff-directory';
  $overrides["views_view.profile_list.display|page_1|display_options|relationships"] = array(
    'nodequeue_rel' => array(
      'id' => 'nodequeue_rel',
      'table' => 'node',
      'field' => 'nodequeue_rel',
      'required' => TRUE,
      'limit' => 1,
      'names' => array(
        'staff' => 'staff',
        'leadership' => 0,
      ),
    ),
  );
  $overrides["views_view.profile_list.display|page_1|display_options|row_options"] = array(
    'card_title' => 'entity_id_6',
    'card_name' => 'entity_id_6',
    'card_link' => 'nid',
    'card_image' => 'entity_id_9',
    'card_framed' => 'nothing',
  );
  $overrides["views_view.profile_list.display|page_1|display_options|row_plugin"] = 'person_fields';
  $overrides["views_view.profile_list.display|page_1|display_options|style_options"] = array(
    'columns' => 3,
  );
  $overrides["views_view.profile_list.display|page_1|display_options|style_plugin"] = 'card';
  $overrides["views_view.profile_list.display|page_2|display_options|defaults|pager"] = FALSE;
  $overrides["views_view.profile_list.display|page_2|display_options|defaults|row_options"] = FALSE;
  $overrides["views_view.profile_list.display|page_2|display_options|defaults|row_plugin"] = FALSE;
  $overrides["views_view.profile_list.display|page_2|display_options|defaults|style_options"] = FALSE;
  $overrides["views_view.profile_list.display|page_2|display_options|defaults|style_plugin"] = FALSE;
  $overrides["views_view.profile_list.display|page_2|display_options|filters|field_profile_staff_value"]["DELETED"] = TRUE;
  $overrides["views_view.profile_list.display|page_2|display_options|pager"] = array(
    'type' => 'some',
    'options' => array(
      'items_per_page' => 12,
    ),
  );
  $overrides["views_view.profile_list.display|page_2|display_options|path"] = 'about/leadership';
  $overrides["views_view.profile_list.display|page_2|display_options|relationships"] = array(
    'nodequeue_rel' => array(
      'id' => 'nodequeue_rel',
      'table' => 'node',
      'field' => 'nodequeue_rel',
      'required' => TRUE,
      'limit' => 1,
      'names' => array(
        'leadership' => 'leadership',
      ),
    ),
  );
  $overrides["views_view.profile_list.display|page_2|display_options|row_options"] = array(
    'card_title' => 'entity_id_6',
    'card_name' => 'title',
    'card_link' => 'nid',
    'card_image' => 'entity_id_9',
    'card_framed' => 'nothing',
  );
  $overrides["views_view.profile_list.display|page_2|display_options|row_plugin"] = 'person_fields';
  $overrides["views_view.profile_list.display|page_2|display_options|sorts|field_profile_last_name_value"]["DELETED"] = TRUE;
  $overrides["views_view.profile_list.display|page_2|display_options|sorts|position"] = array(
    'id' => 'position',
    'table' => 'nodequeue_nodes',
    'field' => 'position',
    'relationship' => 'nodequeue_rel',
  );
  $overrides["views_view.profile_list.display|page_2|display_options|style_options"] = array(
    'columns' => 3,
  );
  $overrides["views_view.profile_list.display|page_2|display_options|style_plugin"] = 'card';

 return $overrides;
}
