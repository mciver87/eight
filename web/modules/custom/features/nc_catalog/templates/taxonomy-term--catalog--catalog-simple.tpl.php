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
<div id="taxonomy-term-<?php print $term->tid; ?>" class="<?php print $classes; ?> simple-list">
  <div class="header-image">
    <?php print render($header_image); ?>
  </div>
  <?php if (!empty($sidebar_filters)): ?>
    <button id="filter-options-toggle" class="button filter-options-toggle ghost" style="display: inline-block;">
      <span class="icon-settings" aria-hidden="true"></span> <?php print t('Filter'); ?>
    </button>
    <div id="filter-options" class="filter-options vertical-filter">
      <div class="fieldgroup">
        <?php print render($sidebar_filters); ?>
      </div>
    </div>
  <?php endif; ?>
  <?php if (!empty($result_count)): ?>
    <div class="filter-results-stats">
      <strong><span class="result-count"><?php print $result_count; ?></span></strong> <span class="result-noun">
        <?php if ($result_count == 1): ?>
          <?php print $singular_item; ?>
        <?php else: ?>
          <?php print $plural_item; ?>
        <?php endif; ?>
      </span> found
    </div>
  <?php endif; ?>
  <?php if (!empty($catalog_results)): ?>
    <section class="results">
      <?php if (!empty($display_search)): ?>
        <div id="search-wrapper">
          <input type="text" class="fuzzy-search" />

          <?php print render($catalog_results); ?>
        </div>
      <?php else: ?>
        <?php print render($catalog_results); ?>
      <?php endif; ?>
      <?php if ($allow_pager):?>
        <div class="pager">
          <span class="next"><a><?php print $pager_next; ?></a></span>
          <?php if ($allow_view_all): ?>
            <span class="view-all"><a><?php print $view_all_text; ?></a></span>
          <?php endif; ?>
        </div>
      <?php endif; ?>
    </section>
  <?php endif; ?>
</div>
