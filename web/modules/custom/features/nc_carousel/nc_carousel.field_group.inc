<?php
/**
 * @file
 * nc_carousel.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function nc_carousel_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_autoplay|bean|nc_carousel|form';
  $field_group->group_name = 'group_autoplay';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'nc_carousel';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Autoplay Options',
    'weight' => '5',
    'children' => array(
      0 => 'field_carousel_autoplay_enabled',
      1 => 'field_carousel_autoplay_inverval',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-autoplay field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_autoplay|bean|nc_carousel|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Autoplay Options');

  return $field_groups;
}
