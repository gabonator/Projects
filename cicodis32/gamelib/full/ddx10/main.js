function audioMasterHandler() {
  const opcode = stack32(2);
  console.log("audio master ", opcode)
  r32[eax] = 0;
}

const vstEventsPtr = allocate(8 + 32 * 4);
const vstEventsDataPtr = allocate(32 * 32);

function processEvents(pluginPtr, dispatcherPtr, events) {
  if (!events || !events.length)
    return;
  //console.log(events);

  const numEvents = events.length;

  const ptrs = events.map((ev, i) => {
    const p = vstEventsDataPtr + i *32; //allocate(32);
    memoryASet32(ds, p + 0x00, 1);   // type = kVstMidiType
    memoryASet32(ds, p + 0x04, 32);  // byteSize
    memoryASet32(ds, p + 0x08, ev.deltaFrames || 0);
    memoryASet32(ds, p + 0x0c, 0);   // flags
    memoryASet32(ds, p + 0x10, 0);   // noteLength
    memoryASet32(ds, p + 0x14, 0);   // noteOffset
    // midiData[0..3] packed as little-endian uint32
    memoryASet32(ds, p + 0x18,
      (ev.status & 0xff) | ((ev.note & 0xff) << 8) | ((ev.velocity & 0xff) << 16));
    memoryASet32(ds, p + 0x1c, 0);
    return p;
  });

  memoryASet32(ds, vstEventsPtr + 0, numEvents);
  memoryASet32(ds, vstEventsPtr + 4, 0);
  ptrs.forEach((p, i) => memoryASet32(ds, vstEventsPtr + 8 + i * 4, p));

  // effProcessEvents = opcode 25
  push32(0); push32(vstEventsPtr); push32(0); push32(0); push32(25); push32(pluginPtr);
  indirectCall(cs, dispatcherPtr);
  r32[esp] += 24;
}

  init();

  const BLOCK_SIZE    = 1024*2;
  const SAMPLE_RATE   = 44100;

  const audioMasterPtr  = 0x77778888;
  const pluginStructPtr = allocate(0x1080);

  push32(audioMasterPtr);
  push32(pluginStructPtr);
  sub_10008b40();
  r32[esp] += 8;

  let pluginPtr = r32[eax] + 0x20;
  console.log('AEffect @ 0x' + pluginPtr.toString(16));

  const dispatcherPtr = memoryAGet32(ds, pluginPtr + 0x04);
  const thisPtr       = memoryAGet32(ds, pluginPtr + 0x40);
  console.log('C++ object @ 0x' + thisPtr.toString(16));


  // effSetProgram (opcode 2) — select preset index (0–31, see CLAUDE.md for full list)
  const PRESET_INDEX = 1; // 0 = Bright E.Piano
 // patch 8, 16 - infinite loop
  push32(0); push32(0); push32(PRESET_INDEX); push32(0); push32(2); push32(pluginPtr);
  indirectCall(cs, dispatcherPtr); r32[esp] += 24;
  console.log('Program set to preset', PRESET_INDEX);

  const outL       = allocate(BLOCK_SIZE * 4);
  const outR       = allocate(BLOCK_SIZE * 4);
  const inputPtrs  = allocate(4);
  const outputPtrs = allocate(8);
  memoryASet32(ds, outputPtrs + 0, outL);
  memoryASet32(ds, outputPtrs + 4, outR);
  let midiEvents = []

  function loop()
  {
    processEvents(pluginPtr, dispatcherPtr, midiEvents);
    midiEvents = [];

    // processReplacing
    push32(BLOCK_SIZE);
    push32(outputPtrs);
    push32(inputPtrs);
    push32(pluginPtr);
    sub_10010750();
    r32[esp] += 16;

    //
    const buffer = audioContext.createBuffer(2, BLOCK_SIZE, SAMPLE_RATE);
    const left = buffer.getChannelData(0);
    const right = buffer.getChannelData(1);

    for (let i = 0; i < BLOCK_SIZE; i++) {
        left[i] = FromFp32(memoryAGet32(ds, outL + i * 4));
        right[i] = FromFp32(memoryAGet32(ds, outR + i * 4));
    }

    return buffer;
  }


let audioContext;
let nextTime = 0;

function scheduleBuffer() {
    const buffer = loop();
    const source = audioContext.createBufferSource();
    source.buffer = buffer;
    source.connect(audioContext.destination);
    source.start(nextTime);
    nextTime += BLOCK_SIZE / SAMPLE_RATE;
}

