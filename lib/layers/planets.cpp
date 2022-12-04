#include <cmath>

#include "solarsystemclock/clock.h"
#include "solarsystemclock/planet.h"
#include "solarsystemclock/sdl/renderer.h"
#include "solarsystemclock/sdl/texture.h"

#include "solarsystemclock/layers/planets.h"

using namespace solarsystemclock;
using namespace solarsystemclock::layers;

Planets::Planets(const sdl::Renderer &renderer, const Clock &clock)
        : Layer(renderer, clock),
          m_bg_texture(renderer, "images/planet-background.png"),
          m_ball_texture(renderer, "images/planet-ball.png"),
          m_shadow_texture(renderer, "images/planet-shadow.png") {
    m_bg_texture.set_alpha_mod(192);
    m_bg_texture.set_blend_mode(SDL_BLENDMODE_BLEND);

    m_shadow_texture.set_alpha_mod(200);
    m_shadow_texture.set_blend_mode(SDL_BLENDMODE_BLEND);
}

void Planets::resize(int width, int height) {
    m_cx = width / 2;
    m_cy = height / 2;
}

void Planets::draw() {
    for (auto &planet: m_clock.planets()) {
        int x = m_cx + std::sin(planet->angle()) * planet->radius();
        int y = m_cy + std::cos(planet->angle()) * planet->radius();

        double degrees = 180.0 - planet->angle() * 180.0 / M_PI;

        m_shadow_texture.set_color_mod(planet->red(), planet->green(), planet->blue());
        m_bg_texture.set_color_mod(planet->red(), planet->green(), planet->blue());

        SDL_FRect shadow_dst_rect = {
                static_cast<float>(x - planet->size()),
                static_cast<float>(y - (planet->size() * 6.25f)),
                static_cast<float>(planet->size() * 2.f),
                static_cast<float>(planet->size() * 12.5f)
        };

        m_renderer.render_copy(m_shadow_texture, nullptr, &shadow_dst_rect, degrees, nullptr, SDL_FLIP_NONE);

        SDL_FRect fg_dst_rect = {
                static_cast<float>(x - (planet->size() / 2.f)),
                static_cast<float>(y - (planet->size() / 2.f)),
                static_cast<float>(planet->size()),
                static_cast<float>(planet->size())
        };

        m_renderer.render_copy(m_bg_texture, nullptr, &fg_dst_rect, degrees, nullptr, SDL_FLIP_NONE);
        m_renderer.render_copy(m_ball_texture, nullptr, &fg_dst_rect, degrees, nullptr, SDL_FLIP_NONE);
    }
}
