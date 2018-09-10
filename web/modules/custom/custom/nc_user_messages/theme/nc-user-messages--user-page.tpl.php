<?php
/**
 * @file
 * Template for displaying messages to the user.
 */
?>
<div class="user-messages">
  <h3><?php print t('Messages'); ?></h3>
  <dl>
    <?php foreach ($messages as $message) : ?>
      <dt><?php print $message->title; ?></dt>
      <dd>
        <div class="message-live-date"><?php print format_date($message->live_date, 'custom', 'D. m/d/Y - g:ia'); ?></div>
        <div class="message"><?php print $message->message; ?></div>
      </dd>
    <?php endforeach; ?>
  </dl>
</div>
