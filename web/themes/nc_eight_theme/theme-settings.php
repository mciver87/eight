<?php
/**
 * @file
 * Contains the file's theme settings.
 */

/**
 * Implements hook_form_system_theme_settings_alter().
 */
function nc_base_theme_form_system_theme_settings_alter(&$form, &$form_state) {
  // Logo support of SVG files.
  $default_svg = theme_get_setting('logo_svg_path');
  $form['logo']['logo_svg_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Path to SVG logo'),
    '#description' => t('The path to the file you would like to use as your SVG logo file.'),
    '#default_value' => $default_svg,
    '#element_validate' => array('_nc_base_theme_logo_svg_path_validate'),
  );

  $form['logo']['logo_svg_upload'] = array(
    '#type' => 'file',
    '#title' => t('Upload SVG logo image'),
    '#maxlength' => 40,
    '#description' => t("If you don't have direct file access to the server, use this field to upload your SVG logo."),
    '#element_validate' => array('_nc_base_theme_logo_svg_upload_validate'),
  );

  // Color Profile.
  $form['nc_base_theme_settings']['color_profile_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Color Profile'),
  );
  $form['nc_base_theme_settings']['color_profile_fieldset']['color_profile'] = array(
    '#type' => 'select',
    '#title' => t('Color Profile Variants'),
    '#default_value' => theme_get_setting('color_profile'),
    '#description' => t('Choose a color profiles for variants of site-wide color configurations.'),
    '#options' => array(
      'default' => t("Default"),
      'governor' => t("Governor's Office"),
      'ncdcr' => t("Cultural Resources"),
      'ncdenr' => t("Environment and Natural Resources"),
      'ncdhhs' => t("Health and Human Services"),
      'ncdoa' => t("Administration"),
      'ncdoc' => t("Commerce"),
      'ncdor' => t("Revenue"),
      'ncdps' => t("Public Safety"),
      'ncgov' => t("NC.gov"),
      'ncoits' => t("Information Technology Services"),
      'ncosbm' => t("Budget Management"),
      'ncoshr' => t("Human Resources"),
      'ncdmva' => t("Military & Veteran's Affairs"),
      'ncdma' => t("Medical Assistance"),
      'nchiea' => t("Health Information Exchange Authority"),
      'ltgov' => t("Lt. Governor"),
      'qar' => t("Queen Anne's Revenge"),
      'nhp' => t("National Heritage Program"),
      'osa' => t("Office of State Archaeology"),

    ),
  );
  // Enterprise Header Theme.
  $form['nc_base_theme_settings']['color_profile_fieldset']['enterprise_header_theme'] = array(
    '#type'          => 'select',
    '#title'         => t('Enterprise Header Theme'),
    '#default_value' => theme_get_setting('enterprise_header_theme') ? theme_get_setting('enterprise_header_theme') : 'enterprise-core-dark',
    '#options'       => array(
      'enterprise-core-dark'      => t('Dark'),
      'enterprise-core-white'     => t('White'),
      'enterprise-core-off-white' => t('Off White'),
    ),
  );
  // Mega Menu.
  $form['nc_base_theme_settings']['mega_menu_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Mega Menu'),
  );
  $form['nc_base_theme_settings']['mega_menu_fieldset']['mega_menu'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable Mega Menu'),
    '#default_value' => theme_get_setting('mega_menu'),
    '#description' => t('Toggle the main menu to display as Mega Menu'),
  );
  $form['nc_base_theme_settings']['mega_menu_fieldset']['mega_menu_hide_tertiary'] = array(
    '#type' => 'checkbox',
    '#title' => t("Hide tertiary menu items."),
    '#default_value' => theme_get_setting('mega_menu_hide_tertiary'),
    '#description' => t('If selected, the secondary menu items will ignore the <i>Show as expanded</i> menu setting in the Mega Menu, preventing tertiary items from being displayed.'),
  );

  // Footer logo.
  $form['nc_base_theme_settings']['footer_logo_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Footer Appearance'),
  );
  $default_footer_svg = theme_get_setting('logo_footer_path');
  $form['nc_base_theme_settings']['footer_logo_fieldset']['logo_footer_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Path to Footer logo'),
    '#description' => t('The path to the file you would like to use as your footer logo file.'),
    '#default_value' => $default_footer_svg,
    '#element_validate' => array('_nc_base_theme_logo_footer_path_validate'),
  );

  $form['nc_base_theme_settings']['footer_logo_fieldset']['logo_footer_upload'] = array(
    '#type' => 'file',
    '#title' => t('Upload Footer logo image'),
    '#maxlength' => 40,
    '#description' => t("If you don't have direct file access to the server, use this field to upload your footer logo."),
    '#element_validate' => array('_nc_base_theme_logo_footer_upload_validate'),
  );

  $form['favicon']['settings']['favicon_upload']['#title'] = t('Upload favicon image (PNG only, at least 192x192px)');

  // Validators for favicon: require png.
  $form['favicon']['settings']['favicon_path']['#element_validate'] = array(
      '_nc_base_theme_favicon_path_validate',
  );

  $form['favicon']['settings']['favicon_upload']['#element_validate'] = array(
      '_nc_base_theme_favicon_upload_validate',
  );
}
