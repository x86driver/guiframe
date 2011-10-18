#ifndef TEXT_H
#define TEXT_H

#include "QWidget.h"

class Text : public QWidget {
public:
    Text(const char *name);
protected:
    virtual void drawself();
};

#endif
