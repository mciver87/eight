<?php

/**
 * @file
 * Adding complex update routines here.
 */

/**
 * ABT-680: New updates to the nc_event field.
 */
function nc_event_update_abt_680_block_feature() {
  // Update the settings of the event dates.
  $instance_info = field_info_instance('node', 'field_event_dates', 'event');

  // Change label.
  $instance_info['label'] = 'When';

  // Update settings.
  $instance_info['display']['default']['type'] = 'hidden';
  $instance_info['display']['block_feature']['label'] = 'above';
  $instance_info['display']['block_feature']['settings']['style_settings'] = array(
    'content' => array(
      'class' => 'field-items',
      'element' => 'div',
    ),
    'default_classes' => 1,
    'item' => array(
      'class' => 'field-item',
      'element' => 'span',
    ),
    'item_limit' => '',
    'prefix_markup' => '',
    'title' => array(
      'class' => 'field-label',
      'element' => 'div',
      'suffix' => ':',
    ),
    'wrapper' => array(
      'class' => '',
      'element' => 'div',
    ),
  );

  // Save the date field.
  field_update_instance($instance_info);

  // Get the event files field instance.
  $instance_info = field_info_instance('node', 'field_event_location', 'event');

  // Update the formatter & display settings.
  // This is a minimal set of updates.
  $instance_info['label'] = 'Where';
  $instance_info['display']['block_feature']['label'] = 'above';
  $instance_info['display']['block_feature']['settings']['style_settings'] = array(
    'content' => array(
      'class' => 'field-items',
      'element' => 'div',
    ),
    'default_classes' => 1,
    'item' => array(
      'class' => 'field-item',
      'element' => 'time',
    ),
    'item_limit' => '',
    'prefix_markup' => '',
    'title' => array(
      'class' => 'field-label',
      'element' => 'div',
      'suffix' => ':',
    ),
    'wrapper' => array(
      'class' => '',
      'element' => 'div',
    ),
  );

  // Save instance.
  field_update_instance($instance_info);

  // Update virtual location.
  $instance_info = field_info_instance('node', 'field_virtual_location', 'event');

  // Update the formatter & display settings.
  // This is a minimal set of updates.
  $instance_info['label'] = 'Online Access';
  $instance_info['display']['block_feature']['label'] = 'above';
  $instance_info['display']['block_feature']['settings']['style_settings'] = array(
    'content' => array(
      'class' => 'field-items',
      'element' => 'div',
    ),
    'default_classes' => 1,
    'item' => array(
      'class' => 'field-item',
      'element' => 'span',
    ),
    'item_limit' => '',
    'prefix_markup' => '',
    'title' => array(
      'class' => 'field-label',
      'element' => 'div',
      'suffix' => ':',
    ),
    'wrapper' => array(
      'class' => '',
      'element' => 'div',
    ),
  );

  // Save instance.
  field_update_instance($instance_info);

  // Update cost.
  $instance_info = field_info_instance('node', 'field_cost', 'event');

  // Update the formatter & display settings.
  // This is a minimal set of updates.
  $instance_info['display']['block_feature']['label'] = 'above';
  $instance_info['display']['block_feature']['settings']['style_settings'] = array(
    'content' => array(
      'class' => 'field-items',
      'element' => 'div',
    ),
    'default_classes' => 1,
    'item' => array(
      'class' => 'field-item',
      'element' => 'span',
    ),
    'item_limit' => '',
    'prefix_markup' => '',
    'title' => array(
      'class' => 'field-label',
      'element' => 'div',
      'suffix' => ':',
    ),
    'wrapper' => array(
      'class' => '',
      'element' => 'div',
    ),
  );

  // Save instance.
  field_update_instance($instance_info);

  // Update organizer.
  $instance_info = field_info_instance('node', 'field_organizer', 'event');

  // Update the formatter & display settings.
  // This is a minimal set of updates.
  $instance_info['widget']['module'] = 'taxonomy';
  $instance_info['widget']['type'] = 'taxonomy_autocomplete';
  $instance_info['widget']['settings']['autocomplete_path'] = 'taxonomy/autocomplete';

  // Save instance.
  field_update_instance($instance_info);
}

/**
 * ABT-782 upadated available countries to include only US. 
 */
function nc_event_update_abt_862_block_feature() {
  $instance_info = field_info_instance('node', 'field_event_location', 'event');
  $instance_info['widget']['settings']['available_countries']['US'] = 'US';
   // Save instance.
  field_update_instance($instance_info);
}
