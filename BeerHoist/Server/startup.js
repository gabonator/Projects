'use strict';

// started from etc/rc.local

var fs = require('fs');
var BTSP = require('bluetooth-serial-port');
var serial = new BTSP.BluetoothSerialPort();

// websocket
var wsconns = [];
var ws = require("nodejs-websocket");
 
ws.createServer(function (conn) {
    wsconns.push(conn);
    conn.address = conn.socket.remoteAddress;
    
    console.log("ws: New connection, clients=" + wsconns.length);
    conn.on("text", function (str) {
      process.stdout.write("< " + str);
      serial.write(Buffer.from(str), function() {});
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
var app = express();

var exec = require('child_process').exec;
function execute(command, callback){
    exec(command, function(error, stdout, stderr){ callback(stdout); });
};

app.get("/", function(req, res) {
  res.sendFile(__dirname + "/index.html");
});

app.get(/^(.+)$/, function(req, res){ 
  res.sendFile(__dirname + req.params[0]); 
});

app.listen(8888, function() {
  console.log("web: Server started at localhost:8888");
});


// bluetooth
//const address = "00:15:FF:F3:56:4C";
//const address = "AB:03:67:78:29:69";
const address = "AB:03:67:78:2f:ef";
//const address = "00-12-F3-13-C6-44"; //atom clock!
//const address = "98:D3:31:fb:5a:6a";
const channel = 1;
var reconnect = false;

serial.on('data', function(data) {
console.log("data:");
   process.stdout.write(data.toString());
   for (var wsc in wsconns)
    wsconns[wsc].sendText(data);
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

//loopx();
    console.log('bt: connected');
  }, function () {
    if (reconnect)
      clearTimeout(reconnect);

    console.log("bt: cannot connect, reconnecting...");
    reconnect = setTimeout(btReconnect, 10000);
  });
}

btReconnect();

function loopx()
{
//setInterval( () => {serial.write(Buffer.from("Status()\n"), function(){}); } , 2000);

}