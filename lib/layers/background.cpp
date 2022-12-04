#include <algorithm>

#include "solarsystemclock/sdl/renderer.h"
#include "solarsystemclock/sdl/texture.h"

#include "solarsystemclock/layers/background.h"

using namespace solarsystemclock;
using namespace solarsystemclock::layers;

Background::Background(const sdl::Renderer &renderer, Clock *clock)
        : Layer(renderer, clock),
          m_texture(renderer, "images/background.png"),
          m_size(0), m_cx(0), m_cy(0) {

}

void Background::resize(int width, int height) {
    m_size = std::min(width, height);
    m_cx = width / 2;
    m_cy = height / 2;
}

void Background::draw() {
    m_renderer.fill(0, 0, 0, 255);

    SDL_FRect dst_rect = {
            static_cast<float>(m_cx - (m_size / 2.0)),
            static_cast<float>(m_cy - (m_size / 2.0)),
            static_cast<float>(m_size),
            static_cast<float>(m_size)
    };

    m_renderer.render_copy(m_texture, nullptr, &dst_rect);
}
