<?php
/**
 * @file
 * Views classes and hooks for nc_cards.
 */

/**
 * Implements hook_views_plugins().
 */
function nc_cards_views_plugins() {
  return array(
    'style' => array(
      'card' => array(
        'title' => t('Card'),
        'help' => t('Displays a card.'),
        'handler' => 'views_plugin_style_card',
        'path' => drupal_get_path('module', 'nc_cards/views/plugins'),
        'uses row plugin' => TRUE,
        'uses options' => TRUE,
        'type' => 'normal',
      ),
    ),
    'row' => array(
      'service_fields' => array(
        'title' => t('Service Card'),
        'help' => t('Display fields as a Service card.'),
        'handler' => 'views_plugin_row_card_service',
        'path' => drupal_get_path('module', 'nc_cards/views/plugins'),
        'uses fields' => TRUE,
        'uses options' => TRUE,
        'type' => 'normal',
      ),
      'agency_fields' => array(
        'title' => t('Agency Card'),
        'help' => t('Display fields as an Agency card.'),
        'handler' => 'views_plugin_row_card_agency',
        'path' => drupal_get_path('module', 'nc_cards/views/plugins'),
        'uses fields' => TRUE,
        'uses options' => TRUE,
        'type' => 'normal',
      ),
      'person_fields' => array(
        'title' => t('Person Card'),
        'help' => t('Display fields as a Person card.'),
        'handler' => 'views_plugin_row_card_person',
        'path' => drupal_get_path('module', 'nc_cards/views/plugins'),
        'uses fields' => TRUE,
        'uses options' => TRUE,
        'type' => 'normal',
      ),
    ),
  );
}
