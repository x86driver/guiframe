#include <string.h>
#include <stdlib.h>
#include "platform.h"
#include "QWidget.h"
#include "layout.h"

QWidget::QWidget(const char *name)
    : bMouseFocus(false), x(0), y(0),
      width(DEFAULT_SCREEN_WIDTH), height(DEFAULT_SCREEN_HEIGHT),
      name(strdup(name)), visible(true), surface(NULL), parent(NULL)
{
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

    SDL_FreeSurface(surface);
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

bool QWidget::CheckMouse(int mx, int my)
{
    if( (mx >= x && mx <= x+width) && (my >= y && my <= y+height) ) {
        return true;
    }
    else {
        return false;
    }
}

char *QWidget::getname()
{
    return name;
}

void QWidget::setVisible(bool visible)
{
    this->visible = visible;
}
