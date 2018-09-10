<?php
/**
 * @file
 * openpublic_agency.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function openpublic_agency_taxonomy_default_vocabularies() {
  return array(
    'agency_category' => array(
      'name' => 'Agency category',
      'machine_name' => 'agency_category',
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
