#ifndef SOLARSYSTEMCLOCK_LAYERS_STARFIELD_H
#define SOLARSYSTEMCLOCK_LAYERS_STARFIELD_H

#include "solarsystemclock/layers/layer.h"

namespace solarsystemclock {
    class Clock;
}

namespace solarsystemclock::sdl {
    class Texture;
}

namespace solarsystemclock::layers {

    struct Star {
        float x, y;
        float size;
        int r, g, b, a;
        int orbit;

        int cx, cy;
        double radius, orig_angle, angle;

        double radius_proportion;

        void update_position();
    };

    class Starfield : public Layer {
    public:
        Starfield(const sdl::Renderer &renderer, const Clock &clock);
        ~Starfield() override;

        void set_rotation(int orbit, double angle);

        void resize(int width, int height) override;
        void draw() override;

    private:
        sdl::Texture m_texture;
        Star *m_stars;
        int m_no_stars;
    };

}

#endif // SOLARSYSTEMCLOCK_LAYERS_STARFIELD_H
