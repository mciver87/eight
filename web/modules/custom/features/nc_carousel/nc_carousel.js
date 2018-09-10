(function ($) {
  "use strict";
  Drupal.behaviors.ncCarousel = {
    attach: function (context, settings) {
      var owl = $('body .owl-carousel').not('body.page-node-edit .owl-carousel');
      owl.each(function () {
        var data = $(this).data('nc-carousel'),
          defaults = {
            transitionStyle: 'fade',
            navigation: true,
            slideSpeed: 1000,
            paginationSpeed: 1000,
            singleItem: true,
            mouseDrag: false,
            addClassActive: true,
            autoHeight: true,
            navigationText: ['<i class="icon-chevron-left"></i>', '<i class="icon-chevron-right"></i>'],
            afterAction: afterAction
          },
          options = $.extend({}, defaults, data);

        $(this).owlCarousel(options);

        function afterAction() {
          $(this).find('.owl-buttons').fadeIn(500);
        }
      });
    }
  };
})(jQuery);