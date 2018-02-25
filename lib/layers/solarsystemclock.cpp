#include "solar-system-clock/layers/starfield.h"
#include "solar-system-clock/layers/orbitrings.h"
#include "solar-system-clock/layers/sun.h"

#include "solar-system-clock/layers/solarsystemclock.h"

using namespace solarsystemclock::layers;

SolarSystemClock::SolarSystemClock(SDL_Renderer *renderer) : Layer(renderer) {
    m_layers.push_back(new Starfield(renderer));
    m_layers.push_back(new OrbitRingss(renderer));
    m_layers.push_back(new Sun(renderer));
}

SolarSystemClock::~SolarSystemClock() {
    for (auto &layer : m_layers) {
        delete layer;
    }
}

void SolarSystemClock::resize(int width, int height) {
    for (auto &layer : m_layers) {
        layer->resize(width, height);
    }
}

void SolarSystemClock::update(float dt) {
    for (auto &layer : m_layers) {
        layer->update(dt);
    }
}

void SolarSystemClock::draw() {
    for (auto &layer : m_layers) {
        layer->draw();
    }
}