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

Texture::Texture(SDL_Texture *texture, int width, int height) {
    m_texture = texture;

    m_src_rect = new SDL_Rect;
    m_src_rect->x = 0;
    m_src_rect->y = 0;
    m_src_rect->w = width;
    m_src_rect->h = height;

    m_dest_rect = new SDL_Rect;
    m_dest_rect->x = 0;
    m_dest_rect->y = 0;
    m_dest_rect->w = width;
    m_dest_rect->h = height;
}

Texture::~Texture() {
    delete m_src_rect;
    delete m_dest_rect;

    SDL_DestroyTexture(m_texture);
}

void Texture::draw(SDL_Renderer *renderer, double x, double y, double width, double height, double angle, int r, int g, int b, int a) {
    m_dest_rect->x = x - (width / 2.0);
    m_dest_rect->y = y - (height / 2.0);
    m_dest_rect->w = width;
    m_dest_rect->h = height;

    SDL_SetTextureColorMod(m_texture, r, g, b);
    SDL_SetTextureAlphaMod(m_texture, a);

    SDL_SetTextureBlendMode(m_texture, SDL_BLENDMODE_BLEND);

    SDL_RenderCopyEx(renderer, m_texture, m_src_rect, m_dest_rect, angle, nullptr, SDL_FLIP_NONE);
}

void Texture::draw(SDL_Renderer *renderer, double x, double y, double width, double height, int r, int g, int b, int a) {
    draw(renderer, x, y, width, height, 0.0f, r, g, b, a);
}

void Texture::draw(SDL_Renderer *renderer, double x, double y, int r, int g, int b, int a) {
    draw(renderer, x, y, m_src_rect->w, m_src_rect->h, r, g, b, a);
}
