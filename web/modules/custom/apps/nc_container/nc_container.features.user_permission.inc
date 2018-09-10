<?php
/**
 * @file
 * nc_container.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function nc_container_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create application_container content'.
  $permissions['create application_container content'] = array(
    'name' => 'create application_container content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any application_container content'.
  $permissions['delete any application_container content'] = array(
    'name' => 'delete any application_container content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own application_container content'.
  $permissions['delete own application_container content'] = array(
    'name' => 'delete own application_container content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any application_container content'.
  $permissions['edit any application_container content'] = array(
    'name' => 'edit any application_container content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own application_container content'.
  $permissions['edit own application_container content'] = array(
    'name' => 'edit own application_container content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
