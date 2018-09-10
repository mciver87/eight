// Custom Extension to jQuery UI Datepicker
// Just run the function and pass a jQuery selector object
// We'll take care of the rest!

function initDatePicker(selector) {

    var wrapper = $(selector),
        selectedDate = wrapper.find(".ui-datepicker-selected-day"),
        calendar = wrapper.find(".ui-datepicker-calendar");

    var weekdayName = new Array(7);
        weekdayName[1] = "Sunday";
        weekdayName[2] = "Monday";
        weekdayName[3] = "Tuesday";
        weekdayName[4] = "Wednesday";
        weekdayName[5] = "Thursday";
        weekdayName[6] = "Friday";
        weekdayName[7] = "Saturday";

    var monthName = new Array(12);
        monthName[1] = "January";
        monthName[2] = "February";
        monthName[3] = "March";
        monthName[4] = "April";
        monthName[5] = "May";
        monthName[6] = "June";
        monthName[7] = "July";
        monthName[8] = "August";
        monthName[9] = "September";
        monthName[10] = "October";
        monthName[11] = "November";
        monthName[12] = "December"; 

    var today = new Date(),
        todayDayOfWeek = weekdayName[today.getUTCDay() + 1],
        todayDay = today.getDate(),
        todayMonth = monthName[today.getMonth() + 1];

        // Let's display today's date by default
        $(selectedDate).html('<span class="week-day">' + todayDayOfWeek + '</span>' + todayMonth + ' ' + todayDay);

        // Okay, now let's initialize jQuery UI Datepicker
        $(calendar).datepicker({
            dayNamesMin: ['S', 'M', 'T', 'W', 'T', 'F', 'S'],
            dateFormat: "yy-mm-dd",
            onSelect: function(dateText, inst) { 

                var date = $(this).datepicker('getDate'),
                    dayOfWeek = weekdayName[date.getUTCDay() + 1],
                    day = date.getDate(),
                    month = monthName[date.getMonth() + 1];

                    // Now let's update our displayed date based on selection
                    $(selectedDate).html('<span class="week-day">' + dayOfWeek + '</span>' + month + ' ' + day);
            }
        });

}