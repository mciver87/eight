<?php
/**
 * @file
 * Template for Video Cards.
 *
 * Available variables:
 * - $card_title: the (sanitized) title of the card.
 * - $card_link: the url of the video.
 * - $card_image: the card image.
 * - $card_framed: a css class for adding a border around the card.
 * - $card_keywords: the formatted list of keywords separated by a comma.
 * - $card_date: the formatted published date of the card.
 * - card_prop_date: the dae to be used in the item prop attribute
 */
?>
<div>
    <div class="cards">
        <div class="card video <?php print $card_framed; ?>" itemscope itemtype="http://schema.org/VideoObject">
            <a href="<?php print render($card_link); ?>" itemprop="url">
                <span itemprop="thumbnail"><?php print render($card_image); ?></span>
                <div class="meta">
                    <span itemprop="name"><?php print $card_title; ?></span>
                    <?php if($card_date): ?>
                      <time itemprop="datePublished" datetime="<?php print $card_prop_date; ?>"><?php print render($card_date); ?></time>
                    <?php endif; ?>
                    <?php if($card_keywords): ?>
                        <span itemprop="keywords"><?php print $card_keywords; ?></span>
                    <?php endif; ?>
                </div>
            </a>
        </div>
    </div>
</div>
