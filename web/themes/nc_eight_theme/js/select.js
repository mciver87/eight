/**
 * @file
 * A JavaScript file for select boxes.
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - https://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {
  Drupal.behaviors.ncSelect = {
    attach: function(context, settings) {

      /* Custom select boxes
       ------------------------------------------------------------------------ */
      $('select:not(.no-selectBoxIt)').once().selectBoxIt({
        autoWidth: false,
        copyClasses: 'form-select',
        dynamicPositioning: false,
        downArrowIcon: 'icon-expand-more',
        aggressiveChange: true
      });
    }
  };
})(jQuery, Drupal, this, this.document);
