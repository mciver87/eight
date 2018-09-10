$(function() {

    var myTimeout = setTimeout(function() {
        initMegaMenu();
        initDropdownMenu();
    }, 10);

    var doit;
    var mh_options = {
        byRow: true,
        property: 'height',
        target: null,
        remove: false
    }

    window.addEventListener("resize", function() {
        clearTimeout(doit);
        doit = setTimeout(setMenuWidth, 100);
    }, false);

    var $megaMenuItems, $dropdownMenuItems, $navContainer;
    $navContainer = $('.topical-nav > ul');
    $megaMenuItems = $('.has-mega');
    $dropdownMenuItems = $('.has-dropdown');

    function initMegaMenu() {
        setMenuWidth();
    }

    function setMenuWidth() {
        if ( $('.topical-nav').length ) {
            var navWidth = $('.topical-nav').outerWidth(),
                navOffset = $navContainer.position().left;

            $.each($megaMenuItems, function(index, val) {
                $('> div', val).css({
                    'width': navWidth,
                    'left': -($(this).position().left)
                });
            });    
        }
    }

    function initDropdownMenu() {
        $('body').on('click', function(e) {
            if ($dropdownMenuItems.hasClass('is-open') && !$(e.target).parents('.has-dropdown').length && !$(e.target).hasClass('has-dropdown')) {
                $('.is-open').removeClass('is-open');
            }
            if($('.jb-overflowmenu-menu-secondary:visible').length == 1 && !$(e.target).hasClass('jb-overflowmenu-menu-secondary-handle') ) {
                $('.topical-nav').overflowmenu('close');
            }
        });
        
        $('body').on('click', '.has-dropdown', function(e) {
            var overflowMenuCheck = $(e.target).parents('.jb-overflowmenu-menu-secondary').length;
            if ( overflowMenuCheck === 0) {
                // don't fire main nav items with dropdown or mega(including chevron icon)
                if($(e.target).hasClass('icon-chevron-right') || $(e.target).parent('li').hasClass('has-dropdown')) {
                    e.preventDefault();
                }

                if($('.topical-nav').hasClass('jb-overflow-menu')) {
                    $('.topical-nav').overflowmenu('close');
                }                

                if ($(this).hasClass('is-open')) {
                    $(this).removeClass('is-open');
                    $('.has-mega li').attr('style', '');
                }
                else {
                    $('.is-open').removeClass('is-open');
                    $(this).addClass('is-open');

                    $('.has-mega.is-open li').matchHeight({
                        byRow: true,
                        property: 'height',
                        target: null,
                        remove: false
                    });

                    $('.has-mega.is-open [class^="span-"]').matchHeight({
                        byRow: true,
                        property: 'height',
                        target: null,
                        remove: false
                    });
    
                }
            }
        });
    }
});
