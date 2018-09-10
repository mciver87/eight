<?php
/**
 * @file
 * nc_responsive_images.default_breakpoints.inc
 */

/**
 * Implements hook_default_breakpoints().
 */
function nc_responsive_images_default_breakpoints() {
  $export = array();

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'breakpoints.theme.nc_base_theme.desktop';
  $breakpoint->name = 'desktop';
  $breakpoint->breakpoint = '(min-width: 1024px)';
  $breakpoint->source = 'nc_base_theme';
  $breakpoint->source_type = 'theme';
  $breakpoint->status = 1;
  $breakpoint->weight = 1;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['breakpoints.theme.nc_base_theme.desktop'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'breakpoints.theme.nc_base_theme.desktop_wide';
  $breakpoint->name = 'desktop_wide';
  $breakpoint->breakpoint = 'only screen and (min-width: 1280px)';
  $breakpoint->source = 'nc_base_theme';
  $breakpoint->source_type = 'theme';
  $breakpoint->status = 1;
  $breakpoint->weight = 0;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['breakpoints.theme.nc_base_theme.desktop_wide'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'breakpoints.theme.nc_base_theme.phablet';
  $breakpoint->name = 'phablet';
  $breakpoint->breakpoint = '(min-width: 480px)';
  $breakpoint->source = 'nc_base_theme';
  $breakpoint->source_type = 'theme';
  $breakpoint->status = 1;
  $breakpoint->weight = 3;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['breakpoints.theme.nc_base_theme.phablet'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'breakpoints.theme.nc_base_theme.phone';
  $breakpoint->name = 'phone';
  $breakpoint->breakpoint = '(min-width: 0px)';
  $breakpoint->source = 'nc_base_theme';
  $breakpoint->source_type = 'theme';
  $breakpoint->status = 1;
  $breakpoint->weight = 4;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['breakpoints.theme.nc_base_theme.phone'] = $breakpoint;

  $breakpoint = new stdClass();
  $breakpoint->disabled = FALSE; /* Edit this to true to make a default breakpoint disabled initially */
  $breakpoint->api_version = 1;
  $breakpoint->machine_name = 'breakpoints.theme.nc_base_theme.tablet';
  $breakpoint->name = 'tablet';
  $breakpoint->breakpoint = '(min-width: 768px)';
  $breakpoint->source = 'nc_base_theme';
  $breakpoint->source_type = 'theme';
  $breakpoint->status = 1;
  $breakpoint->weight = 2;
  $breakpoint->multipliers = array(
    '1x' => '1x',
  );
  $export['breakpoints.theme.nc_base_theme.tablet'] = $breakpoint;

  return $export;
}
