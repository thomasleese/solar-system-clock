#include <cmath>

#include "solarsystemclock/clock.h"
#include "solarsystemclock/sdl/texture.h"
#include "solarsystemclock/sdl/renderer.h"

#include "solarsystemclock/layers/sunrisesunset.h"

using namespace solarsystemclock::layers;

SunriseSunset::SunriseSunset(const sdl::Renderer &renderer, const Clock &clock)
        : Layer(renderer, clock), m_texture(renderer, "images/shootingstar.png") {
    m_texture.set_blend_mode(SDL_BLENDMODE_BLEND);
}

void SunriseSunset::resize(int width, int height) {
    m_radius = m_clock.orbits_radius(9);
    m_size = m_clock.size() * 0.1;

    m_cx = width / 2;
    m_cy = height / 2;
}

void SunriseSunset::draw() {
    double sunset_angle = m_clock.sunset_angle();
    double sunrise_angle = m_clock.sunrise_angle();

    double hours_angle = m_clock.hours_angle();

    bool sunrise_happened = hours_angle < sunrise_angle;

    draw_shooting_star(sunrise_angle, !sunrise_happened);
    draw_shooting_star(sunset_angle, sunrise_happened);
}

void SunriseSunset::draw_shooting_star(double angle, bool bright) {
    double radians = M_PI - angle;

    float x = m_cx + std::sin(radians) * m_radius;
    float y = m_cy + std::cos(radians) * m_radius;

    double degrees = 270.0 - radians * 180.0 / M_PI;

    m_texture.set_alpha_mod(bright ? 255 : 150);

    SDL_FRect dst_rect = {
            x - m_size / 2.f,
            y - m_size / 2.f,
            m_size,
            m_size
    };

    SDL_FPoint center = {x, y};

    m_renderer.render_copy(m_texture, nullptr, &dst_rect, degrees, &center, SDL_FLIP_NONE);
}
