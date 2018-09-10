(function ($) {
    var countUpOptions = {
        useEasing : true,
        useGrouping : true,
        separator : ',',
        decimal : '.',
        prefix : '',
        suffix : ''
    };

    function animateCountup(statId) {
        var targetId = statId + "-target";
        var animationSettings = Drupal.settings.nc_cards[statId];
        var animation = new CountUp(targetId, 0, animationSettings.value, animationSettings.decimals, animationSettings.duration, countUpOptions);
        animation.start();
    }

    // Store our function as a property of Drupal.behaviors.
    Drupal.behaviors.addCountup = {
        attach: function (context, settings) {
            $('.card.animated.countup.stat').each(function (n) {
                var thisOffset = $(this).offset().top - window.innerHeight;
                var animatedStat = $(this);
                var animatedStatID = $(this).attr('id');
                if ($(this).is(':in-viewport')) {
                    animateCountup(animatedStatID);
                }
                else {
                    var interval = setInterval(function(){
                        if(animatedStat.is(':in-viewport')){
                            animateCountup(animatedStatID);
                            clearInterval(interval);
                        }
                        //do whatever here..
                    }, 20);
                }
            });
        }
    };

}(jQuery));