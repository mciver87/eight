<?php
/**
 * @file
 * nc_media_gallery.features.inc
 */

/**
 * Implements hook_views_api().
 */
function nc_media_gallery_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_field_default_field_instances_alter().
 */
function nc_media_gallery_field_default_field_instances_alter(&$data) {
  if (isset($data['node-media_gallery-body'])) {
    $data['node-media_gallery-body']['display']['basic_card'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-media_gallery-body']['display']['block_feature'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-media_gallery-body']['display']['default']['settings']['field_formatter_class'] = ''; /* WAS: '' */
    $data['node-media_gallery-body']['display']['default']['settings']['style_settings'] = array(
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
    ); /* WAS: '' */
  }
  if (isset($data['node-media_gallery-field_media_gallery_media'])) {
    $data['node-media_gallery-field_media_gallery_media']['display']['basic_card'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-media_gallery-field_media_gallery_media']['display']['block_feature'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-media_gallery-field_media_gallery_media']['display']['default']['settings']['field_formatter_class'] = ''; /* WAS: '' */
    $data['node-media_gallery-field_media_gallery_media']['display']['default']['settings']['style_settings'] = array(
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
    ); /* WAS: '' */
    $data['node-media_gallery-field_media_gallery_media']['display']['teaser']['module'] = 'node_reference'; /* WAS: 'node_reference_view_formatter' */
    $data['node-media_gallery-field_media_gallery_media']['display']['teaser']['settings']['field_formatter_class'] = ''; /* WAS: '' */
    $data['node-media_gallery-field_media_gallery_media']['display']['teaser']['settings']['node_reference_view_mode'] = 'full'; /* WAS: '' */
    $data['node-media_gallery-field_media_gallery_media']['display']['teaser']['settings']['style_settings'] = array(
      'content' => array(
        'class' => 'field-items',
        'element' => 'ul',
      ),
      'default_classes' => 1,
      'item' => array(
        'class' => 'field-item',
        'element' => 'li',
      ),
      'item_limit' => '',
      'prefix_markup' => '',
      'title' => array(
        'class' => 'field-label',
        'element' => 'h3',
        'suffix' => ':',
      ),
      'wrapper' => array(
        'class' => '',
        'element' => 'div',
      ),
    ); /* WAS: '' */
    $data['node-media_gallery-field_media_gallery_media']['display']['teaser']['type'] = 'node_reference_node'; /* WAS: 'node_reference_view' */
    unset($data['node-media_gallery-field_media_gallery_media']['display']['teaser']['settings']['view']);
  }
  if (isset($data['node-photo-body'])) {
    $data['node-photo-body']['display']['basic_card'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-photo-body']['display']['block_feature'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-photo-body']['display']['default']['settings']['field_formatter_class'] = ''; /* WAS: '' */
    $data['node-photo-body']['display']['default']['settings']['style_settings'] = array(
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
    ); /* WAS: '' */
    $data['node-photo-body']['display']['teaser']['type'] = 'hidden'; /* WAS: 'text_summary_or_trimmed' */
    unset($data['node-photo-body']['display']['teaser']['module']);
    unset($data['node-photo-body']['display']['teaser']['settings']['trim_length']);
  }
  if (isset($data['node-photo-field_photo_image'])) {
    $data['node-photo-field_photo_image']['display']['basic_card'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-photo-field_photo_image']['display']['block_feature'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
    $data['node-photo-field_photo_image']['display']['default']['settings']['field_formatter_class'] = ''; /* WAS: '' */
    $data['node-photo-field_photo_image']['display']['default']['settings']['style_settings'] = array(
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
    ); /* WAS: '' */
    $data['node-photo-field_photo_image']['display']['editors_choice']['settings']['field_formatter_class'] = ''; /* WAS: '' */
    $data['node-photo-field_photo_image']['display']['editors_choice']['settings']['style_settings'] = array(
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
    ); /* WAS: '' */
    $data['node-photo-field_photo_image']['display']['teaser']['settings']['field_formatter_class'] = ''; /* WAS: '' */
    $data['node-photo-field_photo_image']['display']['teaser']['settings']['image_link'] = ''; /* WAS: 'content' */
    $data['node-photo-field_photo_image']['display']['teaser']['settings']['image_style'] = ''; /* WAS: 'list-page-thumbnail' */
    $data['node-photo-field_photo_image']['display']['teaser']['settings']['style_settings'] = array(
      'content' => array(
        'class' => 'field-items',
        'element' => 'div',
      ),
      'default_classes' => 1,
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
    ); /* WAS: '' */
    $data['node-photo-field_photo_image']['widget']['settings']['filefield_sources'] = array(
      'filefield_sources' => array(),
      'source_attach' => array(
        'absolute' => 0,
        'attach_mode' => 'move',
        'path' => 'file_attach',
      ),
      'source_imce' => array(
        'imce_mode' => 0,
      ),
      'source_reference' => array(
        'autocomplete' => 0,
      ),
    ); /* WAS: '' */
  }
}

/**
 * Implements hook_image_styles_alter().
 */
function nc_media_gallery_image_styles_alter(&$data) {
  if (isset($data['media_gallery'])) {

  if (!isset($data['media_gallery']['storage']) || $data['media_gallery']['storage'] == IMAGE_STORAGE_DEFAULT) {
    $data['media_gallery']['effects'][0]['data']['height'] = 480;
  }

  if (!isset($data['media_gallery']['storage']) || $data['media_gallery']['storage'] == IMAGE_STORAGE_DEFAULT) {
    $data['media_gallery']['effects'][0]['data']['width'] = 480;
  }

  if (!isset($data['media_gallery']['storage']) || $data['media_gallery']['storage'] == IMAGE_STORAGE_DEFAULT) {
    $data['media_gallery']['effects'][1] = array(
      'data' => array(
        'height' => 125,
        'width' => 165,
      ),
      'dimensions callback' => 'image_resize_dimensions',
      'effect callback' => 'image_scale_and_crop_effect',
      'form callback' => 'image_resize_form',
      'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
      'label' => 'Scale and crop',
      'module' => 'image',
      'name' => 'image_scale_and_crop',
      'summary theme' => 'image_resize_summary',
      'weight' => 1,
    );
  }

  if (!isset($data['media_gallery']['storage']) || $data['media_gallery']['storage'] == IMAGE_STORAGE_DEFAULT) {
    unset($data['media_gallery']['effects'][0]['name']);
  }

  if (!isset($data['media_gallery']['storage']) || $data['media_gallery']['storage'] == IMAGE_STORAGE_DEFAULT) {
    unset($data['media_gallery']['effects'][0]['weight']);
  }
  }
}

/**
 * Implements hook_strongarm_alter().
 */
function nc_media_gallery_strongarm_alter(&$data) {
  if (isset($data['node_preview_media_gallery'])) {
    $data['node_preview_media_gallery']->value = 0; /* WAS: 1 */
  }
}

/**
 * Implements hook_views_default_views_alter().
 */
function nc_media_gallery_views_default_views_alter(&$data) {
  if (isset($data['media_gallery'])) {
    $data['media_gallery']->display['block_2']->display_options['arguments'] = array(
      'name' => array(
        'id' => 'name',
        'table' => 'taxonomy_term_data',
        'field' => 'name',
        'relationship' => 'field_card_keywords_tid',
        'default_action' => 'default',
        'default_argument_type' => 'fixed',
        'default_argument_options' => array(
          'argument' => 'Video',
        ),
        'summary' => array(
          'number_of_records' => 0,
          'format' => 'default_summary',
        ),
        'summary_options' => array(
          'items_per_page' => 25,
        ),
        'limit' => 0,
      ),
    ); /* WAS: '' */
    $data['media_gallery']->display['block_2']->display_options['defaults']['arguments'] = FALSE; /* WAS: '' */
    $data['media_gallery']->display['default']->display_options['arguments'] = array(
      'name' => array(
        'id' => 'name',
        'table' => 'taxonomy_term_data',
        'field' => 'name',
        'relationship' => 'field_card_keywords_tid',
        'default_action' => 'default',
        'default_argument_type' => 'fixed',
        'default_argument_options' => array(
          'argument' => 'Photo Gallery',
        ),
        'summary' => array(
          'number_of_records' => 0,
          'format' => 'default_summary',
        ),
        'summary_options' => array(
          'items_per_page' => 25,
        ),
        'limit' => 0,
      ),
    ); /* WAS: '' */
    $data['media_gallery']->display['default']->display_options['relationships'] = array(
      'field_card_keywords_tid' => array(
        'id' => 'field_card_keywords_tid',
        'table' => 'field_data_field_card_keywords',
        'field' => 'field_card_keywords_tid',
        'required' => TRUE,
      ),
    ); /* WAS: '' */
    $data['media_gallery']->display['page_1']->display_options['arguments'] = array(
      'name' => array(
        'id' => 'name',
        'table' => 'taxonomy_term_data',
        'field' => 'name',
        'relationship' => 'field_card_keywords_tid',
        'default_action' => 'default',
        'default_argument_type' => 'fixed',
        'default_argument_options' => array(
          'argument' => 'Video',
        ),
        'summary' => array(
          'number_of_records' => 0,
          'format' => 'default_summary',
        ),
        'summary_options' => array(
          'items_per_page' => 25,
        ),
        'limit' => 0,
      ),
    ); /* WAS: '' */
    $data['media_gallery']->display['page_1']->display_options['defaults']['arguments'] = FALSE; /* WAS: '' */
    unset($data['media_gallery']->display['block_2']->display_options['filters']['field_card_keywords_tid']);
    unset($data['media_gallery']->display['default']->display_options['filters']['field_card_keywords_tid']);
    unset($data['media_gallery']->display['page_1']->display_options['filters']['field_card_keywords_tid']);
  }
  if (isset($data['media_gallery_list'])) {
    $data['media_gallery_list']->display['block_1']->display_options['arguments']['nid']['group_type'] = 'stddev_pop'; /* WAS: '' */
    $data['media_gallery_list']->display['block_1']->display_options['arguments']['null']['group_type'] = 'stddev_pop'; /* WAS: '' */
    $data['media_gallery_list']->display['block_1']->display_options['defaults']['group_by'] = FALSE; /* WAS: '' */
    $data['media_gallery_list']->display['block_1']->display_options['defaults']['relationships'] = FALSE; /* WAS: '' */
    $data['media_gallery_list']->display['block_1']->display_options['fields']['entity_id_1']['group_column'] = 'entity_id'; /* WAS: '' */
    $data['media_gallery_list']->display['block_1']->display_options['fields']['entity_id_1']['group_type'] = 'stddev_pop'; /* WAS: '' */
    $data['media_gallery_list']->display['block_1']->display_options['fields']['language'] = array(
      'id' => 'language',
      'table' => 'node',
      'field' => 'language',
    ); /* WAS: '' */
    $data['media_gallery_list']->display['block_1']->display_options['fields']['nid'] = array(
      'id' => 'nid',
      'table' => 'node',
      'field' => 'nid',
      'group_type' => 'count_distinct',
    ); /* WAS: '' */
    $data['media_gallery_list']->display['block_1']->display_options['relationships'] = array(
      'reverse_field_media_gallery_media_node' => array(
        'id' => 'reverse_field_media_gallery_media_node',
        'table' => 'node',
        'field' => 'reverse_field_media_gallery_media_node',
        'required' => TRUE,
      ),
    ); /* WAS: '' */
    $data['media_gallery_list']->display['block_1']->display_options['row_options'] = array(
      'links' => FALSE,
    ); /* WAS: '' */
    $data['media_gallery_list']->display['block_1']->display_options['row_plugin'] = 'node'; /* WAS: 'fields' */
    $data['media_gallery_list']->display['block_1']->display_options['style_options'] = array(
      'class' => 'media-grid',
      'wrapper_class' => 'wrapper group',
    ); /* WAS: '' */
    $data['media_gallery_list']->display['block_1']->display_options['style_plugin'] = 'list'; /* WAS: 'default' */
    $data['media_gallery_list']->display['block_2']->display_options['defaults']['relationships'] = FALSE; /* WAS: '' */
    $data['media_gallery_list']->display['block_2']->display_options['fields']['body'] = array(
      'id' => 'body',
      'table' => 'field_data_body',
      'field' => 'body',
      'label' => '',
      'exclude' => TRUE,
      'alter' => array(
        'alter_text' => TRUE,
        'text' => '[body]
                                                <div><a href="[uri]" download="[title]" title="[title]">Download Original</a></div>',
      ),
      'element_label_colon' => FALSE,
      'settings' => array(
        'style_settings' => array(
          'title' => array(
            'element' => 'div',
            'class' => 'field-label',
            'suffix' => ':',
          ),
          'content' => array(
            'element' => 'div',
            'class' => 'field-items',
          ),
          'item' => array(
            'element' => 'div',
            'class' => 'field-item',
          ),
          'wrapper' => array(
            'element' => 'div',
            'class' => '',
          ),
          'default_classes' => 1,
          'prefix_markup' => '',
          'item_limit' => '',
        ),
        'field_formatter_class' => '',
      ),
    ); /* WAS: '' */
    $data['media_gallery_list']->display['block_2']->display_options['fields']['colorbox'] = array(
      'id' => 'colorbox',
      'table' => 'colorbox',
      'field' => 'colorbox',
      'label' => '',
      'element_label_colon' => FALSE,
      'trigger_field' => 'entity_id_1',
      'popup' => '[field_photo_image] ',
      'caption' => '[body]',
      'gid' => 1,
      'width' => '640px',
      'height' => '480px',
    ); /* WAS: '' */
    $data['media_gallery_list']->display['block_2']->display_options['fields']['entity_id_1']['click_sort_column'] = 'fid'; /* WAS: '' */
    $data['media_gallery_list']->display['block_2']->display_options['fields']['entity_id_1']['element_label_colon'] = FALSE; /* WAS: '' */
    $data['media_gallery_list']->display['block_2']->display_options['fields']['entity_id_1']['exclude'] = TRUE; /* WAS: '' */
    $data['media_gallery_list']->display['block_2']->display_options['fields']['entity_id_1']['label'] = '480x480 image'; /* WAS: '' */
    $data['media_gallery_list']->display['block_2']->display_options['fields']['entity_id_1']['settings'] = array(
      'image_style' => 'large',
      'image_link' => '',
      'style_settings' => array(
        'title' => array(
          'element' => 'div',
          'class' => 'field-label',
          'suffix' => ':',
        ),
        'content' => array(
          'element' => 'div',
          'class' => 'field-items',
        ),
        'item' => array(
          'element' => 'div',
          'class' => 'field-item',
        ),
        'wrapper' => array(
          'element' => 'div',
          'class' => '',
        ),
        'default_classes' => 1,
        'prefix_markup' => '',
        'item_limit' => '',
      ),
      'field_formatter_class' => '',
    ); /* WAS: '' */
    $data['media_gallery_list']->display['block_2']->display_options['fields']['field_photo_image'] = array(
      'id' => 'field_photo_image',
      'table' => 'field_data_field_photo_image',
      'field' => 'field_photo_image',
      'label' => '800x600 image',
      'exclude' => TRUE,
      'element_default_classes' => FALSE,
      'click_sort_column' => 'fid',
      'settings' => array(
        'image_style' => 'media_gallery_colorbox',
        'image_link' => '',
        'style_settings' => array(
          'title' => array(
            'element' => '',
            'class' => 'field-label',
            'suffix' => ':',
          ),
          'content' => array(
            'element' => '',
            'class' => 'field-items',
          ),
          'item' => array(
            'element' => '',
            'class' => 'field-item',
          ),
          'wrapper' => array(
            'element' => '',
            'class' => '',
          ),
          'default_classes' => 1,
          'prefix_markup' => '',
          'item_limit' => '',
        ),
        'field_formatter_class' => '',
      ),
    ); /* WAS: '' */
    $data['media_gallery_list']->display['block_2']->display_options['fields']['title'] = array(
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'exclude' => TRUE,
      'alter' => array(
        'strip_tags' => TRUE,
      ),
      'link_to_node' => FALSE,
    ); /* WAS: '' */
    $data['media_gallery_list']->display['block_2']->display_options['fields']['uri'] = array(
      'id' => 'uri',
      'table' => 'file_managed',
      'field' => 'uri',
      'relationship' => 'node_to_file',
      'exclude' => TRUE,
      'file_download_path' => TRUE,
    ); /* WAS: '' */
    $data['media_gallery_list']->display['block_2']->display_options['relationships'] = array(
      'node_to_file' => array(
        'id' => 'node_to_file',
        'table' => 'file_usage',
        'field' => 'node_to_file',
        'required' => TRUE,
      ),
    ); /* WAS: '' */
    $data['media_gallery_list']->display['block_2']->display_options['row_options']['default_field_elements'] = FALSE; /* WAS: '' */
    $data['media_gallery_list']->display['block_2']->display_options['row_plugin'] = 'fields'; /* WAS: 'node' */
    $data['media_gallery_list']->display['block_2']->display_options['style_options']['class'] = 'media-grid'; /* WAS: '' */
    $data['media_gallery_list']->display['block_2']->display_options['style_options']['default_row_class'] = FALSE; /* WAS: '' */
    $data['media_gallery_list']->display['block_2']->display_options['style_options']['row_class_special'] = FALSE; /* WAS: '' */
    $data['media_gallery_list']->display['block_2']->display_options['style_options']['wrapper_class'] = 'wrapper group'; /* WAS: '' */
    $data['media_gallery_list']->display['block_2']->display_options['style_plugin'] = 'list'; /* WAS: 'grid' */
    $data['media_gallery_list']->display['default']->display_options['filters']['status'] = array(
      'id' => 'status',
      'table' => 'node',
      'field' => 'status',
      'value' => 1,
    ); /* WAS: '' */
    $data['media_gallery_list']->display['default']->display_options['pager']['options']['items_per_page'] = 8; /* WAS: 6 */
    $data['media_gallery_list']->display['default']->display_options['title'] = 'Media Gallery'; /* WAS: 'Multimedia' */
    $data['media_gallery_list']->display['page_1']->display_options['defaults']['css_class'] = FALSE; /* WAS: '' */
    $data['media_gallery_list']->display['page_1']->display_options['defaults']['row_options'] = FALSE; /* WAS: '' */
    $data['media_gallery_list']->display['page_1']->display_options['defaults']['row_plugin'] = FALSE; /* WAS: '' */
    $data['media_gallery_list']->display['page_1']->display_options['defaults']['style_options'] = FALSE; /* WAS: '' */
    $data['media_gallery_list']->display['page_1']->display_options['defaults']['style_plugin'] = FALSE; /* WAS: '' */
    $data['media_gallery_list']->display['page_1']->display_options['defaults']['title'] = FALSE; /* WAS: '' */
    $data['media_gallery_list']->display['page_1']->display_options['display_description'] = 'Grid page containing galleries.'; /* WAS: '' */
    /*$data['media_gallery_list']->display['page_1']->display_options['menu'] = array(
      'type' => 'normal',
      'title' => 'Media Gallery',
      'name' => 'main-menu',
      'context' => 0,
      'context_only_inline' => 0,
    );*/ /* WAS: '' */
    $data['media_gallery_list']->display['page_1']->display_options['path'] = 'media-gallery'; /* WAS: 'multimedia' */
    $data['media_gallery_list']->display['page_1']->display_options['row_options'] = array(
      'links' => FALSE,
    ); /* WAS: '' */
    $data['media_gallery_list']->display['page_1']->display_options['row_plugin'] = 'node'; /* WAS: '' */
    $data['media_gallery_list']->display['page_1']->display_options['style_options'] = array(
      'default_row_class' => FALSE,
      'row_class_special' => FALSE,
      'class' => 'media-grid',
      'wrapper_class' => 'wrapper group',
    ); /* WAS: '' */
    $data['media_gallery_list']->display['page_1']->display_options['style_plugin'] = 'list'; /* WAS: '' */
    $data['media_gallery_list']->display['page_1']->display_options['title'] = 'Media Gallery'; /* WAS: '' */
    $data['media_gallery_list']->display['page_1']->display_title = 'Media Gallery Page'; /* WAS: 'Multimedia' */
    unset($data['media_gallery_list']->display['block_2']->display_options['fields']['entity_id']);
    unset($data['media_gallery_list']->display['block_2']->display_options['row_options']['links']);
    unset($data['media_gallery_list']->display['block_2']->display_options['style_options']['columns']);
  }
}

/**
 * Implements hook_image_default_styles().
 */
function nc_media_gallery_image_default_styles() {
  $styles = array();

  // Exported image style: media_gallery_colorbox.
  $styles['media_gallery_colorbox'] = array(
    'name' => 'media_gallery_colorbox',
    'label' => 'media_gallery_colorbox',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 800,
          'height' => 600,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
