#ifndef BUTTON_H
#define BUTTON_H

#include <SDL.h>
#include "QWidget.h"
#include "misc.h"

class QButton : public QWidget {
public:
    QButton(const char *name);
    virtual void OnMouseDown(int mx, int my);
    virtual void OnMouseUp(int mx, int my);
protected:
    virtual void drawself();
private:
    TColors Col;
    void  DrawBtnUp();
    void  DrawBtnDown();
    enum Status {
        BUTTON_UP,
        BUTTON_DOWN
    } status;
};

#endif
