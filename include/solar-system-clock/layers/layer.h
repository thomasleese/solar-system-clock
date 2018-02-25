#pragma once

struct SDL_Renderer;

namespace solarsystemclock {
    class Texture;
}

namespace solarsystemclock::layers {

    class Layer {
    public:
        Layer(SDL_Renderer *renderer);
        virtual ~Layer();

        virtual void resize(int width, int height);
        virtual void update(double dt);
        virtual void draw();

    protected:
        SDL_Renderer *m_renderer;
    };

}
