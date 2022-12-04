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
        Planets(const sdl::Renderer &renderer, const Clock &clock);

        void draw() override;

    private:
        sdl::Texture m_bg_texture, m_ball_texture, m_shadow_texture;
    };

}

#endif // SOLARSYSTEMCLOCK_LAYERS_PLANETS_H