async function playStart() {
    audioContext = new AudioContext({ SAMPLE_RATE });
    await audioContext.resume();

    nextTime = audioContext.currentTime;
    // schedule 3 buffers ahead to avoid gaps
    schedulerInterval = setInterval(() => {
      while (nextTime < audioContext.currentTime + 0.1) {
        scheduleBuffer();
      }
    }, 10); // run every 10 ms
}

// Map QWERTY keys to MIDI notes (C4=60, D4=62, etc.)
const keyMap = {
  'A': 60, // C
  'W': 61, // C#
  'S': 62, // D
  'E': 63, // D#
  'D': 64, // E
  'F': 65, // F
  'T': 66, // F#
  'G': 67, // G
  'Y': 68, // G#
  'H': 69, // A
  'U': 70, // A#
  'J': 71, // B
  'K': 72  // C5
};

let activeKeys = {}; // Track which keys are currently down
let first = true;

//document.onkeydown = evt => handleKey(evt.key.toUpperCase(), 1);
//document.onkeyup = evt => handleKey(evt.key.toUpperCase(), 0);

async function handleKey(key, pressed) {
  if (first) {
    first = false;
    playStart();
  }

  const midiNote = keyMap[key];
  if (!midiNote) return; // Ignore keys not mapped

  // Prevent repeat firing if key is already pressed
  if (activeKeys[key] === pressed) return;
  activeKeys[key] = pressed;

  if (pressed) {
    midiEvents.push({ status: 0x90, note: midiNote, velocity: 100 }); // Note on
  } else {
    midiEvents.push({ status: 0x80, note: midiNote, velocity: 0 });   // Note off
  }
}

// gui: call editor->open(hwnd) via effEditOpen vtable[3] = sub_10001b10
// ecx = editor object (at thisPtr+8), push hwnd=0 as the host window arg
const editorPtr = memoryAGet32(ds, thisPtr + 8);
r32[ecx] = editorPtr;
push32(0); // hwnd (stub, no real window)
sub_10001b10();
// sub_10001b10 is __thiscall+1 arg, pops its own arg (stackDrop4)

