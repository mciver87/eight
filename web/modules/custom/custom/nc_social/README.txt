------------------
-- Introduction --
------------------
NC Social adds blocks that provide social media interaction to the sites.  This module adds two different blocks:
 * nc_social_share - a standard block
 * nc_social_share_follow_us - a bean

---------------------
-- nc_social_share --
---------------------
nc_social_share is a standard block with no configuration.  It is setup to appear on every page that uses the standard
page template.  It provides social share icons for Facebook and Twitter.  It appears on the page by using a custom
region called "social_share" which the nc_base_theme has been updated to support.

If this new block does not appear on the pages once the module is enabled, so the following:

1. Go to Structure -> Blocks
2. Find the block titled "NC Social Share".
3. Using the pull down menu, select "Social Share" for NC Social Share.
4. Click on "Save Blocks"

-------------------------------
-- nc_social_share_follow_us --
-------------------------------
nc_social_share_follow_us is a bean block with its own configuration.  This allows different social links to be added
to different pages any where a block can be added.  To create a nc_social_share_follow_us block, do the following:

1. Go to Content -> Blocks
2. Click on "Add Block"
3. Click on "Follow Us"
4. Provide a label for the block.  The label is what is displayed in the admin to represent your block.
5. Add a title, if wanted.  The title will appear at the top of the block when displayed in the site.
6. For each of the listed social media, add in the url to the desired social media page. Only social media's that have
   urls provided will appear.
7. Click on "Save"

To make the block appear on the page, edit any node and select the block to appear in any block fields.