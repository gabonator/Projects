'use strict';
const fs   = require('fs');
const path = require('path');
const { NexusModule, BLOCK_SIZE, SAMPLE_RATE, parseFxp, loadSections, nexusInit, renderBlock } = require('./nexuslib.js');

// ── Config ────────────────────────────────────────────────────────────────────
const CONTENT_ROOT = '/Users/gabrielvalky/Documents/git/CleanRoom/jsfun4/installer/Nexus Content';
const OUT_WAV      = path.join(__dirname, 'output.wav');
const FXP_PATH     = process.argv[2] || null;

// Note sequence [midiNote, sustainBlocks, releaseBlocks]
const SEQ = [
  [60, 18, 28],  // C4
  [64, 18, 28],  // E4
  [67, 18, 28],  // G4
  [72, 18, 56],  // C5 (long release)
];

// ── WASM globals (accessed from EM_ASM in kernel32.h) ────────────────────────
global.window              = global;
global.nexusFileCache      = [];
global.nexusDirCache       = {};
global.nexusFindHandles    = {};
global.nexusFindHandleNext = 0x200;

// Pre-scan Nexus Content for FindFirstFileA / FindNextFileA
(function scanDir(winPath, localPath) {
  try {
    const entries = fs.readdirSync(localPath, { withFileTypes: true })
      .filter(e => !e.name.startsWith('.'))
      .map(e => {
        const isDir = e.isDirectory();
        let size = 0;
        if (!isDir) try { size = fs.statSync(path.join(localPath, e.name)).size; } catch {}
        return { name: e.name, isDir, size };
      });
    global.nexusDirCache[winPath.toLowerCase()] = entries;
    entries.filter(e => e.isDir).forEach(e => scanDir(winPath + '/' + e.name, path.join(localPath, e.name)));
  } catch {}
})('C:/Nexus Content', CONTENT_ROOT);

// Mock XHR: redirects "Nexus Content/..." fetches to local filesystem
global.XMLHttpRequest = class {
  open(_method, url) { this._url = url; }
  set responseType(_v) {}
  send() {
    if (!this._url.startsWith('Nexus Content/')) {
      this.status = 404; this.response = null; return;
    }
    const localPath = path.join(CONTENT_ROOT, this._url.slice('Nexus Content/'.length));
    try {
      const buf     = fs.readFileSync(localPath);
      this.status   = 200;
      this.response = buf.buffer.slice(buf.byteOffset, buf.byteOffset + buf.byteLength);
    } catch {
      this.status = 404; this.response = null;
    }
  }
};

// ── WAV writer ────────────────────────────────────────────────────────────────
function writeWav(outPath, sampleRate, left, right) {
  const n   = left.length;
  const buf = Buffer.alloc(44 + n * 4);
  let o = 0;
  const w32 = v => { buf.writeUInt32LE(v, o); o += 4; };
  const w16 = v => { buf.writeUInt16LE(v, o); o += 2; };
  const str = s => { buf.write(s, o, 'ascii'); o += 4; };
  str('RIFF'); w32(36 + n * 4); str('WAVE');
  str('fmt '); w32(16); w16(1); w16(2);
  w32(sampleRate); w32(sampleRate * 4); w16(4); w16(16);
  str('data'); w32(n * 4);
  for (let i = 0; i < n; i++) {
    buf.writeInt16LE(Math.round(Math.max(-1, Math.min(1, left[i]))  * 32767), o); o += 2;
    buf.writeInt16LE(Math.round(Math.max(-1, Math.min(1, right[i])) * 32767), o); o += 2;
  }
  fs.writeFileSync(outPath, buf);
  console.log(`WAV written: ${outPath}  (${(n / sampleRate).toFixed(2)}s)`);
}

// ── Main ──────────────────────────────────────────────────────────────────────
async function main() {
  const M = await NexusModule({
    locateFile: f => path.join(__dirname, f),
    printErr:   msg => console.error('[wasm]', msg),
  });
  console.log(`WASM loaded  (${M.HEAPU8.byteLength >> 20} MB heap)`);

  await loadSections(M, name => fs.readFileSync(path.join(__dirname, 'res', name)));

  const chunk = FXP_PATH ? parseFxp(fs.readFileSync(FXP_PATH)) : null;
  if (FXP_PATH && !chunk) { console.error('Invalid FXP file'); process.exit(1); }
  nexusInit(M, chunk);
  if (chunk) console.log(`Preset: ${path.basename(FXP_PATH)}  (${chunk.length} bytes)`);

  const totalBlocks = SEQ.reduce((s, [, sus, rel]) => s + 1 + sus + rel, 0);
  const bufL = new Float32Array(totalBlocks * BLOCK_SIZE);
  const bufR = new Float32Array(totalBlocks * BLOCK_SIZE);

  let block = 0;
  for (const [note, sus, rel] of SEQ) {
    M._nexus_midi(0x90, note, 100);
    for (let b = 0; b < 1 + sus; b++) renderBlock(M, bufL, bufR, block++);
    M._nexus_midi(0x80, note, 0);
    for (let b = 0; b < rel; b++) renderBlock(M, bufL, bufR, block++);
  }

  let peakL = 0, peakR = 0;
  for (let i = 0; i < bufL.length; i++) {
    if (Math.abs(bufL[i]) > peakL) peakL = Math.abs(bufL[i]);
    if (Math.abs(bufR[i]) > peakR) peakR = Math.abs(bufR[i]);
  }
  console.log(`Peak  L=${peakL.toFixed(4)}  R=${peakR.toFixed(4)}${peakL < 1e-6 ? '  ⚠ silence' : ''}`);

  writeWav(OUT_WAV, SAMPLE_RATE, bufL, bufR);
}

main().catch(e => { console.error(e); process.exit(1); });
