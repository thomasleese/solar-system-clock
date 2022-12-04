#ifndef SOLARSYSTEMCLOCK_LAYERS_SUN_H
#define SOLARSYSTEMCLOCK_LAYERS_SUN_H

#include "solarsystemclock/layers/layer.h"

namespace solarsystemclock::sdl {
    class Texture;
}

namespace solarsystemclock::layers {

    class Sun : public Layer {
    public:
        Sun(const sdl::Renderer &renderer, Clock *clock);

        void resize(int width, int height) override;

        void draw() override;

    private:
        sdl::Texture m_texture;
        float m_size, m_cx, m_cy;
    };

}

#endif // SOLARSYSTEMCLOCK_LAYERS_SUN_H
