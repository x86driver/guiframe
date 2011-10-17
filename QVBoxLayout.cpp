#include <stdio.h>
#include "QVBoxLayout.h"

QVBoxLayout::QVBoxLayout(const char *name) : Layout(name)
{
}

void QVBoxLayout::drawLayout()
{
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
