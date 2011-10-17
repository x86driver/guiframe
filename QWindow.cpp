#include <stddef.h>
#include "QWindow.h"

QWindow::QWindow() : layout(NULL), screen(NULL)
{
    screen = new SDL_Surface;
    screen->w = 480;
    screen->h = 272;
}

QWindow::~QWindow() {
    delete screen;
}

void QWindow::setLayout(Layout *layout) {
    this->layout = layout;
}

void QWindow::show() {
    layout->setWidth(screen->w);
    layout->setHeight(screen->h);
    layout->draw(screen);
}
