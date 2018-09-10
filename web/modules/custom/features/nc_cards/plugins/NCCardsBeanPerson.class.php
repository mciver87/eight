<?php
/**
 * @file
 * NC Cards Bean plugin.
 */

class NCCardsBeanPerson extends BeanPlugin {
  /**
   * Declare default block settings.
   */
  public function values() {
    $values = array(
      'framed' => FALSE,
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
    $form['config']['framed'] = array(
      '#type' => 'checkbox',
      '#title' => t('Frame the Card'),
      '#description' => t('Add a border around the card.'),
      '#default_value' => $bean->framed,
    );
    return $form;
  }

  /**
   * View the Bean.
   */
  public function view($bean, $content, $view_mode = 'default', $langcode = NULL) {
    // Provide variables to our theme function.
    $wrapper = entity_metadata_wrapper('bean', $bean);
    $variables['card_title'] = $wrapper->field_card_title->value(array('sanitized' => TRUE));
    $link = $wrapper->field_card_link->value(array('sanitized' => TRUE));
    if ($link) {
      $link = _nc_cards_card_link_query_fix($link);
      $url = url($link['url'], $link);
      $variables['card_link'] = nc_cards_check_url($url);
    }
    $variables['card_name'] = $wrapper->field_card_person_name->value(array('sanitized' => TRUE));
    if (!empty($content['bean'][$bean->delta]['field_card_image'][0])) {
      $variables['card_image'] = $content['bean'][$bean->delta]['field_card_image'][0];
    }
    $variables['card_framed'] = ($bean->framed) ? "framed" : "";
    $build = theme('nc_card_person', $variables);
    return $build;
  }
}
