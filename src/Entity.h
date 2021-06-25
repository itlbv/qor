#ifndef QOR_ENTITY_H
#define QOR_ENTITY_H

#include <SDL.h>
#include <memory>
#include "Vect.h"

class Entity {
private:
    std::unique_ptr<SDL_Rect> _renderShape;
    std::unique_ptr<Vect> _dest;

protected:
    std::unique_ptr<Vect> velocity_;

public:
    std::unique_ptr<Vect> pos_;
    const double radius_;

    Entity(double a_x, double a_y);

    SDL_Rect *getRenderShape();

    void setDest(double a_x, double a_y);

    Vect *getDest();

    void setVelocity(Vect &velocity_a);

    Vect *getVelocity();
};

#endif //QOR_ENTITY_H
