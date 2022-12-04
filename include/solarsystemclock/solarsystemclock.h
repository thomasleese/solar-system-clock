#ifndef SOLARSYSTEMCLOCK_LAYERS_SOLARSYSTEMCLOCK_H
#define SOLARSYSTEMCLOCK_LAYERS_SOLARSYSTEMCLOCK_H

#include <vector>

#include "solarsystemclock/layers/layer.h"

namespace solarsystemclock::sdl {
    class Init;
    class Window;
}

namespace solarsystemclock {
    class Clock;

    class SolarSystemClock {
    public:
        SolarSystemClock();

        ~SolarSystemClock();

        void run();

        void resize();

        void draw();

    private:
        sdl::Init m_sdl;
        Clock m_clock;
        sdl::Window m_window;
        std::vector<layers::Layer *> m_layers;
    };

}

#endif // SOLARSYSTEMCLOCK_LAYERS_SOLARSYSTEMCLOCK_H
