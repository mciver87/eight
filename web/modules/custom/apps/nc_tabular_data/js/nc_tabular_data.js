(function ($) {
  Drupal.behaviors.nc_tabular_data = {
    attach: function (context, settings) {

      var elem = $('table.tablefield'),
          defaultSettings = {
          responsive : true,
          lengthMenu: [[10, 25, 50, 100, -1], [10, 25, 50, 100, "All"]],
          pageLength : 100, // Default number of rows to show.
          order : [], // This disables ordering by default, so items appear in the order they were entered.
          bSort : true,
        },
        dtOptions = $.extend({}, defaultSettings, settings.nc_tabular_data || {});
        var datatable = elem.DataTable(dtOptions);
    }
  }
})(jQuery);
