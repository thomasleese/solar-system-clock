#ifndef SOLARSYSTEMCLOCK_LAYERS_BACKGROUND_H
#define SOLARSYSTEMCLOCK_LAYERS_BACKGROUND_H

#include "solarsystemclock/layers/layer.h"

namespace solarsystemclock::sdl {
    class Texture;
}

namespace solarsystemclock::layers {

    class Background : public Layer {
    public:
        Background(const sdl::Renderer &renderer, const Clock &clock);

        void draw() override;

    private:
        sdl::Texture m_texture;
    };

}

#endif // SOLARSYSTEMCLOCK_LAYERS_BACKGROUND_H
