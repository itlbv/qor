#ifndef QOR_INPUT_H
#define QOR_INPUT_H

#include <SDL.h>
#include "Entity.h"

class Input {
private:
    static const Uint8 *keyStates;
    static SDL_Event sdlEvent;
    static SDL_Point mousePos;
    static Entity *selectedEntity;

    static void registerQuit();

    static void registerMousePos();

    static void registerClickOnEntity();

    static void registerPlayerVelocity();

    static void selectOrClearEntity();

    static void assignMoveToBehavior();

    static void assignAttackBehavior(std::shared_ptr<Entity> target_entity);

public:
    static void processInput();
};


#endif //QOR_INPUT_H
