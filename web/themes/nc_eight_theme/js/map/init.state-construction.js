$(function () {

  var select_list = $('#state-construction-list'),
      select_map = $('#state-construction-map');

  // Initiate the accordion
  select_list.find('div').addClass('is-hidden');
  select_list.find('h3').append('<i class="icon-expand-more"></i>');
  select_list.find('div').each(function() {
    var total = $(this).find('li').length;

    $(this).find('h3').append(' <small>' + total + ' counties</small>')
  });

  // Toggle the accordion
  select_list.find('h3').click(function() {
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
  select_map.highcharts('Map', {
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
        allAreas: false,
        borderColor: 'silver',
        joinBy: ['name', 'code'],
        dataLabels: {
          enabled: true,
          color: 'white'
        },
        mapData: Highcharts.maps['countries/us/us-nc-all'],
        tooltip: {
          headerFormat: '',
          pointFormat: '{point.name} County: <b>{series.name}</b>'
        },
        events: {
          legendItemClick: false
        },
        nullColor: 'rgba(0,0,0,0)'
      }
    },
    series: [
      {
        name: 'Western',
        color: '#A83338',
        data: $.map([
          'Cherokee',
          'Clay',
          'Graham',
          'Macon',
          'Swain',
          'Jackson',
          'Haywood',
          'Transylvania',
          'Madison',
          'Buncombe',
          'Henderson',
          'Polk',
          'Rutherford',
          'McDowell',
          'Yancey',
          'Mitchell',
          'Burke',
          'Caldwell',
          'Avery',
          'Cleveland',
          'Lincoln',
          'Gaston',
          'Mecklenburg',
          'Union',
          'Cabarrus'
        ], function(code) {
          return { code: code };
        })
      },
      {
        name: 'West Central',
        color: '#701C45',
        data: $.map([
          'Watauga',
          'Ashe',
          'Alleghany',
          'Surry',
          'Stokes',
          'Rockingham',
          'Guilford',
          'Alamance',
          'Davidson',
          'Stanly',
          'Anson',
          'Rowan',
          'Iredell',
          'Catawba',
          'Alexander',
          'Wilkes',
          'Yadkin',
          'Forsyth',
          'Davie'
        ], function(code) {
          return { code: code };
        })
      },
      {
        name: 'Central',
        color: '#3F7D97',
        data: $.map([
          'Montgomery',
          'Randolph',
          'Chatham',
          'Lee',
          'Wake',
          'Orange'          
        ], function(code) {
          return { code: code };
        })
      },
      {
        name: 'Lower East',
        color: '#3C807D',
        data: $.map([
          'Richmond',
          'Moore',
          'Harnett',
          'Johnston',
          'Wayne',
          'Lenoir',
          'Craven',
          'Pamlico',
          'Carteret',
          'Onslow',
          'Pender',
          'New Hanover',
          'Brunswick',
          'Columbus',
          'Robeson',
          'Scotland',
          'Hoke',
          'Cumberland',
          'Bladen',
          'Sampson',
          'Duplin',
          'Jones'        
        ], function(code) {
          return { code: code };
        })
      },
      {
        name: 'Upper East',
        color: '#00376D',
        data: $.map([
          'Caswell',
          'Person',
          'Granville',
          'Vance',
          'Warren',
          'Halifax',
          'Northampton',
          'Hertford',
          'Gates',
          'Pasquotank',
          'Camden',
          'Currituck',
          'Dare',
          'Perquimans',
          'Chowan',
          'Beaufort',
          'Pitt',
          'Greene',
          'Wilson',
          'Nash',
          'Franklin',
          'Durham',
          'Edgecombe',
          'Martin',
          'Bertie',
          'Washington',
          'Tyrrell',
          'Hyde'     
        ], function(code) {
          return { code: code };
        })
      }
    ]

  });
});