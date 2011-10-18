#ifndef QWIDGET_H
#define QWIDGET_H

#include <SDL.h>

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
    void draw(SDL_Surface *parent);
    void blit();
    virtual void drawself() = 0;
protected:
    int x, y;
    int width, height;
    char *name;
    SDL_Surface *surface, *parent;
private:
    QWidget(const QWidget &);
    void operator=(const QWidget &);
};

#endif
