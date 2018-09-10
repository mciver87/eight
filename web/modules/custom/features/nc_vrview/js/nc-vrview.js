(function($) {
  Drupal.behaviors.ncVrViewer = {
    attach: function(context, settings) {
      var ncVrViewerLen = Drupal.settings.ncVrViewer.items.length;
      for (var i = 0; i < ncVrViewerLen; i++) {
        vrViewItem = Drupal.settings.ncVrViewer.items[i];
        $('#' + vrViewItem.htmlId).hide();
        var vrView;
        if (vrViewItem.vrType == 'video') {
          vrView = new VRView.Player('#' + vrViewItem.htmlId, {
            video: vrViewItem.resourcePath,
            is_stereo: false,
            is_autopan_off: true,
            width: '100%',
            height: '100%'
          });
        }
        else {
          vrView = new VRView.Player('#' + vrViewItem.htmlId, {
            image: vrViewItem.resourcePath,
            preview: vrViewItem.resourcePath,
            is_stereo: false,
            is_autopan_off: true,
            width: '100%',
            height: '100%'
          });
        }
        vrView.on('ready', function(event) {
          $('#' + vrViewItem.htmlId).css('height', '30rem');
          $('#' + vrViewItem.htmlId).fadeIn();
        });
      }
    }
  }
}(jQuery));
