<?php
/**
 * @file
 * Contains DPS menu/breadcrumb migration.
 */

class MigrateDPSPageMenu extends MigrateDPSBase {
  /**
   * Constructor.
   */
  public function __construct($args) {
    parent::__construct($args);

    $url_source = variable_get('nc_migrate_dps_page_menu', FALSE);
    if ($url_source) {
      $columns = array(
        0 => array('id', 'Menu ID'),
        1 => array('ref_parent', 'Parent Ref'),
        2 => array('menu_1', 'Menu Level 1'),
        3 => array('menu_2', 'Menu Level 2'),
        4 => array('menu_3', 'Menu Level 3'),
        5 => array('menu_4', 'Menu Level 4'),
        6 => array('menu_5', 'Menu Level 5'),
        7 => array('menu_6', 'Menu Level 6'),
        8 => array('menu_7', 'Menu Level 7'),
        9 => array('path', 'path'),
        12 => array('type', 'Page type'),
        103 => array('weight', 'Weight'),
      );
      $options = array(
        'header_rows' => 1,
      );
      $this->source = new MigrateDPSCSVSource($url_source, $columns, $options);
    }

    $this->destination = new MigrateDestinationMenuLinks();
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'id' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'ID of destination link',
        ),
      ),
      MigrateDestinationMenuLinks::getKeySchema()
    );

    // Add simple mappings.
    $this->addSimpleMappings(array(
      'weight',
    ));

    // Add custom field mappings.
    $this->addFieldMapping('menu_name')->defaultValue('main-menu');
    $this->addFieldMapping('plid', 'ref_parent')->sourceMigration($this->getMachineName());
    $this->addFieldMapping('link_path', 'path');
    $this->addFieldMapping('router_path')->defaultValue('node/%');
    $this->addFieldMapping('link_title', 'title');
    $this->addFieldMapping('external')->defaultValue('0');
    $this->addFieldMapping('expanded')->defaultValue('0');
    $this->addFieldMapping('customized')->defaultValue('1');
    $this->addFieldMapping('has_children')->defaultValue('0');
    $this->addFieldMapping('depth')->defaultValue('1');
  }

  /**
   * Prepare a row.
   */
  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
    // Fix the path.
    if (strpos($row->path, '/') === 0) {
      $row->path = substr($row->path, 1);
    }

    // Convert the alias to the node path.
    $node_path = drupal_lookup_path('source', $row->path);
    if ($node_path == FALSE) {
      return FALSE;
    }

    // Make sure we have a title.
    if (empty($row->title)) {
      $message = t('Missing title for row !row', array('!row' => $row->id));
      $this->getMap()->saveMessage(array($row->id), $message, MigrationBase::MESSAGE_NOTICE);
      return FALSE;
    }
    $row->path = $node_path;
    $row->weight = 0;
    return TRUE;
  }

  /**
   * Creates a stub menu link, for when a child is imported before its parent.
   *
   * @param object $migration
   *   The source migration
   *
   * @return mixed
   *   int $mlid on success
   *   FALSE on failure
   */
  protected function createStub($migration) {
    // If ref_parent is 0, that means it has no parent, so don't create a stub.
    if (!$migration->sourceValues->ref_parent) {
      return FALSE;
    }
    $menu_link = array(
      'menu_name' => $this->destinationValues->menu_name,
      'link_path' => 'stub-path',
      'router_path' => 'stub-path',
      'link_title' => t('Stub title'),
    );
    $mlid = menu_link_save($menu_link);
    if ($mlid) {
      return array($mlid);
    }
    else {
      return FALSE;
    }
  }

  /**
   * Process an entity prior to saving it.
   */
  public function prepare($entity, $row) {
    // Check if we have this menu item already via name lookup.
    $mlid = db_select('menu_links', 'm')
      ->fields('m', array('mlid'))
      ->condition('link_path', $row->path, '=')
      ->execute()
      ->fetchField();
    if ($mlid) {
      $entity->mlid = $mlid;
    }
  }
}
