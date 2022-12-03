#pragma once

struct SDL_Renderer;

namespace solarsystemclock {
    class Clock;
    class Texture;
}

namespace solarsystemclock::layers {

    class Layer {
    public:
        Layer(SDL_Renderer *renderer, Clock *clock);
        virtual ~Layer();

        virtual void resize(int width, int height);
        virtual void draw();

    protected:
        SDL_Renderer *m_renderer;
        Clock *m_clock;
    };

}