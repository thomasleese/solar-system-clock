#include <algorithm>

#include "solarsystemclock/sdl/renderer.h"

#include "solarsystemclock/layers/layer.h"

using namespace solarsystemclock::layers;

Layer::Layer(const sdl::Renderer &renderer, const Clock &clock)
        : m_renderer(renderer), m_clock(clock), m_center({0, 0}), m_square_size(0) {

}

void Layer::resize(int width, int height) {
    m_square_size = static_cast<float>(std::min(width, height));

    m_center = {
            static_cast<float>(width) / 2.f,
            static_cast<float>(height) / 2.f
    };
}

void Layer::draw() {

}
