#include <stdio.h>
#include "QButton.h"

QButton::QButton(const char *name) : QWidget(name)
{
}

void QButton::drawself(SDL_Surface *s)
{
    printf("Draw a Button [%s] on (%d, %d), size: (%d, %d).\n",
        name, x, y, width, height);
}
