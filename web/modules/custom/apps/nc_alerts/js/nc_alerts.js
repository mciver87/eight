(function($) {
  "use strict";
  Drupal.behaviors.nc_alerts = {
    attach: function (context, settings) {
      var alerts = $('#alerts');

      if ($('#alerts > .alert-box').length > 1) {
        var overrideOptions = settings.nc_alerts.options || {},
          carouselOptions = $.extend(
            {
              transitionStyle: 'goDown',
              navigation: true,
              callbacks: true,
              slideSpeed: 500,
              paginationSpeed: 500,
              singleItem: true,
              mouseDrag: false,
              addClassActive: true,
              autoHeight: true,
              navigationText: [
                '<i class="icon-chevron-left"></i>',
                '<i class="icon-chevron-right"></i>'
              ],
              'beforeInit': function(elem) {
                elem.find('.alert-box').show();
              }
            }, overrideOptions);

        // Add class for multiple alerts before owl inits.
        alerts.addClass('multiple-alerts').owlCarousel(carouselOptions);

        // Add the dismiss button.
        alerts.find('.owl-buttons').append('<button class="alert-dismiss" id="dismiss-alerts" title="Dismiss"><span class="icon-close" aria-hidden="true"></span> <span>Dismiss</span></button>');

      } else {
        alerts.find('.alert-box').show();
        // Add the dismiss button for a single alert.
        $('#alerts .alert-box').append('<div class="dismiss-single"><button class="alert-dismiss" id="dismiss-alerts" title="Dismiss"><span class="icon-close" aria-hidden="true"></span> <span>Dismiss</span></button></div>');
      }

      // Setup the handler object.
      var alertsHandler = alerts.alertsHandler({});

      // Add alerts toggle widget.
      $('.utility-wrapper').append('<div class="alert-widget">'+
        '<button id="recall-alerts">'+
          '<span class="icon-notifications" aria-hidden="true"></span>'+
          '<div class="alert-count">'+$('#alerts .alert-box').length+'</div>'+
        '</button>'+
      '</div>');

      // Show alerts toggle widget. May need conditional logic.
      $('.header-container.no-alerts').removeClass('no-alerts');

      // However whatever items/elements are chosen to perform the actions, this
      // demonstrates how to dismiss & recall alerts.
      $('#dismiss-alerts').click(function () {
        alertsHandler.dismiss('slide');
      });
      $('#recall-alerts').click(function () {
        alertsHandler.recall('slide');
      });
    }
  };
}(jQuery));