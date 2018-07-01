var autoupdate = true;
var chart;
var clearTimer;
var liveZoom = true;

// grafy
function loadScript(url, handler) {
	window.collected = [];
    
	window._ = function(json) {
		window.collected.push(json);
	};

	var head = document.getElementsByTagName('head')[0];

	var script = document.createElement('script');
	script.id = "remote_script";
	script.type = 'text/javascript';
	script.src = url;
	script.onload = function() {
		window._ = null;
		handler(window.collected);
	};

	for (var i = 0; i < head.childNodes.length; i++) {
		if (head.childNodes[i].nodeName == "SCRIPT" && head.childNodes[i].id == "remote_script") {
			head.removeChild(head.childNodes[i]);
			break;
		}
	}

	head.appendChild(script);
}

function todayTimestamp()
{
	return new Date().getFullYear() + "-" + ("0" + (new Date().getMonth() + 1)).substr(-2) + "-" + ("0" + (new Date().getDate())).substr(-2);    
}

function today() {
	if (window.location.hash !== "") {
		//autoupdate = false;
		return window.location.hash.substr(1);
	}
    return todayTimestamp();
}


function history(delta)
{
    liveZoom = false;
    
    if (clearTimer)
        clearTimeout(clearTimer);

    clearTimer = setTimeout(function()
    {
       chart.setTitle({text:"Nie su ziadne data pre " + today()});

        while(chart && chart.series.length > 0)
            chart.series[0].remove(true);
    }, 500);
        
    // 2017-09-29
    var t = today();
    var d = new Date(t.substr(0, 4), t.substr(5, 2)-1, t.substr(8, 2));
    d.setDate(d.getDate() + delta);
    var f = d.getFullYear() + "-" + ("0" + (d.getMonth() + 1)).substr(-2) + "-" + ("0" + (d.getDate())).substr(-2);
    window.location.hash = "#" + f;
    chart.setTitle({text:"Nacitavam " + f + "..."});

    update(function()
    {
        clearTimeout(clearTimer);
        clearTimer = null;
    });
    
    autoupdate = f == todayTimestamp();
}

/*
 function joinData(d0, d1)
 {
 var result = [];
 
 for (var i=0; i<d0.length; i++)
 result.push(Math.max(d0[i], d1[i]));
 
 return result;
 }
 
function reduceData(data, len) {
	while (data.length > len) {
		var newData = [];
		for (var i = 0; i < data.length - 1; i += 2)
			newData.push(data[i]); //.push(joinData(data[i], data[i+1]));

		if (data.length & 1)
			newData.push(data[data.length - 1]);

		data = newData;
	}
	return data;
}
*/

function update(onLoad) {
    var lastts = 0;
    var firstts = 0;


	loadScript("logs/" + today() + ".js", function(alldata) {
        if (onLoad)
            onLoad();
    
        lastts = alldata[alldata.length-1].ts;
        firstts = alldata[0].ts;
        
        var data = alldata.filter(function(e){return e.data && e.data.devs;});
        var eventdata = alldata.filter(function(e){return !!e.websocket && e.websocket.data.length > 3;});
        
		var buildSeriesPair = function(id, key, color, visible) {

			var values;
			if (key == "$ion")
				values = data.map(function(json) {
					return [json.ts, json.data.ion[0]];
				});
			else if (key == "$cerpadlo")
				values = data.map(function(json) {
					return [json.ts, (json.data.devs.cerpadlo != "off") * 1.7 + 8];
				});
			else if (key == "$plyn")
				values = data.map(function(json) {
					return [json.ts, (json.data.devs.plyn != "off") * 1.7 + 6];
				});
			else if (key == "$ventilator")
				values = data.map(function(json) {
					return [json.ts, (json.data.devs.ventilator != "off") * 1.7 + 10];
				});
			else
				values = data.map(function(json) {
					return [json.ts, json.data.temp[key]];
				});

			//      values = reduceData(values, 350);

			return [{
				name: id,
				data: values,
				zIndex: 1,
				marker: {
					enabled: false
				},
				color: Highcharts.getOptions().colors[color],
				visible: visible
			}];
		};

		var series = [];
		series = series.concat(buildSeriesPair("Teplota kotla", "termostat", 2, true));
		series = series.concat(buildSeriesPair("Teplota vody vystup", "vystup", 0, true));
		series = series.concat(buildSeriesPair("Teplota vody vstup", "vstup", 1, true));
		series = series.concat(buildSeriesPair("Vzduch nasavania", "vzduch", 3, false));
		series = series.concat(buildSeriesPair("Ionizacny senzor", "$ion", 6, false));
		series = series.concat(buildSeriesPair("Plyn", "$plyn", 5, true));
		series = series.concat(buildSeriesPair("Cerpadlo", "$cerpadlo", 4, false));
		series = series.concat(buildSeriesPair("Ventilator", "$ventilator", 7, false));
        
        var events = eventdata.map(function(e) {
            var important = (e.websocket.data == "start\n" || e.websocket.data == "safe\n");
        	return {
        		color: important ? "#00b000" : "#808080",
        		value: e.ts,
        		width: important ? 2 : 1,
                zIndex: important ? 5 : 0,
        		label: {
        			text: e.websocket.address + ": " + e.websocket.data,
        		}
        	};
        });
        
		Highcharts.setOptions({
			chart: {
                //type: "StockChart",
				zoomType: "x"
			},
			global: {
				useUTC: false
			},
			plotOptions: {
				series: {
					animation: false
				}
			},
            credits:false
		});

		chart = Highcharts.chart('chart', {
			title: {
				text: "Meranie teploty " + today() + ((today() == todayTimestamp()) ? " (live)" : "")
			},
			xAxis: {
				type: 'datetime',
				//          tickInterval: 60 * 60 * 1000
				gridLineWidth: 1,
				plotLines: events,
			},
            //resetZoomButton: {theme:{display:"block"}},
			yAxis: {
				title: {
					text: null
				},
				gridLineWidth: 1,
				min: 0,
			},
			tooltip: {
				crosshairs: true,
				shared: true,
				valueSuffix: " " + String.fromCharCode(0xb0) + "C"
			},
            exporting: {
                buttons: {
                    customButton: {
                        text: 'Den dopredu',
                        onclick: function () {
                            history(+1);
                        }
                    },
                   anotherButton: {
                        text: 'Den dozadu',
                        onclick: function () {
                            history(-1);
                        }
                    }
                }
            },
            
			series: series		
        });
        
        if (liveZoom)
            chart.xAxis[0].setExtremes(Math.max(firstts, lastts-1000*60*60*4), lastts);
	});
    //chart.zoom();
    //chart.showResetZoom();    
}

update();
setInterval(function() {
    if (autoupdate)
        update();
}, 60 * 1000);