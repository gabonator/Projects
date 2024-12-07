"use strict";
process.title = "tunneler";

// webserver
const express = require('express');
const ws = require('ws');
const app = express();
const wsServer = new ws.Server({ noServer: true });
const server = app.listen(8042, () => console.log(`Tuneller at 8042`));

app.use(express.static("."));
app.get("/", (req, res) => {
  var sid = ("00000000"+Math.floor(Math.random()*100000)+""+Math.floor(Math.random()*100000)).substr(-8)
  res.redirect(307, "tunneler.html?" + sid);
});

server.on('upgrade', (request, socket, head) => {
  wsServer.handleUpgrade(request, socket, head, socket => {
    wsServer.emit('connection', socket, request);
  });
});

// websocket

function PathSub(path, l, r)
{
  var aux = [];
  for (var i=0; i<path.length; i++)
    if (path[i][0] > l && path[i][0] <= r)
      aux.push([path[i][0], path[i][1]])
  return aux;
}

class Session
{
  constructor(id)
  {
    this.id = id;
    this.masterStarted = false;
    this.sockets = [];
    this.seed = 0;
    this.started = [0, 0, 0, 0, 0, 0];
    this.fps = 0;
    this.mergedPath = {path:[], cachedValue:0, cachedIndex:0};
  }
}

class NetBackend
{
  timestampToBytes(ts)
  {
    const buffer = new ArrayBuffer(8);
    const view = new DataView(buffer);
    view.setFloat64(0, ts, true);
    return new Uint8Array(buffer);
  }
  dwordToBytes(dw)
  {
    return new Uint8Array([(dw >> 24) & 0xff, (dw >> 16) & 0xff, (dw >> 8) & 0xff, dw & 0xff]);
  }
  bytesToDword(b)
  {
    return (b[0] << 24) | (b[1] << 16) | (b[2] << 8) | b[3];
  }
  bytesToTimestamp(b)
  {
    const view = new DataView(new Uint8Array(b).buffer);
    return view.getFloat64(0, true);
  }
  buildInitPacket(p)
  {
    return [0x31, ...this.dwordToBytes(p.seed), ...this.timestampToBytes(p.started)];
  }
  parseInitPacket(buf)
  {
    // 0x41, new seed, new timestamp
    if (buf[0] != 0x30 || buf.length != 13)
      throw "wrong token"
    return {seed:this.bytesToDword(buf.slice(1, 1+4)), started:this.bytesToTimestamp(buf.slice(5, 5+8)), path:[]};
  }
  pathToBytes(path)
  {
    var buf = [];
    for (var i=0; i<path.length; i++)
    {
      buf.push(path[i][0]>>8);
      buf.push(path[i][0]&255);
      buf.push(path[i][1]>>8);
      buf.push(path[i][1]&255);
    }
    return buf;
  }
  bytesToPath(buf)
  {
    var path = [];
    for (var i=0; i<buf.length; i+=4)
      path.push([(buf[i]<<8)|(buf[i+1]), (buf[i+2]<<8)|(buf[i+3])]);
    return path;
  }
  parseSyncPacket(buf)
  {
    if (buf[0] != 0x32 || buf.length % 4 != 1)
      throw "wrong token"
    var frame = this.bytesToDword(buf.slice(1, 5));
    return {frame: frame, path:this.bytesToPath(buf.slice(5, buf.length))};
  }
  buildSyncPacket(path, frame, clients, startFrame)
  {
    var lastFrame = path.length ? path[path.length-1][0] : 0;
    var subPath = PathSub(path, startFrame, lastFrame);
    return [0x33, ...this.dwordToBytes(frame | (clients << 24)), ...this.pathToBytes(subPath)];
  }
}

var sessions = {};
var net = new NetBackend();

