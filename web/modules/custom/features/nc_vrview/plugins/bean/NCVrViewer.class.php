<?php
/**
 * @file
 * NC Vr Viewer Bean.
 */

class NcVrViewerBean extends BeanPlugin {

  /**
   * Declares default block settings.
   */
  public function values() {
    $values = array(
      'settings' => array(),
    );
    return array_merge(parent::values(), $values);
  }

  /**
   * Bean form.
   */
  public function form($bean, $form, &$form_state) {
    $form['#prefix'] = '<p><strong>Please upload either an image or a video, but not both.</strong></p>';
    return $form;
  }


  /**
   * View the Bean.
   */
  public function view($bean, $content, $view_mode = 'default', $langcode = NULL) {
    //Drupal.settings.ncVrViewer.items{ .vrType (video/image), .htmlId (alphanumeric), .resourcePath (absolute url)}
    $wrapper = entity_metadata_wrapper('bean', $bean);
    // Get the image and video wrapper values.
    $image = $wrapper->field_360_image->value();
    $video = $wrapper->field_360_video->value();
    // Process video first, if empty, use image.
    if (!empty($video)) {
      $resource_path = $video['uri'];
      $vr_type = 'video';
    }
    else {
      $resource_path = $image['uri'];
      $vr_type = 'image';
    }
    $vr_id = 'vrview-' . $bean->bid;
    $viewer_settings['items'][] = array(
      'vrType' => $vr_type,
      'htmlId' => $vr_id,
      'resourcePath' => file_create_url($resource_path),
    );

    // Render array for NC Vr Viewer content.
    $content = array(
      'container' => array(
        '#prefix' => '<div class="vr-viewer" id="' . $vr_id . '">',
        '#suffix' => '</div>',
      ),
      '#attached' => array(
        'css' => array(
          'type' => 'file',
          'data' => drupal_get_path('module', 'nc_vrview') . '/css/nc-vrview.css',
        ),
        'js' => array(
          array(
            'type' => 'file',
            'data' => drupal_get_path('module', 'nc_vrview') . '/js/nc-vrview.js',
          ),
          array(
            'type' => 'file',
            'data' => drupal_get_path('module', 'nc_vrview') . '/viewerapi/build/vrview.min.js',
          ),
          array(
            'type' => 'setting',
            'data' => array('ncVrViewer' => $viewer_settings),
          ),
        ),
      ),
    );
    return $content;
  }
}
