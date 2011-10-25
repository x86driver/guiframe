#ifndef BUTTON_H
#define BUTTON_H

#include <SDL.h>
#include "QWidget.h"
#include "QFont.h"
#include "misc.h"
#include "lib/functor.h"
#include "lib/tuple.h"

class QButton : public QWidget {
public:
    typedef std::tuple_element<0, std::tuple<void (QWidget *, void *)> >::type CallbackType;
    QButton(const char *name);
    ~QButton();
    virtual void OnMouseDown(int mx, int my);
    virtual void OnMouseUp(int mx, int my);
    void setClicked(Functor<CallbackType> &cmd, QWidget *widget, void *data);
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
    QFont *caption;
    QWidget *cmd_widget;
    void *cmd_data;
    Functor<CallbackType> cmd;
    NoCommand<CallbackType> nocmd;

    // not implement
    QButton(const QButton &);
    void operator=(const QButton &);
};

#endif
