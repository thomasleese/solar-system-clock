#include <algorithm>

#include <SDL2/SDL.h>

#include "solar-system-clock/texture.h"

#include "solar-system-clock/layers/background.h"

using namespace solarsystemclock;
using namespace solarsystemclock::layers;

Background::Background(SDL_Renderer *renderer) : Layer(renderer) {
    m_texture = new Texture(renderer, "images/background.png");
}

Background::~Background() {
    delete m_texture;
}

void Background::resize(int width, int height) {
    m_size = std::min(width, height);
    m_cx = width / 2;
    m_cy = height / 2;
}

void Background::draw() {
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
    SDL_RenderClear(m_renderer);

    m_texture->draw(m_renderer, m_cx, m_cy, m_size, m_size, 255, 255, 255, 255);
}
