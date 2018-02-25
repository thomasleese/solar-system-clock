#include "solar-system-clock/layers/layer.h"

struct SDL_Renderer;

namespace solarsystemclock {
    class Texture;
}

namespace solarsystemclock::layers {

    struct Star {
        int x, y;
        int size;
        int r, g, b, a;
    };

    class Starfield : public Layer {
    public:
        Starfield(SDL_Renderer *renderer);
        ~Starfield();

        void resize(int width, int height) override;
        void update(float dt) override;
        void draw() override;

    private:
        Texture *m_star_texture;

        Star *m_stars;
        int m_no_stars;
    };

}
