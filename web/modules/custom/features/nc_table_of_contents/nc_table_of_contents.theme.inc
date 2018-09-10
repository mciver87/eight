<?php
/**
 * @file
 * NC Table of Contents theme functions.
 */

/**
 * Theme NC Table of Contents Block.
 */
function theme_nc_table_of_contents_block(&$variables) {
  $build = array(
    'links' => array(
      '#prefix' => '<section class="toc_block">',
      '#suffix' => '</section>',
      'links_title' => array(
        '#markup' => '<h3>' . t('!title', array('!title' => $variables['title'])) . '</h3>',
      ),
      'links_wrapper' => array(
        '#prefix' => '<ul class="toc-links">',
        '#suffix' => '<li>',
      ),
      '#attached' => $variables['attached']
    ),
  );
  if (empty($variables['title'])) {
    unset($build['links']['links_title']);
  }

  return $build;
}
