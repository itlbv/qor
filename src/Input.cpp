#include "Input.h"
#include "Qor.h"

SDL_Event Input::sdlEvent;
SDL_Point Input::mousePos;
Entity *Input::selectedEntity;

void Input::processInput() {
    while (SDL_PollEvent(&sdlEvent)) {
        registerQuit();
        updateMousePos();
        registerClickOnEntity();
    }
}

void Input::registerQuit() {
    if (sdlEvent.type == SDL_QUIT || keyDown() == SDLK_ESCAPE) {
        Qor::quit = true;
    }
}

void Input::updateMousePos() {
    if (sdlEvent.type == SDL_MOUSEMOTION) {
        mousePos = {sdlEvent.motion.x, sdlEvent.motion.y};
    }
}

void Input::registerClickOnEntity() {
    if (sdlEvent.type == SDL_MOUSEBUTTONDOWN) {
        if (sdlEvent.button.button == SDL_BUTTON_LEFT) {
            for (auto &e : Qor::entities) {
                if (SDL_PointInRect(&mousePos, e->getRenderShape())) {
                    selectedEntity = e.get();
                }
            }
        } else if (sdlEvent.button.button == SDL_BUTTON_RIGHT) {
            if (selectedEntity != nullptr) {
                // move entity
            }
        }
    }
}

int Input::keyDown() {
    if (sdlEvent.type == SDL_KEYDOWN) {
        return sdlEvent.key.keysym.sym;
    }
    return -1;
}
