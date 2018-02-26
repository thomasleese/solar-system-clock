#include <algorithm>
#include <cmath>
#include <iostream>

#include <SDL2/SDL.h>

#include "solar-system-clock/clock.h"
#include "solar-system-clock/planet.h"
#include "solar-system-clock/texture.h"

#include "solar-system-clock/layers/planets.h"

using namespace solarsystemclock;
using namespace solarsystemclock::layers;

Planets::Planets(SDL_Renderer *renderer, Clock *clock) : Layer(renderer, clock) {
    m_bg_texture = new Texture(renderer, "images/planet-background.png");
    m_ball_texture = new Texture(renderer, "images/planet-ball.png");
    m_shadow_texture = new Texture(renderer, "images/planet-shadow.png");
}

Planets::~Planets() {
    delete m_bg_texture;
    delete m_ball_texture;
    delete m_shadow_texture;
}

void Planets::resize(int width, int height) {
    m_cx = width / 2;
    m_cy = height / 2;
}

void Planets::draw() {
    for (auto &planet : m_clock->planets()) {
        int x = m_cx + std::sin(planet->angle()) * planet->radius();
        int y = m_cy + std::cos(planet->angle()) * planet->radius();

        double degrees = 180.0 - planet->angle() * 180.0 / M_PI;

        m_shadow_texture->draw(m_renderer, x, y, planet->size() * 2, planet->size() * 12.5, degrees, planet->red(), planet->green(), planet->blue(), 200);
        m_bg_texture->draw(m_renderer, x, y, planet->size(), planet->size(), degrees, planet->red(), planet->green(), planet->blue(), 192);
        m_ball_texture->draw(m_renderer, x, y, planet->size(), planet->size(), degrees, 255, 255, 255, 255);
    }
}
