#include <algorithm>
#include <iostream>

#include <SDL2/SDL.h>

#include "solar-system-clock/texture.h"

#include "solar-system-clock/orbits.h"

using namespace solarsystemclock;

Orbits::Orbits(SDL_Renderer *renderer) : m_renderer(renderer) {
    m_texture = new Texture(renderer, "images/orbits.png");
}

Orbits::~Orbits() {
    delete m_texture;
}

void Orbits::resize(int width, int height) {
    m_size = std::min(width, height) * 0.9;

    m_cx = width / 2;
    m_cy = height / 2;
}

void Orbits::draw() {
    m_texture->draw(m_renderer, m_cx, m_cy, m_size, m_size, 255, 255, 255, 255);
}
