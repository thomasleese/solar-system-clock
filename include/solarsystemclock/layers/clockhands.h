#ifndef SOLARSYSTEMCLOCK_LAYERS_CLOCKHANDS_H
#define SOLARSYSTEMCLOCK_LAYERS_CLOCKHANDS_H

#include "solarsystemclock/layers/layer.h"

namespace solarsystemclock {
    class Clock;
}

namespace solarsystemclock::sdl {
    class Texture;
}

namespace solarsystemclock::layers {

    class ClockHands : public Layer {
    public:
        ClockHands(const sdl::Renderer &renderer, const Clock &clock);

        void resize(int width, int height) override;

        void draw() override;

        void draw_hand(float radius, double angle);

    private:
        sdl::Texture m_texture;
        float m_hour_radius, m_minute_radius, m_second_radius;
        float m_cx, m_cy;
    };

}

#endif // SOLARSYSTEMCLOCK_LAYERS_CLOCKHANDS_H
