This module integrate the GSAP javascript library with Drupal through the
Libraries API.
GSAP is a powerful, high-performance javascript animation library for the web.
This module is intended to be an API module for developers.
The main aim is to integrate GSAP with the Libraries API to manage it
efficiently as a project dependency

Dependencies:
Drupal 7.x core
Libraries Api (https://www.drupal.org/project/libraries)
GSAP library (https://github.com/greensock/GreenSock-JS/)

Note: this module is developing with GSAP library v.1.18.2.

Installation:
  - Install GSAP module as usual Drupal module.
  - Download GSAP library from Official site (http://greensock.com/gsap") or
    GitHub (https://github.com/greensock/GreenSock-JS/) and unpack archive to
    your libraries directory (/sites/all/libraries by default).
    Rename folder with library to 'gsap', so in the default case you should
    have next path to js files:
   /sites/all/libraries/gsap/src/minified/TweenLite.min.js
  - Or you can install GSAP library via drush with command 'drush gsap-install'.

Useful documentation and articles about GSAP library:
  - GSAP Homepage - https://greensock.com/
  - GSAP Documentation - http://greensock.com/docs/#/HTML5/
  - GSAP Getting Started - http://greensock.com/get-started-js
