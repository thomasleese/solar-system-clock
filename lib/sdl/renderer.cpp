#include <SDL.h>

#include <spdlog/spdlog.h>

#include "solarsystemclock/sdl/error.h"

#include "solarsystemclock/sdl/renderer.h"

using namespace solarsystemclock::sdl;

Renderer::Renderer(SDL_Renderer *renderer) : m_logger(spdlog::get("sdl")), m_renderer(renderer) {
    m_logger->info("Creating renderer");

    if (!m_renderer) {
        throw Error("Could not create renderer.");
    }
}

Renderer::Renderer(SDL_Window *window, int index, uint32_t flags)
        : Renderer(SDL_CreateRenderer(window, index, flags)) {

}

Renderer::~Renderer() {
    m_logger->info("Destroying renderer");

    if (m_renderer) {
        SDL_DestroyRenderer(m_renderer);
    }
}

void Renderer::set_target(SDL_Texture *texture) const {
    if (SDL_SetRenderTarget(*this, texture) != 0) {
        throw Error("Could not set render target.");
    }
}

void Renderer::get_output_size(int *width, int *height) const {
    SDL_GetRendererOutputSize(*this, width, height);
}

void Renderer::get_logical_size(int *width, int *height) const {
    SDL_RenderGetLogicalSize(*this, width, height);
}

void Renderer::set_logical_size(int width, int height) {
    if (SDL_RenderSetLogicalSize(*this, width, height) != 0) {
        throw Error("Could not set render logical size.");
    }
}

void Renderer::render_copy(SDL_Texture *texture, const SDL_Rect *srcrect, const SDL_FRect *dstrect) const {
    SDL_RenderCopyF(*this, texture, srcrect, dstrect);
}

void Renderer::render_copy(SDL_Texture *texture, const SDL_Rect *srcrect, const SDL_FRect *dstrect, const double angle,
                           const SDL_FPoint *center, const SDL_RendererFlip flip) const {
    SDL_RenderCopyExF(*this, texture, srcrect, dstrect, angle, center, flip);
}

void Renderer::fill(uint8_t r, uint8_t g, uint8_t b, uint8_t a) const {
    SDL_SetRenderDrawColor(*this, r, g, b, a);
    clear();
}

void Renderer::clear() const {
    if (SDL_RenderClear(*this) != 0) {
        throw Error("Could not render clear.");
    }
}

void Renderer::present() const noexcept {
    SDL_RenderPresent(*this);
}
