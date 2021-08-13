#include "Logger.h"

void Logger::log(const char *message) {
    SDL_Log("%s", message);
}

void Logger::log(const char *message, Entity &e) {
    SDL_Log("[%s]: %s", std::to_string(e.getId()).c_str(), message);
}

void Logger::log(const std::string &message) {
    SDL_Log("%s", message.c_str());
}

void Logger::log(const std::string &message, Entity &e) {
    SDL_Log("[%s]: %s", std::to_string(e.getId()).c_str(), message.c_str());
}

void Logger::error(const char *message) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", message);
}

void Logger::error(const char *message, Entity &e) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[%s]: %s", std::to_string(e.getId()).c_str(), message);
}

void Logger::error(const std::string &message) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", message.c_str());
}
