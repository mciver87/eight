<?php
/**
 * @file
 * Theme functions for nc_search.
 */

/**
 * Theme Featured Results.
 */
function theme_nc_search_featured_results($variables) {
  $view = $variables['view'];
  // We let Views render the row as its defined View plugin.
  $renderer = $view->style_plugin->row_plugin;
  $view->row_index = 0;
  $build = array(
    '#markup' => $renderer->render($variables['row']),
  );
  $build['#attached']['css'] = array(
    drupal_get_path('module', 'nc_search') . '/nc_search.css',
  );
  return $build;
}
