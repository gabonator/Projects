void sub_24B90()
{
    WORD _cs = _seg002;
  _flags.interrupt = true;                         //sti
  _push(_bx);                                     //push bx
  _push(_cx);                                     //push cx
  _push(_dx);                                     //push dx
  _push(_si);                                     //push si
  _push(_di);                                     //push di
  _push(_ds);                                     //push ds
  _push(_cs);                                     //push cs
  _ds = _pop();                                   //pop ds
  _bh = _bh ^ _bh;                                //xor bh, bh
  _bl = _ah;                                      //mov bl, ah
  _ah -= 0x10;                                    //sub ah, 10h
  if (_ah <= 0)                                   //jbe short loc_24BA5
    goto loc_24BA5;
  goto loc_24CC0;                                 //jmp loc_24CC0
loc_24BA5:                                        //loc_24BA5:
  _bl <<= 1;                                      //shl bl, 1
  switch (_bx)                                    //call off_24BDA[bx]
  {
    case 0: sub_24EFC(); break;
    case 2: sub_24CD5(); break;
    case 4: sub_24D33(); break;
    case 6: sub_24F05(); break;
    default:
      _ASSERT(0);
  }
loc_24BAB:                                        //loc_24BAB:
  _ds = _pop();                                   //pop ds
  _di = _pop();                                   //pop di
  _si = _pop();                                   //pop si
  _dx = _pop();                                   //pop dx
  _cx = _pop();                                   //pop cx
  _bx = _pop();                                   //pop bx
  return;                                         //iret
  _STOP_("db 3 dup(0), 1, 5 dup(0), 90h, 4 dup(0), 4...");
  _STOP_("db 2, 0B9h, 2, 0E7h, 2, 0EAh, 2, 8Dh, 2, 0...");
  _STOP_("db 3, 0A9h, 2, 0E2h, 2, 0F3h, 2, 0A4h, 2, ...");
  _STOP_("off_24BDA dw offset sub_24D57");        //off_24BDA dw offset sub_24D57
  _STOP_("db 10h, 99h, 79h, 90h, 5Dh, 88h, 0B6h, 80h...");
  _STOP_("db 72h, 3Bh, 6Ch, 28h, 66h, 6Ch, 60h, 3, 5...");
  _STOP_("db 15h, 51h, 88h, 4Ch, 3Ch, 48h, 2Fh, 44h,...");
  _STOP_("db 3Ch, 55h, 39h, 1Eh, 36h, 14h, 33h, 36h,...");
  _STOP_("db 0F4h, 2Ah, 8Bh, 28h, 44h, 26h, 1Eh, 24h...");
  _STOP_("db 20h, 5Fh, 1Eh, 0ABh, 1Ch, 0Fh, 1Bh, 8Ah...");
  _STOP_("db 0C1h, 16h, 7Ah, 15h, 45h, 14h, 22h, 13h...");
  _STOP_("db 11h, 17h, 10h, 30h, 0Fh, 55h, 0Eh, 87h,...");
  _STOP_("db 0Eh, 0Ch, 60h, 0Bh, 0BDh, 0Ah, 23h, 0Ah...");
  _STOP_("db 9, 86h, 8, 0Bh, 8, 98h, 7, 2Bh, 7, 0C4h...");
  _STOP_("db 7, 6, 0B0h, 5, 5Eh, 5, 11h, 5, 0C9h, 4,...");
  _STOP_("db 4, 6, 4, 0CCh, 3, 95h, 3, 62h, 3, 31h, ...");
  _STOP_("db 2, 0AFh, 2, 89h, 2, 64h, 2, 42h, 2, 21h...");
  _STOP_("db 1, 0CBh, 1, 0B1h, 1, 99h, 1, 82h, 1, 6C...");
  _STOP_("db 44h, 1, 32h, 1, 21h, 1, 30h dup(0)");//db 44h, 1, 32h, 1, 21h, 1, 30h dup(0)
loc_24CC0:                                        //loc_24CC0:
  _flags.carry = _bl < 0x20;                       //sub bl, 20h
  _bl -= 0x20;
  if (_flags.carry)                                //jb short loc_24CCC
    goto loc_24CCC;
  memory(_ds, _bx + 34) = _al;                    //mov [bx+22h], al
  goto loc_24BAB;                                 //jmp loc_24BAB
loc_24CCC:                                        //loc_24CCC:
  _bl = _ah;                                      //mov bl, ah
  _al = memory(_ds, _bx + 34);                    //mov al, [bx+22h]
  goto loc_24BAB;                                 //jmp loc_24BAB
}
