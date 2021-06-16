#include "Viewport.h"

Viewport::Viewport(int width, int height)
        : viewportRect(SDL_Rect{0, 0, width, height}) {
}

SDL_Rect *Viewport::getViewportRect() {
    return &viewportRect;
}
