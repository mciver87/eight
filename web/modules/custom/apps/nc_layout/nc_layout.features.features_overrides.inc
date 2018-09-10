<?php
/**
 * @file
 * nc_layout.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function nc_layout_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: context
  $overrides["context.leadership.conditions|path"]["DELETED"] = TRUE;

 return $overrides;
}
