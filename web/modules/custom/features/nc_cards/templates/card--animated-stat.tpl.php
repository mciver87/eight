<?php
/**
 * @file
 * Template for Animated Stat Cards.
 *
 * Available variables:
 * - $card_title: the (sanitized) title of the card.
 * - $card_description: the (sanitized) description of the card.
 * - $card_stat: the url the card links to.
 * - $card_accent: css class to apply to the card.
 */
//'animation_type' => '',
//'counter_duration' => '',
//'chart_values' => '',
?>
<div>
  <div class="cards">
    <div class="card animated <?php print $animation_type; ?> stat <?php print $card_accent; ?>" itemscope itemtype="http://schema.org/Thing" id="animated-<?php print $animation_type; ?>-stat-<?php print $stat_id; ?>">
      <div class="meta">
        <span itemprop="name"><strong><?php print $counter_prefix; ?><span id="animated-<?php print $animation_type; ?>-stat-<?php print $stat_id; ?>-target">0</span><?php print $counter_suffix; ?></strong><?php print $card_title; ?></span>
        <span itemprop="description"><?php print $card_description; ?></span>
      </div>
    </div>
  </div>
</div>
