#include "Timer.h"

#include <SDL.h>

void Timer::start() {
    timeStarted = SDL_GetTicks();
}

unsigned int Timer::getTimePassed() const {
    return SDL_GetTicks() - timeStarted;
}
