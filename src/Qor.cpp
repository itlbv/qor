#include <memory>
#include "Qor.h"
#include "Input.h"

#define SCREEN_WIDTH_PXL 1200
#define SCREEN_HEIGHT_PXL 900

bool Qor::quit = false;
double Qor::delta;
std::vector<std::unique_ptr<Resource>> Qor::resources;
std::vector<std::shared_ptr<Mob>> Qor::mobs;

std::unique_ptr<Player> Qor::player = std::make_unique<Player>(15, 15);

Qor::Qor()
        : window(RenderWindow("Qor", SCREEN_WIDTH_PXL, SCREEN_HEIGHT_PXL)),
          viewport(Viewport(SCREEN_WIDTH_PXL, SCREEN_HEIGHT_PXL)) {
    createMobs();
    createResources();
}

void Qor::run(unsigned int deltaTime) {
    Qor::delta = (double) deltaTime / 1000;

    Input::processInput();

    player->update();
    updateMobs();

    window.startFrame();
    renderResources();
    renderMobs();
    renderPlayer();
    window.showFrame();
}

void Qor::createResources() {
    resources.push_back(std::make_unique<Resource>(10, 3, 3));
    resources.push_back(std::make_unique<Resource>(11, 4, 8));
    resources.push_back(std::make_unique<Resource>(12, 7, 7));
}

void Qor::createMobs() {
    mobs.push_back(std::make_shared<Mob>(1, 1, 1));
    mobs.push_back(std::make_shared<Mob>(2, 5, 5));
}

void Qor::updateMobs() {
    for (auto &e : mobs) {
        e->update();
    }
}

void Qor::renderResources() {
    for (auto &r : resources) {
        window.renderEntity(*r);
    }
}

void Qor::renderMobs() {
    for (auto &m : mobs) {
        window.renderEntity(*m);
    }
}

void Qor::renderPlayer() {
    window.renderEntity(*player);
}
