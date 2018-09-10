<?php
/**
 * @file
 * Required for Apps module.
 */

/**
 * Implements hook_apps_app_info().
 */
function nc_layout_apps_app_info() {
  return array(
    'configure form' => 'nc_layout_app_configure_form',
    // 'status callback' => 'nc_layout_app_status',
  );
}

/**
 * Implements 'configure form' callback for apps.
 */
function nc_layout_app_configure_form() {
  // Get form elements normally added to form context_ui_settings via
  // context_by_node's alter hook.
  $form = array();
  $form_state = array();
  context_by_node_form_alter($form, $form_state, 'context_ui_settings');
  return system_settings_form($form);
}

/**
 * Implements 'status callback' for apps.
 */
function nc_layout_app_status() {
  // Setup the status table.
  $status = array(
    'title' => 'Status',
    'headers' => array('severity', 'title', 'description', 'action'),
    'items' => array(),
  );

  return $status;
}
