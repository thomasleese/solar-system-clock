#include <algorithm>
#include <cmath>
#include <iostream>

#include <SDL2/SDL.h>

#include "solarsystemclock/clock.h"
#include "solarsystemclock/texture.h"

#include "solarsystemclock/layers/sunrisesunset.h"

using namespace solarsystemclock::layers;

SunriseSunset::SunriseSunset(SDL_Renderer *renderer, Clock *clock) : Layer(renderer, clock) {
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

void SunriseSunset::draw() {
    double sunset_angle = m_clock->sunset_angle();
    double sunrise_angle = m_clock->sunrise_angle();

    double hours_angle = m_clock->hours_angle();

    bool sunrise_happened = hours_angle < sunrise_angle;

    draw_shooting_star(sunrise_angle, !sunrise_happened);
    draw_shooting_star(sunset_angle, sunrise_happened);
}

void SunriseSunset::draw_shooting_star(double angle, bool bright) {
    double radians = M_PI - angle;

    int x = m_cx + std::sin(radians) * m_radius;
    int y = m_cy + std::cos(radians) * m_radius;

    double degrees = 270.0 - radians * 180.0 / M_PI;

    m_texture->draw(m_renderer, x, y, m_size, m_size, degrees, 255, 255, 255, bright ? 255 : 150);
}
