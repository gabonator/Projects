#include <Arduino.h>
#include <driver/i2s_std.h>

#include "Display_ST7789.h"
#include "delaylama_dsp.h"
#include "image.h"
constexpr int SAMPLE_RATE = 44100;
constexpr int BLOCK_SIZE  = 256;

#define I2S_DOUT GPIO_NUM_47
#define I2S_BCLK GPIO_NUM_48
#define I2S_LRC  GPIO_NUM_38
static i2s_chan_handle_t tx_chan;

DelayLamaDSP dsp;
TaskHandle_t audioTask;

void setupI2S()
{
    //i2s_chan_config_t chan_cfg =
        //I2S_CHANNEL_DEFAULT_CONFIG(I2S_NUM_0, I2S_ROLE_MASTER);

    i2s_chan_config_t chan_cfg = {
        .id = I2S_NUM_0,
        .role = I2S_ROLE_MASTER,
        .dma_desc_num = 2,      // Only 2 DMA buffers
        .dma_frame_num = BLOCK_SIZE,   // Frames per buffer
        .auto_clear = true,
    #if SOC_I2S_SUPPORTS_TDM
        .auto_clear_before_cb = false,
    #endif
        .intr_priority = 0,
    };

    i2s_new_channel(&chan_cfg, &tx_chan, NULL);

    i2s_std_config_t std_cfg =
    {
        .clk_cfg =
            I2S_STD_CLK_DEFAULT_CONFIG(SAMPLE_RATE),

        .slot_cfg =
            I2S_STD_MSB_SLOT_DEFAULT_CONFIG(
                I2S_DATA_BIT_WIDTH_32BIT,
                I2S_SLOT_MODE_STEREO),

        .gpio_cfg =
        {
            .mclk = I2S_GPIO_UNUSED,
            .bclk = I2S_BCLK,
            .ws   = I2S_LRC,
            .dout = I2S_DOUT,
            .din  = I2S_GPIO_UNUSED,
            .invert_flags = {}
        }
    };

    i2s_channel_init_std_mode(tx_chan, &std_cfg);
    i2s_channel_enable(tx_chan);
}


void setup()
{
    // Init DSP
    dsp.init((float)SAMPLE_RATE);

    // Parameters — match DLL default preset 0 (confirmed from JS emulator state dump):
    //   portamento=0.5, vowel_sel=0.5, vowel_depth=0.5, feedback=0.8
    dsp.setParameter(0, 0.5f);   // volume
    dsp.setParameter(1, 0.5f);   // vowel_sel
    dsp.setParameter(2, 0.5f);   // portamento (DLL default [esi+0xb0]=0.5)
    dsp.setParameter(3, 0.5f);   // vowel_depth (DLL default [esi+0xc4]=0.5)
    dsp.setParameter(4, 0.8f);   // feedback (DLL default [esi+0xbc]=0.8)

    setupI2S();


    // lcd
    LCD_Init();
    Backlight_Init();
    Set_Backlight(Backlight_MAX*0.8);
    LCD_SetCursor(0, 0, 240, 320);
    LCD_WriteBegin();
//GRB565
/*
    // blue, green chessboard
    for (int y=0; y<240; y++)
       for (int x=0; x<320; x++)
        LCD_Write((x/8+y/8)%2 ? 0x001f : 0xf800);

        // white red chessboard
     for (int y=0; y<240; y++)
       for (int x=0; x<320; x++)
        LCD_Write((x/8+y/8)%2 ? (0x3f << 5) : 0xffff);
*/
        
//       LCD_Write(x+y*256);
    LCD_Write(image, 320*240);
    LCD_WriteEnd();

    xTaskCreatePinnedToCore(
        audioTaskFunc,
        "Audio",
        8192,
        nullptr,
        configMAX_PRIORITIES - 1,
        &audioTask,
        1      // choose core 0 or 1
    );
}

float left[BLOCK_SIZE], right[BLOCK_SIZE];
int32_t samples[BLOCK_SIZE * 2];


void loop()
{
  vTaskDelay(portMAX_DELAY);
}

void audioTaskFunc(void *arg)
{
int32_t last = 0;
    while (true) {
      int32_t now = millis();
      float f = cos(now/30000.0f*M_PI*2);
      dsp.setParameter(1, f*0.5+0.5);
      if (now-last > 3000) {
        last = now;
            dsp.noteOn(40+ random()%40, 100);

      }
      
      dsp.process(left, right, BLOCK_SIZE);
    
      for (int i = 0; i < BLOCK_SIZE; i++) {
        float f = left[i]*0.7f;
        if (f < -1) samples[2 * i + 0] = 0x80000000;
        else if (f > 1) samples[2 * i + 0] = 0x7fffffff;
        else samples[2 * i + 0] = (int32_t)(f * 2147483647.0f);

        f = right[i]*0.7f;
        if (f < -1) samples[2 * i + 1] = 0x80000000;
        else if (f > 1) samples[2 * i + 1] = 0x7fffffff;
        else samples[2 * i + 1] = (int32_t)(f * 2147483647.0f);

        //samples[2 * i + 0] = (int32_t)(left[i] * 2147483647.0f * 0.7f);
        //samples[2 * i + 1] = (int32_t)(right[i] * 2147483647.0f * 0.7f);
      }
      
      size_t written;
      i2s_channel_write(
          tx_chan,
          samples,
          BLOCK_SIZE * 2 * 4,
          &written,
          portMAX_DELAY);
    }
}

