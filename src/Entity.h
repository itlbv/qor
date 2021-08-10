#pragma once

#include <SDL.h>
#include <memory>
#include "Vect.h"

class Entity {
private:
    const int id_;
    const double radius_;
    std::unique_ptr<Vect> pos_;
    std::unique_ptr<SDL_Rect> renderShape_;

public:
    Entity(int id_a, double x_a, double y_a);

    int getId();

    Vect *getPos();

    double getRadius();

    SDL_Rect *getRenderShape();
};
