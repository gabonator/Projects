static const char _index_html[] PROGMEM = R"---(
<html>
<head>
<link rel="icon" type="image/png" href="/favicon.png"/>
<script src="highcharts.js"></script>
</head>
<body>
<input type="button" value="<<<" onMouseDown="ui.onLeft(3)" onMouseUp="ui.onStop()">
<input type="button" value="<<" onMouseDown="ui.onLeft(2)" onMouseUp="ui.onStop()">
<input type="button" value="<" onMouseDown="ui.onLeft(1)" onMouseUp="ui.onStop()">
<input type="button" value="[panic]" onMouseDown="ui.onPanic()">
<input type="button" value=">" onMouseDown="ui.onRight(1)" onMouseUp="ui.onStop()">
<input type="button" value=">>" onMouseDown="ui.onRight(2)" onMouseUp="ui.onStop()">
<input type="button" value=">>>" onMouseDown="ui.onRight(3)" onMouseUp="ui.onStop()">
<input type="button" value="fun" onMouseDown="ui.onFun()">
<br>
<input type="button" value="manual" onMouseDown="ui.onManual()">
<input type="button" value="go(0)" onMouseDown="ui.goZero()">
<input type="button" value="set(0)" onMouseDown="ui.setZero()">
<input type="button" value="en/dis glitch" onMouseDown="ui.toggleGlitch()">
<input type="button" value="log start" onMouseDown="ui.logStart()">
<input type="button" value="log stop" onMouseDown="ui.logStop()">
<br>
<input type="button" value="clear" onMouseDown="ui.clear()">
<input type="button" value="force reset" onMouseDown="ui.forceReset()">
<input type="button" value="set min" onMouseDown="ui.setMin()">
<input type="button" value="set max" onMouseDown="ui.setMax()">
&nbsp;Period[s]:<input type="text" size="8" value="4.0" onChange="ui.setPeriod(this.value)">
<input type="checkbox" value="" onChange="ui.setFlavour(this.checked ? 1 : 0)">Trojuholnik
&nbsp;<input type="button" value="calculate" onMouseDown="ui.calcFunction()">
<br><br>
<input type="button" value="go home" onMouseDown="ui.goMin()">
<input type="button" value="chart start" onMouseDown="ui.chartStart()">
<input type="button" value="chart stop" onMouseDown="ui.chartStop()">
<input type="button" value="START/STOP" onMouseDown="ui.onFun()">

<div id="info"></div>
<div id="extra"></div>
<div style="width:400px; height:400px">
<canvas id="canBlend" width="400" height="400" style="position:absolute; border:#000 solid 1px;"></canvas>
<canvas id="canHold" width="400" height="400" style="position:absolute; border:#000 solid 1px;"></canvas>
<canvas id="canCurrent" width="400" height="400" style="position:absolute; border:#000 solid 1px;"></canvas>
<canvas id="canGrid" width="400" height="400" style="position:absolute; border:#000 solid 1px;"></canvas>
</div>
<br>
<div id="chart" style="width:100%; height:400px;"></div>
<div id="log"></div>
</body>
<script>

Canvas = function(id)
{
  this.can = document.getElementById(id);
  this.ctx = this.can.getContext("2d");
  this.clear();
}

Canvas.prototype.dot = function(x, y, clr, size)
{
  size = size || 4;
  this.ctx.fillStyle = clr; //"rgba(128, 0, 0, 0.8)";
  this.ctx.fillRect(x-size/2, y-size/2, size, size);
}

Canvas.prototype.bar = function(left, top, right, bottom, clr)
{
  this.ctx.fillStyle = clr;
  this.ctx.fillRect(left, top, right-left, bottom-top);
}

Canvas.prototype.line = function(x0, y0, x1, y1, clr)
{
  this.ctx.strokeStyle = clr;

  this.ctx.beginPath();
  this.ctx.moveTo(x0, y0);
  this.ctx.lineTo(x1, y1);
  this.ctx.stroke();
}

Canvas.prototype.clear = function()
{
  this.ctx.clearRect(0, 0, this.can.width, this.can.height);
}

Canvas.prototype.blend = function()
{
  this.ctx.fillStyle = "rgba(255, 255, 255, 0.08)";
  this.ctx.fillRect(0, 0, this.can.width, this.can.height);
}

