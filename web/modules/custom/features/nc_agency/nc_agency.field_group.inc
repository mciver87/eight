<?php
/**
 * @file
 * nc_agency.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function nc_agency_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_card|node|agency|form';
  $field_group->group_name = 'group_card';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'agency';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Info Card',
    'weight' => '1',
    'children' => array(
      0 => 'field_agency_card_description',
      1 => 'field_agency_card_link',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-card field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_card|node|agency|form'] = $field_group;

  return $export;
}
