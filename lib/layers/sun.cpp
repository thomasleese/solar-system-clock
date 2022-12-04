#include <algorithm>

#include "solarsystemclock/sdl/texture.h"
#include "solarsystemclock/sdl/renderer.h"

#include "solarsystemclock/layers/sun.h"

using namespace solarsystemclock::layers;

Sun::Sun(const sdl::Renderer &renderer, const Clock &clock)
        : Layer(renderer, clock), m_texture(renderer, "images/sun.png"), m_size(0) {

}

void Sun::resize(int width, int height) {
    Layer::resize(width, height);
    m_size = m_square_size * 0.08f;
}

void Sun::draw() {
    SDL_FRect dst_rect = {
            m_center.x - m_size / 2.f,
            m_center.y - m_size / 2.f,
            m_size,
            m_size
    };

    m_renderer.render_copy(m_texture, nullptr, &dst_rect);
}
