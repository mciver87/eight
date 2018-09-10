<?php
/**
 * @file
 * NC Search block form template.
 */
?>
<label for="nc_search_block_form" class="visuallyhidden">Search NC.gov</label>
<input type="search" placeholder="<?php print $search_text_placeholder; ?>" name="<?php print $nc_search_name; ?>" id="nc_search_block_form" />
<input type="submit" value="Submit" /><span class="icon-search" aria-hidden="true"></span>
<?php print $search['hidden'] ?>
