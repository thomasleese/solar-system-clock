#ifndef SOLARSYSTEMCLOCK_LAYERS_SUNRISESUNSET_H
#define SOLARSYSTEMCLOCK_LAYERS_SUNRISESUNSET_H

#include "solarsystemclock/layers/layer.h"

namespace solarsystemclock {
    class Clock;
}

namespace solarsystemclock::sdl {
    class Texture;
}

namespace solarsystemclock::layers {

    class SunriseSunset : public Layer {
    public:
        SunriseSunset(const sdl::Renderer &renderer, const Clock &clock);

        void resize(int width, int height) override;

        void draw() override;

        void draw_shooting_star(double angle, bool bright);

    private:
        sdl::Texture m_texture;
        float m_radius, m_size;
    };

}

#endif // SOLARSYSTEMCLOCK_LAYERS_SUNRISESUNSET_H
