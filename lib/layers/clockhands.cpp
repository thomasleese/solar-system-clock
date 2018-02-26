#include <algorithm>
#include <cmath>
#include <iostream>

#include <SDL2/SDL.h>

#include "solar-system-clock/clock.h"
#include "solar-system-clock/texture.h"

#include "solar-system-clock/layers/clockhands.h"

using namespace solarsystemclock::layers;

ClockHands::ClockHands(SDL_Renderer *renderer, Clock *clock) : Layer(renderer, clock) {
    m_texture = new Texture(renderer, "images/hand.png");
}

ClockHands::~ClockHands() {
    delete m_texture;
}

void ClockHands::resize(int width, int height) {
    m_hour_radius = m_clock->orbits_radius(3);
    m_minute_radius = m_clock->orbits_radius(5);
    m_second_radius = m_clock->orbits_radius(7);

    m_cx = width / 2;
    m_cy = height / 2;
}

void ClockHands::draw() {
    draw_hand(m_hour_radius, m_clock->hours_angle());
    draw_hand(m_minute_radius, m_clock->minutes_angle());
    draw_hand(m_second_radius, m_clock->seconds_angle());
}

void ClockHands::draw_hand(double radius, double angle) {
    double x = m_cx + radius * std::sin(angle) * 0.5;
    double y = m_cy - radius * std::cos(angle) * 0.5;

    double degrees = angle * 180.0 / M_PI;
    m_texture->draw(m_renderer, x, y, 5, radius, degrees, 255, 255, 255, 200);
}
