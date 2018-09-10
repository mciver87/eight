$( function()
{
    if($('#map').length) {

        L.Icon.Default.imagePath = '../img/';

        var map = L.map('map').setView(new L.LatLng(35.7806, -78.6389), 6);

        function style(feature) {
            return {
                fillColor: '#cc0000',
                weight: 2,
                opacity: 1,
                color: 'white',
                dashArray: '3',
                fillOpacity: 0.7
            };
        }



        L.tileLayer('http://{s}.mqcdn.com/tiles/1.0.0/osm/{z}/{x}/{y}.png', {
                    attribution: 'Tiles by <a href="http://www.mapquest.com/">MapQuest</a> &mdash; Map data &copy; <a href="http://openstreetmap.org">OpenStreetMap</a> contributors, <a href="http://creativecommons.org/licenses/by-sa/2.0/">CC-BY-SA</a>',
                    maxZoom: 18,
                    subdomains: ['otile1','otile2','otile3','otile4']
                }).addTo(map); 

        var geojsonURL = 'public/data/nc-counties.json';

        $.ajax( geojsonURL, 
            {dataType: 'json'}).done(function(statesData, responseType, xhr) {
                console.log('loaded');
                console.log(statesData)
                L.geoJson(statesData, {style: style}).addTo(map);
        });



        var marker = L.marker(new L.LatLng(35.7806, -78.6389)).addTo(map);
        marker.bindPopup("<b>Raleigh</b>").openPopup();

    // var circle = L.circle(new L.LatLng(38.617, -100.261), 500, {
    //     color: 'red',
    //     fillColor: '#f03',
    //     fillOpacity: 0.5
    // }).addTo(map);

    }
    

});