// Kataster portal to kml converter
// Ziska geometriu parcely a skonvertuje do KML suboru ktory sa da vizualizovat v google earth

var request = require("request");

var list = [
  {lv:"5124", parcela:"1372", register:"e", pomer:"1/5", plocha:5355},
  {lv:"5124", parcela:"1373/201", register:"e", pomer:"1/5", plocha:3174},
  {lv:"5124", parcela:"1373/202", register:"e", pomer:"1/5", plocha:1257},];

function _ASSERT(e)
{
    if (!e)
      throw new Error();
}

function findParcela(parcela, kategoria, h)
{
    findParcelaSub("k.ú. Sereď (855251)", "855251", parcela, kategoria, (r) =>
    {
        if (r)
        {
            h(r);
            return;
        }
        if (!r)
          findParcelaSub("obec Sereď (okres Galanta)", "504009", parcela, kategoria, (r) =>
            {
                _ASSERT(r);
                h(r);
                return;                
            });
    });
}

function findParcelaSub(ltext, cu, parcela, kategoria, h)
{
    request({
        url: "https://zbgis.skgeodesy.sk/mkzbgis/Cadastral/Suggest",
        method: "POST",
        json: {text: parcela, lockText: "k.ú. Sereď (855251)", cu: "855251"}
    }, (e, r, json) =>
    {
        if (e)
        {
            if (e=="Error: read ECONNRESET")
            {
                console.log("<!-- try reconnect -->");
                findParcelaSub(ltext, cu, parcela, kategoria, h);                
                return;
            }
            console.log("error: " + e);
            _ASSERT(0);
            h();
            return;
        }
        for (var i in json)
        {
            if (json[i].txt == parcela && json[i].category == "parcela-"+kategoria)
            {
                h(detailToGeometry(json[i].detailLink, kategoria));
                return;
            }
        }
    });
}

function downloadJson(url, h)
{
    request({
        url: url,
        method: "GET",
    }, (e, r, data) =>
    {
        if (e)
        {
            console.log("Chyba pri stahovani: "+url)
            _ASSERT(0);
            console.log("error: " + e);
            h();
            return;
        }
        h(JSON.parse(data));
    });
}

function detailToGeometry(url, register)
{
  var match = url.match("\\((\\d+)\\)");
  if (match && match.length == 2)
    return "https://kataster.skgeodesy.sk/eskn/rest/services/VRM/parcels_" + register + "_view/MapServer/0/" +
      "query?objectIds="+match[1]+"&returnGeometry=true&outSR=4326&f=json";
}

function dumpKmlHeader()
{
  var l = (x) => console.log(x);
  l('<?xml version="1.0" encoding="UTF-8"?>');
  l('<kml xmlns="http://www.opengis.net/kml/2.2" xmlns:gx="http://www.google.com/kml/ext/2.2" xmlns:kml="http://www.opengis.net/kml/2.2" xmlns:atom="http://www.w3.org/2005/Atom">');
  l('<Document>');
  l('<name>Kataster portal kml report</name>');
}

lastgroupid = "";
curgroupidi = 0;

function dumpKmlFooter()
{
  var l = (x) => console.log(x);
  if (curgroupidi > 0)
   l('</Folder>');  
  l('</Document>');
  l('</kml>');
}

function dumpKmlPolygon(folder, id, groupid, grouppoly)
{
  var l = (x) => console.log(x);
  var colors = ['#058DC7', '#50B432', '#ED561B', '#DDDF00', '#24CBE5', '#64E572', 
             '#FF9655', '#FFF263', '#6AF9C4',
             '#ff0000', '#00ff00', '#0000ff', "#ffff00", "#ff00ff", "#00ffff"];
  
  if (lastgroupid != groupid)
  {
    if (curgroupidi > 0)
      l('</Folder>');
    lastgroupid = groupid;
    curgroupidi++;
    l('<Folder>');
    l('<open>1</open>');
    l('<name>' + folder + "</name>");
  }
  
  var color = colors[curgroupidi % colors.length].substr(1);

  for (var j = 0; j<grouppoly.length; j++)
  {
    var poly = grouppoly[j];
    _ASSERT(poly[0][0] == poly[poly.length-1][0] && poly[0][1] == poly[poly.length-1][1]);

    l('<Placemark>');
    l('<Style>');
    l('<LineStyle><width>1.0</width><color>ff' + color + '</color></LineStyle>');
    l('<PolyStyle><color>80' + color + '</color><fill>1</fill></PolyStyle>');
    l('</Style>');
    
    if (grouppoly.length>1)
      l('<name>' + id + ' ('+(j+1)+"/"+grouppoly.length+ ')</name>');
    else
      l('<name>' + id + '</name>');

    
    l('<Polygon>');
    l('<tessellate>1</tessellate>');
      l('<outerBoundaryIs>');
      l('<LinearRing>');
      l('<coordinates>');
      for (var i in poly)
      {
        l(poly[i][0].toFixed(7) + "," + poly[i][1].toFixed(7)+",0");
      }
      l('</coordinates>');
      l('</LinearRing>');
      l('</outerBoundaryIs>');
    l('</Polygon>');
    l('</Placemark>');
  }
}

dumpKmlHeader();

function findContinue()
{
    var rec = list.shift();

    console.log("<!-- hladam " + rec.lv + " - " + rec.parcela + " (" + rec.register + ") -->");
    
    findParcela(rec.parcela, rec.register, (l) => {
        downloadJson(l, (data) => {
            if (!data)            
            {
                _ASSERT(0);
                console.log("<!-- chyba! -->");
                findDone();
                return;
            }

            _ASSERT(data.features.length == 1);
            _ASSERT(data.features[0].attributes["PARCEL_NUMBER"] == rec.parcela);

            var poly = data.features[0].geometry.rings;
            dumpKmlPolygon("LV: "+rec.lv, rec.register.toUpperCase() + ": " + rec.parcela + " " + rec.pomer + " Plocha: " + rec.plocha, rec.lv, poly);
            findDone();
        })
    });
}

function findDone()
{
  if (list.length > 0)
  {
    findContinue();
    return;
  }
  dumpKmlFooter();  
}

findContinue();