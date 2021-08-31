#pragma once

#include <SDL.h>
#include "Viewport.h"
#include "Entity.h"

class RenderWindow {
private:
    SDL_Window *window_;
    SDL_Renderer *renderer_;

    void renderMapGrid();

public:
    RenderWindow(const char *title, int width, int height);

    ~RenderWindow();

    void renderLine(int x1, int y1, int x2, int y2);

    void updateViewport(Viewport *viewport);

    void startFrame();

    void showFrame();

    void renderMap();

    void renderEntity(Entity &e);
};
