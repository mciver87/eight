<?php
/**
 * @file
 * nc_wysiwyg.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function nc_wysiwyg_filter_default_formats() {
  $formats = array();

  // Exported format: Filtered HTML.
  $formats['filtered_html'] = array(
    'format' => 'filtered_html',
    'name' => 'Filtered HTML',
    'cache' => 1,
    'status' => 1,
    'weight' => 0,
    'filters' => array(
      'video_filter' => array(
        'weight' => -1,
        'status' => 0,
        'settings' => array(
          'video_filter_width' => 500,
          'video_filter_height' => 300,
          'video_filter_autoplay' => 0,
          'video_filter_related' => 0,
          'video_filter_html5' => 1,
          'video_filter_codecs' => array(
            'youtube' => 'YouTube',
            'youtube_playlist' => 'YouTube (Playlist)',
            'archive' => 'Archive.org',
            'flickr_slideshows' => 'Flickr Slideshows',
            'flickr_video' => 'Flickr Video',
            'slideshare' => 'Slideshare',
            'vimeo' => 'Vimeo',
          ),
        ),
      ),
      'filter_url' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'filter_html' => array(
        'weight' => 1,
        'status' => 1,
        'settings' => array(
          'allowed_html' => '<a> <em> <strong> <cite> <blockquote> <code> <ul> <ol> <li> <dl> <dt> <dd>',
          'filter_html_help' => 1,
          'filter_html_nofollow' => 0,
        ),
      ),
      'filter_autop' => array(
        'weight' => 2,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => 10,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  // Exported format: Full HTML.
  $formats['full_html'] = array(
    'format' => 'full_html',
    'name' => 'Full HTML',
    'cache' => 0,
    'status' => 1,
    'weight' => -1,
    'filters' => array(
      'video_filter' => array(
        'weight' => -1,
        'status' => 1,
        'settings' => array(
          'video_filter_width' => 500,
          'video_filter_height' => 300,
          'video_filter_autoplay' => 0,
          'video_filter_related' => 0,
          'video_filter_html5' => 1,
          'video_filter_codecs' => array(
            'youtube' => 'YouTube',
            'youtube_playlist' => 'YouTube (Playlist)',
            'archive' => 'Archive.org',
            'picasa_slideshows' => 'Picasa Slideshows',
            'slideshare' => 'Slideshare',
            'vimeo' => 'Vimeo',
          ),
        ),
      ),
      'ckeditor_link_filter' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_url' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'insert_view' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
      'nc_filters_node_card' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_autop' => array(
        'weight' => 1,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => 10,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  // Exported format: Plain text.
  $formats['plain_text'] = array(
    'format' => 'plain_text',
    'name' => 'Plain text',
    'cache' => 1,
    'status' => 1,
    'weight' => 10,
    'filters' => array(
      'video_filter' => array(
        'weight' => -1,
        'status' => 0,
        'settings' => array(
          'video_filter_width' => 400,
          'video_filter_height' => 400,
          'video_filter_autoplay' => 0,
          'video_filter_related' => 1,
          'video_filter_html5' => 1,
          'video_filter_codecs' => array(
            'youtube' => 'YouTube',
            'youtube_playlist' => 'YouTube (Playlist)',
            'archive' => 'Archive.org',
            'picasa_slideshows' => 'Picasa Slideshows',
            'slideshare' => 'Slideshare',
            'vimeo' => 'Vimeo',
          ),
        ),
      ),
      'filter_html_escape' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_url' => array(
        'weight' => 1,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'filter_autop' => array(
        'weight' => 2,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
