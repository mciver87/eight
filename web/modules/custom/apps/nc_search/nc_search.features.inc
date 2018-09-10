<?php
/**
 * @file
 * nc_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nc_search_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "elasticsearch_connector" && $api == "elasticsearch_connector_defaults") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_search_api_index().
 */
function nc_search_default_search_api_index() {
  global $shortcode;
  global $os_env;
  $index_name = $os_env . '_' . $shortcode;

  $items = array();
  $items[$index_name] = entity_import('search_api_index', '{
    "name" : "' . $index_name . '",
    "machine_name" : "' . $index_name . '",
    "description" : null,
    "server" : "nc_elasticsearch",
    "item_type" : "node",
    "options" : {
      "index_directly" : 0,
      "cron_limit" : "50",
      "index_name" : { "index" : "' . $index_name . '", "cluster_id" : "" },
      "collect_index_statistics" : 0,
      "log_only_not_found" : 0,
      "index_statistics_ttl" : "365d",
      "number_of_shards" : "5",
      "number_of_replicas" : "1",
      "fields" : {
        "body:summary" : { "type" : "text" },
        "body:value" : { "type" : "text" },
        "changed" : { "type" : "date" },
        "created" : { "type" : "date" },
        "field_agency_department" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_author" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_bands:field_full_width_markup:value" : { "type" : "list\\u003Ctext\\u003E" },
        "field_bands:field_left_middle_markup" : { "type" : "list\\u003Ctext\\u003E" },
        "field_bands:field_left_middle_title" : { "type" : "list\\u003Ctext\\u003E" },
        "field_bands:field_left_title" : { "type" : "list\\u003Ctext\\u003E" },
        "field_bands:field_middle_markup:value" : { "type" : "list\\u003Ctext\\u003E" },
        "field_bands:field_middle_title" : { "type" : "list\\u003Ctext\\u003E" },
        "field_bands:field_name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_bands:field_right_middle_markup" : { "type" : "list\\u003Ctext\\u003E" },
        "field_bands:field_right_middle_title" : { "type" : "list\\u003Ctext\\u003E" },
        "field_bands:field_right_title" : { "type" : "list\\u003Ctext\\u003E" },
        "field_blog_terms" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_city_location" : { "type" : "text" },
        "field_cost" : { "type" : "text" },
        "field_document_attachment:description" : { "type" : "list\\u003Ctext\\u003E" },
        "field_document_author" : { "type" : "text" },
        "field_document_type" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_event_terms" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_event_type" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_key_search_topics" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_key_search_topics:name" : { "type" : "list\\u003Ctext\\u003E", "boost" : "21.0" },
        "field_official_title" : { "type" : "text" },
        "field_organizer" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_press_release_terms" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_profile_address" : { "type" : "text" },
        "field_profile_department" : { "type" : "text" },
        "field_profile_division" : { "type" : "text" },
        "field_profile_first_name" : { "type" : "text" },
        "field_profile_job_title" : { "type" : "text" },
        "field_profile_last_name" : { "type" : "text" },
        "field_profile_organization" : { "type" : "text" },
        "field_profile_phone" : { "type" : "text" },
        "field_published_date" : { "type" : "date" },
        "field_release_date" : { "type" : "date" },
        "field_virtual_location" : { "type" : "text" },
        "language" : { "type" : "string" },
        "nid" : { "type" : "integer" },
        "search_api_language" : { "type" : "string" },
        "search_api_site_hash" : { "type" : "uri" },
        "search_api_viewed" : { "type" : "text" },
        "status" : { "type" : "integer" },
        "title" : { "type" : "text", "boost" : "5.0" },
        "type" : { "type" : "string" },
        "url" : { "type" : "uri" }
      },
      "data_alter_callbacks" : {
        "site_index" : { "status" : 1, "weight" : "-50", "settings" : [] },
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : { "photo" : "photo" } }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_language_control" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "search_api_alter_node_status" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_add_viewed_entity" : { "status" : 1, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_metatag_alter_callback" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "-50",
          "settings" : { "fields" : {
              "type" : true,
              "language" : true,
              "url" : true,
              "field_key_search_topics" : true,
              "field_agency_department" : true,
              "field_document_author" : true,
              "field_document_type" : true,
              "field_official_title" : true,
              "field_published_date" : true,
              "field_cost" : true,
              "field_event_terms" : true,
              "field_event_type" : true,
              "field_organizer" : true,
              "field_virtual_location" : true,
              "field_city_location" : true,
              "field_press_release_terms" : true,
              "field_profile_address" : true,
              "field_profile_department" : true,
              "field_profile_division" : true,
              "field_profile_first_name" : true,
              "field_profile_job_title" : true,
              "field_profile_last_name" : true,
              "field_profile_organization" : true,
              "field_profile_phone" : true,
              "field_blog_terms" : true,
              "field_author" : true,
              "search_api_language" : true,
              "body:value" : true,
              "body:summary" : true,
              "field_key_search_topics:name" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "-49",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_official_title" : true,
              "search_api_viewed" : true,
              "body:value" : true,
              "body:summary" : true,
              "field_bands:field_name" : true,
              "field_bands:field_left_middle_markup" : true,
              "field_bands:field_left_middle_title" : true,
              "field_bands:field_left_title" : true,
              "field_bands:field_right_middle_markup" : true,
              "field_bands:field_right_middle_title" : true,
              "field_bands:field_right_title" : true,
              "field_bands:field_middle_title" : true,
              "field_bands:field_full_width_markup:value" : true,
              "field_bands:field_middle_markup:value" : true
            },
            "title" : 0,
            "alt" : 0,
            "tags" : ""
          }
        },
        "search_api_elasticsearch_highlighting" : {
          "status" : 1,
          "weight" : "-48",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "128",
            "excerpt_fragments" : "1",
            "concatenator" : "...",
            "highlight" : "server"
          }
        },
        "search_api_transliteration" : {
          "status" : 0,
          "weight" : "-47",
          "settings" : { "fields" : {
              "title" : true,
              "field_document_author" : true,
              "field_official_title" : true,
              "field_cost" : true,
              "field_virtual_location" : true,
              "field_city_location" : true,
              "field_profile_address" : true,
              "field_profile_department" : true,
              "field_profile_division" : true,
              "field_profile_first_name" : true,
              "field_profile_job_title" : true,
              "field_profile_last_name" : true,
              "field_profile_organization" : true,
              "field_profile_phone" : true,
              "body:value" : true,
              "body:summary" : true,
              "field_key_search_topics:name" : true,
              "field_document_attachment:description" : true,
              "field_bands:field_name" : true,
              "field_bands:field_left_middle_markup" : true,
              "field_bands:field_left_middle_title" : true,
              "field_bands:field_left_title" : true,
              "field_bands:field_right_middle_markup" : true,
              "field_bands:field_right_middle_title" : true,
              "field_bands:field_right_title" : true,
              "field_bands:field_middle_title" : true,
              "field_bands:field_full_width_markup:value" : true,
              "field_bands:field_middle_markup:value" : true
            }
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "-46",
          "settings" : {
            "fields" : { "title" : true },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "-45",
          "settings" : {
            "fields" : { "title" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "-44",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "128",
            "exclude_fields" : [],
            "highlight" : "always",
            "highlight_partial" : 0
          }
        },
        "search_api_porter_stemmer" : {
          "status" : 0,
          "weight" : "-43",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_document_author" : true,
              "field_official_title" : true,
              "field_cost" : true,
              "field_virtual_location" : true,
              "field_city_location" : true,
              "field_profile_address" : true,
              "field_profile_department" : true,
              "field_profile_division" : true,
              "field_profile_first_name" : true,
              "field_profile_job_title" : true,
              "field_profile_last_name" : true,
              "field_profile_organization" : true,
              "field_profile_phone" : true,
              "body:value" : true,
              "body:summary" : true,
              "field_key_search_topics:name" : true,
              "field_document_attachment:description" : true,
              "field_bands:field_name" : true,
              "field_bands:field_left_middle_markup" : true,
              "field_bands:field_left_middle_title" : true,
              "field_bands:field_left_title" : true,
              "field_bands:field_right_middle_markup" : true,
              "field_bands:field_right_middle_title" : true,
              "field_bands:field_right_title" : true,
              "field_bands:field_middle_title" : true,
              "field_bands:field_full_width_markup:value" : true,
              "field_bands:field_middle_markup:value" : true
            },
            "exceptions" : "texan=texa"
          }
        },
        "search_api_elasticsearch_prefix_search" : {
          "status" : 1,
          "weight" : "-42",
          "settings" : { "fields" : {
              "title" : true,
              "field_document_author" : true,
              "field_official_title" : true,
              "field_cost" : true,
              "field_virtual_location" : true,
              "field_city_location" : true,
              "field_profile_address" : true,
              "field_profile_department" : true,
              "field_profile_division" : true,
              "field_profile_first_name" : true,
              "field_profile_job_title" : true,
              "field_profile_last_name" : true,
              "field_profile_organization" : true,
              "field_profile_phone" : true,
              "body:value" : true,
              "body:summary" : true,
              "field_key_search_topics:name" : true
            }
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "microdata" : { "#attributes" : { "itemscope" : "" } },
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function nc_search_default_search_api_server() {
  global $os_env;
  $items = array();
  $items['nc_elasticsearch'] = entity_import('search_api_server', '{
    "name" : "NC Cluster",
    "machine_name" : "nc_elasticsearch",
    "description" : "",
    "class" : "search_api_elasticsearch_connector",
    "options" : { "cluster" : "nc_cluster", "facet_limit" : 10 },
    "enabled" : "1",
    "microdata" : { "#attributes" : { "itemscope" : "" } },
    "rdf_mapping" : []
  }');
  return $items;
}
