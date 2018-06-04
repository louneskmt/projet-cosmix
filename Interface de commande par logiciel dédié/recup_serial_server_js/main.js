var SerialPort = require('serialport');
var port = new SerialPort('/dev/ttyACM0');

port.on('open', function() {
    console.log('Serial Port Opened');
    port.on('data', function(data) {
        console.log(data[0]);
    });
});