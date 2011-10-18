#include <stdio.h>
#include "misc.h"
#include "QButton.h"

QButton::QButton(const char *name) : QWidget(name), Col()
{
    // set colors
    Col.Border.r = 0x00; Col.Border.g = 0x00; Col.Border.b = 0x00;
    Col.CapBkg.r = 0xF0; Col.CapBkg.g = 0xA0; Col.CapBkg.b = 0x00;
    Col.CapTxt.r = 0xff; Col.CapTxt.g = 0xff; Col.CapTxt.b = 0xff;
    Col.CliBkg.r = 0xC0; Col.CliBkg.g = 0xC0; Col.CliBkg.b = 0xC0;
    Col.Light3D.r = 0xff; Col.Light3D.g = 0xff; Col.Light3D.b = 0xff;
    Col.Dim3D.r = 0x40; Col.Dim3D.g = 0x40; Col.Dim3D.b = 0x40;
}

void QButton::drawself()
{
    printf("Draw a Button [%s] on (%d, %d), size: (%d, %d).\n",
        name, x, y, width, height);
    DrawBtnUp();
}

void QButton::DrawBtnUp()
{
    int b = 1;

    SDL_SetAlpha(surface, SDL_SRCALPHA, 255);

    SDL_Rect tl = {0, 0, width, height};
    SDL_Rect br = {b, b, width-b, height-b};
    SDL_Rect bk = {b, b, width-2*b, height-2*b};

    SDL_FillRect(surface, &tl, GetCol(surface, Col.Light3D));
    SDL_FillRect(surface, &br, GetCol(surface, Col.Dim3D));
    SDL_FillRect(surface, &bk, GetCol(surface, Col.CliBkg));
}

void QButton::DrawBtnDown()
{
    int b = 1;

    SDL_Rect tl = {0, 0, width, height};
    SDL_Rect br = {b, b, width-b, height-b};
    SDL_Rect bk = {b, b, width-2*b, height-2*b};

    SDL_FillRect(surface, &tl, GetCol(surface, Col.Dim3D));
    SDL_FillRect(surface, &br, GetCol(surface, Col.Light3D));
    SDL_FillRect(surface, &bk, GetCol(surface, Col.CliBkg));
}

