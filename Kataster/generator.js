var request = require("request");
var fs = require("fs");

var cookie = "_ga=GA1.2.439494694.1613241620; ZbGis_acceptedCookie1=2021-02-13T19:26:45.419Z; 3.23=2021-02-13T20:19:24.992Z; BIGipServerpool_zbgis_mapclient=2025367744.20480.0000; _gid=GA1.2.1631876125.1614429574; _gat=1; session-/Common/SPWEB_VIP_443=34249530; .ESKN_RECAPTCHA=CD3zaMypSmGp1cZ0TVId6wholl6Dq7%2fc9CYLMAwtYHlutxX1SLCpypYFGw7i5PrfbuO8E0TGXI4DSFetQaCIHqxacgwKRT8osm8E%2bQogDzn00r7%2fFGj64JoLPcebddlCeOd71eRI%2f7a3BAb30B7Y3rEjcNw31lyP7XSTHc0nUMI%3d";

//var findName = "Losonsky Richard";
var findName = "Tomcanyi Martin";
var cu = "855251";
var outputFile = "output.json";

class Writer {
  constructor()
  {
    this.data = {folios:{}};
    this.lastFolio = null;
  }
  setRequest(json)
  {
    this.data.request = json;
    this.data.request.timestamp = new Date();
  }
  setOwner(json)
  {
    this.data.owner = json
  }
  addFolio(id)
  {
    this.data.folios[id] = [];
    this.lastFolio = id;
  }
  addParcel(json) 
  {
    this.data.folios[this.lastFolio].push(json);
  }
  setParcelGeometry(rings)
  {
    var folio = this.data.folios[this.lastFolio];
    var parcel = folio[folio.length-1];
    var f = v => Math.floor(v*10000000)/10000000;

    parcel.geometry = [];
    for (var j = 0; j<rings.length; j++)
    {
      var poly = rings[j];
      if (!(poly[0][0] == poly[poly.length-1][0] && poly[0][1] == poly[poly.length-1][1]))
        throw "wrong poly format";

      var subpoly = []
      for (var i in poly)
        subpoly.push([f(poly[i][0]), f(poly[i][1])])
      parcel.geometry.push(subpoly)
    }
  }
  getText()
  {
    return JSON.stringify(this.data);
  }
}

function download(url)
{
  return new Promise((resolve,reject) =>
  {
      request({
          url: url,
          method: "GET",
      }, (e, r, json) =>
      {
        if (e) reject();
        else resolve(JSON.parse(json));
      });
  });
}

function Search(op, ltext, cu, query)
{
  return new Promise((resolve, reject) =>
  {  
    var url = "https://zbgis.skgeodesy.sk/mkzbgis/Cadastral/" + op;
    request({
        url: url,
        method: "POST",
        json: {text: query, lockText: ltext, cu: cu}
    }, (e, r, json) =>
    {
        if (e)
        {
            console.log("Failed to fetch url: " + url);
            console.log("Error: " + e);
            throw "error";
            reject();
            return;
        }

        var results = [];
        for (var i in json.results)
          results.push({txt:json.results[i].txt, id:json.results[i].id, addr:json.results[i].txtDesc, 
            category:json.results[i].category, detail:json.results[i].detailLink});
     
        resolve(results);
    });
  });
}

function getParcelGeometry(cu, parcelName, reg)
{
  if (cu != "855251")
    throw "wrong cu";

  return Search("Search", "k.ú. Sereď (855251)", cu, parcelName)
  .then((r) => r.find(e=>e.category == "parcela-"+(reg=="C"?"c":"e") && e.txt == parcelName))
  .then((f) => 
  {
    if (!f || !f.detail)
    {
      console.log("Geometry req failed");
      throw "Geometry req failed";
    }

    var match = f.detail.match("\\((\\d+)\\)");
    if (match && match.length == 2)
      return "https://kataster.skgeodesy.sk/eskn/rest/services/VRM/parcels_" + (reg=="C"?"c":"e") + "_view/MapServer/0/" +
        "query?objectIds="+match[1]+"&returnGeometry=true&outSR=4326&f=json";
    else
      throw "no geometry url"
  })
  .then((url) => download(url))
  .then((json) => 
  {
    if (json.features.length != 1)
      throw "features len error";
    if (json.features[0].attributes["PARCEL_NUMBER"] != parcelName)
      throw "parcel name no match";
    return json.features[0].geometry.rings;
  })
  .catch( (e) =>
  { 
    console.log("ERROR: getParcelGeometry failed")
  })
}

