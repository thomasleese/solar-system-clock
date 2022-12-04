#ifndef SOLARSYSTEMCLOCK_LAYERS_ROCKET_H
#define SOLARSYSTEMCLOCK_LAYERS_ROCKET_H

#include "solarsystemclock/layers/layer.h"

namespace solarsystemclock {
    class Clock;
}

namespace solarsystemclock::sdl {
    class Texture;
}

namespace solarsystemclock::layers {

    class Rocket : public Layer {
    public:
        Rocket(const sdl::Renderer &renderer, const Clock &clock);

        void resize(int width, int height) override;

        void draw() override;

    private:
        sdl::Texture m_texture;
        float m_radius, m_size, m_cx, m_cy;
    };

}

#endif // SOLARSYSTEMCLOCK_LAYERS_ROCKET_H
