<?php
/**
 * @file
 * Template for markup of newsletter signup form in Card View mode.
 *
 * Form variables are:
 *
 * email            Email to subscribe to list
 * call_to_action   Call to action text that displays to the left of the email
 * subscribe        Submit button
 */
?>
<div class="cards">
  <div class="card cta theme-accent-red" itemscope="" itemtype="http://schema.org/Thing" style="">
    <a itemprop="url">
      <div class="meta">
        <span class="icon-email" aria-hidden="true"></span>
        <span itemprop="name"><?php print $title; ?></span>
      <span itemprop="description"><p><?php print render($form['call_to_action']); ?></p>
        <div class="field">
          <label for="email">Email Address:</label>
          <input type="email" name="email" id="edit-email" placeholder="someone@example.com" autocapitalize="off" />
          <strong class="error-message">This field is required <span class="icon-error" aria-hidden="true"></span></strong>
        </div>
        <?php print render($form['subscribe']); ?>
      </div>
    </a>
  </div>
</div>
<?php print drupal_render_children($form); ?>