// Walk the VSTGUI widget tree and render to SVG
{
  const framePtr = memoryAGet32(ds, editorPtr + 0x10);
  const childCount = memoryAGet32(ds, framePtr + 0x100);

  const VTABLE_NAME = {
    0x1003f864: 'TooltipKnob',
    0x1003fb5c: 'TooltipDisplay',
    0x10040c74: 'CSplashScreen',
    0x1003e89c: 'TextLabel',
    0x1003ea0c: 'TextEdit',
    0x1003eb8c: 'OptionMenu',
    0x1003f9f4: 'TooltipSlider',
    0x10040084: 'CParamDisplay',
    0x1003ff24: 'CControl',
    0x10040b2c: 'CKickButton',
  };
  const FILL = {
    TooltipKnob:    '#4488ff',
    TooltipDisplay: '#ffcc44',
    CSplashScreen:  '#44cc88',
    TextLabel:      '#eeeeee',
    TextEdit:       '#ffffff',
    OptionMenu:     '#ddbbff',
    TooltipSlider:  '#ff8844',
    CParamDisplay:  '#ccaaff',
    CControl:       '#aaccff',
    CKickButton:    '#ff4466',
  };

  // Read current preset name and float parameters from plugin memory
  const presetBank    = memoryAGet32(ds, thisPtr + 0xb0);
  const currentProg   = memoryAGet32(ds, thisPtr + 0x1c);
  const presetBase    = presetBank + 0x60 * currentProg;
  const presetNamePtr = presetBase + 0x44;
  const presetName    = readstring(presetNamePtr);
  // 12 slider params at +0x00..+0x2c, 5 knob params at +0x30..+0x40
  const presetFloats  = [];
  for (let i = 0; i <= 16; i++)
    presetFloats.push(FromFp32(memoryAGet32(ds, presetBase + i * 4)));

  const widgets = [];
  for (let i = 0; i < childCount; i++) {
    const ptr    = memoryAGet32(ds, framePtr + 0x104 + i * 4);
    const vtbl   = memoryAGet32(ds, ptr);
    const left   = memoryAGet32(ds, ptr + 0x08);
    const top    = memoryAGet32(ds, ptr + 0x0c);
    const right  = memoryAGet32(ds, ptr + 0x10);
    const bottom = memoryAGet32(ds, ptr + 0x14);
    const type   = VTABLE_NAME[vtbl] || ('vtbl:0x' + vtbl.toString(16));
    widgets.push({ ptr, type, left, top, right, bottom });
  }

  // compute canvas bounds from widget extents
  //let maxX = 0, maxY = 0;
  //for (const w of widgets) { maxX = Math.max(maxX, w.right); maxY = Math.max(maxY, w.bottom); }
  const W = 856, H = 392;

  // resolve background image if available
  const IMG_DIR = 'res';
  function imgPath(name) { return `${IMG_DIR}/${name.toUpperCase()}.png`; }
  function imgExists(p) { try { fs.accessSync(p); return true; } catch(e) { return false; } }

  let svg = `<svg xmlns="http://www.w3.org/2000/svg" width="${W}" height="${H}">\n`;
  svg += `  <rect width="${W}" height="${H}" fill="#333"/>\n`;

  // background image (first bitmap loaded = Background)
  const bgNames = Object.values(bitmapFiles);
  if (bgNames.length > 0) {
    const p = imgPath(bgNames[0]);
    if (imgExists(p))
      svg += `  <image href="${p}" x="0" y="0" width="${W}" height="${H}"/>\n`;
  }

  const WIDGET_IMG   = { CSplashScreen: 'Splashscreen', TooltipKnob: 'Knob', TooltipSlider: 'SliderBack' };
  const SPRITE_FRAMES = { TooltipKnob: { total: 101, frameH: 64 } };
  // preset float indices: sliders 0..11 → presetFloats[0..11], knobs 0..4 → presetFloats[12..16]
  let sliderIdx = 0, knobIdx = 0;

  for (const w of widgets) {
    const fill = FILL[w.type] || '#aaaaaa';
    const x = w.left, y = w.top, ww = w.right - w.left, hh = w.bottom - w.top;
    const wimp = imgPath(WIDGET_IMG[w.type] || w.type.replace('Tooltip', ''));
    if (imgExists(wimp)) {
      const sprite = SPRITE_FRAMES[w.type];
      if (sprite) {
        // Knob sprite sheet: frame from preset float
        const val = presetFloats[12 + knobIdx] || 0;
        const frameIndex = Math.round(Math.max(0, Math.min(1, val)) * (sprite.total - 1));
        knobIdx++;
        const vy = frameIndex * sprite.frameH;
        const fullH = sprite.total * sprite.frameH;
        svg += `  <svg x="${x}" y="${y}" width="${ww}" height="${hh}" viewBox="0 ${vy} ${ww} ${hh}" overflow="hidden">\n`;
        svg += `    <image href="${wimp}" x="0" y="0" width="${ww}" height="${fullH}"/>\n`;
        svg += `  </svg>\n`;
      } else if (w.type === 'TooltipSlider') {
        // Slider: handle travels 112px based on preset float value
        const val = presetFloats[sliderIdx] || 0;
        sliderIdx++;
        const handleImg = imgPath('SliderHandle');
        const handleH = 16;
        const handleY = y + Math.round((1 - Math.max(0, Math.min(1, val))) * 112);
        svg += `  <image href="${wimp}" x="${x}" y="${y}" width="${ww}" height="${hh}"/>\n`;
        if (imgExists(handleImg))
          svg += `  <image href="${handleImg}" x="${x}" y="${handleY}" width="${ww}" height="${handleH}"/>\n`;
      } else {
        svg += `  <image href="${wimp}" x="${x}" y="${y}" width="${ww}" height="${hh}"/>\n`;
      }
    } else {
      svg += `  <rect x="${x}" y="${y}" width="${ww}" height="${hh}" fill="${fill}" stroke="#000" stroke-width="1" opacity="0.85"/>\n`;
    }
    const label = w.type === 'TextEdit' ? presetName : w.type;
    svg += `  <text x="${x + ww/2}" y="${y + hh/2}" text-anchor="middle" dominant-baseline="middle" font-family="monospace" font-size="9" fill="#000">${label}</text>\n`;
  }
  svg += `</svg>\n`;

  fs.writeFileSync('gui_layout.svg', svg);
  console.log(`gui_layout.svg: ${childCount} widgets, canvas ${W}x${H}`);
  for (const w of widgets)
    console.log(`  ${w.type.padEnd(20)} (${w.left},${w.top})-(${w.right},${w.bottom})`);
}
