<?php
/**
 * @file
 * The main navigation template for North Carolina.
 *
 * Start here if you are troubleshooting the navigation.
 */
?>
  <?php if (isset($logo) && $logo && theme_get_setting('color_profile') == 'ncgov') : ?>
    <style>
    @media screen and (max-width: 1023px) {
      .topical-nav ul li.home a {
        background: url(<?php echo $logo; ?>) no-repeat 50% 50%/auto 70px;
      }
      .mobile-nav div img,
      .mobile-nav div svg {
        display: none;
      }
    }
    @media screen and (min-width: 1024px) {
      .mobile-nav div {
        width: 265px;
        width: 16.5625rem;
        height: 160px;
        height: 10rem;
        top: 0;
      }
      .mobile-nav div img {
        width: 265px;
        width: 16.5625rem;
        height: 160px;
        height: 10rem;
      }
      .mobile-nav div svg {
        display: block;
        max-height: 100%;
        height: auto;
      }
      .mobile-nav div a,
      .mobile-nav h1 a {
        background-image: none;
        height: 100%;
        width: 100%;
        text-align: center;
      }
      .mobile-nav .site-title-mobile {
        display: none;
      }
      .menu-container {
        padding-top: 80px;
      }
      .enterprise-nav {
        height: 80px;
      }
      .enterprise-nav ul li a {
        line-height: 90px;
      }
      .header-container .alert-widget {
        top: 20px;
      }
      .header-search {
        top: 30px;
      }
      .enterprise-nav ul li:last-child {
        margin-right: 70px;
      }

      .topical-nav ul li.home a {
        background: none;
        background-image: none;
        font-family: 'Georgia';
        text-decoration: none;
        font-size: 1.2rem;
        text-align: center;
        font-weight: 700;
      }
    }
    @media print {
      .enterprise-core-dark .mobile-nav div a {
        background: none !important;
      }
    }
  </style>
  <?php endif; ?>

<?php if (isset($logo) && $logo && theme_get_setting('color_profile', 'nc_base_theme') != 'ncgov') : ?>
  <style>
    @media screen and (max-width: 1023px) {
      .topical-nav ul li.home a {
        background-image: url(<?php echo $logo; ?>);
      }
      .mobile-nav div img,
      .mobile-nav div svg {
        display: none;
      }
    }
    @media screen and (min-width: 1024px) {
      .mobile-nav div {
        max-width: 300px;
        height: auto;
        max-height: 60px;
      }
      .mobile-nav div img {
        max-width: 100%;
        max-height: 100%;
      }
      .mobile-nav div svg {
        display: block;
        max-height: 100%;
        height: auto;
      }
      .mobile-nav div a,
      .mobile-nav h1 a {
        background-image: none;
        height: 60px;
        width: auto;
        text-align: left;
      }
      .mobile-nav .site-title-mobile {
        display: none;
      }
      .menu-container {
        padding-top: 100px;
      }
      .enterprise-nav {
        height: 100px;
      }
      .enterprise-nav ul li a {
        line-height: 90px;
      }
      .header-container .alert-widget {
        top: 20px;
      }
      .header-search {
        top: 30px;
      }
      .enterprise-nav ul li:last-child {
        margin-right: 70px;
      }
    }
    @media print {
      .enterprise-core-dark .mobile-nav div a {
        background: none !important;
      }
    }
  </style>
<?php endif; ?>
<div class="mobile-nav">
  <button class="flyout-trigger open-trigger"><span class="icon-dehaze" aria-hidden="true"></span><span> Menu</span></button>
  <div class="site-title">
    <a href="/" rel="home" title="<?php print $site_name; ?>">
      <?php if (isset($logo) && $logo) :
        $finfo = pathinfo($logo, PATHINFO_EXTENSION);
          if($finfo == 'svg') :
            $logo_file = file_get_contents($logo);
            if (strpos($logo_file, 'preserveAspectRatio="xMinYMid"') === false) :
                $logo_file = substr_replace($logo_file, ' preserveAspectRatio="xMinYMid"', 4, 0);
            endif;
            echo $logo_file;
          else : ?>
          <img src="<?php echo $logo; ?>" alt="<?php print $site_name; ?> logo"/>
          <?php endif;
        endif; ?>
      <span class="site-title-mobile"><?php print $site_name; ?></span>
    </a>
  </div>
  <button formaction="search" class="search-trigger"><span>Search </span><span class="icon-search" aria-hidden="true"></span></button>
</div>
<div class="<?php print $main_menu_classes; ?>" id="mainMenu">
  <div aria-label="First level" class="">
    <button href="#" class="flyout-trigger close-trigger" aria-hidden="true"><span class="icon-close" aria-hidden="true"></span><span>Close Menu</span></button>
    <div data-scrollmagic-pin-spacer="" class="scrollmagic-pin-spacer">
      <?php if (isset($topical_nav)) : ?>
        <?php print render($topical_nav); ?>
      <?php endif; ?>
    </div>
    <?php if (isset($enterprise_nav)) : ?>
      <?php print render($enterprise_nav); ?>
    <?php endif; ?>
  </div>
</div>