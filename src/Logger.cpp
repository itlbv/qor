#include "Logger.h"

void Logger::log(const char *message) {
    SDL_Log("%s", message);
}

void Logger::log(const std::string &message) {
    SDL_Log("%s", message.c_str());
}
