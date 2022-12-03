#include "solarsystemclock/layers/layer.h"

struct SDL_Renderer;

namespace solarsystemclock {
    class Texture;
}

namespace solarsystemclock::layers {

    class Background : public Layer {
    public:
        Background(SDL_Renderer *renderer, Clock *clock);
        ~Background();

        void resize(int width, int height) override;
        void draw() override;

    private:
        Texture *m_texture;
        int m_size, m_cx, m_cy;
    };

}
