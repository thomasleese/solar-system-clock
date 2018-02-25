#include <algorithm>
#include <cmath>
#include <iostream>

#include <SDL2/SDL.h>

#include "solar-system-clock/clock.h"
#include "solar-system-clock/texture.h"

#include "solar-system-clock/layers/rocket.h"

using namespace solarsystemclock::layers;

Rocket::Rocket(SDL_Renderer *renderer, Clock *clock) : Layer(renderer), m_clock(clock), m_angle(0) {
    m_texture = new Texture(renderer, "images/rocket.png");
}

Rocket::~Rocket() {
    delete m_texture;
}

void Rocket::resize(int width, int height) {
    m_radius = m_clock->orbits_radius(8);
    m_size = m_clock->size() * 0.06;

    m_cx = width / 2;
    m_cy = height / 2;
}

void Rocket::update(double dt) {
    m_angle = m_clock->seconds_angle();
}

void Rocket::draw() {
    double radians = M_PI - m_angle;

    int x = m_cx + std::sin(radians) * m_radius;
    int y = m_cy + std::cos(radians) * m_radius;

    double degrees = 270.0 - radians * 180.0 / M_PI;

    m_texture->draw(m_renderer, x, y, m_size, m_size, degrees, 255, 255, 255, 255);
}
