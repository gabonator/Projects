class COregon2 : public CProtocol
{
 public:
    enum {
        String_THGR810 = 2000,
        String_WGR800 = 2001,
        String_PCR800 = 2002,
        
        ID_THGR810 = 0xaf82,
        ID_WGR800 = 0xa198, // a1984
        ID_PCR800 = 0xa291, // a2914
    };
    
public:
	virtual int Frequency() override
	{
		return 433876000UL;
	}
	
    virtual const char* GetString(int i) override
    {
        switch (i)
        {
            case String_THGR810: return "THGR810";
            case String_WGR800: return "WGR800";
            case String_PCR800: return "PCR800";
        }
        return nullptr;
    }
  virtual void Example(CAttributes& attributes) override
  {
    // -512 (-51.2 C) ... 999 (+99.9 C)
    attributes["length"] = 64;
    attributes["data_0"] = 0x12345678;
    attributes["data_1"] = 0xabcdef01;
  }

  virtual bool Demodulate(const CArray<uint16_t>& pulse, CAttributes& attributes) override
  {
    uint8_t nibblesData[24];
    CArray<uint8_t> b(nibblesData, COUNT(nibblesData));

    int length = 0;
    if (!PulseToBytes(pulse, b, length))
      return false;

    BitstreamToAttributes(b, length, attributes);

    Analyse(attributes);
    return true;
  }

  void Analyse(CAttributes& attributes)
  {
      //50 FA28A428 20229083 4B46
    const uint32_t d0 = attributes["data_0"];
    const uint32_t d1 = attributes["data_1"];
    const uint32_t d2 = attributes["data_2"];

    uint8_t message[12] = {
        (uint8_t)(d0 >> 24), (uint8_t)(d0 >> 16), (uint8_t)(d0 >> 8), (uint8_t)(d0),
        (uint8_t)(d1 >> 24), (uint8_t)(d1 >> 16), (uint8_t)(d1 >> 8), (uint8_t)(d1),
        (uint8_t)(d2 >> 24), (uint8_t)(d2 >> 16), (uint8_t)(d2 >> 8), (uint8_t)(d2)};
     bool wrongRead = false;

      auto nibble = [&wrongRead](uint8_t* p, int n)
      {
          int v = ((n&1)==0) ? p[n>>1] >> 4 : p[n>>1] & 0x0f;
          if (v > 9) wrongRead = true;
//          _ASSERT(v <= 9);   // TODO: !
          return v;
      };
      auto nibble16 = [](uint8_t* p, int n)
      {
          int v = ((n&1)==0) ? p[n>>1] >> 4 : p[n>>1] & 0x0f;
          return v;
      };
      
        #define nib(i) nibble(message, i)
        #define nib16(i) nibble16(message, i)
      
      int sensor_id = (message[0] << 8) | message[1];

      if (sensor_id == ID_THGR810) // 0xaf824
      {
        attributes["$model"] = String_THGR810; //(uintptr_t)"THGR810";
        int temp_c = nib(11)*100 + nib(10)*10 + nib(9);
        if (nib(12) != 0)  
            temp_c = -temp_c;
        int hum = nib(14)*10 + nib(13);

        attributes["temperature10"] = temp_c;
        attributes["humidity"] = hum;
        attributes["channel"] = nib16(6) + nib16(7)*16;

        uint8_t checksum = 0;
        for (int i=0; i<15; i++)
          checksum += nib16(i+1);

        attributes["crc"] = nib16(16)+nib16(17)*16 == checksum;
        if (wrongRead)
          attributes["crc"] = 0;

        // high nibble (x) = x*2+1,  low nibble (x) = x*2+2
    }
      if (sensor_id == ID_WGR800)
      {
        attributes["$model"] = String_WGR800;
                int gustWindspeed10 = nib(12) + nib(13)*10 + nib(14) * 100;
                int avgWindspeed10 = nib(15) + nib(16)*1 + nib(17) * 100;
                int quadrant = nib16(9);
        // m/s
        attributes["gusts10"] = gustWindspeed10;
        attributes["wind10"] = avgWindspeed10;
        attributes["quadrant16"] = quadrant;
        attributes["channel"] = nib16(6) + nib16(7)*16;//nib(5);
        //rc = (message[2] & 0x0F) + (message[3] & 0xF0);

        uint8_t checksum = 0;
        for (int i=0; i<17; i++)
          checksum += nib16(i+1);

        attributes["crc"] = nib16(18)+nib16(19)*16 == checksum;
        if (wrongRead)
          attributes["crc"] = 0;

      }
      if (sensor_id == ID_PCR800) {
        attributes["$model"] = String_PCR800;

        //LSD = 0.01 inches per hour
        int rainRate100inch = nib(12) * 1000 + nib(11) * 100 + nib(10) * 10 + nib(9);
        // Nibbles 17..12 Total rain, LSD = 0.001, 543210 = 012.345 inches
        long totalRain1000inch = nib(18) * 100000
            + nib(17) * 10000 + nib(16) * 1000
            + nib(15) *100 + nib(14) *10
            + nib(13);

        attributes["rainRate100i"] = rainRate100inch;
        attributes["rainTotal1000i"] = totalRain1000inch;
        attributes["channel"] = nib16(6) + nib16(7)*16;

        uint8_t checksum = 0;
        for (int i=0; i<18; i++)
          checksum += nib16(i+1);

        attributes["crc"] = nib16(19)+nib16(20)*16 == checksum;
        if (wrongRead)
          attributes["crc"] = 0;
      }


#undef nib
  }
    
    virtual void Synthesize(CAttributes& attributes) override
    {
        auto setnib = [&](int nibble, int value)
        {
            const char* key = "data_0";
            if (nibble < 16)
                key = "data_2";
            else if (nibble < 8)
                key = "data_1";
            
            int i = attributes.indexOf(key);
            if (i==-1)
            {
                //BIOS::DBG::Print("oregon-2 synth error");
                //_ASSERT(0);
                return;
            }
            
            TKeyValue& kv = attributes[i];

            _ASSERT(value >= 0 && value <= 15);
            int bitofs = (7-(nibble&7))*4;
            kv.value &= ~(0xf<<bitofs);
            kv.value |= value<<bitofs;
        };
        
        if (attributes.indexOf("$model") != -1 && attributes["$model"] == String_THGR810)
        {
            int temp = (int)attributes["temperature10"];
            if (temp < 0)
                setnib(12, 0xf);
            else
                setnib(12, 0x0);
            temp = abs(temp);
            setnib(11, (temp/100)%10);
            setnib(10, (temp/10)%10);
            setnib(9, temp%10);
            
            int hum = abs((int)attributes["humidity"]);
            setnib(14, (hum/10)%10);
            setnib(13, hum%10);
        }
    }

    virtual bool Modulate(const CAttributes& attr, CArray<uint16_t>& pulse) override
    {
        uint8_t nibblesData[24];
        CArray<uint8_t> b(nibblesData, COUNT(nibblesData));
        int length;
        AttributesToBitstream(attr, b, length);
        return BytesToPulse(b, length, pulse);
    }

    virtual int PulseDivisor() override { return 350; }
    
private:
  int PulseLen(int microseconds)
  {
      return (microseconds+480/2)/480;
  }

  int PulseDuration(int ticks)
  {
      return ticks*350;
  }

  bool PulseToBytes(const CArray<uint16_t>& pulse, CArray<uint8_t>& bytes, int& length)
  {
    int i;
    for (i=0; i<pulse.GetSize()-4; i++)
    {
      int t = PulseLen(pulse[i]);
      if (t == 2)
        break;
      if (t != 1)
        return false;
    }

    if (i < 40) // should be 47 (45, 46, 47)
      return false;

    int l = 1;
    length = 0;
    int bits = 0;
    for (; i<pulse.GetSize(); i++)
    {
      bool isLast = i == pulse.GetSize() - 1;
      if (PulseLen(pulse[i]) == 1 && (isLast || PulseLen(pulse[i+1]) == 1))
      {
        if (l)
            bits |= 1 << (7-(length & 7));
          
        length++;
        //bits <<= 1;
        //bits |= l;
        i++;
      }
      else
      if (PulseLen(pulse[i]) == 2)
      {
          l = 1-l;
          if (l)
              bits |= 1 << (7-(length & 7));

          length++;
        //l = 1-l;
        //bits <<= 1;
        //bits |= l;
      }
      else        
      {
        return false;
      }

      if ((length & 7) == 0)
      {
        // swap nibbles
        bits = reverse(bits);
        bits = (bits >> 4) | ((bits & 15) << 4);
        bytes.Add(bits);
          if (bytes.GetMaxSize() == bytes.GetSize())
              return true;
        bits = 0;
      }
    }
      
      if ((length & 7) != 0)
      {
        // swap nibbles
        bits = reverse(bits);
        bits = (bits >> 4) | ((bits & 15) << 4);
        bytes.Add(bits);
          if (bytes.GetMaxSize() == bytes.GetSize())
              return true;
        bits = 0;
      }

    return true;
  }

  unsigned char reverse(unsigned char b) {
     b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
     b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
     b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
     return b;
  }

  bool BytesToPulse(const CArray<uint8_t>& bytes, int length, CArray<uint16_t>& pulse)
  {                                   
    const int preambule = 47; // parne cislo?
    for (int i=0; i<preambule; i++)
      pulse.Add(PulseDuration(1));

    int l = 1;
    for (int i=0; i<length; i++)
    {
      int bit = (bytes[i/8] >> (7-(i&7)))&1;
      if (l==bit)
      {
        pulse.Add(PulseDuration(1));
        pulse.Add(PulseDuration(1));
      } else
      {
        l = 1-l;
        pulse.Add(PulseDuration(2));
      }
    }
    return true;
  }

    virtual void GetName(char* name) override
    {
        strcpy(name, "OregonScientific-2");
    }
    
    virtual void GetDescription(CAttributes& attributes, char* desc) override
    {
        int model = 0;
        if (attributes.indexOf("$model") != -1)
            model = attributes["$model"];
        
        if (model == String_THGR810)
        {
            sprintf(desc, "<THGR810:> ch:%d temp <%d.%d\xf8""C> hum <%d%%>", (int)attributes["channel"], (int)attributes["temperature10"] / 10, (int)attributes["temperature10"] % 10, (int)attributes["humidity"]);
        }
        else if (model == String_WGR800)
        {          
            sprintf(desc, "<WGR800:> ch:%d avg <%d.%d m/s> gusts <%d.%d>", (int)attributes["channel"], (int)attributes["wind10"] / 10, (int)attributes["wind10"] % 10,
              (int)attributes["gusts10"] / 10, (int)attributes["gusts10"] % 10);
        }
        else if (model == String_PCR800)
        {
            sprintf(desc, "<PCR800:> ch:%d rain <%d.%d\"/h> total <%d.%d\">", (int)attributes["channel"], (int)attributes["rainRate100i"] / 100, (int)(attributes["rainRate100i"] % 100)/10, 
              (int)attributes["rainTotal1000i"] / 1000, (int)(attributes["rainTotal1000i"] % 1000)/100);
        }
        else
            sprintf(desc, "%d bits: <%08x %08x>", (int)attributes["length"], (int)attributes["data_0"], (int)attributes["data_1"]);
    }

};
