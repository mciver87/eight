<?php
/**
 * @file
 * Required for Apps module.
 */

/**
 * Implements hook_apps_app_info().
 */
function nc_crawler_admin_apps_app_info() {
  return array(
    'configure form' => 'nc_crawler_admin_app_configure_form',
  );
}

/**
 * Implements 'configure form' callback for apps.
 */
function nc_crawler_admin_app_configure_form() {
  $form = array();

  // Check for a request for a specific crawler.
  $crawler = NULL;
  $crawler_id = arg(5);
  if ($crawler_id) {
    // We have a crawler, so load it up.
    $crawler = nc_crawler_admin_get_crawler($crawler_id);
    if ($crawler) {
      $crawler_op = arg(6);
      $form['crawler'] = array(
        '#type' => 'value',
        '#value' => $crawler,
      );
      $form['crawler_op'] = array(
        '#type' => 'value',
        '#value' => $crawler_op,
      );
      switch ($crawler_op) {
        case 'delete':
          $form = confirm_form(
            $form,
            t('Delete crawler %crawler?', array('%crawler' => $crawler['name'])),
            'admin/apps/openpublic/nc_crawler_admin/configure',
            t('Are you sure you want to delete the crawler definition named %crawler?  This action cannot be undone!', array('%crawler' => $crawler['name'])),
            t('Delete')
          );
          $form['#submit'] = array('_nc_crawler_admin_crawler_delete_submit');
          break;

        case 'edit':
        default:
          $form = _nc_crawler_admin_crawler_config($form, $crawler);
      }
    }
  }

  if (!$crawler) {
    if ('_add' == $crawler_id) {
      // Show empty crawler config page.
      $form = _nc_crawler_admin_crawler_config($form);
    }
    else {
      // Show a table of all available crawlers.
      $form = _nc_crawler_admin_crawler_list($form);
    }
  }

  return $form;
}

/**
 * Util function to generate help output on listing and edit pages.
 */
