#include <SDL2/SDL.h>

#include "solar-system-clock/clock.h"
#include "solar-system-clock/layers/starfield.h"
#include "solar-system-clock/layers/orbitrings.h"
#include "solar-system-clock/layers/sun.h"
#include "solar-system-clock/layers/planets.h"

#include "solar-system-clock/layers/solarsystemclock.h"

using namespace solarsystemclock::layers;

SolarSystemClock::SolarSystemClock(SDL_Renderer *renderer) : Layer(renderer) {
    m_clock = new Clock;

    m_layers.push_back(new Starfield(renderer, m_clock));
    m_layers.push_back(new OrbitRings(renderer, m_clock));
    m_layers.push_back(new Sun(renderer));
    m_layers.push_back(new Planets(renderer, m_clock));
}

SolarSystemClock::~SolarSystemClock() {
    for (auto &layer : m_layers) {
        delete layer;
    }

    delete m_clock;
}

void SolarSystemClock::resize(int width, int height) {
    m_clock->resize(width, height);

    for (auto &layer : m_layers) {
        layer->resize(width, height);
    }
}

void SolarSystemClock::update(double dt) {
    m_clock->update(dt);

    for (auto &layer : m_layers) {
        layer->update(dt);
    }
}

void SolarSystemClock::draw() {
    SDL_SetRenderDrawColor(m_renderer, 10, 60, 130, 255);
    SDL_RenderClear(m_renderer);

    for (auto &layer : m_layers) {
        layer->draw();
    }
}
