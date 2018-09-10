<?php
/**
 * @file
 * nc_agency.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function nc_agency_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: field_base
  $overrides["field_base.field_agency_category.cardinality"] = -1;

  // Exported overrides for: field_instance
  $overrides["field_instance.node-agency-field_agency_address.display|default|label"] = 'hidden';
  $overrides["field_instance.node-agency-field_agency_address.required"] = 0;
  $overrides["field_instance.node-agency-field_agency_category.display|basic_card|label"] = 'hidden';
  $overrides["field_instance.node-agency-field_agency_category.display|basic_card|module"] = 'taxonomy';
  $overrides["field_instance.node-agency-field_agency_category.display|basic_card|settings|style_settings"] = array(
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
  $overrides["field_instance.node-agency-field_agency_category.display|basic_card|type"] = 'taxonomy_term_reference_plain';
  $overrides["field_instance.node-agency-field_agency_category.display|default|label"] = 'hidden';
  $overrides["field_instance.node-agency-field_agency_category.display|default|module"] = 'nc_fields';
  $overrides["field_instance.node-agency-field_agency_category.display|default|type"] = 'nc_fields_term_formatter_simple';
  $overrides["field_instance.node-agency-field_agency_category.widget|type"] = 'options_buttons';
  $overrides["field_instance.node-agency-field_agency_email.display|default|label"] = 'hidden';
  $overrides["field_instance.node-agency-field_agency_email.display|default|type"] = 'email_plain';
  $overrides["field_instance.node-agency-field_agency_email.required"] = 0;
  $overrides["field_instance.node-agency-field_agency_phone.display|default|label"] = 'hidden';
  $overrides["field_instance.node-agency-field_agency_phone.label"] = 'Telephone';
  $overrides["field_instance.node-agency-field_agency_phone.settings|ca_phone_parentheses"] = 0;

  // Exported overrides for: views_view
  $overrides["views_view.agencies.display|default|display_options|arguments"] = array(
    'field_agency_category_tid' => array(
      'id' => 'field_agency_category_tid',
      'table' => 'field_data_field_agency_category',
      'field' => 'field_agency_category_tid',
      'default_argument_type' => 'fixed',
      'summary' => array(
        'format' => 'default_summary',
      ),
      'specify_validation' => TRUE,
      'validate' => array(
        'type' => 'taxonomy_term',
        'fail' => 'empty',
      ),
      'validate_options' => array(
        'vocabularies' => array(
          'agency_category' => 'agency_category',
        ),
        'type' => 'convert',
        'transform' => TRUE,
      ),
    ),
  );
  $overrides["views_view.agencies.display|default|display_options|css_class"] = 'results';
  $overrides["views_view.agencies.display|default|display_options|exposed_form|options"] = array(
    'reset_button' => TRUE,
  );
  $overrides["views_view.agencies.display|default|display_options|fields|body"] = array(
    'id' => 'body',
    'table' => 'field_data_body',
    'field' => 'body',
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
  );
  $overrides["views_view.agencies.display|default|display_options|fields|name"] = array(
    'id' => 'name',
    'table' => 'taxonomy_term_data',
    'field' => 'name',
    'relationship' => 'field_key_search_topics_tid',
    'label' => '',
    'element_label_colon' => FALSE,
  );
  $overrides["views_view.agencies.display|default|display_options|fields|title|element_label_colon"] = FALSE;
  $overrides["views_view.agencies.display|default|display_options|filters|combine"] = array(
    'id' => 'combine',
    'table' => 'views',
    'field' => 'combine',
    'operator' => 'contains',
    'group' => 1,
    'exposed' => TRUE,
    'expose' => array(
      'operator_id' => 'combine_op',
      'label' => 'Contains',
      'operator' => 'combine_op',
      'identifier' => 'combine',
      'remember_roles' => array(
        2 => 2,
        1 => 0,
        5 => 0,
        4 => 0,
        3 => 0,
        6 => 0,
      ),
    ),
    'fields' => array(
      'title' => 'title',
      'body' => 'body',
      'name' => 'name',
    ),
  );
  $overrides["views_view.agencies.display|default|display_options|filters|field_agency_category_tid"] = array(
    'id' => 'field_agency_category_tid',
    'table' => 'field_data_field_agency_category',
    'field' => 'field_agency_category_tid',
    'group' => 1,
    'exposed' => TRUE,
    'expose' => array(
      'operator_id' => 'field_agency_category_tid_op',
      'label' => 'Category',
      'operator' => 'field_agency_category_tid_op',
      'identifier' => 'field_agency_category_tid',
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
    'vocabulary' => 'agency_category',
  );
  $overrides["views_view.agencies.display|default|display_options|filters|field_top_level_agency_value"] = array(
    'id' => 'field_top_level_agency_value',
    'table' => 'field_data_field_top_level_agency',
    'field' => 'field_top_level_agency_value',
    'value' => array(
      1 => 1,
    ),
  );
  $overrides["views_view.agencies.display|default|display_options|filters|type|group"] = 1;
  $overrides["views_view.agencies.display|default|display_options|query|options|distinct"] = TRUE;
  $overrides["views_view.agencies.display|default|display_options|relationships"] = array(
    'field_key_search_topics_tid' => array(
      'id' => 'field_key_search_topics_tid',
      'table' => 'field_data_field_key_search_topics',
      'field' => 'field_key_search_topics_tid',
    ),
  );
  $overrides["views_view.agencies.display|default|display_options|row_options"] = array(
    'view_mode' => 'basic_card',
  );
  $overrides["views_view.agencies.display|default|display_options|sorts|created"]["DELETED"] = TRUE;
  $overrides["views_view.agencies.display|default|display_options|sorts|title"] = array(
    'id' => 'title',
    'table' => 'node',
    'field' => 'title',
  );
  $overrides["views_view.agencies.display|default|display_options|style_options"] = array(
    'default_row_class' => FALSE,
    'row_class_special' => FALSE,
    'uses_fields' => TRUE,
  );

 return $overrides;
}
