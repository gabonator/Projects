    document.onkeydown = function(evt) {
        evt = evt || window.event;
        var con = true;
        switch (evt.keyCode)
        {
          case 38: curKeys |= 1; break; //memory[0x1228 * 16 + 0x4d44 + "H".charCodeAt(0)] = 1; break; // up
          case 39: curKeys |= 2; break; //memory[0x1228 * 16 + 0x4d44 + "M".charCodeAt(0)] = 1; break; // right
          case 40: curKeys |= 4; break; //memory[0x1228 * 16 + 0x4d44 + "P".charCodeAt(0)] = 1; break; // down
          case 37: curKeys |= 8; break; //memory[0x1228 * 16 + 0x4d44 + "K".charCodeAt(0)] = 1; break; // left
          case 32: curKeys |= 16; break; //memory[0x1228 * 16 + 0x4d44 + 0x1c] = 1; break; // space -> enter
          case 27: curKeys |= 32; break; //memory[0x1228 * 16 + 0x4d44 + 1] = 1; break; // esc
          default: con = false;
        }
        if (con) evt.preventDefault();
    }
    document.onkeyup = function(evt) {
        evt = evt || window.event;
        var con = true;
        switch (evt.keyCode)
        {
          case 38: curKeys &= ~1; break; //memory[0x1228 * 16 + 0x4d44 + "H".charCodeAt(0)] = 0; break; // up
          case 39: curKeys &= ~2; break; //memory[0x1228 * 16 + 0x4d44 + "M".charCodeAt(0)] = 0; break; // right
          case 40: curKeys &= ~4; break; //memory[0x1228 * 16 + 0x4d44 + "P".charCodeAt(0)] = 0; break; // down
          case 37: curKeys &= ~8; break; //memory[0x1228 * 16 + 0x4d44 + "K".charCodeAt(0)] = 0; break; // left
          case 32: curKeys &= ~16; break; //memory[0x1228 * 16 + 0x4d44 + 0x1c] = 0; break; // space -> enter
          case 27: curKeys &= ~32; break; //memory[0x1228 * 16 + 0x4d44 + 1] = 0; break; // esc
          default: con = false;
        }
        if (con) evt.preventDefault();
    }
