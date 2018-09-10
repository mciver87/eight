<?php
/**
 * @file
 * Template for markup of newsletter signup form.  Form variables are:
 *
 * email            Email to subscribe to list
 * call_to_action   Call to action text that displays to the left of the email
 * subscribe        Submit button
 */
?>
<?php if($card): ?>
  <?php print render(theme('nc_signup_form_card', get_defined_vars())); ?>
<?php else: ?>
  <section class="band pad-small email-signup">
    <div class="wrapper group">
      <header>
        <img src="<?php print $theme_path; ?>/img/g_email-notification.svg" aria-hidden="true" alt="email icon with notification indicator" />
        <h2 class="email-signup-title"><?php print $title; ?></h2>
        <p><?php print render($form['call_to_action']); ?></p>
      </header>
      <section class="field-group">
        <div class="field">
          <label for="edit-email">Email Address:</label>
          <input type="email" name="email" id="edit-email" placeholder="someone@example.com" autocapitalize="off" />
          <!-- <?php //print render($form['email']); ?> -->
          <strong class="error-message">This field is required <span class="icon-error" aria-hidden="true"></span></strong>
        </div>
        <?php print render($form['subscribe']); ?>
      </section>
    </div>
  </section>
  <?php if (!path_is_admin(current_path())) : ?>
    <?php print drupal_render_children($form); ?>
  <?php endif; ?>
<?php endif; ?>
