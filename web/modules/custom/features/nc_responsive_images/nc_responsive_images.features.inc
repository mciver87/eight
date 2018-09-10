<?php
/**
 * @file
 * nc_responsive_images.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nc_responsive_images_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "breakpoints" && $api == "default_breakpoint_group") {
    return array("version" => "1");
  }
  if ($module == "breakpoints" && $api == "default_breakpoints") {
    return array("version" => "1");
  }
  if ($module == "picture" && $api == "default_picture_mapping") {
    return array("version" => "2");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function nc_responsive_images_image_default_styles() {
  $styles = array();

  // Exported image style: resp_hero-breakpoints_theme_nc_base_theme_desktop_1x.
  $styles['resp_hero-breakpoints_theme_nc_base_theme_desktop_1x'] = array(
    'name' => 'resp_hero-breakpoints_theme_nc_base_theme_desktop_1x',
    'label' => 'resp_hero-breakpoints_theme_nc_base_theme_desktop_1x',
    'effects' => array(
      6 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1024,
          'height' => 410,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: resp_hero-breakpoints_theme_nc_base_theme_phablet_1x.
  $styles['resp_hero-breakpoints_theme_nc_base_theme_phablet_1x'] = array(
    'name' => 'resp_hero-breakpoints_theme_nc_base_theme_phablet_1x',
    'label' => 'resp_hero-breakpoints_theme_nc_base_theme_phablet_1x',
    'effects' => array(
      8 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 480,
          'height' => 192,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: resp_hero-breakpoints_theme_nc_base_theme_phone_1x.
  $styles['resp_hero-breakpoints_theme_nc_base_theme_phone_1x'] = array(
    'name' => 'resp_hero-breakpoints_theme_nc_base_theme_phone_1x',
    'label' => 'resp_hero-breakpoints_theme_nc_base_theme_phone_1x',
    'effects' => array(
      9 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 320,
          'height' => 128,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: resp_hero-breakpoints_theme_nc_base_theme_tablet_1x.
  $styles['resp_hero-breakpoints_theme_nc_base_theme_tablet_1x'] = array(
    'name' => 'resp_hero-breakpoints_theme_nc_base_theme_tablet_1x',
    'label' => 'resp_hero-breakpoints_theme_nc_base_theme_tablet_1x',
    'effects' => array(
      7 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 768,
          'height' => 307,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
