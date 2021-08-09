#pragma once

#include <SDL.h>
#include <string>
#include "Entity.h"

class Logger {
public:
    static void log(const char *message);

    static void log(const char *message, Entity &e);

    static void log(const std::string &message);

    static void log(const std::string &message, Entity &e);
};

