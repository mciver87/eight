<?php
/**
 * @file
 * nc_landing_page.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function nc_landing_page_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_left_middle|paragraphs_item|four_column|default';
  $field_group->group_name = 'group_left_middle';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'four_column';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Left Middle',
    'weight' => '5',
    'children' => array(
      0 => 'field_left_middle_block',
      1 => 'field_left_middle_markup',
      2 => 'field_left_middle_title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Left Middle',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_left_middle|paragraphs_item|four_column|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_left_middle|paragraphs_item|four_column|form';
  $field_group->group_name = 'group_left_middle';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'four_column';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Left Middle',
    'weight' => '2',
    'children' => array(
      0 => 'field_left_middle_title',
      1 => 'field_left_middle_block',
      2 => 'field_left_middle_markup',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Left Middle',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_left_middle|paragraphs_item|four_column|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_left_middle|paragraphs_item|four_column|paragraphs_editor_preview';
  $field_group->group_name = 'group_left_middle';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'four_column';
  $field_group->mode = 'paragraphs_editor_preview';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Left Middle',
    'weight' => '2',
    'children' => array(
      0 => 'field_left_middle_block',
      1 => 'field_left_middle_markup',
      2 => 'field_left_middle_title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Left Middle',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-left-middle field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_left_middle|paragraphs_item|four_column|paragraphs_editor_preview'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_left|paragraphs_item|four_column|default';
  $field_group->group_name = 'group_left';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'four_column';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Left',
    'weight' => '1',
    'children' => array(
      0 => 'field_left_block',
      1 => 'field_left_title',
      2 => 'field_left_markup',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Left',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_left|paragraphs_item|four_column|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_left|paragraphs_item|four_column|form';
  $field_group->group_name = 'group_left';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'four_column';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Left',
    'weight' => '1',
    'children' => array(
      0 => 'field_left_title',
      1 => 'field_left_block',
      2 => 'field_left_markup',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Left',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_left|paragraphs_item|four_column|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_left|paragraphs_item|four_column|paragraphs_editor_preview';
  $field_group->group_name = 'group_left';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'four_column';
  $field_group->mode = 'paragraphs_editor_preview';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Left',
    'weight' => '1',
    'children' => array(
      0 => 'field_left_block',
      1 => 'field_left_markup',
      2 => 'field_left_title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Left',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-left field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_left|paragraphs_item|four_column|paragraphs_editor_preview'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_left|paragraphs_item|three_column|default';
  $field_group->group_name = 'group_left';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'three_column';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Left',
    'weight' => '1',
    'children' => array(
      0 => 'field_left_block',
      1 => 'field_left_markup',
      2 => 'field_left_title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Left',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-left field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_left|paragraphs_item|three_column|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_left|paragraphs_item|three_column|form';
  $field_group->group_name = 'group_left';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'three_column';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Left',
    'weight' => '2',
    'children' => array(
      0 => 'field_left_block',
      1 => 'field_left_markup',
      2 => 'field_left_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Left',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_left|paragraphs_item|three_column|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_left|paragraphs_item|three_column|paragraphs_editor_preview';
  $field_group->group_name = 'group_left';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'three_column';
  $field_group->mode = 'paragraphs_editor_preview';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Left',
    'weight' => '1',
    'children' => array(
      0 => 'field_left_block',
      1 => 'field_left_markup',
      2 => 'field_left_title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Left',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-left field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_left|paragraphs_item|three_column|paragraphs_editor_preview'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_left|paragraphs_item|two_column|default';
  $field_group->group_name = 'group_left';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'two_column';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Left',
    'weight' => '1',
    'children' => array(
      0 => 'field_left_block',
      1 => 'field_left_markup',
      2 => 'field_left_title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Left',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-left field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_left|paragraphs_item|two_column|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_left|paragraphs_item|two_column|form';
  $field_group->group_name = 'group_left';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'two_column';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Left',
    'weight' => '3',
    'children' => array(
      0 => 'field_left_block',
      1 => 'field_left_markup',
      2 => 'field_left_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Left',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-left field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_left|paragraphs_item|two_column|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_left|paragraphs_item|two_column|paragraphs_editor_preview';
  $field_group->group_name = 'group_left';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'two_column';
  $field_group->mode = 'paragraphs_editor_preview';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Left',
    'weight' => '1',
    'children' => array(
      0 => 'field_left_block',
      1 => 'field_left_markup',
      2 => 'field_left_title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Left',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-left field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_left|paragraphs_item|two_column|paragraphs_editor_preview'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_middle|paragraphs_item|three_column|default';
  $field_group->group_name = 'group_middle';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'three_column';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Middle',
    'weight' => '2',
    'children' => array(
      0 => 'field_middle_block',
      1 => 'field_middle_markup',
      2 => 'field_middle_title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Middle',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-middle field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_middle|paragraphs_item|three_column|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_middle|paragraphs_item|three_column|form';
  $field_group->group_name = 'group_middle';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'three_column';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Middle',
    'weight' => '3',
    'children' => array(
      0 => 'field_middle_block',
      1 => 'field_middle_markup',
      2 => 'field_middle_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Middle',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_middle|paragraphs_item|three_column|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_middle|paragraphs_item|three_column|paragraphs_editor_preview';
  $field_group->group_name = 'group_middle';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'three_column';
  $field_group->mode = 'paragraphs_editor_preview';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Middle',
    'weight' => '2',
    'children' => array(
      0 => 'field_middle_block',
      1 => 'field_middle_markup',
      2 => 'field_middle_title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Middle',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-middle field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_middle|paragraphs_item|three_column|paragraphs_editor_preview'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_right_middle|paragraphs_item|four_column|default';
  $field_group->group_name = 'group_right_middle';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'four_column';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Right Middle',
    'weight' => '9',
    'children' => array(
      0 => 'field_right_middle_block',
      1 => 'field_right_middle_markup',
      2 => 'field_right_middle_title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Right Middle',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_right_middle|paragraphs_item|four_column|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_right_middle|paragraphs_item|four_column|form';
  $field_group->group_name = 'group_right_middle';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'four_column';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Right Middle',
    'weight' => '3',
    'children' => array(
      0 => 'field_right_middle_title',
      1 => 'field_right_middle_block',
      2 => 'field_right_middle_markup',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Right Middle',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_right_middle|paragraphs_item|four_column|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_right_middle|paragraphs_item|four_column|paragraphs_editor_preview';
  $field_group->group_name = 'group_right_middle';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'four_column';
  $field_group->mode = 'paragraphs_editor_preview';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Right Middle',
    'weight' => '3',
    'children' => array(
      0 => 'field_right_middle_block',
      1 => 'field_right_middle_markup',
      2 => 'field_right_middle_title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Right Middle',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-right-middle field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_right_middle|paragraphs_item|four_column|paragraphs_editor_preview'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_right|paragraphs_item|four_column|default';
  $field_group->group_name = 'group_right';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'four_column';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Right',
    'weight' => '13',
    'children' => array(
      0 => 'field_right_block',
      1 => 'field_right_markup',
      2 => 'field_right_title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Right',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_right|paragraphs_item|four_column|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_right|paragraphs_item|four_column|form';
  $field_group->group_name = 'group_right';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'four_column';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Right',
    'weight' => '4',
    'children' => array(
      0 => 'field_right_title',
      1 => 'field_right_block',
      2 => 'field_right_markup',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Right',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_right|paragraphs_item|four_column|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_right|paragraphs_item|four_column|paragraphs_editor_preview';
  $field_group->group_name = 'group_right';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'four_column';
  $field_group->mode = 'paragraphs_editor_preview';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Right',
    'weight' => '4',
    'children' => array(
      0 => 'field_right_block',
      1 => 'field_right_markup',
      2 => 'field_right_title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Right',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-right field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_right|paragraphs_item|four_column|paragraphs_editor_preview'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_right|paragraphs_item|three_column|default';
  $field_group->group_name = 'group_right';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'three_column';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Right',
    'weight' => '3',
    'children' => array(
      0 => 'field_right_block',
      1 => 'field_right_markup',
      2 => 'field_right_title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Right',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-right field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_right|paragraphs_item|three_column|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_right|paragraphs_item|three_column|form';
  $field_group->group_name = 'group_right';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'three_column';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Right',
    'weight' => '4',
    'children' => array(
      0 => 'field_right_block',
      1 => 'field_right_markup',
      2 => 'field_right_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Right',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_right|paragraphs_item|three_column|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_right|paragraphs_item|three_column|paragraphs_editor_preview';
  $field_group->group_name = 'group_right';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'three_column';
  $field_group->mode = 'paragraphs_editor_preview';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Right',
    'weight' => '3',
    'children' => array(
      0 => 'field_right_block',
      1 => 'field_right_markup',
      2 => 'field_right_title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Right',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-right field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_right|paragraphs_item|three_column|paragraphs_editor_preview'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_right|paragraphs_item|two_column|default';
  $field_group->group_name = 'group_right';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'two_column';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Right',
    'weight' => '2',
    'children' => array(
      0 => 'field_right_block',
      1 => 'field_right_markup',
      2 => 'field_right_title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Right',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-right field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_right|paragraphs_item|two_column|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_right|paragraphs_item|two_column|form';
  $field_group->group_name = 'group_right';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'two_column';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Right',
    'weight' => '4',
    'children' => array(
      0 => 'field_right_block',
      1 => 'field_right_markup',
      2 => 'field_right_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Right',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-right field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_right|paragraphs_item|two_column|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_right|paragraphs_item|two_column|paragraphs_editor_preview';
  $field_group->group_name = 'group_right';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'two_column';
  $field_group->mode = 'paragraphs_editor_preview';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Right',
    'weight' => '2',
    'children' => array(
      0 => 'field_right_block',
      1 => 'field_right_markup',
      2 => 'field_right_title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Right',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-right field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_right|paragraphs_item|two_column|paragraphs_editor_preview'] = $field_group;

  return $export;
}
