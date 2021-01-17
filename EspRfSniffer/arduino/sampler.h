bool streamerBufferLogic = 0;
int streamerBufferCounter = 0;
int streamerBufferMaxCounter = 25000;
int streamerOverrun = 0;
RingBufCPP<uint16_t, 512> streamerBuffer;

void ICACHE_RAM_ATTR sampler(bool sample)
{
    if (sample == streamerBufferLogic)
    {
      streamerBufferCounter++;
      // append [60000, 0] to buffer
      if (streamerBufferCounter >= streamerBufferMaxCounter)
      {
        if (streamerBuffer.capacity() > 2)
        {                                           
          streamerBuffer.push(streamerBufferCounter);
          streamerBuffer.push(0);
        } else
        {
          streamerOverrun++;
        }
        streamerBufferCounter = 0;
      }
    } else
    {
      // append ticks to buffer and toggle logic
      if (streamerBuffer.capacity() > 1)
        streamerBuffer.push(streamerBufferCounter);
      else
        streamerOverrun++;

      streamerBufferCounter = 0;
      streamerBufferLogic = 1 - streamerBufferLogic;
    }  
}
