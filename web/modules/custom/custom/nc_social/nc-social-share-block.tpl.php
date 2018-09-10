<div class="social-links">
  <p><strong><?php print t('Share this page:'); ?></strong></p>
  <ul>
    <li>
      <a href="https://www.facebook.com/sharer/sharer.php?u=<?php print urlencode($url); ?>" target="_blank">
        <span class="icon-facebook" aria-hidden="true"></span> <span><?php print t('Facebook'); ?></span>
      </a>
    </li>
    <li>
      <a href="http://twitter.com/intent/tweet?url=<?php print urlencode($url); ?>" target="_blank">
        <span class="icon-twitter" aria-hidden="true"></span> <span><?php print t('Twitter'); ?></span>
      </a>
    </li>
  </ul>
</div>
