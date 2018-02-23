#include <iostream>

#include <SDL2/SDL.h>

#include "solar-system-clock/starfield.h"

using namespace solarsystemclock;

Starfield::Starfield(SDL_Renderer *renderer) : m_renderer(renderer) {
}

Starfield::~Starfield() {

}

void Starfield::resize(int width, int height) {
    std::cout << width << "x" << height << std::endl;
}

void Starfield::render(float dt) {
    SDL_SetRenderDrawColor(m_renderer, 5, 45, 109, 255);
    SDL_RenderClear(m_renderer);
}
