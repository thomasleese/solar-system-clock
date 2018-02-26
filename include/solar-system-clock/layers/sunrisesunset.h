#include "solar-system-clock/layers/layer.h"

struct SDL_Renderer;

namespace solarsystemclock {
    class Clock;
    class Texture;
}

namespace solarsystemclock::layers {

    class SunriseSunset : public Layer {
    public:
        SunriseSunset(SDL_Renderer *renderer, Clock *clock);
        ~SunriseSunset();

        void resize(int width, int height) override;
        void draw() override;

        void draw_shooting_star(double angle, bool bright);

    private:
        Clock *m_clock;

        Texture *m_texture;

        double m_radius;

        int m_size, m_cx, m_cy;
    };

}
