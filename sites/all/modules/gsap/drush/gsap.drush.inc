<?php

/**
 * @file
 * Drush integration for Gsap.
 */

/**
 * The Greensock plugin URI.
 */
define('GSAP_DOWNLOAD_URI', 'https://github.com/greensock/GreenSock-JS/archive/master.zip');
define('GSAP_DOWNLOAD_PREFIX', 'GreenSock-JS-');

/**
 * Implements hook_drush_command().
 *
 * In this hook, you specify which commands your
 * drush module makes available, what it does and
 * description.
 *
 * Notice how this structure closely resembles how
 * you define menu hooks.
 *
 * See `drush topic docs-commands` for a list of recognized keys.
 */
function gsap_drush_command() {
  $items = array();

  // The key in the $items array is the name of the command.
  $items['gsap-install'] = array(
    'callback' => 'gsap_drush_install',
    'description' => dt('Download and install the GSAP library.'),
    'bootstrap' => DRUSH_BOOTSTRAP_NONE,
    'arguments' => array(
      'path' => dt('Optional. A path to the download folder. If omitted Drush will use the default location.'),
    ),
    'aliases' => array('gsap'),
  );

  return $items;
}

/**
 * Implements hook_drush_help().
 *
 * This function is called whenever a drush user calls
 * 'drush help <name-of-your-command>'
 */
function gsap_drush_help($section) {
  switch ($section) {
    case 'drush:gsap-install':
      return dt('Download and install the GSAP library from github.com/greensock/GreenSock-JS, default location is sites/all/libraries.');
  }
}

/**
 * Command to download the GSAP library.
 */
function gsap_drush_install() {
  $args = func_get_args();

  $path = !empty($args[0]) ? $args[0] : 'sites/all/libraries';
  // Create the path if it does not exist.
  if (!is_dir($path)) {
    drush_op('mkdir', $path);
    drush_log(dt('Directory @path was created', array('@path' => $path)), 'notice');
  }

  // Set the directory to the download location.
  $olddir = getcwd();
  chdir($path);

  // Download the zip archive.
  $dirname = '';
  $filepath = drush_download_file(GSAP_DOWNLOAD_URI);

  if ($filepath) {
    $filename = basename($filepath);
    $dirname = GSAP_DOWNLOAD_PREFIX . basename($filepath, '.zip');

    // Remove any existing 'gsap' directory.
    if (is_dir($dirname) || is_dir('gsap')) {
      drush_delete_dir($dirname, TRUE);
      drush_delete_dir('gsap', TRUE);
      drush_log(dt('A existing GSAP library was deleted from @path', array('@path' => $path)), 'notice');
    }

    // Decompress the zip archive.
    drush_tarball_extract($filename);

    // Change the directory name to "colorbox" if needed.
    if ($dirname != 'gsap') {
      drush_move_dir($dirname, 'gsap', TRUE);
      $dirname = 'gsap';
    }
  }

  if (is_dir($dirname)) {
    drush_log(dt('GSAP library has been installed in @path', array('@path' => $path)), 'success');
  }
  else {
    drush_log(dt('Drush was unable to install the GSAP library to @path', array('@path' => $path)), 'error');
  }

  // Set working directory back to the previous working directory.
  chdir($olddir);
}
