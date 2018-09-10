<?php
/**
 * @file
 * nc_quicklinks.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function nc_quicklinks_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'bean-nc_quicklinks-field_quick_link'
  $field_instances['bean-nc_quicklinks-field_quick_link'] = array(
    'bundle' => 'nc_quicklinks',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
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
        'type' => 'link_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'bean',
    'field_name' => 'field_quick_link',
    'label' => 'Quick Links',
    'required' => 1,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
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
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'bean-nc_quicklinks-field_quick_link_style'
  $field_instances['bean-nc_quicklinks-field_quick_link_style'] = array(
    'bundle' => 'nc_quicklinks',
    'default_value' => array(
      0 => array(
        'value' => 'default',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
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
        'type' => 'list_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'bean',
    'field_name' => 'field_quick_link_style',
    'label' => 'Quick Links Block Style',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'bean-nc_quicklinks-field_quick_link_a_style'
  $field_instances['bean-nc_quicklinks-field_quick_link_a_style'] = array(
    'bundle' => 'nc_quicklinks',
    'default_value' => array(
      0 => array(
        'value' => 'default',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
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
        'type' => 'list_default',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'bean',
    'field_name' => 'field_quick_link_a_style',
    'label' => 'Quick Links Style',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'bean-nc_quicklinks-field_quick_links_header'
  $field_instances['bean-nc_quicklinks-field_quick_links_header'] = array(
    'bundle' => 'nc_quicklinks',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
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
        'weight' => 1,
      ),
    ),
    'entity_type' => 'bean',
    'field_name' => 'field_quick_links_header',
    'label' => 'Quick Links Header',
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
      'weight' => 1,
    ),
  );

// Exported field_instance: 'bean-nc_quicklinks-field_quick_links_header_style'
  $field_instances['bean-nc_quicklinks-field_quick_links_header_style'] = array(
    'bundle' => 'nc_quicklinks',
    'default_value' => array(
      0 => array(
        'value' => 'primary',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
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
        'type' => 'list_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'bean',
    'field_name' => 'field_quick_links_header_style',
    'label' => 'Quick Links Header Style',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 2,
    ),
  );


  // Exported field_instance: 'bean-nc_quicklinks-field_quick_links_description'
  $field_instances['bean-nc_quicklinks-field_quick_links_description'] = array(
    'bundle' => 'nc_quicklinks',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
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
      ),
    ),
    'entity_type' => 'bean',
    'field_name' => 'field_quick_links_description',
    'label' => 'Quick Links Description',
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
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Quick Links');
  t('Quick Links Header');
  t('Quick Links Header Style');
  t('Quick Links Description');
  t('Quick Links Block Style');
  t('Quick Links Style');

  return $field_instances;
}
