<?php
/**
 * @file
 * NC Quick Links Bean plugin.
 */

class NCTableOfContentsBean extends BeanPlugin {
  /**
   * Displays the bean.
   */
  public function view($bean, $content, $view_mode = 'default', $langcode = NULL) {
    $wrapper = entity_metadata_wrapper('bean', $bean);
    $heading = $wrapper->field_toc_header->value();
    $variables['toc_id'] = $bean->vid;
    $attached = $this->process_attached_js();

    if (!empty($heading)) {
      return theme('nc_table_of_contents_block', array(
          'title' => $heading,
          'attached' => $attached,
        )
      );
    }
  }

  /**
   * Function process_attached_js().
   * 
   * Handle attach array processing for the animated stat bean.
   *
   * @param string $stat_type
   *   The animation type.
   * @param array $variables
   *   Variables provided by the bean.
   *
   * @return array
   *   An array of JS to send to #attached.
   */
  private function process_attached_js() {
    $attached = array();
    // Add basic JS.
    $attached['js'][] = array(
      'data' => drupal_get_path('module', 'nc_table_of_contents') . '/js/nc_toc_block.js',
      'type' => 'file'
    );

    return $attached;
  }
}


