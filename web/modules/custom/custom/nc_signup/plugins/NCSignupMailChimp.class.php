<?php
/**
 * Contains the Bean definition for MailChimp signups.
 */

/**
 * Class definition for NCSignupMailChimp.
 */
class NCSignupMailChimp extends NCSignupBase {
  /**
   * Declare default block settings.
   */
  public function values() {
    $values = array(
      'apikey' => '',
      'listid' => '',
    );

    return array_merge(parent::values(), $values);
  }

  /**
   * Bean form.
   */
  public function form($bean, $form, &$form_state) {
    $form = parent::form($bean, $form, $form_state);

    $form['mailchimp'] = array(
      '#type' => 'fieldset',
      '#title' => t('MailChimp Configuration'),
      '#description' => t('Configuration items for this MailChimp signup block'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );

    $form['mailchimp']['apikey'] = array(
      '#type' => 'textfield',
      '#title' => t('API key'),
      '#default_value' => $bean->apikey,
      '#required' => TRUE,
    );

    $form['mailchimp']['listid'] = array(
      '#type' => 'textfield',
      '#title' => t('List ID'),
      '#default_value' => $bean->listid,
      '#required' => TRUE,
    );

    return $form;
  }

  /**
   * Process submit of the custom form.
   */
  public function submit_form(&$form, $form_state) {
    $values = $form_state['values'];
    $bean = $form['#bean'];

    // Load MCAPI.
    if (!empty($values['email'])) {
      $libpath = libraries_get_path('mailchimp');
      require_once($libpath . '/src/Mailchimp.php');
      try {
        $mc = new Mailchimp($bean->apikey);
        $resp = $mc->lists->subscribe($bean->listid, array('email' => $values['email']), null, 'html', TRUE, TRUE);

        return TRUE;
      }
      catch (Mailchimp_Error $e) {
        drupal_set_message($e->getMessage(), 'error');
      }
    }
  }
}
