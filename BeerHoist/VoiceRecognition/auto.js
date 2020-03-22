// started from etc/rc.local

// voice control
const record = require('node-record-lpcm16');
const Detector = require('snowboy').Detector;
const Models = require('snowboy').Models;

const models = new Models();

models.add({
  file: 'resources/ahoj.pmdl',
  sensitivity: '0.5',
  hotwords : 'ahoj'
});

const detector = new Detector({
  resource: "resources/common.res",
  models: models,
  audioGain: 1.0,
  applyFrontend: true
});

detector.on('silence', function () {
});

detector.on('sound', function (buffer) {
    process.stdout.write(".");

});

detector.on('error', function () {
  console.log('error');
});

detector.on('hotword', function (index, hotword, buffer) {
  console.log('hotword', index, hotword);

  if (hotword == "ahoj")
      serial.write(Buffer.from("Pub.GoToggle()\n"), function() {});
});

const mic = record.record({
  threshold: 0,
  verbose: true,
  sampleRate: 16000
}).stream()
.pipe(detector);

// bluetooth

var fs = require('fs');
var BTSP = require('bluetooth-serial-port');
var serial = new BTSP.BluetoothSerialPort();

const address = "AB:03:67:78:2f:ef";
const channel = 1;
var reconnect = false;

serial.on('data', function(data) {
   console.log("data:");
   process.stdout.write(data.toString());
});

serial.on('closed', function() { 
  if (reconnect)
    clearTimeout(reconnect);

  console.log("bt: connection closed, reconnecting...");
  reconnect = setTimeout(btReconnect, 10000);
});

function btReconnect()
{
  if (reconnect)
    clearTimeout(reconnect);

  console.log("bt: connecting...");

  serial.connect(address, channel, function() {
    console.log('bt: connected');
  }, function () {
    if (reconnect)
      clearTimeout(reconnect);

    console.log("bt: cannot connect, reconnecting...");
    reconnect = setTimeout(btReconnect, 10000);
  });
}

btReconnect();
 
