/*
 *   Latency calculation by Claude
 *┌───────────────────────────────────────────────┬────────────┐                                                                                    
  │                     Stage                     │    Time    │
  ├───────────────────────────────────────────────┼────────────┤                                                                                    
  │ MIDI serial transfer (3 bytes @ 31250 baud)   │ ~960 µs    │                                                                                  
  ├───────────────────────────────────────────────┼────────────┤
  │ UART FIFO wait (0–1 audio block)              │ 0–362 µs   │
  ├───────────────────────────────────────────────┼────────────┤                                                                                    
  │ Parse + process + I2S commit (measured)       │ 350–700 µs │
  ├───────────────────────────────────────────────┼────────────┤                                                                                    
  │ DMA playback (1 buffer to start clocking out) │ 0–362 µs   │                                                                                  
  └───────────────────────────────────────────────┴────────────┘ 
 */
#include <Arduino.h>
#include <driver/i2s_std.h>
#include <driver/uart.h>
#include <esp_timer.h>

#include "Display_ST7789.h"
#include "delaylama_dsp.h"
#include "image.h"
constexpr int SAMPLE_RATE = 44100;
constexpr int BLOCK_SIZE  = 16;

#define I2S_DOUT GPIO_NUM_47
#define I2S_BCLK GPIO_NUM_48
#define I2S_LRC  GPIO_NUM_38
static i2s_chan_handle_t tx_chan;

constexpr uart_port_t MIDI_UART = UART_NUM_1;

DelayLamaDSP dsp;
TaskHandle_t audioTaskStream;
TaskHandle_t resonatorTask;
QueueHandle_t midiQueue;
uart_event_t event;

// Double buffer for triggerResonator (computed on core 1)
float resonatorBuf[DelayLamaDSP::N_frames];
volatile bool resonatorReady = false;
volatile int pendingVowelIdx = 0;
volatile bool pendingForceTrigger = false;

void resonatorTaskFunc(void* arg) {
    while (true) {
        ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
        dsp.triggerResonator(pendingVowelIdx, resonatorBuf);
        resonatorReady = true;
    }
}

void processMidiEvent(uint8_t event, uint8_t data1, uint8_t data2);

class MidiParser
{
public:

    void input(uint8_t b)
    {
        // Realtime messages may appear anywhere.
        if (b >= 0xF8)
        {
            processRealtime(b);
            return;
        }

        // Status byte?
        if (b & 0x80)
        {
            runningStatus = b;
            index = 0;
            return;
        }

        // Ignore data before first status.
        if (runningStatus == 0)
            return;

        buffer[index++] = b;

        int needed = dataLength(runningStatus);

        if (index >= needed)
        {
            processMidiEvent(
                runningStatus,
                buffer[0],
                needed > 1 ? buffer[1] : 0);

            index = 0;
            // runningStatus intentionally preserved
        }
    }

private:
    uint8_t runningStatus = 0;
    uint8_t buffer[2];
    int index = 0;

    static int dataLength(uint8_t status)
    {
        switch (status & 0xF0)
        {
            case 0xC0:      // Program Change
            case 0xD0:      // Channel Pressure
                return 1;

            case 0x80:
            case 0x90:
            case 0xA0:
            case 0xB0:
            case 0xE0:
                return 2;
        }

        return 0;
    }

    void processRealtime(uint8_t msg)
    {
        // MIDI clock/start/stop if desired
    }

    void processMidiEvent(uint8_t event,
                          uint8_t data1,
                          uint8_t data2)
    {
        ::processMidiEvent(event, data1, data2);
    }
};
MidiParser parser;

int gMidiPrevNote = 0;
int gMidiPrevMod = 0;
int gMidiPrevPitch = 0;
int gMidiNote = 0;
int gMidiPitch = 0;
int gMidiVelocity = 0;
int gMidiMod = 0;
int gMidiEcho = -1;
int gMidiPrevEcho = -1;
int gMidiVibrato = -1;
int gMidiPrevVibrato = -1;
int gMidiPortamento = -1;
int gMidiPrevPortamento = -1;
int gMidiDepth = -1;
int gMidiPrevDepth = -1;
volatile uint32_t gNoteOnSeq = 0;   // incremented on every note-on
uint32_t prevNoteOnSeq = 0;
volatile uint32_t gNoteOffSeq = 0;  // incremented on every note-off
uint32_t prevNoteOffSeq = 0;

