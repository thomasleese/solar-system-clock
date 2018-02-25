#include "solar-system-clock/layers/layer.h"

struct SDL_Renderer;

namespace solarsystemclock {
    class Texture;
}

namespace solarsystemclock::layers {

    class OrbitRingss : public Layer {
    public:
        OrbitRingss(SDL_Renderer *renderer);
        ~OrbitRingss();

        int radius(int orbit) const;

        void resize(int width, int height) override;
        void draw() override;

    private:
        Texture *m_texture;

        int m_size, m_cx, m_cy;
    };

}
