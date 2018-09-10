<?php
/**
 * @file
 * nc_event.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nc_event_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_field_default_field_instances_alter().
 */
function nc_event_field_default_field_instances_alter(&$data) {
  if (isset($data['node-event-body'])) {
    $data['node-event-body']['display']['basic_card'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-event-body']['display']['block_feature'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 13,
    ); /* WAS: '' */
    $data['node-event-body']['display']['default']['settings']['style_settings'] = array(
      'content' => array(
        'class' => 'field-items',
        'element' => '',
      ),
      'default_classes' => 1,
      'item' => array(
        'class' => 'description',
        'element' => 'div',
      ),
      'item_limit' => '',
      'prefix_markup' => '',
      'title' => array(
        'class' => 'section-title',
        'element' => 'h2',
        'suffix' => '',
      ),
      'wrapper' => array(
        'class' => '',
        'element' => '',
      ),
    ); /* WAS: '' */
    $data['node-event-body']['display']['default']['weight'] = 1; /* WAS: 2 */
    $data['node-event-body']['display']['ical'] = array(
      'label' => 'hidden',
      'module' => 'text',
      'settings' => array(
        'field_formatter_class' => '',
        'style_settings' => array(
          'content' => array(
            'class' => 'field-items',
            'element' => 'div',
          ),
          'default_classes' => TRUE,
          'item' => array(
            'class' => 'field-item',
            'element' => 'div',
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
        ),
      ),
      'type' => 'text_default',
      'weight' => 2,
    ); /* WAS: '' */
    $data['node-event-body']['display']['teaser']['settings']['style_settings'] = array(
      'content' => array(
        'class' => 'field-items',
        'element' => 'div',
      ),
      'default_classes' => 1,
      'item' => array(
        'class' => 'field-item',
        'element' => 'div',
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
    ); /* WAS: '' */
    $data['node-event-body']['display']['teaser']['settings']['trim_length'] = 250; /* WAS: 600 */
    $data['node-event-body']['display']['teaser']['weight'] = 1; /* WAS: 0 */
    $data['node-event-body']['label'] = 'Event Description'; /* WAS: 'Description' */
    $data['node-event-body']['widget']['weight'] = 7; /* WAS: 4 */
  }
  if (isset($data['node-event-field_event_dates'])) {
    $data['node-event-field_event_dates']['display']['basic_card'] = array(
      'label' => 'hidden',
      'module' => 'date',
      'settings' => array(
        'style_settings' => array(
          'content' => array(
            'class' => 'field-items',
            'element' => 'div',
          ),
          'default_classes' => TRUE,
          'item' => array(
            'class' => 'field-item',
            'element' => 'div',
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
        ),
      ),
      'type' => 'date_plain',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-event-field_event_dates']['display']['block_feature'] = array(
      'label' => 'above',
      'module' => 'date',
      'settings' => array(
        'format_type' => 'long',
        'fromto' => 'both',
        'multiple_from' => '',
        'multiple_number' => '',
        'multiple_to' => '',
        'style_settings' => array(
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
        ),
      ),
      'type' => 'date_default',
      'weight' => 1,
    ); /* WAS: '' */
    $data['node-event-field_event_dates']['display']['default']['label'] = 'hidden'; /* WAS: 'inline' */
    $data['node-event-field_event_dates']['display']['default']['settings']['style_settings'] = array(
      'content' => array(
        'class' => 'field-items',
        'element' => 'div',
      ),
      'default_classes' => TRUE,
      'item' => array(
        'class' => 'field-item',
        'element' => 'div',
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
    ); /* WAS: '' */
    $data['node-event-field_event_dates']['display']['default']['type'] = 'hidden'; /* WAS: 'date_default' */
    $data['node-event-field_event_dates']['display']['default']['weight'] = 6; /* WAS: 0 */
    $data['node-event-field_event_dates']['display']['ical'] = array(
      'label' => 'hidden',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-event-field_event_dates']['display']['teaser']['module'] = 'date'; /* WAS: '' */
    $data['node-event-field_event_dates']['display']['teaser']['settings']['format_type'] = 'long'; /* WAS: '' */
    $data['node-event-field_event_dates']['display']['teaser']['settings']['fromto'] = 'both'; /* WAS: '' */
    $data['node-event-field_event_dates']['display']['teaser']['settings']['multiple_from'] = ''; /* WAS: '' */
    $data['node-event-field_event_dates']['display']['teaser']['settings']['multiple_number'] = ''; /* WAS: '' */
    $data['node-event-field_event_dates']['display']['teaser']['settings']['multiple_to'] = ''; /* WAS: '' */
    $data['node-event-field_event_dates']['display']['teaser']['settings']['style_settings'] = array(
      'content' => array(
        'class' => 'field-items',
        'element' => 'div',
      ),
      'default_classes' => TRUE,
      'item' => array(
        'class' => 'field-item',
        'element' => 'div',
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
    ); /* WAS: '' */
    $data['node-event-field_event_dates']['display']['teaser']['type'] = 'date_default'; /* WAS: 'hidden' */
    $data['node-event-field_event_dates']['label'] = 'When'; /* WAS: 'Dates' */
    unset($data['node-event-field_event_dates']['display']['default']['settings']['show_repeat_rule']);
  }
  if (isset($data['node-event-field_event_location'])) {
    $data['node-event-field_event_location']['display']['basic_card'] = array(
      'label' => 'hidden',
      'module' => 'addressfield',
      'settings' => array(
        'format_handlers' => array(
          0 => 'address',
        ),
        'style_settings' => array(
          'content' => array(
            'class' => 'field-items',
            'element' => 'div',
          ),
          'default_classes' => TRUE,
          'item' => array(
            'class' => 'field-item',
            'element' => 'div',
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
        ),
        'use_widget_handlers' => 1,
      ),
      'type' => 'addressfield_default',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-event-field_event_location']['display']['block_feature'] = array(
      'label' => 'above',
      'module' => 'addressfield',
      'settings' => array(
        'format_handlers' => array(
          'address' => 'address',
        ),
        'style_settings' => array(
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
        ),
        'use_widget_handlers' => 1,
      ),
      'type' => 'addressfield_default',
      'weight' => 2,
    ); /* WAS: '' */
    $data['node-event-field_event_location']['display']['default']['label'] = 'hidden'; /* WAS: 'above' */
    $data['node-event-field_event_location']['display']['default']['type'] = 'hidden'; /* WAS: 'addressfield_default' */
    $data['node-event-field_event_location']['display']['default']['weight'] = 7; /* WAS: 1 */
    $data['node-event-field_event_location']['display']['ical'] = array(
      'label' => 'hidden',
      'module' => 'addressfield',
      'settings' => array(
        'field_formatter_class' => '',
        'format_handlers' => array(
          0 => 'address',
        ),
        'style_settings' => array(
          'content' => array(
            'class' => 'field-items',
            'element' => 'div',
          ),
          'default_classes' => TRUE,
          'item' => array(
            'class' => 'field-item',
            'element' => 'div',
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
        ),
        'use_widget_handlers' => 1,
      ),
      'type' => 'addressfield_default',
      'weight' => 1,
    ); /* WAS: '' */
    $data['node-event-field_event_location']['display']['teaser']['weight'] = 6; /* WAS: 0 */
    $data['node-event-field_event_location']['label'] = 'Where'; /* WAS: 'Location' */
    $data['node-event-field_event_location']['widget']['settings']['available_countries']['US'] = 'US'; /* WAS: '' */
    $data['node-event-field_event_location']['widget']['settings']['default_country'] = ''; /* WAS: '' */
    unset($data['node-event-field_event_location']['display']['default']['module']);
    unset($data['node-event-field_event_location']['display']['default']['settings']['format_handlers']);
    unset($data['node-event-field_event_location']['display']['default']['settings']['use_widget_handlers']);
  }
  if (isset($data['node-event-field_event_terms'])) {
    $data['node-event-field_event_terms']['display']['basic_card'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-event-field_event_terms']['display']['block_feature'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 8,
    ); /* WAS: '' */
    $data['node-event-field_event_terms']['display']['default']['label'] = 'hidden'; /* WAS: 'above' */
    $data['node-event-field_event_terms']['display']['default']['module'] = 'views_term_link_formatter'; /* WAS: 'taxonomy' */
    $data['node-event-field_event_terms']['display']['default']['settings']['anchor_class'] = 'link'; /* WAS: '' */
    $data['node-event-field_event_terms']['display']['default']['settings']['anchor_enabled'] = 1; /* WAS: '' */
    $data['node-event-field_event_terms']['display']['default']['settings']['style_settings']['content']['element'] = 'div'; /* WAS: '' */
    $data['node-event-field_event_terms']['display']['default']['settings']['style_settings']['default_classes'] = 1; /* WAS: 0 */
    $data['node-event-field_event_terms']['display']['default']['settings']['style_settings']['item']['class'] = 'field-item'; /* WAS: 'label tag' */
    $data['node-event-field_event_terms']['display']['default']['settings']['style_settings']['item']['element'] = 'div'; /* WAS: 'span' */
    $data['node-event-field_event_terms']['display']['default']['settings']['style_settings']['title']['class'] = 'field-label'; /* WAS: '' */
    $data['node-event-field_event_terms']['display']['default']['settings']['style_settings']['title']['element'] = 'div'; /* WAS: 'p' */
    $data['node-event-field_event_terms']['display']['default']['settings']['views_view'] = 'event_list|page'; /* WAS: '' */
    $data['node-event-field_event_terms']['display']['default']['settings']['wrapper'] = 'span'; /* WAS: '' */
    $data['node-event-field_event_terms']['display']['default']['settings']['wrapper_class'] = 'label tag'; /* WAS: '' */
    $data['node-event-field_event_terms']['display']['default']['type'] = 'views_term_link_formatter_term_link'; /* WAS: 'taxonomy_term_reference_link' */
    $data['node-event-field_event_terms']['display']['default']['weight'] = 4; /* WAS: 5 */
    $data['node-event-field_event_terms']['widget']['weight'] = 9; /* WAS: 10 */
    unset($data['node-event-field_event_terms']['display']['default']['settings']['field_formatter_class']);
  }
  if (isset($data['node-event-field_event_type'])) {
    $data['node-event-field_event_type']['display']['basic_card'] = array(
      'label' => 'hidden',
      'module' => 'taxonomy',
      'settings' => array(
        'style_settings' => array(
          'content' => array(
            'class' => 'field-items',
            'element' => 'div',
          ),
          'default_classes' => TRUE,
          'item' => array(
            'class' => 'field-item',
            'element' => 'div',
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
        ),
      ),
      'type' => 'taxonomy_term_reference_plain',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-event-field_event_type']['display']['block_feature'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 6,
    ); /* WAS: '' */
    $data['node-event-field_event_type']['display']['default']['label'] = 'hidden'; /* WAS: 'above' */
    $data['node-event-field_event_type']['display']['default']['type'] = 'hidden'; /* WAS: 'taxonomy_term_reference_link' */
    $data['node-event-field_event_type']['display']['default']['weight'] = 10; /* WAS: 8 */
    $data['node-event-field_event_type']['widget']['weight'] = 10; /* WAS: 11 */
    unset($data['node-event-field_event_type']['display']['default']['module']);
    unset($data['node-event-field_event_type']['display']['default']['settings']['field_formatter_class']);
    unset($data['node-event-field_event_type']['display']['default']['settings']['style_settings']);
  }
  if (isset($data['node-event-field_organizer'])) {
    $data['node-event-field_organizer']['display']['basic_card'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-event-field_organizer']['display']['block_feature'] = array(
      'label' => 'above',
      'module' => 'taxonomy',
      'settings' => array(
        'style_settings' => array(
          'content' => array(
            'class' => 'field-items',
            'element' => 'div',
          ),
          'default_classes' => 1,
          'item' => array(
            'class' => 'field-item',
            'element' => 'div',
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
        ),
      ),
      'type' => 'taxonomy_term_reference_plain',
      'weight' => 5,
    ); /* WAS: '' */
    $data['node-event-field_organizer']['display']['default']['label'] = 'hidden'; /* WAS: 'above' */
    $data['node-event-field_organizer']['display']['default']['type'] = 'hidden'; /* WAS: 'taxonomy_term_reference_link' */
    $data['node-event-field_organizer']['display']['default']['weight'] = 5; /* WAS: 3 */
    $data['node-event-field_organizer']['widget']['module'] = 'taxonomy'; /* WAS: 'options' */
    $data['node-event-field_organizer']['widget']['settings']['autocomplete_path'] = 'taxonomy/autocomplete'; /* WAS: '' */
    $data['node-event-field_organizer']['widget']['settings']['size'] = 60; /* WAS: '' */
    $data['node-event-field_organizer']['widget']['type'] = 'taxonomy_autocomplete'; /* WAS: 'options_select' */
    $data['node-event-field_organizer']['widget']['weight'] = 11; /* WAS: 12 */
    unset($data['node-event-field_organizer']['display']['default']['module']);
    unset($data['node-event-field_organizer']['display']['default']['settings']['field_formatter_class']);
    unset($data['node-event-field_organizer']['display']['default']['settings']['style_settings']);
  }
  if (isset($data['node-event-field_related_content'])) {
    $data['node-event-field_related_content']['display']['basic_card'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-event-field_related_content']['display']['block_feature'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 10,
    ); /* WAS: '' */
    $data['node-event-field_related_content']['display']['default']['label'] = 'above'; /* WAS: 'hidden' */
    $data['node-event-field_related_content']['display']['default']['settings']['style_settings'] = array(
      'content' => array(
        'class' => 'field-items',
        'element' => '',
      ),
      'default_classes' => 1,
      'item' => array(
        'class' => 'field-item',
        'element' => 'li',
      ),
      'item_limit' => '',
      'prefix_markup' => '',
      'title' => array(
        'class' => 'section-title',
        'element' => 'h2',
        'suffix' => '',
      ),
      'wrapper' => array(
        'class' => '',
        'element' => 'ul',
      ),
    ); /* WAS: '' */
    $data['node-event-field_related_content']['display']['teaser']['weight'] = 5; /* WAS: 0 */
    $data['node-event-field_related_content']['settings']['validate_url'] = 0; /* WAS: 1 */
    $data['node-event-field_related_content']['widget']['settings']['validate_url'] = 0; /* WAS: '' */
    $data['node-event-field_related_content']['widget']['weight'] = 14; /* WAS: 5 */
  }
}

/**
 * Implements hook_image_default_styles().
 */
function nc_event_image_default_styles() {
  $styles = array();

  // Exported image style: event-detail.
  $styles['event-detail'] = array(
    'name' => 'event-detail',
    'label' => 'event-detail',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 740,
          'height' => 416,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_microdata_mappings_defaults().
 */
function nc_event_microdata_mappings_defaults() {
  $microdata_mappings = array();

  // Exported Microdata mapping: event
  $microdata_mappings['node']['event'] = array(
    '#itemtype' => array(
      0 => 'http://schema.org/Event',
    ),
    'title' => array(
      '#itemprop' => array(
        0 => 'name',
      ),
    ),
    '#is_item' => TRUE,
    '#itemid_token' => '[node:url]',
    '#use_schema_url' => 1,
    'body' => array(
      '#itemprop' => array(),
      '#is_item' => FALSE,
      'value' => array(
        '#itemprop' => array(
          0 => 'description',
        ),
        '#itemtype' => '',
      ),
      'summary' => array(
        '#itemprop' => array(),
        '#itemtype' => '',
      ),
    ),
    'field_event_dates' => array(
      'value' => array(
        '#itemprop' => array(
          0 => 'startDate',
        ),
        '#itemtype' => '',
      ),
      'value2' => array(
        '#itemprop' => array(
          0 => 'endDate',
        ),
        '#itemtype' => '',
      ),
    ),
    'field_event_terms' => array(
      '#itemprop' => array(
        0 => 'about',
      ),
      '#is_item' => FALSE,
    ),
    'field_main_image' => array(
      '#itemprop' => array(
        0 => 'image',
      ),
      '#is_item' => FALSE,
    ),
    'field_north_carolina_counties' => array(
      '#itemprop' => array(),
      '#is_item' => FALSE,
    ),
    'field_agency_department' => array(
      '#itemprop' => array(),
      '#is_item' => FALSE,
    ),
    'field_virtual_location' => array(
      '#itemprop' => array(),
      '#is_item' => FALSE,
    ),
    'field_event_contact_name' => array(
      '#itemprop' => array(),
      '#is_item' => FALSE,
    ),
    'field_event_contact_phone' => array(
      '#itemprop' => array(),
      '#is_item' => FALSE,
    ),
  );

  return $microdata_mappings;
}
