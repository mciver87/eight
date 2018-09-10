<?php
/**
 * @file
 * nc_translation.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function nc_translation_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: context
  $overrides["context.language_switch.conditions|admin_theme"] = array(
    'values' => array(
      'non_admin' => 'non_admin',
    ),
  );
  $overrides["context.language_switch.hidden"] = 0;
  $overrides["context.language_switch.reactions|block"]["DELETED"] = TRUE;

  // Exported overrides for: variable
  $overrides["variable.language_negotiation_language_content.value|language-default"]["DELETED"] = TRUE;
  $overrides["variable.language_negotiation_language_content.value|locale-interface"] = array(
    'callbacks' => array(
      'language' => 'locale_language_from_interface',
    ),
    'file' => 'includes/locale.inc',
  );
  $overrides["variable.language_negotiation_language_content.value|locale-url"]["DELETED"] = TRUE;

 return $overrides;
}
