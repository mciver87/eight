<?php
/**
 * @file
 * Template for CTA Cards.
 *
 * Available variables:
 * - $card_title: the (sanitized) title of the card.
 * - $card_description: the (sanitized) description of the card.
 * - $card_stat: the url the card links to.
 * - $card_accent: css class to apply to the card.
 */
?>

<div>
  <div class="cards">
    <div class="card stat <?php print $card_accent; ?>" itemscope itemtype="http://schema.org/Thing">
      <div class="meta">
        <span itemprop="name"><strong><?php print $card_stat; ?></strong><?php print $card_title; ?></span>
        <span itemprop="description"><?php print $card_description; ?></span>
      </div>
    </div>
  </div>
</div>
