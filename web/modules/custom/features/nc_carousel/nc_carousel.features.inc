<?php
/**
 * @file
 * nc_carousel.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nc_carousel_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "bean_admin_ui" && $api == "bean") {
    return array("version" => "5");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function nc_carousel_image_default_styles() {
  $styles = array();

  // Exported image style: carousel___hero.
  $styles['carousel___hero'] = array(
    'label' => 'Carousel / Hero',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1140,
          'height' => 450,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
