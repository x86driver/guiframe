#include "QHBoxLayout.h"
#include <stdio.h>

QHBoxLayout::QHBoxLayout(const char *name) : Layout(name)
{
}

void QHBoxLayout::drawLayout()
{
    int ave_width = width / count;
    int ave_height = height;
    int sx = 0, sy = 0;

//    printf("Draw Hlayout [%s] on (%d, %d), ave size: (%d, %d)\n",
//        name, sx, sy, ave_width, ave_height);

    for (int i = 0; i < count; ++i) {
        zList[i]->setX(sx);
        zList[i]->setY(sy);
        zList[i]->setWidth(ave_width);
        zList[i]->setHeight(ave_height);
        zList[i]->draw(surface);
        sx += ave_width;
    }
}
