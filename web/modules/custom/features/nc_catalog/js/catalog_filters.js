(function ($) {
  Drupal.behaviors.catalogPager = {
    attach: function (context, settings) {
      // var allowPager = Drupal.settings.catalogPager.allowPager;
      // var pagerItems = Drupal.settings.catalogPager.items;
      // var viewAllSetting = Drupal.settings.catalogPagerViewAll.viewAll;
    }
  }
  Drupal.behaviors.catalogSearch = {
    attach: function (context, settings) {
      var searchList = new List('search-wrapper', {
        valueNames: ['keywords', 'term-keywords'],
        location: 0,
        distance: 500,
        threshold: 1.0,
      });
    }
  }
  Drupal.behaviors.catalogFiltersResizeCheckboxes = {
    attach: function (context, settings) {
      // Loop through all filter options and resize any of the groups which have
      // more than 10 items.
      $('.nc-catalog-page #filter-options .form-type-checkboxes').each(function(){
        var numberOfCheckboxes = $(this).children('.form-checkboxes').children('div').length;
        if (numberOfCheckboxes > 6) {
          $(this).children('.form-checkboxes').css({
            height: "12em",
            overflowY: "scroll",
            webkitOverflowScrolling: "touch",
            overflowX: "hidden"
          });
          $(this).children('.form-checkboxes').attr('tabindex', 0);
        }
      });
    }
  }
  function getCommonElements(arrays){
    //Assumes that we are dealing with an array of arrays of integers
    var currentValues = {};
    var commonValues = {};
    for (var i = arrays[0].length-1; i >=0; i--){
      //Iterating backwards for efficiency
      currentValues[arrays[0][i]] = 1;
      //Doesn't really matter what we set it to
    }
    for (var i = arrays.length-1; i>0; i--){
      var currentArray = arrays[i];
      for (var j = currentArray.length-1; j >=0; j--){
        if (currentArray[j] in currentValues){
          commonValues[currentArray[j]] = 1;
          //Once again, the `1` doesn't matter
        }
      }
      currentValues = commonValues;
      commonValues = {};
    }
    return Object.keys(currentValues).map(function(value){
      return parseInt(value);
    });
  }
  Drupal.behaviors.catalogFilters = {
    attach: function (context, settings) {
      $('.nc-catalog-page #filter-options input[type=checkbox]').change(function(e){
        var visibleNodes = new Array();
        var visibleGroupedNodes = new Array();
        var visibleFilters = new Array();
        // Unset the visible class for all items.
        $('.results .node').parent('li').removeClass('display-node');
        // Get all selected values.
        var catalogFilterData = Drupal.settings.catalog_filter_data;
        var numChecked = $('.nc-catalog-page #filter-options input[type=checkbox]:checked').length;
        var mapreduceArray = new Object();
        $('.nc-catalog-page #filter-options input[type=checkbox]:checked').each(function(i){
          // Only do special processing if more than one item is checked.
          var currentValue = this.value;
          if (numChecked > 1) {
            var visibleNodesForThisGroup = new Array();
            // Create an array of node ids per-term.
            catalogFilterData[currentValue].forEach(function(nid){
              visibleNodesForThisGroup.push(nid);
            });
            visibleGroupedNodes.push(visibleNodesForThisGroup);
          }
          else {
            // Build a "visible nodes" list.
            catalogFilterData[currentValue].forEach(function(nid){
              visibleNodes.push(nid);
            });
          }
        });
        if (numChecked > 1) {
          commonElements = getCommonElements(visibleGroupedNodes);
          if (commonElements.length > 0) {
            for (var nid in commonElements) {
              visibleNodes.push("" + commonElements[nid] + "");
            }
          }
        }
        // Show or hide based on selected values.
        var allUnchecked = $('.nc-catalog-page #filter-options input[type=checkbox]:checked').length;
        if (!allUnchecked) {
          // Make sure they're all shown.
          $('.results .node').parent('li').show();
          $('.results .node').parent('li').addClass('display-node');
          // Enable all checkboxes.
          $('.nc-catalog-page #filter-options input[type=checkbox]').prop('disabled', false);
        }
        else {
          $('.results .node').parent('li').hide();
          visibleNodes.forEach(function(nid){
            $('.results #node-' + nid).parent('li').show();
            $('.results #node-' + nid).parent('li').addClass('display-node');
          });
          // Ensure that any filters that would be useless are not displayed.
          // Disable the checkbox by default.
          $('.nc-catalog-page #filter-options input[type=checkbox]').prop('disabled', true);
          for (var termID in catalogFilterData) {
            if (catalogFilterData.hasOwnProperty(termID)) {
              // Determine if this filter includes the nodes, if it has ONE,
              // set the property and go to the next item.
              visibleNodes.forEach(function(nid){
                var exists = catalogFilterData[termID].indexOf(nid);
                if (exists != -1) {
                  $('.nc-catalog-page #filter-options input[type=checkbox][value=' + termID + ']').prop('disabled', false);
                }
              });
            }
          }
        }
        // Update count.
        var visibleElements = $('.results li.display-node').length;
        var singularItemNoun = Drupal.settings.catalogTaxonomyData.singular;
        var pluralItemNoun = Drupal.settings.catalogTaxonomyData.plural;
        if (visibleElements == 1) {
          $('.filter-results-stats .result-noun').text(singularItemNoun);
        }
        else {
          $('.filter-results-stats .result-noun').text(pluralItemNoun);
        }
        $('.filter-results-stats .result-count').text(visibleElements);
        // Fix scroll issue in some browsers.
        $('html,body').animate({
          scrollTop: $(".nc-catalog-page").offset().top
        });
      });
    }
  }
})(jQuery);

