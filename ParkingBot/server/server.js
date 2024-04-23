process.title = "***** parkbot";

const express = require("express");
const router = express.Router();
const app = express();
const path = require("path");
const basicAuth = require('express-basic-auth')
const port = 8056;
const prefix = "/";
var requested = [];
var lastUpdate = 0;
var remotePayload = null;

var auth = basicAuth( { authorizer: myAuthorizer, challenge: true } )
function myAuthorizer(username, password) {
  return password == "****";
}

app.use(express.json());
app.use(prefix, router);

var state = [
     {id:"#place7", state:"locked"},
     {id:"#place6", state:"locked"},
     {id:"#place5", state:"unlocked", user:"ivan"},
     {id:"#place4", state:"unlocked", user:"jozef"},
     {id:"#place3", state:"locked"},
     {id:"#place2", state:"locked"},
   ];

router.get("/status", auth, (req, res) => {
  res.setHeader('Content-Type', 'application/json');
  res.send({status:"good", lastUpdate:lastUpdate, payload:remotePayload, state:state})
});

router.get("/favicon.ico", (req, res) => {
  var f = favicon();
  res.writeHead(200, {
    'Content-Type': 'image/webp',
    'Content-Length': f.length
  });
  res.end(f)
});

router.get("/lock*", auth, (req, res) => {
  var cid = req.path.substr(-1)
  sendCode(cid);
  var tid = "#place"+cid;
  var st = state.find(s=>s.id == tid);
  st.state = "locked";
  delete st.user
  res.send(state)
});

router.get("/unlock*", auth, (req, res) => {
  var cid = req.path.substr(-1)
  sendCode(cid);
  var tid = "#place"+cid;
  var st = state.find(s=>s.id == tid);
  st.state = "unlocked";
  st.user = req.auth.user;
  res.send(state)
});

router.get("/logout", (req, res) => {
  res.status(401).send('Logged out<script>document.location.href="/"</script>')
});

router.post("/api", (req, res) => {
  remotePayload = req.body;
  lastUpdate = new Date().getTime();
  res.json(requested);
  requested = [];
});

function sendCode(i)
{
  var toPush;
  switch (i)
  {
    case "2": toPush = "000b8d"; break;
    case "3": toPush = "13bdf8"; break;
    case "4": toPush = "000b81"; break;
    case "5": toPush = "000611"; break;
    case "6": toPush = "000b65"; break;
    case "7": toPush = "000bbd"; break;
    default:
      return false;
  }
  if (toPush && requested.indexOf(toPush) == -1)
    requested.push(toPush);
  return true;
}

router.get("/", auth, (req, res) => {
  res.sendFile(path.resolve("index.html"));
});

app.listen(port);
console.log(`App Listening to port ${port}`);

function favicon()
{
  // curl "https://cdn.vectorstock.com/i/preview-1x/00/28/parking-square-symbol-icon-cartoon-vector-37420028.webp" -o icon.webp
  // base64 -w 0 icon.webp
  var f = "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";
  return Buffer.from(f, "base64");
}