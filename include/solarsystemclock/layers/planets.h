#include <vector>

#include "solarsystemclock/layers/layer.h"

struct SDL_Renderer;

namespace solarsystemclock {
    class Clock;
    class Texture;
}

namespace solarsystemclock::layers {

    class Planets : public Layer {
    public:
        Planets(SDL_Renderer *renderer, Clock *clock);
        ~Planets();

        void resize(int width, int height) override;
        void draw() override;

    private:
        double m_cx, m_cy;

        Texture *m_bg_texture, *m_ball_texture, *m_shadow_texture;
    };

}
