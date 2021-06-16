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
    if (sdlEvent.type == SDL_QUIT) {
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
            for (Entity &e : Qor::entities) {
                if (SDL_PointInRect(&mousePos, e.getRenderShape())) {
                    selectedEntity = &e;
                }
            }
        } else if (sdlEvent.button.button == SDL_BUTTON_RIGHT) {
            if (selectedEntity != nullptr) {
                // move entity
            }
        }
    }
}
