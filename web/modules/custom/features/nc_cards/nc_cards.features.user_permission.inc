<?php
/**
 * @file
 * nc_cards.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function nc_cards_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create any nc_card_animated_stat bean'.
  $permissions['create any nc_card_animated_stat bean'] = array(
    'name' => 'create any nc_card_animated_stat bean',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'delete any nc_card_animated_stat bean'.
  $permissions['delete any nc_card_animated_stat bean'] = array(
    'name' => 'delete any nc_card_animated_stat bean',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit any nc_card_animated_stat bean'.
  $permissions['edit any nc_card_animated_stat bean'] = array(
    'name' => 'edit any nc_card_animated_stat bean',
    'roles' => array(
      'administrator' => 'administrator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any nc_card_animated_stat bean'.
  $permissions['view any nc_card_animated_stat bean'] = array(
    'name' => 'view any nc_card_animated_stat bean',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bean',
  );

  return $permissions;
}
