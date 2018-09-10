<?php
/**
 * @file
 * nc_catalog.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function nc_catalog_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create catalog content'.
  $permissions['create catalog content'] = array(
    'name' => 'create catalog content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any catalog content'.
  $permissions['delete any catalog content'] = array(
    'name' => 'delete any catalog content',
    'roles' => array(
      'administrator' => 'administrator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own catalog content'.
  $permissions['delete own catalog content'] = array(
    'name' => 'delete own catalog content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in catalog'.
  $permissions['delete terms in catalog'] = array(
    'name' => 'delete terms in catalog',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in catalog_category'.
  $permissions['delete terms in catalog_category'] = array(
    'name' => 'delete terms in catalog_category',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit any catalog content'.
  $permissions['edit any catalog content'] = array(
    'name' => 'edit any catalog content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own catalog content'.
  $permissions['edit own catalog content'] = array(
    'name' => 'edit own catalog content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in catalog'.
  $permissions['edit terms in catalog'] = array(
    'name' => 'edit terms in catalog',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in catalog_category'.
  $permissions['edit terms in catalog_category'] = array(
    'name' => 'edit terms in catalog_category',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  return $permissions;
}
