#ifndef QVBOXLAYOUT_H
#define QVBOXLAYOUT_H

#include "layout.h"

class QVBoxLayout : public Layout {
public:
    QVBoxLayout(const char *name);
protected:
    virtual void drawLayout();
};

#endif
