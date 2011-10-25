#ifndef QFONT_H
#define QFONT_H

#include "QWidget.h"

class QFont : public QWidget {
public:
    QFont(const char *str);
    ~QFont();
    SDL_Surface *render();
    void setfontsize(int size);
    void setbgcolor(uint8_t r, uint8_t g, uint8_t b);
    void setfgcolor(uint8_t r, uint8_t g, uint8_t b);
    virtual void OnMouseDown(int mx, int my);
    virtual void OnMouseUp(int mx, int my);
protected:
    virtual void drawself();
private:
    char *str;
    int fontsize;
    SDL_Color backcolor;
    SDL_Color forecolor;
    QFont(const QFont &);
    void operator=(const QFont &);
};

#endif
