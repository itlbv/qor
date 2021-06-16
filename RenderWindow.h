#ifndef QOR_RENDERWINDOW_H
#define QOR_RENDERWINDOW_H

#include <SDL.h>
#include "Viewport.h"

class RenderWindow {
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
public:
    RenderWindow(const char *title, int width, int height);

    void updateViewport(Viewport *viewport);

    void startFrame();

    void showFrame();

    ~RenderWindow();
};


#endif //QOR_RENDERWINDOW_H
