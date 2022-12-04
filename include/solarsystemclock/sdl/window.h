#ifndef SOLARSYSTEMCLOCK_SDL_WINDOW_H
#define SOLARSYSTEMCLOCK_SDL_WINDOW_H

#include <memory>

struct SDL_Renderer;
struct SDL_Window;

namespace spdlog {
    class logger;
}

namespace solarsystemclock::sdl {

    class Renderer;

    class Window {
    public:
        Window(int width, int height);
        ~Window();

        operator SDL_Window *() const {
            return m_window;
        }

        [[nodiscard]] uint32_t get_id() const;

        void get_size(int *width, int *height) const;

        [[nodiscard]] Renderer &renderer() const {
            return *m_renderer;
        }

    private:
        std::shared_ptr<spdlog::logger> m_logger;

        SDL_Window *m_window;
        std::unique_ptr<Renderer> m_renderer;
    };

}

#endif // SOLARSYSTEMCLOCK_SDL_WINDOW_H
