<?php
/**
 * @file
 * Template for Government Cards.
 *
 * Available variables:
 * - $card_title: the (sanitized) title of the card.
 * - $card_image: the card image.
 * - $card_keywords: the formatted list of card terms separated by a comma.
 * - $card_link: the url the card links to.
 * - $card_link_text: the text for the card link.
 */
?>

<div>
  <div class="cards">
    <div class="card govt" itemscope itemtype="http://schema.org/Thing">
      <span itemprop="photo"><?php print render($card_image); ?></span>
      <div class="meta">
        <span itemprop="category"><?php print $card_keywords; ?></span>
        <h3 itemprop="name"><?php print $card_title; ?></h3>
        <?php if($card_link): ?>
          <a href="<?php print $card_link; ?>" itemprop="url" class="button ghost inverted"><span><?php print $card_link_text; ?></span></a>
        <?php endif; ?>
      </div>
    </div>
  </div>
</div>
