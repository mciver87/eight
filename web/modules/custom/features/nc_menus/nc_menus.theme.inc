<?php

/**
 * @file
 * Theme functions for nc_menu.
 */

/**
 * Implements theme_HOOK() for links__main_menu.
 */
function theme_menu_tree__main_menu__nc_menus($variables) {
  $mega_menu = theme_get_setting('mega_menu', 'nc_base_theme');
  $site_frontpage = url(variable_get('site_frontpage', 'node'), array('absolute' => TRUE));
  $site_name = variable_get('site_name', t('North Carolina'));
  $icon = variable_get('theme_nc_base_theme_settings', NULL);
  $icon_path = (is_array($icon)) ? $icon['logo_path'] : '';
  $links = $variables['tree'];
  $topical_menu_style = (theme_get_setting('theme_style', 'nc_site_theme_one') ? 'topical-nav-' . theme_get_setting('theme_style', 'nc_site_theme_one') : 'topical-nav');

  $data = array();
  $build = array(
    'topical_wrapper' => array(
      '#prefix' => "<nav class='{$topical_menu_style}' role='navigation' aria-label='Topical Navigation'><h2 class='visuallyhidden'>Topical Navigation</h2>",
      '#suffix' => '</nav>',
      'menu' => array(
        '#prefix' => '<ul class="wrapper">',
        '#suffix' => '</ul>',
      ),
    ),
  );
  $elements = element_children($links);
  $num_links = count($elements);
  $i = 1;
  // Build the links within the menu as nested render arrays.
  foreach ($elements as $id) {
    $link = $variables['tree'][$id];
    // Convert the link to a standard url.
    $link['#href'] = url($link['#href']);
    // $link['#attributes']['class'][] = $id;
    // Themeing each link depends on the depth of the link within the menu.
    // If a first level has children, render the second level. If a second level
    // has children, render the third level. Each level is its own ul/li combo.
    // There is no fourth level.

    // Add relevant classes to the link attributes.
    if (!empty($link['#attributes']['class'])) {
      // Add the has-dropdown class if needed.
      if (in_array('expanded', $link['#attributes']['class'])) {
        if (!variable_get('disable_main_menu_expand', FALSE)) {
          $link['#attributes']['class'][] = 'has-dropdown';
        }
        if ($mega_menu == 1) {
          $link['#attributes']['class'][] = 'has-mega';
        }
      }
      // Add the current-page class if needed.
      if (in_array('active-trail', $link['#attributes']['class'])) {
        $link['#attributes']['class'][] = 'current-page';
      }
      // Get Menu Attributes if set.
      if (!empty($link['#localized_options']['item_attributes'])) {
        $link['#attributes']['class'][] = $link['#localized_options']['item_attributes']['class'];
      }
      // Add home class if we are on the first link.
      if (in_array('first', $link['#attributes']['class'])) {
        $link['#attributes']['class'][] = 'home';
      }
    }
    $data[$id] = array(
      'first_level' => array(
        '#prefix' => '<li' . drupal_attributes($link['#attributes']) . '>',
        '#suffix' => '</li>',
        'link' => array(
          '#markup' => $link['#title'],
          '#prefix' => "<a href='{$link['#href']}'>",
          '#suffix' => '</a>',
        ),
      ),
    );
    if (!empty($link['#localized_options']['attributes']['target'])) {
      $data[$id]['first_level']['link']['#prefix'] = "<a target='" . $link['#localized_options']['attributes']['target'] . "' href='{$link['#href']}'>";
    }

    $i++;

    // If the link has a 'child', do second level work.
    if (!empty($link['#below']) && !variable_get('disable_main_menu_expand', FALSE)) {

      // Add flyout to the last 1st level link.
      $data[$id]['first_level']['link']['#prefix'] = "<a href='{$link['#href']}'><span class='icon-chevron-right' aria-hidden='true'></span>";

      // Start working on the 2nd level.
      $data[$id]['first_level']['second_level'] = array(
        'parent' => array(
          'wrapper' => array(
            '#prefix' => '<div aria-label="Second level">',
            '#suffix' => '</div>',
            'parent_title' => array(
              '#markup' => "<a href='{$link['#href']}' class='parent-title wrapper' aria-hidden='true'><span>{$link['#title']}</span></a>",
            ),
            'list_wrapper' => array(
              '#prefix' => '<ul class="wrapper">',
              '#suffix' => '</ul>',
              'list_first' => array(
                '#prefix' => '<li class="flyout-trigger back-trigger" aria-hidden="true"><button href="#"><span class="icon-chevron-left" aria-hidden="true"></span> Back</button></li>',
              ),
            ),
          ),
        ),
      );
      // Add the level 1 link to the 2nd level items, since the level 1 item is
      // not clickable.
      $level_1_parent[0] = array(
        '#theme' => $link['#theme'],
        '#attributes' => array(),
        '#title' => $link['#title'],
        '#href' => $link['#href'],
        '#localized_options' => $link['#localized_options'],
      );
      $link['#below'] = ($mega_menu == 1) ? $link['#below'] : $level_1_parent + $link['#below'];
      $level_2_links = element_children($link['#below']);
      foreach ($level_2_links as $index) {
        $level_2_link = $link['#below'][$index];
        $level_2_link['#href'] = url($level_2_link['#href']);

        $expanded = !empty($level_2_link['#original_link']['expanded']) ? TRUE : FALSE;
        $mega_menu_hide_tertiary = theme_get_setting('mega_menu_hide_tertiary') ? TRUE : FALSE;
        if (!empty($level_2_link['#below']) && !$mega_menu_hide_tertiary && $expanded) {
          $level_2_link['#attributes']['class'][] = 'has-dropdown';
          $data[$id]['first_level']['second_level']['parent']['wrapper']['list_wrapper'][$index] = array(
            '#prefix' => '<li' . drupal_attributes($level_2_link['#attributes']) . '>',
            '#suffix' => '</li>',
            'link' => array(
              '#markup' => $level_2_link['#title'],
              '#prefix' => "<a href='{$level_2_link['#href']}'><span class='icon-chevron-right' aria-hidden='true'></span>",
              '#suffix' => '</a>',
            ),
          );
        }
        else {
          $data[$id]['first_level']['second_level']['parent']['wrapper']['list_wrapper'][$index] = array(
            '#prefix' => '<li' . drupal_attributes($level_2_link['#attributes']) . '>',
            '#suffix' => '</li>',
            'link' => array(
              '#markup' => $level_2_link['#title'],
              '#prefix' => "<a href='{$level_2_link['#href']}'>",
              '#suffix' => '</a>',
            ),
          );
        }
        // Do 3rd level work, but only if theme setting allows, and only if
        // expanded.
        if (!empty($level_2_link['#below']) && !$mega_menu_hide_tertiary && $expanded) {
          // Start working on the 3nd level.
          $data[$id]['first_level']['second_level']['parent']['wrapper']['list_wrapper'][$index]['third_level'] = array(
            'parent' => array(
              'wrapper' => array(
                '#prefix' => '<div aria-label="Third level" class="third-level">',
                '#suffix' => '</div>',
                'parent_title' => array(
                  '#markup' => "<a href='{$level_2_link['#href']}' class='parent-title' aria-hidden='true'>{$level_2_link['#title']}</a>",
                ),
                'list_wrapper' => array(
                  '#prefix' => '<ul class="wrapper">',
                  '#suffix' => '</ul>',
                  'list_first' => array(
                    '#prefix' => '<li class="flyout-trigger back-trigger" aria-hidden="true"><button href="#"><span class="icon-chevron-left" aria-hidden="true"></span> Back</button></li>',
                  ),
                ),
              ),
            ),
          );

          $level_3_links = $elements = element_children($level_2_link['#below']);
          foreach ($level_3_links as $item) {
            $level_3_link = $level_2_link['#below'][$item];
            $level_3_link['#href'] = url($level_3_link['#href']);
            $data[$id]['first_level']['second_level']['parent']['wrapper']['list_wrapper'][$index]['third_level']['parent']['wrapper']['list_wrapper'][$item] = array(
              '#prefix' => '<li' . drupal_attributes($level_3_link['#attributes']) . '>',
              '#suffix' => '</li>',
              'link' => array(
                '#markup' => $level_3_link['#title'],
                '#prefix' => "<a href='{$level_3_link['#href']}'>",
                '#suffix' => '</a>',
              ),
            );
          }
        }
      }
    }
  }
  $build['topical_wrapper']['menu']['items'] = $data;
  return $build;
}

