(function($) {
    'use strict';

    $.fn.accordionToTabs = function (options) {
        return this.each(function () {
            var $element = $(this);
            $element.uniqueId();
            // only perform action if the element is an accordion
            if ($element.is('.ui-accordion')) {
                var ids = [];
                // set up the divs
                var divs = $('');
                $element.find('>div').each(function() {
                    var newDiv = $('<div>' + $(this).html() + '</div>');
                    var heading = String($('h2',$(this)).text().trim().toLowerCase()).replace(/\s/g, '-');
                    // assign id to the div 
                    newDiv.attr('id', heading);
                    ids.push(heading);
                    divs = divs.add(newDiv);
                });
                // create the ul for the tabs
                var links = $('<ul>');
                $element.find('>a').each(function(aIndex) {
                    links.append('<li><a href="#' + ids[aIndex] + '">' + $(this).text() + '</a></li>');
                });

                $element.accordion('destroy')
                    .empty()
                    .append(links)
                    .append(divs)
                    .removeClass('abt-accordion')
                    .addClass('abt-tabs');

                $element.tabs(options);
            }
            $('body .abt-tabs > ul > li > a').matchHeight();
        });
    };

    $.fn.tabsToAccordion = function (options) {
        return this.each(function () {
            var $element = $(this);
            $element.uniqueId();
            // only switch if the element has tabs
            if ($element.is('.ui-tabs')) {
                var divs = $element.find('>div');
                var lis = $element.find('>ul>li');

                $element.tabs('destroy')
                    .empty()
                    .removeClass('abt-tabs')
                    .addClass('abt-accordion');

                lis.each(function(i) {
                    var div = $('<div>' + $(divs[i]).html() + '</div>');
                    $element.append($(this).html())
                        .append(div);
                });

                $element.accordion(options);
            }
        });
    };

    Drupal.behaviors.abtAccordions = {
        attach: function(context, settings) {

            var accordionSettings = {
                heightStyle: "content",
                navigation: true,
                autoHeight: false,
                collapsible: true,
                animate: 300,
                create: function(event, ui) {
                    var current = window.location.hash;
                    $(".ui-accordion-header").each(function(){
                        var accordionHeader = $(this);
                        var accordionHeaderId = accordionHeader.text().trim().toLowerCase().replace(/\s/g, '-');
                        accordionHeader.attr('id', accordionHeaderId);
                    });
                    var firstAccordionHeader = $('.ui-accordion-header:first').first().attr('ID');
                    var firstHash = current.split('#')[1];
                    if (firstAccordionHeader !== firstHash) {
                        $(current).trigger('click');
                    }
                },
                activate: function( event, ui ) {
                    var offset = $("div.mobile-nav").height() > 0 ?
                        $("div.mobile-nav").position().top + $("div.mobile-nav").outerHeight(true) :
                        $("div.mainMenu  nav.topical-nav").position().top + $("div.mainMenu  nav.topical-nav").outerHeight(true);
                    if(!$.isEmptyObject(ui.newHeader.offset())) {
                        $('html:not(:animated), body:not(:animated)').animate({ scrollTop: ui.newHeader.offset().top - offset }, 'fast');
                    }
                    if (typeof ui.newHeader.attr('id') !== 'undefined') {
                        window.location.hash = ui.newHeader.attr('id');
                    }
                }
            };

            var tabSettings = {
                heightStyle: "content",
                navigation: true,
                activate: function(event, ui) {
                    window.location.hash = ui.newPanel.attr('id');
                    var offset = $("div.mainMenu  nav.topical-nav").position().top + $("div.mainMenu  nav.topical-nav").outerHeight(true);
                    $('html, body').animate({
                        scrollTop: $('.ui-tabs-nav').offset().top - offset
                    }, 'fast');
                }
            };

            $('.abt-accordion, .abt-tab-accordion').accordion(accordionSettings);
            enquire.register('screen and (min-width: 1024px)', {
                match: function() {
                    $('body .abt-tab-accordion').accordionToTabs(tabSettings);
                },
                unmatch: function() {
                    $('body .abt-tab-accordion').tabsToAccordion( accordionSettings);
                }
            });
        }
    };
})(jQuery);
