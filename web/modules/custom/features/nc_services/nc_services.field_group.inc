<?php
/**
 * @file
 * nc_services.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function nc_services_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_details|node|services|default';
  $field_group->group_name = 'group_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'services';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '4',
    'children' => array(
      0 => 'group_related',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Details',
      'instance_settings' => array(
        'classes' => 'details group',
        'element' => 'section',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => '',
      ),
    ),
  );
  $export['group_details|node|services|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_files|node|services|default';
  $field_group->group_name = 'group_files';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'services';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Associated Files',
    'weight' => '3',
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
  $export['group_files|node|services|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related|node|services|default';
  $field_group->group_name = 'group_related';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'services';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_details';
  $field_group->data = array(
    'label' => 'This resource is related to:',
    'weight' => '10',
    'children' => array(
      0 => 'field_service_category',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'This resource is related to:',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'tags',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_related|node|services|default'] = $field_group;

  return $export;
}
