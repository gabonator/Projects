#include "machine.h"
#include "ega.h"

CEga mVideo;
WORD _stack[64];
BYTE memoryBuffer[0x1000*8];
BYTE videoBuffer[640*480];

int _filesize();
int _fileopen(char* name);
int _fileclose();
int _fileread(int ofs, int size, int mseg, int mofs);

void _tone(int f)
{
//    std::cout << "tone " << hex << f << " f=" << dec << (1193180/f) << "\n";
}

void _out(WORD port, BYTE val)
{
    if (mVideo.PortWrite8(port, val))
        return;

    if (port == 0x201 || port == 0x40)
        return;
    
    if (port == 0x61)
    {
        if ((val & 3) == 3)
        {
            // speaker on
            return;
        }
        if ((val & 3) == 0)
        {
            // speaker ff
            return;
        }
        _ASSERT(0);
    }
    
    static int _p42 = 0;
    static int _buffer42 = 0;
    
    if ( port == 0x43 )
    {
        if ( val == 0x36 ) // play tone, channel 0
        {
            _p42 = 0;
            _buffer42 = 0;
        }
      else if ( val == 0xB6 ) // play tone, channel 1/2?
      {
        _p42 = 0;
        _buffer42 = 0;
      } else if (val == 0x00)
      {
        _ASSERT(0);
      } else
        _ASSERT(0);
        return;
    }
    if ( port == 0x42 )
    {
      if ( _p42 == 0 )
      {
        _buffer42 = val;
        _p42++;
      } else if ( _p42 == 1 )
      {
        _buffer42 = (val<<8) | _buffer42;
        _tone(/*1193180 /*/ _buffer42);
          _p42 =0;
      }
        return;
    }
    _ASSERT(0);
}

void _out(WORD port, WORD val)
{
    if (mVideo.PortWrite16(port, val))
        return;
    _ASSERT(0);
}

void _interrupt(BYTE i)
{
    static int filePos = 0;

    if (i == 0x21 && _ah == 0x3e)
    {
        _fileclose();

//        std::cout << "Close file" << endl;
        _flags.carry = 0;
        return;
    }

    if (i == 0x21 && _ah == 0x3d)
    {
        // read file DS:DX filename
        // AX = file handle
        char filename[100];
        bool dot = false;
        int p = 0;
        for (int i=0; i<100; i++)
        {
            char c = memory(_ds, _dx+i);
            if (c==' ')
                continue;
            if (!c)
                break;
            filename[p++] = c;
        }
        filename[p] = 0;
        if (_fileopen(filename))
        {
          filePos = 0;
          _flags.carry = 0;
          _ax = 1;
        } else
        {
          _flags.carry = 1;
          _ax = 0;
        }
        return;

    }
    if (i == 0x21 && _ah == 0x3f)
    {
        _fileread(filePos, _cx, _ds, _dx);
        filePos += _cx;
        _flags.carry = 0;
/*
        // read file CX bytes => CS:DX
        _ASSERT(f);
        uint8_t* buf = new uint8_t[_cx];
        int c = fread(buf, 1, _cx, f);
        for (int i=0; i<_cx; i++)
            memory(_ds, _dx+i) = buf[i];
        delete[] buf;
        std::cout << "read " << _cx << " (" << c << ")" << endl;
        _ASSERT(c);
        _flags.carry = 0;
*/
        return;

    }
    
    if (i == 0x21 && _ah == 0x42)
    {
        // move file pointer
        if (_al == 2 && _cx == 0 && _dx == 0)
        {
            _ax = _filesize();
            _dx = 0;
            return;
        }
        if (_al == 0 && _dx == 0)
        {
//            filePos = 0;
            return;
        }

    }

    if (i == 0x21 && _ah == 0x35)
    {        
        // get int vect AL ES:BX
        // AL == 08 -> system timer
        _es = 0;
        _bx = 0;
        return;

    }
    if (i == 0x21 && _ah == 0x25)
    {
        // set int vect AL DS:DX
        // seg000:600b - TODO: ignorujeme
        return;

    }
    if (i == 0x80)
    {
        //sub_24B90();
        return;

    }
    
    if (i == 0x16) // keyboard
    {
        // TODO
        static int simEnter = 0;
        if (_ah == 0x00)
        {
/*
            if (keyboardBuffer.size() > 0)
            {
                _ax = keyboardBuffer.front();
                keyboardBuffer.pop_front();
            }
*/
            _ax = 0;
            return;
        }
        if (_ah == 0x01)
        {
            _flags.zero = true; //(keyboardBuffer.size() == 0);
        }
        return;

    }
    if (i == 0x10) // gfx
    {        
        if (_ah == 0x10 && _al == 0x12)
        {
            mVideo.Interrupt();
            return;
        }
        if (_ah == 0x1a)
        {
            // get video info
            //http://www.techhelpmanual.com/177-int_10h_1ah__set_or_query_display_combination_code.html
            _al = 0x1a;
            _bl = 5;
            return;
        }
        if (_ah == 0x0f)
        {
            // get character count
            //https://vitaly_filatov.tripod.com/ng/asm/asm_023.16.html
            _al = 3;
            _ah = 80;
            _bh = 0;
            return;
        }
        if (_ah == 0x01)
        {
            // set cursor size
            return;
        }
        if (_ah == 0x00)
        {
//            cout << hex << "\nset video mode " << (int)_al << endl;
            return;
        }
        if (_ax == 0x1002)
        {
            mVideo.Interrupt();
            //cout << "set palette " << endl;
            return;
        }
        if (_ax == 0x1001)
        {
//            cout << "set border " << endl;
            return;
        }
        if (_ax == 0x1110)
        {
//            cout << "set custom font " << endl;
            return;
        }
        if (_ax == 0x1201)
        {
//            cout << "set vertical resolution " << endl;
            return;
        }
        if (_ax == 0x1103)
        {
//            cout << "block specifier " << endl;
            return;
        }
        if (_ax == 0x1003)
        {
//            cout << "toggle intensity blinking " << endl;
            return;
        }

        _ASSERT(0);
        return;
    }
    
    if (i == 0x21 && _ah == 0x3c)
    {
        // create file
        _flags.carry = 1;
        return;
    }
    
    if (i == 0x1A && _ah == 0x00)
    {
        // time of day
        _cx = 1;
        _dx = 1;
        return;
    }
    
    if (i == 0x21 && _ah == 0x2c)
    {
        _ch = 1; // hours
        _cl = 0; // mins
        _dx = 0;
        return;
        
    }
    if (i == 0x21 && _ah == 0x2a)
    {
        _dl = 1; // day
        _dh = 1; // month
        _cx = 2035;
        return;        
    }
    if (i == 0x12)
    {
        _ax = 0x800;
        return;
    }

    _ASSERT(0);
}

