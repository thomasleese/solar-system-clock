#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

#include "solar-system-clock/texture.h"

#include "solar-system-clock/orbitring.h"

using namespace solarsystemclock;

OrbitRing::OrbitRing(SDL_Renderer *renderer, int radius, int thickness) {
    int size = (radius + thickness + 1) * 2;

    auto texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_TARGET, size, size);
    SDL_SetRenderTarget(renderer, texture);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);

    //SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    filledCircleRGBA(renderer, size / 2, size / 2, radius, 255, 255, 255, 255);
    filledCircleRGBA(renderer, size / 2, size / 2, radius - thickness, 0, 0, 0, 255);
    aacircleRGBA(renderer, size / 2, size / 2, radius, 255, 255, 255, 255);
    aacircleRGBA(renderer, size / 2, size / 2, radius - thickness, 0, 0, 0, 255);

    SDL_SetRenderTarget(renderer, nullptr);

    m_texture = new Texture(texture, size, size);
}

OrbitRing::~OrbitRing() {
    delete m_texture;
}

void OrbitRing::draw(SDL_Renderer *renderer, int x, int y, int r, int g, int b, int a) {
    m_texture->draw(renderer, x, y, r, g, b, a);
}
