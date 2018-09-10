<?php
/**
 * Contains the Bean definition for iContact signups.
 */

/**
 * Class definition for NCSignupIContact.
 */
class NCSignupIContact extends NCSignupBase {
  /**
   * Declare default block settings.
   */
  public function values() {
    $values = array(
      'appId' => '',
      'apiUsername' => '',
      'apiPassword' => '',
      'listid' => '',
    );

    return array_merge(parent::values(), $values);
  }

  /**
   * Bean form.
   */
  public function form($bean, $form, &$form_state) {
    $form = parent::form($bean, $form, $form_state);

    $form['icontact'] = array(
      '#type' => 'fieldset',
      '#title' => t('iContact Configuration'),
      '#description' => t('Configuration items for this iContact signup block'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );

    $form['icontact']['appId'] = array(
      '#type' => 'textfield',
      '#title' => t('Application ID'),
      '#default_value' => $bean->appId,
      '#required' => TRUE,
    );

    $form['icontact']['apiUsername'] = array(
      '#type' => 'textfield',
      '#title' => t('API username'),
      '#default_value' => $bean->apiUsername,
      '#required' => TRUE,
    );

    $form['icontact']['apiPassword'] = array(
      '#type' => 'textfield',
      '#title' => t('API password'),
      '#default_value' => $bean->apiPassword,
      '#required' => TRUE,
    );

    $form['icontact']['listid'] = array(
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

    // Load iContact API.
    if (!empty($values['email'])) {
      $libpath = libraries_get_path('icontact');
      require_once($libpath . '/lib/iContactApi.php');
      try {
        // Give the API your information.
        iContactApi::getInstance()->setConfig(array(
          'appId'       => $bean->appId,
          'apiPassword' => $bean->apiPassword,
          'apiUsername' => $bean->apiUsername,
        ));

        // Store the singleton.
        $oiContact = iContactApi::getInstance();

        // Add/update email and subscribe to list.
        $contact = $oiContact->addContact($values['email']);
        $subs = $oiContact->subscribeContactToList($contact->contactId, $bean->listid);

        return TRUE;
      }
      catch (Exception $e) {
        drupal_set_message(print_r($oiContact->getErrors(), TRUE), 'error');
      }
    }
  }
}
