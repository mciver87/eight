<?php
/**
 * @file
 * nc_workflow.features.inc
 */

/**
 * Implements hook_user_default_permissions_alter().
 */
function nc_workflow_user_default_permissions_alter(&$data) {
  if (isset($data['access workbench'])) {
    unset($data['access workbench']['roles']['editor']);
    unset($data['access workbench']['roles']['staff']);
  }
  if (isset($data['administer workbench moderation'])) {
    $data['administer workbench moderation']['roles']['publisher'] = 'publisher'; /* WAS: '' */
  }
  if (isset($data['moderate content from archived to draft'])) {
    unset($data['moderate content from archived to draft']['module']);
    unset($data['moderate content from archived to draft']['roles']['administrator']);
    unset($data['moderate content from archived to draft']['roles']['publisher']);
  }
  if (isset($data['moderate content from archived to published'])) {
    unset($data['moderate content from archived to published']['module']);
    unset($data['moderate content from archived to published']['roles']['administrator']);
    unset($data['moderate content from archived to published']['roles']['publisher']);
  }
  if (isset($data['moderate content from draft to needs_review'])) {
    unset($data['moderate content from draft to needs_review']['roles']['staff']);
  }
  if (isset($data['moderate content from draft to published'])) {
    unset($data['moderate content from draft to published']['module']);
    unset($data['moderate content from draft to published']['roles']['administrator']);
    unset($data['moderate content from draft to published']['roles']['publisher']);
  }
  if (isset($data['moderate content from published to archived'])) {
    unset($data['moderate content from published to archived']['module']);
    unset($data['moderate content from published to archived']['roles']['administrator']);
    unset($data['moderate content from published to archived']['roles']['publisher']);
  }
  if (isset($data['use workbench_moderation my drafts tab'])) {
    unset($data['use workbench_moderation my drafts tab']['roles']['staff']);
  }
  if (isset($data['use workbench_moderation needs review tab'])) {
    unset($data['use workbench_moderation needs review tab']['roles']['staff']);
  }
  if (isset($data['view moderation history'])) {
    unset($data['view moderation history']['roles']['staff']);
  }
  if (isset($data['view moderation messages'])) {
    unset($data['view moderation messages']['roles']['staff']);
  }
}
