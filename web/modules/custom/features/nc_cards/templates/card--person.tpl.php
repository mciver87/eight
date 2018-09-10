<?php
/**
 * @file
 * Template for Person Cards.
 *
 * Available variables:
 * - $card_title: the (sanitized) title of the card.
 * - $card_name: the name of the card.
 * - $card_link: the url the card links to.
 * - $card_image: the card image.
 * - $card_framed: css class to apply to the card.
 */
?>

<div>
  <div class="cards">
    <div class="card person <?php print $card_framed; ?>" itemscope itemtype="http://schema.org/Person">
      <a href="<?php print $card_link; ?>" itemprop="url">
        <span itemprop="photo"><?php print render($card_image); ?></span>
        <div class="meta">
          <span itemprop="name"><?php print $card_name; ?></span>
          <span itemprop="title"><?php print $card_title; ?></span>
        </div>
      </a>
    </div>
  </div>
</div>
