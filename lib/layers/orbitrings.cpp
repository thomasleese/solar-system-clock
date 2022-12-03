#include <algorithm>
#include <iostream>

#include <SDL2/SDL.h>

#include "solarsystemclock/clock.h"
#include "solarsystemclock/texture.h"

#include "solarsystemclock/layers/orbitrings.h"

using namespace solarsystemclock::layers;

OrbitRings::OrbitRings(SDL_Renderer *renderer, Clock *clock) : Layer(renderer, clock) {
    m_texture = new Texture(renderer, "images/orbits.png");
}

OrbitRings::~OrbitRings() {
    delete m_texture;
}

void OrbitRings::resize(int width, int height) {
    m_size = m_clock->orbits_size();
    m_cx = width / 2;
    m_cy = height / 2;
}

void OrbitRings::draw() {
    m_texture->draw(m_renderer, m_cx, m_cy, m_size, m_size, 255, 255, 255, 255);
}
