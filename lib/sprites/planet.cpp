#include <algorithm>
#include <cmath>
#include <iostream>

#include <SDL2/SDL.h>

#include "solar-system-clock/texture.h"
#include "solar-system-clock/layers/orbitrings.h"

#include "solar-system-clock/sprites/planet.h"

using namespace solarsystemclock;
using namespace solarsystemclock::sprites;
using namespace solarsystemclock::layers;

Planet::Planet(SDL_Renderer *renderer, int orbit, int diameter, int red, int green, int blue) : m_renderer(renderer), m_orbit(orbit), m_diameter(diameter), m_r(red), m_g(green), m_b(blue) {
    m_bg_texture = new Texture(renderer, "images/planet-background.png");
    m_ball_texture = new Texture(renderer, "images/planet-ball.png");
    m_shadow_texture = new Texture(renderer, "images/planet-shadow.png");

    m_angle = 0;
}

Planet::~Planet() {
    delete m_bg_texture;
    delete m_ball_texture;
    delete m_shadow_texture;
}

void Planet::resize(int width, int height, layers::OrbitRingss *orbit_rings) {
    m_cx = width / 2;
    m_cy = height / 2;

    m_radius = orbit_rings->radius(m_orbit);

    double min = orbit_rings->gap() * 0.6f;
    double max = orbit_rings->gap() * 1.2f;
    double largest = 139822;
    double smallest = 4780;

    m_size = ((max - min) / (largest - smallest)) * (static_cast<double>(m_diameter) - smallest) + min;
}

void Planet::update(double dt) {
    m_angle -= dt * (m_orbit + 1) * 0.1f;
}

void Planet::draw() {
    double angle = m_angle;

    int x = m_cx + std::sin(angle) * m_radius;
    int y = m_cy + std::cos(angle) * m_radius;

    double degrees = 180 - angle * (180.0 / 3.141592653589793238463);

    m_shadow_texture->draw(m_renderer, x, y, m_size * 2, m_size * 12.5, degrees, m_r, m_g, m_b, 200);
    m_bg_texture->draw(m_renderer, x, y, m_size, m_size, degrees, m_r, m_g, m_b, 192);
    m_ball_texture->draw(m_renderer, x, y, m_size, m_size, degrees, 255, 255, 255, 255);
}
