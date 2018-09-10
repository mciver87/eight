/**
 * This handles scrolling the page on the services list to the results section.
 *
 * Although there are default settings integrated with this code that are
 * designed to work on nc.gov and associated sites, you can override much
 * of the functionality by defining nc_services_options in a global context
 * and including it before this script.
 *
 * nc_services_options.offset = function | int - defines offset to scroll (for fixed header)
 * nc_services_options.target = function | string - defines target element to scroll to
 * nc_services_options.duration = int - scroll animation speed
 * nc_services_options.timeout = int - defines timeout before scroll (to allow page to load)
 * nc_services_options.enabled = bool - last chance to enable/disable this functionality
 */
(function ($, opts) {
  /**
   * Scroll to the target.
   *
   * @param target - HTML element
   * @param duration - Animation speed
   * @param offset - Offset (px) scroll (useful for fixed headers)
   */
  function nc_services_scroll_to_results(target, duration, offset) {
    $("body, html").animate({
      scrollTop: target.offset().top - offset
    }, duration);
  };

  Drupal.behaviors.nc_services = {
    attach: function (context, settings) {
      // Get all the arguments prepped.
      var module_settings = typeof settings.nc_services !== 'undefined' ? settings.nc_services: {},
        target = opts.target || module_settings['target']|| 'div.results-title-block',
        duration = opts.duration || module_settings['duration'] || 250,
        timeout = opts.timeout || module_settings['timeout'] || 500,
        enabled = true,
        offset = opts.offset || module_settings['offset'] || function() {
            return jQuery("div.mobile-nav").height() > 0 ?
              jQuery("div.mobile-nav").position().top + jQuery("div.mobile-nav").outerHeight(true) :
              jQuery("div.mainMenu  nav.topical-nav").position().top + jQuery("div.mainMenu  nav.topical-nav").outerHeight(true);
          };

      if (typeof opts.enabled !== 'undefined') {
        enabled = opts.enabled;
      } else if (typeof module_settings['enabled'] !== 'undefined') {
        enabled = module_settings['enabled'];
      }

      if (enabled) {
        setTimeout(function() {
          if (typeof  offset === 'function') {
            offset = offset();
          }

          if (typeof  target === 'function') {
            target = target();
          }

          if (typeof target === 'string') {
            target = $(target);
          }

          nc_services_scroll_to_results(target, duration, offset);
        }, 400);
      }
    }
  };
}(jQuery, (typeof nc_services_options !== 'undefined' ? nc_services_options : {})));