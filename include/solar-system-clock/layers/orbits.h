#include "solar-system-clock/layers/layer.h"

struct SDL_Renderer;

namespace solarsystemclock {
    class Texture;
}

namespace solarsystemclock::layers {

    class Orbits : public Layer {
    public:
        Orbits(SDL_Renderer *renderer);
        ~Orbits();

        int radius(int orbit) const;

        void resize(int width, int height) override;
        void draw() override;

    private:
        Texture *m_texture;

        int m_size, m_cx, m_cy;
    };

}
