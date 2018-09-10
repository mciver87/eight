<?php
/**
 * @file
 * nc_roles.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function nc_roles_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 2,
  );

  // Exported role: editor.
  $roles['editor'] = array(
    'name' => 'editor',
    'weight' => 5,
  );

  // Exported role: event creator.
  $roles['event creator'] = array(
    'name' => 'event creator',
    'weight' => 6,
  );

  // Exported role: site admin.
  $roles['site admin'] = array(
    'name' => 'site admin',
    'weight' => 8,
  );

  // Exported role: site manager.
  $roles['site manager'] = array(
    'name' => 'site manager',
    'weight' => 7,
  );

  return $roles;
}
