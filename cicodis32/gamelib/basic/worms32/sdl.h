//
//  sdl.h
//  cicodis32
//
//  Created by Gabriel Valky on 04/07/2025.
//

// Other linker flags: /opt/homebrew/lib/libSDL2.dylib
// System header search paths: /opt/homebrew/include/SDL2

typedef uint32_t Uint32;
#include <SDL.h>
#include <SDL_render.h>
#include <vector>

void onKey(int k, int p);

class CSdl
{
    enum {
        Width = 320,
        Height = 200
    };
    std::vector< unsigned char > pixels;
    const int pixelSize = 2;

    SDL_Renderer* renderer{nullptr};
    SDL_Texture* texture{nullptr};
    SDL_Window* window{nullptr};
    bool running{true};
    int lastKey{0};


public:
    void Init()
    {
        nanosleep((const struct timespec[]){{0, 500000000L}}, NULL);
        
        pixels.resize(Width*Height*4);
        SDL_Init( SDL_INIT_EVERYTHING );
        atexit( SDL_Quit );
        
        window = SDL_CreateWindow
        (
         "Cicoparser32 simulator",
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
         SDL_PIXELFORMAT_ABGR8888,
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
    
    void Loop(bool noDelay = false)
    {
        SDL_Event event;
                
        while( SDL_PollEvent( &event ) )
        {
            if (SDL_KEYDOWN == event.type)
            {
                lastKey = event.key.keysym.scancode;
                onKey(event.key.keysym.scancode, 1);
            }
            
            if (SDL_KEYUP == event.type)
            {
                lastKey = event.key.keysym.scancode;
                onKey(event.key.keysym.scancode, 0);
            }

            if( ( SDL_QUIT == event.type ) ||
               ( SDL_KEYDOWN == event.type && SDL_SCANCODE_ESCAPE == event.key.keysym.scancode ) )
            {
                running = false;
                break;
            }
        }
        if (noDelay)
            return;
        Blit();
        
        //const Uint64 end = SDL_GetPerformanceCounter();
        //const static Uint64 freq = SDL_GetPerformanceFrequency();
        //const double seconds = ( end - start ) / static_cast< double >( freq );
        //std::cout << "Frame time: " << seconds * 1000.0 << "ms" << std::endl;
        if (running)
            SDL_Delay(30);

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


