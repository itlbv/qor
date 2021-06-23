#ifndef QOR_INPUT_H
#define QOR_INPUT_H

#include <SDL.h>
#include "Entity.h"

class Input {
private:
    static SDL_Event sdlEvent;
    static SDL_Point mousePos;
    static Entity *selectedEntity;

    static void registerQuit();

    static void updateMousePos();

    static void registerClickOnEntity();

    static void selectOrClearEntity();

    static void assignMoveToToEntity();

    static int keyDown();

public:
    static void processInput();
};


#endif //QOR_INPUT_H
