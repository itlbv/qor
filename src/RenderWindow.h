#pragma once

#include <SDL.h>
#include "Viewport.h"
#include "Entity.h"

class RenderWindow {
private:
    SDL_Window *window_;
    SDL_Renderer *renderer_;

    static SDL_Rect *getEntityRenderShape(Entity *e);

    void renderMapGrid();

    void renderLine(int x1, int y1, int x2, int y2);

public:
    RenderWindow(const char *title, int width, int height);

    ~RenderWindow();

    void updateViewport(Viewport *viewport);

    void startFrame();

    void showFrame();

    void renderEntity(Entity &e);
};
