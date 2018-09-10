NC Alerts Integration Library
=================


What is it?
----------------------

This is a development library that should, in theory, assist with developing modules and services that integrate with the NC Alerts module. This module provides no front-end or admin accessible functionality, and is merely a tool for developers.

Development on this began in  January 2016 in an effort to support the DPS site's Silver and Amber alerts, which needed to be integrated into the NC Alerts alerts bar.

The current goal of this library is to support requesting data from external data sources (s.a. an RSS feed), parsing the data, and rendering it in a way that it is compatible with NC Alerts.

How To Use This?
-------------

Take a look at the NC DPS Alerts module for example use. As a developer, you will need to develop the code that handles functionality such as adding configuration settings, parsing responses, and rendering the response data in a format that can be used by NC Alerts.

Some basics you will need to consider:

In your .info file, you need to add: 
			> `dependencies[] = nc_alerts_integration_library` 

If you are doing a basic request, such as requesting data from an XML or JSON feed, then you can use the built-in components to handle making the request. However, since every feed is different and data is structured differently, you will need to develop a custom response parser that extends the abstract class AbstractResponseBodyParser.

The overall idea is this: Use the RequestParserConnector to connect a request handler, like the DrupalRequestDelegate, with a your custom response handler.
	 

Dependencies
-----------------
* NC Alerts


How To Update
------------------

Be aware that any changes you make to this shared module library could affect other modules. Currently only NC DPS Alerts (Missing Persons Alerts) is using this, but if the API changes, it might affect other modules.