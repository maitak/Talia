<?php

/**
 * @file
 * Hooks provided by the GSAP module.
 *
 * Modules may implement any of the available hooks to interact with GSAP.
 */

/**
 * Register GSAP components.
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
 * @return array
 *   An array of GSAP components.
 */
function hook_gsap_components_info() {
  $components = array(
    'mycoolplugin' => array(
      'group' => GSAP_COMPONENT_GROUP_EASING,
      'filename' => 'MyCoolPlugin',
    ),
  );

  return $components;
}

/**
 * Alter GSAP components before they are called.
 *
 * @param array $components
 *   An array of GSAP components registered via hook_gsap_components_info().
 */
function hook_gsap_components_info_alter(array &$components) {
  // Change group for our component to 'plugin'.
  $components['mycoolplugin']['group'] = GSAP_COMPONENT_GROUP_PLUGIN;
  // Replace component path with empty string, so it should be located in the
  // GSAP library folder together with othe plugins in 'plugins' subdirectory.
  $components['mycoolplugin']['path'] = '';
}

/**
 * Register variants for GSAP library.
 *
 * Each variant will be added as separate library via hook_library_info().
 * Prefix 'gsap_' will be added to each variant name to avoid overriding
 * existing libraries if variant doesn't start with 'gsap_'.
 *
 * Please remember that TweenMax already include a set of other GSAP components.
 * So you don't need include them when you include TweenMax. Also TweenLite is a
 * base component, and will be included automatically as dependency.
 * @link https://greensock.com/tweenmax
 *
 * @return array
 *   An array of variants. Each variant with array with 2 elements:
 *     - label: Human-readable name of varint;
 *     - components: Array with GSAP registered components.
 *
 * @see hook_gsap_components_info()
 */
function hook_gsap_variants_info() {
  $variants = array(
    'gsap_lightweight' => array(
      'label' => t('GSAP Lightweight'),
      'components' => array('css', 'easepack'),
    ),
  );

  return $variants;
}
