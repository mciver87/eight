<?php
/**
 * @file
 * nc_responsive_images.default_picture_mapping.inc
 */

/**
 * Implements hook_default_picture_mapping().
 */
function nc_responsive_images_default_picture_mapping() {
  $export = array();

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Hero Image Picture Mapping';
  $picture_mapping->machine_name = 'hero_image_picture_mapping';
  $picture_mapping->breakpoint_group = 'hero';
  $picture_mapping->mapping = array(
    'breakpoints.theme.nc_base_theme.desktop_wide' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'carousel___hero',
      ),
    ),
    'breakpoints.theme.nc_base_theme.desktop' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'resp_hero-breakpoints_theme_nc_base_theme_desktop_1x',
      ),
    ),
    'breakpoints.theme.nc_base_theme.tablet' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'resp_hero-breakpoints_theme_nc_base_theme_tablet_1x',
      ),
    ),
    'breakpoints.theme.nc_base_theme.phablet' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'resp_hero-breakpoints_theme_nc_base_theme_phablet_1x',
      ),
    ),
    'breakpoints.theme.nc_base_theme.phone' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'resp_hero-breakpoints_theme_nc_base_theme_phone_1x',
      ),
    ),
  );
  $export['hero_image_picture_mapping'] = $picture_mapping;

  return $export;
}
