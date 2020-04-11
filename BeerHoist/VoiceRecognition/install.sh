need to install nodejs v12 (v13 is not compatibile with bluetooth-serial-port) on raspberry pi

- log in as root!

- follow this tutorial: https://thisdavej.com/beginners-guide-to-installing-node-js-on-a-raspberry-pi/
- curl -sL https://deb.nodesource.com/setup_12.x | sudo -E bash -
- sudo apt-get install nodejs=12.16.1.1-nodesource1
- check version by running "node -v" (should be v12.16.1)

- apt install libbluetooth-dev
- npm install bluetooth-serial-port

- apt install libatlas-base-dev
- npm install snowboy@sonus

- apt-get install sox libsox-fmt-all
- npm install node-record-lpcm16

- set default recoding device in user interface
- test usb microphone: "sox --default-device --no-show-progress --rate 16000 --channels 1 --encoding signed-integer --bits 16 type wav -"

- test voice recognition with microphone "node microphone.js"
- test service "node auto.js"