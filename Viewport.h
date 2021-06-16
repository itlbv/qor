#ifndef QOR_VIEWPORT_H
#define QOR_VIEWPORT_H


#include <SDL.h>

class Viewport {
private:
    SDL_Rect viewportRect;
public:
    Viewport(int width, int height);
};


#endif //QOR_VIEWPORT_H
