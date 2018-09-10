<?php $_first = true; ?>
<div class="nc-social-follow-us">
  <?php if (isset($title) && $title) : ?>
    <h3 class="section-title border"><?php print $title; ?></h3>
  <?php endif; ?>
  <section class="cards social parts-span-fourth">
    <?php if (isset($facebook) && $facebook) : ?>
      <div class="card cta facebook" itemscope="" itemtype="http://schema.org/Thing">
        <a href="<?php print $facebook; ?>" itemprop="url" target="_blank">
          <div class="meta">
            <span class="icon-facebook" aria-hidden="true"></span>
            <div>
              <span itemprop="name"><?php print !empty($facebook_title) && $facebook_title ? $facebook_title : t('Follow Us on Facebook'); ?></span>
              <span itemprop="description"><?php print t('social media'); ?></span>
            </div>
          </div>
        </a>
      </div>
    <?php endif; ?>

    <?php if (isset($twitter) && $twitter) : ?>
      <div class="card cta twitter" itemscope="" itemtype="http://schema.org/Thing">
        <a href="<?php print $twitter; ?>" itemprop="url" target="_blank">
          <div class="meta">
            <span class="icon-twitter" aria-hidden="true"></span>
            <div>
              <span itemprop="name"><?php print !empty($twitter_title) && $twitter_title ? $twitter_title : t('Follow Us on Twitter'); ?></span>
              <span itemprop="description"><?php print t('social media'); ?></span>
            </div>
          </div>
        </a>
      </div>
    <?php endif; ?>

    <?php if (isset($instagram) && $instagram) : ?>
      <div class="card cta instagram" itemscope="" itemtype="http://schema.org/Thing">
        <a href="<?php print $instagram; ?>" itemprop="url" target="_blank">
          <div class="meta">
            <span class="icon-instagram" aria-hidden="true"></span>
            <div>
              <span itemprop="name"><?php print !empty($instagram_title) && $instagram_title ? $instagram_title : t('Follow Us on Instagram'); ?></span>
              <span itemprop="description"><?php print t('social media'); ?></span>
            </div>
          </div>
        </a>
      </div>
    <?php endif; ?>

    <?php if (isset($flickr) && $flickr) : ?>
      <div class="card cta flickr" itemscope="" itemtype="http://schema.org/Thing">
        <a href="<?php print $flickr; ?>" itemprop="url" target="_blank">
          <div class="meta">
            <span class="icon-flickr" aria-hidden="true"></span>
            <div>
              <span itemprop="name"><?php print !empty($flickr_title) && $flickr_title ? $flickr_title : t('Follow Us on Flickr'); ?></span>
              <span itemprop="description"><?php print t('social media'); ?></span>
            </div>
          </div>
        </a>
      </div>
    <?php endif; ?>

    <?php if (isset($youtube) && $youtube) : ?>
      <div class="card cta youtube" itemscope="" itemtype="http://schema.org/Thing">
        <a href="<?php print $youtube; ?>" itemprop="url" target="_blank">
          <div class="meta">
            <span class="icon-youtube" aria-hidden="true"></span>
            <div>
              <span itemprop="name"><?php print !empty($youtube_title) && $youtube_title ? $youtube_title : t('Follow Us on YouTube'); ?></span>
              <span itemprop="description"><?php print t('social media'); ?></span>
            </div>
          </div>
        </a>
      </div>
    <?php endif; ?>

    <?php if (isset($pinterest) && $pinterest) : ?>
      <div class="card cta pinterest" itemscope="" itemtype="http://schema.org/Thing">
        <a href="<?php print $pinterest; ?>" itemprop="url" target="_blank">
          <div class="meta">
            <span class="icon-pinterest" aria-hidden="true"></span>
            <div>
              <span itemprop="name"><?php print !empty($pinterest_title) && $pinterest_title ? $pinterest_title : t('Follow Us on Pinterest'); ?></span>
              <span itemprop="description"><?php print t('social media'); ?></span>
            </div>
          </div>
        </a>
      </div>
    <?php endif; ?>

    <?php if (isset($feed) && $feed) : ?>
      <div class="card cta feed" itemscope="" itemtype="http://schema.org/Thing">
        <a href="<?php print $feed; ?>" itemprop="url" target="_blank">
          <div class="meta">
            <span class="icon-feed" aria-hidden="true"></span>
            <div>
              <span itemprop="name"><?php print !empty($feed_title) && $feed_title ? $feed_title : t('Follow Us on Our RSS Feed'); ?></span>
              <span itemprop="description"><?php print t('social media'); ?></span>
            </div>
          </div>
        </a>
      </div>
    <?php endif; ?>

    <?php if (isset($medium) && $medium) : ?>
      <div class="card cta medium" itemscope="" itemtype="http://schema.org/Thing">
        <a href="<?php print $medium; ?>" itemprop="url" target="_blank">
          <div class="meta">
            <span class="icon-medium" aria-hidden="true"></span>
            <div>
              <span itemprop="name"><?php print !empty($medium_title) && $medium_title ? $feed_title : t('Follow Us on Medium'); ?></span>
              <span itemprop="description"><?php print t('social media'); ?></span>
            </div>
          </div>
        </a>
      </div>
    <?php endif; ?>

  </section>
</div>
