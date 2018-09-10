$(function () {

  var office_list = $('#dept-regional-offices-list'),
      office_map = $('#dept-regional-offices-map');

  // Initiate the accordion
  office_list.find('div').addClass('is-hidden');
  office_list.find('h3').append('<i class="icon-expand-more"></i>');
  office_list.find('div').each(function() {
    var total = $(this).find('li').length;

    $(this).find('h3').append(' <small>' + total + ' counties</small>')
  });

  // Toggle the accordion
  office_list.find('h3').click(function() {
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
  office_map.highcharts('Map', {
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
        joinBy: ['name', 'code'],
        dataLabels: {
          enabled: true,
          color: 'white'
        },
        mapData: Highcharts.maps['countries/us/us-nc-all'],
        tooltip: {
          headerFormat: '',
          pointFormat: '{point.name} County: <b>{series.name} Office</b>'
        },
        events: {
          legendItemClick: false
        }
      }
    },
    series: [{
      name: 'Asheville',
      color: '#A83338',
      data: $.map(['Cherokee', 'Graham', 'Clay', 'Swain', 'Macon', 'Jackson', 'Transylvania', 'Henderson', 'Polk', 'Rutherford', 'Burke', 'Caldwell', 'Mitchell', 'Yancey', 'McDowell', 'Buncombe', 'Madison', 'Haywood', 'Avery'], function(code) {
        return { code: code };
      }),
      nullColor: 'yellow'
    }, {
      name: 'Fayetteville',
      color: '#701C45',
      data: $.map(['Anson', 'Richmond', 'Scotland', 'Robeson', 'Bladen', 'Sampson', 'Cumberland', 'Harnett', 'Moore', 'Montgomery', 'Hoke'], function(code) {
        return { code: code };
      })
    }, {
      name: 'Mooresville',
      color: '#6A7681',
      data: $.map(['Cleveland', 'Gaston', 'Mecklenburg', 'Union', 'Stanly', 'Cabarrus', 'Rowan', 'Iredell', 'Catawba', 'Lincoln', 'Alexander'], function(code) {
        return { code: code };
      })
    }, {
      name: 'Raleigh',
      color: '#3F7D97',
      data: $.map(['Person', 'Granville', 'Vance', 'Warren', 'Halifax', 'Northampton', 'Edgecombe', 'Wilson', 'Johnston', 'Wake', 'Chatham', 'Lee', 'Orange', 'Durham', 'Franklin', 'Nash'], function(code) {
        return { code: code };
      })
    }, {
      name: 'Washington',
      color: '#00376D',
      data: $.map(['Wayne', 'Lenoir', 'Jones', 'Carteret', 'Greene', 'Pitt', 'Martin', 'Bertie', 'Hertford', 'Gates', 'Camden', 'Currituck', 'Pasquotank', 'Perquimans', 'Chowan', 'Washington', 'Tyrrell', 'Dare', 'Hyde', 'Beaufort' , 'Craven' , 'Pamlico'], function(code) {
        return { code: code };
      })
    }, {
      name: 'Wilmington',
      color: '#588023',
      data: $.map(['Brunswick', 'Columbus', 'New Hanover', 'Pender', 'Onslow', 'Duplin'], function(code) {
        return { code: code };
      })
    }, {
      name: 'Winston-Salem',
      color: '#9A6F09',
      data: $.map(['Watauga', 'Ashe', 'Alleghany', 'Surry', 'Stokes', 'Rockingham', 'Caswell', 'Alamance', 'Randolph', 'Guilford', 'Davidson', 'Forsyth', 'Davie', 'Yadkin', 'Wilkes'], function(code) {
        return { code: code };
      })
    }, {
      type: 'mappoint',
      name: 'Office',
      color: '#fff',
      marker: {
        radius: 4
      },
      showInLegend: false,
      dataLabels: {
        color: '#fff',
        align: 'center',
        verticalAlign: 'bottom',
        style: {
          'fontSize': '14px'
        }
      },
      tooltip: {
        pointFormat: '{point.name}'
      },
      data: [{
        name: 'Asheville',
        lat: 35.595058,
        lon: -82.551487
      }, {
        name: 'Mooresville',
        lat: 35.584860,
        lon: -80.810072
      }, {
        name: 'Winston-Salem',
        lat: 36.099860,
        lon: -80.244216
      },{
        name: 'Raleigh',
        lat: 35.779590,
        lon: -78.638179
      }, {
        name: 'Fayetteville',
        lat: 35.052664,
        lon: -78.878358
      }, {
        name: 'Wilmington',
        lat: 34.225726,
        lon: -77.944710
      }, {
        name: 'Washington',
        lat: 35.546552,
        lon: -77.052174
      }]
    }]

  });
});