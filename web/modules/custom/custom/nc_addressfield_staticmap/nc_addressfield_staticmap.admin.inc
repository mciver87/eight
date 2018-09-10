<?php
/**
 * @file
 * Sets up the admin menu for the module
 */


/**
 * Admin form callback.
 */
function _nc_addressfield_staticmap_admin_form($form, &$form_state) {
  $form['nc_addressfield_staticmap_endpoint'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Static Map Endpoint'),
    '#default_value' => variable_get('nc_addressfield_staticmap_endpoint', 'https://nonprod-staticmapgen.dc.nc.gov'),
    '#size'          => 100,
    '#maxlength'     => 100,
    '#description'   => t('The endpoint used to generate a static map image.'),
    '#required'      => TRUE,
  );

  return system_settings_form($form);
}
