<?php

/**
 * @file
 * Catalog photo list theme implementation to display a catalog using photo list.
 *
 * @see template_preprocess()
 * @see template_preprocess_taxonomy_term()
 * @see template_process()
 *
 * @ingroup themeable
 */
?>
<div id="taxonomy-term-<?php print $term->tid; ?>" class="<?php print $classes; ?>">
  <div class="header-image">
    <?php print render($header_image); ?>
  </div>
  <?php if (!empty($sidebar_filters)): ?>
    <div id="filter-options" class="filter-options vertical-filter">
      <div class="fieldgroup">
        <?php print render($sidebar_filters); ?>
      </div>
    </div>
  <?php endif; ?>
  <?php if (!empty($result_count)): ?>
    <div class="filter-results-stats">
      <span class="result-count"><strong><?php print $result_count; ?></strong></span> results found
    </div>
  <?php endif; ?>
  <?php if (!empty($catalog_results)): ?>
    <section class="results">
      <?php print render($catalog_results); ?>
    </div>
  <?php endif; ?>
</div>
