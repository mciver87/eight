<?php
/**
 * @file
 * nc_tax_type.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function nc_tax_type_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_meta|node|tax_type|teaser';
  $field_group->group_name = 'group_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tax_type';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Date and Category',
    'weight' => '0',
    'children' => array(
      0 => 'field_revised_date',
      1 => 'field_tax_category',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Date and Category',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-meta field-group-div meta',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_meta|node|tax_type|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related|node|tax_type|default';
  $field_group->group_name = 'group_related';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tax_type';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related group',
    'weight' => '4',
    'children' => array(
      0 => 'field_tax_category',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Related group',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-related field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_related|node|tax_type|default'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Date and Category');
  t('Related group');

  return $field_groups;
}
