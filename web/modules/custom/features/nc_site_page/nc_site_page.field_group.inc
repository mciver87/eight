<?php
/**
 * @file
 * nc_site_page.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function nc_site_page_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_files|node|site_page|default';
  $field_group->group_name = 'group_files';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'site_page';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Associated Files',
    'weight' => '4',
    'children' => array(
      0 => 'field_files',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Associated Files',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'files group',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'h2',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_files|node|site_page|default'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Associated Files');

  return $field_groups;
}