Graph = function()
{
  this.hold = new Canvas("canHold");
//  this.hold.ctx.globalAlpha = 0.3;
  this.hold.can.style.opacity = 0.1;

  this.canvas = new Canvas("canBlend");
  this.canvas.ctx.lineWidth = 5;

  this.range = {xmin:-24000, xmax:24000, ymin:-5000, ymax:5000}; //spd 4000
 
  this.grid = new Canvas("canGrid");
  this.width = this.canvas.can.width;
  this.height = this.canvas.can.height;

  this.grid.ctx.globalAlpha = 0.5;

  this.current = new Canvas("canCurrent");
  this.init();
}

Graph.prototype.init = function()
{
  this.lastPos = false;
  this.redrawAxes();
}

Graph.prototype.redrawAxes = function()
{
  this.grid.clear(); 
  var pmin = this.project(funct.min, 0).x;
  var pmax = this.project(funct.max, 0).x;

  this.grid.bar(pmin, 4, pmax, 8, "#8080b0");
  this.line(this.range.xmin, 0, this.range.xmax, 0, "#000000", this.grid);
  this.line(0, this.range.ymin, 0, this.range.ymax, "#000000", this.grid);  
}

Graph.prototype.clear = function()
{
  this.canvas.clear();  
  this.hold.clear();  
  this.grid.clear();  
  this.init();
}

Graph.prototype.dot = function(x, y, clr)
{
  var pos = this.project(x, y);
  this.hold.dot(pos.x, pos.y, clr);
  //this.canvas.dot(pos.x, pos.y, clr);
  if (this.lastPos)
  {
    this.canvas.line(this.lastPos.x, this.lastPos.y, pos.x, pos.y, clr);
  }
  this.lastPos = pos;
  this.canvas.blend();
  this.current.clear();
  this.current.dot(pos.x, pos.y, "#000000", 8);
}

Graph.prototype.debugDot = function(x, y, clr)
{
  var pos = this.project(x, y);
  this.current.dot(pos.x, pos.y, clr);
}

Graph.prototype.project = function(x, y)
{
  return {
    x:(x-this.range.xmin)*this.width/(this.range.xmax-this.range.xmin),
    y:(y-this.range.ymin)*this.height/(this.range.ymax-this.range.ymin)};
}

Graph.prototype.line = function(x0, y0, x1, y1, clr, target)
{
  var p0 = this.project(x0, y0);
  var p1 = this.project(x1, y1);

  target = target || this.canvas;
  target.line(p0.x, p0.y, p1.x, p1.y, clr);
}

Comm = function()
{
  this.buffer = "";

  var base = location.hash ? location.hash.substr(1) : window.location.hostname;
  var wsUri = "ws://" + base + ":88/";
  //wsUri = "ws://localhost:2222";
  
  this.socket = new WebSocket(wsUri);
  this.socket.onopen = () => console.log("Connected!");
  this.socket.onclose = () => console.log("Connection lost!");
  this.socket.onerror = () => console.log("Connection lost!");
  this.socket.onmessage = (function(msg)
  {
    this.buffer += new String(msg.data);
    var lines = this.buffer.split("\r").join("\n").split("\n");
    while ( lines.length > 1 )
      comm.onData(lines.shift());
    this.buffer = lines.join("\n");
  }).bind(this);
}

Comm.prototype.send = function(msg)
{
  console.log("<"+msg);
  this.socket.send(msg+"\n");
}

Comm.prototype.onData = function(msg)
{
  if (msg.charAt(0) == "_" && msg.charAt(1) == "(")
    ; 
  else
    console.log(">"+msg);

  if (msg.charAt(0) == '_')
    eval("receiver."+msg);
}

Ui = function(comm)
{                 
  this.comm = comm;
  this.repeat = "";
  this.speed = 0;
  this.manual = false;
  this.mouse = {x:0, y:0};

  var _this = this;
  this._timer = setInterval((function()
  {
    this.mtimer();
  }).bind(this), 400);
/*
  document.onmousemove = (function(e) 
  { 
    this.mouse = {x:e.clientX, y:e.clientY};
  }).bind(this);
  */
}

Ui.prototype.mtimer = function()
{
  if (this.repeat != "")
    this.comm.send(this.repeat);    
}

Ui.prototype.setSpeed = function(speed)
{
  if (this.speed == speed)
    return;

  this.speed = speed;
  this.comm.send("speed="+this.speed); // 4000 max?
}

