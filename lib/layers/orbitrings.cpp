#include "solarsystemclock/clock.h"
#include "solarsystemclock/sdl/renderer.h"
#include "solarsystemclock/sdl/texture.h"

#include "solarsystemclock/layers/orbitrings.h"

using namespace solarsystemclock;
using namespace solarsystemclock::layers;

OrbitRings::OrbitRings(const sdl::Renderer &renderer, const Clock &clock)
        : Layer(renderer, clock),
          m_texture(renderer, "images/orbits.png") {

}

void OrbitRings::resize(int width, int height) {
    m_size = m_clock.orbits_size();
    m_cx = width / 2.f;
    m_cy = height / 2.f;
}

void OrbitRings::draw() {
    SDL_FRect dst_rect = {
            m_cx - (m_size / 2.f),
            m_cy - (m_size / 2.f),
            m_size,
            m_size
    };

    m_renderer.render_copy(m_texture, nullptr, &dst_rect);
}
