#include "solar-system-clock/layers/layer.h"

struct SDL_Renderer;

namespace solarsystemclock {
    class Texture;
}

namespace solarsystemclock::layers {

    class OrbitRingss;

    struct Star {
        double x, y;
        int size;
        int r, g, b, a;
        int orbit;

        int cx, cy;
        double radius, angle;

        void update_position();
    };

    class Starfield : public Layer {
    public:
        Starfield(SDL_Renderer *renderer, OrbitRingss *orbit_rings);
        ~Starfield();

        void rotate_stars(int orbit, double amount);

        void resize(int width, int height) override;
        void update(double dt) override;
        void draw() override;

    private:
        layers::OrbitRingss *m_orbit_rings;

        Texture *m_star_texture;

        Star *m_stars;
        int m_no_stars;
    };

}
