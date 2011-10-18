#include "text.h"
#include <stdio.h>

Text::Text(const char *name) : QWidget(name)
{
}

void Text::drawself()
{
    printf("Draw a Text [%s] on (%d, %d), size: (%d, %d).\n",
        name, x, y, width, height);
}
