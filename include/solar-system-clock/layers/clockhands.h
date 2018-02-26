#include "solar-system-clock/layers/layer.h"

struct SDL_Renderer;

namespace solarsystemclock {
    class Clock;
    class Texture;
}

namespace solarsystemclock::layers {

    class ClockHands : public Layer {
    public:
        ClockHands(SDL_Renderer *renderer, Clock *clock);
        ~ClockHands();

        void resize(int width, int height) override;
        void update(double dt);
        void draw() override;

        void draw_hand(double radius, double angle);

    private:
        Clock *m_clock;
        Texture *m_texture;

        double m_hour_radius, m_hour_angle;
        double m_minute_radius, m_minute_angle;
        double m_second_radius, m_second_angle;

        int m_cx, m_cy;
    };

}
