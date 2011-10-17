#ifndef QWIDGET_H
#define QWIDGET_H

#include "SDL.h"

class Layout;

class QWidget {
public:
    QWidget(const char *name);
    virtual ~QWidget();
    void setX(int x);
    void setY(int y);
    void setWidth(int width);
    void setHeight(int height);
    void show();
    virtual void draw(SDL_Surface *s);
protected:
    int x, y;
    int width, height;
    char *name;
    SDL_Surface *surface;
    virtual void drawself(SDL_Surface *s) = 0;
private:
    QWidget(const QWidget &);
    void operator=(const QWidget &);
};

#endif
