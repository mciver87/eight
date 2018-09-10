<?php
/**
 * @file
 * nc_cards.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nc_cards_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function nc_cards_image_default_styles() {
  $styles = array();

  // Exported image style: card_photo.
  $styles['card_photo'] = array(
    'label' => 'Card Photo',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 500,
          'height' => 376,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: nc_event_card.
  $styles['nc_event_card'] = array(
    'label' => 'NC Event Card',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 800,
          'height' => 450,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
