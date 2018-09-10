<?php
/**
 * @file
 * Theme functions for nc_fields.
 */

/**
 * Theme NC term labels.
 */
function theme_nc_term_label($variables) {
  $class = '';
  switch ($variables['type']) {
    case 'simple':
      $class = "label tag";
      break;
  }
  $build = array(
    '#markup' => t('!term_name', array('!term_name' => $variables['term']->name)),
    '#prefix' => '<span class="' . $class . '" itemprop="keywords">',
    '#suffix' => '</span>',
  );
  return $build;
}

/**
 * Theme NC file detail output.
 */
function theme_nc_file_detail($variables) {
  // Figure out what the title of the file should be.
  $official_title = FALSE;
  if ($variables['node']) {
    $node = $variables['node'];
    $official_title = field_get_items('node', $node, 'field_official_title', $variables['language']);
  }
  if ($official_title) {
    $title = $official_title[0]['safe_value'];
  }
  else {
    $title = $variables['file']['filename'];
  }

  $description = '';
  if (!empty($variables['file']['description'])) {
    $description = check_plain($variables['file']['description']);
  }

  $doctype = nc_fields_file_mime_to_doctype($variables['file']['filemime']);
  $icon = $doctype['icon'];
  $type = $doctype['type'];
  $uri = file_create_url($variables['file']['uri']);
  $size = format_size($variables['file']['filesize'], $variables['language']);
  $build = array(
    'article' => array(
      '#prefix' => '<article class="file" itemscope="" itemtype="http://schema.org/Article">',
      '#suffix' => '</article>',
      'preview' => array(
        '#prefix' => '<div class="file-thumb preview">',
        '#suffix' => '</div>',
        'span' => array(
          '#prefix' => "<span class=\"icon-doctype {$icon}\" aria-hidden=\"true\"></span>",
          '#suffix' => '<span class="icon-attachment" aria-hidden="true"></span>',
        ),
      ),
      'title' => array(
        '#markup' => l(check_plain($title), $uri),
        '#prefix' => '<h1 itemprop="name">',
        '#suffix' => '</h1>',
      ),
      'description' => array(
        '#markup' => $description,
        '#prefix' => '<p>',
        '#suffix' => '</p>',
      ),
      'meta' => array(
        '#prefix' => '<div class="meta">',
        '#suffix' => '</div>',
        'category' => array(
          '#markup' => "<span class=\"label category\">{$type}</span>",
        ),
        'file-size' => array(
          '#markup' => " • <span class=\"label file-size\">{$size}</span>",
        ),
      ),
      'download' => array(
        '#markup' => l(t('Download'), $uri, array(
          'attributes' => array(
            'itemprop' => 'url',
          ),
        )),
      ),
    ),
  );
  return $build;
}

/**
 * Theme the last_updated style of dates.
 */
function theme_nc_date($variables) {
  $build = array(
    '#prefix' => '<div class="first-published">',
    '#suffix' => '</div>',
    'time' => array(
      '#markup' => date('M j, Y', strtotime($variables['date']['value'] . $variables['date']['timezone'])),
      '#prefix' => '<time itemprop="datePublished">',
      '#suffix' => '</time>',
    ),
  );
  return $build;
}
