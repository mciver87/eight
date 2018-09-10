/**
 * @file
 * A JavaScript file for the theme.
 *
 * In order for this JavaScript to be loaded on pages, see the instructions in
 * the README.txt next to this file.
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - https://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {
  Drupal.behaviors.flyoutMenu = {
    attach: function (context, settings) {

      $('body').on('mouseup', '.paginate_button:not(.disabled)', function(){
        $('html,body').animate({
          scrollTop: $('.dataTables_wrapper').offset().top
        }, 'slow');
      });

      // Desktop navigation
      $mainMenu = $('#mainMenu');
      if (navigator.appVersion.indexOf("MSIE 8.") != -1) {
        $mainMenu.removeClass('flyout-panel');
        if (!Modernizr.svg) {
          var imgs = document.getElementsByTagName('img');
          var svgExtension = /.*\.svg$/
          var l = imgs.length;
          for (var i = 0; i < l; i++) {
            if (imgs[i].src.match(svgExtension)) {
              imgs[i].src = imgs[i].src.slice(0, -3) + 'png';
            }
          }
        }
      }
      enquire.register('screen and (min-width: 1024px)', {
        match: function() {
          $mainMenu.removeClass('flyout-panel');
          $('.enterprise-nav').css({'position': ''});
          $('body').removeClass('no-scroll');
        },
        unmatch: function() {
          $mainMenu.addClass('flyout-panel');
          // remove desktop styles applied for mega menus
          $('*', $mainMenu).attr({
            'style': ''
          });
        },
        setup: function() {
          $mainMenu.addClass('flyout-panel');
        }
      });

      var $panel = $mainMenu;
      var $firstPanel = $panel.children('div');

      resizedw();
      function resizedw() {
        if (calculateContents($firstPanel)) {
          $panel.addClass('contents-less');
        }
      }

      
      $('body', context).once('initMenuClickHandlers', function () {
        // Code here will only be applied to $('#some_element')
        // a single time.
        var myTimeout = setTimeout(function () {
          initMegaMenu();
          initDropdownMenu();
        }, 10);
      });

      var doit;
      window.addEventListener("resize", function () {
        clearTimeout(doit);
        doit = setTimeout( function() {
          resizedw();
          setMenuWidth();
        }, 100);
      }, false);

      window.addEventListener("orientationchange", function () {
        resizedw();
      }, false);

      $('.flyout-trigger.open-trigger', context).on('click', function () {
        $panel.addClass('active');
        $firstPanel.addClass('active');
        $('body').addClass('no-scroll');
        // This is a hack to make the flyout nav more accessible for users who zoom in with the browser.
        if($('.flyout-panel').outerHeight(true) < ($('.enterprise-nav').outerHeight(true) + $('.topical-nav').outerHeight(true) + $('.close-trigger').outerHeight(true))) {
          //Set scrollable topical-nav if both don't fit.
          //$('.topical-nav').height($('.flyout-panel').outerHeight(true) - $('.enterprise-nav').outerHeight(true) - $('.close-trigger').outerHeight(true)).css({'overflow': 'scroll'})
          //Don't have the enterprise nav absolute to bottom if there isn't enough room for the topical-nav.
          $('.enterprise-nav').css({'position': 'relative'});
        }
      });

      $('.flyout-trigger.close-trigger', context).on('click', function () {
        $firstPanel.removeClass('active');
        if (navigator.appVersion.indexOf("MSIE 9.") != -1) {
          $panel.find('.active').removeClass('active');
          $panel.find('.sub-active').removeClass('sub-active');
          $panel.removeClass('active').removeClass('sub-active');
          $('body', context).removeClass('no-scroll');
        }
      });

      $('.flyout-trigger.back-trigger', context).on('click', function (e) {
        $(e.target).closest('div').removeClass('active').parent('li').closest('div').removeClass('sub-active');
      });

      $panel.find('a').on('click', function (e) {
        if ($(e.target).closest('li').children('div').length) {
          $(e.target).closest('div').scrollTop(0); //scroll parent panel up to avoid cutoff content
          $(e.target).closest('li').children('div').addClass('active');
          $(e.target).parentsUntil('.flyout-panel', 'div').addClass('sub-active');
        }
      });

      $panel.on('click', function (e) {
        if ($(e.target).hasClass('flyout-panel')) {
          $firstPanel.removeClass('active');
          if (navigator.appVersion.indexOf("MSIE 9.") != -1) {
            $panel.find('.active').removeClass('active');
            $panel.find('.sub-active').removeClass('sub-active');
            $panel.removeClass('active').removeClass('sub-active');
            $('body').removeClass('no-scroll');
          }
        }
      });

      function removeCoverIE() {
        if(!$firstPanel.hasClass('active')) {
          $panel.find('.active').removeClass('active');
          $panel.find('.sub-active').removeClass('sub-active');
          $panel.removeClass('active').removeClass('sub-active');
          $('body').removeClass('no-scroll');
        }
      }
      $firstPanel.on('webkitTransitionEnd otransitionend oTransitionEnd msTransitionEnd transitionend',
        function (e) {
          if (!$firstPanel.hasClass('active')) {
            $panel.find('.active').removeClass('active');
            $panel.find('.sub-active').removeClass('sub-active');
            $panel.removeClass('active').removeClass('sub-active');
            $('body').removeClass('no-scroll');
          }
        });

      function calculateContents(element) {
        var firstPanelHeight = 0;
        element.children().each(function () {
          firstPanelHeight += $(this).outerHeight();
        });
        if (firstPanelHeight < $(window).height()) {
          return true;
        }
        return false;
      }

      var $megaMenuItems, $dropdownMenuItems, $navContainer;
      $navContainer = $('.topical-nav > ul');
      $megaMenuItems = $('.has-mega');
      $dropdownMenuItems = $('.has-dropdown');

      function initMegaMenu() {
          setMenuWidth();
      }
      function setMenuWidth() {
        if ($('.topical-nav').length) {
          var navWidth = $('.topical-nav').outerWidth();
          var navOffset = $navContainer.position().left;

          $.each($megaMenuItems, function(index, val){
            $('> div', val).css({
              'width': navWidth,
              'left': - ($(this).position().left)
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

              // Target only the second level items
              $('.has-mega.is-open > div > ul > li').matchHeight({
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
      function DesktopMenuClickHandler(e) {
        var overflowMenuCheck = $(e.target).parents('.jb-overflowmenu-menu-secondary').length;
        if ( overflowMenuCheck === 0) {
          // don't fire main nav items with dropdown or mega(including chevron icon)
          if( $(e.target).hasClass('icon-chevron-right') || $(e.target).parent('li').hasClass('has-dropdown') ) {
            if( !$(e.target).next('.third-level').length ) {
              e.preventDefault();
            }
          }
        }
      }
      function MobileMenuClickHandler(e) {
        if( $(e.target).hasClass('icon-chevron-right') || $(e.target).parent('li').hasClass('has-dropdown') ) {
          e.preventDefault();
        }
      }
      enquire.register('screen and (min-width: 1024px)', {
        match: function() {
          $('body').on('click', '.has-dropdown', DesktopMenuClickHandler);
        },
        unmatch: function() {
          $('body').off('click', '.has-dropdown', DesktopMenuClickHandler);
        }
      });
      enquire.register('screen and (max-width: 1023px)', {
        match: function() {
          $('body').on('click', '.has-dropdown', MobileMenuClickHandler);
        },
        unmatch: function() {
          $('body').off('click', '.has-dropdown', MobileMenuClickHandler);
        }
      });
    }
  };
})(jQuery, Drupal, this, this.document);

/**
 * Tooltips JS.
 */
