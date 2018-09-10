<?php
/**
 * @file
 * nc_osbm_document.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function nc_osbm_document_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_statistics|node|document|form';
  $field_group->group_name = 'group_statistics';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'document';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Statistics',
    'weight' => '27',
    'children' => array(
      0 => 'field_data_topic',
      1 => 'field_data_race',
      2 => 'field_data_sex',
      3 => 'field_data_type',
      4 => 'field_data_year',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-statistics field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_statistics|node|document|form'] = $field_group;

  return $export;
}
