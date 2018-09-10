<?php
/**
 * @file
 * nc_social.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function nc_social_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create any nc_social_follow_us bean'.
  $permissions['create any nc_social_follow_us bean'] = array(
    'name' => 'create any nc_social_follow_us bean',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'delete any nc_social_follow_us bean'.
  $permissions['delete any nc_social_follow_us bean'] = array(
    'name' => 'delete any nc_social_follow_us bean',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit any nc_social_follow_us bean'.
  $permissions['edit any nc_social_follow_us bean'] = array(
    'name' => 'edit any nc_social_follow_us bean',
    'roles' => array(
      'administrator' => 'administrator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any nc_social_follow_us bean'.
  $permissions['view any nc_social_follow_us bean'] = array(
    'name' => 'view any nc_social_follow_us bean',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bean',
  );

  return $permissions;
}
