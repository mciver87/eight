(function ($) {
  Drupal.behaviors.ncMap = {
    attach: function(context, settings) {
      // Cleans up svg county id names.
      function capitalize(str) {
        strVal = "";
        str = str.split(" ");
        for (var chr = 0; chr < str.length; chr++) {
          strVal += str[chr].substring(0, 1).toUpperCase() + str[chr].substring(1, str[chr].length)
          // Must address New Hanover County...
          strValNoDash = strVal.replace("-h", " H");
          // And McDowell county.
          if (strValNoDash == 'Mcdowell') {
            strValNoDash = 'McDowell';
          }
        }
        return strValNoDash
      }

      // Get county data from bean form.
      var counties = Drupal.settings.countyDestinations;
      var defaults = Drupal.settings.defaults;

      var x = 0;

      $(".map-wrapper").each(function(i) {
        $(this).attr("id", x);
        $(this).children("svg").children("defs").children("pattern").attr("id", "pattern-" + x);
        var patternID = "url(#" + $(this).children("svg").children("defs").children("pattern").attr("id") + ")";
        x++;

        var mapInstance = $(this).attr("id");

        // Determine default colors for a given map instance
        if (typeof defaults[mapInstance]["default_fill_color_empty"] !== 'undefined') {
          if (defaults[mapInstance]["default_fill_color_empty"].length > 0) {
            var defaultEmpty = defaults[mapInstance]["default_fill_color_empty"];
          }
          else {
            var defaultEmpty = "#BABABA";
          }
        }
        else {
          var defaultEmpty = "#BABABA";
        }

        if (typeof defaults[mapInstance]["default_fill_color_populated"] !== 'undefined') {
          if (defaults[mapInstance]["default_fill_color_populated"].length > 0) {
            var defaultPopulated = defaults[mapInstance]["default_fill_color_populated"];
          }
          else {
            var defaultPopulated = "#919191";
          }
        }
        else {
          var defaultPopulated = "#919191";
        }


        // Set default map bg color.
        $(this).children(".ncstatemap").css({fill: defaultEmpty});

        $(this).children(".ncstatemap").children(".map-region").css({fill: patternID});

        for (var i in counties[mapInstance]) {
          var countyId = "#" + counties[mapInstance][i]["county"].toLowerCase().replace(" ", "-");
          // Ultimately, we're going to need a function to determine if a county's "populated"
          if (counties[mapInstance][i]["fill_color"].length == 0) {
            if (counties[mapInstance][i]["title"]["value"].length > 0 || counties[mapInstance][i]["url"].length > 0) {
              $(this).find(countyId).css({fill: defaultPopulated});
            }
          }
          else {
            $(this).find(countyId).css({fill: counties[mapInstance][i]["fill_color"]});
          }
        }
      });

      if ($(window).width() > 1024) {
        $("g g").click(function() {
          var mapInstance = $(this).closest("div").attr("id");
          var id = $(this).attr("id");
          id = capitalize(id);
          for (var i in counties[mapInstance]) {
            if (counties[mapInstance][i]["county"] == id && counties[mapInstance][i]["url"].length > 0) {
              window.location = counties[mapInstance][i]["url"];
            }
          }
        });
      }

      $(".ncsvgmap-hover").tooltip({
        items: "[data-name]",
        content: function () {
          return $(this).data("name");
        },
        track: true,
      });

      $("g g").hover(function(e){
        $(this).css("opacity", "0.5");
        var hoverId = $(this).attr("id");
        hoverIdTitleCase = capitalize(hoverId);

        var mapInstance = $(this).closest("div").attr("id");

        for (var i in counties[mapInstance]) {
          if (hoverIdTitleCase == counties[mapInstance][i]["county"]) {
            $(".ui-tooltip-content").parents("div").append(counties[mapInstance][i]["title"]["value"]);
          }
        }

      },function(){
       $(this).css("opacity", "1");
       $(".ui-tooltip-content").parents("div").remove();
     });

    $(".nc-map-info-toggle").click(function(e) {
      $(this).hide();
      $(this).siblings(".county-display").toggle();
      $(this).siblings("#ncstatemap").css("opacity", 0.3);
    });

    $(".nc-map-info-close").click(function(e) {
      $(this).parent(".county-display").siblings(".nc-map-info-toggle").show();
      $(this).parent(".county-display").toggle();
      $(this).parent(".county-display").siblings("#ncstatemap").css("opacity", 1);
    });

    $(".map-wrapper").each(function() {
      var details = '<div class="nc-map-details">';
      var mapInstance = $(this).closest("div").attr("id");
      for (var i in counties[mapInstance]) {
        details = details + '<h4 style="color: black;">';
        if (counties[mapInstance][i]["url"].length > 0) {
          details = details + '<a style="color: black;" href="' + counties[mapInstance][i]["url"] + '">';
        }
        details = details + counties[mapInstance][i]["county"];
        if (counties[mapInstance][i]["url"].length > 0) {
          details = details + '</a>';
        }
        details = details + '</h4>';
        details = details + counties[mapInstance][i]["title"]["value"];
      }
      details = details + '</div>';
      $(this).children(".county-display").append(details);
    });


 /**
 * detect IE
 * returns version of IE or false, if browser is not Internet Explorer
 */
 function detectIE() {
  var ua = window.navigator.userAgent;

  var msie = ua.indexOf('MSIE ');
  if (msie > 0) {
        // IE 10 or older => return version number
        return parseInt(ua.substring(msie + 5, ua.indexOf('.', msie)), 10);
      }

      var trident = ua.indexOf('Trident/');
      if (trident > 0) {
        // IE 11 => return version number
        var rv = ua.indexOf('rv:');
        return parseInt(ua.substring(rv + 3, ua.indexOf('.', rv)), 10);
      }

      var edge = ua.indexOf('Edge/');
      if (edge > 0) {
       // Edge (IE 12+) => return version number
       return parseInt(ua.substring(edge + 5, ua.indexOf('.', edge)), 10);
     }

    // other browser
    return false;
  }

  if (detectIE() != false) {
    $(".map-wrapper").css("padding-bottom", "44%");
    $(".map-wrapper").css("padding-top", "3%");
  }

  if ($(window).width() <= 1024) {
    $("g g").click(function() {
      if ($(this).data("hover") == 1) {
        var mapInstance = $(this).closest("div").attr("id");
        var id = $(this).attr("id");
        id = capitalize(id);
        for (var i in counties[mapInstance]) {
          if (counties[mapInstance][i]["county"] == id) {
            window.location = counties[mapInstance][i]["url"];
          }
        }
      }
      $(this).data("hover", 1);
      $(this).siblings().data("hover", 0);
    });


    $( ".map-wrapper" ).each(function(i) {
      $(".map-wrapper").css("padding-bottom", "65%");
    });

    if (detectIE() != false) {
      $(".map-wrapper").css("padding-bottom", "44%");
      $(".map-wrapper").css("padding-top", "3%");
    }

    function separation() {
      $(".map-wrapper").each(function(i) {
        $(this).find(".east").css("transform", "translateX(50px) scale(0.95)");
        $(this).find(".west").css("transform", "translateX(-30px) scale(0.95)");
        $(this).find(".piedmont").css("transform", "translateX(10px) scale(0.95)");
        $(this).find(".west, .east, .piedmont").css("display", "inline-block");
      });
    }

    function fullMap() {
      $(".map-wrapper").each(function(i) {
        $(this).find(".back-to-regions").hide();
        $(this).find(".east").css("transform", "translateX(50px) scale(0.95)");
        $(this).find(".west").css("transform", "translateX(-30px) scale(0.95)");
        $(this).find(".piedmont").css("transform", "translateX(10px) scale(0.95)");
        $(this).find(".west, .east, .piedmont").css("display", "inline-block");
      });
    }

    $('<button class="back-to-regions" href="#" style="position: absolute; top: 1px; left: 1px; opacity: 0.6; font-size: 0.8em;">View All</button>').appendTo(".map-wrapper");
    $(".map-region").css("transition", "all 1s");
    $( ".ncstatemap" ).each(function(i) {
      $(".ncstatemap").removeAttr("viewBox");
    });
    $(".ncstatemap").each(function () { $(this)[0].setAttribute("viewBox", "0 0 950 600") });
    $(".back-to-regions").hide();
    $(window).load(function() {
      separation();
    });

    $(".west").hover(function() {
        $(this).parent("#ncstatemap").siblings(".back-to-regions").show();
        $(this).css("transform", "scale(2.3)");
        $(this).parent().find(".east, .piedmont").css("display", "none");
        $(this).parent().parent().find(".nc-map-info-toggle").hide();
    });

    $(".east").hover(function() {
        $(this).parent("#ncstatemap").siblings(".back-to-regions").show();
        $(this).css("transform", "translateX(-600px) scale(1.5)");
        $(this).parent().find(".west, .piedmont").css("display", "none");
        $(this).parent().parent().find(".nc-map-info-toggle").hide();
    });

    $(".piedmont").hover(function() {
        $(this).parent("#ncstatemap").siblings(".back-to-regions").show();
        $(this).css("transform", "translateX(-425px) scale(2)");
        $(this).parent().find(".east, .west").css("display", "none");
        $(this).parent().parent().find(".nc-map-info-toggle").hide();
    });

    $(".back-to-regions").hover(function() {
      $(this).parent().parent().find(".nc-map-info-toggle").show();
      fullMap();
    });
  }
}
};
}(jQuery));
