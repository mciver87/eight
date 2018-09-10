<?php
/**
 * @file
 * nc_menus.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function nc_menus_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: enterprise-nav-menu.
  $menus['enterprise-nav-menu'] = array(
    'menu_name' => 'enterprise-nav-menu',
    'title' => 'Enterprise Navigation',
    'description' => 'Navigation used in the top of the header.',
    'language' => 'und',
    'i18n_mode' => 0,
  );
  // Exported menu: main-menu.
  $menus['main-menu'] = array(
    'menu_name' => 'main-menu',
    'title' => 'Main menu',
    'description' => 'The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.',
    'language' => 'und',
    'i18n_mode' => 0,
  );
  // Exported menu: network-menu.
  $menus['network-menu'] = array(
    'menu_name' => 'network-menu',
    'title' => 'Network Menu',
    'description' => 'Navigation used in the bottom of the footer.',
    'language' => 'und',
    'i18n_mode' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Enterprise Navigation');
  t('Main menu');
  t('Navigation used in the bottom of the footer.');
  t('Navigation used in the top of the header.');
  t('Network Menu');
  t('The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.');


  return $menus;
}
