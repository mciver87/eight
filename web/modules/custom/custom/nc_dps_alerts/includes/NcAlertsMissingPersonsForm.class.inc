<?php
/**
 * @file
 * Code for the NC DPS Silver and Amber Alerts feature.
 */

/**
 * Class NcAlertsMissingPersonsForm
 */
class NcAlertsMissingPersonsForm {
  const URL_VARIABLE_AMBER = 'nc_dps_alerts_amber_alert_rss_url';
  const ORDER_VARIABLE_AMBER = 'nc_dps_alerts_amber_alert_order';
  const URL_VARIABLE_SILVER = 'nc_dps_alerts_silver_alert_rss_url';
  const ORDER_VARIABLE_SILVER = 'nc_dps_alerts_silver_alert_order';
  const URL_VARIABLE_BLUE = 'nc_dps_alerts_blue_alert_rss_url';
  const ORDER_VARIABLE_BLUE = 'nc_dps_alerts_blue_alert_order';
  const ORDER_VARIABLE_CUSTOM = 'nc_dps_alerts_custom_alert_order';
  const CACHE_LIFETIME_VARIABLE = 'nc_dps_alerts_cache_lifetime';
  const CACHE_LIFETIME_DEFAULT = 5;
  /**
   * Form.
   *
   * @var array
   */
  protected $form = array();

  /**
   * Options.
   *
   * @var array
   */
  protected $options = array();

  /**
   * Constructor.
   *
   * @param array $options
   *   Options.
   */
  public function __construct($options = array()) {
    $this->options = $options;
    $this->form = $this->initForm();
  }

  /**
   * Get options.
   *
   * @return array
   *   Returns options.
   */
  public function getOptions() {
    return $this->options;
  }

  /**
   * Set options.
   *
   * @param array $options
   *   Options.
   *
   * @return this
   *   Returns this.
   */
  public function setOptions($options) {
    $this->options = $options;
    return $this;
  }

  /**
   * Get form.
   *
   * @return array
   *   Returns form.
   */
  public function getForm() {
    return $this->form;
  }

  /**
   * Set form.
   *
   * @param mixed $form
   *   Form.
   *
   * @return this
   *   Returns this.
   */
  public function setForm($form) {
    $this->form = $form;
    return $this;
  }

  /**
   * Initialize form.
   *
   * @return array
   *   Returns the initialized form.
   */
  protected function initForm() {
    $form = array();

    $form[static::URL_VARIABLE_SILVER] = array(
      '#type' => 'textfield',
      '#title' => t('Silver Alert RSS URL'),
      '#default_value' => variable_get(
        static::URL_VARIABLE_SILVER,
        'https://www2.ncdps.gov/rss/rssSilverAlert.cfm'
      ),
      '#size' => 128,
      '#description' => t("Enter the Silver Alert RSS URL."),
      '#required' => TRUE,
    );

    $form[static::URL_VARIABLE_AMBER] = array(
      '#type' => 'textfield',
      '#title' => t('Amber Alert RSS URL'),
      '#default_value' => variable_get(
        static::URL_VARIABLE_AMBER,
        'https://www2.ncdps.gov/rss/rssAmberAlert.cfm'
      ),
      '#size' => 128,
      '#description' => t("Enter the Amber Alert RSS URL."),
      '#required' => TRUE,
    );

    $form[static::URL_VARIABLE_BLUE] = array(
      '#type' => 'textfield',
      '#title' => t('Blue Alert RSS URL'),
      '#default_value' => variable_get(
        static::URL_VARIABLE_BLUE,
        'https://www2.ncdps.gov/rss/rssBlueAlert.cfm'
      ),
      '#size' => 128,
      '#description' => t("Enter the Blue Alert RSS URL."),
      '#required' => TRUE,
    );

    $form[static::CACHE_LIFETIME_VARIABLE] = array(
      '#type' => 'textfield',
      '#title' => t('RSS Feed Cache Lifetime (in seconds)'),
      '#default_value' => variable_get(
        static::CACHE_LIFETIME_VARIABLE,
        static::CACHE_LIFETIME_DEFAULT
      ),
      '#size' => 6,
      '#maxlength' => 8,
      '#description' => t("This defines how long (in seconds) the system will cache the results from the RSS feed."),
      '#required' => TRUE,
    );

    $form['order'] = array(
      '#type' => 'fieldset',
      '#title' => t('Alerts Display Order'),
      '#collapsible' => FALSE,
      '#collapsed' => FALSE,
    );

    $form['order'][static::ORDER_VARIABLE_SILVER] = array(
      '#type' => 'textfield',
      '#title' => t('Silver Alerts'),
      '#default_value' => variable_get(
        static::ORDER_VARIABLE_SILVER,
        4
      ),
      '#size' => 3,
      '#required' => TRUE,
      '#maxlength' => 3,
      '#number_type' => 'integer',
      '#field_name' => static::ORDER_VARIABLE_SILVER,
      '#element_validate' => array('number_field_widget_validate'),
    );

    $form['order'][static::ORDER_VARIABLE_AMBER] = array(
      '#type' => 'textfield',
      '#title' => t('Amber Alerts'),
      '#default_value' => variable_get(
        static::ORDER_VARIABLE_AMBER,
        1
      ),
      '#size' => 3,
      '#required' => TRUE,
      '#maxlength' => 3,
      '#number_type' => 'integer',
      '#field_name' => static::ORDER_VARIABLE_AMBER,
      '#element_validate' => array('number_field_widget_validate'),
    );

    $form['order'][static::ORDER_VARIABLE_BLUE] = array(
      '#type' => 'textfield',
      '#title' => t('Blue Alerts'),
      '#default_value' => variable_get(
        static::ORDER_VARIABLE_BLUE,
        2
      ),
      '#size' => 3,
      '#required' => TRUE,
      '#maxlength' => 3,
      '#number_type' => 'integer',
      '#field_name' => static::ORDER_VARIABLE_BLUE,
      '#element_validate' => array('number_field_widget_validate'),
    );

    $form['order'][static::ORDER_VARIABLE_CUSTOM] = array(
      '#type' => 'textfield',
      '#title' => t('Custom Alerts'),
      '#default_value' => variable_get(
        static::ORDER_VARIABLE_CUSTOM,
        3
      ),
      '#size' => 3,
      '#required' => TRUE,
      '#maxlength' => 3,
      '#number_type' => 'integer',
      '#field_name' => static::ORDER_VARIABLE_CUSTOM,
      '#element_validate' => array('number_field_widget_validate'),
    );

    return $form;
  }
}
