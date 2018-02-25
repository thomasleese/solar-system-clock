#include <algorithm>
#include <iostream>

#include <SDL2/SDL.h>

#include "solar-system-clock/texture.h"
#include "solar-system-clock/layers/orbits.h"

#include "solar-system-clock/planet.h"

using namespace solarsystemclock;
using namespace solarsystemclock::layers;

Planet::Planet(SDL_Renderer *renderer, int orbit) : m_renderer(renderer), m_orbit(orbit) {
    m_bg_texture = new Texture(renderer, "images/planet-background.png");
    m_ball_texture = new Texture(renderer, "images/planet-ball.png");
    m_shadow_texture = new Texture(renderer, "images/planet-shadow.png");
}

Planet::~Planet() {
    delete m_bg_texture;
    delete m_ball_texture;
    delete m_shadow_texture;
}

void Planet::resize(int width, int height, Orbits *orbits) {
    m_cx = width / 2;
    m_cy = height / 2;

    m_radius = orbits->radius(m_orbit);
}

void Planet::update(float dt) {

}

void Planet::draw() {
    int x = m_cx;
    int y = m_cy - m_radius;

    m_shadow_texture->draw(m_renderer, x, y, 60, 375, 255, 0, 0, 200);
    m_bg_texture->draw(m_renderer, x, y, 30, 30, 255, 0, 0, 192);
    m_ball_texture->draw(m_renderer, x, y, 30, 30, 255, 255, 255, 255);
}