/**
 * Implements theme_HOOK() for links__enterprise_nav_menu.
 */
function theme_menu_tree__enterprise_nav_menu__nc_menus($variables) {
  $links = $variables['tree'];
  $enterprise_menu_style = (theme_get_setting('theme_style', 'nc_site_theme_one') ? 'utility-nav-' . theme_get_setting('theme_style', 'nc_site_theme_one') : 'enterprise-nav');

  $build = array(
    'enterprise_wrapper' => array(
      '#prefix' => "<nav class='{$enterprise_menu_style}' role='navigation' aria-label='Enterprise Navigation'><h2 class='visuallyhidden'>Enterprise Navigation</h2>",
      '#suffix' => '</nav>',
      'menu' => array(
        '#prefix' => '<ul class="wrapper">',
        '#suffix' => '</ul>',
      ),
    ),
  );
  $data = array();
  $i = 1;
  $elements = element_children($links);
  foreach ($elements as $id) {
    $link = $variables['tree'][$id];
    $link['#href'] = url($link['#href']);
    $link['#attributes']['class'][] = $id;
    if (!empty($link['#localized_options']['item_attributes'])) {
      $link['#attributes']['class'][] = $link['#localized_options']['item_attributes']['class'];
    }
    $data[$id] = array(
      '#prefix' => '<li>',
      '#suffix' => '</li>',
      'link' => array(
        '#prefix' => "<a href='{$link['#href']}' title='{$link['#title']}'>",
        '#suffix' => "<span>{$link['#title']}</span></a>",
      ),
    );
    if (!empty($link['#localized_options']['attributes']['target'])) {
      $data[$id]['link']['#prefix'] = "<a target='" . $link['#localized_options']['attributes']['target'] . "' href='{$link['#href']}' title='{$link['#title']}'>";
    }

    if (!theme_get_setting('theme_style', 'nc_site_theme_one')) {
      // The first link always gets the icon.
      if ($i == 1) {
        $data[$id]['link']['icon'] = array(
          '#prefix' => '<span class="icon-nc-brand" aria-hidden="true"></span><span>' . check_plain($link['#title']),
          '#suffix' => '</span>',
        );
        unset($data[$id]['link']['#suffix']);
      }
      else {
        // Get the custom icon class.
        $icons = nc_menus_icon_attribute_classes_options();
        if (!empty($link['#localized_options']['item_attributes'])) {
          $data[$id]['link']['link_icon'] = array(
            '#prefix' => "<span class='{$icons[$link['#localized_options']['item_attributes']['icon']]}' aria-hidden='true'>",
            '#suffix' => '</span>',
          );
        }
      }
    }
    $i++;
  }
  $build['enterprise_wrapper']['menu']['items'] = $data;
  return $build;
}