function getNameSuggestion(name)
{
  return Search("Search", "k.ú. Sereď (855251)", "855251", name)
    .then((r) =>
    {
        if (r && r.length)
        {
            for (var i in r)
              r[i].cu = "855251";
            return r;
        }

        return Search("Search", "obec Sereď (okres Galanta)", "504009", name)
          .then((r) =>
            {
                for (var i in r)
                  r[i].cu = "504009";
                return r;
            });
    });
}

function getPagedRequest(url, response, single)
{
  return new Promise((resolve, reject)=>
  {
      if (!response)
        response = [];

      request({
          url: url,
          method: "GET",
          headers: { "Cookie": cookie }
      }, (e, r, json) =>
      {
          if (e)
          {
              console.log("failed to fetch: " + url);
              throw "error: " + e;
              reject();
              return;
          }

          try {
            json = JSON.parse(json);
          } catch (e) {
            console.log("(187) failed to fetch: " + url);
            console.log("json: " + json);
            throw "Json parse failed";
          }
          if (!single && typeof(json["@odata.count"]) != "number")
          {                   
            console.log("request:"+url);
            console.log(json);
            console.trace();
            throw "invalid count type"
          }

          for (var i in json.value)
            response.push(json.value[i]);

          if (json["@odata.nextLink"])
            return getPagedRequest(json["@odata.nextLink"], response).then((r) => resolve(r))
          else 
          {
            if (!single && json["@odata.count"] != response.length)
              throw "length no match";

            resolve(response);
          }
      });
  });
}

function getFolioListFor(entity)
{
  return getPagedRequest("https://kataster.skgeodesy.sk/PortalODataPublic/Participants?%24filter=Subjects%2Fany(p%3A+p%2FId+eq+"+entity.id+")+and+CadastralUnit%2FCode+eq+"+entity.cu+"&%24select=Id%2CValidTo%2CName&%24expand=Municipality(%24expand%3DDistrict(%24select%3DName))%2COwnershipRecord(%24select%3DId%2COrder%3B%24expand%3DFolio(%24select%3DNo%2CId))%2CCadastralUnit(%24select%3DName%2CCode)&%24orderby=OwnershipRecord%2FFolio%2FNo%2COwnershipRecord%2FOrder&%24skip=0&%24count=true")
    .then((result)=>result.map(e => ({Id:e.Id, Folio:e.OwnershipRecord.Folio})));
}

function getParcelsForFolio(folioId, register)
{
  console.log("getParcelsForFolio "+folioId + " reg "+register);
  
  if (register == "C")
    url = "https://kataster.skgeodesy.sk/PortalODataPublic/ParcelsC?%24filter=FolioId+eq+"+folioId+"&%24select=Id%2CNo&%24orderby=NoSort&%24skip=0&%24count=true";
  else
    url = "https://kataster.skgeodesy.sk/PortalODataPublic/ParcelsE?%24filter=FolioId+eq+"+folioId+"&%24select=Id%2CNoFull&%24orderby=NoSort&%24skip=0&%24count=true";

  return getPagedRequest(url);
}

