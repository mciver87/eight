North Carolina Quick Links View
=

What is it?
-----------

A module that provides a new Style and Row plugin for the views module that will
output a formatted list of links.  It will also format the date output if needed.

How does it work?
-----------------

When the view is set to use these two plugins, it will render the list in the
formatted way.

Need to knows.
--------------

This module was written with the intention of the the view to be displayed in
 block mode.  If block mode is not chosen, there is a chance that it will not
 work correctly.

 Also, most of the display settings for views are ignored.  This has been made
 to output the list a certain way, using the needed style classes and markup to
 look the way it needs to with the current North Carolina theme.

 How to use
 ----------

 1. Enable the module.
 2. Create or modify a view.
 3. Add a new display to the view, choosing "Block" as the display type.
 4. If you want a title to be displayed, enter a title in the "Title" section.
 5. For **Format**, select "Quick Links".
 6. For the Format settings, you can choose 1 of 3 appearance settings that
 alter the colors that are used.
 7. Select the fields you want to be included in the block.
 8. For the **Show** setting, choose "Quick Link".
 9. For the Show settings, select which field is the **Link Title** field.
    **NOTE:** it is best for this to be a node title field or a text field value.
 10. If there is a date field to be displayed, use the **Date Field** selector
 to select it.
 11. To make the block easier to be found, change the **Block name** setting to
 a value that makes sense.
 12. Once saved, a new block can be placed anywhere that a normal block can be
 that will display the view.

 **NOTE:** if modifying a current view, you are selecting "This block (override)"
 under the **For** select box, so the changes are only affecting the new Display.
 Also, you will know this is only affecting the current block display, because the
 **Apply** button will display "Apply (this display)".