function _nc_crawler_admin_form_help($form) {
  // Generate some helper text for crawler config.
  $docs_path = drupal_get_path('module', 'nc_crawler_admin') . '/docs';
  $form['help'] = array(
    '#prefix' => '<h2>',
    '#suffix' => '</h2>',
    '#markup' => t('Help'),
  );
  $form['help_cron'] = array(
    '#type' => 'fieldset',
    '#title' => 'Cron schedules',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['help_cron']['text'] = array(
    '#markup' => file_get_contents($docs_path . '/help_cron.html'),
  );
  $form['help_cron']['links'] = array(
    '#prefix' => '<p>',
    '#suffix' => '</p>',
    '#markup' => t('For more details on cron scheduling syntax, see !link', array('!link' => l(t('CronExpression'), 'http://quartz-scheduler.org/api/2.2.0/org/quartz/CronExpression.html'))),
  );

  return $form;
}

/**
 * Form validate callback for 'save'.
 */
function _nc_crawler_admin_app_configure_form_validate($form, &$form_state) {
  $values = $form_state['values'];

  // Check to see if this name is already in use.
  if (!empty($values['config']['name']) && nc_crawler_admin_get_crawler($values['config']['name'])) {
    form_set_error("config']['name", t('Crawler name already exists: %name', array('%name' => $values['config']['name'])));
  }

  // Process URLs into arrays.
  if (!empty($values['config']['crawl']['url'])) {
    $urls = _nc_crawler_admin_preprocess_textarea($values['config']['crawl']['url']);
    foreach ($urls as $idx => &$url) {
      // Check for properly formed URL.
      if (!filter_var($url, FILTER_VALIDATE_URL)) {
        form_set_error("config']['crawl']['url'][" . $idx, t('Invalid URL to crawl: %url', array('%url' => $url)));
      }
      else {
        // Go ahead and append trailing slash if it doesn't exist.
        if (substr_compare($url, '/', -1)) {
          $url .= '/';
        }
      }
    }
    unset($url);
    $values['config']['crawl']['url'] = $urls;
  }

  // Process include filters, set defaults based on URLs if none provided.
  $values['config']['crawl']['includeFilter'] = _nc_crawler_admin_preprocess_textarea($values['config']['crawl']['includeFilter']);
  if (empty($values['config']['crawl']['includeFilter'])) {
    $filters = array();
    foreach ($values['config']['crawl']['url'] as $idx => $url) {
      $filters[] = $url . '.*';
    }
    $values['config']['crawl']['includeFilter'] = $filters;
  }

  // Process exclude filters, dropping from settings if none provided.
  if (!empty($values['config']['crawl']['excludeFilter'])) {
    $values['config']['crawl']['excludeFilter'] = _nc_crawler_admin_preprocess_textarea($values['config']['crawl']['excludeFilter']);
  }
  else {
    unset($values['config']['crawl']['excludeFilter']);
  }

  // Suss out crawler name; new or old?
  $name = !empty($values['crawler']['name']) ? $values['crawler']['name'] : $values['config']['name'];

  // Save crawler definition since we can't throw an error safely from submit.
  if (!nc_crawler_admin_save_crawler($name, $values['config'])) {
    // Report error.
    form_set_error('save_error', t('Unable to save crawler configuration.'));
  }
}

/**
 * Form submit callback for 'save'.
 */
function _nc_crawler_admin_app_configure_form_submit($form, &$form_state) {
  $values = $form_state['values'];

  // Suss out crawler name; new or old?
  $name = !empty($values['crawler']['name']) ? $values['crawler']['name'] : $values['config']['name'];

  // Let 'em know we saved (done in validate handler).
  drupal_set_message(t('Crawler configuration for %name saved.', array('%name' => $name)));

  // Redirect to crawler list page.
  $args = arg();
  array_pop($args);
  $form_state['redirect'] = array(implode('/', $args));
}

/**
 * Form submit callback for 'cancel'.
 */
function _nc_crawler_admin_app_configure_form_cancel($form, &$form_state) {
  $args = arg();
  array_pop($args);
  $form_state['redirect'] = array(implode('/', $args));
}

/**
 * Util function to build crawler listing.
 */
function _nc_crawler_admin_crawler_list($form) {
  // Retrieve existing crawlers from ES.
  $crawlers = nc_crawler_admin_get_crawlers();

  $header = array(
    t('Name'),
    t('URL(s)'),
    t('Cron schedule'),
    t('Operations'),
  );
  $rows = array();
  foreach ($crawlers as $crawler) {
    $row = array();
    $row[] = l($crawler['name'], request_path() . '/' . $crawler['name']);
    $row[] = !empty($crawler['crawl']['url']) ? implode('<br/>', $crawler['crawl']['url']) : '';
    $row[] = !empty($crawler['schedule']['cron']) ? ('<pre>' . $crawler['schedule']['cron'] . '</pre>') : '';

    $ops = array();
    $ops[] = l(t('Edit'), request_path() . '/' . $crawler['name'] . '/edit');
    $ops[] = l(t('Delete'), request_path() . '/' . $crawler['name'] . '/delete');
    $row[] = implode('&nbsp;|&nbsp;', $ops);

    $rows[] = $row;
  }
  $form['crawlers'] = array(
    '#markup' => theme('table', array('header' => $header, 'rows' => $rows)),
  );

  $form = _nc_crawler_admin_form_help($form);
  return $form;
}

/**
 * Util function to build crawler config form.
 */
function _nc_crawler_admin_crawler_config($form, $crawler = NULL) {
  $form['config'] = array(
    '#tree' => TRUE,
  );

  if (!empty($crawler['name'])) {
    $form['config']['name'] = array(
      '#prefix' => '<h2>',
      '#suffix' => '</h2>',
      '#markup' => $crawler['name'],
    );
  }
  else {
    $form['config']['name'] = array(
      '#type' => 'textfield',
      '#title' => t('Crawler name'),
      '#required' => TRUE,
      '#default_value' => !empty($crawler['name']) ? $crawler['name'] : '',
    );
  }

  $form['config']['crawl']['url'] = array(
    '#type' => 'textarea',
    '#title' => t('URL(s) to crawl'),
    '#description' => t('Base URL(s) for this crawler to follow, one per line.'),
    '#required' => TRUE,
    '#default_value' => !empty($crawler['crawl']['url']) ? implode("\r\n", $crawler['crawl']['url']) : '',
  );
  $form['config']['crawl']['includeFilter'] = array(
    '#type' => 'textarea',
    '#title' => t('Include filter'),
    '#description' => t('Regular expression(s) of URL patterns to include, one per line. Default is any.'),
    '#required' => FALSE,
    '#default_value' => !empty($crawler['crawl']['includeFilter']) ? implode("\r\n", $crawler['crawl']['includeFilter']) : '',
  );
  $form['config']['crawl']['excludeFilter'] = array(
    '#type' => 'textarea',
    '#title' => t('Exclude filter'),
    '#description' => t('Regular expression(s) of URL patterns to exclude, one per line. Default is none.'),
    '#required' => FALSE,
    '#default_value' => !empty($crawler['crawl']['excludeFilter']) ? implode("\r\n", $crawler['crawl']['excludeFilter']) : '',
  );
  $form['config']['crawl']['maxDepth'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum depth to crawl'),
    '#description' => t('Maximum recursion level to crawl site. Default is full depth.'),
    '#required' => FALSE,
    '#default_value' => !empty($crawler['crawl']['maxDepth']) ? $crawler['crawl']['maxDepth'] : '',
  );
  $form['config']['crawl']['maxAccessCount'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum access count per run'),
    '#required' => FALSE,
    '#default_value' => !empty($crawler['crawl']['maxAccessCount']) ? $crawler['crawl']['maxAccessCount'] : '1000',
  );
  $form['config']['crawl']['numOfThread'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum number of threads'),
    '#required' => FALSE,
    '#default_value' => !empty($crawler['crawl']['numOfThread']) ? $crawler['crawl']['numOfThread'] : '3',
  );
  $form['config']['crawl']['interval'] = array(
    '#type' => 'textfield',
    '#title' => t('Interval between requests (ms)'),
    '#required' => FALSE,
    '#default_value' => !empty($crawler['crawl']['interval']) ? $crawler['crawl']['interval'] : '1000',
  );
  $form['config']['crawl']['userAgent'] = array(
    '#type' => 'textfield',
    '#title' => t('User agent to use for requests'),
    '#description' => t('If the target site blocks traffic from non-standard user agents, set this to an allowed user agent string.'),
    '#required' => FALSE,
    '#default_value' => !empty($crawler['crawl']['userAgent']) ? $crawler['crawl']['userAgent'] : '',
  );
  $form['config']['schedule']['cron'] = array(
    '#type' => 'textfield',
    '#title' => t('Cron schedule'),
    '#description' => t('Common cron schedule expression; see below for syntax. Default is daily at midnight. Empty value executes immediately and deletes the crawler.'),
    '#default_value' => isset($crawler['schedule']['cron']) ? $crawler['schedule']['cron'] : '0 0 0 * * ?',
  );

  // Form buttons.
  $form['save'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
    '#submit' => array('_nc_crawler_admin_app_configure_form_submit'),
    '#validate' => array('_nc_crawler_admin_app_configure_form_validate'),
  );
  $form['cancel'] = array(
    '#type' => 'submit',
    '#value' => t('Cancel'),
    '#submit' => array('_nc_crawler_admin_app_configure_form_cancel'),
  );

  $form = _nc_crawler_admin_form_help($form);
  return $form;
}

/**
 * Submit callback for crawler delete confirmation form.
 */
function _nc_crawler_admin_crawler_delete_submit($form, &$form_state) {
  if (!empty($form_state['values']['crawler']['name'])) {
    nc_crawler_admin_delete_crawler($form_state['values']['crawler']['name']);
  }
  $form_state['redirect'] = 'admin/apps/openpublic/nc_crawler_admin/configure';
}
