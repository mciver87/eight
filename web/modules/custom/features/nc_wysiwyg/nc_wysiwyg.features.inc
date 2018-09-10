<?php
/**
 * @file
 * nc_wysiwyg.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nc_wysiwyg_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Use this to update configuration for CKeditor / WYSIWYG.
 * Specifically at this time this is being used to disable the
 * default CKEditor behavior that causes it to strip empty tags
 * from the WYSIWYG when switching between sources.
 *
 * Implements hook_wysiwyg_editor_settings_alter(&$settings, $context).
 *
 * @param $settings
 * @param $context
 */
function nc_wysiwyg_wysiwyg_editor_settings_alter(&$settings, $context) {
  if ($context['profile']->editor == 'ckeditor') {
    $settings['customConfig'] = base_path() . drupal_get_path('module', 'nc_wysiwyg') . '/ckedit.config.js';
  }
}
