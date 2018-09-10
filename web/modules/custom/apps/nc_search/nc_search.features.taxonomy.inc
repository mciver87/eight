<?php
/**
 * @file
 * nc_search.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function nc_search_taxonomy_default_vocabularies() {
  return array(
    'key_search_topics' => array(
      'name' => 'Key Search Topics',
      'machine_name' => 'key_search_topics',
      'description' => '',
      'hierarchy' => 0,
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
