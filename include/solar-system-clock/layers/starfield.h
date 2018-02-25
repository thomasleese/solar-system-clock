#include "solar-system-clock/layers/layer.h"

struct SDL_Renderer;

namespace solarsystemclock {
    class Clock;
    class Texture;
}

namespace solarsystemclock::layers {

    struct Star {
        double x, y;
        int size;
        int r, g, b, a;
        int orbit;

        int cx, cy;
        double radius, orig_angle, angle;

        void update_position();
    };

    class Starfield : public Layer {
    public:
        Starfield(SDL_Renderer *renderer, Clock *clock);
        ~Starfield();

        void set_rotation(int orbit, double angle);

        void resize(int width, int height) override;
        void update(double dt) override;
        void draw() override;

    private:
        Clock *m_clock;

        Texture *m_star_texture;

        double m_outer_angle;

        Star *m_stars;
        int m_no_stars;
    };

}
