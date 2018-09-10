# Views Term Link Formatter

## Overview

This allows you to format term reference field content to link to Views pages with exposed forms for the given vocabulary.

## Usage

This module allows you to setup formatters for term references so that the term can link to a specific page setup using Views. This provides functionality so that if the view supposed exposed form (filtering) on the term reference, the link will take users directly to the filtered view.

For instance, if you have a Blog content type where you specify one or more categories, and a blog listing page implemented with Views, this formatter will allow you to list an individual blog item's categories. The categories will link back to the Views list, with the exposed form set to match the category, so that the blog listing shows only blog items of the selected category.

## How To

### Setup Formatter On A Field

**NOTE**: This only applies and appears for Term Reference (taxonomy_term_reference).
    
    1. Login as a user with rights to modify a content type
    2. Go to Structure >> Content Types >> manage display (next to appropriate content type)
    3. Select the appropriate display(s), such as Default
    4. Locate your Term Reference field, choose Views Term Link as the formatter
    5. Open the formatter settings
    6. Select the View => Display you want to use
    7. Enable the link (make sure the checkbox is checked)
    8. Specify anchor class(es) that will be applied to the link anchor (<a>), classes should be separated with whitespace
    9. Specify the wrapping element type, such as "span" or "div"
    10. Specify wrapping element class(es), classes should be separated with whitespace
    11. Update any other Style settings
    12. Click update
    13. Be sure to save the display when done
    14. You may need to clear the cache for changes to take effect


### Setup Exposed Form Filter Criteria

    1. Login as a user with rights to modify a view
    2. Go to Structure >> Views, click to edit the view you plan to link to
    3. Select the appropriate display
    4. In the Filter Criteria, identify the exposed field, click it to edit
    5. Ensure that either "Is one of" is selected as the operator OR that "Expose operator" is selected
    6. Click to apply
    7. Be sure to save the view
    8. You may need to clear the cache for changes to take effect



## Installation

Installation is currently presumed to be via code inclusion in the site project. The module is currently not available in the Drupal module repository.

## Deployment

    * Deploy code to server
    * Install & enable this module:
        * Enable through the Drupal administration page (Modules)
        * Enable via drush: drush pm-enable views_term_link_formatter -y
    * Setup field(s) on content types to use the Views Term Link for the display


## Dependencies

    * Views module
    * Drupal 7
    

## Known Issues & Limitations

    * Supports Page displays only.
    * Supports numeric (tid) relationships only.
    * The formatter settings where View|Display is selected is not filtered by displays with appropriate exposed forms.
    * The Views Display Exposed Filter must be setup to use the "Is one of" operator OR "Expose operator" must be checked.


## Additional Information


## External Links

    * [Views Module](https://www.drupal.org/project/views)
    

## Nice To Have / Future Enhancements

    * In the formatter settings, the View|Display select list should be filtered to show only displays with an appropriate filter (matching vocabulary).


## TODO

    * Test with different reference types and exposed form settings.
    * Test on multiple sites.
    * Acceptance criteria
    * Update this README!!!!