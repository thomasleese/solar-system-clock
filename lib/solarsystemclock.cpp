#include <SDL2/SDL_events.h>

#include "solarsystemclock/clock.h"
#include "solarsystemclock/sdl/init.h"
#include "solarsystemclock/sdl/texture.h"
#include "solarsystemclock/sdl/renderer.h"
#include "solarsystemclock/sdl/window.h"
#include "solarsystemclock/layers/background.h"
#include "solarsystemclock/layers/starfield.h"
#include "solarsystemclock/layers/orbitrings.h"
#include "solarsystemclock/layers/sun.h"
#include "solarsystemclock/layers/planets.h"
#include "solarsystemclock/layers/rocket.h"
#include "solarsystemclock/layers/sunrisesunset.h"
#include "solarsystemclock/layers/clockhands.h"

#include "solarsystemclock/solarsystemclock.h"

using namespace solarsystemclock;

SolarSystemClock::SolarSystemClock() : m_window(800, 600), m_clock(new Clock) {
    m_layers.push_back(new layers::Background(m_window.renderer(), m_clock));
    m_layers.push_back(new layers::Starfield(m_window.renderer(), m_clock));
    m_layers.push_back(new layers::OrbitRings(m_window.renderer(), m_clock));
    m_layers.push_back(new layers::Planets(m_window.renderer(), m_clock));
    m_layers.push_back(new layers::Rocket(m_window.renderer(), m_clock));
    m_layers.push_back(new layers::SunriseSunset(m_window.renderer(), m_clock));
    m_layers.push_back(new layers::ClockHands(m_window.renderer(), m_clock));
    m_layers.push_back(new layers::Sun(m_window.renderer(), m_clock));

    resize();
}

SolarSystemClock::~SolarSystemClock() {
    for (auto &layer: m_layers) {
        delete layer;
    }

    delete m_clock;
}

void SolarSystemClock::run() {
    SDL_Event event;

    while (true) {
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                return;
            }

            if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_RESIZED &&
                event.window.windowID == m_window.get_id()) {
                resize();
            }
        }

        draw();
        m_window.renderer().present();
    }
}

void SolarSystemClock::resize() {
    int width, height;
    m_window.renderer().get_output_size(&width, &height);

    m_clock->resize(width, height);

    for (auto &layer: m_layers) {
        layer->resize(width, height);
    }
}

void SolarSystemClock::draw() {
    m_clock->update();

    for (auto &layer: m_layers) {
        layer->draw();
    }
}
