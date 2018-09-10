
// require('../../js/vendors/jquery.selectBoxIt.min.js')

// var init = function() {
// 	var $allTheSelects = $('.select');

// 	// $allTheSelects.each(function(){
// 	// 	var $tempThis = $(this);
// 	// 	attachEvents($tempThis);
// 	// 	$tempThis.append(createOptionList($tempThis.find('select').hide()));
// 	// });

	
// };

// // var createOptionList = function(selectItem) {
// // 	var $returnUL = $('<ul/>');

// // 	// console.log($(selectItem).find('option'))
// // 	$(selectItem).find('option').each(function(){
// // 		$returnUL.append('<li data-value="'+this.value+'">'+this.value+'<span class="icon-check" aria-hidden="true"></span></li>');
// // 	});
// // 	// $returnUL.wrapAll('<div></div>');
// // 	var $tempDiv = $('<div><span class="icon-expand-more" aria-hidden="true"></span></div>');
// // 	$tempDiv.append($returnUL);
// // 	return $tempDiv;
// // };

// // var attachEvents = function($element) {

	
// // 	$element.on('click', 'label, div', function(e) {
// // 		$(this).parent().toggleClass('is-open');
// // 	});
// // 	$element.on('click', 'li', function(e) {
// // 		$element.find('li').removeClass('selected');
// // 		$element.find('option').removeAttr('selected');
// // 		$element.find('option[value="'+$(this).attr('data-value')+'"]').attr('selected','selected');
// // 		$(this).addClass('selected');
// // 		// $(this).parents('.select').toggleClass('is-open has-selected');
// // 		$(this).parents('.select').addClass('has-selected');
// // 	});
// // };

// exports.init = init;