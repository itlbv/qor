#pragma once

#include <SDL.h>
#include "Mob.h"

class Input {
private:
    static const Uint8 *keyStates;
    static SDL_Event sdlEvent;
    static SDL_Point mousePos;
    static Mob *selectedMob;

    static void registerQuit();

    static void registerMousePos();

    static void registerClickOnEntity();

    static void registerPlayerVelocity();

    static void selectOrClearMob();

    static void assignMoveToBehavior();

    static void assignAttackBehavior(const std::shared_ptr<Mob> &target_mob);

public:
    static void processInput();
};
