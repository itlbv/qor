#pragma once

#include <SDL.h>

class Viewport {
private:
    SDL_Rect viewportRect;
public:
    Viewport(int width, int height);

    SDL_Rect *getViewportRect();
};
