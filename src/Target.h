#pragma once

#include "Vect.h"

class Target {
public:
    enum TargetType {
        STATIC,
        DYNAMIC
    };

    explicit Target(TargetType type_a);

    virtual Vect *getPos() = 0;

    TargetType getType();

private:
    Target::TargetType type_;
};

