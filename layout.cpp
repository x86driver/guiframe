#include "layout.h"

Layout::Layout(const char *name) : QWidget(name), count(0)
{
}

void Layout::addWidget(QWidget *widget)
{
    zList[count++] = widget;
}

void Layout::addLayout(Layout *layout)
{
    zList[count++] = layout;
}

void Layout::drawself()
{
    drawLayout();
}

void Layout::OnMouseDown(int mx, int my)
{
    mx -= this->x;
    my -= this->y;

    for (int i = 0; i < count; ++i) {
        if (zList[i]->CheckMouse(mx, my) == true) {
            zList[i]->OnMouseDown(mx, my);
        }
    }
}

// 這裡是否一定要傳回 true, 或者可以直接用 QWidget 的 CheckMouse
bool Layout::CheckMouse(int mx, int my)
{
    return true;
}
