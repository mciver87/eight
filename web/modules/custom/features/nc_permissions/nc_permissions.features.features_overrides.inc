<?php
/**
 * @file
 * nc_permissions.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function nc_permissions_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: user_permission
  $overrides["user_permission.access workbench.roles|event creator"] = 'event creator';
  $overrides["user_permission.access workbench.roles|site admin"] = 'site admin';
  $overrides["user_permission.access workbench.roles|site manager"] = 'site manager';
  $overrides["user_permission.administer workbench moderation.roles|site admin"] = 'site admin';
  $overrides["user_permission.administer workbench moderation.roles|site manager"] = 'site manager';
  $overrides["user_permission.administer workbench.roles|site admin"] = 'site admin';
  $overrides["user_permission.administer workbench.roles|site manager"] = 'site manager';
  $overrides["user_permission.bypass workbench moderation.roles|site admin"] = 'site admin';
  $overrides["user_permission.bypass workbench moderation.roles|site manager"] = 'site manager';
  $overrides["user_permission.moderate content from draft to needs_review.roles|event creator"] = 'event creator';
  $overrides["user_permission.moderate content from draft to needs_review.roles|site admin"] = 'site admin';
  $overrides["user_permission.moderate content from draft to needs_review.roles|site manager"] = 'site manager';
  $overrides["user_permission.moderate content from needs_review to draft.roles|site admin"] = 'site admin';
  $overrides["user_permission.moderate content from needs_review to draft.roles|site manager"] = 'site manager';
  $overrides["user_permission.moderate content from needs_review to published.roles|site admin"] = 'site admin';
  $overrides["user_permission.moderate content from needs_review to published.roles|site manager"] = 'site manager';
  $overrides["user_permission.use workbench_moderation my drafts tab.roles|event creator"] = 'event creator';
  $overrides["user_permission.use workbench_moderation my drafts tab.roles|site admin"] = 'site admin';
  $overrides["user_permission.use workbench_moderation my drafts tab.roles|site manager"] = 'site manager';
  $overrides["user_permission.use workbench_moderation needs review tab.roles|event creator"] = 'event creator';
  $overrides["user_permission.use workbench_moderation needs review tab.roles|site admin"] = 'site admin';
  $overrides["user_permission.use workbench_moderation needs review tab.roles|site manager"] = 'site manager';
  $overrides["user_permission.view all unpublished content.roles|event creator"] = 'event creator';
  $overrides["user_permission.view all unpublished content.roles|site admin"] = 'site admin';
  $overrides["user_permission.view all unpublished content.roles|site manager"] = 'site manager';
  $overrides["user_permission.view moderation history.roles|event creator"] = 'event creator';
  $overrides["user_permission.view moderation history.roles|site admin"] = 'site admin';
  $overrides["user_permission.view moderation history.roles|site manager"] = 'site manager';
  $overrides["user_permission.view moderation messages.roles|site admin"] = 'site admin';

 return $overrides;
}