function getParcelInfo(parcelName, register, cu)
{
//  console.log("getParcelInfo parcelName="+parcelName+" register="+register+" cu="+cu);

  var parcelInfo = "";
  if (register == "C")
    parcelInfo = "https://kataster.skgeodesy.sk/PortalODataPublic/ParcelsC?$select=Id,ValidTo,No,Area,HouseNo,Extent&$expand=OwnershipType($select=Name,Code),CadastralUnit($select=Name,Code),Localization($select=Name),Municipality($select=Name),LandUse($select=Name),SharedProperty($select=Name),ProtectedProperty($select=Name),Affiliation($select=Name),Folio($select=Id,No),Utilisation($select=Name),Status($select=Code)&$filter=CadastralUnit/Code%20eq%20"+cu+"%20and%20No%20eq%20%27"+parcelName+"%27";
  else
    parcelInfo = "https://kataster.skgeodesy.sk/PortalODataPublic/ParcelsE?$select=Id,ValidTo,No,NoFull,Area,HouseNo,Extent&$expand=OwnershipType($select=Name,Code),CadastralUnit($select=Name,Code),Localization($select=Name),Municipality($select=Name),LandUse($select=Name),SharedProperty($select=Name),Folio($select=Id,No),Status($select=Code),OriginalCadastralUnit($select=Name,Code,Value)&$filter=CadastralUnit/Code%20eq%20"+cu+"%20and%20NoFull%20eq%20%27"+parcelName+"%27";

  return getPagedRequest(parcelInfo, [], true)
    .then((result)=>{
     if (result.length != 1 || (result[0].No != parcelName && result[0].NoFull != parcelName)) 
     {
       console.log(result);
//       console.log("Parcel name: " + parcelName);
       throw "(250) wrong res";
     }

     return {
          area:result[0].Area,
          use:result[0].LandUse.Name,
          localization:result[0].Localization.Name
        };
   });
}

function getParticipantsForParcel(parcelId, register)
{
  var participants = "https://kataster.skgeodesy.sk/PortalODataPublic/Parcels"+register+"("+parcelId+")/Kn.Participants?%24filter=Type%2FCode+eq+1&%24select=Id%2CName%2CValidTo%2CNumerator%2CDenominator&%24expand=OwnershipRecord(%24select%3DOrder)&%24orderby=OwnershipRecord%2FOrder&%24skip=0&%24count=true"
  return getPagedRequest(participants)
  .then((r) => r.map(p=>({Id:p.Id, Numerator:p.Numerator, Denominator:p.Denominator, Name:p.Name})));
}

