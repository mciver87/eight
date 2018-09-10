<?php
/**
 * @file
 * Code for the NC DPS Silver and Amber Alerts feature.
 */

/**
 * Class NcAlertsMissingPersonsMenu
 */
class NcAlertsMissingPersonsMenu {
  const MAIN_MENU_KEY = 'admin/config/nc_dps_alerts';
  const FEED_MENU_KEY = 'admin/config/nc_dps_alerts/feed';

  /**
   * Items.
   *
   * @var array
   */
  protected $items = array();

  /**
   * Options.
   *
   * @var array
   */
  protected $options = array();

  /**
   * Constructor.
   *
   * @param array $options
   *   Pass in options.
   */
  public function __construct($options = array()) {
    $this->setOptions($options);
    $this->setItems($this->initItems());
  }


  /**
   * Get Options.
   *
   * @return array
   *   Return array.
   */
  public function getOptions() {
    return $this->options;
  }


  /**
   * Set options.
   *
   * @param array $options
   *   Options.
   *
   * @return this
   *   Return this.
   */
  public function setOptions($options) {
    $this->options = $options;
    return $this;
  }


  /**
   * Get items.
   *
   * @return array
   *   Returns items.
   */
  public function getItems() {
    return $this->items;
  }


  /**
   * Set items.
   *
   * @param array $items
   *   Items.
   *
   * @return this
   *   Return this.
   */
  public function setItems($items) {
    $this->items = $items;
    return $this;
  }

  /**
   * Initialize items.
   *
   * @return array
   *   Initialized items.
   */
  public function initItems() {
    $items = array();

    $items[static::MAIN_MENU_KEY] = array(
      'title' => 'North Carolina Missing Persons Alerts',
      'description' => 'Configure Silver, Amber, and Blue Alerts',
      'position' => 'left',
      'weight' => 754,
      'page callback' => 'system_admin_menu_block_page',
      'access arguments' => array('administer site configuration'),
      'file' => 'system.admin.inc',
      'file path' => drupal_get_path('module', 'system'),
    );
    // Need at least one child item before your section will appear.
    $items[static::FEED_MENU_KEY] = array(
      'title' => 'Missing Persons RSS Feeds',
      'description' => 'Update DPS Silver, Amber, and Blue Alert Feed Information',
      'page callback' => 'drupal_get_form',
      'page arguments' => array('nc_dps_alerts_admin'),
      'access arguments' => array('administer site configuration'),
    );
    return $items;
  }
}
