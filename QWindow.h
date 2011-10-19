#ifndef QWINDOW_H
#define QWINDOW_H

#include <SDL.h>
#include "layout.h"

class QWindow {
public:
    QWindow(SDL_Surface *s);
    ~QWindow();
    void setLayout(Layout *layout);
    void show();
    void OnMouseDown(int x, int y);
    void OnMouseUp(int x, int y);
    void redraw();
private:
    Layout *layout;
    SDL_Surface *screen;
    QWindow(const QWindow &);
    void operator=(const QWindow &);
};

#endif
