<?php
/**
 * @file
 * nc_webform_deter.default_webform_deter_pattern.inc
 */

/**
 * Implements hook_default_webform_deter_pattern().
 */
function nc_webform_deter_default_webform_deter_pattern() {
  $export = array();

  $pattern = new stdClass();
  $pattern->disabled = FALSE; /* Edit this to true to make a default pattern disabled initially */
  $pattern->api_version = 1;
  $pattern->machine_name = 'birthday_text';
  $pattern->name = 'Date of birth text';
  $pattern->pattern = '\\b(dob|birthday|date of birth)\\b';
  $pattern->description = 'text indicating a DOB might be present';
  $export['birthday_text'] = $pattern;

  $pattern = new stdClass();
  $pattern->disabled = FALSE; /* Edit this to true to make a default pattern disabled initially */
  $pattern->api_version = 1;
  $pattern->machine_name = 'credit_card';
  $pattern->name = 'Credit Card';
  $pattern->pattern = '\\b[\\d \\-]{13,19}\\b';
  $pattern->description = '13 to 16 digit strings of numbers, spaces or dashes. Covers standard groups of 4 and older series of 13 numbers, 15 numbers, etc';
  $export['credit_card'] = $pattern;

  $pattern = new stdClass();
  $pattern->disabled = FALSE; /* Edit this to true to make a default pattern disabled initially */
  $pattern->api_version = 1;
  $pattern->machine_name = 'credit_card_text';
  $pattern->name = 'Credit Card Text';
  $pattern->pattern = '\\b(card number|credit card)\\b';
  $pattern->description = 'Text indicating credit card might be present';
  $export['credit_card_text'] = $pattern;

  $pattern = new stdClass();
  $pattern->disabled = FALSE; /* Edit this to true to make a default pattern disabled initially */
  $pattern->api_version = 1;
  $pattern->machine_name = 'date_of_birth';
  $pattern->name = 'Date of birth ## ## ####';
  $pattern->pattern = '\\b\\d{1,2}[^\\d]\\d{1,2}[^\\d]\\d{2,4}\\b';
  $pattern->description = 'one or two digits, a non digit, one or two digits, a non digit, two or four digits';
  $export['date_of_birth'] = $pattern;

  $pattern = new stdClass();
  $pattern->disabled = FALSE; /* Edit this to true to make a default pattern disabled initially */
  $pattern->api_version = 1;
  $pattern->machine_name = 'drivers_license';
  $pattern->name = 'NC Driver\'s License';
  $pattern->pattern = '\\b\\d{8}\\b';
  $pattern->description = '8 consecutive digits';
  $export['drivers_license'] = $pattern;

  $pattern = new stdClass();
  $pattern->disabled = FALSE; /* Edit this to true to make a default pattern disabled initially */
  $pattern->api_version = 1;
  $pattern->machine_name = 'drivers_license_text';
  $pattern->name = 'NC Driver\'s License Text';
  $pattern->pattern = '\\b(license number|driver\'s license number)\\b';
  $pattern->description = 'Text indicating a driver\'s license number might be present';
  $export['drivers_license_text'] = $pattern;

  $pattern = new stdClass();
  $pattern->disabled = FALSE; /* Edit this to true to make a default pattern disabled initially */
  $pattern->api_version = 1;
  $pattern->machine_name = 'ssn';
  $pattern->name = 'SSN';
  $pattern->pattern = '\\b(\\d{3}-?\\d{2}-?\\d{4}|XXX-XX-XXXX)\\b';
  $pattern->description = 'SSN with or without dashes 123-45-6789 123456789.';
  $export['ssn'] = $pattern;

  $pattern = new stdClass();
  $pattern->disabled = FALSE; /* Edit this to true to make a default pattern disabled initially */
  $pattern->api_version = 1;
  $pattern->machine_name = 'ssn_text';
  $pattern->name = 'SSN Text';
  $pattern->pattern = '\\b(ssn|social security number)\\b';
  $pattern->description = 'text indicating a social security number might be present';
  $export['ssn_text'] = $pattern;

  return $export;
}
