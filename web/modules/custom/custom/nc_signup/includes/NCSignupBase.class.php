<?php
/**
 * Contains base Bean class for signup blocks.
 */

/**
 * Class definition for NCSignupBase.
 */
class NCSignupBase extends BeanPlugin {
  public $plugin_info;

  /**
   * Declare default block settings.
   */
  public function values() {
    $values = array(
      'call_to_action' => '',
      'view_modes' => array(
        'default' => 'Default',
        'card' => 'Card',
      ),
    );

    return array_merge(parent::values(), $values);
  }

  /**
   * Bean form.
   */
  public function form($bean, $form, &$form_state) {
    $form = array();
    $form['call_to_action'] = array(
      '#type' => 'textarea',
      '#title' => t('Call to action'),
      '#description' => t('Optional call to action text to display above form elements'),
      '#required' => FALSE,
      '#default_value' => $bean->call_to_action,
    );

    return $form;
  }

  /**
   * View the Bean.
   */
  public function view($bean, $content, $view_mode = 'default', $langcode = NULL) {
    $bean->object = $this;
    $output = drupal_get_form('nc_signup_form', $bean, $content, $view_mode, $langcode);
    return $output;
  }

  /**
   * Render the custom form.
   */
  public function view_form(&$form, $form_state, $content, $view_mode, $langcode) {
  }

  /**
   * Validate the custom form.
   */
  public function validate_form(&$form, $form_state) {
  }

  /**
   * Process submit of the custom form.
   */
  public function submit_form(&$form, $form_state) {
  }

  /**
   * GetInfo.
   */
  public function getInfo($key = NULL) {
    if ($key == 'cache_level') {
      $this->plugin_info[$key] = DRUPAL_NO_CACHE;
    }
    if (!empty($key) && isset($this->plugin_info[$key])) {
      return $this->plugin_info[$key];
    }

    return $this->plugin_info;
  }
}
