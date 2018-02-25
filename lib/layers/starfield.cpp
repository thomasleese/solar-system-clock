#include <cstdlib>
#include <iostream>

#include <SDL2/SDL.h>

#include "solar-system-clock/texture.h"

#include "solar-system-clock/layers/starfield.h"

using namespace solarsystemclock::layers;

Starfield::Starfield(SDL_Renderer *renderer) : Layer(renderer), m_stars(nullptr) {
    m_star_texture = new Texture(renderer, "images/star.png");
}

Starfield::~Starfield() {
    delete[] m_stars;
}

void Starfield::resize(int width, int height) {
    if (m_stars != nullptr) {
        delete[] m_stars;
    }

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
        m_stars[i].x = rand() % (width + size * 2);
        m_stars[i].y = rand() % (height + size * 2);
        m_stars[i].r = 255;
        m_stars[i].g = 255;
        m_stars[i].b = 255;
        m_stars[i].a = 255;
    }
}

void Starfield::update(float dt) {
    int chance_rand = 3000 * dt;

    for (int i = 0; i < m_no_stars; i++) {
        auto &star = m_stars[i];

        if (rand() % chance_rand == 0) {
            star.a = 150 + rand() % 106;
        }
    }
}

void Starfield::draw() {
    SDL_SetRenderDrawColor(m_renderer, 10, 60, 130, 255);
    SDL_RenderClear(m_renderer);

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