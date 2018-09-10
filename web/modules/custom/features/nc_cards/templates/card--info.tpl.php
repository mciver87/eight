<?php
/**
 * @file
 * Template for Info Cards.
 *
 * Available variables:
 * - $card_title: the (sanitized) title of the card.
 * - $card_link: the url the card links to.
 * - $card_description: the (sanitized) description of the card.
 */
?>
<div class="info-summary <?php print $card_style; ?>">
  <p itemprop="description"><?php print $card_description; ?></p>
  <?php if($card_link && $card_title): ?>
    <a href="<?php print $card_link ?>" itemprop="url" class="button ghost inverted"><?php print $card_title ?></a>
  <?php endif; ?>
</div>

