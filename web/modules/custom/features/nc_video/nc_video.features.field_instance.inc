<?php
/**
 * @file
 * nc_video.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function nc_video_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-video-body'
  $field_instances['node-video-body'] = array(
    'bundle' => 'video',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'basic_card' => array(
        'label' => 'hidden',
        'module' => 'text',
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
          'trim_length' => 600,
        ),
        'type' => 'text_summary_or_trimmed',
        'weight' => 1,
      ),
      'block_feature' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
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
        'type' => 'text_default',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
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
          'trim_length' => 600,
        ),
        'type' => 'text_summary_or_trimmed',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'Body',
    'required' => FALSE,
    'settings' => array(
      'display_summary' => TRUE,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-video-field_published_date'
  $field_instances['node-video-field_published_date'] = array(
    'bundle' => 'video',
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
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
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
        'type' => 'nc_fields_date_formatter',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_published_date',
    'label' => 'First published',
    'required' => 0,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 15,
        'input_format' => 'm/d/Y - g:i:sa',
        'input_format_custom' => '',
        'label_position' => 'above',
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_popup',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-video-field_tracking'
  $field_instances['node-video-field_tracking'] = array(
    'bundle' => 'video',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This field is administrative only and is used for notation of the origin, permissions, etc. of the video, and is not displayed.',
    'display' => array(
      'basic_card' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
      'block_feature' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
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
    'field_name' => 'field_tracking',
    'label' => 'Tracking / Permissions',
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
        'maxlength_js_label' => '',
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-video-field_video'
  $field_instances['node-video-field_video'] = array(
    'bundle' => 'video',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'basic_card' => array(
        'label' => 'hidden',
        'module' => 'video_embed_field',
        'settings' => array(
          'description' => 1,
          'description_position' => 'bottom',
          'image_link' => 'content',
          'image_style' => 'medium',
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
        'type' => 'video_embed_field_thumbnail',
        'weight' => 0,
      ),
      'block_feature' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'video_embed_field',
        'settings' => array(
          'description' => 0,
          'description_position' => 'bottom',
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
          'video_style' => 'normal',
        ),
        'type' => 'video_embed_field',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_video',
    'label' => 'Video',
    'required' => 1,
    'settings' => array(
      'description_field' => 0,
      'description_length' => 128,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'video_embed_field',
      'settings' => array(),
      'type' => 'video_embed_field_video',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-video-field_video_terms'
  $field_instances['node-video-field_video_terms'] = array(
    'bundle' => 'video',
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
        'weight' => 0,
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
        'type' => 'nc_fields_term_formatter_simple',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_video_terms',
    'label' => 'Video terms',
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
      'weight' => 7,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Body');
  t('First published');
  t('This field is administrative only and is used for notation of the origin, permissions, etc. of the video, and is not displayed.');
  t('Tracking / Permissions');
  t('Video');
  t('Video terms');

  return $field_instances;
}
