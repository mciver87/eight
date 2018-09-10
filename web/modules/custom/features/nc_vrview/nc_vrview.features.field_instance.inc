<?php
/**
 * @file
 * nc_vrview.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function nc_vrview_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'bean-nc_vrview-field_360_image'.
  $field_instances['bean-nc_vrview-field_360_image'] = array(
    'bundle' => 'nc_vrview',
    'deleted' => 0,
    'description' => 'VR view supports mono 360 images and videos. Images and video need to be stored in the equirectangular-panoramic (equirect-pano) format, which is a common format supported by many capture solutions.
<ul>
<li>VR view images can be stored as png, jpeg, or gif. We recommend you use jpeg for improved compression.</li>
<li>For maximum compatibility and performance, image dimensions should be powers of two (e.g., 2048 or 4096).</li>
<li>Images should be 2:1 aspect ratio (e.g. 4096 x 2048).</li>
</ul>',
    'display' => array(
      'card' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
          'style_settings' => array(
            'content' => array(
              'class' => 'field-items',
              'element' => 'div',
            ),
            'default_classes' => TRUE,
            'item' => array(
              'class' => 'field-item',
              'element' => 'div',
            ),
            'item_limit' => '',
            'prefix_markup' => '',
            'title' => array(
              'class' => 'field-label',
              'element' => 'div',
              'suffix' => ':',
            ),
            'wrapper' => array(
              'class' => '',
              'element' => 'div',
            ),
          ),
        ),
        'type' => 'image',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'bean',
    'field_name' => 'field_360_image',
    'label' => '360 Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => '3d-images',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'imce_filefield_on' => 1,
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'bean-nc_vrview-field_360_video'.
  $field_instances['bean-nc_vrview-field_360_video'] = array(
    'bundle' => 'nc_vrview',
    'deleted' => 0,
    'description' => 'VR view supports mono and stereo 360 images and videos. Images and video need to be stored in the equirectangular-panoramic (equirect-pano) format, which is a common format supported by many capture solutions.
<ul>
<li>VR view videos should be stored as mp4s encoded with h264.</li>
<li>Mono videos should be 2:1 aspect ratio.</li>
<li>Stereo videos should be 1:1 aspect ratio.</li>
<li>Some older devices cannot decode video larger than 1080p (1920x1080). If maximum compatibility and quality is a priority, we recommend that users provide both a monoscopic 1920x1080 video and a stereo video at 2048x2048 or higher.</li>
</ul>',
    'display' => array(
      'card' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(
          'style_settings' => array(
            'content' => array(
              'class' => 'field-items',
              'element' => 'div',
            ),
            'default_classes' => TRUE,
            'item' => array(
              'class' => 'field-item',
              'element' => 'div',
            ),
            'item_limit' => '',
            'prefix_markup' => '',
            'title' => array(
              'class' => 'field-label',
              'element' => 'div',
              'suffix' => ':',
            ),
            'wrapper' => array(
              'class' => '',
              'element' => 'div',
            ),
          ),
        ),
        'type' => 'file_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'bean',
    'field_name' => 'field_360_video',
    'label' => '360 Video',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => '3d-videos',
      'file_extensions' => 'mp4',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'imce_filefield_on' => 1,
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 3,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('360 Image');
  t('360 Video');
  t('VR view supports mono 360 images and videos. Images and video need to be stored in the equirectangular-panoramic (equirect-pano) format, which is a common format supported by many capture solutions.
<ul>
<li>VR view images can be stored as png, jpeg, or gif. We recommend you use jpeg for improved compression.</li>
<li>For maximum compatibility and performance, image dimensions should be powers of two (e.g., 2048 or 4096).</li>
<li>Images should be 2:1 aspect ratio (e.g. 4096 x 2048).</li>
</ul>');
  t('VR view supports mono and stereo 360 images and videos. Images and video need to be stored in the equirectangular-panoramic (equirect-pano) format, which is a common format supported by many capture solutions.
<ul>
<li>VR view videos should be stored as mp4s encoded with h264.</li>
<li>Mono videos should be 2:1 aspect ratio.</li>
<li>Stereo videos should be 1:1 aspect ratio.</li>
<li>Some older devices cannot decode video larger than 1080p (1920x1080). If maximum compatibility and quality is a priority, we recommend that users provide both a monoscopic 1920x1080 video and a stereo video at 2048x2048 or higher.</li>
</ul>');

  return $field_instances;
}
