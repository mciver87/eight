Overview
========

Users are reporting that the WYSIWYG content in the Bands' text areas is disappearing. This is a potential bandage for that.


What's Going On?
================

When the Paragraphs module receives 2 identical edit requests, the second request causes Paragraphs to save the text area with empty content, causing data loss.

This data loss can be achieved (sans this fix) by editing a Band, clicking the browser back button, then using the browser forward button to return to the edit page. From there, if you click edit again, the text areas are empty.

This happens when the Default edit mode for Paragraphs is Preview, which is the preferred setting for NC.GOV.

When in preview mode, the Edit button generates AJAX requests to the Paragraphs module, and this is where the trouble happens.


What Does This Do?
==================

This fix modifies the browser cache control value passed in the Drupal response header when a user is navigating the administrative side of Drupal.

In doing so, the exact duplicate requests that sometimes occur are prevented since, in theory if the browser honors the cache control header, it will make a new request instead of using the cached version of the edit form.


Other Info?
===========

This works in all tested browser/os combos, and doesn't seem to be causing issues on the frontend.
