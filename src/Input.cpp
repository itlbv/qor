#include "Input.h"
#include "Qor.h"
#include "ai/Ai.h"

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
            selectOrClearEntity();
        }
    } else if (sdlEvent.button.button == SDL_BUTTON_RIGHT) {
        assignMoveToToEntity();
    }
}

void Input::selectOrClearEntity() {
    selectedEntity = nullptr;
    for (auto &e : Qor::entities) {
        if (SDL_PointInRect(&mousePos, e->getRenderShape())) {
            selectedEntity = e.get();
        }
    }
}

void Input::assignMoveToToEntity() {
    if (selectedEntity != nullptr) {
        ai::Ai::assignBehaviorToEntity(selectedEntity, "moveTo");
    }
}

int Input::keyDown() {
    if (sdlEvent.type == SDL_KEYDOWN) {
        return sdlEvent.key.keysym.sym;
    }
    return -1;
}
