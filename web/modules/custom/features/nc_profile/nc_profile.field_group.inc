<?php
/**
 * @file
 * nc_profile.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function nc_profile_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_profile_contact|node|profile|block_feature';
  $field_group->group_name = 'group_profile_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'profile';
  $field_group->mode = 'block_feature';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact',
    'weight' => '0',
    'children' => array(
      0 => 'field_profile_address',
      1 => 'field_profile_email',
      2 => 'field_profile_phone',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Contact',
      'instance_settings' => array(
        'classes' => '',
        'element' => '',
        'show_label' => '1',
        'label_element' => '',
        'attributes' => '',
      ),
    ),
  );
  $export['group_profile_contact|node|profile|block_feature'] = $field_group;

  return $export;
}
