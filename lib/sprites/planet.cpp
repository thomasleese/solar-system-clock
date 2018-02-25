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

Planet::Planet(SDL_Renderer *renderer, int orbit, int diameter) : m_renderer(renderer), m_diameter(diameter), m_orbit(orbit) {
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

    float min = orbit_rings->gap() * 0.6f;
    float max = orbit_rings->gap() * 1.2f;
    float largest = 139822;
    float smallest = 4780;

    m_size = ((max - min) / (largest - smallest)) * (static_cast<float>(m_diameter) - smallest) + min;
}

void Planet::update(float dt) {
    m_angle -= dt * (m_orbit + 1) * 0.2f;
}

void Planet::draw() {
    float angle = m_angle;

    int x = m_cx + std::sin(angle) * m_radius;
    int y = m_cy + std::cos(angle) * m_radius;

    m_shadow_texture->draw(m_renderer, x, y, m_size * 2, m_size * 12.5, 255, 0, 0, 200);
    m_bg_texture->draw(m_renderer, x, y, m_size, m_size, 255, 0, 0, 192);
    m_ball_texture->draw(m_renderer, x, y, m_size, m_size, 255, 255, 255, 255);
}
