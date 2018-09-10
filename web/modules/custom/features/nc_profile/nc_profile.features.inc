<?php
/**
 * @file
 * nc_profile.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nc_profile_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_context_default_contexts_alter().
 */
function nc_profile_context_default_contexts_alter(&$data) {
  if (isset($data['profile_page'])) {
    $data['profile_page']->hidden = 0; /* WAS: '' */
    $data['profile_page']->reactions['block']['blocks']['bean-nc_profile_node_block_featured'] = array(
      'module' => 'bean',
      'delta' => 'nc_profile_node_block_featured',
      'region' => 'sidebar_second',
      'weight' => 0,
    ); /* WAS: '' */
    $data['profile_page']->tag = 'Content Types'; /* WAS: '' */
  }
}

/**
 * Implements hook_field_default_field_instances_alter().
 */
function nc_profile_field_default_field_instances_alter(&$data) {
  if (isset($data['node-profile-body'])) {
    $data['node-profile-body']['display']['basic_card'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 15,
    ); /* WAS: '' */
    $data['node-profile-body']['display']['block_feature'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-profile-body']['display']['default']['settings']['style_settings'] = array(
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
    ); /* WAS: '' */
    $data['node-profile-body']['display']['default']['weight'] = 5; /* WAS: 3 */
    $data['node-profile-body']['display']['teaser']['settings']['style_settings'] = array(
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
  }
  if (isset($data['node-profile-field_profile_address'])) {
    $data['node-profile-field_profile_address']['display']['basic_card'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 11,
    ); /* WAS: '' */
    $data['node-profile-field_profile_address']['display']['block_feature'] = array(
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
    ); /* WAS: '' */
    $data['node-profile-field_profile_address']['display']['default']['type'] = 'hidden'; /* WAS: 'text_default' */
    $data['node-profile-field_profile_address']['display']['default']['weight'] = 2; /* WAS: 12 */
    unset($data['node-profile-field_profile_address']['display']['default']['module']);
  }
  if (isset($data['node-profile-field_profile_department'])) {
    $data['node-profile-field_profile_department']['display']['basic_card'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 12,
    ); /* WAS: '' */
    $data['node-profile-field_profile_department']['display']['block_feature'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-profile-field_profile_department']['display']['default']['weight'] = 8; /* WAS: 5 */
  }
  if (isset($data['node-profile-field_profile_division'])) {
    $data['node-profile-field_profile_division']['display']['basic_card'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 13,
    ); /* WAS: '' */
    $data['node-profile-field_profile_division']['display']['block_feature'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-profile-field_profile_division']['display']['default']['type'] = 'hidden'; /* WAS: 'text_default' */
    $data['node-profile-field_profile_division']['display']['default']['weight'] = 15; /* WAS: 14 */
    unset($data['node-profile-field_profile_division']['display']['default']['module']);
  }
  if (isset($data['node-profile-field_profile_email'])) {
    $data['node-profile-field_profile_email']['display']['basic_card'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 14,
    ); /* WAS: '' */
    $data['node-profile-field_profile_email']['display']['block_feature'] = array(
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
    ); /* WAS: '' */
    $data['node-profile-field_profile_email']['display']['default']['weight'] = 13; /* WAS: 10 */
  }
  if (isset($data['node-profile-field_profile_first_name'])) {
    $data['node-profile-field_profile_first_name']['display']['basic_card'] = array(
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
    ); /* WAS: '' */
    $data['node-profile-field_profile_first_name']['display']['block_feature'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-profile-field_profile_first_name']['display']['default']['weight'] = 9; /* WAS: 6 */
  }
  if (isset($data['node-profile-field_profile_job_title'])) {
    $data['node-profile-field_profile_job_title']['display']['basic_card'] = array(
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
    ); /* WAS: '' */
    $data['node-profile-field_profile_job_title']['display']['block_feature'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-profile-field_profile_job_title']['display']['default']['type'] = 'hidden'; /* WAS: 'text_default' */
    $data['node-profile-field_profile_job_title']['display']['default']['weight'] = 0; /* WAS: 1 */
    unset($data['node-profile-field_profile_job_title']['display']['default']['module']);
  }
  if (isset($data['node-profile-field_profile_last_name'])) {
    $data['node-profile-field_profile_last_name']['display']['basic_card'] = array(
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
    ); /* WAS: '' */
    $data['node-profile-field_profile_last_name']['display']['block_feature'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-profile-field_profile_last_name']['display']['default']['weight'] = 11; /* WAS: 8 */
  }
  if (isset($data['node-profile-field_profile_leadership'])) {
    $data['node-profile-field_profile_leadership']['display']['basic_card'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 10,
    ); /* WAS: '' */
    $data['node-profile-field_profile_leadership']['display']['block_feature'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-profile-field_profile_leadership']['display']['default']['type'] = 'hidden'; /* WAS: 'list_default' */
    $data['node-profile-field_profile_leadership']['display']['default']['weight'] = 4; /* WAS: 0 */
    unset($data['node-profile-field_profile_leadership']['display']['default']['module']);
  }
  if (isset($data['node-profile-field_profile_organization'])) {
    $data['node-profile-field_profile_organization']['display']['basic_card'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 9,
    ); /* WAS: '' */
    $data['node-profile-field_profile_organization']['display']['block_feature'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-profile-field_profile_organization']['display']['default']['type'] = 'hidden'; /* WAS: 'text_default' */
    $data['node-profile-field_profile_organization']['display']['default']['weight'] = 14; /* WAS: 11 */
    unset($data['node-profile-field_profile_organization']['display']['default']['module']);
  }
  if (isset($data['node-profile-field_profile_phone'])) {
    $data['node-profile-field_profile_phone']['display']['basic_card'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 5,
    ); /* WAS: '' */
    $data['node-profile-field_profile_phone']['display']['block_feature'] = array(
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
    ); /* WAS: '' */
    $data['node-profile-field_profile_phone']['display']['default']['weight'] = 7; /* WAS: 4 */
  }
  if (isset($data['node-profile-field_profile_photo'])) {
    $data['node-profile-field_profile_photo']['display']['basic_card'] = array(
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
    ); /* WAS: '' */
    $data['node-profile-field_profile_photo']['display']['block_feature'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-profile-field_profile_photo']['display']['default']['settings']['image_style'] = 'profile_wide'; /* WAS: '' */
    $data['node-profile-field_profile_photo']['display']['default']['settings']['style_settings'] = array(
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
    ); /* WAS: '' */
    $data['node-profile-field_profile_photo']['display']['default']['weight'] = 1; /* WAS: 2 */
    $data['node-profile-field_profile_photo']['widget']['settings']['filefield_sources'] = array(
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
  }
  if (isset($data['node-profile-field_profile_social_media'])) {
    $data['node-profile-field_profile_social_media']['display']['basic_card'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 4,
    ); /* WAS: '' */
    $data['node-profile-field_profile_social_media']['display']['block_feature'] = array(
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
    ); /* WAS: '' */
    $data['node-profile-field_profile_social_media']['display']['default']['type'] = 'hidden'; /* WAS: 'text_default' */
    $data['node-profile-field_profile_social_media']['display']['default']['weight'] = 3; /* WAS: 13 */
    unset($data['node-profile-field_profile_social_media']['display']['default']['module']);
  }
  if (isset($data['node-profile-field_profile_staff'])) {
    $data['node-profile-field_profile_staff']['display']['basic_card'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 6,
    ); /* WAS: '' */
    $data['node-profile-field_profile_staff']['display']['block_feature'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-profile-field_profile_staff']['display']['default']['weight'] = 10; /* WAS: 7 */
  }
  if (isset($data['node-profile-field_profile_user'])) {
    $data['node-profile-field_profile_user']['display']['basic_card'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 7,
    ); /* WAS: '' */
    $data['node-profile-field_profile_user']['display']['block_feature'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-profile-field_profile_user']['display']['default']['weight'] = 12; /* WAS: 9 */
  }
}

/**
 * Implements hook_strongarm_alter().
 */
function nc_profile_strongarm_alter(&$data) {
  if (isset($data['field_bundle_settings_node__profile'])) {
    $data['field_bundle_settings_node__profile']->value['extra_fields']['display']['language'] = array(
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
    ); /* WAS: '' */
    $data['field_bundle_settings_node__profile']->value['view_modes']['block_feature'] = array(
      'custom_settings' => TRUE,
    ); /* WAS: '' */
  }
  if (isset($data['node_preview_profile'])) {
    $data['node_preview_profile']->value = 0; /* WAS: 1 */
  }
}

/**
 * Implements hook_views_default_views_alter().
 */
function nc_profile_views_default_views_alter(&$data) {
  if (isset($data['profile_list'])) {
    $data['profile_list']->display['block_2'] = unserialize('O:13:"views_display":7:{s:15:"display_options";a:7:{s:5:"query";a:2:{s:4:"type";s:11:"views_query";s:7:"options";a:0:{}}s:8:"defaults";a:5:{s:5:"pager";b:0;s:12:"style_plugin";b:0;s:13:"style_options";b:0;s:10:"row_plugin";b:0;s:11:"row_options";b:0;}s:5:"pager";a:2:{s:4:"type";s:4:"some";s:7:"options";a:2:{s:14:"items_per_page";s:1:"2";s:6:"offset";s:1:"0";}}s:12:"style_plugin";s:4:"card";s:13:"style_options";a:2:{s:7:"columns";s:1:"1";s:7:"padding";i:1;}s:10:"row_plugin";s:13:"person_fields";s:11:"row_options";a:5:{s:10:"card_title";s:11:"entity_id_6";s:9:"card_name";s:5:"title";s:9:"card_link";s:3:"nid";s:10:"card_image";s:11:"entity_id_9";s:11:"card_framed";s:7:"nothing";}}s:8:"db_table";s:13:"views_display";s:3:"vid";i:0;s:2:"id";s:7:"block_2";s:13:"display_title";s:27:"Leadership Block - 2 Column";s:14:"display_plugin";s:5:"block";s:8:"position";i:0;}'); /* WAS: '' */
    $data['profile_list']->display['block_3'] = unserialize('O:13:"views_display":7:{s:15:"display_options";a:8:{s:5:"query";a:2:{s:4:"type";s:11:"views_query";s:7:"options";a:0:{}}s:8:"defaults";a:6:{s:12:"link_display";b:0;s:5:"pager";b:0;s:12:"style_plugin";b:0;s:13:"style_options";b:0;s:10:"row_plugin";b:0;s:11:"row_options";b:0;}s:12:"link_display";s:6:"page_2";s:5:"pager";a:2:{s:4:"type";s:4:"some";s:7:"options";a:2:{s:14:"items_per_page";s:1:"4";s:6:"offset";s:1:"0";}}s:12:"style_plugin";s:4:"card";s:13:"style_options";a:2:{s:7:"columns";s:1:"3";s:7:"padding";i:1;}s:10:"row_plugin";s:13:"person_fields";s:11:"row_options";a:5:{s:10:"card_title";s:11:"entity_id_6";s:9:"card_name";s:5:"title";s:9:"card_link";s:3:"nid";s:10:"card_image";s:11:"entity_id_9";s:11:"card_framed";s:7:"nothing";}}s:8:"db_table";s:13:"views_display";s:3:"vid";i:0;s:2:"id";s:7:"block_3";s:13:"display_title";s:27:"Leadership Block - 4 Column";s:14:"display_plugin";s:5:"block";s:8:"position";i:0;}'); /* WAS: '' */
    $data['profile_list']->display['default']->display_options['fields']['entity_id_9']['element_label_colon'] = FALSE; /* WAS: '' */
    $data['profile_list']->display['default']->display_options['fields']['entity_id_9']['settings']['image_link'] = ''; /* WAS: 'content' */
    $data['profile_list']->display['default']->display_options['fields']['entity_id_9']['settings']['image_style'] = 'card_photo'; /* WAS: 'list-page-thumbnail' */
    $data['profile_list']->display['default']->display_options['fields']['entity_id_9']['settings']['style_settings'] = array(
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
    $data['profile_list']->display['default']->display_options['fields']['nid'] = array(
      'id' => 'nid',
      'table' => 'node',
      'field' => 'nid',
      'label' => 'Link',
      'alter' => array(
        'alter_text' => TRUE,
        'text' => 'node/[nid]',
      ),
    ); /* WAS: '' */
    $data['profile_list']->display['default']->display_options['fields']['nothing'] = array(
      'id' => 'nothing',
      'table' => 'views',
      'field' => 'nothing',
      'label' => 'Framed',
      'alter' => array(
        'text' => 1,
        'trim_whitespace' => TRUE,
        'strip_tags' => TRUE,
      ),
    ); /* WAS: '' */
    $data['profile_list']->display['default']->display_options['fields']['title'] = array(
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'label' => 'Title only',
      'element_label_colon' => FALSE,
      'link_to_node' => FALSE,
    ); /* WAS: '' */
    $data['profile_list']->display['default']->display_options['pager']['options'] = array(
      'items_per_page' => 12,
    ); /* WAS: '' */
    $data['profile_list']->display['default']->display_options['relationships'] = array(
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
    ); /* WAS: '' */
    $data['profile_list']->display['default']->display_options['sorts'] = array(
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
    ); /* WAS: '' */
    $data['profile_list']->display['default']->display_options['style_plugin'] = 'list'; /* WAS: 'default' */
    $data['profile_list']->display['page_1']->display_options['defaults'] = array(
      'style_plugin' => FALSE,
      'style_options' => FALSE,
      'row_plugin' => FALSE,
      'row_options' => FALSE,
      'relationships' => FALSE,
      'arguments' => FALSE,
      'filter_groups' => FALSE,
      'filters' => FALSE,
    ); /* WAS: '' */
    $data['profile_list']->display['page_1']->display_options['filters'] = array(
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
    ); /* WAS: '' */
    $data['profile_list']->display['page_1']->display_options['path'] = 'about/staff-directory'; /* WAS: 'staff-directory' */
    $data['profile_list']->display['page_1']->display_options['relationships'] = array(
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
    ); /* WAS: '' */
    $data['profile_list']->display['page_1']->display_options['row_options'] = array(
      'card_title' => 'entity_id_6',
      'card_name' => 'entity_id_6',
      'card_link' => 'nid',
      'card_image' => 'entity_id_9',
      'card_framed' => 'nothing',
    ); /* WAS: '' */
    $data['profile_list']->display['page_1']->display_options['row_plugin'] = 'person_fields'; /* WAS: '' */
    $data['profile_list']->display['page_1']->display_options['style_options'] = array(
      'columns' => 3,
    ); /* WAS: '' */
    $data['profile_list']->display['page_1']->display_options['style_plugin'] = 'card'; /* WAS: '' */
    $data['profile_list']->display['page_2']->display_options['defaults']['pager'] = FALSE; /* WAS: '' */
    $data['profile_list']->display['page_2']->display_options['defaults']['row_options'] = FALSE; /* WAS: '' */
    $data['profile_list']->display['page_2']->display_options['defaults']['row_plugin'] = FALSE; /* WAS: '' */
    $data['profile_list']->display['page_2']->display_options['defaults']['style_options'] = FALSE; /* WAS: '' */
    $data['profile_list']->display['page_2']->display_options['defaults']['style_plugin'] = FALSE; /* WAS: '' */
    $data['profile_list']->display['page_2']->display_options['pager'] = array(
      'type' => 'some',
      'options' => array(
        'items_per_page' => 12,
      ),
    ); /* WAS: '' */
    $data['profile_list']->display['page_2']->display_options['path'] = 'about/leadership'; /* WAS: 'staff-directory/leadership' */
    $data['profile_list']->display['page_2']->display_options['relationships'] = array(
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
    ); /* WAS: '' */
    $data['profile_list']->display['page_2']->display_options['row_options'] = array(
      'card_title' => 'entity_id_6',
      'card_name' => 'title',
      'card_link' => 'nid',
      'card_image' => 'entity_id_9',
      'card_framed' => 'nothing',
    ); /* WAS: '' */
    $data['profile_list']->display['page_2']->display_options['row_plugin'] = 'person_fields'; /* WAS: '' */
    $data['profile_list']->display['page_2']->display_options['sorts']['position'] = array(
      'id' => 'position',
      'table' => 'nodequeue_nodes',
      'field' => 'position',
      'relationship' => 'nodequeue_rel',
    ); /* WAS: '' */
    $data['profile_list']->display['page_2']->display_options['style_options'] = array(
      'columns' => 3,
    ); /* WAS: '' */
    $data['profile_list']->display['page_2']->display_options['style_plugin'] = 'card'; /* WAS: '' */
    unset($data['profile_list']->display['default']->display_options['fields']['title_1']);
    unset($data['profile_list']->display['page_2']->display_options['filters']['field_profile_staff_value']);
    unset($data['profile_list']->display['page_2']->display_options['sorts']['field_profile_last_name_value']);
  }
}

/**
 * Implements hook_image_default_styles().
 */
function nc_profile_image_default_styles() {
  $styles = array();

  // Exported image style: profile_wide.
  $styles['profile_wide'] = array(
    'name' => 'profile_wide',
    'label' => 'Profile Wide',
    'effects' => array(
      6 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1140,
          'height' => 654,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_microdata_mappings_defaults().
 */
function nc_profile_microdata_mappings_defaults() {
  $microdata_mappings = array();

  // Exported Microdata mapping: profile
  $microdata_mappings['node']['profile'] = array(
    '#itemtype' => array(
      0 => 'http://schema.org/Person',
    ),
    'title' => array(
      '#itemprop' => array(
        0 => 'name',
      ),
    ),
    '#is_item' => TRUE,
    '#itemid_token' => '[node:url]',
    '#use_schema_url' => 1,
    'body' => array(
      '#itemprop' => array(),
      '#is_item' => FALSE,
      'value' => array(
        '#itemprop' => array(
          0 => 'description',
        ),
        '#itemtype' => '',
      ),
      'summary' => array(
        '#itemprop' => array(),
        '#itemtype' => '',
      ),
    ),
    'field_profile_address' => array(
      '#itemprop' => array(
        0 => 'workLocation',
      ),
      '#is_item' => FALSE,
    ),
    'field_profile_department' => array(
      '#itemprop' => array(),
      '#is_item' => FALSE,
    ),
    'field_profile_division' => array(
      '#itemprop' => array(),
      '#is_item' => FALSE,
    ),
    'field_profile_email' => array(
      '#itemprop' => array(
        0 => 'email',
      ),
      '#is_item' => FALSE,
    ),
    'field_profile_first_name' => array(
      '#itemprop' => array(
        0 => 'givenName',
      ),
      '#is_item' => FALSE,
    ),
    'field_profile_job_title' => array(
      '#itemprop' => array(
        0 => 'jobTitle',
      ),
      '#is_item' => FALSE,
    ),
    'field_profile_last_name' => array(
      '#itemprop' => array(
        0 => 'familyName',
      ),
      '#is_item' => FALSE,
    ),
    'field_profile_organization' => array(
      '#itemprop' => array(
        0 => 'worksFor',
      ),
      '#is_item' => FALSE,
    ),
    'field_profile_phone' => array(
      '#itemprop' => array(
        0 => 'telephone',
      ),
      '#is_item' => FALSE,
    ),
    'field_profile_photo' => array(
      '#itemprop' => array(
        0 => 'image',
      ),
      '#is_item' => FALSE,
    ),
    'field_profile_social_media' => array(
      '#itemprop' => array(),
      '#is_item' => FALSE,
    ),
  );

  return $microdata_mappings;
}
