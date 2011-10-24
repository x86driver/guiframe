#ifndef MISC_H
#define MISC_H

#include <SDL.h>

typedef struct {
    SDL_Color Border;
    SDL_Color CapBkg;
    SDL_Color CapTxt;
    SDL_Color CliBkg;
    SDL_Color Light3D;
    SDL_Color Dim3D;
} TColors;
#define GetCol(s, col) (SDL_MapRGB(s->format, col.r, col.g, col.b))

#undef DEBUG

#ifdef DEBUG
    #define dbg(format, arg...) printf(format, ##arg)
#else
    #define dbg(format, arg...) do {} while(0)
#endif

#endif
