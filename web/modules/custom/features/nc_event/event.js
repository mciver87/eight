(function ($, Drupal, window, document, undefined) {
  Drupal.behaviors.ncEvents = {
    attach: function (context, settings) {

      // Move the results summary
      $('#filter-results').replaceWith( $('.filter-results-stats') );

      var exposed_filter_calendar = $('#edit-field-event-dates-value-value-date');
      var toolbar = $('#events-toolbar');
      var calendar = $('#events-datepicker');
      var wrapper = $('#events-wrapper');
      var list = $('.related-cards');

      // Init the right-side datepicker.
      $(calendar).datepicker({
        onSelect: function (dateText, inst) {
          $(exposed_filter_calendar).val(dateText);
          $('#views-exposed-form-event-list-page').submit();
        }
      });
      $(calendar).datepicker('setDate',$(exposed_filter_calendar).val());

      // Make list-view active by default
      toolbar.addClass('list-view-active');
      wrapper.addClass('list-view-active');

      // Change display of event lists
      $('#event-display-toggle button').click(function() {
        if ($(this).hasClass('ghost')) {
          var display = $(this).attr('data-event-display');

          $(this).removeClass('ghost').siblings().addClass('ghost');

          if (display == "list") {
            toolbar.removeClass('grid-view-active');
            wrapper.removeClass('grid-view-active');

            toolbar.addClass('list-view-active');
            wrapper.addClass('list-view-active');

            list.addClass('stacked');
          } else {
            toolbar.removeClass('list-view-active');
            wrapper.removeClass('list-view-active');

            toolbar.addClass('grid-view-active');
            wrapper.addClass('grid-view-active');

            list.removeClass('stacked');
          }
        }
      });

      // Toggle datepicker
      $('#event-select-date').click(function() {
        calendar.toggle();
        calendar.toggleClass('is-active');
        calendar.toggleClass('is-inactive');
      });

      if (typeof enquire !== "undefined") {
        enquire.register("screen and (min-width:1024px)", {
          match: function () {

            // Display calendar
            calendar.show();
            calendar.removeClass('is-inactive');
            calendar.addClass('is-active');

            // Disable select-date button
            $('#event-select-date').prop('disabled', true);

            $('#event-display-toggle button').click(function () {
              var display = $(this).attr('data-event-display');

              if (display == "list") {

                // Show calendar
                calendar.show();
                calendar.removeClass('is-inactive');
                calendar.addClass('is-active');

                // Disable select-date button
                $('#event-select-date').prop('disabled', true);

              } else {

                // Enable select-date button
                $('#event-select-date').prop('disabled', false);

              }
            });
          },
          unmatch: function () {
            // Hide calendar
            calendar.hide();
            calendar.removeClass('is-active');
            calendar.addClass('is-inactive');
          }
        });
      }

    }
  };
})(jQuery, Drupal, this, this.document);

