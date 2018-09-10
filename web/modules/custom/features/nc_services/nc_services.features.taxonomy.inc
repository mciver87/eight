<?php
/**
 * @file
 * nc_services.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function nc_services_taxonomy_default_vocabularies() {
  return array(
    'service_category' => array(
      'name' => 'Service category',
      'machine_name' => 'service_category',
      'description' => '',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
      'microdata' => array(
        '#attributes' => array(
          'itemscope' => '',
        ),
      ),
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
