#pragma once

#include <SDL.h>
#include <string>

class Logger {
public:
    static void log(const char *message);

    static void log(const std::string &message);
};

