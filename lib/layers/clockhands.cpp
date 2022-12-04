#include <cmath>

#include "solarsystemclock/clock.h"
#include "solarsystemclock/sdl/renderer.h"
#include "solarsystemclock/sdl/texture.h"

#include "solarsystemclock/layers/clockhands.h"

using namespace solarsystemclock::layers;

ClockHands::ClockHands(const sdl::Renderer &renderer, const Clock &clock)
        : Layer(renderer, clock),
          m_texture(renderer, "images/hand.png") {
    m_texture.set_alpha_mod(200);
    m_texture.set_blend_mode(SDL_BLENDMODE_BLEND);
}

void ClockHands::resize(int width, int height) {
    m_hour_radius = m_clock.orbits_radius(3);
    m_minute_radius = m_clock.orbits_radius(5);
    m_second_radius = m_clock.orbits_radius(7);

    m_cx = width / 2.f;
    m_cy = height / 2.f;
}

void ClockHands::draw() {
    draw_hand(m_hour_radius, m_clock.hours_angle());
    draw_hand(m_minute_radius, m_clock.minutes_angle());
    draw_hand(m_second_radius, m_clock.seconds_angle());
}

void ClockHands::draw_hand(float radius, double angle) {
    float x = m_cx + radius * std::sin(angle) * 0.5;
    float y = m_cy - radius * std::cos(angle) * 0.5;

    double degrees = angle * 180.0 / M_PI;

    float width = 5.f;
    float height = radius;

    SDL_FRect dst_rect = {
            x - (width / 2.f),
            y - (height / 2.f),
            width,
            height
    };

    m_renderer.render_copy(m_texture, nullptr, &dst_rect, degrees, nullptr, SDL_FLIP_NONE);
}
