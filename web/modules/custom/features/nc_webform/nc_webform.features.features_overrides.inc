<?php
/**
 * @file
 * nc_webform.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function nc_webform_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: variable
  $overrides["variable.node_preview_webform.value"] = 0;
  $overrides["variable.node_submitted_webform.value"] = 0;

 return $overrides;
}
