<?php
/**
 * @file
 * Template for Google Custom Search
 */
?>
<?php if ($search_id) : ?>
  <div>
    <script>
      (function() {
        var cx = '<?php echo $search_id; ?>'; // Insert your own Custom Search engine ID here
        var gcse = document.createElement('script'); gcse.type = 'text/javascript'; gcse.async = true;
        gcse.src = '//www.google.com/cse/cse.js?cx=' + cx;
        var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(gcse, s);
      })();
    </script>
    <gcse:search></gcse:search>
  </div>
<?php else: ?>
  <div>SearchID missing.</div>
<?php endif; ?>