#pragma once

#include <SDL.h>
#include <memory>
#include "Vect.h"
#include "ai/btree/Behavior.h"

class Behavior;

class Entity {
private:
    bool alive_;
    int health_;
    std::unique_ptr<SDL_Rect> renderShape_;
    std::unique_ptr<Vect> dest_;
    std::shared_ptr<Entity> target_;
    std::unique_ptr<Behavior> behavior_;

protected:
    std::unique_ptr<Vect> velocity_;

public:
    int id_;
    std::unique_ptr<Vect> pos_;
    const double radius_;

    Entity(int id_a, double x_a, double y_a);

    void update();

    void defend();

    void setBehavior(std::unique_ptr<Behavior> behavior);

    SDL_Rect *getRenderShape();

    void setDest(double a_x, double a_y);

    Vect *getDest();

    void setTarget(std::shared_ptr<Entity> e);

    Entity *getTarget();

    void setVelocity(Vect &velocity_a);

    Vect *getVelocity();

    [[nodiscard]] bool isAlive() const;
};
