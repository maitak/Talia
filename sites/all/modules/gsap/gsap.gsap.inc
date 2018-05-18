<?php

/**
 * @file
 * Implementation of the GSAP hooks.
 */

/**
 * Implements hook_gsap_components_info().
 *
 * Returns array with default GSAP components out the box.
 * Each component should be keyed with unique name and described
 * with the next properties:
 *  - group: group of GSAP component, defined by constant.
 *    Avalilable constants are:
 *    - GSAP_COMPONENT_GROUP_CORE: Core components likes TweenLite or TweenMax.
 *    - GSAP_COMPONENT_GROUP_EASING: Easing related components likes EasePack.
 *    - GSAP_COMPONENT_GROUP_UTIL: Different utilities likes Draggable.
 *    - GSAP_COMPONENT_GROUP_PLUGIN: Different GSAP plugins likes CSSRulePlugin.
 *  - filename: name of file without extension and '.min' suffix;
 *
 * @see hook_hook_info()
 */
function gsap_gsap_components_info() {
  $components = array(
    // Core components. TweenLite doesn't included, because it's a
    // base component and added directly in gsap_components().
    'tweenmax' => array(
      'group' => GSAP_COMPONENT_GROUP_CORE,
      'filename' => 'TweenMax',
    ),
    'timelinelite' => array(
      'group' => GSAP_COMPONENT_GROUP_CORE,
      'filename' => 'TimelineLite',
    ),
    'timelinemax' => array(
      'group' => GSAP_COMPONENT_GROUP_CORE,
      'filename' => 'TimelineMax',
    ),
    'jquerygsap' => array(
      'group' => GSAP_COMPONENT_GROUP_CORE,
      'filename' => 'jquery.gsap',
    ),
    // Easing components.
    'easepack' => array(
      'group' => GSAP_COMPONENT_GROUP_EASING,
      'filename' => 'EasePack',
    ),
    // Utility components.
    'draggable' => array(
      'group' => GSAP_COMPONENT_GROUP_UTIL,
      'filename' => 'Draggable',
    ),
    // Plugin components.
    'attr' => array(
      'group' => GSAP_COMPONENT_GROUP_PLUGIN,
      'filename' => 'AttrPlugin',
    ),
    'bezier' => array(
      'group' => GSAP_COMPONENT_GROUP_PLUGIN,
      'filename' => 'BezierPlugin',
    ),
    'colorprops' => array(
      'group' => GSAP_COMPONENT_GROUP_PLUGIN,
      'filename' => 'ColorPropsPlugin',
    ),
    'css' => array(
      'group' => GSAP_COMPONENT_GROUP_PLUGIN,
      'filename' => 'CSSPlugin',
    ),
    'cssrule' => array(
      'group' => GSAP_COMPONENT_GROUP_PLUGIN,
      'filename' => 'CSSRulePlugin',
    ),
    'directionalrotation' => array(
      'group' => GSAP_COMPONENT_GROUP_PLUGIN,
      'filename' => 'DirectionalRotationPlugin',
    ),
    'easel' => array(
      'group' => GSAP_COMPONENT_GROUP_PLUGIN,
      'filename' => 'EaselPlugin',
    ),
    'endarray' => array(
      'group' => GSAP_COMPONENT_GROUP_PLUGIN,
      'filename' => 'EndArrayPlugin',
    ),
    'kinetic' => array(
      'group' => GSAP_COMPONENT_GROUP_PLUGIN,
      'filename' => 'KineticPlugin',
    ),
    'raphael' => array(
      'group' => GSAP_COMPONENT_GROUP_PLUGIN,
      'filename' => 'RaphaelPlugin',
    ),
    'roundprops' => array(
      'group' => GSAP_COMPONENT_GROUP_PLUGIN,
      'filename' => 'RoundPropsPlugin',
    ),
    'scrollto' => array(
      'group' => GSAP_COMPONENT_GROUP_PLUGIN,
      'filename' => 'ScrollToPlugin',
    ),
    'text' => array(
      'group' => GSAP_COMPONENT_GROUP_PLUGIN,
      'filename' => 'TextPlugin',
    ),
  );

  return $components;
}

/**
 * Implements hook_gsap_variants_info().
 */
function gsap_gsap_variants_info() {
  $variants = array(
    'gsap_lightweight' => array(
      'label' => t('GSAP Lightweight'),
      'components' => array('css', 'easepack'),
    ),
    'gsap_robust' => array(
      'label' => t('GSAP Robust'),
      'components' => array('tweenmax'),
    ),
    'gsap_text' => array(
      'label' => t('GSAP Text'),
      'components' => array('text'),
    ),
    'gsap_draggable' => array(
      'label' => t('GSAP Draggable'),
      'components' => array('css', 'draggable'),
    ),
    'gsap_scrollto' => array(
      'label' => t('GSAP ScrollTo'),
      'components' => array('scrollto'),
    ),
    'gsap_jquery' => array(
      'label' => t('GSAP jQuery'),
      'components' => array('css', 'jquerygsap'),
    ),
  );

  return $variants;
}
