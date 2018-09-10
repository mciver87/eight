# Services & Information

## Overview

This provides a Services and Information listing page, as well as landing pages for services and information.

This is being used on the main [NC.GOV](https://www.nc.gov/) website only. It is currently not intended for use on other sites.

## Updates

**2016-04-29**

ABT#614 NC.gov Information and Services pages reformatted wtih the design that was originally intended, see https://projects.invisionapp.com/share/A23BETRCN#/screens/65167234

This update refactors the landing page to include a header region for content on the top-level taxonomy term (i.e. Budget and Taxes), and to provide autosubmit on the user's filter selections.

## How To 

### Update Taxonomy Content
  
    1. Login as admin with permissions to edit taxonomy
    2. Go to Structure >> Taxonomy
    3. Locate Service category, click "list terms"
    4. Locate a top-level (parent) category (such as Budget and Taxes), click "edit"
    5. Update content in the Description field, this is what appears in the top area of the page
    6. Be sure to save
    7. You may need to clear the cache after updating content before it appears on the frontend
    
### View Services
    
    1. On frontend, click Services link in main menu
    2. Click on a service, to get to the landing page
    
    
## Deployment

Services and Information currently resides on the main nc.gov site only. After a code push, content will need to be entered for top-level categories (see HOW TO - Update Taxonomy Content).
