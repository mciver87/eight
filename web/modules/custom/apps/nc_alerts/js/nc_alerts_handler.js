/**
 * This is a handler for the alerts functionality - dismiss & recall.
 */
(function ($, window, document) {
  "use strict";
  var AlertsHandler = (function () {
    var opts = {},
        elem = {},
        cookieKey  = 'alerts-hash',
        hashAttrs  = ['data-alerts-hash', 'alerts-hash'];

    /**
     * Sets the cookie that indicates the given hash has been dismissed.
     *
     * @param hash - The hash value.
     */
    function setCookie(hash) {
      $.cookie(cookieKey, hash);
    };

    /**
     * Gets current cookie value (if set).
     *
     * @returns {*|String}
     */
    function getCookie() {
      return $.cookie(cookieKey);
    };

    /**
     * Hide all alerts.
     *
     * @param transitionType
     */
    function hideAll(transitionType) {
      if(transitionType === 'slide') {
        elem.slideUp();
      }
      else {
        elem.hide();
      }
    };

    /**
     * Show all alerts.
     *
     * @param transitionType
     */
    function showAll(transitionType) {
      if(transitionType === 'slide') {
        elem.slideDown();
      }
      else {
        elem.hide();
      }
    };

    /**
     * This handles the entire dismiss process.
     *
     * @param transitionType
     */
    function dismiss(transitionType) {
      setCookie(getHash());
      hideAll(transitionType);
      
    };

    /**
     * This handles the entire recall process.
     *
     * @param transitionType
     */
    function recall(transitionType) {
      setCookie(false);
      showAll(transitionType);
    };

    /**
     * Gets the data hash.
     */
    function getHash() {
      for (var attr in hashAttrs) {
        if (elem.attr(hashAttrs[attr])) {
          return elem.attr(hashAttrs[attr]);
        }
      }
    };

	  /**
     * This is the main routine. Setup.
     */
    function run() {
      var hash = getHash(), cookie = getCookie();
      if (hash === cookie) {
        dismiss();
      }
    };

    // This is our return object.
    return {
      init : function(outerElem, options) {
        opts = options || {};
        elem = $(outerElem);
        cookieKey  = opts.cookieKey || 'alerts-hash';
        hashAttrs = opts.hashAttrs || ['data-alerts-hash', 'alerts-hash'];
        run();
      },
      dismiss : dismiss,
      recall : recall
    };
  });
  // Attach to outer scope.
  $.fn.alertsHandler = function (options) {
    var handler = new AlertsHandler();
    handler.init(this, options);
    return handler;
  };
}(jQuery, window, document));