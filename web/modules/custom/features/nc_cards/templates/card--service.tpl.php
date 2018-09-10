<?php
/**
 * @file
 * Template for Service Cards.
 *
 * Available variables:
 * - $card_name: the (sanitized) name of the service.
 * - $card_link: the url the card links to.
 * - $card_icon: the icon html.
 */
?>

<div>
  <div class="cards">
    <div class="card service" itemscope itemtype="http://schema.org/Thing">
      <div class="meta">
        <a href="<?php print $card_link; ?>" itemprop="url">
          <span class="<?php print $icon_classes ?>" aria-hidden="true"></span>
          <span itemprop="name"><?php print $card_name; ?></span>
        </a>
      </div>
    </div>
  </div>
</div>
