#include <algorithm>
#include <cmath>

#include "solar-system-clock/clock.h"

#include "solar-system-clock/planet.h"

using namespace solarsystemclock;

Planet::Planet(int orbit, int diameter, int red, int green, int blue, double orbital_period, double orbit_at_2000) : m_orbit(orbit), m_diameter(diameter), m_red(red), m_green(green), m_blue(blue), m_orbital_period(orbital_period), m_orbit_at_2000(orbit_at_2000) {
    m_angle = 0;
}

Planet::~Planet() {

}

double Planet::size() const {
    return m_size;
}

double Planet::radius() const {
    return m_radius;
}

double Planet::angle() const {
    return m_angle;
}

void Planet::resize(Clock *clock) {
    m_radius = clock->orbits_radius(m_orbit);

    double min = clock->orbits_gap() * 0.6f;
    double max = clock->orbits_gap() * 1.2f;
    double largest = 139822;
    double smallest = 4780;

    m_size = ((max - min) / (largest - smallest)) * (static_cast<double>(m_diameter) - smallest) + min;
}

void Planet::update(double dt) {
    m_angle -= dt * (m_orbit + 1) * 0.1f;
}
