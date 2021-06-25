#include "Input.h"
#include "Qor.h"
#include "ai/Ai.h"
#include "Util.h"

const Uint8 *Input::keyStates;

SDL_Event Input::sdlEvent;
SDL_Point Input::mousePos;
Entity *Input::selectedEntity;
Vect Input::player_velocity{};

void Input::processInput() {
    while (SDL_PollEvent(&sdlEvent)) {
        keyStates = SDL_GetKeyboardState(nullptr);

        registerQuit();
        registerMousePos();
        registerClickOnEntity();
        registerPlayerVelocity();
    }
}

void Input::registerQuit() {
    if (sdlEvent.type == SDL_QUIT || keyStates[SDL_SCANCODE_ESCAPE])
        Qor::quit = true;
}

void Input::registerMousePos() {
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
        selectedEntity->setDest(util::screenToWorld(mousePos.x), util::screenToWorld(mousePos.y));
    }
}

void Input::registerPlayerVelocity() {
    player_velocity.zero();

    if (keyStates[SDL_SCANCODE_UP])
        player_velocity.add(0, -0.1);
    if (keyStates[SDL_SCANCODE_DOWN])
        player_velocity.add(0, 0.1);
    if (keyStates[SDL_SCANCODE_LEFT])
        player_velocity.add(-0.1, 0);
    if (keyStates[SDL_SCANCODE_RIGHT])
        player_velocity.add(0.1, 0);

    Qor::player->velocity_player_.set(player_velocity);
}
