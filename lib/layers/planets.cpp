#include <algorithm>
#include <iostream>

#include <SDL2/SDL.h>

#include "solar-system-clock/sprites/planet.h"

#include "solar-system-clock/layers/planets.h"

using namespace solarsystemclock;
using namespace solarsystemclock::sprites;
using namespace solarsystemclock::layers;

Planets::Planets(SDL_Renderer *renderer, layers::OrbitRingss *orbit_rings) : Layer(renderer), m_orbit_rings(orbit_rings) {
    m_planets.push_back(new Planet(renderer, 0, 4780, 0x80, 0x80, 0x80));
    m_planets.push_back(new Planet(renderer, 1, 12104, 0xff, 0x90, 0x00));
    m_planets.push_back(new Planet(renderer, 2, 12756, 0x00, 0xc0, 0x50));
    m_planets.push_back(new Planet(renderer, 3, 6780, 0xef, 0x10, 0x00));
    m_planets.push_back(new Planet(renderer, 4, 139822, 0xe0, 0xa0, 0x70));
    m_planets.push_back(new Planet(renderer, 5, 116464, 0xef, 0xb0, 0x20));
    m_planets.push_back(new Planet(renderer, 6, 50724, 0x00, 0xb0, 0xc0));
    m_planets.push_back(new Planet(renderer, 7, 49248, 0x15, 0x40, 0xff));
}

Planets::~Planets() {
    for (auto &planet : m_planets) {
        delete planet;
    }
}

void Planets::resize(int width, int height) {
    for (auto &planet : m_planets) {
        planet->resize(width, height, m_orbit_rings);
    }
}

void Planets::update(double dt) {
    for (auto &planet : m_planets) {
        planet->update(dt);
    }
}

void Planets::draw() {
    for (auto &planet : m_planets) {
        planet->draw();
    }
}
