North Carolina Theme - External Links Customization
=

What Is It?
------------

This module provides further customization to the External Links (extlink) module. It overrides the functionality within External Links that appends a span to anchors (links) from the content WYSIWYG that denotes whether a link will take the visitor off site.

How Does It Work?
----------------------

Currently the module makes one modification to the External Links Javascript functionality that appends a span to anchors. This module overrides the applyClassAndSpan function.


How To Use It?
---------------------

Enable the North Carolina Theme - External Links Customization module. You will need to have External Links (extlink) installed as well, since this is a dependency for North Carolina Theme - External Links Customization.

Once the module is installed, make sure to configure it:
* Configuration >> External Links
*  Check the "Place an icon next to external links." box
* Be sure to save.

Additionally, upon running the database update (update.php), this module will be enabled and approriate default settings will be in place. This module is a requirement to help adhere to the NC.GOV styleguide for external links.

Dependencies
-----------------
* [External Links (extlinks)](https://www.drupal.org/project/extlink)