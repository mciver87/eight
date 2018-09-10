<?php
/**
 * @file
 * NC Alerts theme functions.
 */

/**
 * Alerts theme function.
 *
 * 2016-01-14: Extracted the core functionality to an additional
 * function, nc_alerts_theme_alert_content, so that the rendering
 * would be accessible for use with items that were not
 * nc alerts blocks. This will help minimize code duplication while
 * at the same time allowing external items to share the same
 * look and feel.
 *
 * @param alert $variables
 *   Alert.
 *
 * @return mixed
 *   Returns updated render array.
 */
function theme_alert(&$variables) {
  if (array_key_exists('alert', $variables)) {
    return nc_alerts_theme_alert_content($variables['alert']);
  }
}

/**
 * Return the render array for the alert.
 *
 * @param mixed $alert
 *   Variables.
 *
 * @return mixed
 *   Return content.
 */
function nc_alerts_theme_alert_content($alert) {
  $class = strtolower($alert['severity']);

  $read_more = nc_alerts_theme_read_more($alert);

  $content = array(
    'alert_box' => array(
      '#prefix' => "<div id='{$alert['id']}' class='alert-box {$class}' style='display:none;'>",
      '#suffix' => '</div>',
      'wrapper_group' => array(
        '#prefix' => "<div class='wrapper group'>",
        '#suffix' => "</div>",
        'alert_icon' => array(
          '#prefix' => "<span class='alert-icon' aria-hidden='true'>",
          '#suffix' => '</span>',
        ),
        'message' => array(
          '#prefix' => "<div class='message'>",
          '#suffix' => $alert['summary'] . $read_more . '</div>',
          'alert_type' => array(
            '#prefix' => "<span class='alert-type'>" . $alert['title'],
            '#suffix' => '</span>',
          ),
        ),
      ),
    ),
  );

  // Attach our Javascript.
  $content['#attached'] = array(
    'js' => array(
      drupal_get_path('module', 'nc_alerts') . '/js/nc_alerts_handler.js' => array(
        'scope' => 'footer',
      ),
      drupal_get_path('module', 'nc_alerts') . '/js/nc_alerts.js' => array(
        'scope' => 'footer',
      ),
      // NOTE: This is theme specific, but we need to
      // guarantee that we have owl carousel.
      drupal_get_path('theme', 'nc_base_theme') . '/js/vendors/owl.carousel.js' =>
      array(
        'scope' => 'footer',
      ),
    ),
    // Ensure the core jquery.cookie library is present.
    'library' => array(
      array('system', 'jquery.cookie'),
    ),
  );

  // We're going to pass options to the carousel.
  // I'm adding this here because eventually
  // we may want to be able Drupal configuration
  // to modify these values.
  $options = array(
    'transitionStyle' => 'goDown',
    'navigation'      => TRUE,
    'slideSpeed'      => 500,
    'paginationSpeed' => 500,
    'singleItem'      => TRUE,
    'mouseDrag'       => FALSE,
    'callbacks'       => TRUE,
    'addClassActive'  => TRUE,
    'autoHeight'      => TRUE,
    'navigationText'  => array(
      '<i class="icon-chevron-left"></i>',
      '<i class="icon-chevron-right"></i>',
    ),
  );
  $auto_play = variable_get(NC_ALERTS_VARIABLE_AUTOROATE, 0);
  if ($auto_play) {
    $options['autoPlay'] = $auto_play;
  }
  $content['#attached']['js'][] = array(
    'type' => 'setting',
    'data' => array(
      'nc_alerts' => array(
        'options' => $options,
      ),
    ),
  );

  global $user;
  $content['#attached']['js'][] = array(
    'data' => array('currentUser' => $user->uid),
    'type' => 'setting',
  );
  return $content;
}

/**
 * Generate the read more link.
 *
 * @param array $alert
 *   Alert array.
 *
 * @return string
 *   Read more link content.
 */
function nc_alerts_theme_read_more($alert) {
  $read_more = ' ';
  if (isset($alert['link']) && array_key_exists('url', $alert['link'])) {
    $options = array(
      'attributes' =>
      array_key_exists('attributes', $alert['link']) ? $alert['link']['attributes'] : array(),
    );

    $url = array_key_exists('url', $alert['link']) ?
      $alert['link']['url'] : '#';

    if (array_key_exists('title', $alert['link'])) {
      $title = $alert['link']['title'];
      if (!isset($options['attributes']['alt'])) {
        $options['attributes']['alt'] = t('Read More') . ' ' . $title;
      }
    }
    else {
      $title = t('Read More');
      if (!isset($options['attributes']['alt'])) {
        $options['attributes']['alt'] = t('Read More') . $alert['title'];
      }
    }

    $read_more .= l($title, $url, $options);
  }

  return $read_more;
}