Ui.prototype.onLeft = function(speed)
{
  var speeds = [0, 4000*0.05, 4000*0.2, 4000*0.5];
  this.setSpeed(Math.floor(speeds[speed])); //Math.floor(4000/3*speed)); // 4000 max?
  this.repeat = "left";
  this.comm.send("left");
}

Ui.prototype.onRight = function(speed)
{
  var speeds = [0, 4000*0.05, 4000*0.2, 4000*0.5];
  this.setSpeed(Math.floor(speeds[speed])); //Math.floor(4000/3*speed)); // 4000 max?
  this.repeat = "right";
  this.comm.send("right");
}

Ui.prototype.onStop = function()
{
  this.repeat = "";
  this.comm.send("stop");
}

Ui.prototype.onPanic = function()
{
  this.repeat = "";
  this.comm.send("panic");
}

Ui.prototype.onFun = function()
{
  this.repeat = "";
  this.setSpeed(4000);
  this.comm.send("fun");
}

Ui.prototype.onManual = function()
{
  this.manual = !this.manual;
}

Ui.prototype.goZero = function()
{
  this.setSpeed(1000);  
  this.repeat = "";
  this.comm.send("go=0");
}

Ui.prototype.setZero = function()
{
  this.repeat = "";
  this.comm.send("set=0");
}

Ui.prototype.toggleGlitch = function()
{
  this.repeat = "";
  this.comm.send("glitch");
}

Ui.prototype.clear = function()
{
  graph.clear();
}

Ui.prototype.forceReset = function()
{
  this.comm.send("freset");
}

Ui.prototype.goMin = function()
{
  this.setSpeed(1000);
  this.comm.send("go="+funct.min);
}

Ui.prototype.setMin = function()
{
  console.log("set min="+lastValue.pos);
  funct.min = lastValue.pos;
}

Ui.prototype.setMax = function()
{
  console.log("set max="+lastValue.pos);
  funct.max = lastValue.pos;
}

Ui.prototype.setPeriod = function(period)
{
  console.log("set period="+period);
  funct.period = period;
}

Ui.prototype.setFlavour = function(flavour)
{
  console.log("set flavour="+flavour);
  funct.flavour = flavour;
}

Ui.prototype.calcFunction = function(period)
{
  var offset = Math.floor((funct.min + funct.max)/2);
  var amplitude = Math.floor((funct.max - funct.min)/2);
  var period = funct.period;
  var flavour = funct.flavour;
  var phase = flavour == 0 ? 270 : 0;

  // sin(270deg) = -1 ... left extrema
  var harmonic = [
    "funt="+period, 
    "funa="+amplitude, 
    "funo="+offset, 
    "funp="+phase,
    "funf="+flavour];
    
  console.log(harmonic);
  while (harmonic.length>0)
    this.comm.send(harmonic.shift());
  graph.redrawAxes();
}

Ui.prototype.logStart = function()
{
  logger.enabled = true;
}

Ui.prototype.logStop = function()
{
  logger.enabled = false;
  
  document.getElementById("log").innerHTML = 
    "<textarea cols=30 rows=40>\n"+
    logger.data.map(v => v.join(", ")).join("\n")
    "</textarea>";
  logger.data = [];  
}

Ui.prototype.chartStart = function()
{
  charter.onInit();
  charter.enabled = true;
}

Ui.prototype.chartStop = function()
{
  charter.enabled = false;
}

Receiver = function()
{
}

Receiver.prototype.calcPosition = (raw) => (raw/8000).toFixed(2) + "cm";
Receiver.prototype.calcForce = (raw) => (raw/2/8300*100*10).toFixed(1) + "mN";
// speed==4000 - every interrupt tick send move signal to stepper
// isr runs 30k times per second
// 800 calls are required for 1mm step
// speed/4000*30000/8000 cm per second
Receiver.prototype.calcSpeed = (raw) => (raw/4000*30000/8000).toFixed(2) + "cm/s";

