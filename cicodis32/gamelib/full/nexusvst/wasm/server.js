'use strict';
const http = require('http');
const fs   = require('fs');
const path = require('path');
const url  = require('url');

const PORT        = parseInt(process.argv[2]) || 3000;
const STATIC_ROOT = __dirname;                          // wasm/ — serves nexus.html, nexus.js, nexus.wasm, res/*
const CONTENT_ROOT = '/Users/gabrielvalky/Documents/git/CleanRoom/jsfun4/installer/Nexus Content';

const MIME = {
  '.html': 'text/html; charset=utf-8',
  '.js':   'application/javascript',
  '.wasm': 'application/wasm',
  '.bin':  'application/octet-stream',
  '.ndb':  'application/octet-stream',
  '.nxf':  'application/octet-stream',
  '.nsk':  'application/octet-stream',
  '.ned':  'application/octet-stream',
};

// Resolve a client-supplied path inside a sandbox root.
// Returns absolute path on success, null if it escapes the sandbox.
function sandboxResolve(root, relPath) {
  const abs = path.resolve(root, relPath.replace(/\\/g, '/'));
  return abs.startsWith(root + path.sep) || abs === root ? abs : null;
}

// Recursive directory listing → [{name, type:'file'|'dir', path, size?}]
function listDir(dir, relBase, recursive, cb) {
  fs.readdir(dir, { withFileTypes: true }, (err, entries) => {
    if (err) { cb(err); return; }
    const results = [];
    let pending = entries.length;
    if (!pending) { cb(null, results); return; }
    entries.forEach(ent => {
      const entRel  = relBase ? relBase + '/' + ent.name : ent.name;
      const entFull = path.join(dir, ent.name);
      if (ent.isDirectory()) {
        results.push({ name: ent.name, type: 'dir', path: entRel });
        if (recursive) {
          listDir(entFull, entRel, true, (err2, sub) => {
            if (!err2) results.push(...sub);
            if (--pending === 0) cb(null, results);
          });
        } else {
          if (--pending === 0) cb(null, results);
        }
      } else if (ent.isFile()) {
        fs.stat(entFull, (err2, st) => {
          results.push({ name: ent.name, type: 'file', path: entRel, size: st ? st.size : 0 });
          if (--pending === 0) cb(null, results);
        });
      } else {
        if (--pending === 0) cb(null, results);
      }
    });
  });
}

function send(res, status, contentType, body) {
  res.writeHead(status, {
    'Content-Type': contentType,
    'Access-Control-Allow-Origin': '*',
  });
  res.end(body);
}

http.createServer((req, res) => {
  const parsed   = url.parse(req.url, true);
  const pathname = parsed.pathname;

  // ── /file?path=<relative-to-Nexus-Content> ──────────────────────────────
  if (pathname === '/file') {
    const relPath = (parsed.query.path || '').replace(/\\/g, '/');
    if (!relPath) { send(res, 400, 'text/plain', 'missing path'); return; }

    const abs = sandboxResolve(CONTENT_ROOT, relPath);
    if (!abs) { send(res, 403, 'text/plain', 'forbidden'); return; }

    fs.readFile(abs, (err, data) => {
      if (err) { send(res, 404, 'text/plain', 'not found: ' + relPath); return; }
      const ext = path.extname(abs).toLowerCase();
      send(res, 200, MIME[ext] || 'application/octet-stream', data);
    });
    return;
  }

  // ── /api/list?path=<relative-to-Nexus-Content>[&recursive=1] ────────────
  if (pathname === '/api/list') {
    const relPath   = (parsed.query.path || '').replace(/\\/g, '/');
    const recursive = parsed.query.recursive === '1';

    // Empty path → list Nexus Content root itself
    const abs = relPath ? sandboxResolve(CONTENT_ROOT, relPath) : CONTENT_ROOT;
    if (!abs) { send(res, 403, 'text/plain', 'forbidden'); return; }

    listDir(abs, relPath, recursive, (err, entries) => {
      if (err) { send(res, 404, 'text/plain', 'not found: ' + relPath); return; }
      // Sort: dirs first, then files, both alphabetically
      entries.sort((a, b) => {
        if (a.type !== b.type) return a.type === 'dir' ? -1 : 1;
        return a.name.localeCompare(b.name);
      });
      send(res, 200, 'application/json', JSON.stringify(entries, null, 2));
    });
    return;
  }

  // ── Static files (nexus.html / nexus.js / nexus.wasm / res/*) ───────────
  const safePath = pathname === '/' ? '/nexus.html' : pathname;
  const abs = path.resolve(STATIC_ROOT, safePath.replace(/^\//, ''));
  if (!abs.startsWith(STATIC_ROOT)) { send(res, 403, 'text/plain', 'forbidden'); return; }

  fs.readFile(abs, (err, data) => {
    if (err) { send(res, 404, 'text/plain', 'not found'); return; }
    const ext = path.extname(abs).toLowerCase();
    send(res, 200, MIME[ext] || 'application/octet-stream', data);
  });

}).listen(PORT, () => {
  console.log(`Nexus server on http://localhost:${PORT}/nexus.html`);
  console.log(`  static  → ${STATIC_ROOT}`);
  console.log(`  content → ${CONTENT_ROOT}`);
  console.log(`  /file?path=Nexus%%20Content/Data.ndb`);
  console.log(`  /api/list?path=Presets&recursive=1`);
});
