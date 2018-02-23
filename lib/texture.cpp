#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "solar-system-clock/texture.h"

using namespace solarsystemclock;

Texture::Texture(SDL_Renderer *renderer, std::string filename) {
    auto surface = IMG_Load(("../" + filename).c_str());
    if (surface == nullptr) {
        std::cerr << "Unable to load " << filename << ": " << IMG_GetError() << std::endl;
        abort();
    }

    m_texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (surface == nullptr) {
        std::cerr << "Unable to load " << filename << ": " << IMG_GetError() << std::endl;
        abort();
    }

    m_src_rect = new SDL_Rect;
    m_src_rect->x = 0;
    m_src_rect->y = 0;
    m_src_rect->w = surface->w;
    m_src_rect->h = surface->h;

    m_dest_rect = new SDL_Rect;
    m_dest_rect->x = 0;
    m_dest_rect->y = 0;
    m_dest_rect->w = surface->w;
    m_dest_rect->h = surface->h;

    SDL_FreeSurface(surface);
}

Texture::~Texture() {
    delete m_src_rect;
    delete m_dest_rect;

    SDL_DestroyTexture(m_texture);
}

void Texture::draw(SDL_Renderer *renderer, int x, int y, int width, int height, int r, int g, int b, int a) {
    m_dest_rect->x = x - (m_src_rect->w / 2.0);
    m_dest_rect->y = y - (m_src_rect->h / 2.0);
    m_dest_rect->w = width;
    m_dest_rect->h = height;

    SDL_SetTextureColorMod(m_texture, r, g, b);
    SDL_SetTextureAlphaMod(m_texture, a);

    SDL_RenderCopy(renderer, m_texture, m_src_rect, m_dest_rect);
}