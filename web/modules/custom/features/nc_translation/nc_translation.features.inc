<?php
/**
 * @file
 * nc_translation.features.inc
 */

/**
 * Implements hook_context_default_contexts_alter().
 */
function nc_translation_context_default_contexts_alter(&$data) {
  if (isset($data['language_switch'])) {
    $data['language_switch']->conditions['admin_theme'] = array(
      'values' => array(
        'non_admin' => 'non_admin',
      ),
    ); /* WAS: '' */
    $data['language_switch']->hidden = 0; /* WAS: '' */
    unset($data['language_switch']->reactions['block']);
  }
}

/**
 * Implements hook_strongarm_alter().
 */
function nc_translation_strongarm_alter(&$data) {
  if (isset($data['language_negotiation_language_content'])) {
    $data['language_negotiation_language_content']->value['locale-interface'] = array(
      'callbacks' => array(
        'language' => 'locale_language_from_interface',
      ),
      'file' => 'includes/locale.inc',
    ); /* WAS: '' */
    unset($data['language_negotiation_language_content']->value['language-default']);
    unset($data['language_negotiation_language_content']->value['locale-url']);
  }
}
