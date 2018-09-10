<?php
/**
 * @file
 * nc_document.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function nc_document_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_details|node|document|default';
  $field_group->group_name = 'group_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'document';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '1',
    'children' => array(
      0 => 'body',
      1 => 'field_related_content',
      2 => 'field_published_date',
      3 => 'field_revised_date',
      4 => 'group_related',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Details',
      'instance_settings' => array(
        'classes' => 'group details',
        'element' => 'section',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_details|node|document|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_files|node|document|default';
  $field_group->group_name = 'group_files';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'document';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Associated Files',
    'weight' => '0',
    'children' => array(
      0 => 'field_document_attachment',
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
  $field_groups['group_files|node|document|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related|node|document|default';
  $field_group->group_name = 'group_related';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'document';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_details';
  $field_group->data = array(
    'label' => 'This resource is related to:',
    'weight' => '5',
    'children' => array(
      0 => 'field_document_collection',
      1 => 'field_document_type',
      2 => 'field_agency_department',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'This resource is related to:',
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
  $field_groups['group_related|node|document|default'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Details');
  t('Associated Files');
  t('This resource is related to:');

  return $field_groups;
}
