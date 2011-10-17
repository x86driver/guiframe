#ifndef BUTTON_H
#define BUTTON_H

#include "QWidget.h"

class QButton : public QWidget {
public:
    QButton(const char *name);
protected:
    virtual void drawself(SDL_Surface *s);
};

#endif
