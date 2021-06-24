#ifndef QOR_RENDERWINDOW_H
#define QOR_RENDERWINDOW_H

#include <SDL.h>
#include "Viewport.h"
#include "Entity.h"

class RenderWindow {
private:
    SDL_Window *window;
    SDL_Renderer *renderer;

    static SDL_Rect *getEntityRenderShape(Entity *e);
public:
    RenderWindow(const char *title, int width, int height);

    ~RenderWindow();

    void updateViewport(Viewport *viewport);

    void startFrame();

    void showFrame();

    void renderEntity(Entity &e);
};


#endif //QOR_RENDERWINDOW_H
