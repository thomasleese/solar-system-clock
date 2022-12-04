#include <cmath>

#include "solarsystemclock/clock.h"
#include "solarsystemclock/sdl/renderer.h"
#include "solarsystemclock/sdl/texture.h"

#include "solarsystemclock/layers/rocket.h"

using namespace solarsystemclock;
using namespace solarsystemclock::layers;

Rocket::Rocket(const sdl::Renderer &renderer, Clock *clock)
        : Layer(renderer, clock), m_texture(renderer, "images/rocket.png") {

}

void Rocket::resize(int width, int height) {
    m_radius = m_clock->orbits_radius(8);
    m_size = m_clock->size() * 0.06f;

    m_cx = width / 2.f;
    m_cy = height / 2.f;
}

void Rocket::draw() {
    double radians = M_PI - m_clock->seconds_angle();

    float x = m_cx + std::sin(radians) * m_radius;
    float y = m_cy + std::cos(radians) * m_radius;

    double degrees = 270.0 - radians * 180.0 / M_PI;

    SDL_FRect dst_rect = {
            x - m_size / 2.f,
            y - m_size / 2.f,
            m_size,
            m_size
    };

    SDL_FPoint center = {m_cx, m_cy};

    m_renderer.render_copy(m_texture, nullptr, &dst_rect, degrees, &center, SDL_FLIP_NONE);
}
