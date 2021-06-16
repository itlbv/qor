#include "Input.h"
#include "Qor.h"

SDL_Event Input::sdlEvent;

void Input::processInput() {
    while (SDL_PollEvent(&sdlEvent)) {
        if (sdlEvent.type == SDL_QUIT) {
            Qor::quit = true;
        }
    }
}
