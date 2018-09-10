NC Breadcrumb Behavior
=================


What Is It?
------------

This module enhances and customizes the Breadcrumbs module with customizations for NC.gov.

The initial goal is to handle long breadcrumb trails on pages. This module provides the ability to truncate individual crumbs (segments) as well as to cloak/hide the entire path if it's deemed too long.

How Does It Work?
----------------------

This module adds some additional features and settings to control its behavior. Using those settings it will...

* Truncate segment (crumb) titles if they are too long


How To Use It?
---------------------

Make sure to enable the extension. You can use the Drupal admin or Drush (drush pm-enable nc_breadcrumb_behavior).

After enabling the modules, you may need to clear the Drupal caches before you will see the configuration page.

**Configuration**

The configuration menu is accessible (with correct permissions) via: Home » Administration » Configuration » Menu Breadcrumb

* Enable Segment Truncation: Enables or disables the ability to truncate titles.
* Maximum Segment Length: Segments longer than this specified character length are truncated.

Dependencies
-----------------
* Menu Breadcrumb

TODO
----
Theme css/js was updated to handle super long breadcrumbs a bit more gracefully. This module will truncate only desktop breadcrumbs.
* Install/update - Enable in update if we want this on all sites. If only 1 site needs it, we can skip this.