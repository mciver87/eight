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
      name: '3.9 - 5.0%',
      color: '#ecf0f3',
      data: $.map(['Graham', 'Haywood', 'Transylvania', 'Madison', 'Buncombe', 'Henderson', 'Polk', 'Watauga', 'Surry', 'Stokes', 'Yadkin', 'Forsyth', 'Alexander', 'Iredell', 'Davie', 'Rowan', 'Davidson', 'Cabarrus', 'Stanly', 'Union', 'Mecklenburg', 'Cleveland', 'Gaston', 'Lincoln', 'Randolph', 'Chatham', 'Alamance', 'Orange', 'Durham', 'Granville', 'Wake', 'Johnston', 'Pitt', 'Pamlico', 'New Hanover'], function(code) {
        return { code: code };
      }),
      nullColor: 'yellow'
    }, {
      name: '5.1 - 6.0%',
      color: '#3a807d',
      data: $.map(['Cherokee', 'Clay', 'Jackson', 'Yancey', 'Avery', 'Ashe', 'Alleghany', 'Wilkes', 'Caldwell', 'Catawba', 'Burke', 'McDowell', 'Guilford', 'Rockingham', 'Caswell', 'Franklin', 'Camden', 'Currituck', 'Greene', 'Wayne', 'Sampson', 'Duplin', 'Pender', 'Onslow', 'Jones', 'Craven', 'Carteret', 'Anson', 'Montgomery', 'Moore'], function(code) {
        return { code: code };
      })
    }, {
      name: '6.1 - 7.0%',
      color: '#9a700f',
      data: $.map(['Gates', 'Macon', 'Mitchell', 'Person', 'Northampton', 'Hertford', 'Bertie', 'Beaufort', 'Dare', 'Lenoir', 'Brunswick', 'Columbus', 'Cumberland', 'Harnett', 'Chowan', 'Perquimans', 'Pasquotank'], function(code) {
        return { code: code };
      })
    }, {
      name: '7.1 - 8.5%',
      color: '#c25616',
      data: $.map(['Lee', 'Swain', 'Rutherford', 'Richmond', 'Hoke', 'Robeson', 'Bladen', 'Vance', 'Warren', 'Halifax', 'Martin', 'Washington', 'Hyde', 'Nash'], function(code) {
        return { code: code };
      })
    }, {
      name: '8.6 - 13.0%',
      color: '#a9363a',
      data: $.map(['Scotland', 'Wilson', 'Edgecombe', 'Tyrrell'], function(code) {
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
      }
    }]

  });
});