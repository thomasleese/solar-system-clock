#include <algorithm>

#include "solarsystemclock/sdl/texture.h"
#include "solarsystemclock/sdl/renderer.h"

#include "solarsystemclock/layers/sun.h"

using namespace solarsystemclock::layers;

Sun::Sun(const sdl::Renderer &renderer, const Clock &clock)
        : Layer(renderer, clock), m_texture(renderer, "images/sun.png") {

}

void Sun::resize(int width, int height) {
    m_size = std::min(width, height) * 0.08f;
    m_cx = width / 2.f;
    m_cy = height / 2.f;
}

void Sun::draw() {
    SDL_FRect dst_rect = {
            m_cx - m_size / 2.f,
            m_cy - m_size / 2.f,
            m_size,
            m_size
    };

    m_renderer.render_copy(m_texture, nullptr, &dst_rect);
}
