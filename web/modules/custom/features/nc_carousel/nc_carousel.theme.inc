<?php
/**
 * @file
 * NC Carousel theme templates.
 */

/**
 * Get the html data attribute for the carousel.
 *
 * @param array $variables
 *   Variables.
 *
 * @return string
 *   Returns the html data attribute.
 */
function nc_carousel_get_carousel_data($variables) {
  $data = isset($variables['carousel_options']) ? $variables['carousel_options'] : array();
  return 'data-nc-carousel=\'' . drupal_json_encode($data) . '\'';
}

/**
 * Theme nc_carousel_slide.
 */
function theme_nc_carousel_slide(&$variables) {
  // Default type.
  $type = isset($variables['banner_type']) ? $variables['banner_type'] : 'widescreen';

  $content = array(
    'carousel' => array(
      '#prefix' => '<div class="owl-carousel ncgov-theme ' . _get_carousel_class($type) . '" ' . nc_carousel_get_carousel_data($variables) . '>',
      '#suffix' => '</div>',
    ),
  );

  // Iterate over the slides content and build our html.
  foreach ($variables['slides'] as $index => $slide) {
    $content['carousel']["item-{$index}"] = array(
      '#prefix' => '<div class="item">',
      '#suffix' => '</div>',
      'item_wrapper' => array(
        '#prefix' => '<div class="item__wrapper">',
        '#suffix' => '</div>',
        'item_image' => array(
          '#markup' => render($slide['data']['image']),
        ),
        'item_content' => array(
          '#prefix' => '<div class="item__content">',
          '#suffix' => '</div>',
          'item_content_align' => array(
            '#prefix' => '<div class="item__content-wrapper">',
            '#suffix' => '</div>',
            'item_category' => array(
              '#markup' => t('!text', array('!text' => $slide['data']['category'])),
              '#prefix' => '<em class="item__category">',
              '#suffix' => '</em>',
            ),
            'item_heading' => array(
              '#markup' => t('!text', array('!text' => ($slide['data']['heading']))),
              '#prefix' => '<h3 class="item__heading">',
              '#suffix' => '</h3>',
            ),
            'item_text_container' => array(
              '#prefix' => '<div class="item__text">',
              '#suffix' => '</div>',
              'item_text' => array(
                '#markup' => t('!text', array('!text' => $slide['data']['text'])),
                '#prefix' => '<p>',
                '#suffix' => '</p>',
              ),
            ),
            'item_count' => array(
              '#prefix' => '<span class="item__count">',
              '#suffix' => '',
              'item_count_current' => array(
                '#prefix' => '<span class="item__count--current">',
                '#suffix' => '</span>',
                '#markup' => $index + 1,
              ),
              'item_count_markup' => array(
                '#markup' => ' ' . t('of') . ' ',
              ),
              'item_count_total' => array(
                '#prefix' => '<span class="item__count--total">',
                '#suffix' => '</span>',
                '#markup' => count($variables['slides']),
              ),
            ),
          ),
        ),
      ),
    );
    // Only render the link button if a link has been provided.
    if (!empty($slide['data']['link_button']['url']) && !empty($slide['data']['link_button']['title'])) {
      $content['carousel']["item-{$index}"]['item_wrapper']['item_content']['item_content_align']['item_text_container']['item_link_button'] = array(
        '#markup' => t('!text', array('!text' => filter_xss($slide['data']['link_button']['title']))),
        '#prefix' => '<a href="' . check_url($slide['data']['link_button']['url']) . '" class="button ghost inverted">',
        '#suffix' => '</a>',
      );
    }
    // Only render item_content if there is some content.
    if (empty($slide['data']['text']) && empty($slide['data']['category']) && empty($slide['data']['heading'])) {
      unset($content['carousel']["item-{$index}"]['item_wrapper']['item_content']);
    }
  }
  $theme = drupal_get_path('theme', 'nc_base_theme');

  // Add the owl carousel library.
  $content['#attached'] = array(
    'js' => array(
      $theme . '/js/vendors/owl.carousel.js' => array(
        'scope' => 'footer',
      ),
      // Include our module's js file.
      drupal_get_path('module', 'nc_carousel') . '/nc_carousel.js' => array(
        'scope' => 'footer',
      ),
    ),
  );
  return $content;
}

/**
 * Theme nc_carousel_hero.
 */
function theme_nc_carousel_hero(&$variables) {
  // Default type.
  $type = isset($variables['banner_type']) ? $variables['banner_type'] : 'widescreen';

  $slide = $variables['slide'];
  $content = array(
    'carousel' => array(
      '#prefix' => '<div class=" ncgov-theme ' . _get_carousel_class($type) . '">',
      '#suffix' => '</div>',
    ),
  );

  // Iterate over the slides content and build our html.
  $content['carousel']["item"] = array(
    '#prefix' => '<div class="item">',
    '#suffix' => '</div>',
    'item_wrapper' => array(
      '#prefix' => '<div class="item__wrapper">',
      '#suffix' => '</div>',
      'item_image' => array(
        '#markup' => render($slide['data']['image']),
      ),
      'item_content' => array(
        '#prefix' => '<div class="item__content">',
        '#suffix' => '</div>',
        'item_content_align' => array(
          '#prefix' => '<div class="item__content-wrapper">',
          '#suffix' => '</div>',
          'item_category' => array(
            '#markup' => t('!text', array('!text' => $slide['data']['category'])),
            '#prefix' => '<em class="item__category">',
            '#suffix' => '</em>',
          ),
          'item_heading' => array(
            '#markup' => t('!text', array('!text' => $slide['data']['heading'])),
            '#prefix' => '<h3 class="item__heading">',
            '#suffix' => '</h3>',
          ),
          'item_text_container' => array(
            '#prefix' => '<div class="item__text">',
            '#suffix' => '</div>',
            'item_text' => array(
              '#markup' => t('!text', array('!text' => $slide['data']['text'])),
              '#prefix' => '<p>',
              '#suffix' => '</p>',
            ),
          ),
        ),
      ),
    ),
  );

  // Only render item_content if there is some content.
  if (empty($slide['data']['text']) && empty($slide['data']['category']) && empty($slide['data']['heading'])) {
    unset($content['carousel']["item"]['item_wrapper']['item_content']);
  }

  // Only render the link button if a link has been provided.
  if (!empty($slide['data']['link_button']['url']) && !empty($slide['data']['link_button']['title'])) {
    $content['carousel']["item"]['item_wrapper']['item_content']['item_content_align']['item_text_container']['item_link_button'] = array(
      '#markup' => t('!text', array('!text' => filter_xss($slide['data']['link_button']['title']))),
      '#prefix' => '<a href="' . check_url($slide['data']['link_button']['url']) . '" class="button ghost inverted">',
      '#suffix' => '</a>',
    );
  }
  return $content;
}

/**
 * Returns the carousel class to be used for the type chosen.
 *
 * @param string $type
 *   The type of carousel being used.
 *
 * @return string
 *   The css class to be added to the prefix for the carousel type.
 */
function _get_carousel_class($type) {
  switch ($type) {
    case 'widescreen-full-width':
      $carousel_class = 'full-width';
      break;

    case 'letterbox':
      $carousel_class = 'split-hero';
      break;

    case 'container-widescreen':
    default:
      $carousel_class = '';
      break;

  }

  return $carousel_class;
}
