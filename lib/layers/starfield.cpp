#include <cstdlib>
#include <cmath>

#include "solarsystemclock/clock.h"
#include "solarsystemclock/planet.h"
#include "solarsystemclock/sdl/renderer.h"
#include "solarsystemclock/sdl/texture.h"

#include "solarsystemclock/layers/starfield.h"

using namespace solarsystemclock;
using namespace solarsystemclock::layers;

void Star::update_position() {
    x = cx + std::sin(angle) * radius;
    y = cy + std::cos(angle) * radius;
}

Starfield::Starfield(const sdl::Renderer &renderer, Clock *clock)
        : Layer(renderer, clock),
          m_texture(renderer, "images/star.png"),
          m_stars(nullptr) {
    m_texture.set_blend_mode(SDL_BLENDMODE_BLEND);
}

Starfield::~Starfield() {
    delete[] m_stars;
}

void Starfield::set_rotation(int orbit, double angle) {
    for (int i = 0; i < m_no_stars; i++) {
        auto &star = m_stars[i];

        if (star.orbit == orbit) {
            star.angle = star.orig_angle + angle;
            star.update_position();
        }
    }
}

void Starfield::resize(int width, int height) {
    if (m_stars != nullptr) {
        delete[] m_stars;
    }

    double orbits[] = {
            m_clock->orbits_radius(0),
            m_clock->orbits_radius(1),
            m_clock->orbits_radius(2),
            m_clock->orbits_radius(3),
            m_clock->orbits_radius(4),
            m_clock->orbits_radius(5),
            m_clock->orbits_radius(6),
            m_clock->orbits_radius(7),
    };

    int hw = width / 2;
    int hh = height / 2;

    int max_radius = std::sqrt(hw * hw + hh * hh);

    m_no_stars = (width * height) / 160;
    m_stars = new Star[m_no_stars];

    for (int i = 0; i < m_no_stars; i++) {
        int size = 1;

        if (rand() % 10 == 0) {
            size = 3;
        } else if (rand() % 6 == 0) {
            size = 2;
        }

        m_stars[i].size = size;

        m_stars[i].cx = width / 2;
        m_stars[i].cy = height / 2;
        int radius = m_stars[i].radius = 1 + rand() % max_radius;
        m_stars[i].orig_angle = m_stars[i].angle = (rand() % 1440) * 0.25 * M_PI / 180.0;

        m_stars[i].orbit = 8;

        for (int orbit = 7; orbit >= 0; orbit--) {
            if (radius <= orbits[orbit] + 1) {
                m_stars[i].orbit = orbit;
            }
        }

        m_stars[i].r = 255;
        m_stars[i].g = 255;
        m_stars[i].b = 255;
        m_stars[i].a = 256;

        m_stars[i].radius_proportion = m_stars[i].radius / static_cast<double>(max_radius);

        m_stars[i].update_position();
    }
}

void Starfield::draw() {
    int chance_rand = 100;

    for (int i = 0; i < m_no_stars; i++) {
        auto &star = m_stars[i];

        if (rand() % chance_rand == 0 || star.a == 256) {
            int minium = std::min(100, static_cast<int>(star.radius_proportion * 400));
            int extra = std::max(1, static_cast<int>(star.radius_proportion * 300));

            star.a = std::min(255, minium + rand() % extra);
        }
    }

    for (int orbit = 0; orbit <= 7; orbit++) {
        set_rotation(orbit, m_clock->planet(orbit)->angle());
    }

    set_rotation(8, m_clock->planet(7)->angle() * 1.1);

    for (int i = 0; i < m_no_stars; i++) {
        auto &star = m_stars[i];

        m_texture.set_color_mod(star.r, star.g, star.b);
        m_texture.set_alpha_mod(star.a);

        SDL_FRect dst_rect = {
                star.x - (star.size / 2.f),
                star.y - (star.size / 2.f),
                star.size,
                star.size
        };

        m_renderer.render_copy(m_texture, nullptr, &dst_rect);
    }
}
