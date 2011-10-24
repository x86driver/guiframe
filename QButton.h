#ifndef BUTTON_H
#define BUTTON_H

#include <SDL.h>
#include "QWidget.h"
#include "misc.h"
#include "lib/functor.h"

class QButton : public QWidget {
public:
    QButton(const char *name);
    virtual void OnMouseDown(int mx, int my);
    virtual void OnMouseUp(int mx, int my);
    void setClicked(Functor<void (QWidget*)> &cmd, QWidget *widget);
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
    QWidget *cmd_widget;
    Functor<void (QWidget*)> cmd;
    NoCommand<void (QWidget*)> nocmd;
    QButton(const QButton &);
    void operator=(const QButton &);
};

#endif
