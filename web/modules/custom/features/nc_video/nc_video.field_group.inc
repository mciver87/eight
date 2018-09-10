<?php
/**
 * @file
 * nc_video.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function nc_video_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related|node|video|default';
  $field_group->group_name = 'group_related';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'video';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'This post is related to:',
    'weight' => '3',
    'children' => array(
      0 => 'field_video_terms',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'This post is related to:',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-related field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_related|node|video|default'] = $field_group;

  return $export;
}