void _in(BYTE& val, WORD port)
{
    if (port == 0x61) // speaker
    {
        val = 0;
        return;
    }
    if (port == 0x201) // joystick
    {
        val = 0xff;
        return;
    }
    _ASSERT(0);
}

BYTE memoryVideoGet(WORD seg, WORD ofs) 
{
    return mVideo.Read(seg*16+ofs);
}

void memoryVideoSet(WORD seg, WORD ofs, BYTE b) 
{
    return mVideo.Write(seg*16+ofs, b);
}

WORD memoryBiosGet16(WORD seg, WORD ofs)
{
    if (seg == 0x0040 && ofs == 0x0063)
        return 0x3d4;
    _ASSERT(0);
    return 0;
}

BYTE& memory(WORD segment, WORD offset) 
{ 
  int ofs = segment*16+offset;
  assert(ofs < sizeof(memoryBuffer));
  return memoryBuffer[ofs];
}

WORD& memory16(WORD segment, WORD offset) 
{ 
  int ofs = segment*16+offset;
  assert(ofs < sizeof(memoryBuffer));
  return (WORD&)memoryBuffer[ofs];
}

void _push(WORD data)
{
js_debug(444);
js_debug(_sp);
    assert(_sp/2 < sizeof(_stack));
    _stack[_sp/2] = data;
    _sp -= 2;
}

WORD _pop()
{
js_debug(555);
js_debug(_sp);
    _sp += 2;
    assert(_sp/2 < sizeof(_stack));
    return _stack[_sp/2];
}

extern "C" uint8_t* appVideoBuffer();
extern "C" uint8_t* appMemory();

uint8_t* appMemory()
{  
    return memoryBuffer;
}

uint8_t* appVideoBuffer()
{
    int shift = mVideo.cfgAddr;
    BYTE* planes = (BYTE*)(mVideo.memory + shift);
        
    BYTE* p = videoBuffer;
    for (int y=0; y<350; y++)
        for (int x=0; x<640/8; x++)
        {
            int plane0 = *planes++;
            int plane1 = *planes++;
            int plane2 = *planes++;
            int plane3 = *planes++;

            for (int i=0; i<8; i++)
            {
                int index = (plane0 & 128) + (plane1 & 128)*2 + (plane2 & 128)*4 + (plane3 & 128)*8;
                int color = mVideo.palette[index >> 7];
                *p++ = color >> 16;
                *p++ = color >> 8;
                *p++ = color >> 0;
                plane0 <<= 1;
                plane1 <<= 1;
                plane2 <<= 1;
                plane3 <<= 1;
            }
        }
   return videoBuffer;
}

