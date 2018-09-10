<?php
/**
 * @file
 * openpublic_agency.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function openpublic_agency_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-agency-body'
  $field_instances['node-agency-body'] = array(
    'bundle' => 'agency',
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
        'weight' => 0,
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
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'node-agency-field_agency_address'
  $field_instances['node-agency-field_agency_address'] = array(
    'bundle' => 'agency',
    'default_value' => array(
      0 => array(
        'element_key' => 'node|agency|field_agency_address|und|0',
        'thoroughfare' => '',
        'premise' => '',
        'locality' => '',
        'administrative_area' => '',
        'postal_code' => '',
        'country' => 'US',
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
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
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
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_agency_address',
    'label' => 'Address',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'addressfield',
      'settings' => array(
        'available_countries' => array(
          'US' => 'US',
        ),
        'format_handlers' => array(
          'address' => 'address',
          'address-hide-country' => 'address-hide-country',
          'organisation' => 0,
          'name-full' => 0,
          'name-oneline' => 0,
        ),
      ),
      'type' => 'addressfield_standard',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-agency-field_agency_category'
  $field_instances['node-agency-field_agency_category'] = array(
    'bundle' => 'agency',
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
              'suffix' => '',
            ),
            'wrapper' => array(
              'class' => '',
              'element' => 'div',
            ),
          ),
        ),
        'type' => 'taxonomy_term_reference_plain',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_agency_category',
    'label' => 'Agency category',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-agency-field_agency_email'
  $field_instances['node-agency-field_agency_email'] = array(
    'bundle' => 'agency',
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
        'label' => 'above',
        'module' => 'email',
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
        'type' => 'email_default',
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
    'field_name' => 'field_agency_email',
    'label' => 'Email',
    'required' => 1,
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
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'node-agency-field_agency_phone'
  $field_instances['node-agency-field_agency_phone'] = array(
    'bundle' => 'agency',
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
        'label' => 'above',
        'module' => 'phone',
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
        'type' => 'phone',
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
    'field_name' => 'field_agency_phone',
    'label' => 'Phone',
    'required' => 1,
    'settings' => array(
      'ca_phone_parentheses' => 1,
      'ca_phone_separator' => '-',
      'phone_country_code' => 0,
      'phone_default_country_code' => 1,
      'phone_int_max_length' => 15,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'phone',
      'settings' => array(),
      'type' => 'phone_textfield',
      'weight' => 7,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Address');
  t('Body');
  t('Email');
  t('Phone');
  t('Agency category');

  return $field_instances;
}
