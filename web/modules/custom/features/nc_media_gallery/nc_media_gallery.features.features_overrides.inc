<?php
/**
 * @file
 * nc_media_gallery.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function nc_media_gallery_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: field_instance
  $overrides["field_instance.node-media_gallery-body.display|basic_card"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-media_gallery-body.display|block_feature"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-media_gallery-body.display|default|settings|field_formatter_class"] = '';
  $overrides["field_instance.node-media_gallery-body.display|default|settings|style_settings"] = array(
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
  );
  $overrides["field_instance.node-media_gallery-field_media_gallery_media.display|basic_card"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-media_gallery-field_media_gallery_media.display|block_feature"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-media_gallery-field_media_gallery_media.display|default|settings|field_formatter_class"] = '';
  $overrides["field_instance.node-media_gallery-field_media_gallery_media.display|default|settings|style_settings"] = array(
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
  );
  $overrides["field_instance.node-media_gallery-field_media_gallery_media.display|teaser|module"] = 'node_reference';
  $overrides["field_instance.node-media_gallery-field_media_gallery_media.display|teaser|settings|field_formatter_class"] = '';
  $overrides["field_instance.node-media_gallery-field_media_gallery_media.display|teaser|settings|node_reference_view_mode"] = 'full';
  $overrides["field_instance.node-media_gallery-field_media_gallery_media.display|teaser|settings|style_settings"] = array(
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
  );
  $overrides["field_instance.node-media_gallery-field_media_gallery_media.display|teaser|settings|view"]["DELETED"] = TRUE;
  $overrides["field_instance.node-media_gallery-field_media_gallery_media.display|teaser|type"] = 'node_reference_node';
  $overrides["field_instance.node-photo-body.display|basic_card"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-photo-body.display|block_feature"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-photo-body.display|default|settings|field_formatter_class"] = '';
  $overrides["field_instance.node-photo-body.display|default|settings|style_settings"] = array(
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
  );
  $overrides["field_instance.node-photo-body.display|teaser|module"]["DELETED"] = TRUE;
  $overrides["field_instance.node-photo-body.display|teaser|settings|trim_length"]["DELETED"] = TRUE;
  $overrides["field_instance.node-photo-body.display|teaser|type"] = 'hidden';
  $overrides["field_instance.node-photo-field_photo_image.display|basic_card"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-photo-field_photo_image.display|block_feature"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field_instance.node-photo-field_photo_image.display|default|settings|field_formatter_class"] = '';
  $overrides["field_instance.node-photo-field_photo_image.display|default|settings|style_settings"] = array(
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
  );
  $overrides["field_instance.node-photo-field_photo_image.display|editors_choice|settings|field_formatter_class"] = '';
  $overrides["field_instance.node-photo-field_photo_image.display|editors_choice|settings|style_settings"] = array(
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
  );
  $overrides["field_instance.node-photo-field_photo_image.display|teaser|settings|field_formatter_class"] = '';
  $overrides["field_instance.node-photo-field_photo_image.display|teaser|settings|image_link"] = '';
  $overrides["field_instance.node-photo-field_photo_image.display|teaser|settings|image_style"] = '';
  $overrides["field_instance.node-photo-field_photo_image.display|teaser|settings|style_settings"] = array(
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
  );
  $overrides["field_instance.node-photo-field_photo_image.widget|settings|filefield_sources"] = array(
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
  );

  // Exported overrides for: image
  $overrides["image.media_gallery.effects|0|data|height"] = 480;
  $overrides["image.media_gallery.effects|0|data|width"] = 480;
  $overrides["image.media_gallery.effects|0|name"]["DELETED"] = TRUE;
  $overrides["image.media_gallery.effects|0|weight"]["DELETED"] = TRUE;
  $overrides["image.media_gallery.effects|1"] = array(
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

  // Exported overrides for: variable
  $overrides["variable.node_preview_media_gallery.value"] = 0;

  // Exported overrides for: views_view
  $overrides["views_view.media_gallery.display|block_2|display_options|arguments"] = array(
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
  );
  $overrides["views_view.media_gallery.display|block_2|display_options|defaults|arguments"] = FALSE;
  $overrides["views_view.media_gallery.display|block_2|display_options|filters|field_card_keywords_tid"]["DELETED"] = TRUE;
  $overrides["views_view.media_gallery.display|default|display_options|arguments"] = array(
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
  );
  $overrides["views_view.media_gallery.display|default|display_options|filters|field_card_keywords_tid"]["DELETED"] = TRUE;
  $overrides["views_view.media_gallery.display|default|display_options|relationships"] = array(
    'field_card_keywords_tid' => array(
      'id' => 'field_card_keywords_tid',
      'table' => 'field_data_field_card_keywords',
      'field' => 'field_card_keywords_tid',
      'required' => TRUE,
    ),
  );
  $overrides["views_view.media_gallery.display|page_1|display_options|arguments"] = array(
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
  );
  $overrides["views_view.media_gallery.display|page_1|display_options|defaults|arguments"] = FALSE;
  $overrides["views_view.media_gallery.display|page_1|display_options|filters|field_card_keywords_tid"]["DELETED"] = TRUE;
  $overrides["views_view.media_gallery_list.display|block_1|display_options|arguments|nid|group_type"] = 'stddev_pop';
  $overrides["views_view.media_gallery_list.display|block_1|display_options|arguments|null|group_type"] = 'stddev_pop';
  $overrides["views_view.media_gallery_list.display|block_1|display_options|defaults|group_by"] = FALSE;
  $overrides["views_view.media_gallery_list.display|block_1|display_options|defaults|relationships"] = FALSE;
  $overrides["views_view.media_gallery_list.display|block_1|display_options|fields|entity_id_1|group_column"] = 'entity_id';
  $overrides["views_view.media_gallery_list.display|block_1|display_options|fields|entity_id_1|group_type"] = 'stddev_pop';
  $overrides["views_view.media_gallery_list.display|block_1|display_options|fields|language"] = array(
    'id' => 'language',
    'table' => 'node',
    'field' => 'language',
  );
  $overrides["views_view.media_gallery_list.display|block_1|display_options|fields|nid"] = array(
    'id' => 'nid',
    'table' => 'node',
    'field' => 'nid',
    'group_type' => 'count_distinct',
  );
  $overrides["views_view.media_gallery_list.display|block_1|display_options|relationships"] = array(
    'reverse_field_media_gallery_media_node' => array(
      'id' => 'reverse_field_media_gallery_media_node',
      'table' => 'node',
      'field' => 'reverse_field_media_gallery_media_node',
      'required' => TRUE,
    ),
  );
  $overrides["views_view.media_gallery_list.display|block_1|display_options|row_options"] = array(
    'links' => FALSE,
  );
  $overrides["views_view.media_gallery_list.display|block_1|display_options|row_plugin"] = 'node';
  $overrides["views_view.media_gallery_list.display|block_1|display_options|style_options"] = array(
    'class' => 'media-grid',
    'wrapper_class' => 'wrapper group',
  );
  $overrides["views_view.media_gallery_list.display|block_1|display_options|style_plugin"] = 'list';
  $overrides["views_view.media_gallery_list.display|block_2|display_options|defaults|relationships"] = FALSE;
  $overrides["views_view.media_gallery_list.display|block_2|display_options|fields|body"] = array(
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
  );
  $overrides["views_view.media_gallery_list.display|block_2|display_options|fields|colorbox"] = array(
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
  );
  $overrides["views_view.media_gallery_list.display|block_2|display_options|fields|entity_id"]["DELETED"] = TRUE;
  $overrides["views_view.media_gallery_list.display|block_2|display_options|fields|entity_id_1|click_sort_column"] = 'fid';
  $overrides["views_view.media_gallery_list.display|block_2|display_options|fields|entity_id_1|element_label_colon"] = FALSE;
  $overrides["views_view.media_gallery_list.display|block_2|display_options|fields|entity_id_1|exclude"] = TRUE;
  $overrides["views_view.media_gallery_list.display|block_2|display_options|fields|entity_id_1|label"] = '480x480 image';
  $overrides["views_view.media_gallery_list.display|block_2|display_options|fields|entity_id_1|settings"] = array(
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
  );
  $overrides["views_view.media_gallery_list.display|block_2|display_options|fields|field_photo_image"] = array(
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
  );
  $overrides["views_view.media_gallery_list.display|block_2|display_options|fields|title"] = array(
    'id' => 'title',
    'table' => 'node',
    'field' => 'title',
    'exclude' => TRUE,
    'alter' => array(
      'strip_tags' => TRUE,
    ),
    'link_to_node' => FALSE,
  );
  $overrides["views_view.media_gallery_list.display|block_2|display_options|fields|uri"] = array(
    'id' => 'uri',
    'table' => 'file_managed',
    'field' => 'uri',
    'relationship' => 'node_to_file',
    'exclude' => TRUE,
    'file_download_path' => TRUE,
  );
  $overrides["views_view.media_gallery_list.display|block_2|display_options|relationships"] = array(
    'node_to_file' => array(
      'id' => 'node_to_file',
      'table' => 'file_usage',
      'field' => 'node_to_file',
      'required' => TRUE,
    ),
  );
  $overrides["views_view.media_gallery_list.display|block_2|display_options|row_options|default_field_elements"] = FALSE;
  $overrides["views_view.media_gallery_list.display|block_2|display_options|row_options|links"]["DELETED"] = TRUE;
  $overrides["views_view.media_gallery_list.display|block_2|display_options|row_plugin"] = 'fields';
  $overrides["views_view.media_gallery_list.display|block_2|display_options|style_options|class"] = 'media-grid';
  $overrides["views_view.media_gallery_list.display|block_2|display_options|style_options|columns"]["DELETED"] = TRUE;
  $overrides["views_view.media_gallery_list.display|block_2|display_options|style_options|default_row_class"] = FALSE;
  $overrides["views_view.media_gallery_list.display|block_2|display_options|style_options|row_class_special"] = FALSE;
  $overrides["views_view.media_gallery_list.display|block_2|display_options|style_options|wrapper_class"] = 'wrapper group';
  $overrides["views_view.media_gallery_list.display|block_2|display_options|style_plugin"] = 'list';
  $overrides["views_view.media_gallery_list.display|default|display_options|filters|status"] = array(
    'id' => 'status',
    'table' => 'node',
    'field' => 'status',
    'value' => 1,
  );
  $overrides["views_view.media_gallery_list.display|default|display_options|pager|options|items_per_page"] = 8;
  $overrides["views_view.media_gallery_list.display|default|display_options|title"] = 'Media Gallery';
  $overrides["views_view.media_gallery_list.display|page_1|display_options|defaults|css_class"] = FALSE;
  $overrides["views_view.media_gallery_list.display|page_1|display_options|defaults|row_options"] = FALSE;
  $overrides["views_view.media_gallery_list.display|page_1|display_options|defaults|row_plugin"] = FALSE;
  $overrides["views_view.media_gallery_list.display|page_1|display_options|defaults|style_options"] = FALSE;
  $overrides["views_view.media_gallery_list.display|page_1|display_options|defaults|style_plugin"] = FALSE;
  $overrides["views_view.media_gallery_list.display|page_1|display_options|defaults|title"] = FALSE;
  $overrides["views_view.media_gallery_list.display|page_1|display_options|display_description"] = 'Grid page containing galleries.';
  /*$overrides["views_view.media_gallery_list.display|page_1|display_options|menu"] = array(
    'type' => 'normal',
    'title' => 'Media Gallery',
    'name' => 'main-menu',
    'context' => 0,
    'context_only_inline' => 0,
  );*/
  $overrides["views_view.media_gallery_list.display|page_1|display_options|path"] = 'media-gallery';
  $overrides["views_view.media_gallery_list.display|page_1|display_options|row_options"] = array(
    'links' => FALSE,
  );
  $overrides["views_view.media_gallery_list.display|page_1|display_options|row_plugin"] = 'node';
  $overrides["views_view.media_gallery_list.display|page_1|display_options|style_options"] = array(
    'default_row_class' => FALSE,
    'row_class_special' => FALSE,
    'class' => 'media-grid',
    'wrapper_class' => 'wrapper group',
  );
  $overrides["views_view.media_gallery_list.display|page_1|display_options|style_plugin"] = 'list';
  $overrides["views_view.media_gallery_list.display|page_1|display_options|title"] = 'Media Gallery';
  $overrides["views_view.media_gallery_list.display|page_1|display_title"] = 'Media Gallery Page';

 return $overrides;
}
