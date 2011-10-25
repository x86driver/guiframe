#include <stdio.h>
#include "misc.h"
#include "QButton.h"

QButton::QButton(const char *name)
    : QWidget(name), Col(), status(BUTTON_UP),
      caption(new QFont(name)), cmd_widget(NULL), cmd_data(NULL), cmd(nocmd), nocmd()
{
    // set colors
    Col.Border.r = 0x00; Col.Border.g = 0x00; Col.Border.b = 0x00;
    Col.CapBkg.r = 0xF0; Col.CapBkg.g = 0xA0; Col.CapBkg.b = 0x00;
    Col.CapTxt.r = 0xff; Col.CapTxt.g = 0xff; Col.CapTxt.b = 0xff;
    Col.CliBkg.r = 0xC0; Col.CliBkg.g = 0xC0; Col.CliBkg.b = 0xC0;
    Col.Light3D.r = 0xff; Col.Light3D.g = 0xff; Col.Light3D.b = 0xff;
    Col.Dim3D.r = 0x40; Col.Dim3D.g = 0x40; Col.Dim3D.b = 0x40;
}

QButton::~QButton()
{
    if (caption)
        delete caption;
}

void QButton::drawself()
{
    dbg("Draw a Button [%s] on (%d, %d), size: (%d, %d).\n",
        name, x, y, width, this->height);
    if (status == BUTTON_UP)
        DrawBtnUp();
    else
        DrawBtnDown();

    SDL_Surface *t = caption->render();
    SDL_Rect dst;
    dst.x = (width - t->w) / 2;
    dst.y = (height - t->h) / 2;
    SDL_BlitSurface(t, NULL, surface, &dst);
    SDL_FreeSurface(t);
}

void QButton::DrawBtnUp()
{
    Sint16 b = 1;

    SDL_SetAlpha(surface, SDL_SRCALPHA, 255);

    SDL_Rect tl = {0, 0, static_cast<Uint16>(width), static_cast<Uint16>(height)};
    SDL_Rect br = {b, b, static_cast<Uint16>(width-b), static_cast<Uint16>(height-b)};
    SDL_Rect bk = {b, b, static_cast<Uint16>(width-2*b), static_cast<Uint16>(height-2*b)};

    SDL_FillRect(surface, &tl, GetCol(surface, Col.Light3D));
    SDL_FillRect(surface, &br, GetCol(surface, Col.Dim3D));
    SDL_FillRect(surface, &bk, GetCol(surface, Col.CliBkg));
}

void QButton::DrawBtnDown()
{
    Sint16 b = 1;

    SDL_Rect tl = {0, 0, static_cast<Uint16>(width), static_cast<Uint16>(height)};
    SDL_Rect br = {b, b, static_cast<Uint16>(width-b), static_cast<Uint16>(height-b)};
    SDL_Rect bk = {b, b, static_cast<Uint16>(width-2*b), static_cast<Uint16>(height-2*b)};

    SDL_FillRect(surface, &tl, GetCol(surface, Col.Dim3D));
    SDL_FillRect(surface, &br, GetCol(surface, Col.Light3D));
    SDL_FillRect(surface, &bk, GetCol(surface, Col.CliBkg));
}

void QButton::OnMouseDown(int mx, int my)
{
    dbg("Button [%s] is pressed!\n", name);
    status = BUTTON_DOWN;
    cmd(cmd_widget, cmd_data);
}

void QButton::OnMouseUp(int mx, int my)
{
    dbg("Button [%s] is pressed!\n", name);
    status = BUTTON_UP;
}

void QButton::setClicked(Functor<CallbackType> &cmd, QWidget *widget, void *data)
{
    this->cmd = cmd;
    this->cmd_widget = widget;
    this->cmd_data = data;
}
