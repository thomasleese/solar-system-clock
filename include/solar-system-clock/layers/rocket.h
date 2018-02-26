#include "solar-system-clock/layers/layer.h"

struct SDL_Renderer;

namespace solarsystemclock {
    class Clock;
    class Texture;
}

namespace solarsystemclock::layers {

    class Rocket : public Layer {
    public:
        Rocket(SDL_Renderer *renderer, Clock *clock);
        ~Rocket();

        void resize(int width, int height) override;
        void draw() override;

    private:
        Texture *m_texture;

        double m_radius;
        int m_size, m_cx, m_cy;
    };

}
