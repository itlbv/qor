#ifndef QOR_QOR_H
#define QOR_QOR_H


#include "RenderWindow.h"
#include "Viewport.h"

class Qor {
private:
    RenderWindow window;
    Viewport viewport;
public:
    static bool quit;

    Qor();

    void run();
};


#endif //QOR_QOR_H
