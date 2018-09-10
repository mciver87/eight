Highcharts.theme = {
    colors: [
        '#F44336', '#673AB7', '#E91E63', '#3F51B5', '#9C27B0', '#2196F3',
        '#03A9F4', '#4CAF50', '#00BCD4', '#8BC34A'
    ],
    title: {
        style: {
            color: '#000',
            font: 'normal 16px "TransportNewMedium", Helvetica, Arial, sans-serif'
        }
    },
    subtitle: {
        style: {
            color: '#666',
            font: 'normal 12px "TransportNewLight", Helvetica, Arial, sans-serif'
        }
    },

    legend: {
        itemStyle: {
            color: '#000',
            font: 'normal 12px "TransportNewLight", Helvetica, Arial, sans-serif'
        },
        itemHoverStyle: {
            color: 'gray'
        }
    }
};

// Apply the theme
Highcharts.setOptions(Highcharts.theme);