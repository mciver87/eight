<?php
/**
 * @file
 * nc_taxonomy.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function nc_taxonomy_taxonomy_default_vocabularies() {
  return array(
    'blog_category' => array(
      'name' => 'Blog Category',
      'machine_name' => 'blog_category',
      'description' => 'Categories for collecting blog posts',
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
    'document_collection' => array(
      'name' => 'Document Collection',
      'machine_name' => 'document_collection',
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
    'event_organizer' => array(
      'name' => 'Event Organizer',
      'machine_name' => 'event_organizer',
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
    'event_terms' => array(
      'name' => 'Event Terms',
      'machine_name' => 'event_terms',
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
    'event_type' => array(
      'name' => 'Event Type',
      'machine_name' => 'event_type',
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
    'nc_agency_department' => array(
      'name' => 'Agency/Department',
      'machine_name' => 'nc_agency_department',
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
    'nc_counties' => array(
      'name' => 'North Carolina Counties',
      'machine_name' => 'nc_counties',
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
    'press_release_terms' => array(
      'name' => 'Press Release Terms',
      'machine_name' => 'press_release_terms',
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
    'video_terms' => array(
      'name' => 'Video Terms',
      'machine_name' => 'video_terms',
      'description' => 'Terms associated with videos',
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
