// (function ($) {
//   Drupal.behaviors.ncDynamicLogo = {
//     attach: function(context, settings) {
//       var headerTotal = $("#header").height();
//       $(".site-title").css("max-height", headerTotal);
//       $(".site-title").height(headerTotal);
//       $(".site-title").find("a").height(headerTotal).css("text-align", "center");
//       $(".site-title").find("img").width("80%").css("height", "auto");
//       var logoHeader = $(".site-title").find("img").height();
//       var vertSpacing = (headerTotal - logoHeader) / 2;
//       $(".site-title").find("img").css("margin-top", vertSpacing);
//       $(".jb-overflowmenu-menu-primary .first").find("a").text("Test");
//     }
//   };
// }(jQuery));