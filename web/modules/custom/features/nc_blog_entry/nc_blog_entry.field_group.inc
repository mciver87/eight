<?php
/**
 * @file
 * nc_blog_entry.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function nc_blog_entry_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_files|node|blog_entry|default';
  $field_group->group_name = 'group_files';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'blog_entry';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Associated Files',
    'weight' => '5',
    'children' => array(
      0 => 'field_files',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Associated Files',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'files group',
        'element' => 'section',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_files|node|blog_entry|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related|node|blog_entry|default';
  $field_group->group_name = 'group_related';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'blog_entry';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'This post is related to:',
    'weight' => '4',
    'children' => array(
      0 => 'field_blog_category',
      1 => 'field_blog_terms',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'This post is related to:',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-related field-group-div tags group',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_related|node|blog_entry|default'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Associated Files');
  t('This post is related to:');

  return $field_groups;
}
