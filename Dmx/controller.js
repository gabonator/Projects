var usb = require('usb');
// DMX512 PC Computer USB Satge Lighting Controller Dimmer to DMX Interface Adapter
// Bus 020 Device 010: ID 16c0:05dc 16c0 uDMX  Serial: ilLUTZminator001

var dev = usb.findByIds(0x16c0, 0x05dc);
dev.__open();
dev.__claimInterface(0);
dev.open();

var dmxAddress = 1;

function color()
{
  var t = (new Date()).getTime();
  var r = Math.floor(127+Math.sin(t*0.001)*127);
  var g = Math.floor(127+Math.sin(t*0.001*0.32)*127);
  var b = Math.floor(127+Math.sin(t*0.001*0.79)*127);
  return [r, g, b];
}

function packetParLightByColor(c)
{        
  // Soft 72W 36LED RGB Stage Light Flat Par Lamp Club DJ Party Disco DMX512 Remote       
  // LED Par Light with remote controller

  var CH1_brightness = 255;
  var CH2_red = c[0];
  var CH3_green = c[1];
  var CH4_blue = c[2];
  var CH5_strobe = 0; 
  // 0..7 no strobe, 8..255 strobe speed
  var CH6_mode = 0; 
  // 0..10 - manual, 
  // 11..60 - color selections, 
  // 61..110 - colors shade, 
  // 111..160 - colors pulse, 
  // 161..210 - colors transiti
  // 211..255 - sound control
  var CH7_value = 0;
  return Buffer.from([CH1_brightness, CH2_red, CH3_green, CH4_blue, CH5_strobe, CH6_mode, CH7_value]);
}

function packetButterflyByColor(c)
{        
  // 30W DMX512 RGBW Voice-activated Auto DJ Projector Led Stage Strobe Light Remote
  // 1W 9-Colors LED DMX BUTTERFLY MAGIC LED LIGHT

  var CH1_mode = 192;
  // 0..63 off,
  // 64..127 auto mode
  // 192..255 dmx mode
  var CH2_red = c[0]; // green
  var CH3_green = c[1]; // orange, yellow white
  var CH4_blue = c[2]; // blue, red, yellow
  var CH5_ledcontrol = 0;
  // 0..31, 32..63 auto, 63..127 auto, 128..191 auto, 192..223 sound, 224..239 sound, 240..255 sound 
  var CH6_strobe = 0; 
  // 0..63 no strobe, 64..191 auto strobe, 192..255 sound strobe
  var CH7_fade = 0;
  // 0..15 no fade, 16..223 auto fade, 224..255 sound fade
  var CH8_spin = 96;
  // 0..95 no spin, 96..255 spin
  var CH9_speed = 128;
  // 0 slow, 255 fast
  return Buffer.from([CH1_mode, CH2_red, CH3_green, CH4_blue, CH5_ledcontrol, CH6_strobe, CH7_fade, CH8_spin, CH9_speed]);
}

function packetFogmachine()
{        
  return Buffer.from([128]);
}

setInterval(() =>
{
  var cSetMultiChannel = 2;
  var cRequestType = usb.LIBUSB_REQUEST_TYPE_VENDOR | usb.LIBUSB_RECIPIENT_DEVICE | usb.LIBUSB_ENDPOINT_OUT;

//  var buffer = packetParLightByColor(color());
  var buffer = packetButterflyByColor(color());
//  var buffer = packetFogmachine();
  dev.controlTransfer(cRequestType, cSetMultiChannel, buffer.length, dmxAddress-1, buffer, (error, data)=>{})
}, 2000);