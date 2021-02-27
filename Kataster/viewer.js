var fs = require("fs");
var d = fs.readFileSync("output.json");
var data = JSON.parse(d);
console.log(data);

function kml(b)
{
  fs.appendFileSync('output_map.kml', b+"\n");
}

var firstHtml = false;
function html(b)
{
  if (!firstHtml) 
  { 
    firstHtml = true;
//    fs.unlinkSync('output_list.html');
  }
  fs.appendFileSync('output_list.html', b+"\n");
}

lastgroupid = "";
curgroupidi = 0;

function dumpKmlFooter()
{
  var l = kml;
  if (curgroupidi > 0)
   l('</Folder>');  
  l('</Document>');
  l('</kml>');
}

function dumpKmlHeader()
{
  var l = kml;
  l('<?xml version="1.0" encoding="UTF-8"?>');
  l('<kml xmlns="http://www.opengis.net/kml/2.2" xmlns:gx="http://www.google.com/kml/ext/2.2" xmlns:kml="http://www.opengis.net/kml/2.2" xmlns:atom="http://www.w3.org/2005/Atom">');
  l('<Document>');
  l('<name>Kataster portal kml report</name>');
}

function dumpKmlPolygon(folder, id, groupid, grouppoly)
{
  var l = kml;
  var colors = ['#058DC7', '#50B432', '#ED561B', '#DDDF00', '#24CBE5', '#64E572', 
             '#FF9655', '#FFF263', '#6AF9C4'];
  
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
    if (!(poly[0][0] == poly[poly.length-1][0] && poly[0][1] == poly[poly.length-1][1]))
      throw "wrong poly format";

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

// dump kml
dumpKmlHeader();
for (var folioid in data.folios)
{
  var folio = data.folios[folioid];
  for (var j in folio)
  { 
    var parcel = folio[j];
      dumpKmlPolygon(
        "LV: "+folioid, 
         parcel.register + ": " + parcel.parcel + " Plocha: " + parcel.area.numerator + "/"+parcel.area.denominator + " " + parcel.area.meters, 
         folioid,
         parcel.geometry);
  }
}

makeTable = json => { 
    var q = "";
    for (var i in json)
    {
      var v = json[i];
      if (typeof(v) == "object")
        v = makeTable(v);
      q += "<tr><td>"+i+"</td><td>"+v+"</td></tr>";
    }
    if (q=="")
      return "null";
    return "<table class='detail' cellspacing=0 cellpadding=1 border=1>" + q + "</table>";
  }

makeTable2 = json => { 
    var q = "";
    for (var i in json)
    {
      var v = json[i];
      q += "<tr><td>"+v.podiel+"</td><td>"+v.meno+"</td></tr>";
    }
    if (q=="")
      return "null";
    return "<table class='detail' cellspacing=0 cellpadding=1 border=1>" + q + "</table>";
  }


function national(s)
{
  return s.normalize("NFD").replace(/[\u0300-\u036f]/g, "").toLowerCase()
}

dumpKmlFooter();

  var totalAllFolioPartialArea = 0;

// dump html
html(getStylesheet())
html("<h2>" + data.owner.name + ", " + data.owner.address + "</h2>");
html("Detailny vypis ploch z katastra pre '"+data.request.name+"' v katastralnom uzemi "+data.request.cadastralUnit+" zo dna " + new Date(data.request.timestamp)+ "<br>\n");
html("<a href='output_map.html'>Mapa parcel</a>. Kliknutim na parcelu sa zobrazi jej oznacenie<br><br>")

for (var folioid in data.folios)
{
  var folio = data.folios[folioid];
  html("<h3>List vlastnictva "+folioid+"</h3>\n");

  var totalFolioArea = 0;
  var totalFolioPartialArea = 0;
  var totalAllFolioPartialArea = 0;

  var count = 0;

  html("<table border=1>\n");
  html(`
    <col width="80px"/>
    <col width="80px"/>
    <col width="260px"/>
    <col width="100px"/>
    <col width="100px"/>
    <col width="100px"/>
    <col width="100px"/>
    <col width="50px"/>
    <col width="140px"/>
  `);
  html("<tr>");
  html("<th>parcela</th>");
  html("<th>register</th>");
  html("<th>vyuzitie</th>");
  html("<th>plocha</th>");
  html("<th>podiel</th>");
  html("<th>podielova plocha</th>");
  html("<th></th>");
  html("</tr>\n");

  for (var j in folio)
  { 
    var parcel = folio[j];
    var use = false;
    var sumValky = 0;
    var sumGerhat = 0;
    for (k in parcel.participants)
    { 
      var normName = national(parcel.participants[k].meno);
      if (normName.indexOf("gerhat") != -1 || normName.indexOf("gerhart") != -1)
      {
        use = true;
        sumGerhat += eval(parcel.participants[k].podiel);
      }
      if (normName.indexOf("valky") != -1)
      {
        sumValky += eval(parcel.participants[k].podiel);
      }
    }

    var partial = parcel.area.meters*parcel.area.numerator/parcel.area.denominator;

    html(use ? "<tr class='highlight'>" : "<tr>");
    html("<td>"+parcel.parcel+"</span></td>");
    html("<td>"+parcel.register+"</td>");
    html("<td class='withComment'>"+parcel.use+"<span class='cellComment'>"+makeTable(parcel.useDetails)+"</td>");
    html("<td>"+parcel.area.meters+"</td>");
    html("<td class='withComment'>"+parcel.area.numerator+"/"+parcel.area.denominator+"<span class='cellComment'>"+makeTable2(parcel.participants)+"</span></td>");
    html("<td>"+Math.floor(partial)+"</td>");
    html("<td><a href='"+parcel.mapUrl+"'>mapa</a></td>");
    html("</tr>\n");

    count++;
    totalFolioArea += parcel.area.meters;
    totalFolioPartialArea += partial;
  }

  if (count > 0)
  {
    html("<tr class='summary'>");
    html("<td colspan=3>suma</td>");
    html("<td>"+Math.floor(totalFolioArea)+"</td>");
    html("<td></td>");
    html("<td>"+Math.floor(totalFolioPartialArea)+"</td>");
    html("<td></td>");
    html("</tr>\n");

    html("</table>\n"); 
  }

  totalAllFolioPartialArea += totalFolioPartialArea;
}

    html(`
<br><br>
<table>
<tr><th>Skupina</th><th>Celkova vymera pre skupinu</th></tr>
<tr><td>Main</td><td>` + Math.floor(totalAllFolioPartialArea) + `</td></tr>
</table>`); 


function getStylesheet()
{
  return`
<head>
  <meta charset="UTF-8">
</head>

<style>
table {
    font-family: arial, sans-serif;
    border-collapse: collapse;
}

td, th {
    border: 1px solid #dddddd;
    text-align: left;
    padding: 8px;
}

.highlight td {
    background-color: #b0c0ff;
}

tr:nth-child(even) {
    background-color: #f0f0f0;
}
.withComment{
  position:relative;
}

.cellComment{
  display:none;
  position:absolute; 
  z-index:100;
  border:1px;
  background-color:white;
  border-style:solid;
  border-width:1px;
  border-color:gray;
  padding:3px;
  color:red; 
  top:20px; 
  left:20px;
}

.withComment:hover span.cellComment{
  display:block;
}
.detail, 
.detail td,
.detail th {
  font-size:14px;
  white-space: nowrap;
  padding:1px;
  border:0px;
  background-color:#ffffff;
}
.detail tr:nth-child(even) {
    background-color: #f0f0f0;
}
.detail tr:nth-child(odd) {
    background-color: #e0e0e0;
}
.summary td {
  color: #808080;
  font-style: italic;
  background-color: white;
}
.detail td:nth-child(1) {
    font-weight:bold;
}
</style>`;
}
