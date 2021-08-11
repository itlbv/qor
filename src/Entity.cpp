#include "Entity.h"
#include "Logger.h"

Entity::Entity(int id_a, double x_a, double y_a, double radius_a, SDL_Color render_color_a, TargetType targetType_a)
        : Target(targetType_a),
          id_(id_a),
          radius_(radius_a),
          render_color_(render_color_a) {
    pos_ = std::make_unique<Vect>();
    pos_->x = x_a;
    pos_->y = y_a;
    render_shape_ = std::make_unique<SDL_Rect>();
}

int Entity::getId() const {
    return id_;
}

Vect *Entity::getPos() {
    return pos_.get();
}

double Entity::getRadius() const {
    return radius_;
}

SDL_Rect *Entity::getRenderShape() {
    return render_shape_.get();
}

SDL_Color *Entity::getRenderColor() {
    return &render_color_;
}

void Entity::setRenderColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    render_color_.r = r;
    render_color_.g = g;
    render_color_.b = b;
    render_color_.a = a;
}
