<?php
/**
 * @file
 * nc_event.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function nc_event_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administrator addressfield nc_addressfield_staticmap'.
  $permissions['administrator addressfield nc_addressfield_staticmap'] = array(
    'name' => 'administrator addressfield nc_addressfield_staticmap',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'nc_addressfield_staticmap',
  );

  return $permissions;
}
