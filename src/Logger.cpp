#include "Logger.h"

void Logger::log(const char *message) {
    SDL_Log("%s", message);
}

void Logger::log(const char *message, Entity &e) {
    SDL_Log("[%s]: %s", std::to_string(e.id_).c_str(), message);
}

void Logger::log(const std::string &message) {
    SDL_Log("%s", message.c_str());
}
