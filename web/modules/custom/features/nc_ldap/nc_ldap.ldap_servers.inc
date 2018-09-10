<?php
/**
 * @file
 * nc_ldap.ldap_servers.inc
 */

/**
 * Implements hook_default_ldap_servers().
 */
function nc_ldap_default_ldap_servers() {
  $export = array();

  $ldap_servers_conf = new stdClass();
  $ldap_servers_conf->disabled = FALSE; /* Edit this to true to make a default ldap_servers_conf disabled initially */
  $ldap_servers_conf->api_version = 1;
  $ldap_servers_conf->sid = 'ncid_ldap';
  $ldap_servers_conf->name = 'ncid_ldap';
  $ldap_servers_conf->status = TRUE;
  $ldap_servers_conf->ldap_type = 'ad';
  $ldap_servers_conf->address = 'ldaps://sharedldapwdcpub.nc.gov';
  $ldap_servers_conf->port = 636;
  $ldap_servers_conf->tls = FALSE;
  $ldap_servers_conf->followrefs = TRUE;
  $ldap_servers_conf->bind_method = 1;
  $ldap_servers_conf->binddn = 'CN=svc_dit_drupal,OU=Service Accounts,OU=Support,DC=iapps,DC=ncads,DC=net';
  $ldap_servers_conf->bindpw = '$l6l3K#h';
  $ldap_servers_conf->basedn = array(
    0 => 'OU=Accounts,OU=Objects,DC=iapps,DC=ncads,DC=net',
    1 => 'OU=Ngroups,OU=Objects,DC=iapps,DC=ncads,DC=net',
  );
  $ldap_servers_conf->user_attr = 'samaccountname';
  $ldap_servers_conf->account_name_attr = '';
  $ldap_servers_conf->mail_attr = 'mail';
  $ldap_servers_conf->mail_template = '';
  $ldap_servers_conf->picture_attr = '';
  $ldap_servers_conf->unique_persistent_attr = 'ncguid';
  $ldap_servers_conf->unique_persistent_attr_binary = FALSE;
  $ldap_servers_conf->user_dn_expression = '';
  $ldap_servers_conf->ldap_to_drupal_user = '';
  $ldap_servers_conf->testing_drupal_username = 'palamb';
  $ldap_servers_conf->testing_drupal_user_dn = 'CN=jcmartinez,OU=Accounts,OU=Objects,DC=iapps,DC=ncads,DC=net';
  $ldap_servers_conf->grp_unused = FALSE;
  $ldap_servers_conf->grp_object_cat = 'group';
  $ldap_servers_conf->grp_nested = FALSE;
  $ldap_servers_conf->grp_user_memb_attr_exists = FALSE;
  $ldap_servers_conf->grp_user_memb_attr = '';
  $ldap_servers_conf->grp_memb_attr = 'member';
  $ldap_servers_conf->grp_memb_attr_match_user_attr = 'dn';
  $ldap_servers_conf->grp_derive_from_dn = FALSE;
  $ldap_servers_conf->grp_derive_from_dn_attr = '';
  $ldap_servers_conf->grp_test_grp_dn = 'CN=ITS-Drupal-Administrators,OU=Ngroups,OU=Objects,DC=iapps,DC=ncads,DC=net';
  $ldap_servers_conf->grp_test_grp_dn_writeable = '';
  $ldap_servers_conf->search_pagination = FALSE;
  $ldap_servers_conf->search_page_size = 1000;
  $ldap_servers_conf->weight = 0;
  $export['ncid_ldap'] = $ldap_servers_conf;

  return $export;
}
