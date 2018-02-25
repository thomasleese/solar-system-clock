#include "solar-system-clock/layers/layer.h"

struct SDL_Renderer;

namespace solarsystemclock::sprites {
    class Planet;
}

namespace solarsystemclock::layers {

    class Planets : public Layer {
    public:
        Planets(SDL_Renderer *renderer);
        ~Planets();

        void resize(int width, int height) override;
        void draw() override;

    private:
        sprites::Planet *m_planet;
    };

}
