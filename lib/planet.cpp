#include <algorithm>
#include <chrono>
#include <cmath>
#include <iostream>

#include "solarsystemclock/clock.h"

#include "solarsystemclock/planet.h"

using namespace std::chrono;

using namespace solarsystemclock;

Planet::Planet(int orbit, int diameter, int red, int green, int blue, double orbital_period, double orbit_at_2000)
        : m_orbit(orbit), m_diameter(diameter), m_red(red), m_green(green), m_blue(blue),
          m_orbital_period(orbital_period), m_orbit_at_2000(orbit_at_2000) {
    m_angle = orbit_at_2000;
}

Planet::~Planet() {

}

double Planet::size() const {
    return m_size;
}

double Planet::radius() const {
    return m_radius;
}

void Planet::resize(Clock *clock) {
    m_radius = clock->orbits_radius(m_orbit);

    double min = clock->orbits_gap() * 0.6f;
    double max = clock->orbits_gap() * 1.2f;
    double largest = 139822;
    double smallest = 4780;

    m_size = ((max - min) / (largest - smallest)) * (static_cast<double>(m_diameter) - smallest) + min;
}

void Planet::update(long ms) {
    double proportion = static_cast<double>(ms) / 1500.0;

    m_angle = m_orbit_at_2000 - (1.0 / m_orbital_period) * proportion;
}
