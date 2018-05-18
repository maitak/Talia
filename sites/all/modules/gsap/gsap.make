;
; This is a Drush make file that will automatically download GSAP library.
; Now you can invoke 'drush make' using the following command:
;
; $ drush make path/to/your/gsap/module/gsap.make --no-core
;
; For example if you installed gsap module into sites/all/modules/contrib/
; directory - you should run the next command from your drupal instalation path:
;
; $ drush make sites/all/modules/contrib/gsap/gsap.make --no-core
;
; @see https://github.com/drush-ops/drush
;

api = 2
core = 7.x

; GSAP.
libraries[gsap][type] = "libraries"
libraries[gsap][download][type] = "file"
libraries[gsap][download][url] = "https://github.com/greensock/GreenSock-JS/archive/master.zip"
libraries[gsap][directory_name] = "gsap"
libraries[gsap][destination] = "libraries"
