<?php

/**
 * @file
 * Default template implementation to display the value of a field.
 */
?>
<?php if (isset($prefix_markup)): ?>
  <?php print $prefix_markup; ?>
<?php endif; ?>
<?php if (isset($wrapper_element)): ?>
  <<?php print $wrapper_element ?> class="<?php print $classes; ?>" <?php print $attributes; ?>>
<?php endif; ?>
  <?php if (!$label_hidden): ?>
    <?php if (isset($title_element)): ?>
      <<?php print $title_element ?> class="<?php print $title_classes ?>" <?php print $title_attributes; ?>>
    <?php endif; ?>
      <?php print $label . $label_suffix ?>
    <?php if (isset($title_element)): ?>
      </<?php print $title_element ?>>
    <?php endif; ?>
  <?php endif; ?>
  <?php if (isset($content_element)): ?>
    <<?php print $content_element ?> class="<?php print $content_classes ?>" <?php print $content_attributes; ?>>
  <?php endif; ?>
    <?php foreach ($items as $delta => $item): ?>
      <?php if (isset($item_element)): ?>
        <<?php print $item_element ?> class="<?php print $item_delta_classes[$delta]; ?>" <?php print $item_attributes[$delta]; ?>>
      <?php endif; ?>
        <?php print render($item); ?>
      <?php if (isset($item_element)): ?>
      </<?php print $item_element ?>>
      <?php endif; ?>
    <?php endforeach; ?>
  <?php if (isset($content_element)): ?>
  </<?php print $content_element ?>>
  <?php endif; ?>
<?php if (isset($wrapper_element)): ?>
</<?php print $wrapper_element ?>>
<?php endif; ?>