Receiver.prototype._ = function(json)
{
  json = {pos:json[0], force:json[1], spd:json[2]};

  lastValue = {pos:json.pos, force:json.force, spd:json.spd};

  if (logger.enabled)
    logger.data.push([json.pos, json.force, json.spd]);
  if (charter.enabled)
    charter.onData([json.pos, json.force, json.spd]);
    
  graph.dot(json.pos, json.force, "#f00");
  document.getElementById("info").innerHTML = "position: " + this.calcPosition(json.pos) + 
    " force: " + this.calcForce(json.force) + " speed: " + this.calcSpeed(json.spd);
  if (ui.manual)
  {
    var millis = (new Date()).getTime();

    var pos = Math.floor(Math.sin(millis/2000.0)*20000);
    var alpha10 = millis/10000.0;
    alpha10 -= Math.floor(alpha10);
    var alpha2 = millis/5000.0;
    alpha2 -= Math.floor(alpha2);
//    var pos = (-1+alpha10*2)*10000 - Math.sin(alpha2*Math.PI*2)*10000;
    graph.debugDot(pos, json.spd, "#00f");
    comm.send("go=" + Math.floor(pos));
  }
  //graph.current.dot(ui.mouse.x - graph.current.can.offsetLeft, ui.mouse.y - graph.current.can.offsetTop, "#0b0");
}

Receiver.prototype._g = function(json)
{
  document.getElementById("extra").innerHTML = JSON.stringify(json);
}

Receiver.prototype._e = function(json)
{
  alert("Chyba: "+ JSON.stringify(json));
}

Receiver.prototype._f = function(json)
{
  document.getElementById("extra").innerHTML = "synthesized function target="+JSON.stringify(json);
}
Receiver.prototype._config = function(json)
{
  document.getElementById("extra").innerHTML = "config="+JSON.stringify(json);
}

var Charter = function()
{
  this.fixedXXX = n => Math.floor(n*1000)/1000;
  this.fixedXX = n => Math.floor(n*100)/100;
  this.fixedX = n => Math.floor(n*10)/10;
  this.gramsToMn = n => n*10; // grams to milli Newtons

  this.calcPosition = (raw) => this.fixedXX(raw/8000); //.toFixed(2) + "cm";
  this.calcForce = (raw) => this.fixedX(this.gramsToMn(raw/2/8300*100)); //.toFixed(2) + "g";
  this.calcSpeed = (raw) => this.fixedXX(raw/4000*30000/8000); //.toFixed(2) + "cm/s";

  this.chart = null;
  this.enabled = false;
}

Charter.prototype.onData = function(d)
{
  var pos = d[0];
  var force = d[1];
  var speed = d[2];
  if (!this.movingRight && speed > 0)
  {
    this.movingRight = true;
    this.collected = [];
  }
  if (this.movingRight && speed < 0)
  {
    this.movingRight = false;
    this.onFinish(this.dataset);
    this.dataset = [];
  }
  if (this.movingRight)	
  {
//    dataset.push([conv.calcPosition(pos), (conv.calcForce(force)/conv.calcSpeed(speed))]);
//    dataset.push([conv.calcPosition(pos), Math.abs(conv.calcForce(force))]);
    var speedCmps = Math.abs(this.calcSpeed(speed));
    var forceMn = Math.abs(this.calcForce(	force));
    var positionCm = this.calcPosition(pos);
    if (speedCmps > 0.5)
//      dataset.push([positionCm, speedCmps]);
      this.dataset.push([positionCm, this.fixedXX(forceMn/speedCmps)]);
  }
}

Charter.prototype.onFinish = function(dataset)
{
  this.chart.addSeries({name:"Pass "+this.pass, data:this.dataset});
  this.pass++;
}

Charter.prototype.onInit = function()
{
  this.movingRight = false;
  this.collected = [];
  this.dataset = [];
  this.pass = 0;

  this.chart = Highcharts.chart('chart', 
  {
      chart: { type: 'spline', animation: Highcharts.svg, marginRight: 10 },
      title: { useHTML: true, text: 'odpor [mN*s*cm<sup>-1</sup>] v zavislosti od polohy [cm]' },
      xAxis: {gridLineWidth: 1},
      yAxis: { title: { text: 'sila [mN] / rychlost [cm/s]' } },
      legend: { enabled: true },
      exporting: { enabled: false },
      tooltip: { shared:true, headerFormat: '{point.key}mm<br>' }
  });
}


var lastValue = {};
var funct = {min:-20000, max:+20000, period:4.0, flavour:0};
var comm = new Comm();
var ui = new Ui(comm);
var receiver = new Receiver();
var graph = new Graph();
var logger = {enabled:false, data:[]};
var charter = new Charter();
</script>
</html>
)---";