(function ($, Drupal, window, document, undefined) {
  Drupal.behaviors.tooltips = {
    attach: function (context, settings) {
      var targets = $( '[rel~=tooltip]' ),
        target  = false,
        tooltip = false,
        title   = false;

      targets.bind( 'mouseenter', function()
      {
        target  = $( this );
        tip     = target.attr( 'title' );
        tooltip = $( '<div id="tooltip" class="'+target.attr('class')+'"></div>' );

        if( !tip || tip == '' )
          return false;

        target.removeAttr( 'title' );
        tooltip.css( 'opacity', 0 )
          .html( tip )
          .appendTo( 'body' );

        var init_tooltip = function()
        {
          if( $( window ).width() < tooltip.outerWidth() * 1.5 )
            tooltip.css( 'max-width', $( window ).width() / 2 );
          else
            tooltip.css( 'max-width', 340 );

          var pos_left = target.offset().left + ( target.outerWidth() / 2 ) - ( tooltip.outerWidth() / 2 ),
            pos_top  = target.offset().top - tooltip.outerHeight() - 30;

          if( pos_left < 0 )
          {
            pos_left = target.offset().left + target.outerWidth() / 2 - 20;
            tooltip.addClass( 'left' );
          }
          else
            tooltip.removeClass( 'left' );

          if( pos_left + tooltip.outerWidth() > $( window ).width() )
          {
            pos_left = target.offset().left - tooltip.outerWidth() + target.outerWidth() / 2 + 20;
            tooltip.addClass( 'right' );
          }
          else
            tooltip.removeClass( 'right' );

          if( pos_top < 0 )
          {
            var pos_top  = target.offset().top + target.outerHeight();
            tooltip.addClass( 'top' );
          }
          else
            tooltip.removeClass( 'top' );

          tooltip.css( { left: pos_left, top: pos_top } )
            .animate( { top: '+=10', opacity: 1 }, 50 );
        };

        init_tooltip();
        $( window ).resize( init_tooltip );

        var remove_tooltip = function()
        {
          tooltip.animate( { top: '-=10', opacity: 0 }, 50, function()
          {
            $( this ).remove();
          });

          target.attr( 'title', tip );
        };

        target.bind( 'mouseleave', remove_tooltip );
        tooltip.bind( 'click', remove_tooltip );
      });
    }
  }
})(jQuery, Drupal, this, this.document);

