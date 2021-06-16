#include <iostream>
#include <SDL.h>

int main(int argc, char *argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        std::cout << "SDL_Init FAILED. Error: " << SDL_GetError() << std::endl;

    return 0;
}