function matchParticipant(participants, Id)
{
  var found = participants.find(e=>e.Id == Id);
  if (!found)
    throw "Participant not found";
  return Promise.resolve(found);
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

function getReportForParcel(folio, parcel, register, cu)
{
//  console.log("getReportForParcel " + folio.Folio.No + " parcel " + parcel.Id + " cu " + cu);
  var parcelInfo = {};
  var participants = {};
//  return getParcelInfo(folio.Folio.No, cu)
  return getParcelInfo(parcel.NoFull ? parcel.NoFull : parcel.No, register, cu)
  .then((info) => parcelInfo = info)
  .then(() => getParticipantsForParcel(parcel.Id, register))
  .then((r) => {participants = r; return matchParticipant(r, folio.Id);})
  .then((r) => 
{
  var report = {
    participants: participants.length,
    folio: folio.Folio.NoFull ? folio.Folio.NoFull : folio.Folio.No,
    parcel: parcel.No ? parcel.No : parcel.NoFull,
    register: register,
    use: parcelInfo.use,
    area: parcelInfo.area,
    num: r.Numerator,
    den: r.Denominator, 
    partial: Math.floor(parcelInfo.area*r.Numerator/r.Denominator)};

  report.urlPreview = "https://zbgis.skgeodesy.sk/mkzbgis/sk/kataster?bm=zbgis#/detail/kataster/parcela-"+(register=="E"?"e":"c")+"/"+cu+"/" + report.parcel.replace("/", "_");

    totalFolioArea += report.area;
    totalFolioPartialArea += report.partial;
    totalPartialArea += report.partial;
    totalArea += report.area;
    totalParcels++;
    console.log("folio:"+report.folio + " parcel:" + report.parcel + " " + report.register + " (" + report.use + ") area: "+report.area+
    " part: "+report.num+"/"+report.den+" partialarea:"+report.partial);

    var simpleParticipants = participants.map(p=>({podiel:p.Numerator + "/" + p.Denominator, meno:p.Name}));

  out.addParcel({
    parcel: report.parcel, 
    register: report.register, 
    use: report.use,
    useDetails: parcelInfo, 
    area: {
      meters:report.area,
      numerator:report.num,
      denominator:report.den},
    participants: simpleParticipants,
    mapUrl: report.urlPreview}); 

  return getParcelGeometry(cu, report.parcel, report.register)
   .then(rings => {
     if (rings)
       out.setParcelGeometry(rings);
    });
  });
}

//getReportForParcel(folios[0], parcelList[0], cu);

function processFolio(folio, cu, register)
{
//  console.log("Folio " + folio.Folio.No + " cadastral unit " + cu + " register " + register);
  var totalParcels = 0;

  var processParcels = (parcels) => //new Promise((resolve, reject) =>
  {
    if (parcels.length == 0)
       return Promise.resolve(totalParcels);

    return getReportForParcel(folio, parcels.shift(), register, cu)
    .then( ()=>processParcels(parcels) )
  };

  return getParcelsForFolio(folio.Folio.Id, register)
  .then((parcels) => 
  {
    totalParcels = parcels.length; 
    if (totalParcels > 0 )
    {
      out.addFolio(folio.Folio.No);
      totalFolioPartialArea = 0;
      totalFolioArea = 0;
    }
    return processParcels(parcels);
  })
  .then((count) => 
  { 
    if (count > 0)
    {
      // totalFolioArea, totalFolioPartialArea
    }
    return count;
  })
}

function processFolios(folios, cu)
{
  var process = (folios) => //new Promise((resolve, reject) =>
  {
    if (folios.length == 0)
      return Promise.resolve();

    var folio = folios.shift();
    var parcelCount = 0;

    return processFolio(folio, cu, "C")
    .then( (n) => parcelCount += n)
    .then( () => processFolio(folio, cu, "E"))
    .then( (n) => parcelCount += n)
    .then( () => {
      if (parcelCount == 0) {
        console.log("Warning: No parcels found in folio: " + folio.Folio.No);
      }
    })
    .then( () => process(folios) );
  };

  return process(folios, cu);
}

function removeOwner(owners, keyword)
{
  return owners.filter(o => o.addr.indexOf(keyword) == -1)
}

function processOwners(owners)
{
  var process = (owners) => 
  {
    if (owners.length == 0)
      return Promise.resolve();

    var owner = owners.shift();
    console.log(owner.txt + ", " + owner.addr);
    out.setOwner({name: owner.txt, address:owner.addr});

    return Promise.resolve(owner)
     .then((o) => getFolioListFor(o))
     .then((folios) => processFolios(folios, cu))
     .then( () => process(owners) );
  };

  return process(owners, cu);  
}

var totalArea = 0, totalPartialArea = 0, totalParcels = 0, totalFolioArea = 0, totalFolioPartialArea = 0;
var out = new Writer();

out.setRequest({name: findName, cadastralUnit:cu})
getNameSuggestion(findName)
.then((r) => {
    if (r.length == 0)
    {
      console.log("Not found!");
      throw "name not found";
    }
    console.log("Found names:");
    for (var i in r)            
      console.log(r[i].txt);
    console.log("========")
    return r;
  })
.then((r)=> removeOwner(r, "Bratislava"))
.then((r) => processOwners(r))
.then(() => {
  console.log("Total area: "+totalArea + " total partial area: " + totalPartialArea + " total parcels:"+totalParcels)
})
.then(() => fs.writeFile(outputFile, out.getText(), () => false) );
