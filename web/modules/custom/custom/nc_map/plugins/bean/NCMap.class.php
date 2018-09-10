<?php
/**
 * @file
 * NC Map Bean.
 */

class NcMapBean extends BeanPlugin {

  /**
   * Declares default block settings.
   */
  public function values() {
    $values = array(
      'settings' => array(),
      'defaults' => array(),
    );
    return array_merge(parent::values(), $values);
  }

  /**
   * Bean form.
   */
  public function form($bean, $form, &$form_state) {
    // County option/values pairs for the select box.
    $county_list = nc_util_county_options();
    $color_list = nc_util_accent_color_options();

    $form['settings'] = array(
      '#type' => 'fieldset',
      '#tree' => TRUE,
      '#collapsible' => TRUE,
      '#title' => t('Settings'),
      '#weight' => 0,
    );

    $form['#attached']['css'] = array(
      drupal_get_path('module', 'nc_map') . '/css/nc-map-style.css',
    );

    if (empty($form_state['county_count'])) {
      $form_state['county_count'] = 1;
    }

    // Render existing county data.
    $increment = 0;
    foreach ($county_list as $county) {
      $form['settings'][$increment] = array(
        '#type' => 'fieldset',
        '#title' => $county,
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
      );
      $form['settings'][$increment]['county'] = array(
        '#type' => 'select',
        '#title' => 'County',
        '#options' => $county_list,
        '#multiple' => FALSE,
        '#required' => FALSE,
        '#empty_option' => 'Select County:',
        '#default_value' => $county,
        '#access' => FALSE,
      );
      $form['settings'][$increment]['title'] = array(
       '#type' => 'text_format',
       '#rows' => 3,
       '#format' => 'full_html',
       '#title' => 'Description',
        '#default_value' => !empty($bean->settings[$increment]['title']['value']) ? $bean->settings[$increment]['title']['value'] : $bean->settings[$increment]['title'],
       '#attributes' => array(
        'placeholder' => t('Description'),
      ),
       '#description' => 'Italicized text to associate with the county. Appears in the bottom left of map on county hover.',
       '#size' => 50,
       '#required' => FALSE,
     );
      $form['settings'][$increment]['url'] = array(
        '#type' => 'textfield',
        '#title' => 'URL',
        '#default_value' => $bean->settings[$increment]['url'],
        '#attributes' => array(
          'placeholder' => t('URL'),
        ),
        '#description' => 'Use http:// or https:// for external links; use a leading / for relative links.',
        '#required' => FALSE,
      );
      $form['settings'][$increment]['fill_color'] = array(
        '#type' => 'select',
        '#title' => 'Custom Fill Color',
        '#options' => $color_list,
        '#multiple' => FALSE,
        '#required' => FALSE,
        '#empty_option' => 'Select Fill Color:',
        '#default_value' => $bean->settings[$increment]['fill_color'],
        '#description' => 'If you\'d like a custom fill color for this county, select it here. Defaults to Core Blue.',
        '#required' => FALSE,
      );
      $increment++;
    }

    $form['defaults'] = array(
      '#type' => 'fieldset',
      '#tree' => TRUE,
      '#collapsible' => TRUE,
      '#title' => t('Settings'),
      '#weight' => -10,
    );

    $form['defaults']['default_fill_color_empty'] = array(
      '#type' => 'select',
      '#title' => 'Empty County Default Fill Color',
      '#options' => $color_list,
      '#multiple' => FALSE,
      '#required' => FALSE,
      '#empty_option' => 'Select Fill Color:',
      '#default_value' => $bean->defaults['default_fill_color_empty'],
      '#description' => 'Choose a fill color for counties without data.',
      '#required' => FALSE,
      '#weight' => -100,
    );

    $form['defaults']['default_fill_color_populated'] = array(
      '#type' => 'select',
      '#title' => 'Populated County Default Fill Color',
      '#options' => $color_list,
      '#multiple' => FALSE,
      '#required' => FALSE,
      '#empty_option' => 'Select Fill Color:',
      '#default_value' => $bean->defaults['default_fill_color_populated'],
      '#description' => 'Choose a fill color for counties with data that do not have a color selected.',
      '#required' => FALSE,
      '#weight' => -99,
    );

    return $form;
  }

  /**
   * View the Bean.
   */
  public function view($bean, $content, $view_mode = 'default', $langcode = NULL) {
    $wrapper = entity_metadata_wrapper('bean', $bean);
    $variables = $bean->settings;
    $variables['bean'] = $bean;
    $variables['title'] = $bean->title;

    $county_destinations = $bean->settings;
    usort($county_destinations,"nc_map_cmp");

    // Run URL function on all county links.
    $i = 0;
    foreach($county_destinations as $destination) {
      if (!empty($destination['url'])) {
        $county_destinations[$i]['url'] = url($destination['url']);
      }
      $i++;
    }

    $map_defaults = $bean->defaults;

    $svg_map = file_get_contents(drupal_get_path('module', 'nc_map') . '/nc-map.svg');

    // Render array for NC Map content.
    $content = array(
      'container' => array(
        '#prefix' => '<div class="map-wrapper">',
        '#suffix' => t('<button class="nc-map-info-toggle button">Text Version</button><div class="county-display"><button class="nc-map-info-close button">Interactive Map</button></div></div>'),
        'markup' => array(
          '#markup' => $svg_map,
        ),
      ),
      '#attached' => array(
        'css' => array(
          array(
            'type' => 'file',
            'data' => drupal_get_path('module', 'nc_map') . '/css/nc-map-style.css',
          ),
        ),
        'js' => array(
          array(
            'type' => 'file',
            'data' => drupal_get_path('module', 'nc_map') . '/js/nc-map.js',
          ),
          array(
            'type' => 'setting',
            'data' => array(
              'countyDestinations' => array(
                $county_destinations,
              ),
              'defaults' => array(
                $map_defaults,
              ),
            ),
          ),
        ),
        'library' => array(
          array('system', 'ui.tooltip', [$every_page = NULL]),
        ),
      ),
    );

    return $content;
  }
}

function nc_map_cmp($a, $b) {
        if ($a['county'] == $b['county']) {
                return 0;
        }
        return ($a['county'] < $b['county']) ? -1 : 1;
}