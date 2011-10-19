#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "QWidget.h"
#include "QWindow.h"
#include "QButton.h"
#include "QHBoxLayout.h"
#include "QVBoxLayout.h"
#include "QFont.h"
#include "platform.h"

int main()
{
    if( -1 == SDL_Init(SDL_INIT_VIDEO) ) {
        printf("Error initializing SDL\n");
        exit(-1);
    }

    atexit(SDL_Quit);

    SDL_Surface *screen = SDL_SetVideoMode(DEFAULT_SCREEN_WIDTH, DEFAULT_SCREEN_HEIGHT, 16,
        SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_HWPALETTE|SDL_HWACCEL|SDL_PREALLOC);
    if (screen == NULL) {
    printf("Error setting video mode!\n");
        exit(-1);
    }

//    QButton *btn1 = new QButton("btn1");
    QFont *font1 = new QFont("Hello world!");
    QButton *btn2 = new QButton("btn2");
    QButton *btn3 = new QButton("btn3");
    QButton *btn4 = new QButton("btn4");
    QButton *btn5 = new QButton("btn5");
    QButton *btn6 = new QButton("btn6");

    QVBoxLayout *vlayout = new QVBoxLayout("vlayout");
    QHBoxLayout *hlayout1 = new QHBoxLayout("hlayout");
    QHBoxLayout *hlayout2 = new QHBoxLayout("hlayout2");

    QWindow *window = new QWindow(screen);

    hlayout1->addWidget(font1);
    hlayout1->addLayout(vlayout);
    hlayout1->addWidget(btn2);

    vlayout->addWidget(btn3);
    vlayout->addLayout(hlayout2);
    vlayout->addWidget(btn4);

    hlayout2->addWidget(btn5);
    hlayout2->addWidget(btn6);

    window->setLayout(hlayout1);
    window->show();

	SDL_Event ev;

//    SDL_ShowCursor(SDL_DISABLE);
    SDL_UpdateRect(screen, 0, 0, 0, 0);
    bool Done = false;

	while (!Done) {
		SDL_Delay(1);
		if( SDL_PollEvent(&ev) == 0 ) {
			continue;
		}
		switch(ev.type)
		{
			case SDL_MOUSEBUTTONDOWN:
				switch(ev.button.button)
				{
					case SDL_BUTTON_LEFT:
						//LMB = true;
                        window->OnMouseDown(ev.motion.x, ev.motion.y);
						//Gui->OnMouseDown(ev.motion.x, ev.motion.y);
						//printf << "LMB Down\n";
						break;
					case SDL_BUTTON_MIDDLE:
						//MMB = true;
						break;
					case SDL_BUTTON_RIGHT:
						//RMB = true;
						break;
					default:
						break;
				}
				break;
			case SDL_MOUSEBUTTONUP:
				switch(ev.button.button)
				{
					case SDL_BUTTON_LEFT:
						//LMB = false;
						//Gui->OnMouseUp(ev.motion.x, ev.motion.y);
                        window->OnMouseUp(ev.motion.x, ev.motion.y);
						//printf << "LMB Up\n";
						break;
					case SDL_BUTTON_MIDDLE:
						//MMB = false;
						break;
					case SDL_BUTTON_RIGHT:
						//RMB = false;
						break;
					default:
						break;
				}
				break;
			case SDL_MOUSEMOTION:
			   //Gui->OnMouseMove(ev.motion.x, ev.motion.y);
				//if(LMB) Gui->Drag(ev.motion.xrel, ev.motion.yrel);
				break;
			case SDL_QUIT:
				//Done = true;
				break;
			case SDL_KEYDOWN:
				switch(ev.key.keysym.sym)
				{
					case SDLK_SPACE:
						Done = true;
						break;
					default:
						break;
				}
			default:
				break;
		}
	}

	return 0;
}

#if 0
int main2()
{
    QButton *btn1 = new QButton("btn1");
    QButton *btn2 = new QButton("btn2");
    Text *text1 = new Text("text1");
    Text *text2 = new Text("text2");
    QVBoxLayout *vlayout = new QVBoxLayout("vlayout");
    QHBoxLayout *hlayout = new QHBoxLayout("hlayout");
    QWindow *window = new QWindow;

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
#endif
