(function ($) {
  Drupal.behaviors.catalogFold = {
    attach: function (context, settings) {
      $('.nc-catalog-fold').each(function() {
        if ($(this).nextAll().length > 0) {
          var expand = $(this).nextAll().hide();
          var toggler = '<p class="nc-catalog-expander">' + $(this).data('bname') + ' <span class="icon-arrow-forward"></span></p>';
          $(this).append(toggler);
          $(this).find('.nc-catalog-expander').on('click', function(e) {
            $(expand).slideToggle();
            if ($(this).hasClass('catalog-expanded')) {
              $(this).removeClass('catalog-expanded');
            }
            else {
              $(this).addClass('catalog-expanded');
            }
          });
        }
      });
    }
  }
})(jQuery);