#ifndef QFONT_H
#define QFONT_H

#include "QWidget.h"

class QFont : public QWidget {
public:
    QFont(const char *str);
    ~QFont();
    void setTextVisible(bool visible);
    SDL_Surface *render();
    virtual void OnMouseDown(int mx, int my);
    virtual void OnMouseUp(int mx, int my);
protected:
    virtual void drawself();
private:
    char *str;
    bool visible;
    QFont(const QFont &);
    void operator=(const QFont &);
};

#endif
