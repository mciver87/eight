<?php
  $_thead = array_shift($table_data);
?>
<?php if ($show_title) : ?>
    <h4><?php print $bean->title; ?></h4>
  <?php endif; ?>
<div class="nc-charts-canvas-holder nc-charts-type-<?php print $chart_type; ?>">
  <canvas id="nc-chart-<?php print $bid; ?>" aria-hidden="true"/>
</div>
<?php if ($toggle_table) : ?>
  <?php $_btn_lbl = ($hide_table ? t('Show Table') : t('Hide Table')); ?>
  <p class="button-group"><button class="nc-charts-table-toggle button"><?php print $_btn_lbl; ?></button></p>
<?php endif; ?>
<div class="nc-charts-data-table"<?php print ($toggle_table && $hide_table ? ' style="display: none;"' : ''); ?>>
  <table>
    <caption><?php print $bean->title; ?></caption>
    <thead>
      <tr>
        <?php foreach ($_thead as $_thead_value) : ?>
          <th scope="col"><?php echo $_thead_value; ?></th>
        <?php endforeach; ?>
      </tr>
    </thead>
    <tbody>
      <?php foreach ($table_data as $_table_row) : ?>
        <?php $_first_cell = TRUE; ?>
        <tr>
          <?php foreach ($_table_row as $_table_cell) : ?>
            <?php if ($_first_cell) : ?>
              <th scope="row"><?php echo $_table_cell; ?></th>
            <?php else : ?>
              <td><?php echo $_table_cell; ?></td>
            <?php endif; ?>
            <?php $_first_cell = FALSE; ?>
          <?php endforeach; ?>
        </tr>
      <?php endforeach; ?>
    </tbody>
  </table>
</div>