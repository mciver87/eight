<?php
/**
 * @file
 * Template for NC BEACON employee detail page
 */
?>
<div class="<?php print $classes; ?>" <?php print $attributes; ?>>
  <section class="band pad-none employee-back-button">
    <a href="/employee-directory" class="button back ghost"><span>Back to search</span></a>
	</section>
  <section class="band">
    <div class="employee-card" itemscope itemtype="http://schema.org/Person">
      <div class="group">
        <div class="image-meta">
                    <!-- <img src="../img/l_ncgov-color.svg" />  -->
          <img src="/<?php echo drupal_get_path('theme',$GLOBALS['theme']);?>/img/l_ncseal.svg" />
        <?php if (!empty($Agency)) : ?>
          <p itemprop="title"><?php print $Agency; ?></p>
        <?php endif; ?>
        </div>
        <div class="meta">
          <p>State of North Carolina</p>
        <?php if (!empty($Agency) || !empty($Division)) : ?>
          <p itemprop="title"><?php print $Agency; ?><br/>
          <?php print $Division; ?></p>
        <?php endif; ?>
        <?php if (!empty($MailCity)) : ?>
          <div itemprop="address" itemscope itemtype="http://schema.org/PostalAddress">
            <p itemprop="streetAddress" ><?php print $MailAddress; ?><br/>
            <?php print $MailCity; ?>, <?php print $MailState; ?> <?php print $MailZip; ?></p>
          </div>
        <?php endif; ?>
          <h2 itemprop="name"><?php print $NameFirst; ?> <?php print $NameMiddle; ?> <?php print $NameLast; ?></h2>
        <?php if (!empty($Phone) || !empty($Email)) : ?>
          <p itemprop="telephone"><?php print $Phone; ?> <?php print $PhoneExt; ?></p>
          <a href="mailto:<?php print $Email; ?>"><?php print $Email; ?></a>
        <?php endif; ?>
        </div>
      </div>
    </div>
  </section>
  <section class="band pad-none">
    <div class="employee-notice">
      <p>
        State employees: If you have concerns about your contact information, please contact your Human Resources office.
      </p>
    </div>
  </section>
</div>
