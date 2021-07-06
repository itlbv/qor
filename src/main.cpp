#include <iostream>
#include <SDL.h>
#include "Qor.h"
#include "ai/btree/BehaviorTrees.h"

#define MILLISECONDS_PER_FRAME 16

void initStatic() {
    BehaviorTrees::initBehaviors();
}

int main(int argc, char *argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
        std::cout << "SDL_Init FAILED. Error: " << SDL_GetError() << std::endl;

    initStatic();

    Qor qor;
    unsigned int deltaTime, prevFrameTime = 0;
    while (!Qor::quit) {
        deltaTime += SDL_GetTicks() - prevFrameTime;
        prevFrameTime = SDL_GetTicks();
        if (deltaTime < MILLISECONDS_PER_FRAME)
            continue;

        qor.run(deltaTime);
        deltaTime = 0;
    }

    SDL_Quit();

    return 0;
}
