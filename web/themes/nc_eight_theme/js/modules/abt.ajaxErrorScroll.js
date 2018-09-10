/**
 * Scrolls the page to the error messages, if present, after an AJAX request.
 */
(function($) {
  Drupal.behaviors.abtAjaxErrorScroll = {
    attach: function(context, settings) {
      $('body', context).once('apply-ajax-scroll-listener', function() {
        $(document, context).ajaxComplete(function(event, xhr, settings) {
          // First determine if the error message wrapper appears
          var errorMessageWrappers = $('span.message-wrapper.error');
          if (errorMessageWrappers.length == 0 || !xhr.responseText) {
            return;
          }

          // Find all of the wrappers that the errorMessageWrappers are part of.
          var wrappers = {};
          for (var i = 0; i < errorMessageWrappers.length; i++) {
            var parent = $(errorMessageWrappers[i]).parent().parent();
            wrappers[parent.attr('id')] = parent;
          }

          // Get the response object, and check for wrappers.  If a wrapper is in the wrappers object
          // scroll to it and return;
          var response = $.parseJSON(xhr.responseText);

          for (var r = 0; r < response.length; r++) {
            if (response[r].settings == undefined || response[r].settings.ajax == undefined) {
              continue;
            }
            var settingsAjax = response[r].settings.ajax;

            for (var x in settingsAjax) {
              // Check if we have found a wrapper that has the error messages
              if (settingsAjax[x].wrapper !== undefined && wrappers[settingsAjax[x].wrapper] !== undefined) {
                var offset = ($('div.mobile-nav', context).height() > 0 ?
                  $('div.mobile-nav', context).position().top + $('div.mobile-nav', context).outerHeight(true) :
                  $('div.mainMenu  nav.topical-nav', context).position().top + $('div.mainMenu  nav.topical-nav', context).outerHeight(true)
                );
                $('body, html', context).animate(
                  {
                    scrollTop: wrappers[settingsAjax[x].wrapper].offset().top - offset
                  },
                  250
                );
                return;
              }
            }
          }
        });
      });
    }
  }
})(jQuery);