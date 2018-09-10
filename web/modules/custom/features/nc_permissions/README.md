NC Permissions
==============

This module used to be a features module, however due to issues with the
features_override module and other modules attempting to set permissions, we
have changed the way the permissions are set for all of the sites.  The
permissions are now set through a csv file stored in the module.  This csv file
can be used to set all of the permissions of the site.  Also, you can export
a csv file to make it easier to update the permissions file.

Exporting Permissions CSV File
------------------------------

You can export all of the current permissions of a site if you have the correct
role for your account (currently only administrators can do this).  To export
the permissions, do the following:

 1.  Log in the admin
 2.  Go to the following url: admin/nc_permissions/export
 3.  The exported CSV file will download to your computer

CSV File Format
---------------

The permissions CSV File should contain the following headings in the first row
of the file:

 * **module** (optional) - This is the name of the module the permission belongs
    to.
 * **name** (optional) - This is the "readable name" of the permission.
 * **permission** - This is the machine_name of the permission.
 * **role columns** - Each role should get its own column, using the
    machine_name of the role. When the permission should be assigned to the
    role, place a 1 in this column.

If you export the permissions as mentioned above you will get a properly formed
CSV file.

Updating All Permissions
========================

These are the steps you should take when you want to update all of the
permissions for the sites.  This would be the most common way:

1.  Log into the admin section of the site.
2.  Set all of the permissions as desired in the Users -> Permissions section
    of the site.
3.  Once all of the permissions have been saved, export the permissions CSV
    file by going to admin/nc_permissions/export and save the file.
    * **NOTE:** Some sites have more permissions than others.  It is okay to
        have permissions listed that the other sites do not have.  When the
        import is ran, it will skip the permissions that the site does not
        have but still apply them to the sites that do have them.
4.  If needed, you can modify the downloaded CSV file to apply permissions to
    to other roles.
5.  Save the newly downloaded file as "nc_permissions.csv" at
    src/profiles/north_carolina/modules/features/nc_permissions/permission_csvs/
6.  Update nc_permissions.install to have the following Where X is replaced
    with the next update number:
```
function nc_permissions_update_710X() {
    _nc_permissions_import_default_csv();
}
```
7.  Run `drush updatedb` to have the updated permissions apply to other sites.

Updating Some Permissions
-------------------------
If you only want to update some permissions, or you want to use a different CSV
file to update the permissions follow all of the steps above, but modify the
CSV file to contain only the permissions and roles you want to modify. Once you
get to creating the update function, make it like this:
```
function nc_permissions_update_710X() {
    $path = "PATH TO CSV FILE"
    _nc_permissions_import_permissions_csv($path);
}
```