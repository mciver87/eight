<?php
/**
 * @file
 * Drush specifics hooks for nc_migrate_denr.
 */

/**
 * Implements hook_drush_command().
 */
function nc_migrate_denr_drush_command() {

  $items['denr-fix-urls'] = array(
    'description' => 'Fix Site Page body urls after DENR migration.',
    'aliases' => array('dfu'),
    'callback' => 'nc_migrate_denr_fix_urls',
  );

  return $items;
}



/**
 * Rewrite links in body field with corrected document urls.
 */
function nc_migrate_denr_fix_urls() {
  // Make sure we have querypath.
  $qp_lib_path = libraries_get_path('querypath');
  if (FALSE === $qp_lib_path) {
    throw new MigrateException(t('Unable to locate library: @libname', array('@libname' => 'querypath')));
  }
  require_once $qp_lib_path . '/src/qp.php';

  // Fetch the site_page nodes we care about.
  $query = db_select('node', 'n')
    ->fields('n', array('nid'))
    ->condition('type', 'site_page', '=')
    ->execute();

  // Iterate over the nodes, fetching the body field.
  while ($nid = $query->fetchField()) {
    $node = node_load($nid);
    if (!empty($node->body)) {
      // Parse the body field for links.
      $body = field_get_items('node', $node, 'body', $node->language);
      $body_value = $body[0]['value'];
      if (nc_migrate_denr_fix_urls_parse_links($node, $body_value)) {
        // Save each node after iterating each link in the body.
        $node->body["{$node->language}"][0]['value'] = $body_value;
        node_save($node);
        watchdog('nc_migrate_denr', 'Updated document links for node %node', array('%node' => $node->nid), WATCHDOG_NOTICE);
      }
      if (!empty($node->failed_links)) {
        watchdog('nc_migrate_denr', 'Failed updating links for node %node: %links', array('%node' => $node->nid, '%links' => var_export($node->failed_links, TRUE)), WATCHDOG_ERROR);
      }
    }
  }
}

/**
 * Helper function to parse node body field links for possible re-writing.
 *
 * @see nc_migrate_denr_fix_urls()
 *
 * @param object $node
 *   The node.
 *
 * @param string $value
 *   The body value.
 */
function nc_migrate_denr_fix_urls_parse_links($node, &$value) {
  $return = FALSE;
  $options = array(
    'use_parser' => 'html',
    'ignore_parser_warnings' => TRUE,
    'encoding' => 'utf-8',
  );
  $body = @qp($value, '*', $options);
  // Iterate over the links.
  $body->find('a')->each(function ($index, $item) use ($value, &$return, $node) {
    $item = qp($item) ;
    if ($item->attr('href')) {
      $href = $item->attr('href');
      // Determine if the link is one we want to re-write and do so.
      $parts = parse_url($href);
      if (strstr($parts['path'], 'document_library/get_file')) {
        $query = $parts['query'];
        // Lookup the file from the spreadsheet based on the query path.
        $url = nc_migrate_denr_fix_url_link_document($query);
        if ($url) {
          $item->attr('href', $url);
          $return = TRUE;
        }
        else {
          $node->failed_links[] = $href;
        }
      }
    }
  });
  if ($return) {
    $value = $body->children()->innerHTML();
  }
  return $return;
}

/**
 * Match an old document link with the updated url.
 *
 * @see nc_migrate_denr_fix_urls
 *
 * @param $query
 * @return BOOL
 */
function nc_migrate_denr_fix_url_link_document($query) {
  // Load the spreadsheet used in the document migration.
  $matches = FALSE;
  $file = variable_get('nc_migrate_denr_document_library', 'http://migrate.nc.p2devcloud.com/DENR_Portal_Document_Library_Map.csv');
  $handle = fopen($file, 'r');
  $url = preg_quote($query, "/");
  while ($data = fgetcsv($handle, 10000, ',')) {
    if (preg_match("/$url/i", $data[2], $matches)) {
      return $data[1];
    }
  }
  return FALSE;
}
