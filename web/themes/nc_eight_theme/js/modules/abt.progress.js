$( function()
{
    $.fn.setProgress = function(value,total){
        total = total || 100;
        $(this).attr({'aria-valuenow': value, 'aria-valuetext': value})
            .find('.progress-now').css({'width': value+'%'}).end()
            .find('.progress-text').text(value+'%');
    };
});

