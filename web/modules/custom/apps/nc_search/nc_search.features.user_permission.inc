<?php
/**
 * @file
 * nc_search.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function nc_search_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer nc search'.
  $permissions['administer nc search'] = array(
    'name' => 'administer nc search',
    'roles' => array(),
    'module' => 'nc_search',
  );

  // Exported permission: 'search nc content'.
  $permissions['search nc content'] = array(
    'name' => 'search nc content',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'site admin' => 'site admin',
    ),
    'module' => 'nc_search',
  );

  return $permissions;
}
