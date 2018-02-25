#include <vector>

#include "solar-system-clock/layers/layer.h"

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
        void update(double dt) override;
        void draw() override;

    private:
        Clock *m_clock;

        double m_cx, m_cy;

        Texture *m_bg_texture, *m_ball_texture, *m_shadow_texture;
    };

}
