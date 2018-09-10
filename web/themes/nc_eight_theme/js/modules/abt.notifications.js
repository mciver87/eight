$( function() {

  if ( $('.alerts').length ) {
  
    // Setup alerts carousel  
    if ( $('.alerts .alert-box').length > 1 ) {
      
      $('.alerts').each(function() {
      
        $('.alerts').owlCarousel({
          transitionStyle: 'goDown',
          navigation: true,
          slideSpeed: 500,
          paginationSpeed: 500,
          singleItem: true,
          mouseDrag: false,
          addClassActive: true,
          autoHeight: true,
          navigationText: ['<i class="icon-chevron-left"></i>', '<i class="icon-chevron-right"></i>']
        });
      
      });  
    
    }
    
    // Display number of alerts in widget
    $('.alert-widget .alert-count').text($('.alert-box').length);
    
    // Dismiss alert notifications
    $('.alert-box .alert-dismiss').on('click', function() {
      $(this).closest('.alert-box').addClass('is-hidden');
    });
    $('.alert-widget').on('click', function() {
      $('#alerts').toggleClass('is-hidden');
    });

    // Add conditional class to hide widget and move nav items
    if( $('.alerts').length ) {
      $('.header-container').removeClass('no-alerts');
    }
    else {
      $('.header-container').addClass('no-alerts');
    }

  }

});