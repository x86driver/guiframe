#ifndef QWINDOW_H
#define QWINDOW_H

#include "SDL.h"
#include "layout.h"

class QWindow {
public:
    QWindow();
    ~QWindow();
    void setLayout(Layout *layout);
    void show();
private:
    Layout *layout;
    SDL_Surface *screen;
    QWindow(const QWindow &);
    void operator=(const QWindow &);
};

#endif
