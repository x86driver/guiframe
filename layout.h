#ifndef LAYOUT_H
#define LAYOUT_H

#include "QWidget.h"

class Layout : public QWidget {
public:
    Layout(const char *name);
    void addWidget(QWidget *widget);
    void addLayout(Layout *layout);
    virtual void OnMouseDown(int mx, int my);
    bool CheckMouse(int mx, int my);
protected:
    int count;
    QWidget *zList[256];

    virtual void drawself();
    virtual void drawLayout() = 0;
private:
    Layout(const Layout &);
    void operator=(const Layout &);
};

#endif
