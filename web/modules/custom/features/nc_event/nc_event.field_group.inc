<?php
/**
 * @file
 * nc_event.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function nc_event_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact|node|event|form';
  $field_group->group_name = 'group_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact',
    'weight' => '20',
    'children' => array(
      0 => 'field_event_contact_name',
      1 => 'field_event_contact_email',
      2 => 'field_event_contact_phone',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-contact field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_contact|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_contact|node|event|block_feature';
  $field_group->group_name = 'group_event_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'block_feature';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact:',
    'weight' => '16',
    'children' => array(
      0 => 'field_event_contact_email',
      1 => 'field_event_contact_name',
      2 => 'field_event_contact_phone',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Contact:',
      'instance_settings' => array(
        'classes' => 'when-where',
        'element' => 'section',
        'show_label' => '1',
        'label_element' => 'strong',
        'attributes' => 'organization',
      ),
    ),
  );
  $field_groups['group_event_contact|node|event|block_feature'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_files|node|event|default';
  $field_group->group_name = 'group_files';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Associated Files',
    'weight' => '2',
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
  $field_groups['group_files|node|event|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_organizer_info|node|event|block_feature';
  $field_group->group_name = 'group_organizer_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'block_feature';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Organizer',
    'weight' => '1',
    'children' => array(
      0 => 'field_external_url',
      1 => 'field_organizer',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Organizer',
      'instance_settings' => array(
        'classes' => 'organizer',
        'element' => 'section',
        'show_label' => '1',
        'label_element' => 'h3',
        'attributes' => 'section-title',
      ),
    ),
  );
  $field_groups['group_organizer_info|node|event|block_feature'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_organizer_info|node|event|default';
  $field_group->group_name = 'group_organizer_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Organizer',
    'weight' => '9',
    'children' => array(
      0 => 'field_external_url',
      1 => 'field_organizer',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Organizer',
      'instance_settings' => array(
        'classes' => 'organizer',
        'element' => 'section',
        'show_label' => '1',
        'label_element' => 'h3',
        'attributes' => 'section-title',
      ),
      'formatter' => '',
    ),
  );
  $field_groups['group_organizer_info|node|event|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_terms|node|event|default';
  $field_group->group_name = 'group_terms';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'This event is related to:',
    'weight' => '3',
    'children' => array(
      0 => 'field_event_terms',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'This event is related to:',
      'instance_settings' => array(
        'classes' => 'details group',
        'element' => 'section',
        'show_label' => '1',
        'label_element' => 'h3',
        'attributes' => '',
        'required_fields' => 1,
      ),
      'formatter' => '',
    ),
  );
  $field_groups['group_terms|node|event|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_when_where|node|event|block_feature';
  $field_group->group_name = 'group_when_where';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'block_feature';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'When and Where',
    'weight' => '0',
    'children' => array(
      0 => 'field_event_dates',
      1 => 'field_event_location',
      2 => 'field_cost',
      3 => 'field_external_url',
      4 => 'field_virtual_location',
      5 => 'field_organizer',
      6 => 'field_static_map',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'When and Where',
      'instance_settings' => array(
        'classes' => 'when-where',
        'element' => 'section',
        'show_label' => '1',
        'label_element' => 'h3',
        'attributes' => 'section-title',
        'required_fields' => 1,
      ),
      'formatter' => '',
    ),
  );
  $field_groups['group_when_where|node|event|block_feature'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_where_when|node|event|default';
  $field_group->group_name = 'group_where_when';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'When & Where',
    'weight' => '8',
    'children' => array(
      0 => 'field_event_dates',
      1 => 'field_event_location',
      2 => 'field_cost',
      3 => 'field_virtual_location',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'Where & When',
      'instance_settings' => array(
        'classes' => 'when-where',
        'element' => 'section',
        'show_label' => '1',
        'label_element' => 'h3',
        'attributes' => 'section-title',
      ),
      'formatter' => '',
    ),
  );
  $field_groups['group_where_when|node|event|default'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Contact');
  t('Contact:');
  t('Files');
  t('Organizer');
  t('This event is related to:');
  t('When & Where');
  t('When and Where');

  return $field_groups;
}
