#  Feature - NC Press Release

For Press Releases, please use DEQ (DENR) as the archetype when updating the Feature and recreating it.

----------

## Press Release List Order By Hour (ABT#645 + Others)

**Overview**

DEQ adds multiple press releases each day, but newest press releases don’t stay on top.

### More Information

**ABT#606**
This update encompasses ABT#606 (Change verbiage of related terms to "This press release is related to").

This update was not feasible using Features export (recreate). During development, there were multiple significant issues with Features, mostly surrounding changes to the field settings of the Press Release content type. Most of the changes/settings would not take effect on various sites, leading to issues where the weights weren't being honored (fields in wrong order) and field formats were ignored (date formats on release date). As a result, some of the changes are being managed in the update/install function.

### Known Issues

* Minutes & seconds are rounded to the nearest 15th increment. For example. 10:12:00 is converted to 10:15:00 and 10:15:09 is rounded to 10:15:15. This should still be sufficient for ordering by time.

### TODO

* Test on all sites
* DHHS - test & port if needed (port install specifically)
* Acceptance Criteria

----------

## Contact Information (ABT#620)

The contact information setup was created from the DPS site as that was determined to be the closest to what NC.GOV wants site-wide.

###  The Contact Information Update (ABT#620) is implemented as follows:

* The feature was created from DPS production site.
* Several significant theme/template updates have been implemented to product markup as specified in the styleguide.
* A new view using Views has been added to provide a way to recreate blocks for a single press release (Single Press Release Blocks).
* A new view block display "Press Release Contact Information" has been added to display the contact information for a press release.
* The Press Release Contact Information block display was added to the Second Sidebar of the Press Release Context.

###  In update ABT#620, we're updating the theme ...

* To use a new custom page template that's specific to Press Releases (page--type--press-release.tpl.php). This template modifies page-level markup related to the node. 
* To simplify markup for press release content, further customization is taking place in the node--press-release.tpl.php template file.
* To add the appropriate title/header markup to the sidebar items, block--sidebar_second.tpl.php was added.
* To cleanup excessive markup that prevented the styles from working, region--sidebar-second.tpl.php was added.


### To Create A New Press Release Block...

This would apply if you want to create a new sidebar block to display pieces of information about the Press Release. Note: This is not the only way to implement a block for this purpose, but will provide a general strategy that may be useful for future updates. This methodology uses Views and builds off the block we've already built for Press Release Contact Information.

When using this strategy, be careful to only update the setting for This block (override) and Apply (this display). For most of these changes, you do not want it to apply to other blocks/dislays.

1. Go to Structure >> Views  >> Single Press Release Blocks >> Edit
2. Click +Add >> Block
3. Update Display name if you want.
4. Update Title to whatever you want to display on the frontend.
5. Modify the Fields you wish to display
6. Update the Filter Criteria as necessary.
7. Ensure that the Contextaul Filters are setup correctly (Content: Nid, Provide Default value, Type = Content ID from URL)
8. Update the CSS class to use quick-links



### View Setup

#### Filter Criteria

Add Content: Published (Yes)
Add Content: Type (=Press Release);
Add Filter For Empty Display
1. Add Contact Email, Contact Name, Contact Phone
2. Operator = Is Not Empty
3. Add And/Or Rearrange
4. Create New Filter Group
5. Drag the Contact fields down into the new group
6. Change Operator to Or
