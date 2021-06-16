#ifndef QOR_QOR_H
#define QOR_QOR_H


#include <vector>
#include "RenderWindow.h"
#include "Viewport.h"
#include "Entity.h"

class Qor {
private:
    RenderWindow window;
    Viewport viewport;

    void createEntities();

    void renderEntities();

public:
    static bool quit;
    static std::vector<Entity> entities;

    Qor();

    void run();
};


#endif //QOR_QOR_H
