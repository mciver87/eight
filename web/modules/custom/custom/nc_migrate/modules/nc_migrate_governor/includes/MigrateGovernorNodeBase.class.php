<?php
/**
 * @file
 * Contains base class for Governor node migrations.
 */

/**
 * Class definition for MigrateGovernorNodeBase.
 */
class MigrateGovernorNodeBase extends MigrateGovernorBase {
  /**
   * Simple initialization.
   *
   * @param array $args
   *  Arguments used to dynamically create a migration, contains:
   *   @param string appname
   *    The short app name from GatherContent.
   *   @param string apikey
   *    The API key from GatherContent.
   *   @param object project
   *    The project to load pages and templates from.
   *   @param object template
   *    The template to filter pages on.
   *   @param string node_type
   *    Drupal content type to migrate into.
   *   @param array fields
   *    The field mappings to add.
   */
  public function __construct($args) {
    parent::__construct($args);
  }

  /**
   * Preprocess the entity prior to saving it.
   */
  public function prepare($entity, $row) {
    /*
     * If workbench_moderation is enabled, add correct flags if node status
     * is set to published.
     * https://www.drupal.org/node/1452016#comment-8503687
     */
    if (module_exists('workbench_moderation') && isset($entity->status)) {
      $entity->revision = TRUE;
      $entity->is_new = !(isset($entity->nid) && ($entity->nid));
      $entity->workbench_moderation_state_current = 'published';
      $entity->workbench_moderation_state_new = 'published';
    }
  }
}
