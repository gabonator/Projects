const alleg40helper = {
  vtable: null,
  getVtable: () => {
    if (this.vtable)
      return this.vtable;
    const ptrVtable = cico.alloc(50*4);
    memoryASet32(0, ptrVtable, 8); // bit_depth
    memoryASet32(0, ptrVtable+0x44, 0x6ab10003); // draw_256_sprite
    memoryASet32(0, ptrVtable+0x4c, 0x6ab1000c); // draw_256_sprite_hflip
    memoryASet32(0, ptrVtable+0xa0, 0x6ab10004); // pivot_scaled_sprite_flip
    memoryASet32(0, ptrVtable+0x34, 0x6ab10005); // line
    memoryASet32(0, ptrVtable+0x38, 0x6ab10006); // rectfill
    memoryASet32(0, ptrVtable+0x10, 0x6ab10007); // acquire
    memoryASet32(0, ptrVtable+0x14, 0x6ab10008); // release
    memoryASet32(0, ptrVtable+0x8, 0x6ab1000a); // unwrite bank
    this.vtable = ptrVtable;
    return ptrVtable;
  },
  bitmapUid: 0x6a000000,
  bitmaps: {},
  buildBitmapUid(w, h)
  {
    this.bitmaps[this.bitmapUid] = {w:w, h:h, canvas:new OffscreenCanvas(w, h)};
    return this.bitmapUid++;
  },
  setPixels: (uid, pix) =>
  {
    let bmp = alleg40helper.bitmaps[uid];
    let pixels = new Uint8ClampedArray(bmp.w * bmp.h * 4);
    let pal = alleg40helper.palette;
    for (let i=0; i<bmp.w*bmp.h; i++)
    {
      let ind = pix[i];
      pixels[i*4] = pal[ind*4+0];
      pixels[i*4+1] = pal[ind*4+1];
      pixels[i*4+2] = pal[ind*4+2];
      pixels[i*4+3] = ind != 0 ? 255 : 0;
    }
    let image = new ImageData(pixels, bmp.w, bmp.h);
    alleg40helper.bitmaps[uid].canvas.getContext("2d").putImageData(image, 0, 0);
  },
  blit: (uidSource, uidDest, srcx, srcy, dstx, dsty, w, h) =>
  {
    let src = alleg40helper.bitmaps[uidSource];
    let dest = alleg40helper.bitmaps[uidDest];
//    dest.canvas.getContext("2d").drawImage(src.canvas, dstx, dsty);
    dest.canvas.getContext("2d").drawImage(
      src.canvas,
      srcx, srcy, w, h,   // source rectangle
      dstx, dsty, w, h    // destination rectangle
    );
  },
  drawSprite: (uidDest, uidSource, x, y) => 
  {
    let src = alleg40helper.bitmaps[uidSource];
    let dest = alleg40helper.bitmaps[uidDest];
    dest.canvas.getContext("2d").drawImage(src.canvas, x, y);
  },
  stretchSprite: (uidDest, uidSource, x, y, w, h, flipX = false, flipY = false) =>
  {
    const src  = alleg40helper.bitmaps[uidSource];
    const dest = alleg40helper.bitmaps[uidDest];
    const ctx  = dest.canvas.getContext("2d");
    w = w || src.canvas.width;
    h = h || src.canvas.height;
    ctx.save();
    ctx.translate(x, y);
    ctx.scale(flipX ? -1 : 1, flipY ? -1 : 1);
    const drawX = flipX ? -w : 0;
    const drawY = flipY ? -h : 0;
    ctx.drawImage(src.canvas, drawX, drawY, w, h);
    ctx.restore();
  },
  fontUid: 0x6b000000,
  fonts: {},
  buildFontUid: () =>
  {
    alleg40helper.fonts[alleg40helper.fontUid] = {height:0, chars:{}}
    return alleg40helper.fontUid++;
  },
  setFontCharacter: (uid, ch, w, h, pix) => {
    let font = alleg40helper.fonts[uid];
    font.height = Math.max(font.height, h);

    let pixels = new Uint8ClampedArray(w * h * 4);
    let pal = alleg40helper.palette;
    for (let i=0; i<w*h; i++)
    {
      let ind = pix[i];
      pixels[i*4] = pal[ind*4+0];
      pixels[i*4+1] = pal[ind*4+1];
      pixels[i*4+2] = pal[ind*4+2];
      pixels[i*4+3] = ind != 0 ? 255 : 0;
    }
    const image = new ImageData(pixels, w, h);
    let canvas = new OffscreenCanvas(w, h);
    font.chars[ch] = canvas;
    canvas.getContext("2d").putImageData(image, 0, 0);
  },
  getFontHeight: (uid) => {
    let font = alleg40helper.fonts[uid];
    return font.height;
  },
  getFontWidth: (uid, text) => {
    let font = alleg40helper.fonts[uid];
    let w = 0;
    for (let i=0; i<text.length; i++)
      w += font.chars[text.charCodeAt(i)].width;
    return w;  
  },
  textout: (uidBmp, uidFont, text, x, y, color, align) => {
    let bitmap = alleg40helper.bitmaps[uidBmp];
    let font = alleg40helper.fonts[uidFont];
    let width = alleg40helper.getFontWidth(uidFont, text);
    if (align == "c")
      x = x - width/2;
    else if (align == "r")
      x = x - width;

    for (let i=0; i<text.length; i++)
    {
      const canvas = font.chars[text.charCodeAt(i)];
      if (color == -1)
        bitmap.canvas.getContext("2d").drawImage(canvas, x, y);
      else {
        const off = document.createElement("canvas");
        off.width = canvas.width;
        off.height = canvas.height;

        const octx = off.getContext("2d");

        octx.drawImage(canvas, 0, 0);
        octx.globalCompositeOperation = "source-in";
        octx.fillStyle = alleg40helper.htmlColor(color);
        octx.fillRect(0, 0, off.width, off.height);
        bitmap.canvas.getContext("2d").drawImage(off, x, y);
      }
      x += canvas.width;
    }
  },
  htmlColor: (index) => {
    let pal = alleg40helper.palette;
    return `rgb(${pal[index*4]}, ${pal[index*4+1]}, ${pal[index*4+2]})`;
  },
  sampleUid: 0x65000000,
  samples: {},
  buildSampleUid: () =>
  {
    alleg40helper.samples[alleg40helper.sampleUid] = {}
    return alleg40helper.sampleUid++;
  },
  setSample: (uid, f, data) => {
    alleg40helper.samples[uid] = {freq:f, data:data};
  },
  audioCtx: new window.AudioContext(),
  playSample: (uid, loop) => {
    let sample = alleg40helper.samples[uid];
    const audioBuffer = alleg40helper.audioCtx.createBuffer(1, sample.data.length/2, sample.freq);
    const floatData = audioBuffer.getChannelData(0);

    for (let i = 0; i < sample.data.length/2; i++)
      floatData[i] = (sample.data[i*2]+sample.data[i*2+1]*256)/32768-1;

    const source = alleg40helper.audioCtx.createBufferSource();
    source.loop = loop;
    source.buffer = audioBuffer;
    source.connect(alleg40helper.audioCtx.destination);
    source.start();
    sample.source = source;
  },
  stopSample: (uid) => {
    let sample = alleg40helper.samples[uid];
    sample.source.stop();
  },
  palette: (() => { var code="AAAAABAQEAAgICAAMDAwAERERABUVFQAZGRkAHR0dACIiIgAmJiYAKioqAC4uLgAzMzMANzc3ADs7OwA/Pz8AAAAAAAMDBQAGBgsACQkQAA0NFQARERkAFRUdABkZIQAdHSYAISEqACYmLgAqKjIALi43ADIyOwA2Nj8AOjo/AAkRGwAPGioAMR8WAD8pHQAlIAAAMS4cABERBgAbGgkAACcGAAA1CQAlFg8AFw0JAAA/PwAAPz8AAD8/AAA/PwALAAAAFQ0IACEWCgAlHA8AIQAAADAAAAA/AAAAPxsXAD82LgAYCQAAKxkAAD8pAAA/NAAAPz8AAD8/KwA/Pz8AAAAAAAMDBQAGBgsACQkQAA0NFQARERkAFRUdABkZIQAdHSYAISEqACYmLgAqKjIALi43ADIyOwA2Nj8APz8/ABIGEQAbCRkAKg8nAAAAGQAKCiIAFRUsACAfNgArKj8AAD8/AAA/PwAAPz8AAD8/AAA/PwAAPz8AAD8/AAA/PwAAPz8AAD8/AAA/PwAYGBgAHBwcACAgIAAkJCQAIR8fAB4ZGgAbFBUAGQ8QABYKCwAZCQsAHQkLACAJCwAkCAsAAD8/AAA/PwAAPz8AAD8/AAA/PwAAPz8AAD8/AAA/PwAAPz8AAD8/AAA/PwAAPz8AAD8/AAA/PwAAPz8AAD8/AAA/PwAAPz8AAD8/AAA/PwAAPz8AAD8/AAA/PwAAPz8AAD8/AAA/PwAAPz8AAD8/AAA/PwAAPz8AAD8/AAA/PwAAPz8AAD8/AAA/PwAAPz8AAD8/AAA/PwAAPz8AAD8/AAA/PwAAPz8AAD8/AAA/PwAAPz8AAD8/AAA/PwAAPz8AAD8/AAA/PwAAPz8AAD8/AAA/PwAAPz8AAD8/AAA/PwAAPz8AAD8/AAA/PwAAPz8AAD8/AAA/PwAAPz8AAD8/AAA/PwAAPz8AAD8/AAA/PwAAPz8AAD8/AAA/PwAAPz8AAD8/AAA/PwAAPz8AAD8/AAA/PwAAPz8AAD8/AAA/PwAAPz8AAD8/AAA/PwAAPz8AAD8/AAA/PwAAPz8AAD8/AAA/PwAAPz8AAD8/AAA/PwAAPz8AAD8/AAA/PwAAPz8AAD8/AAA/PwAAPz8AAD8/AAA/PwAAPz8AAD8/AAA/PwAAPz8AAD8/AAA/PwAAPz8AAD8/AAA/PwAAPz8AAD8/AD8AAAA/FQAAPyoAAD8/AAAqPwAAFT8AAAA/AAAAMwwAACYZAAAZJgAADDMAAAA/AA8APwAfAD8ALwA/AD8APwAAPz8AAD8/AAA/PwAAPz8AAD8/AAA/PwAAPz8AAD8/AAA/PwAAPz8AAD8/AAA/PwAAPz8AAD8/AAAUPwAAKgcAA=="; return Uint8Array.from(atob(code), c => c.charCodeAt(0));})()
}

