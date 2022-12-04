#ifndef SOLARSYSTEMCLOCK_LAYERS_LAYER_H
#define SOLARSYSTEMCLOCK_LAYERS_LAYER_H

#include <SDL2/SDL_rect.h>

namespace solarsystemclock {
    class Clock;
}

namespace solarsystemclock::sdl {
    class Renderer;
}

namespace solarsystemclock::layers {

    class Layer {
    public:
        Layer(const sdl::Renderer &renderer, const Clock &clock);

        virtual ~Layer() = default;

        virtual void resize(int width, int height);
        virtual void draw();

    protected:
        const sdl::Renderer &m_renderer;
        const Clock &m_clock;

        SDL_FPoint m_center;
        float m_square_size;
    };

}

#endif // SOLARSYSTEMCLOCK_LAYERS_LAYER_H
