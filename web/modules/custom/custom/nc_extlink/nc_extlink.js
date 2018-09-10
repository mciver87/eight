(function ($) {
  Drupal.behaviors.ncExtLink = {
    attach: function (context, settings) {
      if (Drupal !== undefined && Drupal.extlink !== undefined) {
        // This is a partial rewrite of the applyClassAndSpan function from the
        // default extlink.js file. I don't want to override the plugin's entire
        // Javascript implementation, so this focuses on one piece only.
        Drupal.extlink.applyClassAndSpan = function (links, class_name) {
          // This code is removed from the extlink module.
          // The part that adds spans is gone, though.
          // No other modifications at this time.
          var $links_to_process;
          if (Drupal.settings.extlink.extImgClass) {
            $links_to_process = $(links);
          } else {
            var links_with_images = $(links).find('img').parents('a');
            $links_to_process = $(links).not(links_with_images);
          }
          $links_to_process.addClass(class_name);
          
          // This code is to remove the class .ext from buttons since the 
          // original module only excludes by parent item.
          $('.button').removeClass('ext');
        };
      }
    },
  };
})(jQuery);
