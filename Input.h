#ifndef QOR_INPUT_H
#define QOR_INPUT_H

#include <SDL.h>

class Input {
private:
    static SDL_Event sdlEvent;
public:
    static void processInput();
};


#endif //QOR_INPUT_H
