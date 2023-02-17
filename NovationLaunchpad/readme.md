# Novation Mini MK3 firmware extras

Video:
[![Novation Launchpad hacking: Image editor](https://img.youtube.com/vi/joenh_Ad5q0/0.jpg)](https://www.youtube.com/watch?v=joenh_Ad5q0 "Novation Launchpad hacking: Image editor")

This project extend the functionality of these launchpads by injecting extra code into the stock firmware. Enter it by taping on User button and then use top left buttons for navigation between applications. Tap again on User button to go back to the menu.

- build_syx.sh - builds the sysex firmware image for flashing with Launchpad Utility (https://fw.mat1jaczyyy.com/firmware). Use following arrow sequence to enable loading of custom firmwares: Up, Up, Down, Down, Left, Right, Left, Right
- build_wasm.sh - build and test the application in simple HTML emulator

Try it online: [WASM build](https://rawgit.valky.eu/gabonator/Projects/master/NovationLaunchpad/build/wasm.html)

