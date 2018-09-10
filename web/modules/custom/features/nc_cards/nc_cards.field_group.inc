<?php
/**
 * @file
 * nc_cards.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function nc_cards_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_countup|bean|nc_card_animated_stat|form';
  $field_group->group_name = 'group_countup';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'nc_card_animated_stat';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Counter',
    'weight' => '5',
    'children' => array(
      0 => 'field_counter_prefix',
      1 => 'field_counter_suffix',
      2 => 'field_counter_duration',
      3 => 'field_counter_value',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Counter',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-countup field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_countup|bean|nc_card_animated_stat|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pie_and_donut|bean|nc_card_animated_stat|form';
  $field_group->group_name = 'group_pie_and_donut';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'nc_card_animated_stat';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Pie and Donut Charts',
    'weight' => '6',
    'children' => array(
      0 => 'field_chart_values',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Pie and Donut Charts',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-pie-and-donut field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_pie_and_donut|bean|nc_card_animated_stat|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Counter');
  t('Pie and Donut Charts');

  return $field_groups;
}
