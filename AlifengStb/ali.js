var net = require('net');
const zlib = require('zlib');

function Bufferfrom(buf, ofs, len)
{
  var n = Buffer(len);
  for (var i=0; i<len; i++)
    n[i] = buf[i+ofs];
  return n;
}

Ali = 
{
  _decompress: (buffer, handler) => zlib.unzip(buffer, {}, (err, buffer) => err ? handler() : handler(buffer.toString())),
  _alibuffer: (buffer) => "Start" + ("0000000" + buffer.length).substr(-7) + "End" + buffer,
  _alijson: (json) => Ali._alibuffer(JSON.stringify(json)),
  _requestBytes: 0,
  _responseBuffers: [],
  _responseBytes: 0,
  _debug:true,

  connect: (url, port) => new Promise((resolve, reject) =>
  {
    Ali.socket = new net.Socket();
    Ali.socket.connect(port, url, () =>
    {
      Ali.socket.write(Ali._alibuffer("<?xml version='1.0' encoding='UTF-8' standalone='yes' ?><Command request=\"998\" />"));
      Ali.socket.on('data', (data) => Ali.ondata(data));
      Ali.socket.on('close', () => console.log('Connection closed'));

      Ali.ondata = (data) =>
      {
        Ali.ondata = null;
        if (data.length == 108 && data[0] == 0x5b)
          resolve();
        else
          reject("Invalid response packet");
      }
    });
  }),

  disconnect: () => new Promise((resolve, reject) => 
  { 
    Ali.socket.end();
    resolve();
  }),

  request:(id) => Ali.requestRaw(Ali._alijson({request:""+id})),
  requestJson:(json) => Ali.requestRaw(Ali._alijson(json)),
  requestRaw:(reqdata) => new Promise((resolve, reject) =>
  {
    !Ali._debug || console.log(reqdata);
    Ali.socket.write(reqdata);
    Ali.ondata = (data) =>
    {
      if (data.length < 16 || data.toString().substr(0, 4) != "GCDH")
      {
        reject("Invalid response packet");
        return;
      }

      Ali._requestBytes = data[4] + data[5]*256;

      if (Ali._requestBytes == 0 )
      { 
        resolve();
        return;
      }

      Ali._responseBytes = 0;
      Ali._responseBuffers = [];

      Ali.ondata = (data) =>
      {
        Ali._responseBuffers.push(data);
        Ali._responseBytes += data.length;

        if (Ali._responseBytes > Ali._requestBytes)
        {
          reject("Too many bytes " + Ali._responseBytes +" > " + Ali._requestBytes);
          return;
        }

        if (Ali._responseBytes == Ali._requestBytes)
        {
          Ali.ondata = null;
          var raw = Buffer.concat(Ali._responseBuffers);
          if (raw[0] != 0x78 || raw[1] != 0x9c)
          {
            reject("Invalid chunk header, unable to decompress");
            return;
          }
          !Ali._debug || console.log("done");
          Ali._decompress(raw, resolve);
          return;
        }
      }

      if (data.length > 16)
        Ali.ondata(data.slice(16));
    };
  })
};

