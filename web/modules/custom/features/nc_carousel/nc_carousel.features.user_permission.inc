<?php
/**
 * @file
 * nc_carousel.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function nc_carousel_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'view any nc_carousel bean'.
  $permissions['view any nc_carousel bean'] = array(
    'name' => 'view any nc_carousel bean',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bean',
  );

  return $permissions;
}
