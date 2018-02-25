#include <vector>

#include "solar-system-clock/layers/layer.h"

struct SDL_Renderer;

namespace solarsystemclock::sprites {
    class Planet;
}

namespace solarsystemclock::layers {

    class OrbitRingss;

    class Planets : public Layer {
    public:
        Planets(SDL_Renderer *renderer, OrbitRingss *orbit_rings);
        ~Planets();

        void resize(int width, int height) override;
        void update(double dt) override;
        void draw() override;

    private:
        layers::OrbitRingss *m_orbit_rings;
        std::vector<sprites::Planet *> m_planets;
    };

}
