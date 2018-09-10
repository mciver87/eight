<?php
/**
 * @file
 * nc_responsive_images.default_breakpoint_group.inc
 */

/**
 * Implements hook_default_breakpoint_group().
 */
function nc_responsive_images_default_breakpoint_group() {
  $export = array();

  $breakpoint_group = new stdClass();
  $breakpoint_group->disabled = FALSE; /* Edit this to true to make a default breakpoint_group disabled initially */
  $breakpoint_group->api_version = 1;
  $breakpoint_group->machine_name = 'hero';
  $breakpoint_group->name = 'Hero';
  $breakpoint_group->breakpoints = array(
    0 => 'breakpoints.theme.nc_base_theme.desktop_wide',
    1 => 'breakpoints.theme.nc_base_theme.desktop',
    2 => 'breakpoints.theme.nc_base_theme.tablet',
    3 => 'breakpoints.theme.nc_base_theme.phablet',
    4 => 'breakpoints.theme.nc_base_theme.phone',
  );
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['hero'] = $breakpoint_group;

  $breakpoint_group = new stdClass();
  $breakpoint_group->disabled = FALSE; /* Edit this to true to make a default breakpoint_group disabled initially */
  $breakpoint_group->api_version = 1;
  $breakpoint_group->machine_name = 'nc_base_theme';
  $breakpoint_group->name = 'North Carolina Theme';
  $breakpoint_group->breakpoints = array(
    0 => 'breakpoints.theme.nc_base_theme.desktop_wide',
    1 => 'breakpoints.theme.nc_base_theme.desktop',
    2 => 'breakpoints.theme.nc_base_theme.tablet',
    3 => 'breakpoints.theme.nc_base_theme.phablet',
    4 => 'breakpoints.theme.nc_base_theme.phone',
  );
  $breakpoint_group->type = 'theme';
  $breakpoint_group->overridden = 0;
  $export['nc_base_theme'] = $breakpoint_group;

  return $export;
}
