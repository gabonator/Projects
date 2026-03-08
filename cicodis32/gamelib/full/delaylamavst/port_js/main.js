// Take this code only as inspiration, this is how another vst plugin was ported

function audioMasterHandler() {
  const opcode = stack32(1); // opcode is 2nd arg: [esp+4]
  console.log("audio master ", opcode)
  if (opcode === 1) r32[eax] = 2400; // audioMasterVersion → return VST 2.4
  else r32[eax] = 0;
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
  sub_10003560();
  r32[esp] += 4;

  let pluginPtr = r32[eax];  // sub_10003560 returns AEffect* directly (already +0x20 from C++ object)
  console.log('AEffect @ 0x' + pluginPtr.toString(16));

  const dispatcherPtr       = memoryAGet32(ds, pluginPtr + 0x04);  // AEffect.dispatcher
  const processReplacingPtr = memoryAGet32(ds, pluginPtr + 0x50);  // AEffect.processReplacing
  const thisPtr             = memoryAGet32(ds, pluginPtr + 0x40);  // AEffect.object (C++ this)
  console.log('C++ object @ 0x' + thisPtr.toString(16));
  console.log('dispatcher @ 0x' + dispatcherPtr.toString(16));
  console.log('processReplacing @ 0x' + processReplacingPtr.toString(16));


  // effSetProgram (opcode 2) — select preset index (0–31)
  const PRESET_INDEX = 1;
  push32(0); push32(0); push32(PRESET_INDEX); push32(0); push32(2); push32(pluginPtr);
  indirectCall(cs, dispatcherPtr); r32[esp] += 24;
  console.log('Program set to preset', PRESET_INDEX);

  // effSetSampleRate (opcode 10) — value passed as float in opt (arg4)
  function toFp32Bits(f) { const v = new DataView(new ArrayBuffer(4)); v.setFloat32(0, f, true); return v.getUint32(0, true); }
  const srFloat = toFp32Bits(SAMPLE_RATE);
  push32(srFloat); push32(0); push32(0); push32(0); push32(10); push32(pluginPtr);
  indirectCall(cs, dispatcherPtr); r32[esp] += 24;
  console.log('Set sample rate', SAMPLE_RATE);

  // effSetBlockSize (opcode 11) — value=BLOCK_SIZE as int in value (arg3)
  push32(0); push32(0); push32(BLOCK_SIZE); push32(0); push32(11); push32(pluginPtr);
  indirectCall(cs, dispatcherPtr); r32[esp] += 24;
  console.log('Set block size', BLOCK_SIZE);

  // effMainsChanged (opcode 12) — value=1 to activate
  push32(0); push32(0); push32(1); push32(0); push32(12); push32(pluginPtr);
  indirectCall(cs, dispatcherPtr); r32[esp] += 24;
  console.log('Plugin activated');

  const inL        = allocate(BLOCK_SIZE * 4);  // silent input channel L
  const inR        = allocate(BLOCK_SIZE * 4);  // silent input channel R
  const outL       = allocate(BLOCK_SIZE * 4);
  const outR       = allocate(BLOCK_SIZE * 4);
  const inputPtrs  = allocate(8);
  const outputPtrs = allocate(8);
  memoryASet32(ds, inputPtrs  + 0, inL);
  memoryASet32(ds, inputPtrs  + 4, inR);
  memoryASet32(ds, outputPtrs + 0, outL);
  memoryASet32(ds, outputPtrs + 4, outR);
  let midiEvents = []

  function loop()
  {
    processEvents(pluginPtr, dispatcherPtr, midiEvents);
    midiEvents = [];

    // processReplacing(AEffect*, inputs**, outputs**, sampleFrames)
    push32(BLOCK_SIZE);
    push32(outputPtrs);
    push32(inputPtrs);
    push32(pluginPtr);
    indirectCall(cs, processReplacingPtr);
    r32[esp] += 16;

    const left  = new Float32Array(BLOCK_SIZE);
    const right = new Float32Array(BLOCK_SIZE);
    for (let i = 0; i < BLOCK_SIZE; i++) {
        left[i]  = FromFp32(memoryAGet32(ds, outL + i * 4));
        right[i] = FromFp32(memoryAGet32(ds, outR + i * 4));
    }
    return { left, right };
  }

  // --- Run: note-on, 3 seconds of audio, note-off, 1 second tail ---
  const allLeft  = [];
  const allRight = [];
  const BLOCKS_ON   = Math.ceil(SAMPLE_RATE * 3 / BLOCK_SIZE);
  const BLOCKS_TAIL = Math.ceil(SAMPLE_RATE * 1 / BLOCK_SIZE);

  midiEvents.push({ status: 0x90, note: 60, velocity: 100 });
  for (let b = 0; b < BLOCKS_ON; b++) {
    const buf = loop();
    for (let i = 0; i < BLOCK_SIZE; i++) { allLeft.push(buf.left[i]); allRight.push(buf.right[i]); }
  }

  midiEvents.push({ status: 0x80, note: 60, velocity: 0 });
  for (let b = 0; b < BLOCKS_TAIL; b++) {
    const buf = loop();
    for (let i = 0; i < BLOCK_SIZE; i++) { allLeft.push(buf.left[i]); allRight.push(buf.right[i]); }
  }

  writeWav('output.wav', allLeft, allRight, SAMPLE_RATE);


function writeWav(filename, leftSamples, rightSamples, sampleRate) {
  const numSamples    = leftSamples.length;
  const numChannels   = 2;
  const bitsPerSample = 16;
  const dataSize      = numSamples * numChannels * (bitsPerSample / 8);
  const buf           = Buffer.alloc(44 + dataSize);
  let off = 0;

  buf.write('RIFF', off); off += 4;
  buf.writeUInt32LE(36 + dataSize, off); off += 4;
  buf.write('WAVE', off); off += 4;
  buf.write('fmt ', off); off += 4;
  buf.writeUInt32LE(16, off); off += 4;
  buf.writeUInt16LE(1, off); off += 2;   // PCM
  buf.writeUInt16LE(numChannels, off); off += 2;
  buf.writeUInt32LE(sampleRate, off); off += 4;
  buf.writeUInt32LE(sampleRate * numChannels * bitsPerSample / 8, off); off += 4;
  buf.writeUInt16LE(numChannels * bitsPerSample / 8, off); off += 2;
  buf.writeUInt16LE(bitsPerSample, off); off += 2;
  buf.write('data', off); off += 4;
  buf.writeUInt32LE(dataSize, off); off += 4;

  for (let i = 0; i < numSamples; i++) {
    const l = Math.max(-1, Math.min(1, leftSamples[i]));
    const r = Math.max(-1, Math.min(1, rightSamples[i]));
    buf.writeInt16LE(Math.round(l * 32767), off); off += 2;
    buf.writeInt16LE(Math.round(r * 32767), off); off += 2;
  }

  require('fs').writeFileSync(filename, buf);
  console.log(`WAV written: ${filename}  (${numSamples} samples, ${(numSamples/sampleRate).toFixed(2)}s)`);
}
