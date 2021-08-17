#include <memory>
#include "Qor.h"
#include "Input.h"

const int Qor::SCREEN_WIDTH_PXL = 1200;
const int Qor::SCREEN_HEIGHT_PXL = 900;
const int Qor::MAP_SIZE = 25;

bool Qor::quit = false;
double Qor::delta;
std::unique_ptr<Map> Qor::map;
std::vector<std::shared_ptr<Item>> Qor::items;
std::vector<std::shared_ptr<Mob>> Qor::mobs;

std::unique_ptr<Player> Qor::player = std::make_unique<Player>(15, 15);

Qor::Qor()
        : window(RenderWindow("Qor", SCREEN_WIDTH_PXL, SCREEN_HEIGHT_PXL)),
          viewport(Viewport(SCREEN_WIDTH_PXL, SCREEN_HEIGHT_PXL)) {
    createMap();
    createMobs();
    createItems();
}

void Qor::run(unsigned int deltaTime) {
    Qor::delta = (double) deltaTime / 1000;

    Input::processInput();

    player->update();
    updateMobs();

    window.startFrame();
    renderMap();
    renderItems();
    renderMobs();
    renderPlayer();
    window.showFrame();
}

void Qor::createMap() {
    map = std::make_unique<Map>(MAP_SIZE, MAP_SIZE);
}

void Qor::createItems() {
    items.push_back(std::make_shared<Item>(10, 3, 3));
    items.push_back(std::make_shared<Item>(11, 4, 8));
    items.push_back(std::make_shared<Item>(12, 7, 7));
}

void Qor::createMobs() {
    mobs.push_back(std::make_shared<Mob>(1, 1, 1));
//    mobs.push_back(std::make_shared<Mob>(2, 5, 5));
}

void Qor::updateMobs() {
    for (auto &e : mobs) {
        e->update();
    }
}

void Qor::renderMap() {
    window.renderMap();
}

void Qor::renderItems() {
    for (auto &i : items) {
        window.renderEntity(*i);
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