// note buf
constexpr int MAX_HELD_NOTES = 16;

uint8_t heldNotes[MAX_HELD_NOTES];
int heldNoteCount = 0;

static void noteOnStack(uint8_t note)
{
    // Remove if already present (prevents duplicates)
    for (int i = 0; i < heldNoteCount; ++i)
    {
        if (heldNotes[i] == note)
        {
            for (int j = i; j < heldNoteCount - 1; ++j)
                heldNotes[j] = heldNotes[j + 1];
            --heldNoteCount;
            break;
        }
    }

    if (heldNoteCount < MAX_HELD_NOTES)
        heldNotes[heldNoteCount++] = note;

    gMidiNote = heldNotes[heldNoteCount - 1];
}

static void noteOffStack(uint8_t note)
{
    for (int i = 0; i < heldNoteCount; ++i)
    {
        if (heldNotes[i] == note)
        {
            for (int j = i; j < heldNoteCount - 1; ++j)
                heldNotes[j] = heldNotes[j + 1];
            --heldNoteCount;
            break;
        }
    }

    if (heldNoteCount)
        gMidiNote = heldNotes[heldNoteCount - 1];
    else
        gMidiNote = 0;
}
// note buf

void processMidiEvent(uint8_t event, uint8_t data1, uint8_t data2)
{
  //printf("{%02x %02x %02x} ", event, data1, data2);
    uint8_t cmd = event & 0xF0;
    uint8_t ch  = event & 0x0F;
    switch (cmd)
    {
        case 0x90:      // Note On
            if (data2 == 0)
            {
              noteOffStack(data1);
              gNoteOffSeq++;
            }
            else
            {
              noteOnStack(data1);
              gMidiVelocity = data2;
              gNoteOnSeq++;
            }
            break;

        case 0x80:      // Note Off
            noteOffStack(data1);
            gNoteOffSeq++;
            break;

        case 0xB0:      // Control Change
            switch (data1)
            {
                case 1: // VIBRATO - mod
                    gMidiVibrato = data2;
                    break;
                case 72: // 72,91 touch Y ///72 amp release
                    gMidiDepth = data2;
                    break;
                case 73: // ECHO - 73 amp atk
                    gMidiEcho = data2;
                    break;
                case 74: // 74,71 touch X 
                    gMidiMod = data2;
                    break;
                case 75: // PORTA SPD - 75 amp decay
                    gMidiPortamento = data2;
                    break;
            }
            break;

        case 0xC0:      // Program Change
            break;

        case 0xE0:      // Pitch Bend
        {
            gMidiPitch = ((int)data2 << 7) | data1;
            gMidiPitch -= 8192;            
            break;
        }
    }
}

