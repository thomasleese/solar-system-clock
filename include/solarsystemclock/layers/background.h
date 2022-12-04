#ifndef SOLARSYSTEMCLOCK_LAYERS_BACKGROUND_H
#define SOLARSYSTEMCLOCK_LAYERS_BACKGROUND_H

#include "solarsystemclock/layers/layer.h"

namespace solarsystemclock::sdl {
    class Texture;
}

namespace solarsystemclock::layers {

    class Background : public Layer {
    public:
        Background(const sdl::Renderer &renderer, Clock *clock);

        void resize(int width, int height) override;

        void draw() override;

    private:
        sdl::Texture m_texture;
        int m_size, m_cx, m_cy;
    };

}

#endif // SOLARSYSTEMCLOCK_LAYERS_BACKGROUND_H
