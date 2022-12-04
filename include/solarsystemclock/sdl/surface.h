#ifndef SOLARSYSTEMCLOCK_SDL_SURFACE_H
#define SOLARSYSTEMCLOCK_SDL_SURFACE_H

#include <memory>
#include <string>

struct SDL_Surface;

namespace spdlog {
    class logger;
}

namespace solarsystemclock::sdl {

    class Surface {
    public:
        explicit Surface(SDL_Surface *surface, const std::string &filename = "");
        explicit Surface(const std::string &filename);
        Surface(Surface &&surface) noexcept;
        Surface(const Surface &) = delete;

        ~Surface();

        operator SDL_Surface *() const {
            return m_surface;
        }

        [[nodiscard]] int width() const {
            return m_surface->w;
        }

        [[nodiscard]] int height() const {
            return m_surface->h;
        }

    private:
        std::shared_ptr<spdlog::logger> m_logger;

        std::string m_filename;
        SDL_Surface *m_surface;
    };

}

#endif // SOLARSYSTEMCLOCK_SDL_SURFACE_H
