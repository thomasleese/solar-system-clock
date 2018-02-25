#include <algorithm>
#include <iostream>

#include <SDL2/SDL.h>

#include "solar-system-clock/texture.h"

#include "solar-system-clock/layers/orbitrings.h"

using namespace solarsystemclock::layers;

OrbitRingss::OrbitRingss(SDL_Renderer *renderer) : Layer(renderer) {
    m_texture = new Texture(renderer, "images/orbits.png");
}

OrbitRingss::~OrbitRingss() {
    delete m_texture;
}

double OrbitRingss::gap() const {
    double scale = m_size / 1024.0;
    return 55.f * scale;
}

int OrbitRingss::radius(int orbit) const {
    double scale = m_size / 1024.0;
    int start = 100 * scale;

    return start + gap() * orbit;
}

void OrbitRingss::resize(int width, int height) {
    m_size = std::min(width, height) * 0.9;

    m_cx = width / 2;
    m_cy = height / 2;
}

void OrbitRingss::draw() {
    m_texture->draw(m_renderer, m_cx, m_cy, m_size, m_size, 255, 255, 255, 255);
}
