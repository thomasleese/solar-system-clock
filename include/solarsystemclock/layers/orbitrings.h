#ifndef SOLARSYSTEMCLOCK_LAYERS_ORBITRINGS_H
#define SOLARSYSTEMCLOCK_LAYERS_ORBITRINGS_H

#include "solarsystemclock/layers/layer.h"

namespace solarsystemclock {
    class Clock;
}

namespace solarsystemclock::sdl {
    class Texture;
}

namespace solarsystemclock::layers {

    class OrbitRings : public Layer {
    public:
        OrbitRings(const SDL_Renderer &renderer, Clock *clock);

        OrbitRings(const sdl::Renderer &renderer, Clock *clock);

        void resize(int width, int height) override;

        void draw() override;

    private:
        sdl::Texture m_texture;
        float m_size, m_cx, m_cy;
    };

}

#endif // SOLARSYSTEMCLOCK_LAYERS_ORBITRINGS_H
