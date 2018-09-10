<?php
/**
 * @file
 * nc_workflow.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function nc_workflow_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: user_permission
  $overrides["user_permission.access workbench.roles|editor"]["DELETED"] = TRUE;
  $overrides["user_permission.access workbench.roles|staff"]["DELETED"] = TRUE;
  $overrides["user_permission.administer workbench moderation.roles|publisher"] = 'publisher';
  $overrides["user_permission.moderate content from archived to draft.module"]["DELETED"] = TRUE;
  $overrides["user_permission.moderate content from archived to draft.roles|administrator"]["DELETED"] = TRUE;
  $overrides["user_permission.moderate content from archived to draft.roles|publisher"]["DELETED"] = TRUE;
  $overrides["user_permission.moderate content from archived to published.module"]["DELETED"] = TRUE;
  $overrides["user_permission.moderate content from archived to published.roles|administrator"]["DELETED"] = TRUE;
  $overrides["user_permission.moderate content from archived to published.roles|publisher"]["DELETED"] = TRUE;
  $overrides["user_permission.moderate content from draft to needs_review.roles|staff"]["DELETED"] = TRUE;
  $overrides["user_permission.moderate content from draft to published.module"]["DELETED"] = TRUE;
  $overrides["user_permission.moderate content from draft to published.roles|administrator"]["DELETED"] = TRUE;
  $overrides["user_permission.moderate content from draft to published.roles|publisher"]["DELETED"] = TRUE;
  $overrides["user_permission.moderate content from published to archived.module"]["DELETED"] = TRUE;
  $overrides["user_permission.moderate content from published to archived.roles|administrator"]["DELETED"] = TRUE;
  $overrides["user_permission.moderate content from published to archived.roles|publisher"]["DELETED"] = TRUE;
  $overrides["user_permission.use workbench_moderation my drafts tab.roles|staff"]["DELETED"] = TRUE;
  $overrides["user_permission.use workbench_moderation needs review tab.roles|staff"]["DELETED"] = TRUE;
  $overrides["user_permission.view moderation history.roles|staff"]["DELETED"] = TRUE;
  $overrides["user_permission.view moderation messages.roles|staff"]["DELETED"] = TRUE;

 return $overrides;
}
