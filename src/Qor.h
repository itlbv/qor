#pragma once

#include <vector>
#include "RenderWindow.h"
#include "Viewport.h"
#include "Entity.h"
#include "Mob.h"
#include "Player.h"
#include "Item.h"
#include "Map.h"

class Qor {
private:
    RenderWindow window;
    Viewport viewport;

    static void createMap();

    static void createMobs();

    static void createItems();

    static void updateMobs();

    void renderMap();

    void renderItems();

    void renderMobs();

    void renderPlayer();

public:
    static const int SCREEN_WIDTH_PXL;
    static const int SCREEN_HEIGHT_PXL;
    static const int MAP_SIZE;

    static bool quit;
    static std::unique_ptr<Map> map;
    static std::vector<std::shared_ptr<Item>> items;
    static std::vector<std::shared_ptr<Mob>> mobs;
    static double delta;

    static std::unique_ptr<Player> player;

    Qor();

    void run(unsigned int deltaTime);
};
