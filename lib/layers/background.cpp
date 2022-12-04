#include <algorithm>

#include "solarsystemclock/sdl/renderer.h"
#include "solarsystemclock/sdl/texture.h"

#include "solarsystemclock/layers/background.h"

using namespace solarsystemclock;
using namespace solarsystemclock::layers;

Background::Background(const sdl::Renderer &renderer, const Clock &clock)
        : Layer(renderer, clock), m_texture(renderer, "images/background.png") {

}

void Background::draw() {
    m_renderer.fill(0, 0, 0, 255);

    SDL_FRect dst_rect = {
            m_center.x - m_square_size / 2.f,
            m_center.y - m_square_size / 2.f,
            m_square_size,
            m_square_size
    };

    m_renderer.render_copy(m_texture, nullptr, &dst_rect);
}
