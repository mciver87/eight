(function ($) {
    Drupal.behaviors.nc_charts = {
        attach: function (context, settings) {
            var charts = settings.nc_charts;
            for (var id in charts) {
                $('#' + id, context).once('nc-chart', function() {
                    var chartConfig = charts[id].chart_object;
                    // Fixes the legend border colors for bar charts.
                    if (typeof charts[id].legend_border_colors != 'undefined') {
                        chartConfig.options.legend.labels.generateLabels = function (chart) {
                            var labels = Chart.defaults.global.legend.labels.generateLabels(chart);
                            for (var i = 0; i < charts[id].legend_border_colors.length; i++) {
                                labels[i].strokeStyle = charts[id].legend_border_colors[i];
                            }
                            return labels;
                        };
                    }
                    var ctx = $('#' + id, context);
                    var myChart = new Chart(ctx, charts[id].chart_object);
                });
            }

            $('body', context).once('toggle-table', function() {
                $('button.nc-charts-table-toggle', context).click(function() {
                    var $toggle = $(this);
                    $(this).parent('p').next('div.nc-charts-data-table').toggle(400, function() {
                        if ($(this).is(':visible')) {
                            $toggle.text(Drupal.t('Hide Table'));
                        } else {
                            $toggle.text(Drupal.t('Show Table'));
                        }
                    });
                });
            });
        }
    };
})(jQuery);