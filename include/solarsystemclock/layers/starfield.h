#include "solarsystemclock/layers/layer.h"

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

        double radius_proportion;

        void update_position();
    };

    class Starfield : public Layer {
    public:
        Starfield(SDL_Renderer *renderer, Clock *clock);
        ~Starfield();

        void set_rotation(int orbit, double angle);

        void resize(int width, int height) override;
        void draw() override;

    private:
        Texture *m_star_texture;

        Star *m_stars;
        int m_no_stars;
    };

}