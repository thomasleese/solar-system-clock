#ifndef SOLARSYSTEMCLOCK_SDL_ERROR_H
#define SOLARSYSTEMCLOCK_SDL_ERROR_H

#include <exception>
#include <string>

namespace solarsystemclock::sdl {

    struct Error : public std::exception {
    public:
        Error(const std::string &operation, const char *error);
        explicit Error(const std::string &operation, bool use_sdl_error = true);

        [[nodiscard]] const char *what() const noexcept override {
            return m_message.c_str();
        }

    private:
        std::string m_message;
    };

}

#endif // SOLARSYSTEMCLOCK_SDL_ERROR_H
