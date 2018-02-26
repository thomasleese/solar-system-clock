#include <algorithm>
#include <cmath>
#include <iostream>

#include <SDL2/SDL.h>

#include "solar-system-clock/clock.h"
#include "solar-system-clock/texture.h"

#include "solar-system-clock/layers/sunrisesunset.h"

using namespace solarsystemclock::layers;

SunriseSunset::SunriseSunset(SDL_Renderer *renderer, Clock *clock) : Layer(renderer), m_clock(clock), m_sunset_angle(0), m_sunrise_angle(0) {
    m_texture = new Texture(renderer, "images/shootingstar.png");
}

SunriseSunset::~SunriseSunset() {
    delete m_texture;
}

void SunriseSunset::resize(int width, int height) {
    m_radius = m_clock->orbits_radius(9);
    m_size = m_clock->size() * 0.1;

    m_cx = width / 2;
    m_cy = height / 2;
}

void SunriseSunset::update(double dt) {
    m_sunset_angle = m_clock->sunset_angle();
    m_sunrise_angle = m_clock->sunrise_angle();
}

void SunriseSunset::draw() {
    draw_shooting_star(m_sunset_angle);
    draw_shooting_star(m_sunrise_angle);
}

void SunriseSunset::draw_shooting_star(double angle) {
    double radians = M_PI - angle;

    int x = m_cx + std::sin(radians) * m_radius;
    int y = m_cy + std::cos(radians) * m_radius;

    double degrees = 270.0 - radians * 180.0 / M_PI;

    m_texture->draw(m_renderer, x, y, m_size, m_size, degrees, 255, 255, 255, 255);
}
