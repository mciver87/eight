# NC User Messages Module

## Overview
The NC User Messages module allows messages to be shared to all users throughout
the Digital Commons system. Messages can be set up so only users with specific
roles can view them.  The messages appear on their user page ({domain}/user)
after they log in. This is achieved by two different modules:

1. **NC User Messages** - used to display the user messages
2. **NC User Messages Admin** - used to manage and distribute the messages.

## NC User Messages
This module is used to display the messages to users when they login.  It parses
the JSON returned by the messages returned by
`{NC User Messages Path}/nc-user-messages/messages/{role}/{Messages Key}`.

### System Config Settings
This module provide system config settings that can be set at
`/admin/config/system/nc-user-messages`. These settings are:

* **NC User Messages Path** - the base path to the website that is managing the
messages. The current default value for this is `https://www.nc.gov`.
* **Messages Key** - They key required to receive the messages. This value must
match the messages key value on the site that is managing the messages.

### Required Permissions
To set these config settings, the user must have the
`administrator nc_user_messages config` permission.

## NC User Messages Admin
This is a sub module of NC User Messages can be found in the
`nc_user_messages/modules` directory. This module is used to manage the messages
to be displayed to the users. It serves the messages to the other sites through
this url: `{domain}/nc-user-messages/messages/{role}/{Messages Key}`. The
message key must match the system config **Messages Key** setting for messages
 to be returned.

**This module should only be enabled on one site at a time.**

### Managing Messages
Messages can be created, modified, and deleted by going to
`{domain}/admin/config/system/nc-user-messages/messages` or by clicking on the `NC User Messages` link
in the admin menu. Page provides the following:

* **Add User Message link** - click on this to create a new user message
* **Delete Expired Messages link** - when clicked on and confirmed, will delete
any messages where the messages's end date has passed. If there are no expired
messages, `There are currently no expired messages.` will appear when clicked on.
* Table of all messages with sorting and edit/delete links.

#### Messages Fields
* **Message Title** - the title of the message.
* **Message** - the message to be sent.
* **Roles** - the user roles the user must have to see the message.
* **Live Date** - when the message is to start appearing.
* **End Date** - when the message is to stop appearing.

#### Required Permissions
The following permissions are required to fully manage the messages:

* **administrator nc_user_messages config** - to set the config settings
* **manage nc_user_messages** - access message management pages
* **create nc_user_message content** - create the messages
* **edit own nc_user_message content** - edit messages created by the user
* **edit any nc_user_message content** - edit any message
* **delete own nc_user_message content** - delete own messages
* **delete any nc_user_message content** - delete any message