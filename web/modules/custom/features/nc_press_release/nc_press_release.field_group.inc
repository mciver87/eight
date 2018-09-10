<?php
/**
 * @file
 * nc_press_release.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function nc_press_release_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_details|node|press_release|default';
  $field_group->group_name = 'group_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'press_release';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '2',
    'children' => array(
      0 => 'body',
      1 => 'field_release_date',
      2 => 'field_city_location',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Details',
      'instance_settings' => array(
        'classes' => 'details group',
        'element' => 'section',
        'show_label' => '0',
        'label_element' => 'h2',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_details|node|press_release|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_files|node|press_release|default';
  $field_group->group_name = 'group_files';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'press_release';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Associated Files',
    'weight' => '4',
    'children' => array(
      0 => 'field_files',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Associated Files',
      'instance_settings' => array(
        'classes' => 'files group',
        'element' => 'section',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_files|node|press_release|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_terms|node|press_release|default';
  $field_group->group_name = 'group_terms';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'press_release';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'This press release is related to:',
    'weight' => '3',
    'children' => array(
      0 => 'field_agency_department',
      1 => 'field_press_release_terms',
      2 => 'field_related_content',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'This press release is related to:',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-terms field-group-div tags group',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_terms|node|press_release|default'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Details');
  t('Files');
  t('This press release is related to:');

  return $field_groups;
}
