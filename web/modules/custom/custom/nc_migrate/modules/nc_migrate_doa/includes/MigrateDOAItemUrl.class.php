<?php
/**
 * @file
 * Implementation of MigrateDOAItem for URL lists.
 */

/**
 * Class MigrateItemUrl.
 */
class MigrateDOAItemUrl extends MigrateItem {
  /**
   * Implements getItem().
   */
  public function getItem($id) {
    // Load QueryPath to process file data.
    $qp_lib_path = libraries_get_path('querypath');
    if (FALSE === $qp_lib_path) {
      throw new MigrateException(t('Unable to locate library: @libname', array('@libname' => 'querypath')));
    }
    require_once $qp_lib_path . '/src/qp.php';

    $row = new stdClass();
    $data = FALSE;

    // Check for cached content, short-circuit if there.
    $cid = self::getCacheKey($id);
    $cache = cache_get($cid);
    if (FALSE !== $cache) {
      $data = $cache->data;
    }
    else {
      // Fake paths need not be fetched from http, and instead provided an empty
      // string.
      $url = parse_url($id);
      $host = !empty($url['host']) ? $url['host'] : NULL;
      if ($host == 'fakepath.domain') {
        $data = '';
      }
      else {
        $options = array(
          'timeout' => '300.0',
        );
        // Try to retrieve file.
        $id = str_replace(' ', '%20', trim($id));
        $resp = drupal_http_request($id, $options);
        if (200 == $resp->code) {
          $data = $resp->data;
        }
        if (!$data) {
          // Report failed retrieval.
          $migration = Migration::currentMigration();
          if ($migration) {
            $m = !empty($resp->status_message) ? $resp->status_message : $resp->error;
            $message = t('[HTTP/!code] @msg', array('@msg' => $m, '!code' => $resp->code));
            $migration->getMap()->saveMessage(array($id), $message, MigrationBase::MESSAGE_ERROR);
          }
          return NULL;
        }
      }
    }

    // Process page data if we have something to work with.
    if (FALSE !== $data) {
      // Add to cache.
      cache_set($cid, $data, 'cache', CACHE_TEMPORARY);

      // Populate new row object, assign the raw HTML to it and clean up.
      $row->raw_html = $data;
      $this->_scrubHTML($row);
    }

    return $row;
  }

  /**
   * Internal util method to scrub HTML pulled from a URL.
   *
   * Borrows heavily from https://gist.github.com/marktheunissen/2596787.
   */
  private function _scrubHTML($row) {
    // Preprocess HTML before handing off to QueryPath
    $html = $row->raw_html;

    // We need to strip the Windows CR characters, because otherwise we end up
    // with &#13; in the output.
    // http://technosophos.com/content/querypath-whats-13-end-every-line
    $html = str_replace(chr(13), '', $html);

    // If the content is not UTF8, we assume it's WINDOWS-1252. This fixes
    // bogus character issues. Technically it could be ISO-8859-1 but it's safe
    // to convert this way.
    // http://en.wikipedia.org/wiki/Windows-1252
    $enc = mb_detect_encoding($html, 'UTF-8', TRUE);
    if (!$enc) {
      $html = mb_convert_encoding($html, 'UTF-8', 'WINDOWS-1252');
    }

    // Init QueryPath object.
    $qp_options = array(
      'convert_to_encoding' => 'utf-8',
      'convert_from_encoding' => 'utf-8',
      'strip_low_ascii' => FALSE,
    );
    $row->qp = @htmlqp($html, NULL, $qp_options);

    if ($row->qp) {
      // Remove comments from the HTML.
      foreach ($row->qp->top()->xpath('//comment()')->get() as $comment) {
        $comment->parentNode->removeChild($comment);
      }
    }
  }

  /**
   * Static util method to generate unique cache key for item.
   */
  public static function getCacheKey($id) {
    return __CLASS__ . ':' . md5($id);
  }
}
