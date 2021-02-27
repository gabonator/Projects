'use strict';

// started from etc/rc.local

const SerialPort = require('serialport')
//const port = new SerialPort('/dev/tty.wchusbserial1410', { autoOpen: false, baudRate: 115200 })
const port = new SerialPort('/dev/tty.wchusbserial14140', { autoOpen: false, baudRate: 115200 })

port.open(function (err) {
  if (err) {
    return console.log('Error opening port: ', err.message)
  }
})

port.on('open', function() {
  console.log("Port opened");
})

port.on('data', function(data) {
   process.stdout.write("> " + data.toString());
   for (var wsc in wsconns)
    wsconns[wsc].sendText(data);
});

// websocket
var wsconns = [];
var ws = require("nodejs-websocket");
 
ws.createServer(function (conn) {
    wsconns.push(conn);
    conn.address = conn.socket.remoteAddress;
    
    console.log("ws: New connection, clients=" + wsconns.length);
    conn.on("text", function (str) {
      process.stdout.write("< " + str);
      port.write(Buffer.from(str), () => 0);
    });

    conn.on("close", function () {
      wsconns.splice(wsconns.indexOf(conn), 1);
      console.log("Connection closed, clients=" + wsconns.length);
    });

    conn.on("error", function()
    {
      console.log("ws error");
    });
}).listen(2222);


// web
var express = require("express");
const fileUpload = require('express-fileupload');
var app = express();
app.use(fileUpload());
var fs = require("fs");

var exec = require('child_process').exec;

app.get("/", function(req, res) {
  res.sendFile(__dirname + "/index.html");
});

app.get(/^(.+)$/, function(req, res){ 
  res.sendFile(__dirname + req.params[0]); 
});

app.listen(8888, function() {
  console.log("web: Server started at localhost:8888");
});

app.post('/', function(req, res) 
{
  if (!req.files)
  {
    console.log("no files");
    return res.status(400).send('No files were uploaded.');
  }
  let sampleFile = req.files.file;
  console.log(sampleFile.name);
  var buffer = sampleFile.data;
  fs.writeFileSync("_temp/f/" + sampleFile.name, buffer);
  res.end("<html>Ok</html>")
});



/*
  $# - homing positions
  G10 P1 L20 X0 Y0 Z0 - reset homing pos to 0 0 0
  $$ - conf
  $101, $102, $103 = ticks per mm
  $110, $120, $130 = max spd

  ? - query pos
    <Idle|MPos:0.000,0.000,0.000|FS:0,0|WCO:0.000,0.000,0.000>
    <Idle|MPos:0.000,0.000,0.000|FS:0,0>

  ! - hold

16:28:30.402 -> $0=10
16:28:30.402 -> $1=25
16:28:30.402 -> $2=0
16:28:30.402 -> $3=6
16:28:30.402 -> $4=0
16:28:30.437 -> $5=0
16:28:30.437 -> $6=0
16:28:30.437 -> $10=1
16:28:30.437 -> $11=1.000
16:28:30.437 -> $12=0.002
16:28:30.437 -> $13=0
16:28:30.437 -> $20=0
16:28:30.437 -> $21=1
16:28:30.437 -> $22=1
16:28:30.437 -> $23=7
16:28:30.437 -> $24=25.000
16:28:30.437 -> $25=500.000
16:28:30.437 -> $26=250
16:28:30.437 -> $27=2.000
16:28:30.437 -> $30=1000
16:28:30.437 -> $31=0
16:28:30.437 -> $32=0
16:28:30.437 -> $100=40.000     ticks [step/mm]
16:28:30.437 -> $101=40.000
16:28:30.437 -> $102=40.000
16:28:30.437 -> $110=8000.000   speed [mm/min]
16:28:30.437 -> $111=8000.000
16:28:30.437 -> $112=8000.000
16:28:30.437 -> $120=80.000     accel [mm/sec^2]
16:28:30.437 -> $121=80.000    
16:28:30.437 -> $122=80.000
16:28:30.437 -> $130=500.000    max travel [mm]
16:28:30.437 -> $131=500.000
16:28:30.470 -> $132=200.000


*/