<?php
/**
 * @file
 * nc_editor_enhanced_imce_privileges.features.inc
 */

/**
 * Implements hook_strongarm_alter().
 */
function nc_editor_enhanced_imce_privileges_strongarm_alter(&$data) {
  if (isset($data['imce_profiles'])) {
    $data['imce_profiles']->value[2]['directories'][0]['delete'] = 1; /* WAS: 0 */
    $data['imce_profiles']->value[2]['mkdirnum'] = 0; /* WAS: 2 */
  }
}
