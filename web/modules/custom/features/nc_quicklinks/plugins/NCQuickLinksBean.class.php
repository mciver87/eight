<?php
/**
 * @file
 * NC Quick Links Bean plugin.
 */

class NCQuickLinksBean extends BeanPlugin {
  /**
   * Displays the bean.
   */
  public function view($bean, $content, $view_mode = 'default', $langcode = NULL) {
    $wrapper = entity_metadata_wrapper('bean', $bean);
    $links = $wrapper->field_quick_link->value();
    $style = $wrapper->field_quick_link_style->value();
    $style_a = $wrapper->field_quick_link_a_style->value();
    $heading = $wrapper->field_quick_links_header->value();
    $style_header = $wrapper->field_quick_links_header_style->value();
    $description = $wrapper->field_quick_links_description->value();
    if (!empty($links) && !empty($style)) {
      return theme('nc_quicklinks_links', array(
          'links' => $links,
          'style' => $style,
          'title' => $heading,
          'description' => $description,
          'style_header' => $style_header,
          'style_a'=> $style_a,
        )
      );
    }
  }
}
