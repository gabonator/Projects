'use strict';

// started from etc/rc.local

var fs = require('fs');
var BTSP = require('bluetooth-serial-port');
var serial = new BTSP.BluetoothSerialPort();
var dns = require("dns");

// websocket
var wsconns = [];
var ws = require("nodejs-websocket");
 
ws.createServer(function (conn) {
    wsconns.push(conn);
    conn.address = conn.socket.remoteAddress;
    
    hostname(conn.address, function(result) {console.log(conn.address + " -> " + result); conn.address = result});

    console.log("ws: New connection, clients=" + wsconns.length);
    conn.on("text", function (str) {
      logBufferAccess.push("_("+JSON.stringify({timestamp:timestamp(), ts:new Date().getTime(), websocket:{address:conn.address, data:str}})+");");
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

app.get("/dmesg", function(req, res) {
  execute("dmesg", (out) => res.end(out));
});

app.get("/ps", function(req, res) {
  execute("ps aux", (out) => res.end(out));
});

app.get("/debug", function(req, res) {
  var vars = [
    "datestamp()",
    "timestamp()",
    "logBufferCollect",
    "logLastData",
    "wsconns",
    "logBuffer",
    "logBufferAccess",
    "__dirname"
  ];
  var q = "<html>";
  for (var i in vars)
  {
    q += "<b>" + vars[i] + "</b> = " + eval(vars[i]) + "<br>";
  }
  q += "</html>";
  res.end(q);
});

app.get("/log", function(req, res) {
  res.sendFile(__dirname + "/startup.log");
});

app.get("/delayed", function(req, res) {
  setTimeout( () => res.end("This is delayed message!"), 10000);
});

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
const address = "00:15:FF:F3:56:4C";
const channel = 1;
var reconnect = false;

serial.on('data', function(data) {
   logData(data);
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
    console.log('bt: connected');
  }, function () {
    if (reconnect)
      clearTimeout(reconnect);

    console.log("bt: cannot connect, reconnecting...");
    reconnect = setTimeout(btReconnect, 10000);
  });
}

btReconnect();
  
// data logger
var logBuffer = "";
var logBufferCollect = [];
var logLastData = null;
var logBufferAccess = [];
var logLastLine = null;

function logData(msg)
{
  logBuffer += msg;
  var logLines = logBuffer.split("\n");
  while (logLines.length > 1) 
  {
     var logLine = logLines.shift();
     logLine = logLine.replace("},devs", "],devs");
     logLine = logLine.replace("ion=", "ion:");
     logLine = logLine.replace("median=", "median:");

     logBufferCollect.push(timestamp() + " " + logLine);
     if (logLine.substr(0, 1) == "{" && logLine.substr(-1, 1) == "}" && logLine.indexOf("devs:") != -1)
     {
       logLastLine = logLine;
       logLastData = "_({timestamp:'"+timestamp()+"', ts:"+(new Date().getTime())+", data:"+logLine+"});";
     }
     //if (logLine.substr(0, 1) == "{" && logLine.substr(-1, 1) == "}" && logLine.indexOf("error") != -1)
     //{
     //   logBufferAccess.push("_({timestamp:'"+timestamp()+"', ts:"+(new Date().getTime())+", data:"+logLine+"});");
     //}
  }

  logBuffer = logLines[0];

  if (logBuffer.length > 512)
  {
    var logLine = logBuffer;
    logBufferCollect.push(timestamp() + " " + logLine);
    logBuffer = "";
  }
//  logLines = logLines.length > 0 ? logLines[0] : "";
}

function datestamp()
{
  var d = new Date();
  return d.getFullYear() + "-" +
         ("0" + (1+d.getMonth())).substr(-2) + "-" +
         ("0" + d.getDate()).substr(-2);
}

function timestamp()
{
  var d = new Date();
  return datestamp() + " " +
         ("0" + d.getHours()).substr(-2) + ":" +
         ("0" + d.getMinutes()).substr(-2) + ":" +
         ("0" + d.getSeconds()).substr(-2);
}

//var reportLine = 0;
setInterval(function()
{
  if (logBufferCollect.length)
  {
    fs.appendFile(__dirname + "/logs/"+datestamp()+".txt", logBufferCollect.join("\r\n"), function (e) {if (e) console.log(e);});
    logBufferCollect = [];
  }
  
  if (logLastData)
  {
    logBufferAccess.push(logLastData);
    fs.appendFile(__dirname + "/logs/"+datestamp()+".js", logBufferAccess.join("\r\n") + "\r\n", function (e) {if (e) console.log(e);});
    logLastData = null;
    logBufferAccess = [];
  }
}, 30000);

// tools
function hostname(ip, handler)
{
  ip = ip.replace("::ffff:", "");

  dns.reverse(ip, function(err, domains) {
    if(err)
    {
      handler(ip);
      return;
    }
    var domain = domains[0];
    //domain = domain.replace(".xxx.xxx", "");
    handler(domain);
  });
}

// rio report
var request = require("request");

function safeEval(expr)
{
  var jsonData = null;
  try {
    eval("jsonData = " + expr);
  } catch (e) {
    console.log("Eval error " + e.message); // true
  }
  return jsonData;
}

function getLocalAddress()
{
  var ifaces = require('os').networkInterfaces();

  var localaddr = [];

  Object.keys(ifaces).forEach(function (ifname) {
    ifaces[ifname].forEach(function (iface) {
      if ('IPv4' !== iface.family || iface.internal !== false) {
        // skip over internal (i.e. 127.0.0.1) and non-ipv4 addresses
        return;
      }
      localaddr.push(iface.address);
    });
  });
  localaddr.push("");
  return localaddr[0];
}

var started = (new Date()).getTime();
var localhostname = require("os").hostname();
var localaddr = getLocalAddress();

function rioreport()
{
  var modes = ["safe", "automatic-prepare", "automatic-ignition", "automatic-burning", "automatic-standby", "manual", "locked"];

  var seconds = Math.floor(((new Date()).getTime() - started)/1000);

  var data = "uptime=" + seconds;

  if (logLastLine)
  {
    var jsonData = safeEval(logLastLine);
    if (jsonData)
    {
      var state = modes.indexOf(jsonData.state);
      if (state==-1)
        state = -8; // unknown state

      data += "&state="+state;
      data += "&analog_ion="+jsonData.ion[0];
      data += "&temp_vstup="+jsonData.temp.vstup;
      data += "&temp_vystup="+jsonData.temp.vystup;
      data += "&temp_termostat="+jsonData.temp.termostat;
      data += "&temp_vzduch="+jsonData.temp.vzduch;
    } else
      data += "&state=-9"; // malformed response
  } else
    data += "&state=-1"; // no response

  logLastLine = null;

  request({
      headers: {
        "Content-Length": data.length,
        "Content-Type": "application/x-www-form-urlencoded",
        "Server": "rio-gabo-guru 2017b node",
        "User-Agent": "nodejs on "+localhostname+" (#fa71cc262a90,custom) localip="+localaddr,
      },
      uri: "http://api.gabo.guru/rio/",
      body: data,
      method: "POST"
    }, function (err, res, body) {
      if (err)
        console.log(err);
      console.log(data + " -> " + body);
    });
}

setInterval(rioreport, 60*1000);

fs.appendFile(__dirname + "/logs/test.txt", (new Date()) + "\r\n", function (e) {if (e) console.log(e);});