/**
 * Implements theme_HOOK() for links__network_menu.
 */
function theme_menu_tree__network_menu__nc_menus($variables) {
  $site_frontpage = url(variable_get('site_frontpage', 'node'), array('absolute' => TRUE));
  $site_name = variable_get('site_name', t('North Carolina'));
  $site_slogan_value = variable_get('site_slogan', NULL);
  if (!empty($site_slogan_value)) {
    $site_slogan = '<span>' . $site_slogan_value . '</span>';
  }
  else {
    $site_slogan = "";
  }

  $icon_path = theme_get_setting('logo_footer_path');
  if (!$icon_path) {
    // Leaving this check for backwards compatibility.
    $icon_path = theme_get_setting('logo_path');
  }

  $links = $variables['tree'];
  $build = array(
    'network_wrapper' => array(
      '#prefix' => '<div class="wrapper"><section>',
      '#suffix' => '</section></div>',
      'menu' => array(
        '#prefix' => '<nav><ul class="group">',
        '#suffix' => '</ul></nav>',
      ),
      'logo' => array(
        '#prefix' => '<div class="brand"><a href="' . $site_frontpage . '" title="' . $site_name . '">',
        '#suffix' => '</a>' . $site_slogan . '</div>',
        'logo_img' => array(
          '#theme' => 'image',
          '#path' => $icon_path,
          '#alt' => t('!site_name', array('!site_name' => $site_name)),
        ),
      ),
    ),
  );
  $data = array();
  $elements = element_children($links);
  foreach ($elements as $id) {
    $link = $variables['tree'][$id];
    $link['#href'] = url($link['#href']);
    $link['#attributes']['class'][] = $id;
    $data[$id] = array(
      '#prefix' => '<li>',
      '#suffix' => '</li>',
      'link' => array(
        '#prefix' => "<a href='{$link['#href']}' title='{$link['#title']}'>",
        '#suffix' => "<span>{$link['#title']}</span><span class='icon-chevron-right' aria-hidden='true'></span></a>",
      ),
    );
  }
  $build['network_wrapper']['menu']['items'] = $data;
  return $build;
}
