#include <iostream>
#include <SDL.h>
#include "Qor.h"

int main(int argc, char *argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        std::cout << "SDL_Init FAILED. Error: " << SDL_GetError() << std::endl;

    Qor qor;
    while (true) {
        qor.run();
    }

    SDL_Quit();

    return 0;
}
