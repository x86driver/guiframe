#include <string.h>
#include <stdlib.h>
#include "platform.h"
#include "QWidget.h"
#include "layout.h"

QWidget::QWidget(const char *name)
    : x(0), y(0),
      width(DEFAULT_SCREEN_WIDTH), height(DEFAULT_SCREEN_HEIGHT),
      name(NULL), surface(NULL), parent(NULL)
{
    this->name = strdup(name);
}

QWidget::~QWidget()
{
    free(name);
    if (surface)
        SDL_FreeSurface(surface);
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

void QWidget::draw(SDL_Surface *parent)
{
	SDL_PixelFormat *fmt = parent->format;
    surface = SDL_CreateRGBSurface( SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_HWPALETTE|SDL_SRCALPHA|SDL_HWACCEL|SDL_PREALLOC, width, height, fmt->BitsPerPixel, fmt->Rmask, fmt->Gmask, fmt->Bmask, fmt->Amask);

    if (surface == NULL) {
        printf("Error creating GuiElement surface\n");
        exit(-1);
    }

    this->parent = parent;
    drawself();
    blit();
}

void QWidget::blit()
{
    SDL_Rect dst;
    dst.x = x;
    dst.y = y;

    if (-1 == SDL_BlitSurface(surface, NULL, parent, &dst )) {
        printf("Error BlitSurface Element > Gui\n");
    }
}
