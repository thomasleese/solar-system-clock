#include <cstdlib>
#include <cmath>
#include <iostream>

#include <SDL2/SDL.h>

#include "solar-system-clock/clock.h"
#include "solar-system-clock/planet.h"
#include "solar-system-clock/texture.h"

#include "solar-system-clock/layers/starfield.h"

using namespace solarsystemclock::layers;

void Star::update_position() {
    x = cx + std::sin(angle) * radius;
    y = cy + std::cos(angle) * radius;
}

Starfield::Starfield(SDL_Renderer *renderer, Clock *clock) : Layer(renderer), m_clock(clock), m_stars(nullptr) {
    m_star_texture = new Texture(renderer, "images/star.png");
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

        if (rand() % 20 == 0) {
            size = 4;
        } else if (rand() % 10 == 0) {
            size = 3;
        } else if (rand() % 6 == 0) {
            size = 2;
        }

        m_stars[i].size = size;

        m_stars[i].cx = width / 2;
        m_stars[i].cy = height / 2;
        int radius = m_stars[i].radius = rand() % max_radius;
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
        m_stars[i].a = 255;

        m_stars[i].update_position();
    }

    m_outer_angle = 0;
}

void Starfield::update(double dt) {
    int chance_rand = 3000 * dt;

    for (int i = 0; i < m_no_stars; i++) {
        auto &star = m_stars[i];

        if (rand() % chance_rand == 0) {
            star.a = 150 + rand() % 106;
        }
    }

    for (int orbit = 0; orbit <= 7; orbit++) {
        set_rotation(orbit, m_clock->planet(orbit)->angle());
    }

    m_outer_angle -= dt * 0.02;
    set_rotation(8, m_outer_angle);
}

void Starfield::draw() {
    for (int i = 0; i < m_no_stars; i++) {
        auto &star = m_stars[i];

        m_star_texture->draw(
            m_renderer,
            star.x, star.y,
            star.size, star.size,
            star.r, star.g, star.b, star.a
        );
    }
}
