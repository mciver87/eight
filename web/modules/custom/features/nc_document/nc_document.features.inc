<?php
/**
 * @file
 * nc_document.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nc_document_ctools_plugin_api($module = NULL, $api = NULL) {
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
function nc_document_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_field_default_field_instances_alter().
 */
function nc_document_field_default_field_instances_alter(&$data) {
  if (isset($data['node-document-body'])) {
    $data['node-document-body']['display']['basic_card'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-document-body']['display']['block_feature'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-document-body']['display']['default']['settings']['style_settings'] = array(
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
    $data['node-document-body']['display']['default']['weight'] = 4; /* WAS: 1 */
    $data['node-document-body']['display']['teaser']['settings']['field_formatter_class'] = ''; /* WAS: '' */
    $data['node-document-body']['display']['teaser']['settings']['style_settings'] = array(
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
    $data['node-document-body']['display']['teaser']['settings']['trim_length'] = 200; /* WAS: 600 */
  }
  if (isset($data['node-document-field_agency_department'])) {
    $data['node-document-field_agency_department']['display']['basic_card'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-document-field_agency_department']['display']['block_feature'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-document-field_agency_department']['display']['default']['label'] = 'hidden'; /* WAS: 'above' */
    $data['node-document-field_agency_department']['display']['default']['module'] = 'views_term_link_formatter'; /* WAS: 'taxonomy' */
    $data['node-document-field_agency_department']['display']['default']['settings']['anchor_class'] = 'link'; /* WAS: '' */
    $data['node-document-field_agency_department']['display']['default']['settings']['anchor_enabled'] = 1; /* WAS: '' */
    $data['node-document-field_agency_department']['display']['default']['settings']['style_settings']['default_classes'] = 1; /* WAS: TRUE */
    $data['node-document-field_agency_department']['display']['default']['settings']['style_settings']['wrapper']['class'] = 'tags'; /* WAS: '' */
    $data['node-document-field_agency_department']['display']['default']['settings']['views_view'] = 'nc_documents|page_1'; /* WAS: '' */
    $data['node-document-field_agency_department']['display']['default']['settings']['wrapper'] = 'span'; /* WAS: '' */
    $data['node-document-field_agency_department']['display']['default']['settings']['wrapper_class'] = 'label tag'; /* WAS: '' */
    $data['node-document-field_agency_department']['display']['default']['type'] = 'views_term_link_formatter_term_link'; /* WAS: 'taxonomy_term_reference_link' */
    $data['node-document-field_agency_department']['display']['default']['weight'] = 8; /* WAS: 6 */
    $data['node-document-field_agency_department']['widget']['weight'] = 4; /* WAS: 3 */
    unset($data['node-document-field_agency_department']['display']['default']['settings']['field_formatter_class']);
  }
  if (isset($data['node-document-field_author'])) {
    unset($data['node-document-field_author']);
  }
  if (isset($data['node-document-field_document_attachment'])) {
    $data['node-document-field_document_attachment']['display']['basic_card'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-document-field_document_attachment']['display']['block_feature'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-document-field_document_attachment']['display']['default']['module'] = 'nc_fields'; /* WAS: 'file' */
    $data['node-document-field_document_attachment']['display']['default']['settings']['style_settings'] = array(
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
    $data['node-document-field_document_attachment']['display']['default']['type'] = 'nc_fields_file_formatter_detail'; /* WAS: 'file_default' */
    $data['node-document-field_document_attachment']['settings']['file_extensions'] = 'pdf doc docx xls xlsx csv txt rtf html zip flv jpg jpeg png gif ppt pptx vsd rss wma wmv mov kmz'; /* WAS: 'pdf doc docx xls xlsx csv txt rtf html zip flv jpg jpeg png gif ppt pptx vsd' */
    $data['node-document-field_document_attachment']['settings']['max_filesize'] = '50MB'; /* WAS: '' */
    $data['node-document-field_document_attachment']['widget']['settings']['imce_filefield_on'] = 1; /* WAS: '' */
    $data['node-document-field_document_attachment']['widget']['weight'] = 8; /* WAS: 3 */
  }
  if (isset($data['node-document-field_related_content'])) {
    $data['node-document-field_related_content']['display']['basic_card'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-document-field_related_content']['display']['block_feature'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-document-field_related_content']['display']['default']['label'] = 'above'; /* WAS: 'hidden' */
    $data['node-document-field_related_content']['display']['default']['settings']['style_settings'] = array(
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
    ); /* WAS: '' */
    $data['node-document-field_related_content']['display']['default']['weight'] = 8; /* WAS: 3 */
    $data['node-document-field_related_content']['settings']['validate_url'] = 0; /* WAS: 1 */
    $data['node-document-field_related_content']['widget']['settings']['validate_url'] = 0; /* WAS: '' */
  }
}

/**
 * Implements hook_strongarm_alter().
 */
function nc_document_strongarm_alter(&$data) {
  if (isset($data['field_bundle_settings_node__document'])) {
    $data['field_bundle_settings_node__document']->value['extra_fields']['display']['language'] = array(
      'default' => array(
        'weight' => 6,
        'visible' => FALSE,
      ),
      'teaser' => array(
        'weight' => 5,
        'visible' => FALSE,
      ),
    ); /* WAS: '' */
    $data['field_bundle_settings_node__document']->value['extra_fields']['form']['language'] = array(
      'weight' => 0,
    ); /* WAS: '' */
    $data['field_bundle_settings_node__document']->value['extra_fields']['form']['path']['weight'] = 9; /* WAS: 4 */
    $data['field_bundle_settings_node__document']->value['extra_fields']['form']['title']['weight'] = 1; /* WAS: 0 */
    $data['field_bundle_settings_node__document']->value['view_modes']['basic_card'] = array(
      'custom_settings' => TRUE,
    ); /* WAS: '' */
    $data['field_bundle_settings_node__document']->value['view_modes']['block_feature'] = array(
      'custom_settings' => TRUE,
    ); /* WAS: '' */
    $data['field_bundle_settings_node__document']->value['view_modes']['diff_standard'] = array(
      'custom_settings' => FALSE,
    ); /* WAS: '' */
    $data['field_bundle_settings_node__document']->value['view_modes']['full'] = array(
      'custom_settings' => FALSE,
    ); /* WAS: '' */
    $data['field_bundle_settings_node__document']->value['view_modes']['ical'] = array(
      'custom_settings' => FALSE,
    ); /* WAS: '' */
    $data['field_bundle_settings_node__document']->value['view_modes']['rss'] = array(
      'custom_settings' => FALSE,
    ); /* WAS: '' */
    $data['field_bundle_settings_node__document']->value['view_modes']['teaser'] = array(
      'custom_settings' => TRUE,
    ); /* WAS: '' */
    $data['field_bundle_settings_node__document']->value['view_modes']['token'] = array(
      'custom_settings' => FALSE,
    ); /* WAS: '' */
  }
}
