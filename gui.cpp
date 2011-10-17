#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct SDL_Surface {
    int w, h;
};

class Widget {
public:
    Widget(const char *name) : surface(NULL) { this->name = strdup(name); }
    virtual ~Widget() { if (surface) delete surface; free(name); }
    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }
    void setWidth(int width) { this->width = width; }
    void setHeight(int height) { this->height = height; }
    void draw(SDL_Surface *s) {
        surface = new SDL_Surface;
        surface->w = width;
        surface->h = height;
        drawself(surface);
    }
protected:
    int x, y;
    int width, height;
    char *name;
    SDL_Surface *surface;
private:
    virtual void drawself(SDL_Surface *s) = 0;
};

class Button : public Widget {
public:
    Button(const char *name) : Widget(name) {}
private:
    virtual void drawself(SDL_Surface *s) {
        printf("Draw a Button [%s] on (%d, %d), size: (%d, %d).\n",
            name, x, y, width, height);
    }
};

class Text : public Widget {
public:
    Text(const char *name) : Widget(name) {}
private:
    virtual void drawself(SDL_Surface *s) {
        printf("Draw a Text [%s] on (%d, %d), size: (%d, %d).\n",
            name, x, y, width, height);
    }
};

class Layout : public Widget {
public:

    Layout(const char *name) : Widget(name), count(0) {
    }

    void addWidget(Widget *widget) {
        zList[count++] = widget;
    }

    void addLayout(Layout *layout) {
        zList[count++] = layout;
    }

    virtual void drawself(SDL_Surface *s) {
        drawLayout();
    }

    virtual void drawLayout() = 0;

protected:
    int count;
    Widget *zList[256];
};

class HBoxLayout : public Layout {
public:
    HBoxLayout(const char *name) : Layout(name) {}
    virtual void drawLayout() {
        int ave_width = width / count;
        int ave_height = height;

        printf("Draw Hlayout [%s] on (%d, %d), ave size: (%d, %d)\n",
            name, x, y, ave_width, ave_height);

        for (int i = 0; i < count; ++i) {
            zList[i]->setX(x);
            zList[i]->setY(y);
            zList[i]->setWidth(ave_width);
            zList[i]->setHeight(ave_height);
            zList[i]->draw(surface);
            x += ave_width;
        }
    }
};

class VBoxLayout : public Layout {
public:
    VBoxLayout(const char *name) : Layout(name) {}
    virtual void drawLayout() {
        int ave_width = surface->w;
        int ave_height = surface->h / count;

        printf("Draw Vlayout [%s] on (%d, %d), ave size: (%d, %d)\n",
            name, x, y, ave_width, ave_height);

        for (int i = 0; i < count; ++i) {
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
        layout->setWidth(screen->w);
        layout->setHeight(screen->h);
        layout->draw(screen);
    }

private:
    Layout *layout;
    SDL_Surface *screen;
};

int main()
{
    Button *btn1 = new Button("btn1");
    Button *btn2 = new Button("btn2");
    Text *text1 = new Text("text1");
    Text *text2 = new Text("text2");
    VBoxLayout *vlayout = new VBoxLayout("vlayout");
    HBoxLayout *hlayout = new HBoxLayout("hlayout");
    Window *window = new Window;

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
