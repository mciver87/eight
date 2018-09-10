/**
 * Here's a cute little script to override the default jump behavior
 * of anchor links.
 *
 * The offset on jumps is wrong due to the floating navigation menu,
 * so we'll incorporate some jQuery magic to ease the process and
 * get the spacing correct.
 *
 */
var AbtJumpToOverride = (function ($, document, window, history) {
    'use strict';
    /**
     * The factory method. Pass in some options, you get your expected behavior.
     *
     * Target: Target objects such as anchors to apply the jump scripting to
     * Offset: A function that will return the size (in pixels) of the fixed navigation menus
     * Duration: Scroll animation speed
     * Onready: Override the initial jump on document ready
     *
     * @param opts
     */
    return function (opts) {
        // Extend defaults
        var options = $.extend({
            "target": $("a"),
            "offset": function () {
                return 0;
            },
            "duration": 250,
            "onready": true
        }, opts);

        /**
         * Relatively generic jump to function to mimic
         * the what the browser would normally do, but
         * adding in an offset
         *
         * @param href
         * @param offset
         * @returns {boolean}
         */
        function jumpTo(href, offset, duration) {
            if (href) {
                try {
                    // This does the scrolling
                    $("body, html").animate({
                        scrollTop: $(href).offset().top - offset
                    }, duration);

                    // This is how we get the #SomethingHappened back into the URL
                    if (history && typeof(history.pushState) !== 'undefined') {
                        history.pushState({}, document.title, window.location.pathname + href);
                        return false;
                    }
                } catch(e) {
                    // Just return if there was an exception.
                    return;
                }
            }
        }

        // On page load, we need to deal with someone
        // coming in with a direct link to one of the jumps
        // i.e. http://www.blahblahblah.com/parent/child/page#SomethingHappened
        $(document).ready(function () {
            if (options.onready) {
                var offset = options.offset();
                if(jQuery(window.location.hash).hasClass('ui-tabs-panel')) {
                    offset += jQuery('.ui-tabs-nav').outerHeight(true);
                }
                jumpTo(window.location.hash, offset, options.duration);
            }
        });

        // Attach our special jumpTo function to the click event
        options.target.on("click", function (e) {
            e.preventDefault();
            jumpTo($(this).attr('href'), options.offset(), options.duration);
            return false;
        });
    };
})(jQuery, document, window, window.history);

// This is where the jump to override object is instantiated
jQuery(document).ready(function() {
    // setTimeout is being used here to allow other page elements to load up
    setTimeout(function(){
        // This is where the magic starts ...
        // Setup the override specifically for NC.gov
        // and associated sites
        AbtJumpToOverride({
            // Filter anchors, looking for jumps, which are assumed to be
            // anchors with an href like #SomethingHappened.
            "target": jQuery('a[href^=#]').filter(function () {
                'use strict';
                // Fine tuned the matching here. Previously only legit anchors used the
                // href="#blah" format. Now that we've integrated ui-tabs, this isn't always true.
                // The .ui-tabs ancestor should indicate that we don't want the jump to occur.
                // Additionally, I've added a class .nojump that can be applied to any element
                // to automatically disable this jump functionality.
                return this.href.match(/#(.)*/) && jQuery(this).parents('.ui-tabs').length < 1 && !jQuery(this).hasClass('nojump');
            }),
            "offset": function() {
                var offset;
                if (jQuery("div.mobile-nav").height() > 0) {
                    offset = jQuery("div.mobile-nav").position().top + jQuery("div.mobile-nav").outerHeight(true); 
                } else {
                    offset = jQuery("div.mainMenu  nav.topical-nav").position().top + jQuery("div.mainMenu  nav.topical-nav").outerHeight(true);
                }
                return offset; 
            },
            "duration": 250,
            "onready": true
        });
    }, 400);
});
