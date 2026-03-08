# Delay Lama vst reverse engineering

- porting done with claude sonnet, in interactive loop
  - cicodis is used for disassembly single method
  - append to delaylama.js
  - run `node run.js`
  - fix errors (add missing method, add indirect tables)
  - repeat

- `port_js` - DSP code ported to javascript, generates a WAV file as a response to MIDI press/release events
- `port_cpp` - complete rewrite of the DSP engine into clean code producing the same sound as ported code