AliTv = {
  _channels: null,

  getTpByServiceId: (ServiceId) =>
  {
    const RequestTpModels = 24;
    var TPIndex = parseInt(ServiceId.substr(4, 5));

    return Ali.request(RequestTpModels)
    .then( (json) => new Promise((resolve, reject) => {
      json = JSON.parse(json);
      for (var i in json)
      {
        if (json[i].TPIndex == TPIndex)
        {
          resolve(json[i]);
          return;
        }
      }
      reject("Cannot find tp " + ServiceId + " index=" + TPIndex);
    }));
  },

  buildStreamUrl: (channelModel, tpModel) =>
  {
    return "?alisatid=" + tpModel.SatIndex + "&" + 
   "freq=" + tpModel.Freq + "&" + 
   "pol=" + (tpModel.POL ? "v" : "h") + "&" + 
   "msys=" + (channelModel.ModulationSystem == 0 ? "dvbs" : "dvbs2") + "&" + 
   "mtype=" + (channelModel.ModulationType == 0 ? "qpsk" : "8psk") + "&" + 
   "ro=" + (channelModel.RollOff / 100).toFixed(2) + "&" + 
   "plts=" + (channelModel.PilotTones == 0 ? "off" : "on") + "&" + 
   "sr=" + tpModel.SR + "&" + 
   "fec=" + tpModel.FEC + "&" + 
   "camode=" + channelModel.Scramble + "&" + 
  // "camode=0" + "&" + 
   "vpid=" + channelModel.VideoPID + "&" + 
   "apid=" + channelModel.AudioArray[0].PID + "&" + 
   "ttxpid=" + channelModel.TTXPID + "&" + 
   "subtpid=" + "0" + "&" + //(channelModel.getSubPid() == null ? Integer.valueOf(0) : channelModel.getSubPid()) + "&" + 
   "pmt=" + channelModel.PMTPID + "&" + 
   "prognumber=" + channelModel.ServiceID.substr(-4) + "&" + 
   "pids=" + [channelModel.VideoPID, channelModel.AudioArray[0].PID, channelModel.TTXPID, "0", channelModel.PMTPID].join(",") + "&"
   "mask";
  },

  getStreamUrl: (ServiceName) => 
  {
    var _channel, _tp;

    return Promise.resolve(AliTv.getChannelByName(ServiceName))
    .then( (channel) => _channel = channel )
    .then( () => AliTv.getTpByServiceId(_channel.ServiceID) )
    .then( (tp) => _tp = tp )
//    .then( () => Ali.requestJson({"request":"1000","TvState":"0","ProgramId":_channel.ServiceID}) )
    .then( () => AliTv.buildStreamUrl(_channel, _tp));
  },

  requestDeviceInfo: () => Ali.requestJson({request:"15"}).then((json) => JSON.parse(json)),
  requestChannelRange: (fromIndex, toIndex) => Ali.requestJson({request:"0",FromIndex:""+fromIndex,ToIndex:""+toIndex}).then((json) => JSON.parse(json)),
  requestCurrentChannel: () => Ali.requestJson({request:"3"}).then((json) => JSON.parse(json)),
  requestButton: () => Ali.requestJson({"request":"1040","array":[{"KeyValue":""+id}]}).then((json) => JSON.parse(json)),

  getChannels: () =>
  {
    AliTv._channels = [];
    var maxChannels = 0;

    return AliTv.requestDeviceInfo() // unable to create sequence of promises
      .then( (resp) => maxChannels = resp[0].ChannelNum )
      .then( () => AliTv.requestChannelRange(0, 99) )
      .then( (subChannels) => AliTv._channels = AliTv._channels.concat(subChannels) )
      .then( () => AliTv.requestChannelRange(100, 199) )
      .then( (subChannels) => AliTv._channels = AliTv._channels.concat(subChannels) )
      .then( () => AliTv.requestChannelRange(200, 280) )
      .then( (subChannels) => AliTv._channels = AliTv._channels.concat(subChannels) )
      .then( () => AliTv._channels);
  },

  getCurrentChannel: () =>
  {
    return AliTv.requestCurrentChannel()
      .then( (json) => AliTv.getChannelById(json[0].Data).ServiceName );
  },

  getChannelById: (id) =>
  {
    for (var i in AliTv._channels)
      if (AliTv._channels[i].ServiceID == id)
        return AliTv._channels[i];

    throw "Channel not found";
  },

  getChannelByName: (id) =>
  {
    for (var i in AliTv._channels)
      if (AliTv._channels[i].ServiceName == id)
        return AliTv._channels[i];

    throw "Channel not found";
  },

  getFreeChannels: () =>
  {
    var free = [];
    var channels = AliTv._channels;
    for (var i in channels)
      if (channels[i].Scramble == 0 && channels[i].Radio == 0)
        free.push(channels[i].ServiceName);

    return free;
  },

  getHdChannels: () =>
  {
    var free = [];
    var channels = AliTv._channels;
    for (var i in AliTv._channels)
      if (channels[i].HD == 1)
        free.push(channels[i].ServiceName);

    return free;
  }

};

