#include <algorithm>
#include <iostream>

#include <SDL2/SDL.h>

#include "solar-system-clock/texture.h"

#include "solar-system-clock/sun.h"

using namespace solarsystemclock;

Sun::Sun(SDL_Renderer *renderer) : m_renderer(renderer) {
    m_texture = new Texture(renderer, "images/sun.png");
}

Sun::~Sun() {
    delete m_texture;
}

void Sun::resize(int width, int height) {
    m_size = std::min(width, height) * 0.08;

    m_cx = width / 2;
    m_cy = height / 2;
}

void Sun::update(float dt) {

}

void Sun::draw() {
    m_texture->draw(m_renderer, m_cx, m_cy, m_size, m_size, 255, 255, 255, 255);
}
