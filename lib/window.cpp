#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "solar-system-clock/orbitring.h"
#include "solar-system-clock/starfield.h"

#include "solar-system-clock/window.h"

using namespace solarsystemclock;

void solarsystemclock::initialise_sdl() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cerr << "Couldn't initialise SDL: " << SDL_GetError() << std::endl;
        abort();
	}

    if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
        std::cerr << "Warning: Linear texture filtering not enabled.";
    }

    int img_flags = IMG_INIT_PNG;
    if (!(IMG_Init(img_flags) & img_flags)) {
        std::cerr << "Couldn't initialise SDL_Image: " << IMG_GetError() << std::endl;
        abort();
    }
}

void solarsystemclock::deinitialise_sdl() {
    IMG_Quit();
    SDL_Quit();
}

Window::Window(int width, int height) {
    m_window = SDL_CreateWindow(
        "Solar System Clock",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        width, height,
        SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI
    );

    if (m_window == nullptr) {
        std::cerr << "Couldn't open window: " << SDL_GetError() << std::endl;
        abort();
    }

    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);

    if (m_renderer == nullptr) {
        std::cerr << "Couldn't initialise renderer: " << SDL_GetError() << std::endl;
        abort();
    }

    int window_width, window_height;
    SDL_GetWindowSize(m_window, &window_width, &window_height);

    int renderer_width, renderer_height;
    SDL_GetRendererOutputSize(m_renderer, &renderer_width, &renderer_height);

    SDL_RenderSetScale(m_renderer, renderer_width / window_width, renderer_height / window_height);

    m_starfield = new Starfield(m_renderer);

    m_orbit_ring = new OrbitRing(m_renderer, 100, 5);

    resize(width, height);
}

Window::~Window() {
    delete m_starfield;
    delete m_orbit_ring;

    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
}

void Window::resize(int width, int height) {
    m_starfield->resize(width, height);
}

void Window::mainloop() {
    int t = 0.0;
    const int dt = (1.0 / 60.0) * 1000.0;

    int current_time = SDL_GetTicks();
    int accumulator = 0.0;

    SDL_Event event;

    while (true) {
        while (SDL_PollEvent(&event) != 0) {
            switch (event.type) {
            case SDL_QUIT:
                return;

            case SDL_WINDOWEVENT:
                if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
                    resize(event.window.data1, event.window.data2);
                }
                break;
            }
		}

        int new_time = SDL_GetTicks();
        int frame_time = new_time - current_time;
        current_time = new_time;

        accumulator += frame_time;

        while (accumulator >= dt) {
            double dt_seconds = dt / 1000.0;

            m_starfield->update(dt_seconds);

            accumulator -= dt;
            t += dt;
        }

        m_starfield->draw();
        m_orbit_ring->draw(m_renderer, 400, 300, 255, 255, 255, 255);

		SDL_RenderPresent(m_renderer);
	}
}
