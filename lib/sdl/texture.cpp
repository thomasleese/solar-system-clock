#include <SDL.h>
#include <SDL_image.h>

#include "solarsystemclock/sdl/error.h"
#include "solarsystemclock/sdl/surface.h"

#include "solarsystemclock/sdl/texture.h"

using namespace solarsystemclock::sdl;

Texture::Texture(SDL_Texture *texture) : m_texture(texture) {
    if (!m_texture) {
        throw Error("Could not create texture.");
    }
}

Texture::Texture(SDL_Renderer *renderer, const int width, const int height)
    : Texture(SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGB888, SDL_TEXTUREACCESS_TARGET, width, height)) {

}

Texture::Texture(SDL_Renderer *renderer, SDL_Surface *surface)
    : Texture(SDL_CreateTextureFromSurface(renderer, surface)) {

}

Texture::Texture(SDL_Renderer *renderer, const std::string &filename)
    : Texture(renderer, Surface(filename)) {

}

Texture::Texture(Texture &&other_texture) noexcept : Texture(other_texture.m_texture) {
    other_texture.m_texture = nullptr;
}

Texture::~Texture() {
    if (m_texture) {
        SDL_DestroyTexture(m_texture);
    }
}

void Texture::set_blend_mode(SDL_BlendMode blend_mode) {
    if (SDL_SetTextureBlendMode(*this, blend_mode) != 0) {
        throw Error("Could not set blend mode.");
    }
}

void Texture::set_color_mod(uint8_t red, uint8_t green, uint8_t blue) {
    if (SDL_SetTextureColorMod(*this, red, green, blue) != 0) {
        throw Error("Could not set color modifier.");
    }
}
