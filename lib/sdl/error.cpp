#include <SDL.h>

#include "solarsystemclock/sdl/error.h"

using namespace solarsystemclock::sdl;

Error::Error(const std::string &operation, const char *error) {
    if (error) {
        m_message = operation + "!\nError: " + error;
    } else {
        m_message = operation;
    }
}

Error::Error(const std::string &operation, const bool use_sdl_error) {
    if (use_sdl_error) {
        Error(operation, SDL_GetError());
    } else {
        Error(operation, nullptr);
    }
}
