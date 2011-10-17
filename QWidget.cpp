#include <string.h>
#include <stdlib.h>
#include "platform.h"
#include "QWidget.h"
#include "layout.h"

QWidget::QWidget(const char *name)
    : x(0), y(0),
      width(DEFAULT_SCREEN_WIDTH), height(DEFAULT_SCREEN_HEIGHT),
      name(NULL), surface(NULL)
{
    this->name = strdup(name);
}

QWidget::~QWidget()
{
    if (surface)
        delete surface;
    free(name);
}

void QWidget::setX(int x)
{
    this->x = x;
}

void QWidget::setY(int y)
{
    this->y = y;
}

void QWidget::setWidth(int width)
{
    this->width = width;
}

void QWidget::setHeight(int height)
{
    this->height = height;
}

void QWidget::draw(SDL_Surface *s)
{
    surface = new SDL_Surface;
    surface->w = width;
    surface->h = height;
    drawself(surface);
}
