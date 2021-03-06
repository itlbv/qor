#include "Entity.h"
#include "Logger.h"
#include "Util.h"

Entity::Entity(int id_a, double x_a, double y_a, double radius_a, SDL_Color render_color_a, TargetType targetType_a,
               double width_a, double height_a)
        : Target(targetType_a),
          id_(id_a),
          renderShape_(radius_a, render_color_a),
          body_(std::make_unique<Body>(x_a, y_a, width_a, height_a)) {
    pos_ = std::make_unique<Vect>();
    pos_->x = x_a;
    pos_->y = y_a;
    updateRenderPosition();
}

void Entity::updateRenderPosition() {
    renderShape_.rect.x = Util::worldToScreen(getPos()->x - renderShape_.radius);
    renderShape_.rect.y = Util::worldToScreen(getPos()->y - renderShape_.radius);
}

int Entity::getId() const {
    return id_;
}

Vect *Entity::getPos() {
    return pos_.get();
}

Vect *Entity::getBodyPos() {
    return body_->getPos();
}

RenderShape *Entity::getRenderShape() {
    return &renderShape_;
}
