#include <stddef.h>
#include "QWindow.h"

QWindow::QWindow(SDL_Surface *s) : layout(NULL), screen(s)
{
}

QWindow::~QWindow()
{
    if (screen)
        SDL_FreeSurface(screen);
}

void QWindow::setLayout(Layout *layout) {
    this->layout = layout;
}

void QWindow::show() {
    layout->setWidth(screen->w);
    layout->setHeight(screen->h);
    layout->draw(screen);
}

void QWindow::OnMouseDown(int x, int y)
{
    layout->OnMouseDown(x, y);
    redraw();
}

void QWindow::OnMouseUp(int x, int y)
{
    layout->OnMouseUp(x, y);
    redraw();
}

void QWindow::redraw()
{
//    SDL_FillRect(screen, NULL, 0);
    layout->draw(screen);
//    layout->blit();
    SDL_Flip(screen);
}
