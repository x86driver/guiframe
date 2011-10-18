#include <stddef.h>
#include "QWindow.h"

QWindow::QWindow(SDL_Surface *s) : layout(NULL), screen(s)
{
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
