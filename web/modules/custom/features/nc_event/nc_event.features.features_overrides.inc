<?php
/**
 * @file
 * nc_event.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function nc_event_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: field_instance
  $overrides["field_instance.node-event-body.display|basic_card"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-event-body.display|block_feature"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 13,
  );
  $overrides["field_instance.node-event-body.display|default|settings|style_settings"] = array(
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
  );
  $overrides["field_instance.node-event-body.display|default|weight"] = 1;
  $overrides["field_instance.node-event-body.display|ical"] = array(
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
  );
  $overrides["field_instance.node-event-body.display|teaser|settings|style_settings"] = array(
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
  );
  $overrides["field_instance.node-event-body.display|teaser|settings|trim_length"] = 250;
  $overrides["field_instance.node-event-body.display|teaser|weight"] = 1;
  $overrides["field_instance.node-event-body.label"] = 'Event Description';
  $overrides["field_instance.node-event-body.widget|weight"] = 7;
  $overrides["field_instance.node-event-field_event_dates.display|basic_card"] = array(
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
  );
  $overrides["field_instance.node-event-field_event_dates.display|block_feature"] = array(
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
  );
  $overrides["field_instance.node-event-field_event_dates.display|default|label"] = 'hidden';
  $overrides["field_instance.node-event-field_event_dates.display|default|settings|show_repeat_rule"]["DELETED"] = TRUE;
  $overrides["field_instance.node-event-field_event_dates.display|default|settings|style_settings"] = array(
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
  );
  $overrides["field_instance.node-event-field_event_dates.display|default|type"] = 'hidden';
  $overrides["field_instance.node-event-field_event_dates.display|default|weight"] = 6;
  $overrides["field_instance.node-event-field_event_dates.display|ical"] = array(
    'label' => 'hidden',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-event-field_event_dates.display|teaser|module"] = 'date';
  $overrides["field_instance.node-event-field_event_dates.display|teaser|settings|format_type"] = 'long';
  $overrides["field_instance.node-event-field_event_dates.display|teaser|settings|fromto"] = 'both';
  $overrides["field_instance.node-event-field_event_dates.display|teaser|settings|multiple_from"] = '';
  $overrides["field_instance.node-event-field_event_dates.display|teaser|settings|multiple_number"] = '';
  $overrides["field_instance.node-event-field_event_dates.display|teaser|settings|multiple_to"] = '';
  $overrides["field_instance.node-event-field_event_dates.display|teaser|settings|style_settings"] = array(
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
  );
  $overrides["field_instance.node-event-field_event_dates.display|teaser|type"] = 'date_default';
  $overrides["field_instance.node-event-field_event_dates.label"] = 'When';
  $overrides["field_instance.node-event-field_event_location.display|basic_card"] = array(
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
  );
  $overrides["field_instance.node-event-field_event_location.display|block_feature"] = array(
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
  );
  $overrides["field_instance.node-event-field_event_location.display|default|label"] = 'hidden';
  $overrides["field_instance.node-event-field_event_location.display|default|module"]["DELETED"] = TRUE;
  $overrides["field_instance.node-event-field_event_location.display|default|settings|format_handlers"]["DELETED"] = TRUE;
  $overrides["field_instance.node-event-field_event_location.display|default|settings|use_widget_handlers"]["DELETED"] = TRUE;
  $overrides["field_instance.node-event-field_event_location.display|default|type"] = 'hidden';
  $overrides["field_instance.node-event-field_event_location.display|default|weight"] = 7;
  $overrides["field_instance.node-event-field_event_location.display|ical"] = array(
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
  );
  $overrides["field_instance.node-event-field_event_location.display|teaser|weight"] = 6;
  $overrides["field_instance.node-event-field_event_location.label"] = 'Where';
  $overrides["field_instance.node-event-field_event_location.widget|settings|available_countries|US"] = 'US';
  $overrides["field_instance.node-event-field_event_location.widget|settings|default_country"] = '';
  $overrides["field_instance.node-event-field_event_terms.display|basic_card"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-event-field_event_terms.display|block_feature"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 8,
  );
  $overrides["field_instance.node-event-field_event_terms.display|default|label"] = 'hidden';
  $overrides["field_instance.node-event-field_event_terms.display|default|module"] = 'views_term_link_formatter';
  $overrides["field_instance.node-event-field_event_terms.display|default|settings|anchor_class"] = 'link';
  $overrides["field_instance.node-event-field_event_terms.display|default|settings|anchor_enabled"] = 1;
  $overrides["field_instance.node-event-field_event_terms.display|default|settings|field_formatter_class"]["DELETED"] = TRUE;
  $overrides["field_instance.node-event-field_event_terms.display|default|settings|style_settings|content|element"] = 'div';
  $overrides["field_instance.node-event-field_event_terms.display|default|settings|style_settings|default_classes"] = 1;
  $overrides["field_instance.node-event-field_event_terms.display|default|settings|style_settings|item|class"] = 'field-item';
  $overrides["field_instance.node-event-field_event_terms.display|default|settings|style_settings|item|element"] = 'div';
  $overrides["field_instance.node-event-field_event_terms.display|default|settings|style_settings|title|class"] = 'field-label';
  $overrides["field_instance.node-event-field_event_terms.display|default|settings|style_settings|title|element"] = 'div';
  $overrides["field_instance.node-event-field_event_terms.display|default|settings|views_view"] = 'event_list|page';
  $overrides["field_instance.node-event-field_event_terms.display|default|settings|wrapper"] = 'span';
  $overrides["field_instance.node-event-field_event_terms.display|default|settings|wrapper_class"] = 'label tag';
  $overrides["field_instance.node-event-field_event_terms.display|default|type"] = 'views_term_link_formatter_term_link';
  $overrides["field_instance.node-event-field_event_terms.display|default|weight"] = 4;
  $overrides["field_instance.node-event-field_event_terms.widget|weight"] = 9;
  $overrides["field_instance.node-event-field_event_type.display|basic_card"] = array(
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
  );
  $overrides["field_instance.node-event-field_event_type.display|block_feature"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 6,
  );
  $overrides["field_instance.node-event-field_event_type.display|default|label"] = 'hidden';
  $overrides["field_instance.node-event-field_event_type.display|default|module"]["DELETED"] = TRUE;
  $overrides["field_instance.node-event-field_event_type.display|default|settings|field_formatter_class"]["DELETED"] = TRUE;
  $overrides["field_instance.node-event-field_event_type.display|default|settings|style_settings"]["DELETED"] = TRUE;
  $overrides["field_instance.node-event-field_event_type.display|default|type"] = 'hidden';
  $overrides["field_instance.node-event-field_event_type.display|default|weight"] = 10;
  $overrides["field_instance.node-event-field_event_type.widget|weight"] = 10;
  $overrides["field_instance.node-event-field_organizer.display|basic_card"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-event-field_organizer.display|block_feature"] = array(
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
  );
  $overrides["field_instance.node-event-field_organizer.display|default|label"] = 'hidden';
  $overrides["field_instance.node-event-field_organizer.display|default|module"]["DELETED"] = TRUE;
  $overrides["field_instance.node-event-field_organizer.display|default|settings|field_formatter_class"]["DELETED"] = TRUE;
  $overrides["field_instance.node-event-field_organizer.display|default|settings|style_settings"]["DELETED"] = TRUE;
  $overrides["field_instance.node-event-field_organizer.display|default|type"] = 'hidden';
  $overrides["field_instance.node-event-field_organizer.display|default|weight"] = 5;
  $overrides["field_instance.node-event-field_organizer.widget|module"] = 'taxonomy';
  $overrides["field_instance.node-event-field_organizer.widget|settings|autocomplete_path"] = 'taxonomy/autocomplete';
  $overrides["field_instance.node-event-field_organizer.widget|settings|size"] = 60;
  $overrides["field_instance.node-event-field_organizer.widget|type"] = 'taxonomy_autocomplete';
  $overrides["field_instance.node-event-field_organizer.widget|weight"] = 11;
  $overrides["field_instance.node-event-field_related_content.display|basic_card"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-event-field_related_content.display|block_feature"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 10,
  );
  $overrides["field_instance.node-event-field_related_content.display|default|label"] = 'above';
  $overrides["field_instance.node-event-field_related_content.display|default|settings|style_settings"] = array(
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
  );
  $overrides["field_instance.node-event-field_related_content.display|teaser|weight"] = 5;
  $overrides["field_instance.node-event-field_related_content.settings|validate_url"] = 0;
  $overrides["field_instance.node-event-field_related_content.widget|settings|validate_url"] = 0;
  $overrides["field_instance.node-event-field_related_content.widget|weight"] = 14;

 return $overrides;
}
