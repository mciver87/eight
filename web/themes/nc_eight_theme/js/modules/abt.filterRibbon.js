$( function()
{
    $.fn.filterRibbon = function(){
		var $filterPicker = $('.filter-ribbon .field-group');
		var $options = $('.filter-ribbon select');

		$.each($options, function(index, val){

		});
		$('.filter-ribbon .filter').on('click', 'button', function(){
			$('.filter-ribbon .field-group').addClass('active');
		});

		

    };
});

