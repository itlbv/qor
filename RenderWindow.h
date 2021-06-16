#ifndef QOR_RENDERWINDOW_H
#define QOR_RENDERWINDOW_H

#include <SDL.h>
#include "Viewport.h"
#include "Entity.h"

class RenderWindow {
private:
    SDL_Window *window;
    SDL_Renderer *renderer;

    SDL_Rect *getEntityRenderShape(Entity *e);

    int worldToScreen(double a);

public:
    RenderWindow(const char *title, int width, int height);

    void updateViewport(Viewport *viewport);

    void startFrame();

    void showFrame();

    void renderEntity(Entity &e);

    ~RenderWindow();
};


#endif //QOR_RENDERWINDOW_H
