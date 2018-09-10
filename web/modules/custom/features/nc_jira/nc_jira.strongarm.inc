<?php
/**
 * @file
 * nc_jira.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function nc_jira_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jira_issue_collector_code';
  $strongarm->value = '// Requires jQuery!
jQuery.ajax({
    url: "https://ncdigitalservices.atlassian.net/s/d41d8cd98f00b204e9800998ecf8427e-T/iq2rmf/b/c/3d70dff4c40bd20e976d5936642e2171/_/download/batch/com.atlassian.jira.collector.plugin.jira-issue-collector-plugin:issuecollector-embededjs/com.atlassian.jira.collector.plugin.jira-issue-collector-plugin:issuecollector-embededjs.js?locale=en-US&collectorId=f007ea1c",
    type: "get",
    cache: true,
    dataType: "script"
});';
  $export['jira_issue_collector_code'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jira_issue_collector_pages';
  $strongarm->value = '';
  $export['jira_issue_collector_pages'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jira_issue_collector_roles';
  $strongarm->value = array(
    1 => 0,
    2 => 2,
    3 => 3,
    4 => 4,
    5 => 5,
    6 => 6,
    7 => 7,
  );
  $export['jira_issue_collector_roles'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jira_issue_collector_url';
  $strongarm->value = 'https://ncdigitalservices.atlassian.net/s/d41d8cd98f00b204e9800998ecf8427e-T/iq2rmf/b/c/7ebd7d8b8f8cafb14c7b0966803e5701/_/download/batch/com.atlassian.jira.collector.plugin.jira-issue-collector-plugin:issuecollector/com.atlassian.jira.collector.plugin.jira-issue-collector-plugin:issuecollector.js?locale=en-US&collectorId=f007ea1c';
  $export['jira_issue_collector_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jira_issue_collector_visibility';
  $strongarm->value = '0';
  $export['jira_issue_collector_visibility'] = $strongarm;

  return $export;
}