(function ($, Drupal, window, document, undefined) {
  Drupal.behaviors.northCarolinaCustom = {
    attach: function (context, settings) {

      // Masked inputs
      $('input[type="tel"]').mask('(999) 999-9999');

      // Autoresize textarea
      $('textarea').autosize();

      // Initialize modals/popups
      $('.card.video > a').magnificPopup({
        disableOn: 700,
        type: 'iframe',
        mainClass: 'mfp-fade',
        removalDelay: 160,
        preloader: false,
        fixedContentPos: false
      });
      $('.open-popup-link').magnificPopup({
        type: 'inline',
        midClick: true
      });
      $('.ajax-popup-link').magnificPopup({
        type: 'ajax'
      });
      $('[data-toggle="modal image"]').magnificPopup({
        type: 'image',
        removalDelay: 500,
        callbacks: {
          beforeOpen: function() {
            this.st.image.markup = this.st.image.markup.replace('mfp-figure', 'mfp-figure mfp-with-anim');
            this.st.mainClass = this.st.el.attr('data-effect');
          }
        },
        closeOnContentClick: true,
        midClick: true
      });

      /*
       * Auto-resize video embeds.
       */
      $('body').fitVids();

      // From abt.progress.js
      $.fn.setProgress = function(value,total){
        total = total || 100;
        $(this).attr({'aria-valuenow': value, 'aria-valuetext': value})
          .find('.progress-now').css({'width': value+'%'}).end()
          .find('.progress-text').text(value+'%');
      };

      /*
       * Initialize DataTables.
       */
      if ($('.enableDT').length) {
        $('.enableDT').DataTable({
          responsive: true
        });
      }

      /*
       * Scroll to top of document
       */
      $('#back-to-top').click(function() {
        var src = $(this).attr('href');

        $('html, body').animate({
          scrollTop: $(src).offset().top,
          easing: 'easeInOutQuart'
        }, 1000);

        return false;
      });

      // Match heights of cards by row. Includes resize and throttle in master .
      var mh_options = {
        byRow: true,
        property: 'height',
        target: null,
        remove: false
      };

      $('.equal-blocks div').matchHeight(mh_options);
      $('.band .link-lists').matchHeight(mh_options);
      $('.card.service').matchHeight(mh_options);
      $('.card.event').matchHeight(mh_options);
      $('.card.article').matchHeight(mh_options);
      $('.card.cta').matchHeight(mh_options);
      $('.card.person').matchHeight(mh_options);
      $('.card.govt').matchHeight(mh_options);

      function initStickyHeader() {
        // Pin desktop menu
        var controller;
        var scene;

        enquire.register('screen and (min-width: 1024px)', {
          match: function() {
            controller = new ScrollMagic.Controller({
              loglevel: 0
            });
            scene = new ScrollMagic.Scene({
              offset: $('.enterprise-nav').height()
            })
              .setPin("nav.topical-nav", {
                pushFollowers: false
              })
              .addTo(controller);
          },
          unmatch: function() {
            controller = controller.destroy(true);
            scene = scene.destroy();
          }
        });
      }
      
      $('body', context).once('initstickyheader', function () {
        // Code here will only be applied to $('#some_element')
        // a single time.
        
        // Detect if topical nav exists(don't load on alt theme)
        if($('nav.topical-nav').length) {
          initStickyHeader();
        }
        
      });

      /*
       * Toggle breadcrumbs.
       */
      $('#breadcrumb button').on('click', function() {
        $(this).toggleClass('active');
        $('.breadcrumbs').toggleClass('active');
      });
      // Fallback for really long breadcrumbs that 
      // take up more than two lines.
      var $breadcrumbs = $('.breadcrumbs');
      function breadcrumbHeightCheck() {
        if( $breadcrumbs.height() < $('.breadcrumbs div').height() ) {
          $breadcrumbs.addClass('tall-breadcrumbs');
        }
        else {
          $breadcrumbs.removeClass('tall-breadcrumbs');
        }
      }
      function resizeBreadcrumbCheck() {
        debounce(breadcrumbHeightCheck(), 100)
      }
      // Init fallback check
      breadcrumbHeightCheck();
      $(window).resize(resizeBreadcrumbCheck);

      // Toggle user feedback
      if ($('#user-feedback').length) {
        $('input[name="submitted[page_submitted]"]').val(window.location.pathname);
      }

      $('#user-feedback .toggle-trigger', context).on('click', function() {
        $('#user-feedback .toggle-container').slideDown({
          duration: 250,
          easing: 'easeInOutQuart'
        });
      });
      $('#user-feedback .toggle-escape', context).on('click', function() {
        $('#user-feedback .toggle-container').slideUp({
          duration: 250,
          easing: 'easeInOutQuart'
        });
      });

      // Language Switcher
      $('.lng-tgl > .icon-container', context).on('click', function() {
        $(this).next('.block-lang-dropdown').slideToggle('fast');
      });

      // Section Nav
      $('.section-nav a.active').removeClass('active');

      // Toggle Search Options
      $('#filter-options-toggle').click(function() {
        $(this).toggleClass('ghost');
        $('#filter-options').toggleClass('is-hidden');
      });
      enquire.register('screen and (min-width: 1024px)', {
        match: function() {
          $('#filter-options-toggle').hide();
          $('#filter-options').removeClass('is-hidden');
        },
        unmatch: function() {
          $('#filter-options-toggle').show();
          $('#filter-options').addClass('is-hidden');
        },
        setup: function() {
          $('#filter-options-toggle').show();
          $('#filter-options').addClass('is-hidden');
        }
      });
      $('.search-trigger').on('click', function(e) {
        $('.header-search').toggleClass('is-toggled');
        $(this).toggleClass('is-toggled');

        if ($('.header-search').hasClass('is-toggled')) {
          $('.header-search input[type="search"]').focus();
        }
      });

      $('#searchToggle').on('click', function(e) {
        $('.header-search').toggleClass('is-toggled');
        // $(this).toggleClass('is-toggled');

        if ($('.header-search').hasClass('is-toggled')) {
            $('.header-search input[type="search"]').focus();
        }
      });
      
      // Initialize Document Revision History Toggle
      var revToggle = $('#doc-history-toggle'),
        revInfo = $('#doc-history-info');

      if (revToggle.length && revInfo.length) {
        var revCount = revInfo.find('li').length;

        // Add counter
        revToggle.find('a').after(' (' + revCount + ')');

        // Hide history
        revInfo.addClass('visuallyhidden');

        // Toggle history
        revToggle.find('a').click(function() {
          revInfo.toggleClass('visuallyhidden');
          return false;
        });
      }

      // Scope overflow menu setup to only run once
      function initOvermenuSetup() {
        var $topicalNav = $('.topical-nav')
        // Initialize Topical Menu Overflow
        function overflowmenu_extension() {
          $topicalNav.addClass('jb-overflow-disabled');

          // Detect overflow menu to see if items exist
          if ( $('.jb-overflowmenu-menu-secondary > li').length ) {
            // If container has items, show it
            $topicalNav.overflowmenu('refresh');
            $topicalNav.removeClass('jb-overflow-disabled');
            $topicalNav.overflowmenu('refresh');
          }

        }
        function resizeOverflow() {
          throttle(overflowmenu_extension(), 50);
          throttle($topicalNav.overflowmenu('refresh'), 50);
        }

        enquire.register('screen and (min-width: 1024px)', {
          match: function() {
            // Setup Overflow Menu
            $topicalNav.overflowmenu({
              label: ''
            });

            // trigger b/c safari seems slow to pickup extra items
            setTimeout(function(){
              $topicalNav.overflowmenu('refresh')
              overflowmenu_extension()
            }, 200);

            // Setup Overflow Menu Extension
            overflowmenu_extension();
            $(window).resize(resizeOverflow);
          },
          unmatch: function() {
            $(window).off("resize", resizeOverflow);
            $topicalNav.overflowmenu('refresh');
            $topicalNav.overflowmenu('destroy');
          }
        });
      }

      $('body', context).once('initoverflowmenu', function () {
        initOvermenuSetup();
      });

      // Debounce.
      function debounce(func, wait, immediate) {
        var timeout;
        return function() {
          var context = this, args = arguments;
          var later = function() {
            timeout = null;
            if (!immediate) func.apply(context, args);
          };
          var callNow = immediate && !timeout;
          clearTimeout(timeout);
          timeout = setTimeout(later, wait);
          if (callNow) func.apply(context, args);
        };
      }
      // Returns a function, that, when invoked, will only be triggered at most once
      // during a given window of time. Normally, the throttled function will run
      // as much as it can, without ever going more than once per `wait` duration;
      // but if you'd like to disable the execution on the leading edge, pass
      // `{leading: false}`. To disable execution on the trailing edge, ditto.
      var throttle = function(func, wait, options) {
        var timeout, context, args, result;
        var previous = 0;
        if (!options) options = {};

        var later = function() {
          previous = options.leading === false ? 0 : _.now();
          timeout = null;
          result = func.apply(context, args);
          if (!timeout) context = args = null;
        };

        var throttled = function() {
          var now = _.now();
          if (!previous && options.leading === false) previous = now;
          var remaining = wait - (now - previous);
          context = this;
          args = arguments;
          if (remaining <= 0 || remaining > wait) {
            if (timeout) {
              clearTimeout(timeout);
              timeout = null;
            }
            previous = now;
            result = func.apply(context, args);
            if (!timeout) context = args = null;
          } else if (!timeout && options.trailing !== false) {
            timeout = setTimeout(later, remaining);
          }
          return result;
        };

        throttled.cancel = function() {
          clearTimeout(timeout);
          previous = 0;
          timeout = context = args = null;
        };

        return throttled;
      };

      // Add loading message on Info and Services view.
      $('.page-services #filter-options form').on('submit', function(){
        $('.filter-results-stats').addClass('loading')
      });
    }
  };
})(jQuery, Drupal, this, this.document);

// reCapatcha fix.
(function ($, Drupal, window, document, undefined) {
  Drupal.behaviors.recapcha_ajax_behaviour = {
    attach: function(context, settings) {
      if (typeof grecaptcha != "undefined") {
        var captchas = document.getElementsByClassName('g-recaptcha');
        for (var i = 0; i < captchas.length; i++) {
          var site_key = captchas[i].getAttribute('data-sitekey');
          if (!$(captchas[i]).html()) {
            grecaptcha.render(captchas[i], { 'sitekey' : site_key});
          }
        }
      }
    }
  }
})(jQuery, Drupal, this, this.document);