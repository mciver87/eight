<?php
/**
 * @file
 * nc_event.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function nc_event_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-event-field_agency_department'.
  $field_instances['node-event-field_agency_department'] = array(
    'bundle' => 'event',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'basic_card' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'block_feature' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 11,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_agency_department',
    'label' => 'Agency/Department',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'node-event-field_cost'.
  $field_instances['node-event-field_cost'] = array(
    'bundle' => 'event',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'basic_card' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'block_feature' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
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
        'type' => 'text_default',
        'weight' => 4,
      ),
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_cost',
    'label' => 'Cost',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-event-field_event_contact_email'.
  $field_instances['node-event-field_event_contact_email'] = array(
    'bundle' => 'event',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'basic_card' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'block_feature' => array(
        'label' => 'hidden',
        'module' => 'email',
        'settings' => array(
          'style_settings' => array(
            'content' => array(
              'class' => 'field-items',
              'element' => 'div',
            ),
            'default_classes' => 1,
            'item' => array(
              'class' => 'field-item',
              'element' => '',
            ),
            'item_limit' => '',
            'prefix_markup' => '',
            'title' => array(
              'class' => 'field-label',
              'element' => '',
              'suffix' => ':',
            ),
            'wrapper' => array(
              'class' => '',
              'element' => '',
            ),
          ),
        ),
        'type' => 'email_default',
        'weight' => 1,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_event_contact_email',
    'label' => 'Email',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'email',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'email_textfield',
      'weight' => 22,
    ),
  );

  // Exported field_instance: 'node-event-field_event_contact_name'.
  $field_instances['node-event-field_event_contact_name'] = array(
    'bundle' => 'event',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'basic_card' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'block_feature' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'style_settings' => array(
            'content' => array(
              'class' => 'field-items',
              'element' => 'div',
            ),
            'default_classes' => 1,
            'item' => array(
              'class' => 'field-item',
              'element' => '',
            ),
            'item_limit' => '',
            'prefix_markup' => '',
            'title' => array(
              'class' => 'field-label',
              'element' => '',
              'suffix' => ':',
            ),
            'wrapper' => array(
              'class' => '',
              'element' => '',
            ),
          ),
        ),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_event_contact_name',
    'label' => 'Name',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 21,
    ),
  );

  // Exported field_instance: 'node-event-field_event_contact_phone'.
  $field_instances['node-event-field_event_contact_phone'] = array(
    'bundle' => 'event',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'basic_card' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'block_feature' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'style_settings' => array(
            'content' => array(
              'class' => 'field-items',
              'element' => 'div',
            ),
            'default_classes' => 1,
            'item' => array(
              'class' => 'field-item',
              'element' => '',
            ),
            'item_limit' => '',
            'prefix_markup' => '',
            'title' => array(
              'class' => 'field-label',
              'element' => '',
              'suffix' => ':',
            ),
            'wrapper' => array(
              'class' => '',
              'element' => '',
            ),
          ),
        ),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_event_contact_phone',
    'label' => 'Phone Number',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 23,
    ),
  );

  // Exported field_instance: 'node-event-field_external_url'.
  $field_instances['node-event-field_external_url'] = array(
    'bundle' => 'event',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'basic_card' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'block_feature' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(
          'style_settings' => array(
            'content' => array(
              'class' => 'field-items',
              'element' => 'div',
            ),
            'default_classes' => 1,
            'item' => array(
              'class' => 'external-link',
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
        'type' => 'link_default',
        'weight' => 6,
      ),
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_external_url',
    'label' => 'External URL',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => '_blank',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'rel_remove' => 'default',
      'title' => 'optional',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'node-event-field_files'.
  $field_instances['node-event-field_files'] = array(
    'bundle' => 'event',
    'deleted' => 0,
    'description' => 'Upload files you would like to associate with this page.',
    'display' => array(
      'basic_card' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'block_feature' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'nc_fields',
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
        'type' => 'nc_fields_file_formatter_detail',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_files',
    'label' => 'Files',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => '',
      'file_extensions' => 'pdf doc docx xls xlsx csv txt rtf html zip flv jpg jpeg png gif ppt pptx vsd',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'imce_filefield_on' => 1,
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 14,
    ),
  );

  // Exported field_instance: 'node-event-field_key_search_topics'.
  $field_instances['node-event-field_key_search_topics'] = array(
    'bundle' => 'event',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'basic_card' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'block_feature' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 13,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_key_search_topics',
    'label' => 'Key Search Topics',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'taxonomy',
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'size' => 60,
      ),
      'type' => 'taxonomy_autocomplete',
      'weight' => 16,
    ),
    'workbench_access_field' => 0,
  );

  // Exported field_instance: 'node-event-field_main_image'.
  $field_instances['node-event-field_main_image'] = array(
    'bundle' => 'event',
    'deleted' => 0,
    'description' => 'Larger images will be scaled and cropped automatically to 740 x 416 pixels.',
    'display' => array(
      'basic_card' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
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
        'type' => 'image',
        'weight' => 0,
      ),
      'block_feature' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => 'event-detail',
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
        'type' => 'image',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_main_image',
    'label' => 'Main Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'imce_filefield_on' => 1,
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-event-field_static_map'.
  $field_instances['node-event-field_static_map'] = array(
    'bundle' => 'event',
    'default_value' => array(
      0 => array(
        'addressfield' => 'field_event_location',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'basic_card' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'block_feature' => array(
        'label' => 'hidden',
        'module' => 'nc_addressfield_staticmap',
        'settings' => array(
          'display_marker' => 1,
          'map_height' => 200,
          'map_width' => 356,
          'marker_color' => 'blue',
          'marker_size' => 'normal',
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
          'type' => 'roadmap',
          'zoom_level' => 14,
        ),
        'type' => 'nc_addressfield_staticmap_default',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 14,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_static_map',
    'label' => 'Static Map',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'nc_addressfield_staticmap',
      'settings' => array(),
      'type' => 'nc_addressfield_staticmap_field',
      'weight' => 19,
    ),
  );

  // Exported field_instance: 'node-event-field_virtual_location'.
  $field_instances['node-event-field_virtual_location'] = array(
    'bundle' => 'event',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'basic_card' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'block_feature' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
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
        'type' => 'text_default',
        'weight' => 3,
      ),
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_virtual_location',
    'label' => 'Online Access',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 4,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Agency/Department');
  t('Cost');
  t('Email');
  t('External URL');
  t('Files');
  t('Key Search Topics');
  t('Main Image');
  t('Name');
  t('Online Access');
  t('Phone Number');
  t('Static Map');
  t('Upload files you would like to associate with this page.');

  return $field_instances;
}
