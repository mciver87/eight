<?php
/**
 * @file
 * Template for Agency Cards.
 *
 * Available variables:
 * - $card_link: the url the card title links to.
 * - $card_title: the (sanitized) title of the card.
 * - $card_keywords: the formatted list of card terms separated by a comma.
 * - $card_description: the (sanitized) description of the card.
 * - $card_link_website: the url the card links to.
 * - $card_link_website_title: the website title.
 * - $social_links: a render array representing social media links.
 * - $card_prefix: content to display before the main card data.
 */
?>

<div>
  <div class="cards">
    <article class="article agency" itemscope itemtype="http://schema.org/Thing">
      <div class="block-icon">
        <span class="<?php print $icon_classes ?>" aria-hidden="true"></span>
      </div>
      <div class="block-item">
        <?php if($card_prefix): ?>
          <?php print render($card_prefix); ?>
        <?php endif; ?>
        <h1 itemprop="name">
          <?php if($card_link): ?>
            <a href="<?php print $card_link; ?>" itemprop="url"><?php print $card_title; ?></a>
            <?php elseif($card_title): ?>
            <?php print $card_title; ?>
          <?php endif; ?>
        </h1>
        <?php if (isset($edit_link)): ?>
          <?php print $edit_link; ?>
        <?php endif; ?>

        <div class="meta">
          <span class="label category"><?php print $card_keywords; ?></span>
        </div>
        <?php if($card_description): ?>
          <p itemprop="description">
          <?php print $card_description; ?>
          </p>
        <?php endif; ?>
        <p>
        <?php print $phone; ?>
        <?php if ($card_link_website && $card_link_website_title): ?>
          <br/><?php print t('Website'); ?>: 
          <a href="<?php print $card_link_website; ?>" itemprop="url"><?php print $card_link_website_title; ?></a>
        <?php endif; ?>
        </p>
        <?php if($social_links): ?>
          <section class="social-links">
            <?php print render($social_links); ?>
          </section>
        <?php endif; ?>
      </div>
    </article>
  </div>
</div>
