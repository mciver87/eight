<?php
/**
 * @file
 * NC Cards Bean plugin.
 */

class NCCardsBeanService extends BeanPlugin {
  /**
   * Declare default block settings.
   */
  public function values() {
    $values = array(
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
    $icons = nc_cards_icon_classes();
    if (array_key_exists($bean->icon, $icons)) {
      $variables['icon_classes'] = $icons[$bean->icon];
    }
    else {
      $variables['icon_classes'] = $icons['icon-check2'];
    }
    $wrapper = entity_metadata_wrapper('bean', $bean);
    $variables['card_name'] = $wrapper->field_card_title->value(array('sanitized' => TRUE));
    $link = $wrapper->field_card_link->value(array('sanitized' => TRUE));
    if ($link) {
      $link = _nc_cards_card_link_query_fix($link);
      $url = url($link['url'], $link);
      $variables['card_link'] = nc_cards_check_url($url);
    }
    $build = theme('nc_card_service', $variables);
    return $build;
  }
}
