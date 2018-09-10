<?php
/**
 * @file
 * nc_catalog.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function nc_catalog_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_catalog_data|node|catalog|form';
  $field_group->group_name = 'group_catalog_data';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'catalog';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Catalog Data',
    'weight' => '5',
    'children' => array(
      0 => 'group_contact',
      1 => 'group_location',
      2 => 'group_media',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-catalog-data field-group-htabs',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_catalog_data|node|catalog|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact|node|catalog|form';
  $field_group->group_name = 'group_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'catalog';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_catalog_data';
  $field_group->data = array(
    'label' => 'Contact',
    'weight' => '12',
    'children' => array(
      0 => 'field_contacts',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-contact field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_contact|node|catalog|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_location|node|catalog|form';
  $field_group->group_name = 'group_location';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'catalog';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_catalog_data';
  $field_group->data = array(
    'label' => 'Location',
    'weight' => '14',
    'children' => array(
      0 => 'field_address',
      1 => 'field_county',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-location field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_location|node|catalog|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_media|node|catalog|form';
  $field_group->group_name = 'group_media';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'catalog';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_catalog_data';
  $field_group->data = array(
    'label' => 'Media',
    'weight' => '11',
    'children' => array(
      0 => 'field_icon',
      1 => 'field_main_image',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-media field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_media|node|catalog|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Catalog Data');
  t('Contact');
  t('Location');
  t('Media');

  return $field_groups;
}
