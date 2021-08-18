#include "Item.h"

const double Item::BODY_SIZE = 0.3;

Item::Item(int id_a, double x_a, double y_a)
        : Entity(id_a, x_a, y_a, BODY_SIZE, {185, 122, 85, 255}, TargetType::STATIC, BODY_SIZE, BODY_SIZE) {}
