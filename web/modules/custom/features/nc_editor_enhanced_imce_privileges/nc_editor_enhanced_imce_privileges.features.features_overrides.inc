<?php
/**
 * @file
 * nc_editor_enhanced_imce_privileges.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function nc_editor_enhanced_imce_privileges_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: variable
  $overrides["variable.imce_profiles.value|2|directories|0|delete"] = 1;
  $overrides["variable.imce_profiles.value|2|mkdirnum"] = 0;

 return $overrides;
}
