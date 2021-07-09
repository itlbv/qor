#include <iostream>
#include <SDL.h>
#include "Qor.h"
#include "Logger.h"

#define MILLISECONDS_PER_FRAME 16

int main(int argc, char *argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        Logger::log(std::string("SDL_Init FAILED. Error: ") + SDL_GetError());

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