AliStream = {
  _socket: null,
  _buffer: "",
  _session: null,
  _streamId: null,
  _seq: 1,

  connect: (url, port) => new Promise((resolve, reject) =>
  {
    AliStream._socket = new net.Socket();
    AliStream._socket.connect(port, url, resolve);
    AliStream._socket.on('data', (data) => {
      AliStream._buffer += data.toString();
      var arr = AliStream._buffer.split("\r\n\r\n");
      if (arr.length < 2)
        return;

      var response = arr.shift();
      AliStream.debugPrint("> ", response);
      AliStream.onResponse(response);
      AliStream._buffer = arr.join("\r\n\r\n");      
    });

  }),

  disconnect: () => new Promise((resolve, reject) => 
  { 
    AliStream._socket.end();
    resolve();
  }),
  
  onResponse: null,

  debugPrint: (prefix, body) =>
  {
    var arr = body.split("\r\n");
    for (var i in arr)
      console.log(prefix + arr[i]);

    console.log("");
  },

  send: (body) => new Promise((resolve, reject) =>
  {
    body += "CSeq: " + (AliStream._seq++) + "\r\n";
    if (AliStream._session)
      body += "Session: " + AliStream._session + "\r\n";
    body += "User-Agent: Lavf57.52.100";

    AliStream.debugPrint("< ", body);

    body += "\r\n\r\n";

    AliStream._socket.write(body);
    AliStream.onResponse = resolve;
  }),
  
  parseSession: (resp) =>
  {
    AliStream._session = resp.match("Session: (.*)")[1];
    AliStream._streamId = resp.match("com.ses.streamID: (.*)")[1];
    return Promise.resolve();
  },
  
  setup:(url)=>AliStream.send("SETUP " + url + " RTSP/1.0\r\n" + "Transport: RTP/AVP/UDP;unicast;client_port=5114-5115\r\n")
    .then((resp) => AliStream.parseSession(resp)),

  play:(url)=>AliStream.send("PLAY " + url + " RTSP/1.0\r\n"),

  options:(url)=>AliStream.send("OPTIONS " + url + " RTSP/1.0\r\n"),

  getUrl: () => "/stream="+AliStream._streamId,

  keepAlive:(url) =>
  {
    setInterval(() => { console.log("up"); AliStream.options(url)}, 10000);
    return Promise.resolve();
  }
};

AliDiscovery = 
{
  _discovered:null,
  _discoverHandler:null,
  _discoverTimer:null,
  _resolved:false,

  discover:() => new Promise((resolve, reject) =>
  {                
    AliDiscovery._discovered = [];
    AliDiscovery._discoverHandler = resolve;
    AliDiscovery._resolved = false;

    var Client = require('node-ssdp').Client
    client = new Client();
 
    client.on('response', (headers, statusCode, rinfo) =>  
    {
      var location = headers.LOCATION.match("^http://(.*):")[1];
      AliDiscovery._discovered.push(location);
      AliDiscovery._resolved = true;
      if (AliDiscovery._discoverHandler)
      {
        AliDiscovery._discoverHandler(location);
        AliDiscovery._discoverHandler = null;
      }
    });

    client.search("urn:ses-com:device:SatIPServer:1");
    //client.search('ssdp:all');
    
    AliDiscovery._discoverTimer = setTimeout(()=>{
      AliDiscovery._discoverTimer = null;
      client.stop();
      if (!AliDiscovery._resolved)
        resolve();
    }, 10000);
  }),

  disconnect:() => {
    if (AliDiscovery._discoverTimer)
      clearTimeout(AliDiscovery._discoverTimer);
    return Promise.resolve();
  },
  getNext:() => new Promise(resolve => {AliDiscovery._discoverHandler = resolve}),
  getAll:() => AliDiscovery._discovered,

  sleep:(ms) => new Promise(resolve => setTimeout(resolve, ms))
};

/*
AliDiscovery.discover()
.then( (device) => console.log(device) )
.then( () => AliDiscovery.getNext() )
.then( (device) => console.log(device) )
.then( () => AliDiscovery.getAll() )
.then( (all) => console.log(all) )
.then( () => AliDiscovery.disconnect() )
*/

var root = "192.168.1.50"; // .6 .50

Ali.connect(root, 20000)
//.then( () => AliTv.requestDeviceInfo() ).then( console.log )
.then( () => AliTv.getChannels() )

//.then( () => AliTv.getFreeChannels() ).then( (list) => console.log("Free: "+list.join(",")) )

.then( () => AliTv.getCurrentChannel() )
//.then( (current) => console.log(current) )
.then( (current) => { console.log(current); return AliTv.getStreamUrl(current); } )

//.then( (current) => AliTv.getStreamUrl("DAJTO HD") )
.then( (current) => AliTv.getStreamUrl("TA3 HD") )
//.then( (current) => AliTv.getStreamUrl("Markiza HD") )

.then( (url) => 
{
  AliStream.connect(root, 554)
  .then(() => AliStream.setup("rtsp://" + root + ":554" + "/" + url))
  .then(() => AliStream.play("rtsp://" + root + ":554" + AliStream.getUrl()))
  .then(() => AliStream.keepAlive("rtsp://" + root + ":554" + AliStream.getUrl()));
//  .then(() => AliStream.disconnect() );
  
  // watch "rtp://@:5114" in vlc
  
} )

.catch( (e) => console.log("Error: "+e) )

.then( () => Ali.disconnect() );