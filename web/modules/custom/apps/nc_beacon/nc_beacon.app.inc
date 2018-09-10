<?php
/**
 * @file
 * Required for Apps module.
 */

/**
 * Implements hook_apps_app_info().
 */
function nc_beacon_apps_app_info() {
  return array(
    'configure form' => 'nc_beacon_app_configure_form',
  );
}

/**
 * Implements 'configure form' callback for apps.
 */
function nc_beacon_app_configure_form() {
  $form = array();

  $options = drupal_map_assoc(nc_beacon_get_agencies());
  $form['nc_beacon_default_agency'] = array(
    '#type' => 'select',
    '#title' => t('Default agency for employee directory search'),
    '#description' => t('To restrict employee directory searches to a specific agency, please select one from the dropdown above.'),
    '#options' => $options,
    '#default_value' => variable_get('nc_beacon_default_agency', ''),
    '#required' => FALSE,
    '#multiple' => FALSE,
    '#empty_option' => '- Any -',
    '#empty_value' => '',
  );

  return system_settings_form($form);
}
