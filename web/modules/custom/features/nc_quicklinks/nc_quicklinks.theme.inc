<?php
/**
 * @file
 * NC Quick Links theme functions.
 */

/**
 * Theme NC Quicklinks Links Block.
 */
function theme_nc_quicklinks_links(&$variables) {
  if (empty($variables['links']) || empty($variables['style'])) {
    // No need to build any data if we lack our variables.
    return array();
  }
  // Convert the style into the actual class expected.
  $style_class = _nc_quicklinks_wrapper_style_to_class($variables['style']);
  $style_header_class = _nc_quicklinks_header_style_to_class($variables['style_header']);
  $style_a_class = _nc_quicklinks_link_style_to_class($variables['style_a']);
  $build = array(
    'links' => array(
      '#prefix' => '<section class="quick-links ' . $style_class . '">',
      '#suffix' => '</section>',
      'links_title' => array(
        '#markup' => '<h3 class="' . $style_header_class . '">' . t('!title', array('!title' => $variables['title'])) . '</h3>',
      ),
      'links_description' => array(
        '#markup' => '<p class="quick-links-description">' . t('!description', array('!description' => $variables['description'])) . '</p>',
      ),
      'links_wrapper' => array(
        '#prefix' => '<ul>',
        '#suffix' => '</ul>',
      ),
    ),
  );
  if (empty($variables['title'])) {
    unset($build['links']['links_title']);
  }
  if (empty($variables['description'])) {
    unset($build['links']['links_description']);
  }
  foreach ($variables['links'] as $index => $link) {
    $build['links']['links_wrapper']["link-{$index}"] = array(
      '#markup' => l($link['title'], url($link['url']), nc_quicklinks_build_link_options($link, $style_a_class)),
      '#prefix' => '<li>',
      '#suffix' => '</li>'
    );
  }

  return $build;
}

/**
 * Return link options for drupal l().
 *
 * This was implemented in response to NC-1077. The Quick Links were sometimes
 * using anchors to reference specific content on the target page, but the
 * anchor fragment was not appearing as part of the link url. This update
 * will re-add the fragments and other options for the l() function that
 * get passed along with the $link variable.
 *
 * @param array $link
 *   Link array.
 *
 * @return array
 *   Returns link options.
 */
function nc_quicklinks_build_link_options($link, $style) {
  // Remove the title & url from link options. Don't confuse Drupal.
  $keys = array_filter(array_keys($link), function ($k) {
    return !in_array($k, array('title', 'url'));
  });

  $options = array_intersect_key($link, array_flip($keys));

  if (!isset($options['attributes']) || !is_array($options['attributes']) || count($options['attributes']) < 1) {
    $options['attributes'] = array();
  }

  if (!isset($options['attributes']['title'])) {
    $options['attributes']['title'] = isset($link['title']) ? $link['title'] : $link['url'];
  }
  if (!isset($options['attributes']['class'])) {
    $options['attributes']['class'] = $style;
  }

  return $options;
}
