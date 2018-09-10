$(function () {

  var select_list = $('#regional-commissioners-list'),
      select_map = $('#regional-commissioners-map');

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
        name: 'Region 1',
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
          'Avery'
        ], function(code) {
          return { code: code };
        })
      },
      {
        name: 'Region 2',
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
          'Wilkes',
          'Yadkin',
          'Forsyth',
          'Davie',
          'Caswell',
          'Randolph'
        ], function(code) {
          return { code: code };
        })
      },
      {
        name: 'Region 3',
        color: '#9A6F09',
        data: $.map([
          'Mecklenburg',
          'Cabarrus',
          'Lincoln',
          'Gaston',
          'Cleveland',
          'Catawba',
          'Union',
          'Stanly',
          'Rowan',
          'Iredell',
          'Alexander',
          'Montgomery'
        ], function(code) {
          return { code: code };
        })
      },
      {
        name: 'Region 4',
        color: '#3F7D97',
        data: $.map([
          'Johnston',
          'Warren',
          'Edgecombe',
          'Halifax',
          'Northampton',
          'Nash',
          'Franklin',
          'Vance',
          'Durham',
          'Person',
          'Granville',
          'Wilson',
          'Lee',
          'Wake',
          'Orange',
          'Chatham'          
        ], function(code) {
          return { code: code };
        })
      },
      {
        name: 'Region 5',
        color: '#3C807D',
        data: $.map([
          'Hoke',
          'Cumberland',
          'Moore',
          'Sampson',
          'Harnett',
          'Bladen',
          'Robeson',
          'Richmond',
          'Scotland',
          'Anson'
        ], function(code) {
          return { code: code };
        })
      },
      {
        name: 'Region 6',
        color: '#00376D',
        data: $.map([
          'Pamlico',
          'Washington',
          'Tyrrell',
          'Hyde',
          'Hertford',
          'Gates',
          'Pasquotank',
          'Camden',
          'Currituck',
          'Dare',
          'Perquimans',
          'Chowan',
          'Beaufort',
          'Martin',
          'Bertie',
          'Pitt',
          'Greene',
          'Wayne',
          'Lenoir',
          'Jones',
          'Craven'      
        ], function(code) {
          return { code: code };
        })
      },
      {
        name: 'Region 7',
        color: '#C05411',
        data: $.map([
          'Duplin',
          'Carteret',
          'Onslow',
          'Pender',
          'New Hanover',
          'Brunswick',
          'Columbus'       
        ], function(code) {
          return { code: code };
        })
      }
    ]

  });
});