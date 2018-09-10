<?php
/**
 * @file
 * NC Cards Bean plugin.
 */

class NCCardsBeanCTA extends BeanPlugin {
  /**
   * Declare default block settings.
   */
  public function values() {
    $values = array(
      'accent' => '',
      'icon' => 'icon-check2',
    );
    return array_merge(parent::values(), $values);
  }

  /**
   * Bean form.
   */
  public function form($bean, $form, &$form_state) {
    $form['config'] = array(
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#title' => t('Settings'),
      '#weight' => 35,
    );
    $form['config']['icon'] = array(
      '#type' => 'select',
      '#title' => t('Icon class'),
      '#description' => t('Change the look of the card with a icon.'),
      '#default_value' => $bean->icon,
      '#options' => nc_cards_icon_classes(),
      '#suffix' => '<div class="dc-icon-picker hidden" data-select="edit-icon"><a href="#" class="hide-show-picker">' . t('Display Picker') . '</a></div>',
    );
    $colors = array(
      '' => t('Default'),
      'theme-core-black' => t('Core Black background'),
      'theme-core-blue' => t('Core Blue background'),
      'theme-core-gray' => t('Core Gray background'),
      'theme-core-light-gray' => t('Core Light Gray background'),
      'theme-accent-cool-gray' => t('Accent Cool Gray background'),
      'theme-accent-warm-gray' => t('Accent Warm Gray background'),
      'theme-accent-light-blue' => t('Accent Light Blue background'),
      'theme-accent-blue' => t('Accent Blue background'),
      'theme-accent-indigo' => t('Accent Indigo background'),
      'theme-accent-deep-purple' => t('Accent Deep Purple background'),
      'theme-accent-purple' => t('Accent Purple background'),
      'theme-accent-red' => t('Accent Red background'),
      'theme-accent-orange' => t('Accent Orange background'),
      'theme-accent-olive' => t('Accent Olive background'),
      'theme-accent-green' => t('Accent Green background'),
      'theme-accent-turquoise' => t('Accent Turquoise background'),
    );
    // Added hook to be able to change the color options.
    drupal_alter('nc_color_options', $colors);

    $form['config']['accent'] = array(
      '#type' => 'select',
      '#title' => t('Accent Color'),
      '#description' => t('Change the look of the card with an accent color.'),
      '#default_value' => $bean->accent,
      '#options' => $colors,
    );
    $form['#attached']['js'] = array(
      drupal_get_path('module', 'nc_cards') . '/js/jets.min.js',
      drupal_get_path('module', 'nc_cards') . '/js/icon-picker.js',
    );
    $form['#attached']['css'] = array(
      drupal_get_path('module', 'nc_cards') . '/css/icon-picker.css',
    );
    return $form;
  }

  /**
   * View the Bean.
   */
  public function view($bean, $content, $view_mode = 'default', $langcode = NULL) {
    // Provide variables to our theme function.
    $variables['card_accent'] = check_plain($bean->accent);
    $icons = nc_cards_icon_classes();
    if (array_key_exists($bean->icon, $icons)) {
      $variables['icon_classes'] = $icons[$bean->icon];
    }
    $wrapper = entity_metadata_wrapper('bean', $bean);
    $variables['card_title'] = $wrapper->field_card_title->value(array('sanitized' => TRUE));
    $variables['card_description'] = $wrapper->field_card_description->value(array('sanitized' => TRUE));
    $link = $wrapper->field_card_link->value(array('sanitized' => TRUE));
    if ($link) {
      $link = _nc_cards_card_link_query_fix($link);
      $url = url($link['url'], $link);
      $variables['card_link'] = nc_cards_check_url($url);
    }
    $build = theme('nc_card_cta', $variables);
    return $build;
  }
}

