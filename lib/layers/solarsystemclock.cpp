#include <SDL2/SDL.h>

#include "solarsystemclock/clock.h"
#include "solarsystemclock/layers/background.h"
#include "solarsystemclock/layers/starfield.h"
#include "solarsystemclock/layers/orbitrings.h"
#include "solarsystemclock/layers/sun.h"
#include "solarsystemclock/layers/planets.h"
#include "solarsystemclock/layers/rocket.h"
#include "solarsystemclock/layers/sunrisesunset.h"
#include "solarsystemclock/layers/clockhands.h"

#include "solarsystemclock/layers/solarsystemclock.h"

using namespace solarsystemclock::layers;

SolarSystemClock::SolarSystemClock(SDL_Renderer *renderer) : Layer(renderer, new Clock) {
    m_layers.push_back(new Background(renderer, m_clock));
    m_layers.push_back(new Starfield(renderer, m_clock));
    m_layers.push_back(new OrbitRings(renderer, m_clock));
    m_layers.push_back(new Planets(renderer, m_clock));
    m_layers.push_back(new Rocket(renderer, m_clock));
    m_layers.push_back(new SunriseSunset(renderer, m_clock));
    m_layers.push_back(new ClockHands(renderer, m_clock));
    m_layers.push_back(new Sun(renderer, m_clock));
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

void SolarSystemClock::draw() {
    m_clock->update();

    for (auto &layer : m_layers) {
        layer->draw();
    }
}
