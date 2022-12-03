#include "solarsystemclock/layers/layer.h"

struct SDL_Renderer;

namespace solarsystemclock {
    class Clock;
    class Texture;
}

namespace solarsystemclock::layers {

    class OrbitRings : public Layer {
    public:
        OrbitRings(SDL_Renderer *renderer, Clock *clock);
        ~OrbitRings();

        void resize(int width, int height) override;
        void draw() override;

    private:
        Texture *m_texture;

        int m_size, m_cx, m_cy;
    };

}
