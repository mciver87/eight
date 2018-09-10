<?php
/**
 * @file
 * Template for Event Cards.
 *
 * Available variables:
 * - $card_title: the (sanitized) title of the card.
 * - $card_link: the url the card links to.
 * - $card_image: the card image.
 * - $card_framed: a css class for adding a border around the card.
 * - $card_datetime: the published date, formatted as 2015-01-05T08:00Z.
 * - $card_date_day: the published date, formatted as the day of the month
 *   without leading zeros.
 * - $card_date_month: the published date, formatted as a full textual
 *   representation of a month, such as January or March.
 * - $card_address_locality: The locality (city) of the card address.
 * - $card_address_region: The region (state) of the card address.
 * - $card_event_type: The event type of the card.
 */
?>

<div>
  <div class="cards">
    <div class="card event <?php print $card_framed; ?>" itemscope itemtype="http://schema.org/Event">
      <a href="<?php print $card_link; ?>" itemprop="url">
        <span itemprop="photo">
          <span itemprop="startDate"><time datetime="<?php print $card_datetime; ?>"><?php print $card_date_day; ?><span><?php print $card_date_month; ?></span></time></span>
          <?php print render($card_image); ?>
        </span>
        <div class="meta">
          <span itemprop="summary"><?php print $card_title; ?></span>
          <span itemprop="location">
            <span itemprop="address" itemscope itemtype="http://data-vocabulary.org/Address">
              <?php if ($card_address_locality): ?>
                <span itemprop="locality"><?php print $card_address_locality; ?></span>,
              <?php endif; ?>
              <?php if ($card_address_region): ?>
                <span itemprop="region"><?php print $card_address_region; ?></span>
              <?php endif; ?>
            </span>
          </span>
          <span itemprop="eventType"><?php print $card_event_type; ?></span>
        </div>
      </a>
    </div>
  </div>
</div>
