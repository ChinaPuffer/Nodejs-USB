var usb = require('device');

var dev = new usb.Device();

console.log(dev.initDevice( 0x05ac, 0x0237 ));


