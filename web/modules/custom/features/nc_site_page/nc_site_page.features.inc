<?php
/**
 * @file
 * nc_site_page.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nc_site_page_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_field_default_field_bases_alter().
 */
function nc_site_page_field_default_field_bases_alter(&$data) {
  if (isset($data['field_files'])) {
    unset($data['field_files']['foreign keys']);
  }
  if (isset($data['field_related_content'])) {
    unset($data['field_related_content']['foreign keys']);
  }
}

/**
 * Implements hook_field_default_field_instances_alter().
 */
function nc_site_page_field_default_field_instances_alter(&$data) {
  if (isset($data['node-site_page-field_thumbnail_image'])) {
    $data['node-site_page-field_thumbnail_image']['display']['basic_card'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['node-site_page-field_files'])) {
    $data['node-site_page-field_files']['display']['basic_card'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-site_page-field_files']['display']['block_feature'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-site_page-field_files']['display']['default']['module'] = 'nc_fields'; /* WAS: 'file' */
    $data['node-site_page-field_files']['display']['default']['settings']['style_settings'] = array(
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
    $data['node-site_page-field_files']['display']['default']['type'] = 'nc_fields_file_formatter_detail'; /* WAS: 'file_default' */
    $data['node-site_page-field_files']['widget']['settings']['imce_filefield_on'] = 1; /* WAS: '' */
    $data['node-site_page-field_files']['widget']['weight'] = 6; /* WAS: 1 */
  }
  if (isset($data['node-site_page-field_related_content'])) {
    $data['node-site_page-field_related_content']['display']['default']['settings']['style_settings']['content']['element'] = 'div'; /* WAS: 'ul' */
    $data['node-site_page-field_related_content']['display']['default']['settings']['style_settings']['item']['element'] = 'div'; /* WAS: 'li' */
    $data['node-site_page-field_related_content']['display']['default']['settings']['style_settings']['title']['class'] = 'section-title'; /* WAS: '' */
    $data['node-site_page-field_related_content']['display']['default']['settings']['style_settings']['title']['element'] = 'h2'; /* WAS: 'h3' */
    $data['node-site_page-field_related_content']['display']['default']['settings']['style_settings']['title']['suffix'] = ''; /* WAS: ':' */
    $data['node-site_page-field_related_content']['widget']['weight'] = 7; /* WAS: 4 */
  }
}

/**
 * Implements hook_strongarm_alter().
 */
function nc_site_page_strongarm_alter(&$data) {
  if (isset($data['node_preview_site_page'])) {
    $data['node_preview_site_page']->value = 0; /* WAS: 1 */
  }
  if (isset($data['node_submitted_site_page'])) {
    $data['node_submitted_site_page']->value = 0; /* WAS: 1 */
  }
}
