<?php
/**
 * @file
 * nc_search.elasticsearch_connector_defaults.inc
 */

/**
 * Implements hook_default_elasticsearch_connector_cluster().
 */
function nc_search_default_elasticsearch_connector_cluster() {
  $export = array();
  $cluster_name = 'nc_cluster';
  $elasticsearch_connector_cluster = new stdClass();
  $elasticsearch_connector_cluster->disabled = FALSE;
  $elasticsearch_connector_cluster->api_version = 1;
  $elasticsearch_connector_cluster->cluster_id = $cluster_name;
  $elasticsearch_connector_cluster->name = 'NC Cluster';
  global $os_env;
  if ($os_env != 'prod') {
    $elasticsearch_connector_cluster->url = 'https://vpc-nonprod-es-001-o5dnft3dsa2qwowbql2hlbiaka.us-east-1.es.amazonaws.com:443';
  }
  else {
    $elasticsearch_connector_cluster->url = 'https://vpc-prod-es-001-5nrxwbo3zlfhcatmz2jbuay2j4.us-east-1.es.amazonaws.com:443';
  }
  $elasticsearch_connector_cluster->status = 0;
  $elasticsearch_connector_cluster->options = array(
    'multiple_nodes_connection' => 0,
    'use_authentication' => 0,
    'timeout' => '150',
  );
  $export[$cluster_name] = $elasticsearch_connector_cluster;

  return $export;
}
