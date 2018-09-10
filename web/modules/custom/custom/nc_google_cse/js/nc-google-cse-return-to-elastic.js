(function($) {
  Drupal.behaviors.ncGoogleCse = {
    attach: function(context, settings) {
      // Optional return to elastic button.
      if (Drupal.settings.elasticReturn === '1') {
        var window_width = $(window).width()
        $(window).load(function() {
          if (window_width >= 992) {
            $('<td style="vertical-align: top;"><a href="search?search_api_views_fulltext=" class="button" id="elastic-search-link">Search This Site Only</a></td>').insertAfter('td.gsc-search-button');
          }
          else {
            $('<a href="search?search_api_views_fulltext=" class="button" id="elastic-search-link">Search This Site Only</a>').insertAfter('table.gsc-search-box');
          }
        });

        // Get contents of input to pass to elastic. Derived from search all button on elastic page.
        $('body').on('click', '#elastic-search-link', function(e) {
          e.preventDefault();
          window.open($('#elastic-search-link').attr('href') + $('#gsc-i-id1').val(), '_self');
        });
      }
    }
  };
}(jQuery));