#include <stdio.h>

struct SDL_Surface {
    int w, h;
};

class Widget {
public:
    Widget() : surface(NULL) {}
    virtual ~Widget() { if (surface) delete surface; }
    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }
    void setWidth(int width) { this->width = width; }
    void setHeight(int height) { this->height = height; }
    void draw(SDL_Surface *s) {
        surface = new SDL_Surface;
        surface->w = s->w;
        surface->h = s->h;
        drawself(surface);
    }
protected:
    int x, y;
    int width, height;
    SDL_Surface *surface;
private:
    virtual void drawself(SDL_Surface *s) = 0;
};

class Button : public Widget {
private:
    virtual void drawself(SDL_Surface *s) {
        printf("Draw a Button on (%d, %d), size: (%d, %d).\n",
            x, y, width, height);
    }
};

class Text : public Widget {
private:
    virtual void drawself(SDL_Surface *s) {
        printf("Draw a Text on (%d, %d), size: (%d, %d).\n",
            x, y, width, height);
    }
};

class Layout : public Widget {
public:

    Layout() : wcount(0), lcount(0), surface(NULL) {
    }

    virtual ~Layout() {
        if (surface)
            delete surface;
    }

    void addWidget(Widget *widget) {
        zList[wcount++] = widget;
    }

    void addLayout(Layout *layout) {
        this->layout[lcount++] = layout;
    }

    virtual void drawself(SDL_Surface *s) {
        surface = new SDL_Surface;
        surface->w = s->w;
        surface->h = s->h;

        drawLayout();
    }

    virtual void drawLayout() = 0;

protected:
    int wcount, lcount;
    int width, height;
    Widget *zList[256];
    Layout *layout[256];
    SDL_Surface *surface;
};

class VBoxLayout : public Layout {
public:

    virtual void drawLayout() {
        int ave_width = width;
        int ave_height = height / wcount;
        int x = 0, y = 0;

/*
        for (int i = 0; i < lcount; ++i) {
            layout[i]->drawself(surface);
        }
*/

        for (int i = 0; i < wcount; ++i) {
            zList[i]->setX(x);
            zList[i]->setY(y);
            zList[i]->setWidth(ave_width);
            zList[i]->setHeight(ave_height);
            zList[i]->draw(surface);
            y += ave_height;
        }
    }
};

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
        layout->draw(screen);
    }

private:
    Layout *layout;
    SDL_Surface *screen;
};

int main()
{
    Button *btn = new Button;
    Text *text = new Text;
    VBoxLayout *layout = new VBoxLayout;
    Window *window = new Window;

    layout->addWidget(btn);
    layout->addWidget(text);

    window->setLayout(layout);
    window->show();

    return 0;
}
