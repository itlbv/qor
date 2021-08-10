#include "Input.h"
#include "Qor.h"
#include "ai/Ai.h"
#include "Util.h"

const Uint8 *Input::keyStates;
SDL_Event Input::sdlEvent;
SDL_Point Input::mousePos;
Mob *Input::selectedMob;

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
            selectOrClearMob();
        }
    } else if (sdlEvent.button.button == SDL_BUTTON_RIGHT) {
        if (selectedMob == nullptr || selectedMob->isDead()) return;
        std::shared_ptr<Mob> clickedMob(nullptr);
        for (const auto &m : Qor::mobs) {
            if (SDL_PointInRect(&mousePos, m->getRenderShape())) {
                clickedMob = m;
            }
        }
        if (clickedMob == nullptr)
            assignMoveToBehavior();
        else assignAttackBehavior(clickedMob);
    }
}

void Input::selectOrClearMob() {
    selectedMob = nullptr;
    for (auto &m : Qor::mobs) {
        if (SDL_PointInRect(&mousePos, m->getRenderShape())) {
            selectedMob = m.get();
        }
    }
}

void Input::assignAttackBehavior(const std::shared_ptr<Mob> &target_mob) {
    Ai::assignAttackBehaviorToMob(*selectedMob, target_mob);
}

void Input::assignMoveToBehavior() {
    Ai::assignMoveToBehaviorToMob(*selectedMob,
                                  util::screenToWorld(mousePos.x),
                                  util::screenToWorld(mousePos.y));
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
