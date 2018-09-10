<?php

/**
 * @file
 * Required for Apps module.
 */

/**
 * Implemens of hook_apps_app_info().
 */
function nc_search_apps_app_info() {
  return array(
    'configure form' => 'nc_search_app_configure_form',
  );
}

/**
 * Configuration form for NC Search.
 */
function nc_search_app_configure_form($form, &$form_state) {
  $access = user_access('administer nc search');
  $form['nc_search_textfield'] = array(
    '#type' => 'fieldset',
    '#title' => t('Search box'),
    '#collapsible' => TRUE,
    '#access' => $access,
  );
  $form['nc_search_textfield']['nc_search_placeholder_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Placeholder text'),
    '#description' => t('This will appear as placeholder text in the search box. Limited to 60 characters.'),
    '#default_value' => variable_get('nc_search_placeholder_text', 'Search...'),
    '#size' => 60,
    '#maxlenth' => 60,
    '#required' => TRUE,
    '#access' => $access,
  );
  $form['nc_search_textfield']['nc_search_title_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#description' => t('This will render as the HTML title attribute in the search box.'),
    '#default_value' => variable_get('nc_search_title_text', 'Enter the terms you wish to search for.'),
    '#required' => TRUE,
    '#access' => $access,
  );

  $form['nc_search_textfield']['nc_search_default_to_google'] = array(
    '#type' => 'radios',
    '#title' => t('Use Google CSE in Header'),
    '#options' => array(
      FALSE => t('No'),
      TRUE => t('Yes'),
    ),
    '#description' => t('This will use the Google Site Search feature for searches submitted from page header.'),
    '#default_value' => variable_get('nc_search_default_to_google', FALSE),
    '#required' => TRUE,
    '#access' => $access,
  );

  return system_settings_form($form);
}

/**
 * Form validation for NC Search config form.
 *
 * @see nc_search_app_configure_form
 */
function nc_search_app_configure_form_validate(&$form, &$form_state) {
  if (strlen($form_state['values']['nc_search_placeholder_text']) > 60) {
    form_error($form['nc_search_textfield']['nc_search_placeholder_text'], t('Text exceeds character limit of 60.'));
  }
}
