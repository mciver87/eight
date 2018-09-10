(function ($) {

    var offset;
    function nc_toc_init(evt) {
        offset = jQuery("div.mobile-nav").height() > 0 ?
              jQuery("div.mobile-nav").position().top + jQuery("div.mobile-nav").outerHeight(true) :
              jQuery("div.mainMenu nav.topical-nav").position().top + jQuery("div.mainMenu nav.topical-nav").outerHeight(true);
        
        $('.toc-links').each(function(){
            var tocElement = this;
            $(this).empty(); //clear out list      
            if($(this).closest('.tab-side').length) {
                nc_toc_traverse_content($(this).closest('.tab-side').siblings('.tab-main'), tocElement);
            }
            if(!$(this).closest('.tab-side').length && $(this).closest('#sidebar-second').length) {
                nc_toc_traverse_content($(this).closest('#sidebar-second').prevUntil('#primary-content'), tocElement);
            }
        });
    };

    function nc_toc_traverse_content($content, $element) {
        $content.find(':header:has(a:not([href]))').each(function(index){
            var list = document.createElement( "li" );
            var target = $(this).find('a').attr('id');
            var link = $('<a>', {
                text: index + 1 + '. ' + $(this).text(),
                title: $(this).text(),
                href: '#'+target,
                click: function(e){
                    e.preventDefault();
                    nc_toc_scroll_to_results($content.find('#'+target), 250, offset);
                }
            } );
            link.appendTo(list);
            $element.append(list);
        });
    };

    function nc_toc_scroll_to_results(target, duration, offset) {
        $("body, html").stop().animate({
            scrollTop: target.offset().top - offset
        }, duration);
    };

    Drupal.behaviors.nc_table_of_contents = {
      attach: function (context, settings) {
        $(document).ready(function(){
            nc_toc_init();
        });
      }
    };
}(jQuery));