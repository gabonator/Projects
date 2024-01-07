// Header search paths: /opt/homebrew/Cellar/sdl2/2.24.0/include/SDL2/
// Library search paths: /opt/homebrew/Cellar/sdl2/2.24.0/lib/
// System header search paths: /opt/homebrew/include/SDL2
// Other linker flags: /opt/homebrew/lib/libSDL2.dylib
// Hardened runtime: Disable library validation

#include <stdint.h>

typedef uint32_t Uint32;
#include <SDL.h>
#include <SDL_render.h>
#include <vector>

#include <string.h>
#include "classes.h"

void onKey(int k, int p);
void onMouse(int e, int x, int y);

class CSdl
{
    enum {
        Width = 240,
        Height = 240
    };
    std::vector< unsigned char > pixels;
    const int pixelSize = 2;

    SDL_Renderer* renderer{nullptr};
    SDL_Texture* texture{nullptr};
    SDL_Window* window{nullptr};
    bool running{true};

public:
    void Init()
    {
        pixels.resize(Width*Height*4);
        SDL_Init( SDL_INIT_EVERYTHING );
        atexit( SDL_Quit );
        
        window = SDL_CreateWindow
        (
         "Cicoparser simulator",
         SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
         Width*pixelSize, Height*pixelSize,
         SDL_WINDOW_SHOWN
         );
        
        renderer = SDL_CreateRenderer
        (
         window,
         -1,
         SDL_RENDERER_ACCELERATED
         );

        texture = SDL_CreateTexture
        (
         renderer,
         SDL_PIXELFORMAT_ARGB8888,
         SDL_TEXTUREACCESS_STREAMING,
         Width, Height
         );
    }
    
    void Blit()
    {
        SDL_SetRenderDrawColor( renderer, 0, 0, 0, SDL_ALPHA_OPAQUE );
        SDL_RenderClear( renderer );
        
        SDL_UpdateTexture
        (
         texture,
         NULL,
         &pixels[0],
         Width * 4
         );
        
        SDL_RenderCopy( renderer, texture, NULL, NULL );
        SDL_RenderPresent( renderer );
    }
    
    bool Loop()
    {
        SDL_Event event;
                
        while( SDL_PollEvent( &event ) )
        {
            if (event.type == SDL_MOUSEBUTTONDOWN)
                onMouse(0, event.motion.x/pixelSize, event.motion.y/pixelSize);
            if (event.type == SDL_MOUSEMOTION)
                onMouse(1, event.motion.x/pixelSize, event.motion.y/pixelSize);
            if (event.type == SDL_MOUSEBUTTONUP)
                onMouse(2, event.motion.x/pixelSize, event.motion.y/pixelSize);
            if (SDL_KEYDOWN == event.type)
                onKey(event.key.keysym.scancode, 1);
            if (SDL_KEYUP == event.type)
                onKey(event.key.keysym.scancode, 0);

            if( ( SDL_QUIT == event.type ) ||
               ( SDL_KEYDOWN == event.type && SDL_SCANCODE_ESCAPE == event.key.keysym.scancode ) )
            {
                running = false;
                break;
            }
        }
        Blit();
        
        //const Uint64 end = SDL_GetPerformanceCounter();
        //const static Uint64 freq = SDL_GetPerformanceFrequency();
        //const double seconds = ( end - start ) / static_cast< double >( freq );
        //std::cout << "Frame time: " << seconds * 1000.0 << "ms" << std::endl;
        if (running)
            SDL_Delay(30/10);
        return running;
    }
    
    void Deinit()
    {
        SDL_DestroyRenderer( renderer );
        SDL_DestroyWindow( window );
        SDL_Quit();
    }
    
    void SetPixel(int x, int y, uint32_t c)
    {
        assert(x >= 0 && x < Width);
        assert(y >= 0 && y < Height);
        
        const unsigned int offset = ( Width * 4 * y ) + x * 4;
        pixels[ offset + 0 ] = (uint8_t)c;
        pixels[ offset + 1 ] = (uint8_t)(c >> 8);
        pixels[ offset + 2 ] = (uint8_t)(c >> 16);
        pixels[ offset + 3 ] = SDL_ALPHA_OPAQUE;
    }

    uint32_t GetPixel(int x, int y)
    {
        assert(x >= 0 && x < Width);
        assert(y >= 0 && y < Height);
        
        const unsigned int offset = ( Width * 4 * y ) + x * 4;
        int b = pixels[ offset + 0 ];
        int g = pixels[ offset + 1 ];
        int r = pixels[ offset + 2 ];
        return r | (g << 8) | (b << 16);
    }

};

CSdl mSdl;



namespace sys
{
  int32_t GetTick()
  {
      struct timespec ts;
      uint32_t theTick = 0U;
      clock_gettime( CLOCK_REALTIME, &ts );
      theTick = (uint32_t) ts.tv_nsec / 1000000;
      theTick += ts.tv_sec * 1000;
      return theTick;
  }
  void DelayMs(int n)
  {
      assert(0);
  }
}

namespace lcd
{
    constexpr int width = 240;
    constexpr int height = 240;
    int fontSize = 17;

    void FillRect(const CRect& rc, uint32_t color)
    {
        if (rc.right > rc.left && rc.bottom > rc.top)
            for (int y=rc.top; y<rc.bottom; y++)
                for (int x=rc.left; x<rc.right; x++)
                    mSdl.SetPixel(x, y, color);
    }

    void Rectangle(const CRect& rc, uint32_t color)
    {
        assert(0);
    }
    void SetFontSize(int size)
    {
        assert(0);
    }
    void DrawText(const CPoint& point, uint32_t front, uint32_t back, const char* msg)
    {
        assert(0);
    }
    void SetPixel(const CPoint& point, uint32_t color)
    {
        assert(0);
    }
    uint32_t GetPixel(const CPoint& point)
    {
        uint32_t color{0};
        assert(0);
        return color;
    }
    void DrawLine(const CPoint& pt1, const CPoint& pt2, uint32_t color)
    {
        assert(0);
    }
    CRect GetTextExtent(const char* msg)
    {
        assert(0);
        return CRect{0, 0, 0, 0};
    }
    uint32_t rgb16to32(uint16_t rgb)
    {
        int r = (((rgb)&0x1f)<<3);
        int g = ((((rgb)>>5)&0x3f)<<2);
        int b = ((((rgb)>>11)&0x1f)<<3);
        return r | (g << 8) | (b << 16);
    }
    void Blit(int bx, int by, int w, int h, uint16_t* data)
    {
        for (int y=by; y<by+h; y++)
            for (int x=bx; x<bx+w; x++)
                mSdl.SetPixel(x, y, rgb16to32(*data++));
    }
}

namespace gpio
{
  void digitalWrite(int i, bool b)
  {
      printf("gpio::digitalWrite(%d, %d)\n", i, b);
  }
}

#include "app.h"
CApp app;

void onKey(int k, int p)
{
    
}
void onMouse(int e, int x, int y)
{
    static bool down = false;
    switch (e)
    {
        case 0: down = true; app.OnTouchBegin({x, y}); return;
        case 1: if (down) app.OnTouchMove({x, y}); return;
        case 2: down = false; app.OnTouchEnd({x, y}); return;
    }
}

int main(int argc, const char * argv[])
{
    mSdl.Init();
    app.Init();
    while (mSdl.Loop())
    {
      app.Do();
    }
    mSdl.Deinit();
    return 0;
}
