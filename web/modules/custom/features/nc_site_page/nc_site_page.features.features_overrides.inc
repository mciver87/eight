<?php
/**
 * @file
 * nc_site_page.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function nc_site_page_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: field_instance
  $overrides["field_instance.node-site_page-body.display|basic_card"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-site_page-body.widget|weight"] = 3;
  $overrides["field_instance.node-site_page-field_files.display|basic_card"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-site_page-field_files.display|default|module"] = 'nc_fields';
  $overrides["field_instance.node-site_page-field_files.display|block_feature"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-site_page-field_files.display|default|settings|style_settings"] = array(
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
  $overrides["field_instance.node-site_page-field_thumbnail_image.display|basic_card"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-site_page-field_files.display|default|type"] = 'nc_fields_file_formatter_detail';
  $overrides["field_instance.node-site_page-field_files.widget|settings|imce_filefield_on"] = 1;
  $overrides["field_instance.node-site_page-field_files.widget|weight"] = 6;
    $overrides["field_instance.node-site_page-field_related_content.display|default|settings|style_settings|content|element"] = 'div';
  $overrides["field_instance.node-site_page-field_related_content.display|default|settings|style_settings|item|element"] = 'div';
  $overrides["field_instance.node-site_page-field_related_content.display|default|settings|style_settings|title|class"] = 'section-title';
  $overrides["field_instance.node-site_page-field_related_content.display|default|settings|style_settings|title|element"] = 'h2';
  $overrides["field_instance.node-site_page-field_related_content.display|default|settings|style_settings|title|suffix"] = '';
  $overrides["field_instance.node-site_page-field_related_content.widget|weight"] = 7;
  $overrides["field_instance.node-site_page-field_related_content.settings|validate_url"] = 0;
  $overrides["field_instance.node-site_page-field_related_content.widget|settings|validate_url"] = 0;

  $overrides["variable.node_preview_site_page.value"] = 0;

 return $overrides;
}
