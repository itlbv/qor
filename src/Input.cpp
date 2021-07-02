#include "Input.h"
#include "Qor.h"
#include "ai/Ai.h"
#include "Util.h"

const Uint8 *Input::keyStates;
SDL_Event Input::sdlEvent;
SDL_Point Input::mousePos;
Entity *Input::selectedEntity;

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
        std::shared_ptr<Entity> clickedEntity(nullptr);
        for (const auto &e : Qor::entities) {
            if (SDL_PointInRect(&mousePos, e->getRenderShape())) {
                clickedEntity = e;
            }
        }
        if (clickedEntity == nullptr)
            assignMoveToBehavior();
        else assignAttackBehavior(clickedEntity);
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

void Input::assignAttackBehavior(std::shared_ptr<Entity> target_entity) {
    if (selectedEntity != nullptr) {
        ai::Ai::assignBehaviorToEntity(selectedEntity, "attack");
        selectedEntity->setTarget(target_entity);
        selectedEntity->setDest(util::screenToWorld(mousePos.x), util::screenToWorld(mousePos.y));
    }
}

void Input::assignMoveToBehavior() {
    if (selectedEntity != nullptr) {
        ai::Ai::assignBehaviorToEntity(selectedEntity, "moveTo");
        selectedEntity->setDest(util::screenToWorld(mousePos.x), util::screenToWorld(mousePos.y));
    }
}

void Input::registerPlayerVelocity() {
    Vect velocity{};

    if (keyStates[SDL_SCANCODE_UP])
        velocity.y = -1;
    if (keyStates[SDL_SCANCODE_DOWN])
        velocity.y = 1;
    if (keyStates[SDL_SCANCODE_LEFT])
        velocity.x = -1;
    if (keyStates[SDL_SCANCODE_RIGHT])
        velocity.x = 1;

    velocity.normalize();
    velocity.setLength(velocity.length() * Qor::delta * Player::Speed);

    Qor::player->setVelocity(velocity);
}
