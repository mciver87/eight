<div class="quick-links <?php print implode(' ', $classes_array); ?>">
  <?php if (isset($title) && !empty($title)) : ?>
    <h3 class="section-title"><?php print $title; ?></h3>
  <?php endif; ?>
  <ul>
    <?php foreach ($rows as $row) : ?>
      <li><?php print render($row); ?></li>
    <?php endforeach; ?>
  </ul>
</div>