void setupI2S()
{
    //i2s_chan_config_t chan_cfg =
        //I2S_CHANNEL_DEFAULT_CONFIG(I2S_NUM_0, I2S_ROLE_MASTER);

    i2s_chan_config_t chan_cfg = {
        .id = I2S_NUM_0,
        .role = I2S_ROLE_MASTER,
        .dma_desc_num = 2,      // fully async, no blocking on audio thread
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
//  Serial.begin(115200);
//     while (!Serial) {
//        delay(10);
//    }
    // Init DSP
    dsp.init((float)SAMPLE_RATE);

    // Parameters — match DLL default preset 0 (confirmed from JS emulator state dump):
    //   portamento=0.5, vowel_sel=0.5, vowel_depth=0.5, feedback=0.8
    dsp.setParameter(0, 0.5f);   // volume
    dsp.setParameter(1, 0.5f);   // vowel_sel
    dsp.setParameter(2, 0.5f);   // portamento (DLL default [esi+0xb0]=0.5)
    dsp.setParameter(3, 0.5f);   // vowel_depth (DLL default [esi+0xc4]=0.5)
    dsp.setParameter(4, 0.8f);   // feedback (DLL default [esi+0xbc]=0.8)

    dsp.triggerResonator(3);
    //dsp.noteOn(58, 100);
    //dsp.noteOn(50, 100);
    dsp.pitchShift(40);
    dsp.force_trigger_ = false;
  
    setupI2S();


    // lcd
    LCD_Init();
    Backlight_Init();
    Set_Backlight(Backlight_MAX*0.8);
    LCD_SetCursor(0, 0, 240, 320);
    LCD_WriteBegin();
    LCD_Write(image, 320*240);//GRB565
    LCD_WriteEnd();
    printf("========begin=======\n");

    uart_driver_install(MIDI_UART, 512, 0, 16, &midiQueue, 0);
uart_config_t cfg = {
    .baud_rate = 31250,
    .data_bits = UART_DATA_8_BITS,
    .parity    = UART_PARITY_DISABLE,
    .stop_bits = UART_STOP_BITS_1,
    .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
    .source_clk = UART_SCLK_DEFAULT
};

uart_param_config(MIDI_UART, &cfg);

uart_set_pin(
    MIDI_UART,
    GPIO_NUM_43,   // TX
    GPIO_NUM_44,   // RX
    UART_PIN_NO_CHANGE,
    UART_PIN_NO_CHANGE);

    
    xTaskCreatePinnedToCore(
        audioTaskStreamFunc,
        "AudioStream",
        8192,
        nullptr,
        configMAX_PRIORITIES - 1,
        &audioTaskStream,
        0      // choose core 0 or 1
    );

    xTaskCreatePinnedToCore(
        resonatorTaskFunc,
        "Resonator",
        4096,
        nullptr,
        configMAX_PRIORITIES - 2,
        &resonatorTask,
        1      // core 1 — off the audio path
    );
    


}

float left[BLOCK_SIZE], right[BLOCK_SIZE];
int32_t samples[BLOCK_SIZE * 2];


void playTestSequence()
{
    vTaskDelay(pdMS_TO_TICKS(1000));

    const uint8_t notes[] = { 60, 64, 67, 72 };  // C E G C
    const int numNotes = sizeof(notes) / sizeof(notes[0]);

    // Each round: 8 notes at a given speed, then pause
    const int speeds_ms[] = { 200, 150, 100, 75, 50, 30, 20, 15, 10, 5 };
    const int numSpeeds = sizeof(speeds_ms) / sizeof(speeds_ms[0]);

    for (int s = 0; s < numSpeeds; s++) {
        int on_ms  = speeds_ms[s];
        int off_ms = speeds_ms[s] / 4;  // 25% gap
        if (off_ms < 1) off_ms = 1;

        printf("=== SPEED: on=%dms off=%dms ===\n", on_ms, off_ms);

        for (int rep = 0; rep < 2; rep++) {
            for (int i = 0; i < numNotes; i++) {
                processMidiEvent(0x90, notes[i], 100);
                vTaskDelay(pdMS_TO_TICKS(on_ms));
                processMidiEvent(0x80, notes[i], 0);
                vTaskDelay(pdMS_TO_TICKS(off_ms));
            }
        }

        // Silence between speed changes
        vTaskDelay(pdMS_TO_TICKS(500));
    }

    printf("=== TEST SEQUENCE END ===\n");
}

void loop()
{
//  static bool tested = false;
//  if (!tested) {
//      tested = true;
//      playTestSequence();
//  }
  vTaskDelay(pdMS_TO_TICKS(1000));
}

void audioTaskStreamFunc(void *arg)
{
    int loopCount = 0;
    float maxPeakL = 0.f, maxPeakR = 0.f;

    while (true) {

      // 1. Drain all pending MIDI bytes (non-blocking)
      uint8_t buf[32];
      int n = uart_read_bytes(MIDI_UART, buf, sizeof(buf), 0);
      for (int i = 0; i < n; i++)
          parser.input(buf[i]);

      // 2. Apply MIDI state to DSP
      bool trigger = false;
      bool noteOnThisLoop = false;

      // Detect note-on via sequence counter (never misses repeated same-note)
      if (prevNoteOnSeq != gNoteOnSeq) {
          prevNoteOnSeq = gNoteOnSeq;
          noteOnThisLoop = true;
          bool fromSilence = !dsp.note_on_;
          dsp.noteOn(gMidiNote, gMidiVelocity);
          if (fromSilence) pendingForceTrigger = true;
          trigger = true;
      }
      // Detect note-off only if no note-on overrode it
      if (prevNoteOffSeq != gNoteOffSeq) {
          prevNoteOffSeq = gNoteOffSeq;
          if (!noteOnThisLoop) {
              if (gMidiNote == 0) {
                  dsp.noteOff(0);
              } else {
                  // Released a note but another is still held — glide back
                  dsp.target_note_ = (float)(gMidiNote - 12);
              }
          }
      }
      if (gMidiPrevMod != gMidiMod) {
          gMidiPrevMod = gMidiMod;
          if (dsp.setParameter(1, gMidiMod / 127.0f))
              trigger = true;
      }
      if (gMidiPrevEcho != gMidiEcho) {
          gMidiPrevEcho = gMidiEcho;
          dsp.setParameter(4, gMidiEcho / 127.0f);  // feedback 0..1
      }
      if (gMidiPrevVibrato != gMidiVibrato) {
          gMidiPrevVibrato = gMidiVibrato;
          dsp.voice_raw_ = gMidiVibrato / 127.0f;   // CC1 mod wheel: vibrato depth/rate
      }
      if (gMidiPrevPortamento != gMidiPortamento) {
          gMidiPrevPortamento = gMidiPortamento;
          dsp.setParameter(2, gMidiPortamento / 127.0f);  // CC75: portamento speed
      }
      if (gMidiPrevDepth != gMidiDepth) {
          gMidiPrevDepth = gMidiDepth;
          dsp.setParameter(3, gMidiDepth / 127.0f);       // CC72: resonator depth
      }
      if (gMidiPrevPitch != gMidiPitch) {
          gMidiPrevPitch = gMidiPitch;
          // ±2 semitones pitch bend range (standard MIDI default)
          dsp.pitch_bend_ = (gMidiPitch / 8192.0f) * 2.0f;
      }


      // Resonator: always async on core 1 (never block audio thread)
      if (trigger) {
          pendingVowelIdx = dsp.p_vowel_sel;
          xTaskNotifyGive(resonatorTask);
      }

      // Swap in completed buffer + deferred force_trigger
      if (resonatorReady) {
          memcpy(dsp.output_buf_, resonatorBuf, sizeof(dsp.output_buf_));
          resonatorReady = false;
          if (pendingForceTrigger) {
              dsp.force_trigger_ = true;
              pendingForceTrigger = false;
          }
      }


      // 3. Render audio
      dsp.process(left, right, BLOCK_SIZE);


      float peakL = 0.f, peakR = 0.f;
      for (int i = 0; i < BLOCK_SIZE; i++) {
        float al = fabsf(left[i]), ar = fabsf(right[i]);
        if (al > peakL) peakL = al;
        if (ar > peakR) peakR = ar;
        samples[2 * i + 0] = (int32_t)(left[i] * 2147483647.0f/2);
        samples[2 * i + 1] = (int32_t)(right[i] * 2147483647.0f/2);
      }
      if (peakL > maxPeakL) maxPeakL = peakL;
      if (peakR > maxPeakR) maxPeakR = peakR;
      size_t written;
      i2s_channel_write(
          tx_chan,
          samples,
          BLOCK_SIZE * 2 * 4,
          &written,
          portMAX_DELAY);


      // (latency printf removed — was causing DMA underruns)

      // Periodic stats (printf removed from hot path to avoid DMA underruns)
      loopCount++;
      if (loopCount >= 5000) {
          loopCount = 0;
          maxPeakL = 0.f;
          maxPeakR = 0.f;
      }
    }
}
