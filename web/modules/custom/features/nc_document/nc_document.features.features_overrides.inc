<?php
/**
 * @file
 * nc_document.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function nc_document_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: field_instance
  $overrides["field_instance.node-document-body.display|basic_card"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-document-body.display|block_feature"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-document-body.display|default|settings|style_settings"] = array(
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
  $overrides["field_instance.node-document-body.display|default|weight"] = 4;
  $overrides["field_instance.node-document-body.display|teaser|settings|field_formatter_class"] = '';
  $overrides["field_instance.node-document-body.display|teaser|settings|style_settings"] = array(
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
  );
  $overrides["field_instance.node-document-body.display|teaser|settings|trim_length"] = 200;
  $overrides["field_instance.node-document-field_agency_department.display|basic_card"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-document-field_agency_department.display|block_feature"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-document-field_agency_department.display|default|label"] = 'hidden';
  $overrides["field_instance.node-document-field_agency_department.display|default|module"] = 'views_term_link_formatter';
  $overrides["field_instance.node-document-field_agency_department.display|default|settings|anchor_class"] = 'link';
  $overrides["field_instance.node-document-field_agency_department.display|default|settings|anchor_enabled"] = 1;
  $overrides["field_instance.node-document-field_agency_department.display|default|settings|field_formatter_class"]["DELETED"] = TRUE;
  $overrides["field_instance.node-document-field_agency_department.display|default|settings|style_settings|default_classes"] = 1;
  $overrides["field_instance.node-document-field_agency_department.display|default|settings|style_settings|wrapper|class"] = 'tags';
  $overrides["field_instance.node-document-field_agency_department.display|default|settings|views_view"] = 'nc_documents|page_1';
  $overrides["field_instance.node-document-field_agency_department.display|default|settings|wrapper"] = 'span';
  $overrides["field_instance.node-document-field_agency_department.display|default|settings|wrapper_class"] = 'label tag';
  $overrides["field_instance.node-document-field_agency_department.display|default|type"] = 'views_term_link_formatter_term_link';
  $overrides["field_instance.node-document-field_agency_department.display|default|weight"] = 8;
  $overrides["field_instance.node-document-field_agency_department.widget|weight"] = 4;
  $overrides["field_instance.node-document-field_author.node-document-field_author"]["DELETED"] = TRUE;
  $overrides["field_instance.node-document-field_document_attachment.display|basic_card"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-document-field_document_attachment.display|block_feature"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-document-field_document_attachment.display|default|module"] = 'nc_fields';
  $overrides["field_instance.node-document-field_document_attachment.display|default|settings|style_settings"] = array(
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
  $overrides["field_instance.node-document-field_document_attachment.display|default|type"] = 'nc_fields_file_formatter_detail';
  $overrides["field_instance.node-document-field_document_attachment.settings|file_extensions"] = 'pdf doc docx xls xlsx csv txt rtf html zip flv jpg jpeg png gif ppt pptx vsd rss wma wmv mov kmz';
  $overrides["field_instance.node-document-field_document_attachment.settings|max_filesize"] = '50MB';
  $overrides["field_instance.node-document-field_document_attachment.widget|settings|imce_filefield_on"] = 1;
  $overrides["field_instance.node-document-field_document_attachment.widget|weight"] = 8;
  $overrides["field_instance.node-document-field_related_content.display|basic_card"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-document-field_related_content.display|block_feature"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-document-field_related_content.display|default|label"] = 'above';
  $overrides["field_instance.node-document-field_related_content.display|default|settings|style_settings"] = array(
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
      'class' => 'section-title',
      'element' => 'h2',
      'suffix' => '',
    ),
    'wrapper' => array(
      'class' => '',
      'element' => 'div',
    ),
  );
  $overrides["field_instance.node-document-field_related_content.display|default|weight"] = 8;
  $overrides["field_instance.node-document-field_related_content.settings|validate_url"] = 0;
  $overrides["field_instance.node-document-field_related_content.widget|settings|validate_url"] = 0;

  // Exported overrides for: variable
  $overrides["variable.field_bundle_settings_node__document.value|extra_fields|display|language"] = array(
    'default' => array(
      'weight' => 6,
      'visible' => FALSE,
    ),
    'teaser' => array(
      'weight' => 5,
      'visible' => FALSE,
    ),
  );
  $overrides["variable.field_bundle_settings_node__document.value|extra_fields|form|language"] = array(
    'weight' => 0,
  );
  $overrides["variable.field_bundle_settings_node__document.value|extra_fields|form|path|weight"] = 9;
  $overrides["variable.field_bundle_settings_node__document.value|extra_fields|form|title|weight"] = 1;
  $overrides["variable.field_bundle_settings_node__document.value|view_modes|basic_card"] = array(
    'custom_settings' => TRUE,
  );
  $overrides["variable.field_bundle_settings_node__document.value|view_modes|block_feature"] = array(
    'custom_settings' => TRUE,
  );
  $overrides["variable.field_bundle_settings_node__document.value|view_modes|diff_standard"] = array(
    'custom_settings' => FALSE,
  );
  $overrides["variable.field_bundle_settings_node__document.value|view_modes|full"] = array(
    'custom_settings' => FALSE,
  );
  $overrides["variable.field_bundle_settings_node__document.value|view_modes|ical"] = array(
    'custom_settings' => FALSE,
  );
  $overrides["variable.field_bundle_settings_node__document.value|view_modes|rss"] = array(
    'custom_settings' => FALSE,
  );
  $overrides["variable.field_bundle_settings_node__document.value|view_modes|teaser"] = array(
    'custom_settings' => TRUE,
  );
  $overrides["variable.field_bundle_settings_node__document.value|view_modes|token"] = array(
    'custom_settings' => FALSE,
  );

 return $overrides;
}
