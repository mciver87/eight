<?php
/**
 * @file
 * nc_media_gallery.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function nc_media_gallery_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'media_gallery';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'bean';
  $view->human_name = 'External Media Gallery';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Media Gallery';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'media-grid';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Relationship: Block: Category (field_card_keywords) */
  $handler->display->display_options['relationships']['field_card_keywords_tid']['id'] = 'field_card_keywords_tid';
  $handler->display->display_options['relationships']['field_card_keywords_tid']['table'] = 'field_data_field_card_keywords';
  $handler->display->display_options['relationships']['field_card_keywords_tid']['field'] = 'field_card_keywords_tid';
  $handler->display->display_options['relationships']['field_card_keywords_tid']['required'] = TRUE;
  /* Field: Block: Link */
  $handler->display->display_options['fields']['field_card_link']['id'] = 'field_card_link';
  $handler->display->display_options['fields']['field_card_link']['table'] = 'field_data_field_card_link';
  $handler->display->display_options['fields']['field_card_link']['field'] = 'field_card_link';
  $handler->display->display_options['fields']['field_card_link']['label'] = '';
  $handler->display->display_options['fields']['field_card_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_card_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_card_link']['type'] = 'link_absolute';
  $handler->display->display_options['fields']['field_card_link']['settings'] = array(
    'style_settings' => array(
      'title' => array(
        'element' => '',
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
      'default_classes' => 0,
      'prefix_markup' => '',
      'item_limit' => '',
    ),
  );
  /* Field: Block: Image */
  $handler->display->display_options['fields']['field_card_image']['id'] = 'field_card_image';
  $handler->display->display_options['fields']['field_card_image']['table'] = 'field_data_field_card_image';
  $handler->display->display_options['fields']['field_card_image']['field'] = 'field_card_image';
  $handler->display->display_options['fields']['field_card_image']['label'] = '';
  $handler->display->display_options['fields']['field_card_image']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_card_image']['element_type'] = '0';
  $handler->display->display_options['fields']['field_card_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_card_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_card_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_card_image']['settings'] = array(
    'image_style' => 'card_photo',
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
  );
  /* Field: Block: Link */
  $handler->display->display_options['fields']['field_card_link_1']['id'] = 'field_card_link_1';
  $handler->display->display_options['fields']['field_card_link_1']['table'] = 'field_data_field_card_link';
  $handler->display->display_options['fields']['field_card_link_1']['field'] = 'field_card_link';
  $handler->display->display_options['fields']['field_card_link_1']['label'] = '';
  $handler->display->display_options['fields']['field_card_link_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_card_link_1']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_card_link_1']['type'] = 'link_title_plain';
  $handler->display->display_options['fields']['field_card_link_1']['settings'] = array(
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
  );
  /* Field: Block: Description */
  $handler->display->display_options['fields']['field_card_description']['id'] = 'field_card_description';
  $handler->display->display_options['fields']['field_card_description']['table'] = 'field_data_field_card_description';
  $handler->display->display_options['fields']['field_card_description']['field'] = 'field_card_description';
  $handler->display->display_options['fields']['field_card_description']['label'] = '';
  $handler->display->display_options['fields']['field_card_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_card_description']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_card_description']['settings'] = array(
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
  );
  /* Contextual filter: Taxonomy term: Name */
  $handler->display->display_options['arguments']['name']['id'] = 'name';
  $handler->display->display_options['arguments']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['name']['field'] = 'name';
  $handler->display->display_options['arguments']['name']['relationship'] = 'field_card_keywords_tid';
  $handler->display->display_options['arguments']['name']['default_action'] = 'default';
  $handler->display->display_options['arguments']['name']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['name']['default_argument_options']['argument'] = 'Photo Gallery';
  $handler->display->display_options['arguments']['name']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['name']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['name']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['name']['limit'] = '0';
  /* Filter criterion: Block: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'bean';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'nc_card_article' => 'nc_card_article',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '16';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['path'] = 'photo-gallery';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '16';
  $handler->display->display_options['pager']['options']['offset'] = '0';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Videos';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '16';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Taxonomy term: Name */
  $handler->display->display_options['arguments']['name']['id'] = 'name';
  $handler->display->display_options['arguments']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['name']['field'] = 'name';
  $handler->display->display_options['arguments']['name']['relationship'] = 'field_card_keywords_tid';
  $handler->display->display_options['arguments']['name']['default_action'] = 'default';
  $handler->display->display_options['arguments']['name']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['name']['default_argument_options']['argument'] = 'Video';
  $handler->display->display_options['arguments']['name']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['name']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['name']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['name']['limit'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Block: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'bean';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'nc_card_article' => 'nc_card_article',
  );
  $handler->display->display_options['path'] = 'video-gallery';

  /* Display: Video block */
  $handler = $view->new_display('block', 'Video block', 'block_2');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '8';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Taxonomy term: Name */
  $handler->display->display_options['arguments']['name']['id'] = 'name';
  $handler->display->display_options['arguments']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['name']['field'] = 'name';
  $handler->display->display_options['arguments']['name']['relationship'] = 'field_card_keywords_tid';
  $handler->display->display_options['arguments']['name']['default_action'] = 'default';
  $handler->display->display_options['arguments']['name']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['name']['default_argument_options']['argument'] = 'Video';
  $handler->display->display_options['arguments']['name']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['name']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['name']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['name']['limit'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Block: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'bean';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'nc_card_article' => 'nc_card_article',
  );
  $translatables['media_gallery'] = array(
    t('Master'),
    t('Media Gallery'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('term from field_card_keywords'),
    t('All'),
    t('Page'),
    t('Block'),
    t('Videos'),
    t('Video block'),
  );
  $export['media_gallery'] = $view;

  return $export;
}
