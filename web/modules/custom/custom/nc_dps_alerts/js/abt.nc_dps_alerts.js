(function($) {
  "use strict";
  Drupal.behaviors.abtDpsAlerts = {
    attach: function (context, settings) {
      var alertWrapper = $('#alerts'),
          alerts       = $('#alerts .alert-box'),
          amberClass   = 'breaking-amber',
          onceAttrKey  = 'abt_dps_alerts_runonce',
          onceAttrVal  = 'yes';

      // This code may be executed more than once on a page.
      // This results in unexpected behavior (floating amber alerts).
      // The solution is to implement a runonce strategy using
      // a custom data attribute on the wrapper to track
      // if the code has run before on this page load.
      if (alertWrapper.attr(onceAttrKey) !== onceAttrVal) {
        // Move amber alerts to beginning of alerts carousel.
        alerts.each(function(index, element) {
          if($(element).hasClass(amberClass)) {
            $(element).prependTo(alertWrapper);
          }
        });
        // Indicate that this has run. Set tracking attribute on wrapper.
        alertWrapper.attr(onceAttrKey, onceAttrVal);
      }
    }
  };
}(jQuery));