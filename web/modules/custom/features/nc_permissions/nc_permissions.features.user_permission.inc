<?php
/**
 * @file
 * nc_permissions.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function nc_permissions_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access advanced_link autocomplete'.
  $permissions['access advanced_link autocomplete'] = array(
    'name' => 'access advanced_link autocomplete',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
      'event creator' => 'event creator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'advanced_link',
  );

  // Exported permission: 'access all views'.
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
    ),
    'module' => 'views',
  );

  // Exported permission: 'access all webform results'.
  $permissions['access all webform results'] = array(
    'name' => 'access all webform results',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'event creator' => 'event creator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access backup and migrate'.
  $permissions['access backup and migrate'] = array(
    'name' => 'access backup and migrate',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'access backup files'.
  $permissions['access backup files'] = array(
    'name' => 'access backup files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'access ckeditor link'.
  $permissions['access ckeditor link'] = array(
    'name' => 'access ckeditor link',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ckeditor_link',
  );

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'site admin' => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access content overview'.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'event creator' => 'event creator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access contextual links'.
  $permissions['access contextual links'] = array(
    'name' => 'access contextual links',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'contextual',
  );

  // Exported permission: 'access dashboard'.
  $permissions['access dashboard'] = array(
    'name' => 'access dashboard',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'dashboard',
  );

  // Exported permission: 'access devel information'.
  $permissions['access devel information'] = array(
    'name' => 'access devel information',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'devel',
  );

  // Exported permission: 'access own authorizations'.
  $permissions['access own authorizations'] = array(
    'name' => 'access own authorizations',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
    ),
    'module' => 'oauth_common',
  );

  // Exported permission: 'access own consumers'.
  $permissions['access own consumers'] = array(
    'name' => 'access own consumers',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
    ),
    'module' => 'oauth_common',
  );

  // Exported permission: 'access own webform results'.
  $permissions['access own webform results'] = array(
    'name' => 'access own webform results',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
      'event creator' => 'event creator',
      'site admin' => 'site admin',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access own webform submissions'.
  $permissions['access own webform submissions'] = array(
    'name' => 'access own webform submissions',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
      'event creator' => 'event creator',
      'site admin' => 'site admin',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access site in maintenance mode'.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(
      'administrator' => 'administrator',
      'site manager' => 'site manager',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access site reports'.
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access toolbar'.
  $permissions['access toolbar'] = array(
    'name' => 'access toolbar',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'event creator' => 'event creator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'toolbar',
  );

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'user',
  );

  // Exported permission: 'add authenticated twitter accounts'.
  $permissions['add authenticated twitter accounts'] = array(
    'name' => 'add authenticated twitter accounts',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'twitter',
  );

  // Exported permission: 'add twitter accounts'.
  $permissions['add twitter accounts'] = array(
    'name' => 'add twitter accounts',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'twitter',
  );

  // Exported permission: 'admin webform remote posts'.
  $permissions['admin webform remote posts'] = array(
    'name' => 'admin webform remote posts',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
    ),
    'module' => 'webform_remote_post',
  );

  // Exported permission: 'administer CAPTCHA settings'.
  $permissions['administer CAPTCHA settings'] = array(
    'name' => 'administer CAPTCHA settings',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'captcha',
  );

  // Exported permission: 'administer actions'.
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer addthis'.
  $permissions['administer addthis'] = array(
    'name' => 'administer addthis',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
    ),
    'module' => 'addthis',
  );

  // Exported permission: 'administer advanced pane settings'.
  $permissions['administer advanced pane settings'] = array(
    'name' => 'administer advanced pane settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer apps'.
  $permissions['administer apps'] = array(
    'name' => 'administer apps',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
    ),
    'module' => 'apps',
  );

  // Exported permission: 'administer backup and migrate'.
  $permissions['administer backup and migrate'] = array(
    'name' => 'administer backup and migrate',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'administer blocks'.
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(
      'administrator' => 'administrator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'block',
  );

  // Exported permission: 'administer boxes'.
  $permissions['administer boxes'] = array(
    'name' => 'administer boxes',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'boxes',
  );

  // Exported permission: 'administer breakpoints'.
  $permissions['administer breakpoints'] = array(
    'name' => 'administer breakpoints',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'breakpoints',
  );

  // Exported permission: 'administer ckeditor link'.
  $permissions['administer ckeditor link'] = array(
    'name' => 'administer ckeditor link',
    'roles' => array(
      'administrator' => 'administrator',
      'site manager' => 'site manager',
    ),
    'module' => 'ckeditor_link',
  );

  // Exported permission: 'administer consumers'.
  $permissions['administer consumers'] = array(
    'name' => 'administer consumers',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
    ),
    'module' => 'oauth_common',
  );

  // Exported permission: 'administer content translations'.
  $permissions['administer content translations'] = array(
    'name' => 'administer content translations',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'i18n_node',
  );

  // Exported permission: 'administer content types'.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer contexts'.
  $permissions['administer contexts'] = array(
    'name' => 'administer contexts',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'context_ui',
  );

  // Exported permission: 'administer delta'.
  $permissions['administer delta'] = array(
    'name' => 'administer delta',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
    ),
    'module' => 'delta_ui',
  );

  // Exported permission: 'administer features'.
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'administer field collections'.
  $permissions['administer field collections'] = array(
    'name' => 'administer field collections',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
    ),
    'module' => 'field_collection',
  );

  // Exported permission: 'administer fieldgroups'.
  $permissions['administer fieldgroups'] = array(
    'name' => 'administer fieldgroups',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'field_group',
  );

  // Exported permission: 'administer filters'.
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'administer follow'.
  $permissions['administer follow'] = array(
    'name' => 'administer follow',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'follow',
  );

  // Exported permission: 'administer google analytics'.
  $permissions['administer google analytics'] = array(
    'name' => 'administer google analytics',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'googleanalytics',
  );

  // Exported permission: 'administer image styles'.
  $permissions['administer image styles'] = array(
    'name' => 'administer image styles',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
    ),
    'module' => 'image',
  );

  // Exported permission: 'administer imce'.
  $permissions['administer imce'] = array(
    'name' => 'administer imce',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
    ),
    'module' => 'imce',
  );

  // Exported permission: 'administer languages'.
  $permissions['administer languages'] = array(
    'name' => 'administer languages',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'locale',
  );

  // Exported permission: 'administer menu'.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'menu',
  );

  // Exported permission: 'administer menu attributes'.
  $permissions['administer menu attributes'] = array(
    'name' => 'administer menu attributes',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
    ),
    'module' => 'menu_attributes',
  );

  // Exported permission: 'administer meta tags'.
  $permissions['administer meta tags'] = array(
    'name' => 'administer meta tags',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'administer microdata'.
  $permissions['administer microdata'] = array(
    'name' => 'administer microdata',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
    ),
    'module' => 'microdata',
  );

  // Exported permission: 'administer module filter'.
  $permissions['administer module filter'] = array(
    'name' => 'administer module filter',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
    ),
    'module' => 'module_filter',
  );

  // Exported permission: 'administer modules'.
  $permissions['administer modules'] = array(
    'name' => 'administer modules',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer nodequeue'.
  $permissions['administer nodequeue'] = array(
    'name' => 'administer nodequeue',
    'roles' => array(
      'administrator' => 'administrator',
      'site manager' => 'site manager',
    ),
    'module' => 'nodequeue',
  );

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'administrator' => 'administrator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer oauth'.
  $permissions['administer oauth'] = array(
    'name' => 'administer oauth',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
    ),
    'module' => 'oauth_common',
  );

  // Exported permission: 'administer page manager'.
  $permissions['administer page manager'] = array(
    'name' => 'administer page manager',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
    ),
    'module' => 'page_manager',
  );

  // Exported permission: 'administer pane access'.
  $permissions['administer pane access'] = array(
    'name' => 'administer pane access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer panels layouts'.
  $permissions['administer panels layouts'] = array(
    'name' => 'administer panels layouts',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer panels styles'.
  $permissions['administer panels styles'] = array(
    'name' => 'administer panels styles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer paragraphs bundles'.
  $permissions['administer paragraphs bundles'] = array(
    'name' => 'administer paragraphs bundles',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
    ),
    'module' => 'paragraphs',
  );

  // Exported permission: 'administer pathauto'.
  $permissions['administer pathauto'] = array(
    'name' => 'administer pathauto',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: 'administer permissions'.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer pictures'.
  $permissions['administer pictures'] = array(
    'name' => 'administer pictures',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'picture',
  );

  // Exported permission: 'administer recaptcha'.
  $permissions['administer recaptcha'] = array(
    'name' => 'administer recaptcha',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
    ),
    'module' => 'recaptcha',
  );

  // Exported permission: 'administer redirects'.
  $permissions['administer redirects'] = array(
    'name' => 'administer redirects',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'redirect',
  );

  // Exported permission: 'administer s3fs'.
  $permissions['administer s3fs'] = array(
    'name' => 'administer s3fs',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
    ),
    'module' => 's3fs',
  );

  // Exported permission: 'administer search_api'.
  $permissions['administer search_api'] = array(
    'name' => 'administer search_api',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
    ),
    'module' => 'search_api',
  );

  // Exported permission: 'administer shortcuts'.
  $permissions['administer shortcuts'] = array(
    'name' => 'administer shortcuts',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: 'administer site configuration'.
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer smtp module'.
  $permissions['administer smtp module'] = array(
    'name' => 'administer smtp module',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'smtp',
  );

  // Exported permission: 'administer software updates'.
  $permissions['administer software updates'] = array(
    'name' => 'administer software updates',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer taxonomy'.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'administer themes'.
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer twitter'.
  $permissions['administer twitter'] = array(
    'name' => 'administer twitter',
    'roles' => array(),
    'module' => 'twitter',
  );

  // Exported permission: 'administer twitter accounts'.
  $permissions['administer twitter accounts'] = array(
    'name' => 'administer twitter accounts',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'twitter',
  );

  // Exported permission: 'administer url aliases'.
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(
      'administrator' => 'administrator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'path',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer video styles'.
  $permissions['administer video styles'] = array(
    'name' => 'administer video styles',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
    ),
    'module' => 'video_embed_field',
  );

  // Exported permission: 'administer views'.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
    ),
    'module' => 'views',
  );

  // Exported permission: 'administer webform_deter'.
  $permissions['administer webform_deter'] = array(
    'name' => 'administer webform_deter',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
    ),
    'module' => 'webform_deter',
  );

  // Exported permission: 'administer xmlsitemap'.
  $permissions['administer xmlsitemap'] = array(
    'name' => 'administer xmlsitemap',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'xmlsitemap',
  );

  // Exported permission: 'assign all roles'.
  $permissions['assign all roles'] = array(
    'name' => 'assign all roles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign editor role'.
  $permissions['assign editor role'] = array(
    'name' => 'assign editor role',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign event creator role'.
  $permissions['assign event creator role'] = array(
    'name' => 'assign event creator role',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign publisher role'.
  $permissions['assign publisher role'] = array(
    'name' => 'assign publisher role',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign site admin role'.
  $permissions['assign site admin role'] = array(
    'name' => 'assign site admin role',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign site manager role'.
  $permissions['assign site manager role'] = array(
    'name' => 'assign site manager role',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'block IP addresses'.
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'system',
  );

  // Exported permission: 'bypass advanced aggregation'.
  $permissions['bypass advanced aggregation'] = array(
    'name' => 'bypass advanced aggregation',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'advagg',
  );

  // Exported permission: 'bypass maxlength'.
  $permissions['bypass maxlength'] = array(
    'name' => 'bypass maxlength',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
    ),
    'module' => 'maxlength',
  );

  // Exported permission: 'bypass node access'.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'cancel account'.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
    ),
    'module' => 'user',
  );

  // Exported permission: 'change follow link titles'.
  $permissions['change follow link titles'] = array(
    'name' => 'change follow link titles',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'follow',
  );

  // Exported permission: 'change layouts in place editing'.
  $permissions['change layouts in place editing'] = array(
    'name' => 'change layouts in place editing',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'change own username'.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
    ),
    'module' => 'user',
  );

  // Exported permission: 'clone node'.
  $permissions['clone node'] = array(
    'name' => 'clone node',
    'roles' => array(
      'administrator' => 'administrator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'clone',
  );

  // Exported permission: 'clone own nodes'.
  $permissions['clone own nodes'] = array(
    'name' => 'clone own nodes',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'clone',
  );

  // Exported permission: 'configure tablefield'.
  $permissions['configure tablefield'] = array(
    'name' => 'configure tablefield',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
    ),
    'module' => 'tablefield',
  );

  // Exported permission: 'context ajax block access'.
  $permissions['context ajax block access'] = array(
    'name' => 'context ajax block access',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'context_ui',
  );

  // Exported permission: 'create agency content'.
  $permissions['create agency content'] = array(
    'name' => 'create agency content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create any bean_entity_view bean'.
  $permissions['create any bean_entity_view bean'] = array(
    'name' => 'create any bean_entity_view bean',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'create any nc_alerts bean'.
  $permissions['create any nc_alerts bean'] = array(
    'name' => 'create any nc_alerts bean',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'create any nc_card_agency bean'.
  $permissions['create any nc_card_agency bean'] = array(
    'name' => 'create any nc_card_agency bean',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'create any nc_card_article bean'.
  $permissions['create any nc_card_article bean'] = array(
    'name' => 'create any nc_card_article bean',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'create any nc_card_cta bean'.
  $permissions['create any nc_card_cta bean'] = array(
    'name' => 'create any nc_card_cta bean',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'create any nc_card_event bean'.
  $permissions['create any nc_card_event bean'] = array(
    'name' => 'create any nc_card_event bean',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'create any nc_card_govt bean'.
  $permissions['create any nc_card_govt bean'] = array(
    'name' => 'create any nc_card_govt bean',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'create any nc_card_info bean'.
  $permissions['create any nc_card_info bean'] = array(
    'name' => 'create any nc_card_info bean',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'create any nc_card_person bean'.
  $permissions['create any nc_card_person bean'] = array(
    'name' => 'create any nc_card_person bean',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'create any nc_card_service bean'.
  $permissions['create any nc_card_service bean'] = array(
    'name' => 'create any nc_card_service bean',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'create any nc_card_stat bean'.
  $permissions['create any nc_card_stat bean'] = array(
    'name' => 'create any nc_card_stat bean',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'create any nc_card_video bean'.
  $permissions['create any nc_card_video bean'] = array(
    'name' => 'create any nc_card_video bean',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'create any nc_carousel bean'.
  $permissions['create any nc_carousel bean'] = array(
    'name' => 'create any nc_carousel bean',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'create any nc_quicklinks bean'.
  $permissions['create any nc_quicklinks bean'] = array(
    'name' => 'create any nc_quicklinks bean',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'create any nc_signup_constant_contact bean'.
  $permissions['create any nc_signup_constant_contact bean'] = array(
    'name' => 'create any nc_signup_constant_contact bean',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'create any nc_signup_icontact bean'.
  $permissions['create any nc_signup_icontact bean'] = array(
    'name' => 'create any nc_signup_icontact bean',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'create any nc_signup_mailchimp bean'.
  $permissions['create any nc_signup_mailchimp bean'] = array(
    'name' => 'create any nc_signup_mailchimp bean',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'create blog_entry content'.
  $permissions['create blog_entry content'] = array(
    'name' => 'create blog_entry content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create context_by_node'.
  $permissions['create context_by_node'] = array(
    'name' => 'create context_by_node',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'context_by_node',
  );

  // Exported permission: 'create data_table content'.
  $permissions['create data_table content'] = array(
    'name' => 'create data_table content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create document content'.
  $permissions['create document content'] = array(
    'name' => 'create document content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create event content'.
  $permissions['create event content'] = array(
    'name' => 'create event content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'event creator' => 'event creator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create media_gallery content'.
  $permissions['create media_gallery content'] = array(
    'name' => 'create media_gallery content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create photo content'.
  $permissions['create photo content'] = array(
    'name' => 'create photo content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create press_release content'.
  $permissions['create press_release content'] = array(
    'name' => 'create press_release content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create profile content'.
  $permissions['create profile content'] = array(
    'name' => 'create profile content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create services content'.
  $permissions['create services content'] = array(
    'name' => 'create services content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create site_page content'.
  $permissions['create site_page content'] = array(
    'name' => 'create site_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create url aliases'.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'path',
  );

  // Exported permission: 'create video content'.
  $permissions['create video content'] = array(
    'name' => 'create video content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create webform content'.
  $permissions['create webform content'] = array(
    'name' => 'create webform content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'customize shortcut links'.
  $permissions['customize shortcut links'] = array(
    'name' => 'customize shortcut links',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: 'delete all webform submissions'.
  $permissions['delete all webform submissions'] = array(
    'name' => 'delete all webform submissions',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'delete any agency content'.
  $permissions['delete any agency content'] = array(
    'name' => 'delete any agency content',
    'roles' => array(
      'administrator' => 'administrator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any bean_entity_view bean'.
  $permissions['delete any bean_entity_view bean'] = array(
    'name' => 'delete any bean_entity_view bean',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'delete any blog_entry content'.
  $permissions['delete any blog_entry content'] = array(
    'name' => 'delete any blog_entry content',
    'roles' => array(
      'administrator' => 'administrator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any data_table content'.
  $permissions['delete any data_table content'] = array(
    'name' => 'delete any data_table content',
    'roles' => array(
      'administrator' => 'administrator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any document content'.
  $permissions['delete any document content'] = array(
    'name' => 'delete any document content',
    'roles' => array(
      'administrator' => 'administrator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any event content'.
  $permissions['delete any event content'] = array(
    'name' => 'delete any event content',
    'roles' => array(
      'administrator' => 'administrator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any media_gallery content'.
  $permissions['delete any media_gallery content'] = array(
    'name' => 'delete any media_gallery content',
    'roles' => array(
      'administrator' => 'administrator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any nc_alerts bean'.
  $permissions['delete any nc_alerts bean'] = array(
    'name' => 'delete any nc_alerts bean',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'delete any nc_card_agency bean'.
  $permissions['delete any nc_card_agency bean'] = array(
    'name' => 'delete any nc_card_agency bean',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'delete any nc_card_article bean'.
  $permissions['delete any nc_card_article bean'] = array(
    'name' => 'delete any nc_card_article bean',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'delete any nc_card_cta bean'.
  $permissions['delete any nc_card_cta bean'] = array(
    'name' => 'delete any nc_card_cta bean',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'delete any nc_card_event bean'.
  $permissions['delete any nc_card_event bean'] = array(
    'name' => 'delete any nc_card_event bean',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'delete any nc_card_govt bean'.
  $permissions['delete any nc_card_govt bean'] = array(
    'name' => 'delete any nc_card_govt bean',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'delete any nc_card_info bean'.
  $permissions['delete any nc_card_info bean'] = array(
    'name' => 'delete any nc_card_info bean',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'delete any nc_card_person bean'.
  $permissions['delete any nc_card_person bean'] = array(
    'name' => 'delete any nc_card_person bean',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'delete any nc_card_service bean'.
  $permissions['delete any nc_card_service bean'] = array(
    'name' => 'delete any nc_card_service bean',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'delete any nc_card_stat bean'.
  $permissions['delete any nc_card_stat bean'] = array(
    'name' => 'delete any nc_card_stat bean',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'delete any nc_card_video bean'.
  $permissions['delete any nc_card_video bean'] = array(
    'name' => 'delete any nc_card_video bean',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'delete any nc_carousel bean'.
  $permissions['delete any nc_carousel bean'] = array(
    'name' => 'delete any nc_carousel bean',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'delete any nc_quicklinks bean'.
  $permissions['delete any nc_quicklinks bean'] = array(
    'name' => 'delete any nc_quicklinks bean',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'delete any nc_signup_constant_contact bean'.
  $permissions['delete any nc_signup_constant_contact bean'] = array(
    'name' => 'delete any nc_signup_constant_contact bean',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'delete any nc_signup_icontact bean'.
  $permissions['delete any nc_signup_icontact bean'] = array(
    'name' => 'delete any nc_signup_icontact bean',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'delete any nc_signup_mailchimp bean'.
  $permissions['delete any nc_signup_mailchimp bean'] = array(
    'name' => 'delete any nc_signup_mailchimp bean',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'delete any photo content'.
  $permissions['delete any photo content'] = array(
    'name' => 'delete any photo content',
    'roles' => array(
      'administrator' => 'administrator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any press_release content'.
  $permissions['delete any press_release content'] = array(
    'name' => 'delete any press_release content',
    'roles' => array(
      'administrator' => 'administrator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any profile content'.
  $permissions['delete any profile content'] = array(
    'name' => 'delete any profile content',
    'roles' => array(
      'administrator' => 'administrator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any services content'.
  $permissions['delete any services content'] = array(
    'name' => 'delete any services content',
    'roles' => array(
      'administrator' => 'administrator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any site_page content'.
  $permissions['delete any site_page content'] = array(
    'name' => 'delete any site_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any video content'.
  $permissions['delete any video content'] = array(
    'name' => 'delete any video content',
    'roles' => array(
      'administrator' => 'administrator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any webform content'.
  $permissions['delete any webform content'] = array(
    'name' => 'delete any webform content',
    'roles' => array(
      'administrator' => 'administrator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete backup files'.
  $permissions['delete backup files'] = array(
    'name' => 'delete backup files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'delete own agency content'.
  $permissions['delete own agency content'] = array(
    'name' => 'delete own agency content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own blog_entry content'.
  $permissions['delete own blog_entry content'] = array(
    'name' => 'delete own blog_entry content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own data_table content'.
  $permissions['delete own data_table content'] = array(
    'name' => 'delete own data_table content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own document content'.
  $permissions['delete own document content'] = array(
    'name' => 'delete own document content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own event content'.
  $permissions['delete own event content'] = array(
    'name' => 'delete own event content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own media_gallery content'.
  $permissions['delete own media_gallery content'] = array(
    'name' => 'delete own media_gallery content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own photo content'.
  $permissions['delete own photo content'] = array(
    'name' => 'delete own photo content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own press_release content'.
  $permissions['delete own press_release content'] = array(
    'name' => 'delete own press_release content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own profile content'.
  $permissions['delete own profile content'] = array(
    'name' => 'delete own profile content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own services content'.
  $permissions['delete own services content'] = array(
    'name' => 'delete own services content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own site_page content'.
  $permissions['delete own site_page content'] = array(
    'name' => 'delete own site_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own video content'.
  $permissions['delete own video content'] = array(
    'name' => 'delete own video content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own webform content'.
  $permissions['delete own webform content'] = array(
    'name' => 'delete own webform content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own webform submissions'.
  $permissions['delete own webform submissions'] = array(
    'name' => 'delete own webform submissions',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'delete revisions'.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      'administrator' => 'administrator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in agency_category'.
  $permissions['delete terms in agency_category'] = array(
    'name' => 'delete terms in agency_category',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in blog_category'.
  $permissions['delete terms in blog_category'] = array(
    'name' => 'delete terms in blog_category',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in blog_terms'.
  $permissions['delete terms in blog_terms'] = array(
    'name' => 'delete terms in blog_terms',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in card_keywords'.
  $permissions['delete terms in card_keywords'] = array(
    'name' => 'delete terms in card_keywords',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in document_collection'.
  $permissions['delete terms in document_collection'] = array(
    'name' => 'delete terms in document_collection',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in document_terms'.
  $permissions['delete terms in document_terms'] = array(
    'name' => 'delete terms in document_terms',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in event_organizer'.
  $permissions['delete terms in event_organizer'] = array(
    'name' => 'delete terms in event_organizer',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in event_terms'.
  $permissions['delete terms in event_terms'] = array(
    'name' => 'delete terms in event_terms',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in event_type'.
  $permissions['delete terms in event_type'] = array(
    'name' => 'delete terms in event_type',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in key_search_topics'.
  $permissions['delete terms in key_search_topics'] = array(
    'name' => 'delete terms in key_search_topics',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in nc_agency_department'.
  $permissions['delete terms in nc_agency_department'] = array(
    'name' => 'delete terms in nc_agency_department',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in nc_counties'.
  $permissions['delete terms in nc_counties'] = array(
    'name' => 'delete terms in nc_counties',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in press_release_terms'.
  $permissions['delete terms in press_release_terms'] = array(
    'name' => 'delete terms in press_release_terms',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in service_category'.
  $permissions['delete terms in service_category'] = array(
    'name' => 'delete terms in service_category',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in video_terms'.
  $permissions['delete terms in video_terms'] = array(
    'name' => 'delete terms in video_terms',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit all webform submissions'.
  $permissions['edit all webform submissions'] = array(
    'name' => 'edit all webform submissions',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'edit any agency content'.
  $permissions['edit any agency content'] = array(
    'name' => 'edit any agency content',
    'roles' => array(
      'administrator' => 'administrator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any bean_entity_view bean'.
  $permissions['edit any bean_entity_view bean'] = array(
    'name' => 'edit any bean_entity_view bean',
    'roles' => array(
      'administrator' => 'administrator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit any blog_entry content'.
  $permissions['edit any blog_entry content'] = array(
    'name' => 'edit any blog_entry content',
    'roles' => array(
      'administrator' => 'administrator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any data_table content'.
  $permissions['edit any data_table content'] = array(
    'name' => 'edit any data_table content',
    'roles' => array(
      'administrator' => 'administrator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any document content'.
  $permissions['edit any document content'] = array(
    'name' => 'edit any document content',
    'roles' => array(
      'administrator' => 'administrator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any event content'.
  $permissions['edit any event content'] = array(
    'name' => 'edit any event content',
    'roles' => array(
      'administrator' => 'administrator',
      'event creator' => 'event creator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any media_gallery content'.
  $permissions['edit any media_gallery content'] = array(
    'name' => 'edit any media_gallery content',
    'roles' => array(
      'administrator' => 'administrator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any nc_alerts bean'.
  $permissions['edit any nc_alerts bean'] = array(
    'name' => 'edit any nc_alerts bean',
    'roles' => array(
      'administrator' => 'administrator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit any nc_card_agency bean'.
  $permissions['edit any nc_card_agency bean'] = array(
    'name' => 'edit any nc_card_agency bean',
    'roles' => array(
      'administrator' => 'administrator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit any nc_card_article bean'.
  $permissions['edit any nc_card_article bean'] = array(
    'name' => 'edit any nc_card_article bean',
    'roles' => array(
      'administrator' => 'administrator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit any nc_card_cta bean'.
  $permissions['edit any nc_card_cta bean'] = array(
    'name' => 'edit any nc_card_cta bean',
    'roles' => array(
      'administrator' => 'administrator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit any nc_card_event bean'.
  $permissions['edit any nc_card_event bean'] = array(
    'name' => 'edit any nc_card_event bean',
    'roles' => array(
      'administrator' => 'administrator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit any nc_card_govt bean'.
  $permissions['edit any nc_card_govt bean'] = array(
    'name' => 'edit any nc_card_govt bean',
    'roles' => array(
      'administrator' => 'administrator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit any nc_card_info bean'.
  $permissions['edit any nc_card_info bean'] = array(
    'name' => 'edit any nc_card_info bean',
    'roles' => array(
      'administrator' => 'administrator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit any nc_card_person bean'.
  $permissions['edit any nc_card_person bean'] = array(
    'name' => 'edit any nc_card_person bean',
    'roles' => array(
      'administrator' => 'administrator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit any nc_card_service bean'.
  $permissions['edit any nc_card_service bean'] = array(
    'name' => 'edit any nc_card_service bean',
    'roles' => array(
      'administrator' => 'administrator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit any nc_card_stat bean'.
  $permissions['edit any nc_card_stat bean'] = array(
    'name' => 'edit any nc_card_stat bean',
    'roles' => array(
      'administrator' => 'administrator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit any nc_card_video bean'.
  $permissions['edit any nc_card_video bean'] = array(
    'name' => 'edit any nc_card_video bean',
    'roles' => array(
      'administrator' => 'administrator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit any nc_carousel bean'.
  $permissions['edit any nc_carousel bean'] = array(
    'name' => 'edit any nc_carousel bean',
    'roles' => array(
      'administrator' => 'administrator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit any nc_quicklinks bean'.
  $permissions['edit any nc_quicklinks bean'] = array(
    'name' => 'edit any nc_quicklinks bean',
    'roles' => array(
      'administrator' => 'administrator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit any nc_signup_constant_contact bean'.
  $permissions['edit any nc_signup_constant_contact bean'] = array(
    'name' => 'edit any nc_signup_constant_contact bean',
    'roles' => array(
      'administrator' => 'administrator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit any nc_signup_icontact bean'.
  $permissions['edit any nc_signup_icontact bean'] = array(
    'name' => 'edit any nc_signup_icontact bean',
    'roles' => array(
      'administrator' => 'administrator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit any nc_signup_mailchimp bean'.
  $permissions['edit any nc_signup_mailchimp bean'] = array(
    'name' => 'edit any nc_signup_mailchimp bean',
    'roles' => array(
      'administrator' => 'administrator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit any photo content'.
  $permissions['edit any photo content'] = array(
    'name' => 'edit any photo content',
    'roles' => array(
      'administrator' => 'administrator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any press_release content'.
  $permissions['edit any press_release content'] = array(
    'name' => 'edit any press_release content',
    'roles' => array(
      'administrator' => 'administrator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any profile content'.
  $permissions['edit any profile content'] = array(
    'name' => 'edit any profile content',
    'roles' => array(
      'administrator' => 'administrator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any services content'.
  $permissions['edit any services content'] = array(
    'name' => 'edit any services content',
    'roles' => array(
      'administrator' => 'administrator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any site_page content'.
  $permissions['edit any site_page content'] = array(
    'name' => 'edit any site_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any user follow links'.
  $permissions['edit any user follow links'] = array(
    'name' => 'edit any user follow links',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
    ),
    'module' => 'follow',
  );

  // Exported permission: 'edit any video content'.
  $permissions['edit any video content'] = array(
    'name' => 'edit any video content',
    'roles' => array(
      'administrator' => 'administrator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any webform content'.
  $permissions['edit any webform content'] = array(
    'name' => 'edit any webform content',
    'roles' => array(
      'administrator' => 'administrator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit boxes'.
  $permissions['edit boxes'] = array(
    'name' => 'edit boxes',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'boxes',
  );

  // Exported permission: 'edit meta tags'.
  $permissions['edit meta tags'] = array(
    'name' => 'edit meta tags',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit node machine name'.
  $permissions['edit node machine name'] = array(
    'name' => 'edit node machine name',
    'roles' => array(
      'administrator' => 'administrator',
      'site manager' => 'site manager',
    ),
    'module' => 'defaultcontent',
  );

  // Exported permission: 'edit own agency content'.
  $permissions['edit own agency content'] = array(
    'name' => 'edit own agency content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own blog_entry content'.
  $permissions['edit own blog_entry content'] = array(
    'name' => 'edit own blog_entry content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own data_table content'.
  $permissions['edit own data_table content'] = array(
    'name' => 'edit own data_table content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own document content'.
  $permissions['edit own document content'] = array(
    'name' => 'edit own document content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own event content'.
  $permissions['edit own event content'] = array(
    'name' => 'edit own event content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'event creator' => 'event creator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own follow links'.
  $permissions['edit own follow links'] = array(
    'name' => 'edit own follow links',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
    ),
    'module' => 'follow',
  );

  // Exported permission: 'edit own media_gallery content'.
  $permissions['edit own media_gallery content'] = array(
    'name' => 'edit own media_gallery content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own photo content'.
  $permissions['edit own photo content'] = array(
    'name' => 'edit own photo content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own press_release content'.
  $permissions['edit own press_release content'] = array(
    'name' => 'edit own press_release content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own profile content'.
  $permissions['edit own profile content'] = array(
    'name' => 'edit own profile content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own services content'.
  $permissions['edit own services content'] = array(
    'name' => 'edit own services content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own site_page content'.
  $permissions['edit own site_page content'] = array(
    'name' => 'edit own site_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own video content'.
  $permissions['edit own video content'] = array(
    'name' => 'edit own video content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own webform content'.
  $permissions['edit own webform content'] = array(
    'name' => 'edit own webform content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own webform submissions'.
  $permissions['edit own webform submissions'] = array(
    'name' => 'edit own webform submissions',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'edit site follow links'.
  $permissions['edit site follow links'] = array(
    'name' => 'edit site follow links',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'follow',
  );

  // Exported permission: 'edit terms in agency_category'.
  $permissions['edit terms in agency_category'] = array(
    'name' => 'edit terms in agency_category',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in blog_category'.
  $permissions['edit terms in blog_category'] = array(
    'name' => 'edit terms in blog_category',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in blog_terms'.
  $permissions['edit terms in blog_terms'] = array(
    'name' => 'edit terms in blog_terms',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in card_keywords'.
  $permissions['edit terms in card_keywords'] = array(
    'name' => 'edit terms in card_keywords',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in document_collection'.
  $permissions['edit terms in document_collection'] = array(
    'name' => 'edit terms in document_collection',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in document_terms'.
  $permissions['edit terms in document_terms'] = array(
    'name' => 'edit terms in document_terms',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in event_organizer'.
  $permissions['edit terms in event_organizer'] = array(
    'name' => 'edit terms in event_organizer',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in event_terms'.
  $permissions['edit terms in event_terms'] = array(
    'name' => 'edit terms in event_terms',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in event_type'.
  $permissions['edit terms in event_type'] = array(
    'name' => 'edit terms in event_type',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in key_search_topics'.
  $permissions['edit terms in key_search_topics'] = array(
    'name' => 'edit terms in key_search_topics',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in nc_agency_department'.
  $permissions['edit terms in nc_agency_department'] = array(
    'name' => 'edit terms in nc_agency_department',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in nc_counties'.
  $permissions['edit terms in nc_counties'] = array(
    'name' => 'edit terms in nc_counties',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in press_release_terms'.
  $permissions['edit terms in press_release_terms'] = array(
    'name' => 'edit terms in press_release_terms',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in service_category'.
  $permissions['edit terms in service_category'] = array(
    'name' => 'edit terms in service_category',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in video_terms'.
  $permissions['edit terms in video_terms'] = array(
    'name' => 'edit terms in video_terms',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'execute php code'.
  $permissions['execute php code'] = array(
    'name' => 'execute php code',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
    ),
    'module' => 'devel',
  );

  // Exported permission: 'export tablefield'.
  $permissions['export tablefield'] = array(
    'name' => 'export tablefield',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'tablefield',
  );

  // Exported permission: 'generate features'.
  $permissions['generate features'] = array(
    'name' => 'generate features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'manage features'.
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'manipulate all queues'.
  $permissions['manipulate all queues'] = array(
    'name' => 'manipulate all queues',
    'roles' => array(
      'administrator' => 'administrator',
      'site manager' => 'site manager',
    ),
    'module' => 'nodequeue',
  );

  // Exported permission: 'manipulate queues'.
  $permissions['manipulate queues'] = array(
    'name' => 'manipulate queues',
    'roles' => array(
      'administrator' => 'administrator',
      'site manager' => 'site manager',
    ),
    'module' => 'nodequeue',
  );

  // Exported permission: 'notify of path changes'.
  $permissions['notify of path changes'] = array(
    'name' => 'notify of path changes',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: 'oauth authorize any consumers'.
  $permissions['oauth authorize any consumers'] = array(
    'name' => 'oauth authorize any consumers',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
    ),
    'module' => 'oauth_common',
  );

  // Exported permission: 'oauth register any consumers'.
  $permissions['oauth register any consumers'] = array(
    'name' => 'oauth register any consumers',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
    ),
    'module' => 'oauth_common',
  );

  // Exported permission: 'opt-in or out of tracking'.
  $permissions['opt-in or out of tracking'] = array(
    'name' => 'opt-in or out of tracking',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'googleanalytics',
  );

  // Exported permission: 'perform backup'.
  $permissions['perform backup'] = array(
    'name' => 'perform backup',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'rebuild tablefield'.
  $permissions['rebuild tablefield'] = array(
    'name' => 'rebuild tablefield',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
    ),
    'module' => 'tablefield',
  );

  // Exported permission: 'rename features'.
  $permissions['rename features'] = array(
    'name' => 'rename features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'restore from backup'.
  $permissions['restore from backup'] = array(
    'name' => 'restore from backup',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'revert revisions'.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      'administrator' => 'administrator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'schedule revisions'.
  $permissions['schedule revisions'] = array(
    'name' => 'schedule revisions',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
    ),
    'module' => 'revision_scheduler',
  );

  // Exported permission: 'select account cancellation method'.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
    ),
    'module' => 'user',
  );

  // Exported permission: 'skip CAPTCHA'.
  $permissions['skip CAPTCHA'] = array(
    'name' => 'skip CAPTCHA',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'captcha',
  );

  // Exported permission: 'switch shortcut sets'.
  $permissions['switch shortcut sets'] = array(
    'name' => 'switch shortcut sets',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: 'switch users'.
  $permissions['switch users'] = array(
    'name' => 'switch users',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
    ),
    'module' => 'devel',
  );

  // Exported permission: 'translate admin strings'.
  $permissions['translate admin strings'] = array(
    'name' => 'translate admin strings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'i18n_string',
  );

  // Exported permission: 'translate content'.
  $permissions['translate content'] = array(
    'name' => 'translate content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'translation',
  );

  // Exported permission: 'translate interface'.
  $permissions['translate interface'] = array(
    'name' => 'translate interface',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'locale',
  );

  // Exported permission: 'translate user-defined strings'.
  $permissions['translate user-defined strings'] = array(
    'name' => 'translate user-defined strings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'i18n_string',
  );

  // Exported permission: 'use PHP for tracking visibility'.
  $permissions['use PHP for tracking visibility'] = array(
    'name' => 'use PHP for tracking visibility',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
    ),
    'module' => 'googleanalytics',
  );

  // Exported permission: 'use context field editor'.
  $permissions['use context field editor'] = array(
    'name' => 'use context field editor',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'context_field',
  );

  // Exported permission: 'use ctools import'.
  $permissions['use ctools import'] = array(
    'name' => 'use ctools import',
    'roles' => array(),
    'module' => 'ctools',
  );

  // Exported permission: 'use entity autocomplete'.
  $permissions['use entity autocomplete'] = array(
    'name' => 'use entity autocomplete',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'entity_autocomplete',
  );

  // Exported permission: 'use ipe with page manager'.
  $permissions['use ipe with page manager'] = array(
    'name' => 'use ipe with page manager',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use page manager'.
  $permissions['use page manager'] = array(
    'name' => 'use page manager',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
    ),
    'module' => 'page_manager',
  );

  // Exported permission: 'use panels caching features'.
  $permissions['use panels caching features'] = array(
    'name' => 'use panels caching features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use panels dashboard'.
  $permissions['use panels dashboard'] = array(
    'name' => 'use panels dashboard',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use panels in place editing'.
  $permissions['use panels in place editing'] = array(
    'name' => 'use panels in place editing',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use panels locks'.
  $permissions['use panels locks'] = array(
    'name' => 'use panels locks',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use text format filtered_html'.
  $permissions['use text format filtered_html'] = array(
    'name' => 'use text format filtered_html',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'site admin' => 'site admin',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format full_html'.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      'administrator' => 'administrator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'view addthis'.
  $permissions['view addthis'] = array(
    'name' => 'view addthis',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
      'event creator' => 'event creator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'addthis',
  );

  // Exported permission: 'view any bean_entity_view bean'.
  $permissions['view any bean_entity_view bean'] = array(
    'name' => 'view any bean_entity_view bean',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any nc_alerts bean'.
  $permissions['view any nc_alerts bean'] = array(
    'name' => 'view any nc_alerts bean',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any nc_card_agency bean'.
  $permissions['view any nc_card_agency bean'] = array(
    'name' => 'view any nc_card_agency bean',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any nc_card_article bean'.
  $permissions['view any nc_card_article bean'] = array(
    'name' => 'view any nc_card_article bean',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'site admin' => 'site admin',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any nc_card_cta bean'.
  $permissions['view any nc_card_cta bean'] = array(
    'name' => 'view any nc_card_cta bean',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'site admin' => 'site admin',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any nc_card_event bean'.
  $permissions['view any nc_card_event bean'] = array(
    'name' => 'view any nc_card_event bean',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any nc_card_govt bean'.
  $permissions['view any nc_card_govt bean'] = array(
    'name' => 'view any nc_card_govt bean',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any nc_card_info bean'.
  $permissions['view any nc_card_info bean'] = array(
    'name' => 'view any nc_card_info bean',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any nc_card_person bean'.
  $permissions['view any nc_card_person bean'] = array(
    'name' => 'view any nc_card_person bean',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any nc_card_service bean'.
  $permissions['view any nc_card_service bean'] = array(
    'name' => 'view any nc_card_service bean',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any nc_card_stat bean'.
  $permissions['view any nc_card_stat bean'] = array(
    'name' => 'view any nc_card_stat bean',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'site admin' => 'site admin',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any nc_card_video bean'.
  $permissions['view any nc_card_video bean'] = array(
    'name' => 'view any nc_card_video bean',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any nc_quicklinks bean'.
  $permissions['view any nc_quicklinks bean'] = array(
    'name' => 'view any nc_quicklinks bean',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'site admin' => 'site admin',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any nc_signup_constant_contact bean'.
  $permissions['view any nc_signup_constant_contact bean'] = array(
    'name' => 'view any nc_signup_constant_contact bean',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any nc_signup_icontact bean'.
  $permissions['view any nc_signup_icontact bean'] = array(
    'name' => 'view any nc_signup_icontact bean',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any nc_signup_mailchimp bean'.
  $permissions['view any nc_signup_mailchimp bean'] = array(
    'name' => 'view any nc_signup_mailchimp bean',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'event creator' => 'event creator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view pane admin links'.
  $permissions['view pane admin links'] = array(
    'name' => 'view pane admin links',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'view revisions'.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      'administrator' => 'administrator',
      'publisher' => 'publisher',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      'administrator' => 'administrator',
      'site admin' => 'site admin',
      'site manager' => 'site manager',
      'publisher' => 'publisher',
      'editor' => 'editor',
    ),
    'module' => 'system',
  );

  return $permissions;
}
