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
            zList[i]->bMouseFocus = true;
            zList[i]->OnMouseDown(mx, my);
        }
    }
}

void Layout::OnMouseUp(int mx, int my)
{
    for (int i = 0; i < count; ++i) {
        if (zList[i]->bMouseFocus) {
            zList[i]->bMouseFocus = false;
            zList[i]->OnMouseUp(mx, my);
        }
    }
}
