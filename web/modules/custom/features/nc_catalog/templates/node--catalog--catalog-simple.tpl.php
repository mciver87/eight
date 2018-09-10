<div id="node-<?php print $nid; ?>" class="node node-catalog contextual-links-region clearfix">
  <article class="article" itemscope="" itemtype="http://schema.org/Thing">
    <div class="keywords"><?php print $title; ?></div>
    <?php if (!empty($terms_exploded)): ?>
      <div class="term-keywords">
        <?php print $terms_exploded; ?>
      </div>
    <?php endif; ?>
    <div class="item">
      <h1 itemprop="name"><?php print $title; ?></h1>

      <?php
        foreach ($order as $field) {
          switch ($field) {
            case 'field_catalog_categories';
              if (!empty($terms_exploded)):
                print $terms_exploded;
              endif;
            break;
            case 'summary';
              if (!empty($summary)):
                print $summary;
              endif;
            break;
            case 'field_internal_or_external_url';
              if (!empty($links)):
                print $links;
              endif;
            break;
            case 'field_contacts';
              if (!empty($contacts)):
                print '<div class="contacts-wrapper">' . $contacts . '</div>';
              endif;
            break;
            case 'field_address';
              if (!empty($locations)):
                print '<div class="location-wrapper">' . $locations . '</div>';
              endif;
            break;
            case 'media';
              if (!empty($media)):
                print $media;
              endif;
            break;
            case 'body':
              if (!empty($body)):
                print '<div class="description-wrapper">' . $body . '</div>';
              endif;
            break;
            case 'field_fold':
              print '<div class="nc-catalog-fold" data-bname="' . end($order) . '""></div>';
            break;
          }
        }
      ?>

    </div>
  </article>
</div>
