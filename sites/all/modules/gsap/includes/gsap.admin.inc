<?php

/**
 * @file
 * Admin page callbacks for the gsap module.
 */

/**
 * Form constructor for the gsap settings form.
 *
 * @ingroup forms
 */
function gsap_admin_settings() {
  $form['gsap_uncompressed'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use uncompressed version of library files.'),
    '#default_value' => variable_get('gsap_uncompressed', 0),
  );

  return system_settings_form($form);
}
