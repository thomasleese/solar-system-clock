#ifndef SOLARSYSTEMCLOCK_LAYERS_LAYER_H
#define SOLARSYSTEMCLOCK_LAYERS_LAYER_H

namespace solarsystemclock {
    class Clock;
}

namespace solarsystemclock::sdl {
    class Renderer;
}

namespace solarsystemclock::layers {

    class Layer {
    public:
        Layer(const sdl::Renderer &renderer, Clock *clock);

        virtual ~Layer() = default;

        virtual void resize(int width, int height);

        virtual void draw();

    protected:
        const sdl::Renderer &m_renderer;
        Clock *m_clock;
    };

}

#endif // SOLARSYSTEMCLOCK_LAYERS_LAYER_H
