NC DPS Alerts
=================


What Is It?
------------

This module integrates the DPS Silver and Amber Alerts (missing persons alerts) into the NC Alerts alert block.

How Does It Work?
----------------------

The module makes requests to the specified Silver and Amber Alerts RSS feeds, then processes the RSS data and injects them into the NC Alerts alerts bar.

Currently, this is intended for use only on the DPS website, so the modules should be enabled only for the DPS sites (prod, staging, dev, etc). Some of the reusable functionality has been ported to a secondary module (NC Alerts Integration Library), with the intention that if other sites want to integrate 3rd party feeds or data sources into their alert bars, developers can make use of the integration library to speed up and standardize alert integration.


How To Use It?
---------------------

The setup for this module is fairly restricted in scope. You must make sure to enable this module's dependencies, NC Alerts and NC Alerts Integration Library, as well as enable this module NC DPS Alerts.

After enabling the modules, you may need to clear the Drupal caches before you will see the configuration page.

**Configuration**

The configuration menu is accessible (with correct permissions) via: Configuration >> North Carolina Missing Persons Alerts >> Missing Persons RSS Feeds

* Silver Alert RSS URL: This specifies the full (absolute) URL of the DPS Silver Alert RSS feed.
	* Ex: https://www.ncdps.gov/rss/rssSilverAlert.cfm
* Amber Alert RSS URL: This specifies the full (absolute) URL of the DPS Amber Alert RSS feed.
	* Ex: https://www.ncdps.gov/rss/rssAmberAlert.cfm
* RSS Feed Cache Lifetime (in seconds): Number of seconds to cache the RSS feed data.
	* The time should be entered as seconds. For 5 minutes, use 300. For 1 hour, use 3600.
	* To disable caching (not recommended), use 0.
	* The cache is in place so that the module does not need to make an external http request for each page load. Instead, the module makes a request, caches it, and does not attempt to make another request until the cache entry expires, as specified by the value of this setting.
	* Please note that page caching can also affect how often the alerts are updated.
	
**NOTE:** After you change settings, you will most likely need to clear the Drupal cache (drush cache-clear all) for settings to take effect immediately.
	 
Dependencies
-----------------
* NC Alerts
* NC Alerts Integration Library


Hooks?
-------

* {module}_nc_dps_alert_severity_alter(&$severity, &$key, &$alert)

>     /**
>      * Alter the severity / class of the dps alerts (silver & amber alerts).
>      */
>     function my_module_nc_dps_alert_severity_alter(&$severity, &$key, &$alert) {
>     	  $severity = 'alert-class-' . $key;
>     }

What's New?
----------------

2016-02-11: Missing persons alerts will have a custom style/color instead of using breaking.
2016-02-11: We'll be adding back a modified version of the "Dismiss" functionality.


Testing
--------

You can use the mock xml files to test. The files are located in the /mock directory. You can update the URLs in the module's settings (See HOW TO USE IT).

* http://{site_url}/profiles/north_carolina/modules/custom/nc_dps_alerts/mock/silver-alert.xml
* http://{site_url}/profiles/north_carolina/modules/custom/nc_dps_alerts/mock/amber-alert.xml
