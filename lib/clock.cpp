#include <algorithm>
#include <cmath>

#include "solar-system-clock/planet.h"

#include "solar-system-clock/clock.h"

using namespace solarsystemclock;

Clock::Clock() {
    m_planets.push_back(new Planet(0, 4780, 0x80, 0x80, 0x80, 0.240846, 208.03));
    m_planets.push_back(new Planet(1, 12104, 0xff, 0x90, 0x00, 0.615198, 278.75));
    m_planets.push_back(new Planet(2, 12756, 0x00, 0xc0, 0x50, 1.0, 0.0));
    m_planets.push_back(new Planet(3, 6780, 0xef, 0x10, 0x00, 1.881, 100.99));
    m_planets.push_back(new Planet(4, 139822, 0xe0, 0xa0, 0x70, 11.86, 63.41));
    m_planets.push_back(new Planet(5, 116464, 0xef, 0xb0, 0x20, 29.46, 54.66));
    m_planets.push_back(new Planet(6, 50724, 0x00, 0xb0, 0xc0, 84.01, 149.55));
    m_planets.push_back(new Planet(7, 49248, 0x15, 0x40, 0xff, 164.8, 159.62));
}

Clock::~Clock() {
    for (auto &planet : m_planets) {
        delete planet;
    }
}

void Clock::resize(int width, int height) {
    m_size = std::min(width, height);

    for (auto &planet : m_planets) {
        planet->resize(this);
    }
}

double Clock::size() const {
    return m_size;
}

double Clock::orbits_size() const {
    return m_size * 0.9;
}

double Clock::orbits_scale() const {
    return orbits_size() / 1024.0;
}

double Clock::orbits_start() const {
    return orbits_scale() * 100.0;
}

double Clock::orbits_gap() const {
    return orbits_scale() * 55.0;
}

double Clock::orbits_radius(int orbit) const {
    return orbits_start() + orbits_gap() * orbit;
}
