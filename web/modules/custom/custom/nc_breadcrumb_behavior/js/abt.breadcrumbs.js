(function($) {
	'use strict';
	/**
	 * Decorates the breaddrumbs.
	 * Adds additional behavior. Truncates long breadcrumbs. Hides all if long
	 * trails are detected.
	 *
	 * Options:
	 * > maxSegmentLength (int) - Max length of characters in crumb before truncating it. Set to 0 to ignore.
	 * > appendTruncated (string) - Append to truncated crumbs.
	 * > outerWrapper (object/array) - Outer element.
	 * > breadcrumbs(object/array) - The crumbs.
	 *
	 * @param opts
	 * @returns {{run: init}}
	 * @constructor
	 */
	var DefaultBreadcrumbsDecorator = function(opts) {
		var opts = $.extend({}, {
				"truncateSegments" : 'enable',
				"maxSegmentLength": 24,
				"appendTruncated": "&hellip;",
				"outerWrapper": $('div#breadcrumb'),
				"breadcrumbs": $('div#breadcrumb a'),
				"childSelector": '[itemprop="child"]'
			}, opts),
			truncateSegments = opts.truncateSegments,
			maxSegmentLength = opts.maxSegmentLength,
			appendTruncated = opts.appendTruncated,
			outerWrapper = opts.outerWrapper,
			breadcrumbs = opts.breadcrumbs,
			childSelector = opts.childSelector,
			breadcrumbCount = 0,
			breadcrumbLength = 0;
		
		/**
		 * Initialize the main functionality.
		 */
		var init = function() {
			// Iterate through each breadcrumb item, truncate if necessary.
			breadcrumbs.each(function(index, element) {
				$(this).find(childSelector).each(function(index, element) {

					var titleElem = $(this),
						title = titleElem.text(),
						truncTitle = maxSegmentLength > 0 ? title.substring(0,
							maxSegmentLength) : title;
					if (truncateSegments === 'enable') {
						titleElem.html((truncTitle.length < title.length ?
						truncTitle + appendTruncated : title));
					}
					breadcrumbLength += titleElem.text().length;
					breadcrumbCount++;
				});
			}).promise().done(function() {});
		};
		/**
		 * Return object / public functionality.
		 */
		return {
			"run": init
		};
	};
	Drupal.behaviors.abtBreadcrumbs = {
		attach: function(context, settings) {
			// If the expand control is added elsewhere, remove these lines.
			// They are only being used to add a demo control element to the page.
			// Also, be sure to update expandElem selector below in defaults if
			// the id of your control is not reveal-breadcrumbs.

			// This is where the magic begins.
			var defaults = {
					"truncateSegments" : 'enable',
					"maxSegmentLength": 24,
					"appendTruncated": "&hellip;",
					"outerWrapper": $('div#breadcrumb'),
					"breadcrumbs": $('div#breadcrumb div[itemprop="child"]'),
					"childSelector": '[itemprop="title"]'
				},
				opts = $.extend({}, defaults, (settings.abtBreadcrumbs || {})),
				decorator = new DefaultBreadcrumbsDecorator(opts);
				
				if($(document).width() >= 1028) {
					decorator.run();
				}
		}
	};
})(jQuery);