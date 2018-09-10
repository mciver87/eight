$( function()
{
    var $panel = $('.flyout-panel');
    var $firstPanel = $panel.children('div');


	resizedw();
	function resizedw(){
    	if(calculateContents($firstPanel)) {
			$panel.addClass('contents-less');
		}
	}

	var doit;
	window.addEventListener("resize", function(){
		clearTimeout(doit);
		doit = setTimeout(resizedw, 100);
	}, false);

	window.addEventListener("orientationchange", function() {
		resizedw();
	}, false);

    $('.flyout-trigger.open-trigger').on('click', function() {
		$panel.addClass('active');
        $firstPanel.addClass('active');
		$('body').addClass('no-scroll');
    });

    $('.flyout-trigger.close-trigger').on('click', function() {
		$firstPanel.removeClass('active');
		if (navigator.appVersion.indexOf("MSIE 9.") != -1) {
            	$panel.find('.active').removeClass('active');
	    		$panel.find('.sub-active').removeClass('sub-active');
				$panel.removeClass('active').removeClass('sub-active');
				$('body').removeClass('no-scroll');
			}
    });

    $('.flyout-trigger.back-trigger').on('click', function(e) {
        $(e.target).closest('div').removeClass('active').parent('li').closest('div').removeClass('sub-active');
    });

    $panel.find('a').on('click', function(e) {
        if ($(e.target).closest('li').children('div').length) {
        	if($panel.hasClass('flyout-panel') && !$(e.target).parents('.jb-overflowmenu-menu-secondary').length) {
        		e.preventDefault();
        	}

            $(e.target).closest('div').scrollTop(0); //scroll parent panel up to avoid cutoff content
            $(e.target).closest('li').children('div').addClass('active');
            $(e.target).parentsUntil('.flyout-panel', 'div').addClass('sub-active');
        }
    });
    
    $panel.on('click', function(e) {
        if( $(e.target).hasClass('flyout-panel') ) {
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
		function(e) {
		if(!$firstPanel.hasClass('active')) {
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

});
