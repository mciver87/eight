<?php
/**
 * @file
 * Follow Us Bean.
 */

class NcSocialFollowUsBean extends BeanPlugin {

  /**
   * Declares default block settings.
   */
  public function values() {
    $values = array(
      'settings' => array(
        'facebook'  => FALSE,
        'twitter'   => FALSE,
        'instagram' => FALSE,
        'flickr'    => FALSE,
        'youtube'   => FALSE,
        'pinterest' => FALSE,
        'feed'      => FALSE,
        'medium'    => FALSE,
      ),
      'title' => 'Follow Us',
    );
    return array_merge(parent::values(), $values);
  }

  /**
   * Builds extra settings for the block edit form.
   */
  public function form($bean, $form, &$form_state) {
    $form['settings'] = array(
      '#type'  => 'fieldset',
      '#tree'  => TRUE,
      '#title' => t('Settings'),
    );

    $this->addSocialOption($form, $bean, 'Facebook', 'facebook');
    $this->addSocialOption($form, $bean, 'Twitter', 'twitter');
    $this->addSocialOption($form, $bean, 'Instragram', 'instagram');
    $this->addSocialOption($form, $bean, 'Flickr', 'flickr');
    $this->addSocialOption($form, $bean, 'YouTube', 'youtube');
    $this->addSocialOption($form, $bean, 'Pinterest', 'pinterest');
    $this->addSocialOption($form, $bean, 'Our RSS Feed', 'feed');
    $this->addSocialOption($form, $bean, 'Medium', 'medium');

    return $form;
  }

  /**
   * Renders the view.
   */
  public function view($bean, $content, $view_mode = 'default', $langcode = NULL) {
    $variables = $bean->settings;
    $variables['bean'] = $bean;
    $variables['title'] = $bean->title;

    $content = theme('nc_social_share_follow_us', $variables);
    return $content;
  }

  /**
   * This will add a specified social option to the form.
   *
   * @param array $form
   *   The form.
   * @param Bean $bean
   *   The Bean.
   * @param string $label
   *   Publicly visible label.
   * @param string $key
   *   Array key for service.
   */
  protected function addSocialOption(&$form, $bean, $label, $key) {
    $form['settings'][$key . '_title'] = array(
      '#type'          => 'textfield',
      '#title'         => t('@label Title', array('@label' => $label)),
      '#default_value' => isset($bean->settings[$key . '_title']) ? $bean->settings[$key . '_title'] : '',
      '#attributes'    => array(
        'placeholder'  => t('Follow Us on @label', array('@label' => $label))
      ),
      '#description'  => t('Enter a custom title. Leave blank for default message: ') . t('Follow Us on @label', array('@label' => $label))
    );

    $form['settings'][$key] = array(
      '#type'          => 'textfield',
      '#title'         => t('@label Link', array('@label' => $label)),
      '#default_value' => $bean->settings[$key],
      '#suffix'        => '<p>&nbsp;<br/></p>',
      '#description'   => t('Enter a URL to the @label account. Leave blank if you do not want this service to display.', array('@label' => $label))
    );
  }
}
