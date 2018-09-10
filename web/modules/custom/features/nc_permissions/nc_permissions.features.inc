<?php
/**
 * @file
 * nc_permissions.features.inc
 */

/**
 * Implements hook_user_default_permissions_alter().
 */
function nc_permissions_user_default_permissions_alter(&$data) {
  if (isset($data['access workbench'])) {
    $data['access workbench']['roles']['event creator'] = 'event creator'; /* WAS: '' */
    $data['access workbench']['roles']['site admin'] = 'site admin'; /* WAS: '' */
    $data['access workbench']['roles']['site manager'] = 'site manager'; /* WAS: '' */
  }
  if (isset($data['administer workbench moderation'])) {
    $data['administer workbench moderation']['roles']['site admin'] = 'site admin'; /* WAS: '' */
    $data['administer workbench moderation']['roles']['site manager'] = 'site manager'; /* WAS: '' */
  }
  if (isset($data['administer workbench'])) {
    $data['administer workbench']['roles']['site admin'] = 'site admin'; /* WAS: '' */
    $data['administer workbench']['roles']['site manager'] = 'site manager'; /* WAS: '' */
  }
  if (isset($data['bypass workbench moderation'])) {
    $data['bypass workbench moderation']['roles']['site admin'] = 'site admin'; /* WAS: '' */
    $data['bypass workbench moderation']['roles']['site manager'] = 'site manager'; /* WAS: '' */
  }
  if (isset($data['moderate content from draft to needs_review'])) {
    $data['moderate content from draft to needs_review']['roles']['event creator'] = 'event creator'; /* WAS: '' */
    $data['moderate content from draft to needs_review']['roles']['site admin'] = 'site admin'; /* WAS: '' */
    $data['moderate content from draft to needs_review']['roles']['site manager'] = 'site manager'; /* WAS: '' */
  }
  if (isset($data['moderate content from needs_review to draft'])) {
    $data['moderate content from needs_review to draft']['roles']['site admin'] = 'site admin'; /* WAS: '' */
    $data['moderate content from needs_review to draft']['roles']['site manager'] = 'site manager'; /* WAS: '' */
  }
  if (isset($data['moderate content from needs_review to published'])) {
    $data['moderate content from needs_review to published']['roles']['site admin'] = 'site admin'; /* WAS: '' */
    $data['moderate content from needs_review to published']['roles']['site manager'] = 'site manager'; /* WAS: '' */
  }
  if (isset($data['use workbench_moderation my drafts tab'])) {
    $data['use workbench_moderation my drafts tab']['roles']['event creator'] = 'event creator'; /* WAS: '' */
    $data['use workbench_moderation my drafts tab']['roles']['site admin'] = 'site admin'; /* WAS: '' */
    $data['use workbench_moderation my drafts tab']['roles']['site manager'] = 'site manager'; /* WAS: '' */
  }
  if (isset($data['use workbench_moderation needs review tab'])) {
    $data['use workbench_moderation needs review tab']['roles']['event creator'] = 'event creator'; /* WAS: '' */
    $data['use workbench_moderation needs review tab']['roles']['site admin'] = 'site admin'; /* WAS: '' */
    $data['use workbench_moderation needs review tab']['roles']['site manager'] = 'site manager'; /* WAS: '' */
  }
  if (isset($data['view all unpublished content'])) {
    $data['view all unpublished content']['roles']['event creator'] = 'event creator'; /* WAS: '' */
    $data['view all unpublished content']['roles']['site admin'] = 'site admin'; /* WAS: '' */
    $data['view all unpublished content']['roles']['site manager'] = 'site manager'; /* WAS: '' */
  }
  if (isset($data['view moderation history'])) {
    $data['view moderation history']['roles']['event creator'] = 'event creator'; /* WAS: '' */
    $data['view moderation history']['roles']['site admin'] = 'site admin'; /* WAS: '' */
    $data['view moderation history']['roles']['site manager'] = 'site manager'; /* WAS: '' */
  }
  if (isset($data['view moderation messages'])) {
    $data['view moderation messages']['roles']['site admin'] = 'site admin'; /* WAS: '' */
  }
}
