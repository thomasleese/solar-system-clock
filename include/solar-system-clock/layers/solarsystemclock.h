#include <vector>

#include "solar-system-clock/layers/layer.h"

struct SDL_Renderer;

namespace solarsystemclock::layers {

    class SolarSystemClock : public Layer {
    public:
        SolarSystemClock(SDL_Renderer *renderer);
        ~SolarSystemClock();

        void resize(int width, int height) override;
        void update(float dt) override;
        void draw() override;

    private:
        std::vector<Layer *> m_layers;
    };

}
