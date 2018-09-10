<?php
/**
 * @file
 * NC Carousel Bean plugin.
 */

class NCCarouselBean extends BeanPlugin {
  /**
   * Displays the bean.
   */
  public function view($bean, $content, $view_mode = 'default', $langcode = NULL) {
    // get the slides
    $slides = field_get_items('bean', $bean, 'field_slide', LANGUAGE_NONE);
    foreach ($slides as $index => $slide) {
      $field_collection = field_collection_item_load($slide['value']);
      $fields = field_attach_view('field_collection_item', $field_collection, $view_mode, $langcode);
      $wrapper = entity_metadata_wrapper('field_collection_item', $field_collection);
      if ($wrapper->field_hide_slide->value()) {
        unset($slides[$index]);
        continue;
      }
      $slides[$index]['data']['image'] = !empty($fields['field_slide_image'][0]) ? $fields['field_slide_image'][0] : '';
      $slides[$index]['data']['category'] = $wrapper->field_slide_category->value();
      $slides[$index]['data']['heading'] = $wrapper->field_slide_heading->value();
      $slides[$index]['data']['text'] = $wrapper->field_slide_text->value();
      if (is_array($slides[$index]['data']['text'])) {
        $slides[$index]['data']['text'] = render($wrapper->field_slide_text->value->value());
      }

      $button = $wrapper->field_slide_link_button->value();
      $slides[$index]['data']['link_button']['title'] = !empty($button['title']) ? $button['title'] : '';
      $slides[$index]['data']['link_button']['url'] = !empty($button['url']) ? url($button['url'], $button) : '';
    }

    // get the type
    $type = field_get_items('bean', $bean, 'field_banner_type', LANGUAGE_NONE);
    if (is_array($type)) {
      $type = $type[0]['value'];
    } else {
      $type = 'widescreen';
    }

    if (count($slides) > 1) {
      $content = theme('nc_carousel_slide', array('slides' => $slides, 'banner_type' => $type, 'carousel_options' => $this->getCarouselOptions($bean)));
    }
    else {
      $content = theme('nc_carousel_hero', array('slide' => reset($slides), 'banner_type' => $type));
    }
    return $content;
  }

  /**
   * Extract Owl Carousel autoplay options.
   *
   * @param Bean $bean
   *   Bean.
   *
   * @return array
   *   Data.
   */
  protected function getCarouselOptions($bean) {
    // Default options.
    $options = array(
      'autoPlay' => false,
      'stopOnHover' => true
    );

    // Get bean values.
    $node_wrapper = entity_metadata_wrapper('bean', $bean);

    // Get autoplay options.
    if (isset($node_wrapper->field_carousel_autoplay_enabled) && isset($node_wrapper->field_carousel_autoplay_inverval)) {
      $autoplay_enabled  = $node_wrapper->field_carousel_autoplay_enabled->value();
      $autoplay_interval = $node_wrapper->field_carousel_autoplay_inverval->value();
    }

    // Update options
    if ($autoplay_enabled && $autoplay_interval > 0) {
      $options['autoPlay'] = $autoplay_interval;
    }

    return $options;
  }
}
