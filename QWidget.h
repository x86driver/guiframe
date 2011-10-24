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
    char *getname();
    virtual bool CheckMouse(int mx, int my);
    virtual void OnMouseDown(int mx, int my) = 0;
    virtual void OnMouseUp(int mx, int my) = 0;
    virtual void drawself() = 0;
    bool bMouseFocus;

protected:
    int x, y;
    int width, height;
    char *name;
    SDL_Surface *surface, *parent;

private:
    QWidget(const QWidget &);
    void operator=(const QWidget &);
};

template <typename Signature>
class NoCommand;

template <typename R, typename... Args>
class NoCommand<R (Args...)> {
public:
    R operator()(Args...) {
    }
};

#endif
