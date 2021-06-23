#include "Entity.h"

#define ENTITY_BODY_RADIUS 0.49

Entity::Entity(double x, double y)
        : _pos({x, y}),
          _radius(ENTITY_BODY_RADIUS),
          _dest({0, 0}) {
    _renderShape = std::make_unique<SDL_Rect>();
}

SDL_Rect *Entity::getRenderShape() {
    return _renderShape.get();
}
