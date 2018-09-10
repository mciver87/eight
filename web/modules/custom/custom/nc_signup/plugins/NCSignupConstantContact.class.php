<?php
/**
 * Contains the Bean definition for ConstantContact signups.
 */

// This is all kindsa non-Drupal-ly and janky, but required by PHP.
require_once('sites/all/libraries/constant_contact/src/Ctct/autoload.php');
use Ctct\ConstantContact;
use Ctct\Components\Contacts\Contact;

/**
 * Class definition for NCSignupConstantContact.
 */
class NCSignupConstantContact extends NCSignupBase {
  /**
   * Declare default block settings.
   */
  public function values() {
    $values = array(
      'apikey' => '',
      'access_token' => '',
      'listid' => '',
    );

    return array_merge(parent::values(), $values);
  }

  /**
   * Bean form.
   */
  public function form($bean, $form, &$form_state) {
    $form = parent::form($bean, $form, $form_state);

    $form['constant_contact'] = array(
      '#type' => 'fieldset',
      '#title' => t('Constant Contact Configuration'),
      '#description' => t('Configuration items for this Constant Contact signup block'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );

    $form['constant_contact']['apikey'] = array(
      '#type' => 'textfield',
      '#title' => t('API key'),
      '#default_value' => $bean->apikey,
      '#required' => TRUE,
    );

    $form['constant_contact']['access_token'] = array(
      '#type' => 'textfield',
      '#title' => t('Access token'),
      '#default_value' => $bean->access_token,
      '#required' => TRUE,
    );

    $form['constant_contact']['listid'] = array(
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

    // Load ConstantContact API.
    if (!empty($values['email'])) {
      //$libpath = libraries_get_path('constant_contact');
      //require_once($libpath . '/src/Ctct/autoload.php');
      try {
        $cc = new ConstantContact($bean->apikey);

        // Create a new contact if one does not exist and add to list.
        $response = $cc->getContactByEmail($bean->access_token, $values['email']);
        if (empty($response->results)) {
          $contact = new Contact();
          $contact->addEmail($values['email']);
          $contact->addList($bean->listid);
          $returnContact = $cc->addContact($bean->access_token, $contact, TRUE);
        }

        // Otherwise update existing contact and add to list.
        else {
          $contact = $response->results[0];
          $contact->addList($bean->listid);
          $returnContact = $cc->updateContact($bean->access_token, $contact, TRUE);
        }

        return TRUE;
      }
      catch (CtctException $e) {
        drupal_set_message('CtctException: ' . print_r($e->getErrors(), TRUE), 'error');
      }
      catch (IllegalArgumentException $e) {
        drupal_set_message('IllegalArgumentException: ' . $e->getMessage(), 'error');
      }
      catch (Exception $e) {
        drupal_set_message('Exception: ' . $e->getMessage(), 'error');
      }
    }
  }
}
