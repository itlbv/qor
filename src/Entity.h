#pragma once

#include <SDL.h>
#include <memory>
#include "Vect.h"

class Entity {
private:
    const int id_;
    const double radius_;
    std::unique_ptr<Vect> pos_;
    std::unique_ptr<SDL_Rect> render_shape_;
    SDL_Color render_color_;

public:
    Entity(int id_a, double x_a, double y_a, double radius_a, SDL_Color render_color_a);

    int getId();

    Vect *getPos();

    double getRadius();

    SDL_Rect *getRenderShape();

    SDL_Color *getRenderColor();

    void setRenderColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
};