const alleg40 = {
//  ptrDefaultFont: null,
  init: () => {
    const ptrBlackPalette = cico.alloc(1024);
    memoryASet32(ds, 0x40d0e8, ptrBlackPalette);

    const TABLE_SIZE = 512;
    const FIXED_SHIFT = 16;
    const ptrCosTable = cico.alloc(512 * 4);
    memoryASet32(ds, 0x40d114, ptrCosTable);

    for (let i = 0; i < TABLE_SIZE; i++) {
      const angle = 2.0 * Math.PI * i / TABLE_SIZE;
      const c = Math.cos(angle);
      const cosFixed = ((c * (1 << FIXED_SHIFT)) + 0.5) | 0;
      memoryASet32(ds, ptrCosTable + (i << 2), cosFixed);
    }

    const ptrLightMap = cico.alloc(4);
    memoryASet32(ds, 0x40d0dc, ptrLightMap);

    const ptrScreen = alleg40.create_bitmap(640, 480);
    const ptrptrScreen = cico.alloc(4);
    memoryASet32(ds, ptrptrScreen, ptrScreen);
    memoryASet32(ds, 0x40d108, ptrptrScreen);

    const ptrJoystick = cico.alloc(128);
    memoryASet32(ds, 0x40d1a0, ptrJoystick);

    const ptrAllegKeys = cico.alloc(256);
    memoryASet32(ds, 0x40d1a4, ptrAllegKeys);

    const ptrptrFont = cico.alloc(4);
    const ptrFont = cico.alloc(4);
    memoryASet32(ds, ptrFont, 0x6b000000); // first font
    memoryASet32(ds, 0x40d0d4, ptrptrFont);
    memoryASet32(ds, ptrptrFont, ptrFont);
    alleg40.ptrDefaultFont = ptrFont;
    
    memoryASet32(ds, 0x42bbc0, 1);
  },
  _WinMain: function*() { return yield* sub_404d90(); },
  install_allegro: () => 1,
  install_keyboard: () => 1,
  install_timer: () => 1,
  install_int: () => 1,
  install_sound: () => 1,
  install_joystick: () => 1,
  create_bitmap: (w, h) => {
    const ptr = cico.alloc(128);
    const vtable = 0;	
    memoryASet32(0, ptr+0, w);
    memoryASet32(0, ptr+4, h);
    memoryASet32(0, ptr+8, alleg40helper.buildBitmapUid(w, h));
    memoryASet32(0, ptr + 7*4, alleg40helper.getVtable());
    memoryASet32(0, ptr + 8*4, 0x6ab1000b); // write_bank
    memoryASet32(0, ptr + 9*4, 0x6ab10009); // read_bank
    console.log("create bitmap", w, h);
    return ptr;
  },
  allegro_message: (ptrMsg) => console.log(cico.readString(ptrMsg)),
  allegro_exit: () => { throw "allegro wants to exit"; },
  load_datafile: (ptrFilename) => {
    const filename = cico.readString(ptrFilename);
    let data = archive[filename.split("data/").join("")];
    if (!data)
      return null;
    data = decompressLZSS(data)
    let datafile = loadAllegroDatafile(data);
    let ptrResult = cico.alloc(4*4*datafile.length);
    for (let i=0; i<datafile.length; i++)
    {
      let ptrPayload = null;
      const res = datafile[i];
      switch (res.type)
      {
        case "PAL":
          ptrPayload = cico.alloc(1024);
          for (let i=0; i<1024; i++)
            memoryASet(0, ptrPayload+i, res.payload[i]);
          break;
        case "BMP":
          let w = res.payload[2]*256 + res.payload[3];
          let h = res.payload[4]*256 + res.payload[5];
          ptrPayload = alleg40.create_bitmap(w, h);
          alleg40helper.setPixels(memoryAGet32(0, ptrPayload+8), res.payload.subarray(6))
          break;
        case "FONT":
          ptrPayload = cico.alloc(4);
          const uid = alleg40helper.buildFontUid();
          memoryASet32(0, ptrPayload, uid);
          const mono = res.payload[4];
          const begin = res.payload[5]*256*256*256 + res.payload[6]*256*256 + res.payload[7]*256 + res.payload[8];
          const end = res.payload[9]*256*256*256 + res.payload[10]*256*256 + res.payload[11]*256 + res.payload[12];
          let pos = 13;

          for (let c = begin; c < end; c++)
          {
              let pixels = [];
              const w = res.payload[pos]*256 + res.payload[pos+1];
              const h = res.payload[pos+2]*256 + res.payload[pos+3];
              pos += 4;

              if (mono)
              {
                for (var y=0; y<h; y++)
                {
                  for (var x=0; x<w; x++)
                    pixels.push(res.payload[pos+(x>>3)] & (128>>(x&7)) ? 15 : 0);
                  pos += (w + 7) >> 3;
                }
              } else {
                for (var y=0; y<h; y++)
                  for (var x=0; x<w; x++)
                    pixels.push(res.payload[pos++]);
              }
              alleg40helper.setFontCharacter(uid, c, w, h, pixels);
          }
          break;
        case "SAMP":
          const len = res.payload[4]*256*256*256 + res.payload[5]*256*256 + res.payload[6]*256 + res.payload[7];
          const freq = res.payload[2]*256 + res.payload[3];
          const uids = alleg40helper.buildSampleUid();
          ptrPayload = cico.alloc(4);
          memoryASet32(0, ptrPayload, uids);
          alleg40helper.setSample(uids, freq, res.payload.subarray(8));
          break;

        default:
          throw "unsupported type"
      }
      memoryASet32(0, ptrResult+i*4*4, ptrPayload);
      memoryASet32(0, ptrResult+i*4*4+4, 0x6ab07777);
      memoryASet32(0, ptrResult+i*4*4+8, res.payload.size);
      memoryASet32(0, ptrResult+i*4*4+12, 0);
    }
    return ptrResult;
  },
  pack_fopen: (ptrFilename) => 0,
  currentPalette: [],
  create_rgb_table(ptrTable, ptrPal, callback) {
    for (let i=0; i<256; i++)
        alleg40.currentPalette[i] = {
          r: memoryAGet(0, ptrPal+i*3)*4,
          g: memoryAGet(0, ptrPal+i*3+1)*4,
          b: memoryAGet(0, ptrPal+i*3+2)*4};

  },
  create_light_table: (ptrTable, ptrPal, r, g, b, callback) => 0,
  set_color_depth: () => 0,
  set_gfx_mode: () => 0,
  set_palette: (ptrPal) => {
    for (let i=0; i<256; i++)
        alleg40.currentPalette[i] = {
          r: memoryAGet(0, ptrPal+i*3)*4,
          g: memoryAGet(0, ptrPal+i*3+1)*4,
          b: memoryAGet(0, ptrPal+i*3+2)*4};
  },
  exists: (name) => {
    console.log("exists?", cico.readString(name))
    return 0;
  },
  set_display_switch_mode: () => 0,
  text_mode: () => 0,
  text_height: (ptrFont) => alleg40helper.getFontHeight(memoryAGet32(0, ptrFont)),
  text_length: (ptrFont, ptrText) => alleg40helper.getFontWidth(memoryAGet32(0, ptrFont), cico.readString(ptrText)),
  blit: (ptrSource, ptrDest, srcx, srcy, dstx, dsty, w, h) =>
  {
    alleg40helper.blit(memoryAGet32(0, ptrSource+8), memoryAGet32(0, ptrDest+8), srcx, srcy, dstx, dsty, w, h);
  },
  textout: (ptrBmp, ptrFont, ptrText, x, y, color) => {
    const text = cico.readString(ptrText);
    alleg40helper.textout(memoryAGet32(0, ptrBmp+8), memoryAGet32(0, ptrFont), text, x, y, color, "l");
  },
  textprintf: (ptrBmp, ptrFont, x, y, color, ptrFmt) => {
    const text = alleg40.sprintf(cico.readString(ptrFmt), 6);
    alleg40helper.textout(memoryAGet32(0, ptrBmp+8), memoryAGet32(0, ptrFont), text, x, y, color, "l");
  },
  textprintf_right: (ptrBmp, ptrFont, x, y, color, ptrFmt) => {
    const text = alleg40.sprintf(cico.readString(ptrFmt), 6);
    alleg40helper.textout(memoryAGet32(0, ptrBmp+8), memoryAGet32(0, ptrFont), text, x, y, color, "r");
  },
  sprintf: (fmt, index) => {
    let aux = ""
    for (let i=0; i<fmt.length; i++)
    {
      if (fmt[i] != "%")
      {
        aux += fmt[i];
        continue;
      }
      switch (fmt[++i])
      {
        case "d":
          aux += stack32(index++).toString();
          break;
        case "s":
          aux += cico.readString(stack32(index++));
          break;
        default:
          throw "bad format"
      }
    }
    return aux;
  },
  drawing_mode: () => 0,
  set_clip: () => 0,
  solid_mode: () => 0,
  fade_in: () => 0,
  fade_out: () => 0,
  poll_joystick: () => 0,
  masked_blit: (ptrSource, ptrDest, srcx, srcy, dstx, dsty, w, h) => {
    alleg40helper.blit(memoryAGet32(0, ptrSource+8), memoryAGet32(0, ptrDest+8), srcx, srcy, dstx, dsty, w, h);
  },
  get_palette_range: () => 0,
  set_palette_range: () => 0,
  vtable_draw_256_sprite: (ptrBmp, ptrSprite, x, y) => {
    alleg40helper.drawSprite(memoryAGet32(0, ptrBmp+8), memoryAGet32(0, ptrSprite+8), x, y);
  },
  vtable_draw_256_sprite_hflip: (ptrBmp, ptrSprite, x, y) => {
    alleg40helper.stretchSprite(memoryAGet32(0, ptrBmp+8), memoryAGet32(0, ptrSprite+8), x, y, 0, 0, true, false);
  },
  pivot_scaled_sprite_flip: (ptrBmp, ptrSprite, fixedX, fixedY, fixedCX, fixedCY, fixedAngle, fixedScale, v_flip) => {
    const dest = alleg40helper.bitmaps[memoryAGet32(0, ptrBmp + 8)];
    const ctx = dest.canvas.getContext("2d");
    const x     = fixedX/65536;
    const y     = fixedY/65536;
    const cx    = fixedCX/65536;
    const cy    = fixedCY/65536;
    const angle = fixedAngle/65536 * Math.PI / 180;
    const scale = fixedScale/65536;

    ctx.save();
    ctx.translate(x, y);
    ctx.rotate(angle);
    const scaleY = v_flip ? -scale : scale;
    ctx.scale(scale, scaleY);
    alleg40helper.drawSprite(memoryAGet32(0, ptrBmp+8), memoryAGet32(0, ptrSprite+8), -cx, -cy);
    ctx.restore();
  },
  vtable_line: (ptrBmp, x1, y1, x2, y2, c) => {
    let src = alleg40helper.bitmaps[memoryAGet32(0, ptrBmp+8)];
    let ctx = src.canvas.getContext("2d");
    ctx.strokeStyle = alleg40helper.htmlColor(c);
    ctx.lineWidth = 1;
    ctx.beginPath();
    ctx.moveTo(x1, y1);
    ctx.lineTo(x2, y2);
    ctx.stroke();
  },
  vtable_rectfill: (ptrBmp, x1, y1, x2, y2, c) => {
    let src = alleg40helper.bitmaps[memoryAGet32(0, ptrBmp+8)];
    let ctx = src.canvas.getContext("2d");
    ctx.fillStyle = typeof(c) == "string" ? c : alleg40helper.htmlColor(c);
    ctx.fillRect(x1, y1, x2-x1, y2-y1);
  },
  vtable_acquire: (ptrBmp) => 0,
  vtable_release: (ptrBmp) => {
    let src = alleg40helper.bitmaps[memoryAGet32(0, ptrBmp+8)];
    mainScreenCtx.drawImage(src.canvas, 0, 0);
  },
  stop_sample: () => 0,
  stretch_sprite: (ptrBmp, ptrSprite, x, y, w, h) => {
    alleg40helper.stretchSprite(memoryAGet32(0, ptrBmp+8), memoryAGet32(0, ptrSprite+8), x, y, w, h);
  },
  textprintf_centre: (ptrBmp, ptrFont, x, y, color, ptrFmt) => {
    const text = alleg40.sprintf(cico.readString(ptrFmt), 6);
    alleg40helper.textout(memoryAGet32(0, ptrBmp+8), memoryAGet32(0, ptrFont), text, x, y, color, "c");
  },
  textout_centre: (ptrBmp, ptrFont, ptrText, x, y, color) => {
    const text = cico.readString(ptrText);
    alleg40helper.textout(memoryAGet32(0, ptrBmp+8), memoryAGet32(0, ptrFont), text, x, y, color, "c");
  },
  play_sample: (ptrSample, vol, pan, freq, loop) => {
    //console.log("samplePlay", memoryAGet32(0, ptrSample) & 0xff, vol, pan, freq, loop);
    alleg40helper.playSample(memoryAGet32(0, ptrSample), 0);
  },
  adjust_sample: (ptrSample, vol, pan, freq, loop) => {
//    console.log("sampleAdjust", memoryAGet32(0, ptrSample) & 0xff, vol, pan, freq, loop);
//    alleg40helper.stopSample(memoryAGet32(0, ptrSample))
  }
}
