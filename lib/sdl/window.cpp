#include <SDL.h>

#include <spdlog/spdlog.h>

#include "solarsystemclock/sdl/error.h"
#include "solarsystemclock/sdl/renderer.h"

#include "solarsystemclock/sdl/window.h"

using namespace solarsystemclock::sdl;

static const uint32_t WINDOW_FLAGS = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI;
static const uint32_t RENDERER_FLAGS =
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE;

Window::Window(const int width, const int height)
        : m_logger(spdlog::get("sdl")),
          m_window(SDL_CreateWindow("Solar System Clock", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height,
                                    WINDOW_FLAGS)) {
    m_logger->info("Creating window {}x{}", width, height);

    if (!m_window) {
        throw Error("Could not create window.");
    }

    m_renderer = std::make_unique<Renderer>(*this, -1, RENDERER_FLAGS);

    m_renderer->fill(0, 0, 0, 0);
    m_renderer->present();
}

Window::~Window() {
    m_renderer.reset();

    m_logger->info("Destroying window");

    if (m_window) {
        SDL_DestroyWindow(m_window);
    }
}

uint32_t Window::get_id() const {
    return SDL_GetWindowID(*this);
}

void Window::get_size(int *width, int *height) const {
    SDL_GetWindowSize(*this, width, height);
}
