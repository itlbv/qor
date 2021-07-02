#ifndef QOR_ENTITY_H
#define QOR_ENTITY_H

#include <SDL.h>
#include <memory>
#include "Vect.h"

class Entity {
private:
    bool alive_;
    std::unique_ptr<SDL_Rect> renderShape_;
    std::unique_ptr<Vect> dest_;
    std::shared_ptr<Entity> target_;

protected:
    std::unique_ptr<Vect> velocity_;

public:
    std::unique_ptr<Vect> pos_;
    const double radius_;

    Entity(double a_x, double a_y);

    SDL_Rect *getRenderShape();

    void setDest(double a_x, double a_y);

    Vect *getDest();

    void setTarget(std::shared_ptr<Entity> e);

    Entity *getTarget();

    void setVelocity(Vect &velocity_a);

    Vect *getVelocity();

    [[nodiscard]] bool isAlive() const;
};

#endif //QOR_ENTITY_H
