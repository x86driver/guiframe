#ifndef QHBOXLAYOUT_H
#define QHBOXLAYOUT_H

#include "layout.h"

class QHBoxLayout : public Layout {
public:
    QHBoxLayout(const char *name);
protected:
    virtual void drawLayout();
};

#endif
