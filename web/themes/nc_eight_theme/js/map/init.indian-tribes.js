$(function () {

  var tribe_list = $('#indian-tribes-list'),
      tribe_map = $('#indian-tribes-map');

  // Initiate the accordion
  tribe_list.find('div').addClass('is-hidden');
  tribe_list.find('h3').append('<i class="icon-expand-more"></i>');
  tribe_list.find('div').each(function() {
    var total = $(this).find('li').length;

    $(this).find('h3').append(' <small>' + total + ' counties</small>')
  });

  // Toggle the accordion
  tribe_list.find('h3').click(function() {
    $(this).parent().toggleClass('is-hidden');

    if ( $(this).parent().is('.is-hidden') ) {
      $(this).find('i').removeClass('icon-expand-less');
      $(this).find('i').addClass('icon-expand-more');
    } else {
      $(this).find('i').removeClass('icon-expand-more');
      $(this).find('i').addClass('icon-expand-less');
    }
  });

  // Initiate the chart
  tribe_map.highcharts('Map', {
    title: {
      text: ''
    },
    subtitle: {
      text: ''
    },
    exporting: {
      enabled: false
    },
    mapNavigation: {
      enabled: false,
      buttonOptions: {
        verticalAlign: 'bottom'
      }
    },
    plotOptions: {
      map: {
        allAreas: true,
        borderColor: 'silver',
        joinBy: ['name', 'code'],
        dataLabels: {
          enabled: true,
          color: 'white'
        },
        mapData: Highcharts.maps['countries/us/us-nc-all'],
        
        events: {
          legendItemClick: false
        },
        nullColor: 'rgba(0,0,0,0)'
      }
    },
    series: [{
      name: 'Coharie',
      color: '#3C807D',
      data: $.map(['Harnett', 'Sampson'], function(code) {
        return { code: code };
      })
    }, {
      name: 'Eastern Band of Cherekee Nation',
      color: '#A83338',
      data: $.map(['Cherokee', 'Clay', 'Graham', 'Jackson', 'Macon', 'Swain'], function(code) {
        return { code: code };
      })
    }, {
      name: 'Haliwa-Saponi',
      color: '#00376D',
      data: $.map(['Halifax', 'Warren'], function(code) {
        return { code: code };
      })
    }, {
      name: 'Lumbee',
      color: '#3F7D97',
      data: $.map(['Hoke', 'Robeson', 'Scotland'], function(code) {
        return { code: code };
      })
    }, {
      name: 'Meherrin',
      color: '#701C45',
      data: $.map(['Hertford'], function(code) {
        return { code: code };
      })
    }, {
      name: 'Occaneechi',
      color: '#C05411',
      data: $.map(['Alamance', 'Orange'], function(code) {
        return { code: code };
      })
    }, {
      name: 'Sappony',
      color: '#757575',
      data: $.map(['Person'], function(code) {
        return { code: code };
      })
    }, {
      name: 'Waccamaw Siouan',
      color: '#662E6B',
      data: $.map(['Bladen', 'Columbus'], function(code) {
        return { code: code };
      })
    }, {
      name: 'Urban Indian Organizations',
      color: '#9A6F09',
      data: $.map(['Cumberland', 'Guilford', 'Mecklenburg', 'Wake'], function(code) {
        return { code: code };
      })
    }]

  });
});