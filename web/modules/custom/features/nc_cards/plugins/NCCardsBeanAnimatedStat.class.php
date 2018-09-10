<?php
/**
 * @file
 * NC Cards Bean plugin.
 */

class NCCardsBeanAnimatedStat extends BeanPlugin {
  /**
   * View the Bean.
   */
  public function view($bean, $content, $view_mode = 'default', $langcode = NULL) {
    // Provide variables to our theme function.
    $wrapper = entity_metadata_wrapper('bean', $bean);
    $variables['stat_id'] = $bean->vid;
    $variables['card_title'] = $wrapper->field_card_title->value(array('sanitized' => TRUE));
    $variables['card_description'] = $wrapper->field_card_description->value(array('sanitized' => TRUE));
    $variables['animation_type'] = $wrapper->field_animation_type->value(array('sanitized' => TRUE));
    $variables['counter_prefix'] = $wrapper->field_counter_prefix->value(array('sanitized' => TRUE));
    $variables['counter_value'] = $wrapper->field_counter_value->value(array('sanitized' => TRUE));
    $variables['counter_suffix'] = $wrapper->field_counter_suffix->value(array('sanitized' => TRUE));
    $variables['counter_duration'] = $wrapper->field_counter_duration->value(array('sanitized' => TRUE));
    $variables['chart_values'] = $wrapper->field_chart_values->value(array('sanitized' => TRUE));

    // Process javascript.
    // Determine if this is a countup or doughnut / pie chart.
    $stat_type = $variables['animation_type'];
    $attached = $this->process_attached_js($stat_type, $variables);
    $build = theme('nc_card_animated_stat', $variables);
    return array(
      '#markup' => $build,
      '#attached' => $attached,
    );
    return $build;
  }
  
  /**
   * Function process_attached_js().
   * 
   * Handle attach array processing for the animated stat bean.
   *
   * @param string $stat_type
   *   The animation type.
   * @param array $variables
   *   Variables provided by the bean.
   *
   * @return array
   *   An array of JS to send to #attached.
   */
  private function process_attached_js($stat_type, $variables) {
    $attached = array();
    // Add basic JS.
    $attached['js'][] = array(
      'data' => drupal_get_path('module', 'nc_cards') . '/js/nc_cards.js',
      'type' => 'file'
    );
    $attached['js'][] = array(
      'data' => libraries_get_path('viewport') . '/jquery.viewport.js',
      'type' => 'file',
    );
    // Process JS additions for countup type.
    if ($stat_type == 'countup') {
      $attached['js'][] = array(
        'data' => libraries_get_path('countup') . '/countUp.js',
        'type' => 'file',
      );
      $attached['js'][] = array(
        'data' => libraries_get_path('countup') . '/countUp-jquery.js',
        'type' => 'file',
      );
      // Sanity check to ensure values.
      if (isset($variables['counter_value']) && isset($variables['counter_duration'])) {
        // Set some basic variables.
        $counter_value = $variables['counter_value'];
        $counter_duration = 0;
        if ($variables['counter_duration'] > 0) {
          $counter_duration = $variables['counter_duration'];
        }
        // How many decimal places do we have?
        $decimal_place = strlen(substr(strrchr($counter_value, "."), 1));
        // Handle CountUp JS attachments.
        $countup_settings = array(
          'animated-' . $stat_type . '-stat-' . $variables['stat_id'] => array(
            'value' => $counter_value,
            'decimals' => $decimal_place,
            'duration' => $counter_duration,
          ),
        );
        $attached['js'][] = array(
          'data' => array(
            'nc_cards' => $countup_settings,
          ),
          'type' => 'setting',
        );
        // drupal_add_js(array('nc_cards' => $countup_settings), 'setting');
      }
    }
    // Process JS additions for donuts and pies.
    elseif (($stat_type == 'doughnut') ||  ($stat_type == 'pie')) {
      // @TODO
      // drupal_add_js(libraries_get_path('chartjs') . '/src/chart.js', array('scope' => 'footer'));
    }
    return $attached;
  }

}
