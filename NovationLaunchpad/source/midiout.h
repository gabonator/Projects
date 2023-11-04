    #include "gpio_midi.h"

class CAppMidiout : public CApp, public CMidi
{
  uint32_t clr{0x00ff00};
  uint8_t map[100] = {0};
  int32_t last{0};
  int check = 0;
  int channel = 15;
  int transpose{60}; 
  int inhibit{0};
  bool latch{false};
  bool arp{false};
  int arptime{0};
  int arppos{0};
  int arpspd{40};
  enum {
    Pressed = 255,
    Latch = 254,
    Arpeggio = 253,
    Released = 252
  };

public:
  virtual void enter() override
  {
    MidiSet();
    for (int y=0; y<9; y++)
      for (int x=0; x<9; x++)
        pixel(x, y) = 0;
  }

  virtual void leave() override
  {
    MidiReset();
  }

  uint32_t fade(uint32_t base, uint8_t& v)
  {
    if (v == 0)
      return base;
    if (v > Released)
      return clr;

    int r = (clr >> 16) & 255;
    int g = (clr >> 8) & 255;
    int b = (clr >> 0) & 255;
    r = r * v / 256;
    g = g * v / 256;
    b = b * v / 256;
    v = 256-v;
    int rb = (base >> 16) & 255;
    int gb = (base >> 8) & 255;
    int bb = (base >> 0) & 255;
    r += rb * v / 256;
    g += gb * v / 256;
    b += bb * v / 256;
    v = 256-v;
    v--;

    return (r<<16) | (g<<8) | b;
  }

  virtual void loop() override
  {
    if (ticks() - last < 5)
      return;
    last = ticks();

    if (arp)
    {
      if (arptime++ >= arpspd)
      {
        arptime = 0;
        if (map[arppos] == Pressed || map[arppos] == Latch)
        {
          int note = GetNote(arppos%10, arppos/10);
          if (note != -1)
            MidiSend(CMidi::NoteOff + channel, note, CMidi::VelocityFull);
        }

        for (int i=0; i<100; i++)
        {
          arppos = (arppos+1)%100;
          if (map[arppos] == Pressed || map[arppos] == Latch)
          {
            int note = GetNote(arppos%10, arppos/10);
            if (note != -1)
              MidiSend(CMidi::NoteOn + channel, note, CMidi::VelocityFull);
            break;
          }
        }
      }
    }
    if (inhibit>0)
    {
      if (--inhibit == 0)
        hideText();
      return;
    }

    for (int y=1; y<9; y++)
      for (int x=0; x<8; x++)
        pixel(x, y) = fade(GetKeyboard(x, y), map[y*10+x]);

    int tim = (last>>2)&511;
    tim = tim <= 255 ? tim : 511-tim;
    pixel(8, 8) = latch ? (tim << 8) : 0;
    pixel(8, 7) = arp ? ((255-tim) << 8) : 0;
  }

  void showText(const char* f, int x)
  {
    char message[8];
    uint8_t buffer[9] = {0};

    strcpy(message, f);
    char* end = message + strlen(message);
    itoa(x, end, 10);

    int w = getTextWidth(message);

    renderText(buffer, (10-w)/2, 0, message);

    for (int y=0; y<8; y++)
      for (int x=0; x<9; x++)   
        pixel(x, y+1) = (buffer[x] & (1<<y)) ? 0xffffff : 0x000000;

    inhibit = 200;
  }

  void hideText()
  {
    for (int y=0; y<8; y++)
      for (int x=0; x<9; x++)   
        pixel(x, y+1) = 0;
  }

  virtual void onPress(int x, int y, int v) override
  {
    if (y == 0)
    {
      switch (x)
      {
        case 0: // up
          if (transpose < 84)
            transpose += 12;
          showText("o", transpose/12);
          break;
        case 1: // down
          if (transpose >= 12)
            transpose -= 12;
          showText("o", transpose/12);
          break;
        case 2: // left
          if (arp)
          {
            arpspd += 4;
            break;
          }
          if (channel > 0)
            channel--;
          showText("", channel+1);
          break;
        case 3: // right
          if (arp)
          {
            if (arpspd > 8)
              arpspd -= 4;
            break;
          }
          if (channel < 15)
            channel++;
          showText("", channel+1);
          break;
      }
      return;
    }
    if (x == 8 && y == 8)
    {
      if (!latch)
      {
        latch = true;
        // mark all pressed
        for (int y=1; y<9; y++)
          for (int x=0; x<8; x++)
            if (map[y*10+x] == Pressed)
              map[y*10+x] = Latch;
      } else {
        latch = false;
        // release marked
        for (int y=1; y<9; y++)
          for (int x=0; x<8; x++)
            if (map[y*10+x] == Latch)
            {
              map[y*10+x] = Released;
              onRelease(x, y);
            }
      }
      return;
    }
    if (x == 8 && y == 7)
    {
      if (!arp)
      {
        arp = true;
        arptime = 0;
        arppos = 0;
        for (int y=1; y<9; y++)
          for (int x=0; x<8; x++)
            if (map[y*10+x] == Pressed)
            {
              int note = GetNote(x, y);
              if (note != -1)
                MidiSend(CMidi::NoteOff + channel, note, CMidi::VelocityFull);
            }
      } else {
        if (map[arppos] == Pressed)
          MidiSend(CMidi::NoteOff + channel, arppos, CMidi::VelocityFull);
        arp = false;
      }
      return;
    }

    int note = GetNote(x, y);
    if (note == -1)
      return;
    if (!arp)
      MidiSend(CMidi::NoteOn + channel, note, CMidi::VelocityFull);
    map[y*10 + x] = Pressed;
  }

  virtual void onRelease(int x, int y) override
  {
    int note = GetNote(x, y);
    if (note == -1)
      return;
    if (map[y*10 + x] == Latch)
      return;
    if (!arp)
      MidiSend(CMidi::NoteOff + channel, note, CMidi::VelocityFull);
    if (arp && arppos == y*10+x)
      MidiSend(CMidi::NoteOff + channel, note, CMidi::VelocityFull);
    map[y*10 + x] = Released;
  }

  uint32_t GetKeyboard(int x, int y)
  {
    static const uint32_t colors[] = {0x000000, 0x40b0f0, 0xf020f0};
    static const uint8_t pat[] = {
      0, 1, 1, 0, 1, 1, 1, 0,   0, 
      2, 1, 1, 1, 1, 1, 1, 2,   0};
    int octave = (y-1)/2;
    int row = (y-1)&1;
    return colors[pat[x+row*9]];
  }

  int GetNote(int x, int y)
  {
    if (y < 1 && y >= 1+8)
      return -1;

    int octave = (y-1)/2;
    static const int8_t mapkey[18] = {
      -1, 1,  3, -1,  6,  8,  10,  -1,   -1,
      0,  2,  4,  5,  7,  9,  11,  12,   -1};
    int row = (y-1)&1;
    int col = x;
    int note = mapkey[row*9+col];
    if (note == -1)
      return -1;

    note += transpose + octave*12-12*2;
    return note;
  }
};
