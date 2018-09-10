<?php
/**
 * @file
 * Template for CTA Cards.
 *
 * Available variables:
 * - $card_title: the (sanitized) title of the card.
 * - $card_description: the (sanitized) description of the card.
 * - $card_link: the url the card links to.
 * - $card_accent: css class to apply to the card.
 * - $card_icon: the icon html.
 */
?>

<div>
  <div class="cards">
    <div class="card cta <?php print $card_accent; ?>" itemscope itemtype="http://schema.org/Thing">
      <a href="<?php print render($card_link); ?>" itemprop="url">
        <div class="meta">
          <span class="<?php print $icon_classes ?>" aria-hidden="true"></span>
          <span itemprop="name"><?php print $card_title; ?></span>
          <span itemprop="description"><?php print $card_description; ?></span>
        </div>
      </a>
    </div>
  </div>
</div>
