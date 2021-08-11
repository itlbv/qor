#include "Item.h"

Item::Item(int id_a, double x_a, double y_a)
        : Entity(id_a, x_a, y_a, 0.3, {185, 122, 85, 255}, TargetType::STATIC) {}
