#include <stdio.h>
#include "QVBoxLayout.h"

QVBoxLayout::QVBoxLayout(const char *name) : Layout(name)
{
}

void QVBoxLayout::drawLayout()
{
    int ave_width = surface->w;
    int ave_height = surface->h / count;
    int sx = 0, sy = 0;

//    printf("Draw Vlayout [%s] on (%d, %d), ave size: (%d, %d)\n",
//        name, sx, sy, ave_width, ave_height);

    for (int i = 0; i < count; ++i) {
    	zList[i]->setX(sx);
        zList[i]->setY(sy);
        zList[i]->setWidth(ave_width);
        zList[i]->setHeight(ave_height);
        zList[i]->draw(surface);
        sy += ave_height;
    }
}
