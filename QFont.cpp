#include <SDL_ttf.h>
#include "QFont.h"
#include "misc.h"

#define DEFAULT_FONT "/usr/share/cups/fonts/Monospace"

QFont::QFont(const char *str) : QWidget("QFont"), str(NULL), visible(true)
{
    this->str = strdup(str);
}

QFont::~QFont()
{
    if (str)
        free(str);
}

SDL_Surface *QFont::render()
{
    SDL_Color backcolor = {0xff, 0, 0, 0};
    SDL_Color forecolor = {0, 0, 0xff, 0};

    if ( TTF_Init() < 0 ) {
        fprintf(stderr, "Couldn't initialize TTF: %s\n",SDL_GetError());
        SDL_Quit();
        return NULL;
    }

    TTF_Font *font = TTF_OpenFont(DEFAULT_FONT, 24);
    if ( font == NULL ) {
        fprintf(stderr, "Couldn't load %d pt font from %s: %s\n",
                    24, DEFAULT_FONT, SDL_GetError());
    }

    SDL_Surface *text = TTF_RenderText_Shaded(font, str, forecolor, backcolor);
    if ( text == NULL ) {
        fprintf(stderr, "Couldn't render text: %s\n", SDL_GetError());
        TTF_CloseFont(font);
    }

    TTF_CloseFont(font);

    return text;
}

void QFont::drawself()
{
    if (visible == true) {
        SDL_Surface *text = render();
        SDL_Rect dstrect;
        dstrect.x = 0;
        dstrect.y = 0;
        dstrect.w = text->w;
        dstrect.h = text->h;

        if ( SDL_BlitSurface(text, NULL, surface, &dstrect) < 0 ) {
            fprintf(stderr, "Couldn't blit text to display: %s\n",
                                SDL_GetError());
        }
        SDL_FreeSurface(text);
    } else {
//        printf("I'm invisible!\n");
        SDL_Color backcolor = {0xff, 0, 0, 0};
        SDL_FillRect(surface, NULL, GetCol(surface, backcolor));
    }
}

void QFont::setTextVisible(bool visible)
{
    this->visible = visible;
}

void QFont::OnMouseDown(int mx, int my)
{
}

void QFont::OnMouseUp(int mx, int my)
{
}
