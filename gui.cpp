#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "QWidget.h"
#include "QWindow.h"
#include "QButton.h"
#include "QHBoxLayout.h"
#include "QVBoxLayout.h"
#include "text.h"

#if 0
class Window {
public:

    Window() {
        screen = new SDL_Surface;
        screen->w = 480;
        screen->h = 272;
    }

    ~Window() {
        delete screen;
    }

    void setLayout(Layout *layout) {
        this->layout = layout;
    }

    void show() {
        layout->setWidth(screen->w);
        layout->setHeight(screen->h);
        layout->draw(screen);
    }

private:
    Layout *layout;
    SDL_Surface *screen;
};
#endif

int main()
{
    QButton *btn1 = new QButton("btn1");
    QButton *btn2 = new QButton("btn2");
    Text *text1 = new Text("text1");
    Text *text2 = new Text("text2");
    QVBoxLayout *vlayout = new QVBoxLayout("vlayout");
    QHBoxLayout *hlayout = new QHBoxLayout("hlayout");
    QWindow *window = new QWindow;

    hlayout->addLayout(vlayout);
    hlayout->addWidget(btn1);
    hlayout->addWidget(text1);

    vlayout->addWidget(btn2);
    vlayout->addWidget(text2);

    window->setLayout(hlayout);
    window->show();

    delete btn1;
    delete btn2;
    delete text1;
    delete text2;
    delete vlayout;
    delete hlayout;
    delete window;

    return 0;
}
