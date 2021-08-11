#include "Target.h"

Target::Target(Target::TargetType type_a)
        : type_(type_a) {}

Target::TargetType Target::getType() {
    return type_;
}