wsServer.on('connection', function(socket, request) {
  var sid = request.url.split("/").join("").substr(0, 20);
  if (!(sid in sessions))
  {
    sessions[sid] = new Session(sid);
    console.log("Creating session",sid);
  }
  var session = sessions[sid];

  session.sockets.push(socket);
  socket.sentFrame = 0;

  socket.on('message', function(msg) {
    if (msg[0] == 0x30)
    {
      if (!session.masterStarted)
      {
        var master = net.parseInitPacket(msg);
        session.started = master.started;
        session.seed = master.seed;
        session.masterStarted = true;
        socket.master = true;
        socket.path = [];
        socket.lastRecvFrame = 0;
        console.log("Master connected", new Date(session.started), session.seed.toString(16));
      } else {
        console.log("Slave connected");
        socket.path = [];
        socket.lastRecvFrame = 0;
      }
      socket.send(net.buildInitPacket({seed:session.seed, started:session.started}))
      return;
    }
    if (msg[0] == 0x32)
    {
      var resp = net.parseSyncPacket(msg);
      socket.lastRecvFrame = resp.frame;

      if (resp.path.length)
      {
        // insert last value, we check for differences
        mergePath(session, [socket.path.length ? socket.path[socket.path.length-1] : [0, 0], ...resp.path]);

        if (resp.path[0][0] < socket.sentFrame)
          throw "continuity"
        socket.path = [...socket.path, ...resp.path]
      }

      //console.log(socket.master ? "post master" : "post slave", master.path);
      let {frame:maxRecvFrame, path:masterPath} = getMergedPath(session, socket.sentFrame)
      //var maxFrame = resp.frame;
      //var masterPath = getMergedPath()//sockets.find(s=>s.master).path
      socket.send(net.buildSyncPacket(masterPath, maxRecvFrame, session.sockets.length, socket.sentFrame))
      socket.sentFrame = maxRecvFrame//masterPath.length ? masterPath[masterPath.length-1][0] : -1;
      return;
    }
    console.log(msg)
  });

  // When a socket closes, or disconnects, remove it from the array.
  socket.on('close', function() {
    if (socket.master)
    {
      console.log("Master disconnected!");
      session.mergedPath = {path:[], cachedValue:0, cachedIndex:0};
      session.masterStarted = 0;
    }
    else
      console.log("Slave disconnected!");
    session.sockets = session.sockets.filter(s => s !== socket);
    if (session.sockets.length == 0)
    {
      delete sessions[session.id];
      console.log("Closing session", session.id, "remaining", Object.keys(sessions).length);
    }
  });
});

function mergePath(session, path)
{
  // 0th index is last value
  for (var i=1; i<path.length; i++)
  {
    var changedKeys = path[i][1] ^ path[i-1][1];
    var addedKeys = changedKeys & path[i][1];
    var removedKeys = changedKeys & path[i-1][1];
    insertMergedPoint(session, {time:path[i][0], added:addedKeys, removed:removedKeys});
  }
}

function insertMergedPoint(session, pt)
{
  if (session.mergedPath.path.length == 0 || pt.time < session.mergedPath.path[0].time)
  {
    session.mergedPath.path.unshift(pt);
    return;
  }
  if (pt.time > session.mergedPath.path[session.mergedPath.path.length-1].time)
  {
    session.mergedPath.path.push(pt);
    return;
  }
  for (var i=0; i<session.mergedPath.path.length; i++)
  {
    if (session.mergedPath.path[i].time == pt.time)
    {
      session.mergedPath.path[i].added |= pt.added;
      session.mergedPath.path[i].removed |= pt.removed;
      return;
    }
  }
  for (var i=0; i<session.mergedPath.path.length-1; i++)
  {
    if (pt.time > session.mergedPath.path[i].time && pt.time < session.mergedPath.path[i+1].time)
    {
      session.mergedPath.path.splice(i+1, 0, pt);
      break;
    }
  }
  throw "problem!";
}

function getMergedPath(session, starting)
{
  var master = session.sockets.find(s=>s.master)
  if (!master)
    return {frame:0, path:[]}

  var maxFrameByClients = session.sockets.map(s=>s.lastRecvFrame).reduce((a,b)=>Math.min(a,b), session.sockets[0].lastRecvFrame)-1; 
  // TODO: optimize
  var mk = session.mergedPath.cachedValue;
  var path = [];
  for (var i=session.mergedPath.cachedIndex; i<session.mergedPath.path.length; i++)
  {
//    if (i<session.mergedPath.path.length-1 && session.mergedPath.path[i+1].time < maxFrameByClients)
//    {
//      session.mergedPath.cachedIndex = i;
//      session.mergedPath.cachedValue = mk;
//    }
    mk = (mk | session.mergedPath.path[i].added) & (~session.mergedPath.path[i].removed);
//    if (session.mergedPath.path[i].time > starting)
      path.push([session.mergedPath.path[i].time, mk])
  }
  var maxFrame = maxFrameByClients;
  return {frame:maxFrame, path:path}
} 
