(function ($) {

    function nc_cards_icon_picker_click(evt) {
        var $clicked_elem = $(this);
        var $icon_picker = $clicked_elem.parent('.dc-icon-picker');
        var icon_picker_list = $icon_picker.children('.dc-icon-picker-list');
        // prevent scroll to top
        evt.preventDefault();
        // Need to make the list.
        if (!icon_picker_list.length) {
            var select_id = $icon_picker.data('select');
            var $icon_select = $('#' + select_id);
            $icon_picker_list = $('<ul class="dc-icon-picker-list" id="iconsContent">');
            $icon_picker_list.hide(); // have it hidden for now.
            $icon_select.children('option').each(function(optIndex) {
                var icon_class = $(this).attr('value');
                if (icon_class != '0') {
                    var $icon_picker_item = $('<li class="dc-icon-pick" data-icon_class="' + icon_class + '"><span class="' + icon_class + '"></span> ' + icon_class + '</li>');
                    $icon_picker_item.click(function(evt) {
                        $icon_select.val($(this).data('icon_class'));
                    });
                    $icon_picker_list.append($icon_picker_item);
                }
            });
            $icon_picker.append('<br/><input class="dc-icon-picker-search" type="search" placeholder="Search for icons" id="iconsSearch"><br/>');
            $icon_picker.append($icon_picker_list);

            var iconJetSearch = new Jets({
                searchTag: '#iconsSearch',
                contentTag: '#iconsContent'
            });
        } else {
            var $icon_picker_list = $(icon_picker_list[0]);
        }

        if ($clicked_elem.parent().hasClass('hidden')) {
            $clicked_elem.text('Hide Picker');
            $clicked_elem.parent().removeClass('hidden');
            $icon_picker_list.show();
        } else {
            $clicked_elem.parent().addClass('hidden');
            $clicked_elem.text('Display Picker');
            $('.dc-icon-picker-list').hide();
        }
    }

    Drupal.behaviors.nc_cards = {
      attach: function (context, settings) {
        $('.hide-show-picker').click(nc_cards_icon_picker_click);
      }
    };
}(jQuery));