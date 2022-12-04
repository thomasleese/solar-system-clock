#ifndef SOLARSYSTEMCLOCK_LAYERS_PLANETS_H
#define SOLARSYSTEMCLOCK_LAYERS_PLANETS_H

#include "solarsystemclock/layers/layer.h"

namespace solarsystemclock {
    class Clock;
}

namespace solarsystemclock::sdl {
    class Texture;
}

namespace solarsystemclock::layers {

    class Planets : public Layer {
    public:
        Planets(const SDL_Renderer &renderer, Clock *clock);

        Planets(const sdl::Renderer &renderer, Clock *clock);

        void resize(int width, int height) override;

        void draw() override;

    private:
        float m_cx, m_cy;
        sdl::Texture m_bg_texture, m_ball_texture, m_shadow_texture;
    };

}

#endif // SOLARSYSTEMCLOCK_LAYERS_PLANETS_H
