#ifndef QOR_QOR_H
#define QOR_QOR_H


#include <vector>
#include "RenderWindow.h"
#include "Viewport.h"
#include "Entity.h"
#include "Player.h"

class Qor {
private:
    RenderWindow window;
    Viewport viewport;

    static void createEntities();

    void renderEntities();

    void renderPlayer();

public:
    static bool quit;
    static std::vector<std::shared_ptr<Entity>> entities;
    static double delta;

    static std::unique_ptr<Player> player;

    Qor();

    void run(unsigned int deltaTime);
};


#endif //QOR_QOR_H
