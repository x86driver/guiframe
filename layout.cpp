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

void Layout::drawself(SDL_Surface *s)
{
    drawLayout();
}

